#include "GTS.h"
#include "Pipe.h"
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void GTS::EditPipe(Pipe& pipe)
{
	cout << "Repair status will be changed, do you agree?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Please, enter your choice: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Enter repair status: ";
		bool pipeRepair = GetCorrectData(false, true);;
		pipe.pipeRepair = pipeRepair;
		cout << "ID: " << pipe.Id << ": ";
		pipe.PrintPipeRepair();
		break;
	}
	case 2:
	{
		return;
	}
	default:
	{
		cout << "Please, enter the correct command!\n" << endl;
		break;
	}
	}
}

void GTS::EditPipes(vector<Pipe*>& pipes)
{
	cout << "\nDo you want to edit repair status of the found pipes?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Please, enter you choice: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Enter repair status for all pipes: ";
		bool repSt = GetCorrectData(false, true);

		for (auto& pipe : pipes)
		{
			pipe->pipeRepair = repSt;
		}
		cout << "\nStatus has been successfully changed for all pipes!" << endl;
		break;
	}
	case 2:
		return;
	default:
		cout << "Please, enter the correct data!" << endl;
		break;
	}
}

void GTS::searchPipe(unordered_map<int, Pipe>& Pipes)
{
	while (true)
	{
		cout << "\nSelect the feature by which you want to select a pipe: " << endl;
		cout << "1. Name" << endl;
		cout << "2. Repair status" << endl;
		cout << "3. Return" << endl;
		cout << "Please, enter you choice: ";
		switch (GetCorrectData(1, 3))
		{
		case 1:
		{
			string pipeName;
			cout << "\nEnter the pipe name: ";
			cin.ignore();
			getline(cin, pipeName);
			vector<Pipe*> editPipes;
			for (auto& elem : Pipes)
			{
				if (elem.second.GetName().find(pipeName) != string::npos)
				{
					cout << elem.second;
					editPipes.push_back(&(elem.second));
				}
			}
			if (editPipes.empty())
				cout << "There is no pipe with that name!" << endl;
			else
				EditPipes(editPipes);
		}
		break;
		case 2:
		{
			cout << "Enter the pipe repair status: ";
			bool repairStatus = GetCorrectData(false, true);
			vector<Pipe*> editPipes;
			for (auto& elem : Pipes)
			{
				if (elem.second.GetStatus() == repairStatus)
				{
					cout << elem.second;
					editPipes.push_back(&(elem.second));
				}
			}
			if (editPipes.empty())
				cout << "There is no pipe with that repair status!" << endl;
			else
				EditPipes(editPipes);
		}
		break;
		case 3:
			return;
		default:
		{
			cout << "Please, enter the correct data!" << endl;
			break;
		}
		}
	}
}

void GTS::EditStation(Station& station)
{
	cout << "Tne number of active workshops will be changed, do you agree?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Please, enter you choice: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Enter the number of active workshops: ";
		station.stationActWorkshops = GetCorrectData(1, station.GetWorkshops());
		cout << "ID: " << station.Id << ": ";
		station.PrintWorkshops();
	}
	case 2:
		return;
	default:
	{
		cout << "Please, enter the correct command!\n" << endl;
		break;
	}
	}
}

void GTS::EditStations(vector<Station*> stations)
{
	cout << "\nDo you want to change the number of active workshops?" << endl;
	cout << "1. Yes" << endl;
	cout << "2. No" << endl;
	cout << "Please, enter your choice: ";
	switch (GetCorrectData(1, 2))
	{
	case 1:
	{
		cout << "Enter the percent of non-active workshops: ";
		float percent = GetCorrectData(0.0, 100.0);
		for (auto& station : stations)
		{
			station->stationActWorkshops = round(station->stationWorkshops * (100 - percent) / 100);
		}
		cout << "\nThe number of active workshops has been successfully changed for all CS!" << endl;
		break;
	}
	case 2:
		return;
	default:
		cout << "Please, enter the correct data!";
		break;
	}
}

