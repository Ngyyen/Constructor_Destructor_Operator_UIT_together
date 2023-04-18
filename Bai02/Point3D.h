#include <iostream>
#include <cmath>
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
	os <<"( "<< rhs.x<<" , " << rhs.y << " , " << rhs.z <<" )";
	return os;
}

Point3D& Point3D::operator= (const Point3D& temp) {
	x = temp.x;
	y = temp.y;
	z = temp.z;
	return *this;
}



