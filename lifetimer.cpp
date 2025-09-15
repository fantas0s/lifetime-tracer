#include "lifetimer.h"
#include <QDebug>
#include <QElapsedTimer>

using namespace lifetime_tracer;

Lifetimer::Lifetimer()
    : m_timer{std::make_unique<QElapsedTimer>()}
{
    m_timer->start();
}

LifeTimer::~LifeTimer()
{
    qDebug() << "Elapsed:" << m_timer->elapsed();
}
