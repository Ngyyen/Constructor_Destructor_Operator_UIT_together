
#ifndef PHAN_SO_H
#define PHAN_SO_H

#include <iostream>
#include <numeric>
using namespace std;

class Phan_so {
	friend istream& operator>>(istream&, Phan_so&);
	friend ostream& operator<<(ostream&, const Phan_so&);
	friend bool operator> (const Phan_so&, const Phan_so&);
private:
	int tu = 0;
	int mau = 1;
public:
	Phan_so() = default;
	Phan_so(int a, int b) : tu(a), mau(b) { }
	Phan_so(const Phan_so& temp) {
		tu = temp.tu;
		mau = temp.mau;
	}
	Phan_so& operator= (const Phan_so& temp) {
		tu = temp.tu;
		mau = temp.mau;
		return *this;
	}
	double get_double() const;
	Phan_so& rut_gon();
	Phan_so reverse() const;
	int kt_am_duong() const;
	~Phan_so() = default;
};

istream& operator>>(istream& is, Phan_so& ps) {
	cout << "Nhap tu: ";
	is >> ps.tu;
	cout << "Nhap mau: ";
	is >> ps.mau;
	if (ps.mau == 0) {
		cout << "Mau ko hop le" << endl;
		ps.tu = 0;
		ps.mau = 1;
	}
	return is;
}

ostream& operator<<(ostream& os, const Phan_so& ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}

double Phan_so::get_double() const {
	return (tu * 1.0) / (mau * 1.0);
}

Phan_so& Phan_so::rut_gon() {
	int ucln = gcd(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
	return *this;
}

Phan_so Phan_so::reverse() const {
	Phan_so ret(mau, tu);
	return ret;
}

int Phan_so::kt_am_duong() const {
	if (this->get_double() > 0) {
		return 1;
	}
	if (this->get_double() < 0) {
		return -1;
	}
	return 0;
}

bool operator> (const Phan_so& lhs, const Phan_so& rhs) {
	return lhs.get_double() > rhs.get_double();
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}



#endif