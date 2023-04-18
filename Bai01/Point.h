#include <iostream>
#include <cmath>
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
	float Distance_to_Origin();
	float Distance_to(const Point&);
	void print();
	void read();
	Point& operator= (const Point& temp);
	~Point() = default;
private:
	float x = 0.0;
	float y = 0.0;
};

istream& operator>>(istream& is, Point& rhs) {
	cout << "Nhap toa do diem: " << endl;
	cout << "x = ";
	is >> rhs.x;
	cout << "y = ";
	is >> rhs.y;
	return is;
}

ostream& operator<<(ostream& os, const Point& rhs) {
	os << "x = " << rhs.x << " y = " << rhs.y << endl;
	return os;
}

Point& Point::operator= (const Point& temp) {
	x = temp.x;
	y = temp.y;
	return *this;
}

float Point::Distance_to_Origin() {
	return sqrt(x * x + y * y);
}

float Point::Distance_to(const Point& p2) {
	return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
}

void Point::print() {
	cout << "x = " << x << " y = " << y << endl;
}

void Point::read() {
	cout << "Nhap toa do diem: " << endl;
	cout << "x = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
}

