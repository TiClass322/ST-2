// Copyright 2025 UNN-CS Team

#include <cstdint>
#include <gtest/gtest.h>

#include "circle.h"
#include "tasks.h"

// --- Circle Class Tests ---

TEST(Circle_Constructor, Radius_1) {
    Circle c(1.0);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-9);
}

TEST(Circle_Constructor, Ference_1) {
    Circle c(1.0);
    EXPECT_NEAR(c.getFerence(), 2 * PI, 1e-9);
}

TEST(Circle_Constructor, Area_1) {
    Circle c(1.0);
    EXPECT_NEAR(c.getArea(), PI, 1e-9);
}

TEST(Circle_SetRadius, Radius_10) {
    Circle c(1.0);
    c.setRadius(10.0);
    EXPECT_NEAR(c.getRadius(), 10.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 20 * PI, 1e-9);
    EXPECT_NEAR(c.getArea(), 100 * PI, 1e-9);
}

TEST(Circle_SetRadius, Radius_0) {
    Circle c(1.0);
    c.setRadius(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

TEST(Circle_SetRadius, Radius_Negative) {
    Circle c(1.0);
    c.setRadius(-5.0);
    EXPECT_NEAR(c.getRadius(), -5.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), -10 * PI, 1e-9);
    // Area is pi * r^2, so should be positive
    EXPECT_NEAR(c.getArea(), 25 * PI, 1e-9);
}

TEST(Circle_SetFerence, Ference_2PI) {
    Circle c(10.0);
    c.setFerence(2 * PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * PI, 1e-9);
    EXPECT_NEAR(c.getArea(), PI, 1e-9);
}

TEST(Circle_SetFerence, Ference_0) {
    Circle c(10.0);
    c.setFerence(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

TEST(Circle_SetFerence, Ference_Negative) {
    Circle c(10.0);
    c.setFerence(-4 * PI);
    EXPECT_NEAR(c.getRadius(), -2.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), -4 * PI, 1e-9);
    EXPECT_NEAR(c.getArea(), 4*PI, 1e-9);
}

TEST(Circle_SetArea, Area_PI) {
    Circle c(10.0);
    c.setArea(PI);
    EXPECT_NEAR(c.getRadius(), 1.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 2 * PI, 1e-9);
    EXPECT_NEAR(c.getArea(), PI, 1e-9);
}

TEST(Circle_SetArea, Area_0) {
    Circle c(10.0);
    c.setArea(0.0);
    EXPECT_NEAR(c.getRadius(), 0.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 0.0, 1e-9);
    EXPECT_NEAR(c.getArea(), 0.0, 1e-9);
}

TEST(Circle_SetArea, Area_16PI) {
    Circle c(1.0);
    c.setArea(16 * PI);
    EXPECT_NEAR(c.getRadius(), 4.0, 1e-9);
    EXPECT_NEAR(c.getFerence(), 8 * PI, 1e-9);
    EXPECT_NEAR(c.getArea(), 16 * PI, 1e-9);
}

TEST(Circle_Getters, GetRadius) {
    Circle c(5.0);
    EXPECT_NEAR(c.getRadius(), 5.0, 1e-9);
}

TEST(Circle_Getters, GetFerence) {
    Circle c(5.0);
    EXPECT_NEAR(c.getFerence(), 10 * PI, 1e-9);
}

TEST(Circle_Getters, GetArea) {
    Circle c(5.0);
    EXPECT_NEAR(c.getArea(), 25 * PI, 1e-9);
}


// --- Tasks Tests ---

TEST(Tasks_EarthAndRope, ProvidedValues) {
    // Earth radius in meters
    double earthRadius = 6378.1 * 1000;
    // Extra rope in meters
    double ropeExtension = 1.0;
    // The gap should be ropeExtension / (2 * PI)
    double expected_gap = 1.0 / (2 * PI);
    EXPECT_NEAR(earthAndRope(earthRadius, ropeExtension), expected_gap, 1e-9);
}

TEST(Tasks_EarthAndRope, ZeroExtension) {
    double earthRadius = 6378.1 * 1000;
    double ropeExtension = 0.0;
    EXPECT_NEAR(earthAndRope(earthRadius, ropeExtension), 0.0, 1e-9);
}

TEST(Tasks_SwimmingPool, ProvidedValues) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double concreteCostPerSqm = 1000.0;
    double fenceCostPerMeter = 2000.0;
    PoolCosts costs = swimmingPool(poolRadius, pathWidth,
                                   concreteCostPerSqm, fenceCostPerMeter);
    // Expected path area = PI * (4^2 - 3^2) = 7 * PI
    double expected_path_cost = (PI * (4*4 - 3*3)) * 1000.0;
    // Expected fence length = 2 * PI * 4 = 8 * PI
    double expected_fence_cost = (2 * PI * 4) * 2000.0;
    EXPECT_NEAR(costs.path_cost, expected_path_cost, 1e-9);
    EXPECT_NEAR(costs.fence_cost, expected_fence_cost, 1e-9);
}

TEST(Tasks_SwimmingPool, ZeroWidth) {
    double poolRadius = 3.0;
    double pathWidth = 0.0;
    double concreteCostPerSqm = 1000.0;
    double fenceCostPerMeter = 2000.0;
    PoolCosts costs = swimmingPool(poolRadius, pathWidth,
                                   concreteCostPerSqm, fenceCostPerMeter);
    EXPECT_NEAR(costs.path_cost, 0.0, 1e-9);
    // Fence cost should be for the pool itself
    double expected_fence_cost = (2 * PI * 3) * 2000.0;
    EXPECT_NEAR(costs.fence_cost, expected_fence_cost, 1e-9);
}

TEST(Tasks_SwimmingPool, ZeroCosts) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    double concreteCostPerSqm = 0.0;
    double fenceCostPerMeter = 0.0;
    PoolCosts costs = swimmingPool(poolRadius, pathWidth,
                                   concreteCostPerSqm, fenceCostPerMeter);
    EXPECT_NEAR(costs.path_cost, 0.0, 1e-9);
    EXPECT_NEAR(costs.fence_cost, 0.0, 1e-9);
}
