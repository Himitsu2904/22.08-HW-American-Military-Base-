#pragma once
using namespace std;

class Vehicle
{
protected:
	double petrol_amount;
	double tank_volume;
	int people_count;
	int max_people;
	double current_load;
	double max_load;
	bool inside; //added
public:
	Vehicle(double _petrol_amount, double _tank_volume)
	{
		tank_volume = _tank_volume;
		if (_petrol_amount > tank_volume)
		{
			petrol_amount = tank_volume;
		}
		else
		{
			petrol_amount = _petrol_amount;
		}
		inside = false;
	}
	double getPetrolAmount()
	{
		return petrol_amount;
	}
	double getTankVolume()
	{
		return tank_volume;
	}	
	int getPeopleCount()
	{
		return people_count;
	}
	int getMaxPeople()
	{
		return max_people;
	}
	double getCurrentLoad()
	{
		return current_load;
	}
	double getMaxLoad()
	{
		return max_load;
	}
	bool getInside() //added
	{
		return inside;
	}
	void setPetrolAmount(double petrol) //added
	{
		petrol_amount = petrol;
	}
	void setPeopleCount(int people) //added
	{
		people_count = people;
	}
	void setCurrentLoad(double load) //added
	{
		current_load = load;
	}
	void setInside(bool _inside) //added
	{
		inside = _inside;
	}
	virtual void arrive() = 0
	{
		cout << "Vehicle arrived" << endl;
		inside = true;
		petrol_amount -= 30;
		if (petrol_amount < 0)
		{
			petrol_amount = 0;
		}
	}
	virtual bool leave() = 0 ;
};

