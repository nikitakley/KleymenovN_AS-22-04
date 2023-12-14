#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <chrono>
#include <format>
#include "Pipe.h"
#include "Station.h"
#include "GTS.h"
#include "Utilities.h"

using namespace std;
using namespace chrono;

int main() 
{
	redirect_output_wrapper cerr_out(cerr);
	string time = format("{:%d_%m_%Y %H_%M_%OS}", system_clock::now() + hours(3));
	ofstream logfile("log_" + time);
	if (logfile)
		cerr_out.redirect(logfile);

	Pipe pipe0;
	Station station0;
	unordered_map<int, Pipe> Pipes = {};
	unordered_map<int, Station> Stations = {};
	GTS gts;
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
		cout << "11) Connect the pipe and CS" << endl;
		cout << "12) Show GTS" << endl;
		cout << "13) Delete GTS" << endl;
		cout << "14) Topological sort" << endl;
		cout << "0) Exit" << endl;
		cout << endl << "Please, enter the command number: ";
		switch (GetCorrectData(0, 14))
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
				gts.EditPipe(pipe0);
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
				gts.EditStation(station0);
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
					gts.searchPipe(Pipes);
					break;
				case 2:
					cout << "\nSearching CS..." << endl;
					gts.searchStation(Stations);
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
		case 11:
		{
			cout << "\n[11] Connect the pipe and CS..." << endl;
			if (Stations.size() < 2)
				cout << "CS not enough!" << endl;
			else
				gts.ConnectInGTS(Pipes, Stations);
			break;
		}
		case 12:
		{
			cout << "\n[12] Show GTS..." << endl;
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
			break;
		}
		case 13:
		{
			cout << "\n[13] Delete GTS..." << endl;
			if (Pipes.size() == 0)
				cout << "Pipes don`t exists!" << endl;
			else
			{
				cout << "Enter the ID of the pipe to delete: ";
				int delPipe;
				GetCorrectData(1, int(Pipes.size()));
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
			break;
		}
		case 14:
		{
			cout << "\n[14] Topological Sort..." << endl;
			vector<int> sortStations = gts.topologSort(Pipes, Stations);

			for (int id : sortStations)
			{
				cout << id << " ";
			}
			cout << endl;
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