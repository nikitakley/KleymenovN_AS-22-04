#include "Pipe.h"
#include "Utilities.h"

int Pipe::maxId = 0;

int Pipe::GetId()
{
    return Id;
}

int Pipe::GetDiametr() const
{
	return pipeDiameter;
}

string Pipe::GetName() const
{
    return pipeName;
}

bool Pipe::GetStatus()
{
    return pipeRepair;
}

void Pipe::PrintPipeRepair()
{
	if (pipeRepair == true)
	{
		cout << "Pipe under repair [=1]\n";
	}
	else
		cout << "Pipe is not in repair [=0]\n";
}

bool Pipe::ConnectionNotBusy() const
{
	return CSid1 < 1 || CSid2 < 1;
}

void Pipe::Connect(const int& id1, const int& id2)
{
	CSid1 = id1;
	CSid2 = id2;
}

void Pipe::DeleteConnection()
{
	CSid1 = 0;
	CSid2 = 0;
}

istream& operator >> (istream& in, Pipe& newPipe)
{
	newPipe.Id = ++newPipe.maxId;
	cout << "ID: " << newPipe.Id << endl;
	cout << "Enter the name of the pipe: ";
	in.ignore();
	getline(in, newPipe.pipeName);
	cout << "Enter the length of the pipe (in metres): ";
	newPipe.pipeLength = GetCorrectData(100.0, 1200.0);
	cout << "Enter the pipe diameter (in millimetres): ";
	newPipe.pipeDiameter = GetCorrectDiameter(500, 1400);
	cout << "Enter the repair status: ";
	newPipe.pipeRepair = GetCorrectData(0, 1);
	return in;
}

ostream& operator << (ostream& out, const Pipe& newPipe)
{
	if (newPipe.pipeName == "None")
	{
		out << "No pipes available!\n";
	}
	else
	{
		out << "ID: " << newPipe.Id << "\tName: " << newPipe.pipeName << "\tLength: " << newPipe.pipeLength
			<< "\tDiameter: " << newPipe.pipeDiameter << "\tRepair: " << newPipe.pipeRepair << endl;
	}
	return out;
}

ifstream& operator >> (ifstream& fin, Pipe& newPipe)
{
	fin >> newPipe.Id;
	newPipe.maxId = newPipe.Id;
	fin.ignore();
	getline(fin, newPipe.pipeName);
	fin >> newPipe.pipeLength;
	fin >> newPipe.pipeDiameter;
	fin >> newPipe.pipeRepair;
	return fin;
}

ofstream& operator << (ofstream& fout, const Pipe& newPipe)
{
	fout << newPipe.Id << endl;
	fout << newPipe.pipeName << endl;
	fout << newPipe.pipeLength << endl;
	fout << newPipe.pipeDiameter << endl;
	fout << newPipe.pipeRepair << endl;
	return fout;
}
