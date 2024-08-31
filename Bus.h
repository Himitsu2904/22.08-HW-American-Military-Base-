#pragma once
#include "Vehicle.h"
using namespace std;

class Bus: public Vehicle
{
public:
	Bus(int people, int maximum_people, double petrol, double max_petrol): Vehicle(petrol, max_petrol)
	{
		max_people = maximum_people;
		if (people > max_people)
		{
			people_count = max_people;
		}
		else
		{
			people_count = people;
		}
		max_load = max_people * 70 /*kg*/ * 0.25;
		current_load = max_load * (people_count / max_people * 1.0);
	}
	virtual void arrive()
	{
		Vehicle::arrive();
		cout << "Bus arrived" << endl;
		people_count = 0;
		current_load = 0;
	}
	virtual bool leave()
	{
		if (petrol_amount != tank_volume || people_count == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
};

