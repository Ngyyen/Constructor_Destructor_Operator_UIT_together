#pragma once
#include <iostream>
#include <vector>
#include <initializer_list>
#include <cmath>
#include "So_hang.h";
#include "Mang_so_hang.h";
using namespace std;

class Da_thuc {
	friend ostream& operator<< (ostream&, const Da_thuc&);
	friend istream& operator>> (istream&, Da_thuc&);
public:
	Da_thuc() = default;
	Da_thuc(int n) {
		for (int i = 0; i <= n; ++i) {
			vec.push_back(So_hang(0, i));
		}
	}
	Da_thuc(initializer_list<So_hang> list) : vec(list) {}
	So_hang& get_sohang(int i) { return vec[i]; }
	const So_hang& get_sohang(int i) const { return vec[i]; }
	int calculate(int x);
	Da_thuc operator+ (Da_thuc& rhs);
	Da_thuc operator- (Da_thuc& rhs);

private:
	static int tim_somu_max(const Mang_so_hang& temp);
	Mang_so_hang vec;
};

ostream& operator<< (ostream& os, const Da_thuc& rhs) {
	os << rhs.get_sohang(0);
	for (int i = 1; i < rhs.vec.get_size(); ++i) {
		os << " + " << rhs.get_sohang(i);
	}
	return os;
}

istream& operator>> (istream& is, Da_thuc& rhs) {
	Mang_so_hang temp;
	int n;
	cout << "Nhap so so hang: ";
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cout << "Nhap so hang thu " << i + 1 << " :" << endl;
		So_hang item;
		cin >> item;
		temp.push_back(item);
	}
	int size = Da_thuc::tim_somu_max(temp);
	for (int i = 0; i <= size; ++i) {
		rhs.vec.push_back(So_hang(0, i));
	}
	for (int i = 0; i < temp.get_size(); ++i) {
		rhs.vec[temp[i].get_so_mu()] = temp[i];
	}
	return is;
}

Da_thuc Da_thuc::operator+ (Da_thuc& rhs) {
	Da_thuc bigger, smaller;
	if (this->vec.get_size() >= rhs.vec.get_size()) {
		bigger = *this;
		smaller = rhs;
	}
	else {
		bigger = rhs;
		smaller = *this;
	}
	for (int i = 0; i < smaller.vec.get_size(); ++i) {
		bigger.get_sohang(i) = bigger.get_sohang(i) + smaller.get_sohang(i);
	}
	return bigger;
}

Da_thuc Da_thuc::operator- (Da_thuc& rhs) {
	Da_thuc bigger, smaller;
	if (this->vec.get_size() >= rhs.vec.get_size()) {
		bigger = *this;
		smaller = rhs;
	}
	else {
		bigger = rhs;
		smaller = *this;
	}
	for (int i = 0; i < smaller.vec.get_size(); ++i) {
		bigger.get_sohang(i) = bigger.get_sohang(i) - smaller.get_sohang(i);
	}
	return bigger;
}

int Da_thuc::tim_somu_max(const Mang_so_hang& temp) {
	int max = 0;
	for (int i = 0; i < temp.get_size(); ++i) {
		if (temp[i].so_mu > max) {
			max = temp[i].so_mu;
		}
	}
	return max;
}

int Da_thuc::calculate(int x) {
	int ret = 0;
	for (int i = 0; i < vec.get_size(); ++i) {
		ret += vec[i].get_value(x);
	}
	return ret;
}


