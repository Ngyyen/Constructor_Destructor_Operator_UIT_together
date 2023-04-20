#include <iostream>
using namespace std;

class A {
public:
	virtual void Sketchy() {
		cout << 1 << ": A's Sketchy()" << endl;
		Sketchy(-1);
	}
	void Sketchy(int num) {
		cout << 2 << ": A's Sketchy(" << num << ")" << endl;
	}
};

class B : public A {
public:
	void Sketchy() { // A::Sketchy được override
		cout << 3 << ": B's Sketchy()" << endl;
		Sketchy(-2);
	}
	void Sketchy(int num) { 
		cout << 4 << ": B's Sketchy(" << num << ")" << endl;
	}
	// lớp B vẫn được kế thừa A::Sketchy(int) từ lớp A
	// tuy nhiên nó bị hàm B::Sketchy(int) ẩn đi
};

class C : public B {
public:
	// lớp C được kế thừa B::Sketchy() từ lớp B
	void Sketchy(int num) {
		cout << 5 << ": C's Sketchy(" << num << ")" << endl;
	}
	// lớp C vẫn được kế thừa B::Sketchy(int) từ lớp B
	// tuy nhiên nó bị hàm C::Sketchy(int) ẩn đi
};

void Curious(A* wacky) {
	wacky->Sketchy();
	((C*)wacky)->Sketchy(123);
}

int main()
{
	A* inky = new B;

	inky->Sketchy();// inky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy()
					 // tiếp tục kiểm tra A::Sketchy() có phải virtual ko
					 // là virtual->dựa vào dynamic type của inky để gọi hàm
					 // inky trỏ vào một đối tượng thuộc lớp B
					 // -> dynamic type của inky là B
					 // -> hàm B::Sketchy() được gọi
					 // trong hàm B::Sketchy gọi hàm B::Sketchy(-2)

	inky->Sketchy(23);// inky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy(int)
					 // tiếp tục kiểm tra A::Sketchy(int) có phải virtual ko
					 // ko phải virtual->dựa vào static type của inky để gọi hàm
					 // -> hàm A::Sketchy(int) được gọi
	cout << endl;
	Curious(inky);// A* wacky = inky
				   // wacky là con trỏ kiểu lớp A
				   // wacky giữ địa chỉ của một đối tượng thuộc lớp B
				   // wacky->Sketchy(): gọi B::Sketchy()->gọi B::Sketchy(-2)
				   
				   // wacky bị ép kiểu thành con trỏ kiểu lớp C
				   // wacky có static type là C
				   // bắt đầu tìm tên hàm Sketchy trong lớp C
				   // tìm thấy tên hàm trong lớp C, dừng, ko kiếm nữa
				   // tìm các hàm tên Sketchy trong lớp C,
				   // xem hàm nào phù hợp nhất để gọi -> C::Sketchy(int)
				   // tiếp tục kiểm tra C::Sketchy(int) có phải virtual ko
				   // ko phải virtual->dựa vào static type của wacky để gọi hàm
				   // -> hàm C::Sketchy(int) được gọi
	cout << endl;
	
	B* pinky = new C;

	pinky->Sketchy();// pinky có static type là B
					 // bắt đầu tìm tên hàm Sketchy trong lớp B
					 // tìm thấy tên hàm trong lớp B, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp B,
					 // xem hàm nào phù hợp nhất để gọi -> B::Sketchy()
					 // tiếp tục kiểm tra B::Sketchy() có phải virtual ko
					 //là virtual->dựa vào dynamic type của pinky là C để gọi hàm
					 // tuy nhiên C ko override B::Sketchy()
					 // -> hàm B::Sketchy() được gọi
					 // trong hàm B::Sketchy gọi hàm B::Sketchy(-2)

	pinky->Sketchy(46);// pinky có static type là B
					 // bắt đầu tìm tên hàm Sketchy trong lớp B
					 // tìm thấy tên hàm trong lớp B, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp B,
					 // xem hàm nào phù hợp nhất để gọi -> B::Sketchy(int)
					 // tiếp tục kiểm tra B::Sketchy(int) có phải virtual ko
					 // ko phải virtual->dựa vào static type của pinky để gọi hàm
					 // -> hàm B::Sketchy(int) được gọi
	cout << endl;
	Curious(pinky);// A* wacky = inky
				   // wacky là con trỏ kiểu lớp A
				   // wacky giữ địa chỉ của một đối tượng thuộc lớp C
	
				   // wacky->Sketchy()
				   // wacky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy()
					 // tiếp tục kiểm tra A::Sketchy() có phải virtual ko
					 // là virtual->dựa vào dynamic type của wacky để gọi hàm
					 // wacky trỏ vào một đối tượng thuộc lớp C
					 // -> dynamic type của wacky là C
					 // lớp C ko override mà thừa hưởng B::Sketchy()
					 // ->B::Sketchy() được gọi->B::Sketchy(-2) đc gọi
					
				   // wacky bị ép kiểu thành C
				   // wacky->Sketchy(123)
				   // C::Sketchy(int) đc gọi
	return 0;
}
