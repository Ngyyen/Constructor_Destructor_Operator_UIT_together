#include <iostream>
#include <cmath>
using namespace std;

class Point {
	friend class Triangle;
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
	float Distance_to_Origin();
	float Distance_to(const Point& p2);
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


float Point::Distance_to_Origin() {
	return sqrt(x * x + y * y);
}

float Point::Distance_to(const Point& p2) {
	return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
}


class Triangle {
	friend istream& operator>>(istream& is, Triangle& rhs);
	friend ostream& operator<<(ostream& os, const Triangle& rhs);
public:
	Triangle() = default;
	Triangle(const Point& first, const Point& second, const Point& third) {
		a = first;
		b = second;
		c = third;
		d_ab = a.Distance_to(b);
		d_bc = b.Distance_to(c);
		d_ca = c.Distance_to(a);
	}
	Triangle(float ax, float ay, float bx, float by, float cx, float cy) {
		a = Point(ax, ay);
		b = Point(bx, by);
		c = Point(cx, cy);
		d_ab = a.Distance_to(b);
		d_bc = b.Distance_to(c);
		d_ca = c.Distance_to(a);
	}
	Triangle(const Triangle& temp) {
		a = temp.a;
		b = temp.b;
		c = temp.c;
		d_ab = a.Distance_to(b);
		d_bc = b.Distance_to(c);
		d_ca = c.Distance_to(a);
	}
	Triangle& operator= (const Triangle& temp) {
		a = temp.a;
		b = temp.b;
		c = temp.c;
		d_ab = a.Distance_to(b);
		d_bc = b.Distance_to(c);
		d_ca = c.Distance_to(a);
		return *this;
	}
	float get_perimeter();
	float get_area();
	Point get_trong_tam();
	int get_type();
	void Nhap() {
		
	}
	~Triangle() = default;

private:
	Point a;
	Point b;
	Point c;
	float d_ab = 0;
	float d_bc = 0;
	float d_ca = 0;
};

istream& operator>>(istream& is, Triangle& rhs) {
	cout << "Nhap diem A: " << endl;
	is >> rhs.a;
	cout << "Nhap diem B: " << endl;
	is >> rhs.b;
	cout << "Nhap diem C: " << endl;
	is >> rhs.c;
	return is;
}
ostream& operator<<(ostream& os, const Triangle& rhs) {
	cout << "Toa do diem A: " << endl;
	os << rhs.a;
	cout << "Toa do diem B: " << endl;
	os << rhs.b;
	cout << "Toa do diem C: " << endl;
	os << rhs.c;
	return os;
}

float Triangle::get_perimeter() {
	return d_ab + d_bc + d_ca;
}

float Triangle::get_area() {
	float p = get_perimeter() / 2;
	return pow(p * (p - d_ab) * (p - d_bc) * (p - d_ca), 0.5);
}

Point Triangle::get_trong_tam() {
	Point g((a.x + b.x + c.x) / 3, (a.y + b.y + c.y) / 3);
	return g;
}

int Triangle::get_type() {
	if (d_ab == d_bc && d_bc == d_ca && d_ca == d_ab)
		return 2;
	if (d_ab == d_bc || d_bc == d_ca || d_ca == d_ab)
		return 1;
	int kc1_sqr = d_ab * d_ab;
	int kc2_sqr = d_bc * d_bc;
	int kc3_sqr = d_ca * d_ca;
	if ((kc1_sqr == (kc2_sqr + kc3_sqr)) || (kc2_sqr == (kc1_sqr + kc3_sqr)) || (kc3_sqr == (kc1_sqr + kc2_sqr)))
		return 3;
	return 0;
}

