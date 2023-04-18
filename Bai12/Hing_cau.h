#include <iostream>
using namespace std;

class Point3D {
	friend istream& operator>>(istream&, Point3D&);
	friend ostream& operator<<(ostream&, const Point3D&);
public:
	Point3D() = default;
	Point3D(float a, float b, float c) : x(a), y(b), z(c) {}
	Point3D(const Point3D& temp) {
		x = temp.x;
		y = temp.y;
		z = temp.z;
	}
	Point3D& operator= (const Point3D& temp);
	~Point3D() = default;

private:
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
};

istream& operator>>(istream& is, Point3D& rhs) {
	cout << "Nhap toa do diem:" << endl;
	is >> rhs.x >> rhs.y >> rhs.z;
	return is;
}

ostream& operator<<(ostream& os, const Point3D& rhs) {
	os << "( " << rhs.x << " , " << rhs.y << " , " << rhs.z << " )";
	return os;
}

Point3D& Point3D::operator= (const Point3D& temp) {
	x = temp.x;
	y = temp.y;
	z = temp.z;
	return *this;
}


class Sphere {
	friend istream& operator>>(istream& is, Sphere& rhs);
	friend ostream& operator<<(ostream& os, const Sphere& rhs);
public:
	Sphere() = default;
	Sphere(const Point3D& i, double r) : I(i), R(r) {}
	Sphere(const Sphere& temp) {
		I = temp.I;
		R = temp.R;
	}
	Sphere& operator= (const Sphere& temp) {
		I = temp.I;
		R = temp.R;
		return *this;
	}
	double get_chu_vi() const;
	double get_dien_tich() const;
	Point3D get_tam() const;
	~Sphere() = default;
private:
	Point3D I;
	double R = 0.0;
};

istream& operator>>(istream& is, Sphere& rhs) {
	cout << "Nhap toa do tam: " << endl;
	is >> rhs.I;
	cout << "Nhap do dai ban kinh: ";
	is >> rhs.R;
	return is;
}
ostream& operator<<(ostream& os, const Sphere& rhs) {
	os << "Toa do tam: " << endl;
	os << rhs.I << endl;
	os << "Ban kinh: " << rhs.R << endl;
	return os;
}
