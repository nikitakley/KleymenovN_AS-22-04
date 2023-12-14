#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

template <typename T>
T GetCorrectData(T min, T max)
{
	T x;
	while ((std::cin >> x).fail() || std::cin.peek() != '\n' || x < min || x > max)
	{
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		std::cout << "\nPlease, enter the correct data! Data must be in the range [" << min << " - " << max << "]";
		std::cout << "\nTry again: ";
	}
	cerr << x << endl;

	return x;
}

template <typename T>
T GetCorrectDiameter(T min, T max)
{
	T diam;
	cin >> diam;
	while (((diam != 500) && (diam != 700) && (diam != 1000) && (diam != 1400)) || diam < min || diam > max || cin.fail() || cin.peek() != '\n')
	{
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Please, enter the correct pipe diameter [500, 700, 1000, 1400]: ";
		cin >> diam;
	}
	return diam;
}

template <typename T>
T& SelectElement(unordered_map<int, T>& notes, int key)
{
	auto it = notes.find(key);
	if (it != notes.end())
	{
		return it->second;
	}
	else
	{
		cout << "Exceeding the number of available elements!" << endl
			<< "Please, try again (number of elements: " << notes.size() << "): ";
	}
}


template <typename K>
unordered_map<int, K> removeKeyIfExists(std::unordered_map<int, K>& notes, int key) {
	if (notes.find(key) != notes.end()) {
		notes.erase(key);
		cout << "Removal was succesful!" << endl;
		return notes;
	}
	else {
		cout << "Key " << key << " does not exist!\nPlease enter a valid key: ";
		int newKey;
		cin >> newKey;
		return removeKeyIfExists(notes, newKey);
	}
}

class redirect_output_wrapper
{
	std::ostream& stream;
	std::streambuf* const old_buf;
public:
	redirect_output_wrapper(std::ostream& src)
		:old_buf(src.rdbuf()), stream(src)
	{
	}

	~redirect_output_wrapper() {
		stream.rdbuf(old_buf);
	}
	void redirect(std::ostream& dest)
	{
		stream.rdbuf(dest.rdbuf());
	}
};