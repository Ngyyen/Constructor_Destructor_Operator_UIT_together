#include <iostream>
using namespace std;

class Point {
	friend istream& operator>>(istream&, Point&);
	friend ostream& operator<<(ostream&, const Point&);
public:
	Point() = default;
	Point(float a, float b) : x(a), y(b) {}
	Point(const Point& temp) {
		x = temp.x;
		y = temp.y;
	}
	Point& operator= (const Point& temp);
	~Point() = default;
private:
	float x = 0.0;
	float y = 0.0;
};

istream& operator>>(istream& is, Point& rhs) {
	is >> rhs.x >> rhs.y;
	return is;
}

ostream& operator<<(ostream& os, const Point& rhs) {
	os << rhs.x << rhs.y;
	return os;
}

Point& Point::operator= (const Point& temp) {
	x = temp.x;
	y = temp.y;
	return *this;
}

class Circle {
	friend istream& operator>>(istream& is, Circle& rhs);
	friend ostream& operator<<(ostream& os, const Circle& rhs);
public:
	Circle() = default;
	Circle(const Point& i, double r) : I(i), R(r) {}
	Circle(const Circle& temp) {
		I = temp.I;
		R = temp.R;
	}
	Circle& operator= (const Circle& temp) {
		I = temp.I;
		R = temp.R;
		return *this;
	}
	double get_chu_vi() const;
	double get_dien_tich() const;
	Point get_tam() const;
	~Circle() = default;
private:
	Point I;
	double R = 0.0;
};

istream& operator>>(istream& is, Circle& rhs) {
	cout << "Nhap toa do tam: " << endl;
	is >> rhs.I;
	cout << "Nhap do dai ban kinh: ";
	is >> rhs.R;
	return is;
}
ostream& operator<<(ostream& os, const Circle& rhs) {
	os << "Toa do tam: " << endl;
	os << rhs.I << endl;
	os << "Ban kinh: " << rhs.R << endl;
	return os;
}

double Circle::get_chu_vi() const {
	return 2 * R * 3.14;
}
double Circle::get_dien_tich() const {
	return R * R * 3.14;
}
Point Circle::get_tam() const {
	return I;
}