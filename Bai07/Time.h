#include <iostream>
#include <string>
using namespace std;

class Thoi_gian {
	friend ostream& operator<< (ostream& os, const Thoi_gian& rhs);
	friend istream& operator>> (istream& is, Thoi_gian& rhs);
private:
	int gio = 0;
	int phut = 0;
	int giay = 0;
public:
	Thoi_gian() = default;
	Thoi_gian(const Thoi_gian& temp) {
		gio = temp.gio;
		giay = temp.giay;
		phut = temp.phut;
	}
	Thoi_gian(int g, int p, int s) : gio(g), phut(p), giay(s) {}
	Thoi_gian& operator= (const Thoi_gian& temp) {
		gio = temp.gio;
		giay = temp.giay;
		phut = temp.phut;
		return *this;
	}
	~Thoi_gian() = default;
};

ostream& operator<< (ostream& os, const Thoi_gian& rhs) {
	os << rhs.gio << ":" << rhs.phut << ":" << rhs.giay;
	return os;
}

istream& operator>> (istream& is, Thoi_gian& rhs) {
	cout << "Nhap gio: ";
	is >> rhs.gio;
	cout << "Nhap phut: ";
	is >> rhs.phut;
	cout << "Nhap giay: ";
	is >> rhs.giay;
	return is;
}
