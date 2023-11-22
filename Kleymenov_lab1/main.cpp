#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "Pipe.h"
#include "Station.h"
#include "Utilities.h"
using namespace std;

void searchPipe(unordered_map<int, Pipe>& Pipes)
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

void searchStation(unordered_map<int, Station>& Stations)
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

int main() 
{
	Pipe pipe0;
	Station station0;
	unordered_map<int, Pipe> Pipes = {};
	unordered_map<int, Station> Stations = {};
	int num = 0;
	while (true) {
		cout << endl << "Menu:" << endl;
		cout << "1) Add pipe" << endl;
		cout << "2) Add a CS" << endl;
		cout << "3) View all objects" << endl;
		cout << "4) Edit pipe" << endl;
		cout << "5) Edit a CS" << endl;
		cout << "6) Delete pipe" << endl;
		cout << "7) Delete CS" << endl;
		cout << "8) Save" << endl;
		cout << "9) Download" << endl;
		cout << "10) Search" << endl;
		cout << "0) Exit" << endl;
		cout << endl << "Please, enter the command number: ";
		switch (GetCorrectData(0, 10))
		{
		case 1:
		{
			cout << "\n[1] Adding a new pipe..." << endl;
			Pipe pipe0;
			cin >> pipe0;
			Pipes.insert({pipe0.GetId(), pipe0});
			break;
		}
		case 2:
		{
			cout << "\n[2] Adding a new CS..." << endl;
			Station station0;
			cin >> station0;
			Stations.insert({station0.GetId(), station0});
			break;
		}
		case 3:
		{
			cout << "\n[3] Viewing all objects: " << endl;
			if (Pipes.size() == 0)
				cout << "\nNo pipes have been added!" << endl;
			for (const auto& elem : Pipes)
				cout << elem.second;

			if (Stations.size() == 0)
				cout << "\nNo stations have been added!" << endl;
			for (const auto& elem : Stations)
				cout << elem.second;
			break;
		}
		case 4:
		{
			if (Pipes.size() == 0) {
				cout << "\nNo pipes available!" << endl;
			}
			else {
				cout << "\n[4] Edit pipe: " << endl;
				cout << "Enter ID: ";
				int indPipes = Pipes.size();
				Pipe& pipe0 = SelectElement(Pipes, GetCorrectData(1, indPipes));
				EditPipe(pipe0);
			}
			break;
		}
		case 5:
		{
			if (Stations.size() == 0) {
				cout << "\nNo CS available!" << endl;
			}
			else {
				cout << "\n[5] Edit CS: " << endl;
				cout << "Enter ID: ";
				int indStations = Stations.size();
				Station& station0 = SelectElement(Stations, GetCorrectData(1, indStations));
				EditStation(station0);
			}
			break;
		}
		case 6:
		{
			if (Pipes.size() == 0) {
				cout << "\nNo pipes available!" << endl;
			}
			else {
				cout << "\n[6] Delete pipe: " << endl;
				cout << "Enter ID: ";
				int key0;
				cin >> key0;
				removeKeyIfExists(Pipes, key0);
			}
			break;
		}		
		case 7:
		{
			if (Stations.size() == 0) {
				cout << "\nNo stations available!" << endl;
			}
			else {
				cout << "\n[7] Delete station: " << endl;
				cout << "Enter ID: ";
				int key0;
				cin >> key0;
				removeKeyIfExists(Stations, key0);
			}
			break;
		}
		case 8:
		{
			cout << "\n[8] Save" << endl;
			ofstream fout;
			string fileName;
			cout << "Please, enter file: ";
			cin.ignore();
			getline(cin, fileName);
			fout.open(fileName);
			if (!fout.is_open())
			{
				cout << "Error in opening file!" << endl;
			}
			else {
				fout << Pipes.size() << endl;
				for (const auto& elem : Pipes)
					fout << elem.second;
				cout << "Pipe data has been saving succesfully!" << endl;

				fout << Stations.size() << endl;
				for (const auto& elem : Stations)
					fout << elem.second;
				cout << "Station data has been saving succesfully!" << endl;
			}
			fout.close();
			break;
		}
		case 9:
		{
			cout << "\n[9] Download" << endl;
			ifstream fin;
			string fileName;
			cout << "Please, enter file name: ";
			cin.ignore();
			getline(cin, fileName);
			fin.open(fileName);
			if (!fin.is_open())
			{
				cout << "Error in opening file!" << endl;
			}
			else {
				int pipesSize;
				fin >> pipesSize;
				if (pipesSize == 0)
					cout << "No info about pipes!" << endl;
				else {
					cout << "Pipe data has been uploaded succesfully!" << endl;
				}
				while (pipesSize-- > 0)
				{
					Pipe pipe0;
					fin >> pipe0;
					Pipes.insert({ pipe0.GetId(), pipe0 });
				}

				int csSize;
				fin >> csSize;
				if (csSize == 0)
					cout << "No info about CS!" << endl;
				else {
					cout << "Station data has been uploaded succesfully!" << endl;
				}
				while (csSize-- > 0)
				{
					Station station0;
					fin >> station0;
					Stations.insert({ station0.GetId(), station0 });
				}
				fin.close();
			}
			break;
		}
		case 10:
		{
			bool flag = true;
			while (flag) {
				cout << "\n[10] Search" << endl;
				cout << "What do you need to find?" << endl;
				cout << "1. Pipe" << endl;
				cout << "2. CS" << endl;
				cout << "3. Return" << endl;
				cout << "Please, enter command: ";
				switch (GetCorrectData(1, 3))
				{
				case 1:
					cout << "\nSearching pipe..." << endl;
					searchPipe(Pipes);
					break;
				case 2:
					cout << "\nSearching CS..." << endl;
					searchStation(Stations);
					break;
				case 3:
					flag = false;
					break;
				default:
					cout << "Please, enter the correct command!" << endl;
					break;
				}
			}
			break;
		}
		case 0:
		{
			return false;
			break;
		}
		default:
		{
			cout << endl << "There is no such command, please, try again" << endl;
			break;
		}	
		}
	}
	return 0;
}