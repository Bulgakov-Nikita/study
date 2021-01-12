#include <iostream>

class MyClass {
	public:
		int time;
	
	MyClass() {
	}
	
	MyClass(int t) {
		time = t;
	}
	
	MyClass operator+(MyClass objB) {
		MyClass tmp;
		tmp.time = time + objB.time;
		return tmp;
	}
	
	MyClass operator--(int) {
		return --time;
	}
	
};

int operator*(MyClass objA, MyClass objB) {
	return objA.time * objB.time;
}

int main() {
	MyClass objA(1), objB(2), objC;
	
	objC = objA + objB;
	std::cout << "objA, ObjB: " << objA.time << " " << objB.time << "\nobjC: " << objC.time << '\n';
	
	objC--;
	std::cout << "objC--: " << objC.time << '\n';
	
	std::cout << "objB*ObjC: " << objB * objC<< '\n';
	
	system("pause>nul");
	return 0;
}
