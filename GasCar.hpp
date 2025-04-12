#pragma once
#include "Vehicle.hpp"

class GasCar : public Vehicle {
public:
	double getFuelLevel() const {
		return fuelLevel;
	}
	void setFuelLevel(const double _fuelLevel) {
		fuelLevel = _fuelLevel;
	}
private:
	double fuelLevel = 0.0;
};