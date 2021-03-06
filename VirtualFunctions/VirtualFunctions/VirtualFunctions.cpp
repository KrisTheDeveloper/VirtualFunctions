// VirtualFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

class Person
{
protected:
	string sName;
	int nAge;
	//int cur_id = 0;

public:
	virtual void getdata() = 0;

	virtual void putdata() = 0;
	
};

class Professor : public Person
{
protected:
	int publication;
	int cur_id = 0;
	static int id;

public:
	Professor()
	{
		this->cur_id = ++id;
	}
	void getdata()
	{
		cin >> this->sName >> this->nAge >> this->publication;
	}

	void putdata()
	{
		cout << this->sName << this->nAge << this->publication << this->cur_id;
	}
};

int Professor::id = 0;

class Student : public Person
{
protected:
	vector<int> marks;
	int cur_id = 0;
	static int id;

public:
	Student() {
		this->cur_id = ++id;
	}
	void getdata()
	{
		cin >> this->sName >> this->nAge;
		for (int i = 0; i < 6; i++)
		{
			int input;
			cin >> input;
			this->marks.push_back(input);
		}
	}

	void putdata()
	{
		int sum = accumulate(marks.begin(), marks.end(), 0);
		cout << this->sName << this->nAge << sum << this->cur_id;
	}
};
int Student::id = 0;
int main()
{
	const int n = 6;
	int val;
	Person *per[n];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;
}
