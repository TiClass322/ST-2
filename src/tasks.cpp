// Copyright 2026 UNN-CS Team
#include "tasks.h"
#include <cmath>

double earthAndRope(double earthRadius, double ropeExtension) {
    Circle earth(earthRadius);
    double initialFerence = earth.getFerence();
    Circle rope(0);
    rope.setFerence(initialFerence + ropeExtension);
    return rope.getRadius() - earthRadius;
}

PoolCosts swimmingPool(double poolRadius, double pathWidth,
                       double concreteCostPerSqm, double fenceCostPerMeter) {
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double pathCost = pathArea * concreteCostPerSqm;
    double fenceLength = poolWithPath.getFerence();
    double fenceCost = fenceLength * fenceCostPerMeter;
    return {pathCost, fenceCost};
}
