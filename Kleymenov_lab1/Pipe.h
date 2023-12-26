#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Pipe
{
public:
	static int maxId;
	int Id;
	string pipeName = "None";
	double pipeLength = 0.0;
	int pipeDiameter = 0;
	bool pipeRepair = false;
	int CSid1 = 0;
	int CSid2 = 0;
	bool free = 1;

	int GetId();
	int GetDiametr() const;

	string GetName() const;
	bool GetStatus();
	void PrintPipeRepair();
	bool ConnectionNotBusy() const;
	void Connect(const int& id1, const int& id2);
	void DeleteConnection();

	//friend void EditPipe(Pipe& pipe);
	//friend void EditPipes(vector <Pipe*>& pipes);
	friend ostream& operator << (ostream& out, const Pipe& newPipe);
	friend istream& operator >> (istream& in, Pipe& newPipe);
	friend ofstream& operator << (ofstream& fout, const Pipe& newPipe);
	friend ifstream& operator >> (ifstream& fin, Pipe& newPipe);
};

