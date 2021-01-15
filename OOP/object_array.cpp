#include <iostream>

class MyClass {
	public:
		int number;
		bool check; 
		
	showAll() {
		std::cout << number << " ";
		if (check) {
			(this+1)-> showAll();
		}
	}
	
	MyClass() {
		check = true;
	}
};

int main() {
	int n = 5;	
	MyClass obj[n];
	
	for (int i = 0; i < n; i++) {
		obj[i].number = i;
	}
	obj[n-1].check = false;
	
	obj[0].showAll();
	
	system("pause>nul");
	return 0;
}
