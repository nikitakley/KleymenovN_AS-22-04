#include "GTS.h"
#include "Pipe.h"
#include "Station.h"
#include "Utilities.h"
#include <iostream>
#include <fstream>
#include <string>

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



