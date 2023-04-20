#ifndef PHAN_SO_H
#define PHAN_SO_H

#include <iostream>
#include <numeric>
using namespace std;

class Phan_so {
private:
	int tu = 0;
	int mau = 1;
public:
	// nhom khoi tao
	friend istream& operator>>(istream&, Phan_so&);
	void Khoi_tao();
	void Khoi_tao(int);
	void Khoi_tao(int, int);
	void Khoi_tao(const Phan_so&);
	Phan_so();
	Phan_so(int);
	Phan_so(int a, int b) : tu(a), mau(b) { }
	Phan_so(const Phan_so& temp) {
		tu = temp.tu;
		mau = temp.mau;
	}
	// nhom cung cap thong tin
	int get_tu();
	int get_mau();
	double get_value() const;
	friend ostream& operator<<(ostream&, const Phan_so&);
	void Xuat();
	// nhom cap nhat thong tin
	void set_tu(int);
	void set_mau(int);
	Phan_so& operator= (const Phan_so& temp);
	// nhom kiem tra
	bool is_co_nghia();
	bool is_toi_gian();
	bool is_zero();
	bool is_duong();
	bool is_am();
	bool operator> (const Phan_so&);
	bool operator< (const Phan_so&);
	bool operator>= (const Phan_so&);
	bool operator<= (const Phan_so&);
	bool operator== (const Phan_so&);
	bool operator!= (const Phan_so&);
	// nhom xu ly
	~Phan_so() = default;
	void rut_gon();
	Phan_so tong(const Phan_so&);
	Phan_so hieu(const Phan_so&);
	Phan_so tich(const Phan_so&);
	Phan_so thuong(const Phan_so&);
	Phan_so operator+ (const Phan_so&);
	Phan_so operator- (const Phan_so&);
	Phan_so operator* (const Phan_so&);
	Phan_so operator/ (const Phan_so&);
	Phan_so& operator++(); //++a
	Phan_so& operator--(); //--a
	Phan_so operator++(int); //a++
	Phan_so operator--(int); //a--
	Phan_so& operator+= (const Phan_so&);
	Phan_so& operator-= (const Phan_so&);
	Phan_so& operator*= (const Phan_so&);
	Phan_so& operator/= (const Phan_so&);
	
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
void Phan_so::Khoi_tao() {
	tu = 0;
	mau = 1;
}
void Phan_so::Khoi_tao(int a) {
	tu = a;
	mau = 1;
}
void Phan_so::Khoi_tao(int a, int b) {
	tu = a;
	mau = b;
}
void Phan_so::Khoi_tao(const Phan_so& temp) {
	tu = temp.tu;
	mau = temp.mau;
}
Phan_so::Phan_so() {
	tu = 0;
	mau = 1;
}
Phan_so::Phan_so(int a) {
	tu = a;
	mau = 1;
}
Phan_so::Phan_so(int a, int b) : tu(a), mau(b) { }
Phan_so::Phan_so(const Phan_so& temp) {
	tu = temp.tu;
	mau = temp.mau;
}
int Phan_so::get_tu() {
	return tu;
}
int Phan_so::get_mau() {
	return mau;
}
double Phan_so::get_value() const {
	return (double)tu / mau;
}
ostream& operator<<(ostream& os, const Phan_so& ps) {
	os << ps.tu << "/" << ps.mau;
	return os;
}
void Phan_so::Xuat() {
	cout << tu << "/" << mau << endl;
}
void Phan_so::set_tu(int tu) {
	this->tu = tu;
}
void Phan_so::set_mau(int mau) {
	if (mau == 0) {
		cout << "ERROR: mau ko the bang 0" << endl;
		return;
	}
	this->mau = mau;
}
Phan_so& Phan_so::operator= (const Phan_so& temp) {
	tu = temp.tu;
	mau = temp.mau;
	return *this;
}
bool Phan_so::is_co_nghia() {
	if (mau == 0) 
		return false;
	return true;
}
bool Phan_so::is_toi_gian() {
	if (gcd(tu, mau) == 1)
		return true;
	return false;
}
bool Phan_so::is_zero() {
	if (tu == 0)
		return true;
	return false;
}
bool Phan_so::is_duong() {
	if (tu * mau > 0)
		return true;
	return false;
}
bool Phan_so::is_am() {
	if (tu * mau < 0)
		return true;
	return false;
}

bool Phan_so::operator> (const Phan_so& x) {
	if (this->get_value() > x.get_value())
		return true;
	return false;
}
bool Phan_so::operator< (const Phan_so& x) {
	if (this->get_value() < x.get_value())
		return true;
	return false;
}
bool Phan_so::operator>= (const Phan_so& x) {
	if (this->get_value() >= x.get_value())
		return true;
	return false;
}
bool Phan_so::operator<= (const Phan_so& x) {
	if (this->get_value() <= x.get_value())
		return true;
	return false;
}
bool Phan_so::operator== (const Phan_so& x) {
	if (this->get_value() == x.get_value())
		return true;
	return false;
}
bool Phan_so::operator!= (const Phan_so& x) {
	if (this->get_value() != x.get_value())
		return true;
	return false;
}
void Phan_so::rut_gon() {
	int ucln = gcd(tu, mau);
	tu = tu / ucln;
	mau = mau / ucln;
}
Phan_so Phan_so::tong(const Phan_so& x) {
	Phan_so temp;
	temp.tu = x.tu * mau + tu * x.mau;
	temp.mau = x.mau * mau;
	return temp;
}
Phan_so Phan_so::hieu(const Phan_so& x) {
	Phan_so temp;
	temp.tu = x.tu * mau - tu * x.mau;
	temp.mau = x.mau * mau;
	return temp;
}
Phan_so Phan_so::tich(const Phan_so& x) {
	Phan_so temp;
	temp.tu = tu * x.tu;
	temp.mau = mau * x.mau;
	return temp;
}
Phan_so Phan_so::thuong(const Phan_so& x) {
	Phan_so temp;
	temp.tu = tu * x.mau;
	temp.mau = mau * x.tu;
	return temp;
}
Phan_so Phan_so::operator+ (const Phan_so& x) {
	Phan_so temp;
	temp.tu = x.tu * mau + tu * x.mau;
	temp.mau = x.mau * mau;
	return temp;
}
Phan_so Phan_so::operator- (const Phan_so& x) {
	Phan_so temp;
	temp.tu = x.tu * mau - tu * x.mau;
	temp.mau = x.mau * mau;
	return temp;
}
Phan_so Phan_so::operator* (const Phan_so& x) {
	Phan_so temp;
	temp.tu = tu * x.tu;
	temp.mau = mau * x.mau;
	return temp;
}
Phan_so Phan_so::operator/ (const Phan_so& x) {
	Phan_so temp;
	temp.tu = tu * x.mau;
	temp.mau = mau * x.tu;
	return temp;
}
Phan_so& Phan_so::operator+= (const Phan_so& x) {
	tu = x.tu * mau + tu * x.mau;
	mau = x.mau * mau;
	return *this;
}
Phan_so& Phan_so::operator-= (const Phan_so& x) {
	tu = tu * x.mau - x.tu * mau;
	mau = x.mau * mau;
	return *this;
}
Phan_so& Phan_so::operator*= (const Phan_so& x) {
	tu = tu * x.tu;
	mau = mau * x.mau;
	return *this;
}
Phan_so& Phan_so::operator/= (const Phan_so& x) {
	tu = tu * x.mau;
	mau = mau * x.tu;
	return *this;
}
Phan_so& Phan_so::operator++() {
	*this += Phan_so(1);
	return *this;
}//++a
Phan_so& Phan_so::operator--() {
	*this -= Phan_so(1);
	return *this;
} //--a
Phan_so Phan_so::operator++(int) {
	Phan_so ret = *this;
	++ *this;
	return ret;
} //a++
Phan_so Phan_so::operator--(int) {
	Phan_so ret = *this;
	-- *this;
	return ret;
} //a--

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

#endif