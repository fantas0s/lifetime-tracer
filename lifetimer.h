#pragma once

class QElapsedTimer;
namespace lifetime_tracer {
class Lifetimer {
public:
    Lifetimer();
    ~Lifetimer();
private:
    std::unique_ptr<QElapsedTimer> m_timer;
};
}