void GTS::searchStation(unordered_map<int, Station>& Stations)
{
	while (true)
	{
		cout << "\nSelect the feature by which you want to select a CS: " << endl;
		cout << "1. Name" << endl;
		cout << "2. Percent of non-active workshops" << endl;
		cout << "3. Return" << endl;
		cout << "Please, enter you choice: ";
		switch (GetCorrectData(1, 3))
		{
		case 1:
		{
			string stationName;
			cout << "Enter the station name : ";
			cin.ignore();
			getline(cin, stationName);
			vector<Station*> editStations;
			for (auto& elem : Stations)
			{
				if (elem.second.GetName().find(stationName) != string::npos)
				{
					cout << elem.second;
					editStations.push_back(&(elem.second));
				}
			}
			if (editStations.empty())
				cout << "There is no station with that name!" << endl;
			else
				EditStations(editStations);
		}
		break;
		case 2:
		{
			cout << "\nEnter the percent of non-active workshops: ";
			int percent = GetCorrectData(0, 100);
			cout << "What limits the search should be?" << endl;
			cout << "1. Less (<%)" << endl;
			cout << "2. Equal (=%)" << endl;
			cout << "3. More (>%)" << endl;
			cout << "Please, enter your choice: ";
			vector<Station*> editStations;
			switch (GetCorrectData(1, 3))
			{
			case 1:
			{
				for (auto& elem : Stations)
				{
					if (elem.second.GetPercentOfNonActiveWorkshops() < percent)
					{
						cout << elem.second;
						editStations.push_back(&(elem.second));
					}
				}
			}
			break;
			case 2:
			{
				for (auto& elem : Stations)
				{
					if (elem.second.GetPercentOfNonActiveWorkshops() == percent)
					{
						cout << elem.second;
						editStations.push_back(&(elem.second));
					}
				}
			}
			break;
			case 3:
			{
				for (auto& elem : Stations)
				{
					if (elem.second.GetPercentOfNonActiveWorkshops() > percent)
					{
						cout << elem.second;
						editStations.push_back(&(elem.second));
					}
				}
			}
			break;
			}
			if (editStations.empty())
				cout << "There is no station with that percent!" << endl;
			else
				EditStations(editStations);
		}
		break;
		case 3:
			return;
		default:
		{
			cout << "Please, enter the correct data!" << endl;
			break;
		}
		}
	}
}

bool GTS::HasConnection(const unordered_map<int, Pipe>& Pipes, const int& CSid1, const int& CSid2)
{
	bool hasPipe = false;
	for (auto& elem : Pipes)
	{
		if ((elem.second.CSid1 == CSid1 && elem.second.CSid2 == CSid2)
			|| (elem.second.CSid1 == CSid2 && elem.second.CSid2 == CSid1))
		{
			hasPipe = true;
		}
	}
	return hasPipe;
}

void GTS::ConnectInGTS(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations)
{
	int pipeDiameter = 0;
	cout << "Enter pipe diameter: ";
	pipeDiameter = GetCorrectDiameter(500, 1400);
	int idConnectedPipe = 0;

	for (auto& elem : Pipes)
	{
		if (elem.second.GetDiametr() == pipeDiameter && elem.second.ConnectionNotBusy())
		{
			idConnectedPipe = elem.first;
			break;
		}
	}

	Pipe* connectedPipe{};
	if (idConnectedPipe == 0)
	{
		bool flag = true;
		while (flag)
		{
			cout << "No pipe with this diameter!\nDo you want to add a pipe?" << endl
				<< "1) Yes" << endl
				<< "2) No" << endl
				<< "Please, enter the command: ";
			switch (GetCorrectData(1, 2))
			{
			case 1:
			{
				Pipe pipe0;
				cin >> pipe0;
				connectedPipe = &pipe0;
				Pipes.insert(make_pair(connectedPipe->GetId(), *connectedPipe));
				flag = false;
			}
			break;
			case 2:
				return;
			default:
				cout << "There is no such command, please, try again" << endl;
				break;
			}
		}
	}
	else
	{
		connectedPipe = &Pipes[idConnectedPipe];
	}

	if (idConnectedPipe != 0)
	{
		cout << "Enter the ID of the first CS: ";
		int CSid1;
		CSid1 = GetCorrectData(1, int(Stations.size()));
		while (Stations.find(CSid1) == Stations.end())
		{
			cout << "\nCS with this ID is busy! Please, try again:" << endl;
			GetCorrectData(1, int(Stations.size()));
		}

		cout << "Enter the ID of the second CS: ";
		int CSid2;
		CSid2 = GetCorrectData(1, int(Stations.size()));
		while (Stations.find(CSid2) == Stations.end() || CSid2 == CSid1 || HasConnection(Pipes, CSid1, CSid2))
		{
			cout << "\nCS with this ID is busy! Please, try again:" << endl;
			GetCorrectData(1, int(Stations.size()));
		}
		connectedPipe->Connect(CSid1, CSid2);
	}
}

