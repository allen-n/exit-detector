/*
Ring buffer utility class, created by Allen Nikka, December 25, 2019
*/

#ifndef DIST_DEBOUNCER_H
#define DIST_DEBOUNCER_H

#include "Arduino.h"

class DistDebouncer
{
public:
    /**
     * @param targetDist The Target Distance being debounced
     * @param threshold +- Target dist we can accept
     * @param deltaTime Time period reading must stay consistent for
     * in milliseconds
     */
    DistDebouncer(
        double targetDist,
        double threshold,
        unsigned long deltaTime);

    /**
     * Check if the debounced distance is at the specified target
     * @param dist The current distance 
     */
    bool isAtTarget(double dist);

private:
    const double _targetDist;       // The Target Distance being debounced
    const double _threshold;        // +- Target dist we can accept
    const unsigned long _deltaTime; // Time period reading must stay consistent for

    unsigned long _startTime; // When distance came into range
    bool _isStarted;          // Whether we are inside the target threshold
    double _mx;               // Max dist we can accept
    double _mn;               // Min dist we can accept
};

#endif // !DIST_DEBOUNCER_H
