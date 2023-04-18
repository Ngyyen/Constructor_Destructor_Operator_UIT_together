#include <iostream>
using namespace std;

class Hon_so {
	friend istream& operator>> (istream& is, Hon_so& rhs);
	friend ostream& operator<< (ostream& os, const Hon_so& rhs);
private:
	int nguyen = 0;
	int tu = 0;
	int mau = 0;
public:
	Hon_so() = default;
	Hon_so(const Hon_so& temp) {
		nguyen = temp.nguyen;
		tu = temp.tu;
		mau = temp.mau;
	}
	Hon_so(int a, int b, int c) : nguyen(a), tu(b), mau(c) {}
	Hon_so& operator= (const Hon_so& temp) {
		nguyen = temp.nguyen;
		tu = temp.tu;
		mau = temp.mau;
		return *this;
	}
	~Hon_so() = default;
};

istream& operator>> (istream& is, Hon_so& rhs) {
	cout << "Nhap phan nguyen: ";
	is >> rhs.nguyen;
	cout << "Nhap tu: ";
	is >> rhs.tu;
	cout << "Nhap mau: ";
	is >> rhs.mau;
	return is;
}

ostream& operator<< (ostream& os, const Hon_so& rhs) {
	os << rhs.nguyen <<" "<< rhs.tu << "/" << rhs.mau;
	return os;
}