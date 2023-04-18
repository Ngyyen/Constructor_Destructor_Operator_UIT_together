#pragma once
#include <iostream>
#include "Mang_dong.h"
using namespace std;

class Ma_tran_dong {
	friend istream& operator>>(istream& is, Ma_tran_dong& rhs);
	friend ostream& operator<<(ostream& os, const Ma_tran_dong& rhs);
public:
	Ma_tran_dong() {
		cout << "Default constructor of Ma_tran_dong has been called" << endl;
	}
	Ma_tran_dong(int n, int m) {
		cout << "Constructor of Ma_tran_dong that take row and col argument has been called" << endl;
		row = n;
		col = m;
		a = new Mang_dong[row];
		for (int i = 0; i < row; ++i) {
			a[i] = Mang_dong(col);
		}
	}
	Ma_tran_dong(initializer_list<Mang_dong> lst) {
		cout << "Constructor of Ma_tran_dong that take list argument has been called" << endl;
		row = lst.size();
		col = lst.begin()->size;
		a = new Mang_dong[row];
		int i = 0;
		for (const Mang_dong& temp : lst) {
			a[i++] = temp;
		}
	}
	Ma_tran_dong(const Ma_tran_dong& temp) {
		cout << "Copy constructor of Ma_tran_dong has been called" << endl;
		row = temp.row;
		col = temp.col;
		a = new Mang_dong[row];
		for (int i = 0; i < row; ++i) {
			a[i] = temp.a[i];
		}
	}
	Ma_tran_dong& operator= (const Ma_tran_dong& temp) {
		cout << "Assignment operator of Ma_tran_dong has been called" << endl;
		delete[] a;
		row = temp.row;
		col = temp.col;
		a = new Mang_dong[row];
		for (int i = 0; i < row; ++i) {
			a[i] = temp.a[i];
		}
		return *this;
	}
	~Ma_tran_dong() {
		cout << "Destructor of Ma_tran_dong has been called" << endl;
		delete[] a;
	}
private:
	Mang_dong* a = NULL;
	int row = 0;
	int col = 0;
};

istream& operator>>(istream& is, Ma_tran_dong& rhs) {
	for (int i = 0; i < rhs.row; ++i) {
		cout << "Nhap hang thu " << i << " :" << endl;
		is >> rhs.a[i];
	}
	return is;
}

ostream& operator<<(ostream& os, const Ma_tran_dong& rhs) {
	if (rhs.row == 0 || rhs.col == 0) {
		cout << "Ma tran ko co phan tu";
		return os;
	}
	for (int i = 0; i < rhs.row; ++i) {
		os << rhs.a[i] << endl;
	}
	return os;
}
