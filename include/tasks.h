#ifndef TASKS_H
#define TASKS_H

#include "circle.h"

struct PoolCosts {
    double path_cost;
    double fence_cost;
};

double earthAndRope(double earthRadius, double ropeExtension);
PoolCosts swimmingPool(double poolRadius, double pathWidth, double concreteCostPerSqm, double fenceCostPerMeter);

#endif // TASKS_H
