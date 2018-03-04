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

//enum class WellType
//{
//	gas, oil, water
//};

//class OilField
//{
//public :
//	OilField(double gasV, double oilV, double waterV);
//	double GetGasVolume();
//	double GetOilVolume();
//	double GetWaterVolume();
//	bool TryDecreaseOilVolume(double val);
//	bool TryIncreaseWaterVolume(double val);
//	list<Well> GetAllWells();
//	void AddWell(WellType wellType, double val);
//	bool TryRemoveWell(int id);
//	bool TryStartWell(int id);
//	bool TryStopWell(int id);
//	void Work();
//};

//class Well
//{
//protected:
//	int _id;
//	bool _isOn;
//	double _volume;
//	double _workRate;
//	WellType _wellType;
//public:
//	Well(int id, WellType wellType, double workRate = 67.0)
//	{
//		_id = id;
//		_isOn = false;
//		_volume = 0.0;
//		_wellType = wellType;
//		_workRate = workRate;
//	}
//	int GetId()
//	{
//		return _id;
//	}
//	double GetVolume()
//	{
//		return _volume;
//	}
//	double GetWorkRate() 
//	{
//		return _workRate; 
//	}
//	WellType GetWellType()
//	{
//		return _wellType;
//	}
//	bool IsOn()
//	{
//		return _isOn;
//	}
//	bool Start()
//	{
//		_isOn = true;
//		return _isOn;
//	}
//	bool Stop()
//	{
//		_isOn = false;
//		return _isOn;
//	}
//
//	void Work(OilField * oF, int *iterationWaterV)
//	{
//		//if (_isOn)
//		//	_volume += _workRate;
//	}
//};

//class OilWell : public Well
//{
//public:
//	OilWell(int id, WellType wellType, double workRate = 67.0) : 
//		Well (id, wellType, workRate)
//	{	}
//
//	void Work(OilField* oF, int* iterationWaterV)
//	{
//		if (_isOn)
//		{
//			int vol = fmin(fmin(oF->GetOilVolume(), _workRate), *iterationWaterV); // *iterationWaterV);
//			if(oF->TryDecreaseOilVolume(vol))
//			{
//				_volume += vol;
//				(*iterationWaterV) -= vol;
//			}
//		}
//		//	_volume += _workRate;
//	}
//};
//
//class OutlWell : public Well
//{
//public :
//	OutlWell(int id, WellType wellType, double workRate = 67.0) :
//		Well(id, wellType, workRate)
//	{	}
//
//	void Work(OilField * oF, int * iterationWaterV)
//	{
//		if (_isOn)
//		{
//			int vol = fmin( _workRate, oF->GetGasVolume() + oF->GetOilVolume() - *iterationWaterV);
//			if (oF->TryIncreaseWaterVolume(vol))
//			{
//				_volume += vol;
//				(*iterationWaterV) += vol;
//			}
//		}
//		//	_volume += _workRate;
//	}
//};

//class OilField
//{
//private:
//	list<Well> _wells;
//
//	double _gasVolume;
//	double _oilVolume;
//	double _waterVolume;
//
//	double _capacity;
//
//	int _idCounter = 0;
//
//	double CalculateVolume(WellType wellType)
//	{
//		double vol = 0;
//
//		for (auto& w : _wells)
//		{
//			if (w.GetWellType() == wellType)
//			{
//				vol += w.GetVolume();
//			}
//		}
//		return vol;
//	}
//
//	bool TryStartOrStopWell(int id, bool start)
//	{
//		auto y = find_if(_wells.begin(), _wells.end(), [=](Well a) { return a.GetId() == id; });
//
//		if (y == _wells.end())
//			return false;
//
//		if (start)
//			y->Start();
//		else
//			y->Stop();
//
//		return true;
//	}
//
//public:
//
//	OilField( double gasV, double oilV, double waterV) 
//	{
//		_gasVolume = gasV;
//		_oilVolume = oilV;
//		_waterVolume = waterV;
//
//		_capacity = _gasVolume + _oilVolume + _waterVolume;
//	}
//
//	double GetGasVolume() { return _gasVolume; }
//	double GetOilVolume() { return _oilVolume; }
//	double GetWaterVolume() { return _waterVolume; }
//
//	bool TryDecreaseOilVolume(double val)
//	{
//		if (_oilVolume - val >= 0)
//		{
//			_oilVolume -= val;
//			return true;
//		}
//		return false;
//	}
//
//	bool TryIncreaseWaterVolume(double val)
//	{
//		if (_capacity >= _waterVolume+val)
//		{
//			_waterVolume += val;
//			return true;
//		}
//		return false;
//	}
//
//	list<Well> GetAllWells()
//	{
//		return _wells;
//	}
//
//	void AddWell(WellType wellType, double val)
//	{
//		//Well w(_idCounter++, wellType);
//		if (wellType == WellType::oil)
//		{
//			_wells.push_back(OilWell(_idCounter++, wellType, val));
//		}
//		if (wellType == WellType::water)
//		{
//			_wells.push_front(OutlWell(_idCounter++, wellType, val));
//		}
//	}
//
//	bool TryRemoveWell(int id)
//	{
//		//_wells.remove_if(_wells.begin(), _wells.end(), my_predicate)
//
//		auto y = find_if(_wells.begin(), _wells.end(), [=](Well a) { return a.GetId() == id; });
//
//		if (y == _wells.end())
//			return false;
//		else
//			_wells.erase(y);
//		return false;
//	}
//
//	bool TryStartWell(int id)
//	{
//		return TryStartOrStopWell(id, true);
//	}
//
//	bool TryStopWell(int id)
//	{
//		return TryStartOrStopWell(id, false);
//	}
//
//	void Work()
//	{
//		for (auto& w : _wells)
//		{
//			int iterationWaterVol = 0;
//			w.Work(this, &iterationWaterVol);
//		}
//	}
//
//};
 
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
			cout << "Well #" << w.GetId() << " of type "
				<< PrintWellType(w.GetWellType())
				<< (w.IsOn() ? " is on " : " is off")
				<< ", rate = "<< w.GetWorkRate()
				<< ",  volume = "
				<< w.GetVolume() << "\n";
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

			if (command == "oil")
			{
				oilF.AddWell(WellType::oil, val);
			}
			else if (command == "water")
			{
				oilF.AddWell(WellType::water, val);
			}
			else if (command == "gas")
			{
				oilF.AddWell(WellType::gas, val);
			}

		}
		else if (command == "del")
		{
			cin >> id;
			if (!oilF.TryRemoveWell(id))
			{
				cout << "Well with this id does not exist.\n";
			}
		}
		else if (command == "start")
		{
			cin >> id;

			oilF.TryStartWell(id);
		}
		else if (command == "stop")
		{
			cin >> id;
			oilF.TryStopWell(id);
		}
		else if (command == "quit")
		{
			cout << "bb\n";
			return 0;
		}
	}

	return 0;
}

