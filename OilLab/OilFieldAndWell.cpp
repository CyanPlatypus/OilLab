#pragma once

#include "stdafx.h"

#include <list>
#include <algorithm>

#include "Oil.h"

using std::list;
using std::find_if;


bool OilField::TryStartOrStopWell(int id, bool start)
{
	auto y = find_if(_wells.begin(), _wells.end(), [=](Well a) { return a.GetId() == id; });

	if (y == _wells.end())
		return false;

	if (start)
		y->Start();
	else
		y->Stop();

	return true;
}

OilField::OilField(double gasV, double oilV, double waterV)
{
	_gasVolume = gasV;
	_oilVolume = oilV;
	_waterVolume = waterV;

	_capacity = _gasVolume + _oilVolume + _waterVolume;
}

double OilField::GetGasVolume() { return _gasVolume; }
double OilField::GetOilVolume() { return _oilVolume; }
double OilField::GetWaterVolume() { return _waterVolume; }

bool OilField::TryDecreaseOilVolume(double val)
{
	if (_oilVolume - val >= 0)
	{
		_oilVolume -= val;
		return true;
	}
	return false;
}

bool OilField::TryIncreaseWaterVolume(double val)
{
	if (_capacity >= _waterVolume + val)
	{
		_waterVolume += val;
		return true;
	}
	return false;
}

list<Well> OilField::GetAllWells()
{
	return _wells;
}

void OilField::AddWell(WellType wellType, double val)
{
	//Well w(_idCounter++, wellType);
	if (wellType == WellType::oil)
	{
		_wells.push_back(OilWell(_idCounter++, wellType, val));
	}
	if (wellType == WellType::water)
	{
		_wells.push_front(OutlWell(_idCounter++, wellType, val));
	}
}

bool OilField::TryRemoveWell(int id)
{
	//_wells.remove_if(_wells.begin(), _wells.end(), my_predicate)

	auto y = find_if(_wells.begin(), _wells.end(), [=](Well a) { return a.GetId() == id; });

	if (y == _wells.end())
		return false;
	else
		_wells.erase(y);
	return false;
}

bool OilField::TryStartWell(int id)
{
	return TryStartOrStopWell(id, true);
}

bool OilField::TryStopWell(int id)
{
	return TryStartOrStopWell(id, false);
}

void OilField::Work()
{


	for (auto& w : _wells)
	{
		double iterationWaterVol = 0.0;
	
		_wells.front().Work(this, &iterationWaterVol);
		
		w.Work(this, &iterationWaterVol);
	}
}

//double OilField::CalculateVolume(WellType wellType)
//{
//	double vol = 0;

//	for (auto& w : _wells)
//	{
//		if (w.GetWellType() == wellType)
//		{
//			vol += w.GetVolume();
//		}
//	}
//	return vol;
//}
