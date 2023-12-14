#include "GTS.h"
#include "Pipe.h"
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

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

vector<int> GTS::topologSort(unordered_map<int, Pipe>& Pipes, unordered_map<int, Station>& Stations)
{
	vector<int> result;
	unordered_map<int, int> enterEdges;

	for (auto& elem : Pipes)
	{
		enterEdges[elem.second.CSid2]++;
	}

	queue<int> que;
	for (auto& elem : Stations)
	{
		if (enterEdges.find(elem.first) == enterEdges.end())
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
			if (elem.second.CSid1 == curStation)
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