void GTS::ConnectInGTS1(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations, vector<GTS>& connection)
{
	if (Stations.size() == 0)
	{
		cout << "CS not enough!";
		return;
	}
	if (Pipes.size() == 0)
	{
		cout << "Pipes not enough!";
		return;
	}
	int k = 0;
	vector <int> free_cs;
	for (auto& elem : Stations)
	{
		if (elem.second.id_in + elem.second.id_out < 2)
		{
			k += 1;
			free_cs.push_back(elem.first);
		}
	}
	if (k < 2)
	{
		cout << "You don`t have free stations!";
		return;
	}

	int n = 0;
	vector<int> free_pipes;
	for (auto& elem : Pipes)
	{
		if (elem.second.free)
		{
			n += 1;
			free_pipes.push_back(elem.first);
		}
	}
	if (n < 1)
	{
		cout << "You don`t have free pipes!";
		return;
	}

	GTS pipe_connect;
	cout << "Please, enter the ID of entry CS: ";
	cin >> pipe_connect.id_entry;
	if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_entry) == free_cs.end())
	{
		while (true)
		{
			cout << "There is no such ID, please, enter correct: ";
			cin >> pipe_connect.id_entry;
			if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_entry) != free_cs.end())
			{
				Stations[pipe_connect.id_entry].id_in += 1;
				break;
			}
		}
	}
	else
		Stations[pipe_connect.id_entry].id_in += 1;

	cout << "Please, enter the ID of outlet CS: ";
	cin >> pipe_connect.id_out;
	if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_out) == free_cs.end() || (pipe_connect.id_out == pipe_connect.id_entry))
	{
		while (true)
		{
			cout << "There is no such ID, please, enter correct: ";
			cin >> pipe_connect.id_out;
			if (find(free_cs.begin(), free_cs.end(), pipe_connect.id_out) != free_cs.end() && (pipe_connect.id_out != pipe_connect.id_entry))
			{
				Stations[pipe_connect.id_out].id_out += 1;
				break;
			}
		}
	}
	else
		Stations[pipe_connect.id_out].id_out += 1;

	int i = 0;
	int pipe_diameter;
	while (true)
	{
		cout << "Enter the diameter of the pipe you want to use (500, 700, 1000, 1400): ";
		pipe_diameter = GetCorrectDiameter(500, 1400);
		for (auto& idp : free_pipes)
		{
			if (Pipes[idp].pipeDiameter == pipe_diameter)
			{
				pipe_connect.id_pipe = idp;
				i += 1;
				Pipes[idp].free = 0;
				break;
			}
		}
		if (i == 1)
		{
			connection.push_back(pipe_connect);
			break;
		}
		else
		{
			cout << "There is no free pipe with this diameter!";
			int new_id_pipe = AddNewPipeConnect(Pipes, pipe_diameter);
			pipe_connect.id_pipe = new_id_pipe;
			Pipes[new_id_pipe].free = 0;
			connection.push_back(pipe_connect);
			break;
		}
	}
}

int GTS::AddNewPipeConnect(unordered_map<int, Pipe>& Pipes, int diameter)
{
	cout << "Diameter that was missing will be installed." << endl;
	Pipe pipe;
	cin >> pipe;
	pipe.pipeDiameter = diameter;
	int new_pipe_id = pipe.GetId();
	Pipes.insert({ new_pipe_id, pipe });
	return new_pipe_id;
}

void GTS::ShowGTS(vector<GTS>& connection)
{
	cout << "[CS ENTRY ID] | [PIPE ID] | [CS OUTLET ID]" << endl;
	if (connection.size() == 0)
	{
		cout << "There is no connections!" << endl;
	}
	else
	{
		for (auto& elem : connection)
		{
			cout << "\t[" << elem.id_entry << "] \t[" << elem.id_pipe << "] \t[" << elem.id_out << "]\n";
		}
	}
}

