#include <iostream>
#include "Mang_so_hang.h"
#include "So_hang.h"
#include "Da_thuc.h"
using namespace std;

int main()
{
	So_hang a1(2, 3), a2(1, 1), a3(4, 4);
	//Da_thuc f = {a1,a2,a3};
	Da_thuc f;
	cin >> f;
	cout << f << endl;
	//cout << f.calculate(3) << endl;
	Da_thuc g;
	cin >> g;
	cout << g << endl;
	Da_thuc h = f + g;
	cout << h << endl;
	return 0;
}