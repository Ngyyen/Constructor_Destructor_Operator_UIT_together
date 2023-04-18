#include <iostream>
#include "Mang_dong.h"
using namespace std;

int main()
{
	Mang_dong vec1 = {1,2,3,4,5};
	cout << vec1 << endl;;
	{
		Mang_dong vec2;
		vec2 = vec1;
	}
	cout << vec1 << endl;
	return 0;
}