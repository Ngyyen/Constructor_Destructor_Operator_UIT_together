#include <iostream>
using namespace std;

class Duong_thang {
	friend ostream& operator<< (ostream& os, const Duong_thang& rhs);
	friend istream& operator>> (istream& is, Duong_thang& rhs);
private:
	int a = 0;
	int b = 0;
public:
	Duong_thang() = default;
	Duong_thang(const Duong_thang& temp) {
		a = temp.a;
		b = temp.b;
	}
	Duong_thang(int aa, int bb) : a(aa), b(bb) {}
	Duong_thang& operator= (const Duong_thang& temp) {
		a = temp.a;
		b = temp.b;
		return *this;
	}
	~Duong_thang() = default;
};

ostream& operator<< (ostream& os, const Duong_thang& rhs) {
	os << "y = " << rhs.a << " x + " << rhs.b;
	return os;
}
istream& operator>> (istream& is, Duong_thang& rhs) {
	cout << "Nhap a :";
	is >> rhs.a;
	cout << "Nhap b:";
	is >> rhs.b;
}





