#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Ngay {
	friend ostream& operator<< (ostream& os, const Ngay& rhs);
	friend istream& operator>> (istream& is, Ngay& rhs);
public:
	Ngay() = default;
	Ngay(int ngay, int thang, int nam) {
		this->ngay = ngay;
		this->thang = thang;
		this->nam = nam;
	}
	Ngay(const Ngay& temp) {
		ngay = temp.ngay;
		thang = temp.thang;
		nam = temp.nam;
	}
	Ngay& operator= (const Ngay& temp) {
		ngay = temp.ngay;
		thang = temp.thang;
		nam = temp.nam;
		return *this;
	}
	Ngay next_day() const;
	Ngay prev_day() const;
	ostream& print(ostream&);
	~Ngay() = default;

private:
	static vector<int> vec;
	static bool kt_nhuan(int);
	int ngay = 0;
	int thang = 0;
	int nam = 0;
};

vector<int> Ngay::vec = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

ostream& operator<< (ostream& os, const Ngay& rhs) {
	os << rhs.ngay << "/" << rhs.thang << "/" << rhs.nam;
	return os;
}
istream& operator>> (istream& is, Ngay& rhs) {
	cout << "Nhap ngay: ";
	is >> rhs.ngay;
	cout << "Nhap thang: ";
	is >> rhs.thang;
	cout << "Nhap nam: ";
	is >> rhs.nam;
	return is;
}

Ngay Ngay::next_day() const {
	Ngay ret = *this;
	ret.ngay++;
	if (kt_nhuan(ret.nam)) {
		vec[2] = 29;
	}
	if (ret.ngay > vec[ret.thang]) {
		++ret.thang;
		ret.ngay = 1;
	}
	if (ret.thang > 12) {
		ret.thang = 1;
		++ret.nam;
	}
	vec[2] = 28;
	return ret;
}

Ngay Ngay::prev_day() const {
	Ngay ret = *this;
	ret.ngay--;
	if (kt_nhuan(ret.nam)) {
		vec[2] = 29;
	}
	if (ret.ngay < 1) {
		--ret.thang;
		ret.ngay = vec[ret.thang];
	}
	if (ret.thang < 1) {
		ret.ngay = 31;
		ret.thang = 12;
		--ret.nam;
	}
	vec[2] = 28;
	return ret;
}

ostream& Ngay::print(ostream& os) {
	os << ngay << "/" << thang << "/" << nam << endl;
	return os;
}

bool Ngay::kt_nhuan(int nam) {
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) {
		return true;
	}
	return false;
}