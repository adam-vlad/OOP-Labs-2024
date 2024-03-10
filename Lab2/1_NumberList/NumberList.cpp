#include "NumberList.h"
#include <iostream>

using namespace std;

void NumberList::Init() {
	countt = 0;
}

bool NumberList::Add(int val) {
	if (countt >= 10) {
		cout << "Nu se mai pot adauga numere\n";
		return false;
	}
	else {
		cout << "A fost adaugat " << val << "\n";
		numbers[countt++] = val;
		return true;
	}
}

void NumberList::Sort() {
	for (int i = 0; i < countt - 1; i++)
		for (int j = i + 1; j < countt; j++)
			if (numbers[i] > numbers[j])
				swap(numbers[i], numbers[j]);
}

void NumberList::Print() {
	for (int i = 0; i < countt; i++)
		cout << numbers[i] << " ";

	cout << "\n";
}