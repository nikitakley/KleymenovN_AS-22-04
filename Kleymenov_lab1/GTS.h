#pragma once
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"

class GTS
{
public:
	void EditPipe(Pipe& pipe);
	void EditPipes(vector <Pipe*>& pipes);
	void searchPipe(unordered_map<int, Pipe>& Pipes);

	void EditStation(Station& station);
	void EditStations(vector <Station*> stations);
	void searchStation(unordered_map<int, Station>& Stations);
	bool HasConnection(const unordered_map<int, Pipe>& Pipes, const int& CSid1, const int& CSid2);
	void ConnectInGTS(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations);

	vector<int> topologSort(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations);
};