// Copyright 2026 UNN-CS Team
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#include "circle.h"

struct PoolCosts {
    double path_cost;
    double fence_cost;
};

double earthAndRope(double earthRadius, double ropeExtension);
PoolCosts swimmingPool(double poolRadius, double pathWidth,
                       double concreteCostPerSqm, double fenceCostPerMeter);

#endif  // INCLUDE_TASKS_H_
