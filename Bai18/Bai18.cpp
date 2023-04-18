#include <iostream>
#include "Mang_so_hang.h"
#include "So_hang.h"
#include "Da_thuc.h"
using namespace std;

int main()
{
	/*
	Da_thuc f;
	cin >> f;
	cout << f << endl;
	Da_thuc g;
	cin >> g;
	cout << g << endl;
	Da_thuc h = f + g;
	cout << h << endl;
	*/

	So_hang a1(2, 3), a2(1, 1), a3(4, 4);
	Da_thuc f = { a1,a2,a3 };
	cout << f << endl;
	{
		Da_thuc g(5);
		cout << g << endl;
		g = f;
		cout << g << endl;
	}
	cout << f << endl;
	
	return 0;
}