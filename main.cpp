#include "ElectricCar.hpp"
#include "GasCar.hpp"
#include <iostream>
#include <vector>
#include "Vehicle.hpp"

const int VEHICLE_NUM = 20;

void showDashboard(const Vehicle* vehicle) {
	if (!vehicle) {
		std::cout << "Null vehicle";
		return;
	}
	if (const ElectricCar* electricCar = dynamic_cast<const ElectricCar*>(vehicle)) {
		std::cout << "Battery: " << electricCar->getBatteryLevel() << "%";
	}
	else if (const GasCar* gasCar = dynamic_cast<const GasCar*>(vehicle)) {
		std::cout << "Fuel: " << gasCar->getFuelLevel() << "%";
	}
	else {
		std::cout << "Unknown vehicle";
	}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::vector<Vehicle*> vehicles;
	for (int i = 0; i < VEHICLE_NUM; ++i) {
		if (std::rand() % 2 == 0) {
			GasCar* gasCar = new GasCar;
			gasCar->setFuelLevel(std::rand() % 101);
			vehicles.push_back(gasCar);
		}
		else {
			ElectricCar* electricCar = new ElectricCar;
			electricCar->setBatteryLevel(std::rand() % 101);
			vehicles.push_back(electricCar);
		}
	}
	for (int i = 0; i < VEHICLE_NUM; ++i) {
		showDashboard(vehicles[i]);
		std::cout << "\n";
	}
	for (Vehicle* v : vehicles) {
		delete v;
	}
	return 0;
}