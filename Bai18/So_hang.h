#ifndef SO_HANG_H
#define SO_HANG_H

#include <iostream>
using namespace std;

class So_hang {
	friend class Da_thuc;
	friend class Mang_so_hang;
	friend ostream& operator<< (ostream&, const So_hang&);
	friend istream& operator>> (istream&, So_hang&);
public:
	So_hang() = default;
	So_hang(int a, int b) : he_so(a), so_mu(b) {}
	So_hang(const So_hang& temp) {
		he_so = temp.he_so;
		so_mu = temp.so_mu;
	}
	So_hang& operator= (const So_hang& temp) {
		he_so = temp.he_so;
		so_mu = temp.so_mu;
		return *this;
	}
	int get_value(int x) const { return he_so * pow(x, so_mu); }
	int get_so_mu() const { return so_mu; }
	So_hang operator+ (const So_hang&) const;
	So_hang operator- (const So_hang&) const;
	~So_hang() = default;
private:
	int he_so = 0;
	int so_mu = 0;
};

So_hang So_hang::operator+ (const So_hang& rhs) const{
	So_hang ret(he_so + rhs.he_so, so_mu);
	return ret;
}

So_hang So_hang::operator- (const So_hang& rhs) const {
	So_hang ret(he_so - rhs.he_so, so_mu);
	return ret;
}

ostream& operator<< (ostream& os, const So_hang& rhs) {
	os << rhs.he_so << "*x^" << rhs.so_mu;
	return os;
}
istream& operator>> (istream& is, So_hang& rhs) {
	cout << "He so: ";
	is >> rhs.he_so;
	cout << "So mu: ";
	is >> rhs.so_mu;
	return is;
}

#endif