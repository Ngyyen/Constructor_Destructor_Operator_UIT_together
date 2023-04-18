#include <iostream>
using namespace std;

class So_phuc {
	friend ostream& operator<< (ostream&, const So_phuc&);
	friend istream& operator>> (istream&, So_phuc&);
	friend So_phuc operator+ (const So_phuc&, const So_phuc&);
	friend So_phuc operator- (const So_phuc&, const So_phuc&);
	friend So_phuc operator/ (const So_phuc&, const So_phuc&);
	friend So_phuc operator* (const So_phuc&, const So_phuc&);
public:
	So_phuc() = default;
	So_phuc(double a, double b) : thuc(a), ao(b) {}
	So_phuc(const So_phuc& temp) {
		thuc = temp.thuc;
		ao = temp.ao;
	}
	So_phuc& operator= (const So_phuc& temp) {
		thuc = temp.thuc;
		ao = temp.ao;
		return *this;
	}
	~So_phuc() = default;
private:
	double thuc = 0.0;
	double ao = 0.0;
};

So_phuc operator+ (const So_phuc& lhs, const So_phuc& rhs) {
	return So_phuc(lhs.thuc + rhs.thuc, lhs.ao + rhs.ao);
}

So_phuc operator- (const So_phuc& lhs, const So_phuc& rhs) {
	return So_phuc(lhs.thuc - rhs.thuc, lhs.ao - rhs.ao);
}
So_phuc operator/ (const So_phuc& lhs, const So_phuc& rhs) {
	So_phuc ret;
	ret.thuc = (lhs.thuc * rhs.thuc + lhs.ao * rhs.ao) / (rhs.thuc * rhs.thuc + rhs.ao * rhs.ao);
	ret.ao = (rhs.thuc * lhs.ao - lhs.thuc * rhs.ao) / (rhs.thuc * rhs.thuc + rhs.ao * rhs.ao);
	return ret;
}
So_phuc operator* (const So_phuc& lhs, const So_phuc& rhs) {
	So_phuc ret;
	ret.thuc = lhs.thuc * rhs.thuc - lhs.ao * rhs.ao;
	ret.ao = lhs.thuc * rhs.ao + rhs.ao * lhs.thuc;
	return ret;
}

ostream& operator<< (ostream& os, const So_phuc& rhs) {
	os << rhs.thuc << " + " << rhs.ao << "i";
	return os;
}

istream& operator>> (istream& is, So_phuc& rhs) {
	cout << "Nhap phan thuc : ";
	is >> rhs.thuc;
	cout << "Nhap phan ao : ";
	is >> rhs.ao;
	return is;
}