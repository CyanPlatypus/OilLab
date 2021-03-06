// PetroleumClassesCppLab.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
//#include <WS2tcpip.h>

#include <list>
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include "Oil.h"

//using namespace  std
using std::list;
using std::string;
using std::cout;
using std::cin;
using std::find_if;

//https://stackoverflow.com/questions/22540147/linux-c-timer-periodic-callback

 
static class OilLogger
{
public:
	static void PrintOilField(OilField oilF)
	{
		cout << "Oil field has \n\t" << oilF.GetGasVolume() << " of gas, \n\t" <<
			oilF.GetOilVolume() << " of oil, \n\t" <<
			oilF.GetWaterVolume() << " of water.\n";



		for (auto& w : oilF.GetAllWells())
		{
			cout << "Well #" << w->GetId() << " of type "
				<< PrintWellType(w->GetWellType())
				<< (w->IsOn() ? " is on" : " is off")
				<< ", rate = "<< w->GetWorkRate()
				<< ",  volume = "
				<< w->GetVolume() << "\n";
		}
	}

	static string PrintWellType(WellType wellType)
	{
		if (wellType == WellType::gas)
			return "gas";
		else if (wellType == WellType::oil)
			return "oil";
		else
			return "water";
	}
};

int main()
{

	OilField oilF(20, 30, 0);


	OilLogger::PrintOilField(oilF);

	string command;
	int id;

	while (true)
	{

		cin >> command;


		if (command == "w" || command == "work")
		{
			oilF.Work();
		}
		else if (command == "p" || command == "print")
		{
			OilLogger::PrintOilField(oilF);
		}
		else if (command == "add")
		{
			cin >> command;

			double val;
			cin >> val;

			val = abs(val);

			if (command == "oil" || command == "o")
			{
				oilF.AddWell(WellType::oil, val);
			}
			else if (command == "water" || command == "w")
			{
				oilF.AddWell(WellType::water, val);
			}
			else if (command == "gas" || command == "g")
			{
				oilF.AddWell(WellType::gas, val);
			}

		}
		else if (command == "rem")
		{
			cin >> id;
			if (!oilF.TryRemoveWell(id))
			{
				cout << "Well with this id does not exist.\n";
			}
		}
		else if (command == "start" || command == "s")
		{
			cin >> id;

			oilF.TryStartWell(id);
		}
		else if (command == "stop")
		{
			cin >> id;
			oilF.TryStopWell(id);
		}
		else if (command == "quit" || command == "q")
		{
			cout << "bb\n";
			return 0;
		}
	}

	return 0;
}

