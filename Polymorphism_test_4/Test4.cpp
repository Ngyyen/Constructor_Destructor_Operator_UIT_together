#include <iostream>
using namespace std;

class A {
public:
	virtual void Sketchy() {
		cout << 1 << ": A's Sketchy()" << endl;
		Sketchy(-1);
	}
	virtual void Sketchy(int num) {
		cout << 2 << ": A's Sketchy(" << num << ")" << endl;
	}
};

class B : public A {
public:
	void Sketchy() { // override A::Sketchy() 
		cout << 3 << ": B's Sketchy()" << endl;
		Sketchy(-2);
	}
	void Sketchy(int num) { // override A::Sketchy(int)
		cout << 4 << ": B's Sketchy(" << num << ")" << endl;
	}
};

class C : public B {
public:
	// lớp C được thừa hưởng B::Sketchy() từ lớp B
	void Sketchy(int num) { // override B::Sketchy(int)
		cout << 5 << ": C's Sketchy(" << num << ")" << endl;
	}
};

void Curious(A* wacky) {
	wacky->Sketchy();
	((C*)wacky)->Sketchy(123);
}

int main()
{
	A* inky = new B;
	inky->Sketchy(); // gọi B::Sketchy()->gọi B::Sketchy(int)
	inky->Sketchy(23); // gọi B::Sketchy(int)
	Curious(inky); // gọi B::Sketchy()
				   // ép kiểu wacky thành C* ???
				   // gọi B::Sketchy(int)
	cout << endl;
	
	B* pinky = new C;
	pinky->Sketchy(); // lớp C ko override Sketchy() nên gọi B::Sketchy()
	                  // trong B::Sketchy() gọi this->Sketchy(-2)
					  // ... ->gọi C::Sketchy(int)
	pinky->Sketchy(46); // gọi C::Sketchy(int)
	Curious(pinky); // lớp C ko override Sketchy() nên gọi B::Sketchy()
					// trong B::Sketchy() gọi this->Sketchy(-2)
					// ... ->gọi C::Sketchy(int)
					// ép kiểu wacky thành C*
					// OK, vì wacky đang giữ địa chỉ của một đối tượng kiểu C
					// ... gọi C::Sketchy(int)
	

	return 0;
}
