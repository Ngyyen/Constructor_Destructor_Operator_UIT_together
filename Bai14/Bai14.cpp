#include <iostream>
#include "Ma_tran_dong.h"
using namespace std;

int main()
{
	Ma_tran_dong mat1 = {{1,2},{3,4}};
	cout << mat1 << endl;
	{
		Ma_tran_dong mat2 = mat1;
		cout << mat2 << endl;
	}
	cout << mat1 << endl;
	Ma_tran_dong mat3(2, 1);
	cout << mat3 << endl;
	mat3 = mat1;
	cout << mat3;
	return 0;
}