#include "../inc/DistDebouncer.h"

DistDebouncer::DistDebouncer(
    double targetDist,
    double threshold,
    unsigned long deltaTime)
    : _targetDist(targetDist),
      _threshold(threshold),
      _deltaTime(deltaTime)
{
    this->_isStarted = false;
    this->_mx = this->_targetDist + this->_threshold;
    this->_mn = this->_targetDist - this->_threshold;
    this->_startTime = 0;
}

bool DistDebouncer::isAtTarget(double dist)
{
    bool isTarget = false;
    unsigned long currentTime = millis();
    if (dist >= this->_mn && dist <= this->_mx) // Inside desired range
    {
        if (!this->_isStarted) // Hadn't yet started
        {
            // Start counting, we're in threshold
            this->_isStarted = true;
            this->_startTime = currentTime;
        }
        else // Had previously started
        {
            // Start time was > dt ago
            if (currentTime - this->_startTime > this->_deltaTime)
            {
                isTarget = true;
                this->_isStarted = false;
            }
        }
    }
    else // We've fallen outside the desired range
    {
        this->_isStarted = false;
    }

    return isTarget;
}