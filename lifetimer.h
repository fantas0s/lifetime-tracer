#pragma once

#include <memory>

class QElapsedTimer;

namespace lifetime_tracer {
class Lifetimer
{
    enum class Accuracy { Milliseconds, Nanoseconds };

public:
    Lifetimer(Accuracy accuracy = Accuracy::Milliseconds);
    ~Lifetimer();

private:
    Accuracy m_accuracy;
    std::unique_ptr<QElapsedTimer> m_timer;
};
} // namespace lifetime_tracer
