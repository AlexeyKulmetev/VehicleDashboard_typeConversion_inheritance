#pragma once
#include "Vehicle.hpp"

class ElectricCar : public Vehicle {
public:
	double getBatteryLevel() const {
		return batteryLevel;
	}
	void setBatteryLevel(const double _batteryLevel) {
		batteryLevel = _batteryLevel;
	}

private:
	double batteryLevel = 0.0;
};