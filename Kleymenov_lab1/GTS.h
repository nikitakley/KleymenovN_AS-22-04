#pragma once
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"

class GTS
{
public:
	int id_entry;
	int id_pipe;
	int id_out;

	void EditPipe(Pipe& pipe);
	void EditPipes(vector <Pipe*>& pipes);
	void searchPipe(unordered_map<int, Pipe>& Pipes);

	void EditStation(Station& station);
	void EditStations(vector <Station*> stations);
	void searchStation(unordered_map<int, Station>& Stations);
	bool HasConnection(const unordered_map<int, Pipe>& Pipes, const int& CSid1, const int& CSid2);
	void ConnectInGTS(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations);

	void ConnectInGTS1(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations, vector<GTS>& connection);
	int AddNewPipeConnect(unordered_map<int, Pipe>& Pipes, int diameter);
	void ShowGTS(vector<GTS>& connection);
	void DeleteConnection(vector<GTS>& connection, unordered_map<int, Pipe>& Pipes);
	
	void case12(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations);
	void case13(unordered_map<int, Pipe>& Pipes);

	void Deikstra(unordered_map<int, Pipe>& Pipes, vector<GTS>& graph, unordered_map<int, Station>& Stations);
	void FordFulkerson(vector<GTS>& graph, unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations);

	vector<int> topologSort(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations);
};