void GTS::DeleteConnection(vector<GTS>& connection, unordered_map<int, Pipe>& Pipes)
{
	cout << "Please, enter the ID of the pipe to remove the connection from: ";
	int idp = GetCorrectData(1, int(Pipes.size()));
	for (auto it = connection.begin(); it != connection.end();)
	{
		if (it->id_pipe == idp)
		{
			it = connection.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void GTS::case12(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations)
{
	if (Pipes.size() == 0)
		cout << "Pipes don`t exists!" << endl;
	if (Stations.size() == 0)
		cout << "CS don`t exists!" << endl;
	int connectCount = 0;
	for (const auto& elem : Pipes)
		if (!elem.second.ConnectionNotBusy())
		{
			cout << "CS1 [" << elem.second.CSid1 << "] - Pipe [" << elem.first << "] - CS2 [" << elem.second.CSid2 << "]" << endl;
			connectCount++;
		}
	cout << "There are " << connectCount << " connections" << endl;
}

void GTS::case13(unordered_map<int, Pipe>& Pipes)
{
	if (Pipes.size() == 0)
		cout << "Pipes don`t exists!" << endl;
	else
	{
		cout << "Enter the ID of the pipe to delete: ";
		int delPipe;
		delPipe = GetCorrectData(1, int(Pipes.size()));
		while (Pipes.find(delPipe) == Pipes.end())
		{
			cout << "\nPipe with this ID not exist! Please, try again: ";
			GetCorrectData(1, int(Pipes.size()));
		}
		if (Pipes[delPipe].ConnectionNotBusy())
		{
			cout << "Pipe not in GTS" << endl;
		}
		else
		{
			Pipes[delPipe].DeleteConnection();
			cout << "Connection deleted sucecessful!" << endl;
		}
	}
}

void GTS::Deikstra(unordered_map<int, Pipe>& Pipes, vector<GTS>& graph, unordered_map<int, Station>& Stations)
{
	if (graph.size() == 0)
	{
		cout << "You have no connection!" << endl;
		return;
	}

	int maxel = 0;
	int minel = Stations[0].maxId;

	set<int> vertexes;
	for (auto& edge : graph)
	{
		vertexes.insert(edge.id_entry);
		vertexes.insert(edge.id_out);
		if (edge.id_entry > maxel)
		{
			maxel = edge.id_entry;
		}
		if (edge.id_entry < minel)
		{
			minel = edge.id_entry;
		}
		if (edge.id_out > maxel)
		{
			maxel = edge.id_out;
		}
		if (edge.id_out < minel)
		{
			minel = edge.id_out;
		}
	}

	int start_vertex;
	int end_vertex;

	cout << "Enter the ID of CS from which you want to find the shortest path: ";
	start_vertex = GetCorrectData(minel, maxel);
	if (find(vertexes.begin(), vertexes.end(), start_vertex) == vertexes.end())
	{
		while (true)
		{
			cout << "There is no such ID, please enter correct: ";
			cin >> start_vertex;
			if (find(vertexes.begin(), vertexes.end(), start_vertex) != vertexes.end())
			{
				break;
			}
		}
	}

	cout << "Enter the ID of CS you want to find the shortest path to: ";
	end_vertex = GetCorrectData(minel, maxel);
	if (find(vertexes.begin(), vertexes.end(), end_vertex) == vertexes.end())
	{
		while (true)
		{
			cout << "There is no such ID, please enter correct: ";
			cin >> end_vertex;
			if (find(vertexes.begin(), vertexes.end(), start_vertex) != vertexes.end())
			{
				break;
			}
		}
	}

	for (const auto& vertex : vertexes) {
		Stations[vertex].shortest_path = numeric_limits<int>::max();
	}

	Stations[start_vertex].shortest_path = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start_vertex });

	while (!pq.empty()) {
		int current_vertex = pq.top().second;
		int current_distance = pq.top().first;
		pq.pop();

		if (current_vertex == end_vertex) {
			break;
		}

		for (const auto& edge : graph) {
			if (edge.id_entry == current_vertex) {
				int neighbor_vertex = edge.id_out;
				const Pipe& truba = Pipes[edge.id_pipe];
				int new_distance = current_distance + truba.pipeLength;

				if (new_distance < Stations[neighbor_vertex].shortest_path) {
					Stations[neighbor_vertex].shortest_path = new_distance;
					pq.push({ new_distance, neighbor_vertex });
				}
			}
		}
	}
	if (Stations[end_vertex].shortest_path == numeric_limits<int>::max())
	{
		cout << "There is no path from " << start_vertex << " to " << end_vertex << "." << endl;
	}
	else
	{
		cout << "Shortest path from " << start_vertex << " to " << end_vertex << ": " << Stations[end_vertex].shortest_path << endl;
	}
}

bool BFS(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent)
{
	int V = rGraph.size();
	vector<bool> visited(V, false);

	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int v = 0; v < V; v++)
		{
			if (visited[v] == false && rGraph[u][v] > 0)
			{
				q.push(v);
				parent[v] = u;
				visited[v] = true;
			}
		}
	}

	return (visited[t] == true);
}

