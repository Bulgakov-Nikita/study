#include <iostream>

class MyClass {
	public:
		int number;
		MyClass* next;
		
	setN(int n) {
		number = n;
	}	
	
	showAll() {
		std::cout << number << " ";
		
		if (next) {
			next->showAll();
		} else {
			std::cout << '\n';
		}
	}
		
	~MyClass() {
		std::cout << "Delete: " << number << '\n';
	}
};

void deleteAll(MyClass* p) {
	if (p->next) {
		deleteAll(p->next);
	}
	
	delete p;
}

int main() {
	int n = 8;
	MyClass* objA = new MyClass;
	objA->number = 0;
	
	MyClass* p = objA;
	
	for (int i = 1; i < n; i++) { // создание цепочки
		p->next = new MyClass;
		p->next->number = i;
		p = p->next;
	}
	
	p->next = 0;
	objA->showAll();
	
	deleteAll(objA);
	system("pause>nul");
	return 0;
}
