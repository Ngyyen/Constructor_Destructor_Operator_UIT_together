#pragma once
#include <iostream>
#include <initializer_list>
#include <ctime>
using namespace std;

class Mang_dong {
	friend class Ma_tran_dong;
	friend istream& operator>>(istream& is, Mang_dong& rhs);
	friend ostream& operator<<(ostream& os, const Mang_dong& rhs);
public:
	Mang_dong() {
		cout << "Default constructor of Mang_dong has been called" << endl;
		a = NULL;
		size = 0;
	}
	Mang_dong(int n) {
		cout << "Constructor of Mang_dong that take size argument has been called" << endl;
		size = n;
		a = new int[size];
		for (int i = 0; i < size; ++i) {
			a[i] = 0;
		}
	}
	Mang_dong(initializer_list<int> lst) {
		cout << "Constructor of Mang_dong that take list argument has been called" << endl;
		size = lst.size();
		a = new int[size];
		int i = 0;
		for (int c : lst) {
			a[i++] = c;
		}
	}
	Mang_dong(const Mang_dong& temp) {
		cout << "Copy constructor of Mang_dong has been called" << endl;
		size = temp.size;
		a = new int[size];
		for (int i = 0; i < size; ++i) {
			a[i] = temp.a[i];
		}
	}
	Mang_dong& operator= (const Mang_dong& temp) {
		cout << "Assignment operator of Mang_dong has been called" << endl;
		delete[] a;
		size = temp.size;
		a = new int[size];
		for (int i = 0; i < size; ++i) {
			a[i] = temp.a[i];
		}
		return *this;
	}
	int count(int x) {
		int dem = 0;
		for (int i = 0; i < size; ++i) {
			if (a[i] == x) {
				++dem;
			}
		}
		return dem;
	}
	bool is_ascend() {
		for (int i = 0; i < size - 1; ++i) {
			if (a[i] > a[i + 1]) {
				return false;
			}
		}
		return true;
	}
	~Mang_dong() {
		cout << "Destructor of Mang_dong has been called" << endl;
		delete[] a;
	}
private:
	int* a = NULL;
	int size = 0;
};

istream& operator>>(istream& is, Mang_dong& rhs) {
	for (int i = 0; i < rhs.size; ++i) {
		cout << "Nhap phan tu thu " << i << " :";
		is >> rhs.a[i];
	}
	return is;
}
ostream& operator<<(ostream& os, const Mang_dong& rhs) {
	if (rhs.size == 0) {
		os << "Mang ko co phan tu";
		return os;
	}
	for (int i = 0; i < rhs.size; ++i) {
		os << rhs.a[i] << " ";
	}
	return os;
}