#include <iostream>
using namespace std;

class A {
public: 
	void Sketchy() {
		cout << 1 << ": A's Sketchy()" << endl;
		Sketchy(-1);
	}
	void Sketchy(int num) {
		cout << 2 << ": A's Sketchy(" << num << ")" << endl;
	}
};

class B : public A {
public:
	void Sketchy() {
		cout << 3 << ": B's Sketchy()" << endl;
		Sketchy(-2);
	}
	void Sketchy(int num) {
		cout << 4 << ": B's Sketchy(" << num << ")" << endl;
	}
	// lớp B vẫn được kết thừa A::Sketchy() và A::Sketchy(int)
	// tuy nhiên chúng bị 2 hàm trên ẩn đi
};

class C : public B {
public: 
	// lớp C được kế thừa B::Sketchy() từ lớp B
	void Sketchy(int num) {
		cout << 5 << ": C's Sketchy(" << num << ")" << endl;
	}
	// lớp C vẫn được kế thừa B::Sketchy(int)
	// tuy nhiên bị C::Sketchy(int) ẩn đi
};

void Curious(A* wacky) {
	wacky->Sketchy();
	((C*)wacky)->Sketchy(123);
}

int main()
{
	A* inky = new B; // inky là con trỏ kiểu lớp A
				     // inky giữ địa chỉ của một đối tượng thuộc lớp B 
					 // lớp B là con của lớp A

	inky->Sketchy(); // inky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy()
					 // tiếp tục kiểm tra A::Sketchy() có phải virtual ko
					 // ko phải virtual->dựa vào static type của inky để gọi hàm
					 // -> hàm A::Sketchy() được gọi
					 // trong hàm A::Sketchy gọi hàm A::Sketchy(-1)

	inky->Sketchy(23);// inky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy(int)
					 // tiếp tục kiểm tra A::Sketchy(int) có phải virtual ko
					 // ko phải virtual->dựa vào static type của inky để gọi hàm
					 // -> hàm A::Sketchy(int) được gọi

	Curious(inky); // A* wacky = inky
				   // wacky là con trỏ kiểu lớp A
				   // wacky giữ địa chỉ của một đối tượng thuộc lớp B
				   // wacky->Sketchy() -> giống TH inky->Sketchy ở trên
				   
				   // (C*)wacky: wacky bị ép kiểu thành con trỏ kiểu lớp C,
				   // wacky->Sketchy(123)
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
	pinky->Sketchy(); // pinky có static type là B
					 // bắt đầu tìm tên hàm Sketchy trong lớp B
					 // tìm thấy tên hàm trong lớp B, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp B,
					 // xem hàm nào phù hợp nhất để gọi -> B::Sketchy()
					 // tiếp tục kiểm tra B::Sketchy() có phải virtual ko
					 // ko phải virtual->dựa vào static type của pinky để gọi hàm
					 // -> hàm B::Sketchy() được gọi
					 // trong hàm B::Sketchy gọi hàm B::Sketchy(-2)

	pinky->Sketchy(46); // B::Sketchy(int) đc gọi

	Curious(pinky); // A* wacky = pinky
				   // wacky là con trỏ kiểu lớp A
				   // wacky giữ địa chỉ của một đối tượng thuộc lớp C
				   
				   // wacky->Sketchy() 
				   // wacky có static type là A
				   // bắt đầu tìm tên hàm Sketchy trong lớp A
				   // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
				   // tìm các hàm tên Sketchy trong lớp A,
				   // xem hàm nào phù hợp nhất để gọi -> A::Sketchy()
				   // tiếp tục kiểm tra A::Sketchy() có phải virtual ko
				   // ko phải virtual->dựa vào static type của inky để gọi hàm
				   // -> hàm A::Sketchy() được gọi
				   // trong hàm A::Sketchy gọi hàm A::Sketchy(-1)
				   
				   // (C*)wacky: wacky bị ép kiểu thành con trỏ kiểu lớp C,
				   // wacky->Sketchy(123)
				   // ... 
	
	return 0;
}
