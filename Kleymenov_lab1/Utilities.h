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
	return x;
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