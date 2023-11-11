#pragma once
#include <string>
#include <fstream>
#include "Utilities.h"
using namespace std;

class Station
{
	static int maxId;
	int Id;
	string stationName = "None";
	int stationWorkshops = 0;
	int stationActWorkshops = 0;
	double stationEfficiency = 0.0;

public:
	int GetId();
	string GetName() const;
	int GetWorkshops() const;
	int GetActWorkshops() const;
	void PrintWorkshops() const;

	friend void EditStation(Station& station);
	friend ostream& operator << (ostream& out, const Station& newStation);
	friend istream& operator >> (istream& in, Station& newStation);
	friend ofstream& operator << (ofstream& fout, const Station& newStation);
	friend ifstream& operator >> (ifstream& fin, Station& newStation);
};

