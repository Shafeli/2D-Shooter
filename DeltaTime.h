#pragma once
class DeltaTime
{
    float m_timeStep = 0.f;
public:

    void SetTime(float time) { m_timeStep = time; }

    [[nodiscard]] float GetSeconds()const { return m_timeStep; }

    [[nodiscard]] float GetMilliseconds()const { return m_timeStep * 1000.f; }

    // for cool thing like casting to a float by default timeStep is seconds
    operator float() const { return m_timeStep; }
};

