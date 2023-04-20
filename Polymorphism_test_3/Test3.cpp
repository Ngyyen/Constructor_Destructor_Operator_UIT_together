#include <iostream>
using namespace std;

class A {
public:
	void Sketchy() {
		cout << 1 << ": A's Sketchy()" << endl;
		Sketchy(-1);
	}
	virtual void Sketchy(int num) {
		cout << 2 << ": A's Sketchy(" << num << ")" << endl;
	}
};

class B : public A {
public:
	void Sketchy() {
		cout << 3 << ": B's Sketchy()" << endl;
		Sketchy(-2);
	}
	void Sketchy(int num) { // A::Sketchy(int) được override
		cout << 4 << ": B's Sketchy(" << num << ")" << endl;
	}
	// lớp B vẫn được kế thừa A::Sketchy() từ lớp A
	// tuy nhiên nó bị hàm B::Sketchy() ẩn đi
};

class C : public B {
public:
	// lớp C được thừa hưởng B::Sketchy() từ lớp B
	void Sketchy(int num) { // B::Sketchy(int) được override
		cout << 5 << ": C's Sketchy(" << num << ")" << endl;
	}
};

void Curious(A* wacky) {
	wacky->Sketchy();
	((C*)wacky)->Sketchy(123);
}

int main()
{
	A* inky = new B;// inky là con trỏ kiểu A, giữ địa chỉ của đối tượng kiểu B
	inky->Sketchy();// inky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy()
					 // tiếp tục kiểm tra A::Sketchy() có phải virtual ko
					 // ko phải virtual->dựa vào static type của inky để gọi hàm
					 // -> hàm A::Sketchy() được gọi
					 
					 // trong thân hàm A::Sketchy() gọi: this->Sketchy(-1);
					 // this là một con trỏ kiểu lớp A
					 // this giữ địa chỉ của đối tượng đang thực hiện lời gọi hàm
					 // tức là đối tượng mà inky trỏ vào
					 // tức là một đối tượng thuộc lớp B
					 // static type của this là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy(int)
					 // tiếp tục kiểm tra A::Sketchy(int) có phải virtual ko
					 // là virtual->dựa vào dynamic type của this để gọi hàm
					 // this giữ địa một đối tượng của lớp B
					 // -> dynamic type của this là B
					 // -> hàm B::Sketchy(-1) được gọi

	inky->Sketchy(23);// inky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy(int)
					 // tiếp tục kiểm tra A::Sketchy(int) có phải virtual ko
					 // là virtual->dựa vào dynamic type của inky để gọi hàm
					 // inky giữ địa chỉ một đối tượng thuộc lớp B
					 // dynamic type của inky là B
					 // -> hàm B::Sketchy(int) được gọi
	cout << endl;
	Curious(inky);// A* wacky = inky
				   // wacky là con trỏ kiểu lớp A
				   // wacky giữ địa chỉ của một đối tượng thuộc lớp B
				   // wacky->Sketchy(): giống inky->Sketchy() ...
				   
				   // wacky bị ép kiểu thành con trỏ kiểu lớp C ???
	// Cách giải thích 1:
				   // wacky đang giữ địa chỉ của B là cha của C
				   // ép kiểu wacky thành C thì sẽ bị lỗi
				   // vì ko thể gán biến cha cho biến con
				   // vì thế chương trình sẽ ko làm gì và giữ nguyên kiểu của wacky
	// Cách giải thích 2:
				   // wacky->Sketchy(123)
				   // wacky có static type là C
				   // bắt đầu tìm tên hàm Sketchy trong lớp C
				   // tìm thấy tên hàm trong lớp C, dừng, ko kiếm nữa
				   // tìm các hàm tên Sketchy trong lớp C,
				   // xem hàm nào phù hợp nhất để gọi -> C::Sketchy(int)
				   // tiếp tục kiểm tra C::Sketchy(int) có phải virtual ko
				   // là virtual->dựa vào dynamic type của wacky để gọi hàm
				   // -> hàm B::Sketchy(int) được gọi
	cout << endl;
	
	B* pinky = new C;// pinky là con trỏ kiểu B, giữ địa chỉ của đối tượng kiểu C
	pinky->Sketchy();// pinky có static type là B
					 // bắt đầu tìm tên hàm Sketchy trong lớp B
					 // tìm thấy tên hàm trong lớp B, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp B,
					 // xem hàm nào phù hợp nhất để gọi -> B::Sketchy()
					 // tiếp tục kiểm tra B::Sketchy() có phải virtual ko
					 // ko phải virtual->dựa vào static type của pinky để gọi hàm
					 // -> hàm B::Sketchy() được gọi

	                 // trong thân hàm B::Sketchy() gọi: this->Sketchy(-1);
					 // this là một con trỏ kiểu lớp B
					 // this giữ địa chỉ của đối tượng đang thực hiện lời gọi hàm
					 // tức là đối tượng mà pinky trỏ vào
					 // tức là một đối tượng thuộc lớp C
					 // static type của this là B
					 // bắt đầu tìm tên hàm Sketchy trong lớp B
					 // tìm thấy tên hàm trong lớp B, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp B,
					 // xem hàm nào phù hợp nhất để gọi -> B::Sketchy(int)
					 // tiếp tục kiểm tra B::Sketchy(int) có phải virtual ko
					 // là virtual->dựa vào dynamic type của this để gọi hàm
					 // this giữ địa một đối tượng của lớp C
					 // -> dynamic type của this là C
					 // -> hàm C::Sketchy(-1) được gọi

	pinky->Sketchy(46);// pinky có static type là B
					 // bắt đầu tìm tên hàm Sketchy trong lớp B
					 // tìm thấy tên hàm trong lớp B, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp B,
					 // xem hàm nào phù hợp nhất để gọi -> B::Sketchy(int)
					 // tiếp tục kiểm tra B::Sketchy(int) có phải virtual ko
					 // là virtual->dựa vào dynamic type của pinky để gọi hàm
					 // pinky giữ địa chỉ một đối tượng thuộc lớp C
					 // dynamic type của pinky là C
					 // -> hàm C::Sketchy(int) được gọi
	cout << endl;

	Curious(pinky);// A* wacky = pinky
				   // wacky là con trỏ kiểu lớp A
				   // wacky giữ địa chỉ của một đối tượng thuộc lớp C
				   // wacky->Sketchy()
				   // wacky có static type là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy()
					 // tiếp tục kiểm tra A::Sketchy() có phải virtual ko
					 // ko phải virtual->dựa vào static type của wacky để gọi hàm
					 // -> hàm A::Sketchy() được gọi
	
					 // trong thân hàm A::Sketchy() gọi: this->Sketchy(-1);
					 // this là một con trỏ kiểu lớp A
					 // this giữ địa chỉ của đối tượng đang thực hiện lời gọi hàm
					 // tức là đối tượng mà wacky trỏ vào
					 // tức là một đối tượng thuộc lớp C
					 // static type của this là A
					 // bắt đầu tìm tên hàm Sketchy trong lớp A
					 // tìm thấy tên hàm trong lớp A, dừng, ko kiếm nữa
					 // tìm các hàm tên Sketchy trong lớp A,
					 // xem hàm nào phù hợp nhất để gọi -> A::Sketchy(int)
					 // tiếp tục kiểm tra A::Sketchy(int) có phải virtual ko
					 // là virtual->dựa vào dynamic type của this để gọi hàm
					 // this giữ địa một đối tượng của lớp C
					 // -> dynamic type của this là C
					 // -> hàm C::Sketchy(-1) được gọi
				   
				   // wacky bị ép kiểu thành con trỏ kiểu lớp C
				   // C::Sketchy(123) đc gọi
	

	return 0;
}