void GTS::FordFulkerson(vector<GTS>& graph, unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations)
{
	if (graph.size() == 0)
	{
		cout << "You have no connections!" << endl;
		return;
	}

	int maxel = 0;
	int minel = Stations[0].maxId;

	set<int>vertexes;
	for (auto& edge : graph)
	{
		vertexes.insert(edge.id_entry);
		vertexes.insert(edge.id_out);
		if (edge.id_entry > maxel)
		{
			maxel = edge.id_entry;
		}
		if (edge.id_entry < minel)
		{
			minel = edge.id_entry;
		}
		if (edge.id_out > maxel)
		{
			maxel = edge.id_out;
		}
		if (edge.id_out < minel)
		{
			minel = edge.id_out;
		}
	}

	int s;
	cout << "Enter the vertex-source: ";
	s = GetCorrectData(minel, maxel);
	cout << "Enter the vertex-sink: ";
	int t;
	t = GetCorrectData(minel, maxel);

	if (s == t)
	{
		while (true)
		{
			cout << "Source and sink must not be the same number!" << endl;
			t = GetCorrectData(minel, maxel);
			if (s != t) {
				break;
			}
		}

	}
	int V = Stations.size();
	vector<vector<int>> RGraph(V, vector<int>(V, 0));
	for (const GTS& edge : graph) {
		RGraph[edge.id_entry][edge.id_out] = Pipes[edge.id_pipe].pipeLength;
	}

	vector<int> parent(V, -1);
	int maxFlow = 0;

	while (BFS(RGraph, s, t, parent))
	{
		int pathFlow = INT_MAX;
		for (int v = t; v != s; v = parent[v])
		{
			int u = parent[v];
			pathFlow = min(pathFlow, RGraph[u][v]);
		}

		for (int v = t; v != s; v = parent[v])
		{
			int u = parent[v];
			RGraph[u][v] -= pathFlow;
			RGraph[v][u] += pathFlow;
		}

		maxFlow += pathFlow;
	}
	cout << "Maximum flow: " << maxFlow << endl;
}

vector<int> GTS::topologSort(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations)
{
	vector<int> result;
	unordered_map<int, int> enterEdges;
	unordered_map<int, int> outEdges;

	for (auto& elem : Pipes)
	{
		if (elem.second.CSid2 != 0)
			enterEdges[elem.second.CSid2]++;
	}
	for (auto& elem : Pipes)
	{
		if (elem.second.CSid1 != 0)
			outEdges[elem.second.CSid1]++;
	}

	queue<int> que;
	for (auto& elem : Stations)
	{
		if (enterEdges.find(elem.first) == enterEdges.end() && outEdges.find(elem.first) != outEdges.end())
		{
			que.push(elem.first);
		}
	}

	while (!que.empty())
	{
		int curStation = que.front();
		que.pop();
		result.push_back(curStation);

		for (auto& elem : Pipes)
		{
			if (elem.second.CSid1 == curStation && elem.second.CSid1 != 0)
			{
				enterEdges[elem.second.CSid2]--;
				if (enterEdges[elem.second.CSid2] == 0)
				{
					que.push(elem.second.CSid2);
				}
			}
		}
	}
	return result;
}

