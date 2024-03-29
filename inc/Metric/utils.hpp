//utils.hpp
#pragma once

#ifndef _METRIC_UTILS_HPP
#define _METRIC_UTILS_HPP

#include <Metric/MetricInterface.hpp>
#include <Drone.hpp>

float getMass(Drone& d);

float getMotorPower(Drone& d);

float getStaticThrust(Drone& d);

#endif //_METRIC_UTILS_HPP
