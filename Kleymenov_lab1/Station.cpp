#include "Station.h"
#include "Utilities.h"

int Station::maxId = 0;

int Station::GetId()
{
    return Id;
}

string Station::GetName() const
{
    return stationName;
}

int Station::GetWorkshops() const
{
    return stationWorkshops;
}

int Station::GetActWorkshops() const
{
    return stationActWorkshops;
}

int Station::GetPercentOfNonActiveWorkshops() const
{
    return (stationWorkshops - stationActWorkshops) * 100 / stationWorkshops;
}

void Station::PrintWorkshops() const
{
    cout << "at the moment " << stationActWorkshops << 
        " out of " << stationWorkshops << " workshops are working" << endl;
}

istream& operator >> (istream& in, Station& newStation)
{
	newStation.Id = ++newStation.maxId;
	cout << "ID: " << newStation.Id << endl;
	cout << "Enter CS name: ";
	in.ignore();
	getline(in, newStation.stationName);
    cout << "Enter the number of workshops: ";
    newStation.stationWorkshops = GetCorrectData(1, 12);
    cout << "Enter the number of active workshops: ";
    newStation.stationActWorkshops = GetCorrectData(1, newStation.stationWorkshops);
    cout << "Enter the efficiency of CS (from 0 to 1 with tenths): ";
    newStation.stationEfficiency = GetCorrectData(0.0, 1.0);
	return in;
}

ostream& operator << (ostream& out, const Station& newStation)
{
	if (newStation.stationName == "None")
	{
		out << "No CS available!\n";
	}
	else
	{
		out << "ID: " << newStation.Id << "\tName: " << newStation.stationName << "\tWorkshops: " << newStation.stationWorkshops
			<< "\tActive workshops: " << newStation.stationActWorkshops << "\tEfficiency: " << newStation.stationEfficiency << endl;
	}
	return out;
}

ifstream& operator >> (ifstream& fin, Station& newStation)
{
    fin >> newStation.Id;
    newStation.maxId = newStation.Id;
    fin.ignore();
    getline(fin, newStation.stationName);
    fin >> newStation.stationWorkshops;
    fin >> newStation.stationActWorkshops;
    fin >> newStation.stationEfficiency;
    return fin;
}

ofstream& operator << (ofstream& fout, const Station& newStation)
{
    fout << newStation.Id << endl;
    fout << newStation.stationName << endl;
    fout << newStation.stationWorkshops << endl;
    fout << newStation.stationActWorkshops << endl;
    fout << newStation.stationEfficiency << endl;
    return fout;
}

