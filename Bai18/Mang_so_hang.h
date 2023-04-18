#ifndef MANG_SO_HANG_H
#define MANG_SO_HANG_H

#include <iostream>
#include <initializer_list>
#include <ctime>
#include "So_hang.h"
using namespace std;

class Mang_so_hang {
	friend istream& operator>>(istream& is, Mang_so_hang& rhs);
	friend ostream& operator<<(ostream& os, const Mang_so_hang& rhs);
public:
	Mang_so_hang() {
		//cout << "Default constructor of Mang_dong has been called" << endl;
	}
	Mang_so_hang(int n);
	Mang_so_hang(initializer_list<So_hang> lst);
	Mang_so_hang(const Mang_so_hang& temp);
	Mang_so_hang& operator= (const Mang_so_hang& temp);
	So_hang& operator[](int index);
	const So_hang& operator[](int index) const;
	Mang_so_hang& push_back(const So_hang& temp);
	int get_size() const {
		return this->size;
	}
	~Mang_so_hang() {
		//cout << "Destructor of Mang_dong has been called" << endl;
		delete[] a;
	}
private:
	void extend();
	So_hang* a = new So_hang[1];
	int size = 0;
	int capacity = 1;
};

Mang_so_hang::Mang_so_hang(int n) {
	//cout << "Constructor of Mang_dong that take size argument has been called" << endl;
	size = n;
	capacity = 2 * n;
	a = new So_hang[capacity];
}

Mang_so_hang::Mang_so_hang(initializer_list<So_hang> lst) {
	//cout << "Constructor of Mang_dong that take list argument has been called" << endl;
	size = lst.size();
	capacity = 2 * size;
	a = new So_hang[capacity];
	int i = 0;
	for (const So_hang& c : lst) {
		a[i++] = c;
	}
}

Mang_so_hang::Mang_so_hang(const Mang_so_hang& temp) {
	//cout << "Copy constructor of Mang_dong has been called" << endl;
	size = temp.size;
	capacity = 2 * size;
	a = new So_hang[capacity];
	for (int i = 0; i < size; ++i) {
		a[i] = temp.a[i];
	}
}

Mang_so_hang& Mang_so_hang::operator= (const Mang_so_hang& temp) {
	//cout << "Assignment operator of Mang_dong has been called" << endl;
	delete[] a;
	size = temp.size;
	capacity = 2 * size;
	a = new So_hang[capacity];
	for (int i = 0; i < size; ++i) {
		a[i] = temp.a[i];
	}
	return *this;
}

istream& operator>>(istream& is, Mang_so_hang& rhs) {
	for (int i = 0; i < rhs.size; ++i) {
		cout << "Nhap so hang thu " << i+1 << " :" << endl;
		is >> rhs.a[i];
	}
	return is;
}
ostream& operator<<(ostream& os, const Mang_so_hang& rhs) {
	if (rhs.size == 0) {
		os << "Mang ko co phan tu";
		return os;
	}
	for (int i = 0; i < rhs.size; ++i) {
		os << rhs.a[i] << " ";
	}
	return os;
}

void Mang_so_hang::extend() {
	//cout << "Extend method has been called" << endl;
	capacity = 2 * capacity;
	So_hang* temp = new So_hang[capacity];
	for (int i = 0; i < size; ++i) {
		temp[i] = a[i];
	}
	delete[] a;
	a = temp;
}

Mang_so_hang& Mang_so_hang::push_back(const So_hang& temp) {
	if (size == capacity) {
		this->extend();
	}
	a[size] = temp;
	++size;
	return *this;
}

So_hang& Mang_so_hang::operator[](int index) { 
	if (index >= size) {
		cout << "ERROR: index out of range" << endl;
	}
	return a[index]; 
}

const So_hang& Mang_so_hang::operator[](int index) const {
	if (index >= size) {
		cout << "ERROR: index out of range" << endl;
	}
	return a[index];
}

#endif

