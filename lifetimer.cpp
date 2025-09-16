#include "lifetimer.h"
#include <QDebug>
#include <QElapsedTimer>

using namespace lifetime_tracer;

Lifetimer::Lifetimer(Accuracy accuracy)
    : m_accuracy{accuracy}
    , m_timer{std::make_unique<QElapsedTimer>()}
{
    // Start the timer as the very last thing to reduce overhead.
    m_timer->start();
}

Lifetimer::~Lifetimer()
{
    // Capture the elapsed time as the very first thing to reduce overhead.
    const quint64 nsecsElapsed = m_timer->nsecsElapsed();
    if (m_accuracy == Accuracy::Milliseconds)
        qDebug() << "Elapsed:" << nsecsElapsed / 1000000 << "milliseconds";
    else
        qDebug() << "Elapsed:" << nsecsElapsed << "nanoseconds";
}
