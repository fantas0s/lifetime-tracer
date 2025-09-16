#pragma once

#include <QAtomicInteger>
#include <QtTypes>

#include <memory>

class QElapsedTimer;

namespace lifetime_tracer {
class CumulativeLifetimer
{
public:
    CumulativeLifetimer();
    ~CumulativeLifetimer();
    static void setPrintInterval(quint64 numberOfIterations);

private:
    static QAtomicInteger<quint64> s_nsecsElapsed;
    static QAtomicInteger<quint64> s_printInterval;
    static QAtomicInteger<quint64> s_calls;
    static QAtomicInteger<quint64> s_callsSinceLastPrint;
    std::unique_ptr<QElapsedTimer> m_timer;
};
} // namespace lifetime_tracer
