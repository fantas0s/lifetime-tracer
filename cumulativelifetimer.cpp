#include "cumulativelifetimer.h"
#include <QDebug>
#include <QElapsedTimer>

using namespace lifetime_tracer;

QAtomicInteger<quint64> CumulativeLifetimer::s_nsecsElapsed{0};
QAtomicInteger<quint64> CumulativeLifetimer::s_printInterval{100};
QAtomicInteger<quint64> CumulativeLifetimer::s_calls{0};
QAtomicInteger<quint64> CumulativeLifetimer::s_callsSinceLastPrint{0};

CumulativeLifetimer::CumulativeLifetimer()
    : m_timer{std::make_unique<QElapsedTimer>()}
{
    // Start the timer as the very last thing to reduce overhead.
    m_timer->start();
}

CumulativeLifetimer::~CumulativeLifetimer()
{
    // Capture the elapsed time as the very first thing to reduce overhead.
    const auto nsecsElapsed = m_timer->nsecsElapsed();
    // Now that we have local value, do atomic variable updates. This way we do not accidentally measure atomic wait time.
    s_nsecsElapsed += nsecsElapsed;
    s_calls++;
    if (++s_callsSinceLastPrint >= s_printInterval) {
        s_callsSinceLastPrint = 0;
        qDebug() << "Cumulative time spent after" << s_calls << "iterations:" << s_nsecsElapsed
                 << "nanoseconds";
    }
}

void CumulativeLifetimer::setPrintInterval(quint64 numberOfIterations)
{
    s_printInterval = numberOfIterations;
}
