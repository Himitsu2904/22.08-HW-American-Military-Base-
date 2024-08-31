#pragma once
#include <iostream>
#include "Bus.h"
#include "Truck.h"
using namespace std;

class Base
{
	static int people_on_base;
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
	Vehicle * transport;
public:
	Base()
	{
		people_on_base = 15;
		vehicles_on_base = 4;
		petrol_on_base = 260;
		goods_on_base = 83;
		transport = nullptr;
	}
	Base(int people, int vehicles, double petrol, double goods)
	{
		people_on_base = people;
		vehicles_on_base = vehicles;
		petrol_on_base = petrol;
		goods_on_base = goods;
		transport = nullptr;
	}
	void Start() //added
	{
		cout << "\t-----WELCOME TO AMERICAN MILITARY BASE-----\n";
		int choice;
		char sub_choice;
		double diff_of_need;
		do
		{
			cout << "1. Show info about Base\n2. Let transport in\n3. Let transport out\n4. Fullfil base supplies\n5. Exit\n";
			choice = 0;
			while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5)
			{
				cout << "Choose an option: ";
				cin >> choice;
			}
			switch (choice)
			{
			case 1:
				ShowInfo();
				cout << "------------------------------------------------------\n";
				break;
			case 2:
				cout << "a) Bus\tb) Truck\nWhat kind of transport will arrive? ";
				cin >> sub_choice;
				switch (sub_choice)
				{
				case 'a':
					transport = new Bus(12, 25, 34, 60);
					break;
				case 'b':
					transport = new Truck(67, 90, 23, 60);
					break;
				}
				vehicles_on_base++;
				people_on_base += transport->getPeopleCount();
				goods_on_base += transport->getCurrentLoad();
				transport->arrive();
				petrol_on_base += transport->getPetrolAmount();
				break;
			case 3:
				if (transport->getInside())
				{
					if (transport->getMaxPeople() <= people_on_base)
					{
						transport->setPeopleCount(transport->getMaxPeople());
						people_on_base -= transport->getPeopleCount();
					}
					else if (transport->getMaxPeople() > people_on_base)
					{
						transport->setPeopleCount(people_on_base);
						people_on_base = 0;
					}

					if (transport->getMaxLoad() <= goods_on_base)
					{
						transport->setCurrentLoad(transport->getMaxLoad());
						goods_on_base -= transport->getCurrentLoad();
					}
					else if (transport->getMaxLoad() > goods_on_base)
					{
						transport->setCurrentLoad(goods_on_base);
						goods_on_base = 0;
					}

					diff_of_need = transport->getTankVolume() - transport->getPetrolAmount();
					if (diff_of_need <= petrol_on_base)
					{
						transport->setPetrolAmount(transport->getTankVolume());
						petrol_on_base -= diff_of_need;
					}
					else if (diff_of_need > petrol_on_base)
					{
						transport->setPetrolAmount(transport->getPetrolAmount() + petrol_on_base);
						petrol_on_base = 0;
					}

					if (transport->leave())
					{
						cout << "Transport left the base." << endl;
						transport->setInside(false);
						vehicles_on_base--;
					}
					else
					{
						cout << "Transport can't leave. Reason(s):\n";
						if (transport->getPetrolAmount() != transport->getTankVolume()) cout << "- not full petrol tank\n";
						if (transport->getPeopleCount() == 0) cout << "- no driver\n";
						if (transport->getCurrentLoad() == 0) cout << "- no goods load\n";
					}
				}
				else
				{
					cout << "Transport didn't arrive." << endl;
				}
				break;
			case 4:
				cout << "1. Petrol\n2. People\n3. Goods\nWhat do you need to update? ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Set petrol volume: ";
					cin >> choice;
					transport->setPetrolAmount(choice);
				case 2:
					cout << "Set people amount: ";
					cin >> choice;
					transport->setPeopleCount(choice);
				case 3:
					cout << "Set goods volume: ";
					cin >> choice;
					transport->setCurrentLoad(choice);
				}
				break;
			}
		} while (choice != 5);
	}
	void ShowInfo() //added
	{
		cout << "-----BASE INFO-----" << endl;
		cout << "People = " << people_on_base << endl;
		cout << "Vehicles = " << vehicles_on_base << endl;
		cout << "Petrol = " << petrol_on_base << " l" << endl;
		cout << "Goods = " << goods_on_base << " t" << endl;
	}
	~Base()
	{
		if (transport != nullptr)
		{
			delete transport;
		}
	}
};

