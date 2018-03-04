#pragma once

#include "stdafx.h"

#include "Oil.h"



Well::Well(int id, WellType wellType, double workRate )
{
	_id = id;
	_isOn = false;
	_volume = 0.0;
	_wellType = wellType;
	_workRate = workRate;
}
int Well::GetId()
{
	return _id;
}
double Well::GetVolume()
{
	return _volume;
}
double Well::GetWorkRate()
{
	return _workRate;
}
WellType Well::GetWellType()
{
	return _wellType;
}
bool Well::IsOn()
{
	return _isOn;
}
bool Well::Start()
{
	_isOn = true;
	return _isOn;
}
bool Well::Stop()
{
	_isOn = false;
	return _isOn;
}

void Well::Work(OilField * oF, double *iterationWaterV)
{
	//if (_isOn)
	//	_volume += _workRate;
}




OilWell::OilWell(int id, WellType wellType, double workRate) :
	Well(id, wellType, workRate)
{	}

void OilWell::Work(OilField* oF, double* iterationWaterV)
{
	if (_isOn)
	{
		double vol = fmin(fmin(oF->GetOilVolume(), _workRate), *iterationWaterV); // *iterationWaterV);
		if (oF->TryDecreaseOilVolume(vol))
		{
			_volume += vol;
			(*iterationWaterV) -= vol;
		}
	}
	//	_volume += _workRate;
}

GasWell::GasWell(int id, WellType wellType, double workRate) :
	Well(id, wellType, workRate)
{	}

void GasWell::Work(OilField* oF, double* iterationWaterV)
{
	if (_isOn)
	{
		double vol = fmin(fmin(oF->GetGasVolume(), _workRate), *iterationWaterV);
		if (oF->TryDecreaseGasVolume(vol))
		{
			_volume += vol;
			(*iterationWaterV) -= vol;
		}
	}
}


OutlWell::OutlWell(int id, WellType wellType, double workRate) :
	Well(id, wellType, workRate)
{	}

void OutlWell::Work(OilField * oF, double * iterationWaterV)
{
	if (_isOn)
	{
		double vol = fmin(_workRate, oF->GetGasVolume() + oF->GetOilVolume() - *iterationWaterV);
		if (oF->TryIncreaseWaterVolume(vol))
		{
			_volume += vol;
			(*iterationWaterV) += vol;
		}
	}
	//	_volume += _workRate;
}
