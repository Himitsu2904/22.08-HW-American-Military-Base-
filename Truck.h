#pragma once
#include <iostream>
#include "Vehicle.h"
using namespace std;

class Truck: public Vehicle
{
public:
	Truck(double load, double maximum_load, double petrol, double max_petrol) :Vehicle(petrol, max_petrol)
	{
		max_load = maximum_load;
		if (load > max_load)
		{
			current_load = max_load;
		}
		else
		{
			current_load = load;
		}
		max_people = 2;
		people_count = max_people;
	}
	virtual void arrive()
	{
		Vehicle::arrive();
		cout << "Truck arrived" << endl;
		people_count = 0;
		current_load = 0;
	}
	virtual bool leave()
	{
		if (petrol_amount != tank_volume || people_count == 0 || current_load == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

