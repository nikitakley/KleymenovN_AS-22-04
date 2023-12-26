#pragma once
#include <string>
#include <fstream>
#include "Utilities.h"
using namespace std;

class Station
{
public:
	static int maxId;
	int Id;
	string stationName = "None";
	int stationWorkshops = 0;
	int stationActWorkshops = 0;
	double stationEfficiency = 0.0;

	int id_in = 0;
	int id_out = 0;
	int shortest_path;

	int GetId();
	string GetName() const;
	int GetWorkshops() const;
	int GetActWorkshops() const;
	int GetPercentOfNonActiveWorkshops() const;
	void PrintWorkshops() const;

	//friend void EditStation(Station& station);
	//friend void EditStations(vector <Station*> stations);
	friend ostream& operator << (ostream& out, const Station& newStation);
	friend istream& operator >> (istream& in, Station& newStation);
	friend ofstream& operator << (ofstream& fout, const Station& newStation);
	friend ifstream& operator >> (ifstream& fin, Station& newStation);
};

