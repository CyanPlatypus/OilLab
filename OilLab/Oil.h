#pragma once

#include "stdafx.h"

#include <list>

using std::list;

enum class WellType
{
	gas, oil, water
};

class Well;

class OilField
{
private:
	list<Well*> _wells;
	double _gasVolume;
	double _oilVolume;
	double _waterVolume;
	double _capacity;
	int _idCounter = 0; bool TryStartOrStopWell(int id, bool start);
public:
	OilField(double gasV = 20.0, double oilV = 30.0, double waterV = 0.0);
	double GetGasVolume();
	double GetOilVolume();
	double GetWaterVolume();
	bool TryDecreaseOilVolume(double val);
	bool TryDecreaseGasVolume(double val);
	bool TryIncreaseWaterVolume(double val);

	//does it make a copy?
	list<Well*> GetAllWells();
	void AddWell(WellType wellType, double val);
	bool TryRemoveWell(int id);
	bool TryStartWell(int id);
	bool TryStopWell(int id);
	void Work();
};

class Well
{
protected:
	int _id;
	bool _isOn;
	double _volume;
	double _workRate;
	WellType _wellType;
public:
	Well(int id, WellType wellType, double workRate = 67.0);
	int GetId();
	double GetVolume();
	double GetWorkRate();
	WellType GetWellType();
	bool IsOn();
	bool Start();
	bool Stop();

	virtual void Work(OilField * oF, double *iterationWaterV);
};

class OilWell : public Well
{
public:
	OilWell(int id, WellType wellType, double workRate = 67.0);

	void Work(OilField* oF, double* iterationWaterV) override;
};

class GasWell : public Well
{
public:
	GasWell(int id, WellType wellType, double workRate = 67.0);

	void Work(OilField* oF, double* iterationWaterV) override;
};

class OutlWell : public Well
{
public:
	OutlWell(int id, WellType wellType, double workRate = 67.0);

	void Work(OilField * oF, double * iterationWaterV) override;
};