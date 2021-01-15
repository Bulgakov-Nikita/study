#include <iostream>

const int ARRAY_SIZE = 10;

class MyClass {
	private:
		int array[ARRAY_SIZE];		
		
	public:
		int &operator[](int n) { // indexing object
			return array[n];
		}
		
		int operator()(int* array_pointer) {
			for (int i = 0; i < ARRAY_SIZE; i++) {
				(*this)[i] = array_pointer[i];
			}
		}
		
		void print_array() {
			for (int i = 0; i < ARRAY_SIZE; i++) {
				std::cout << (*this)[i] << " ";
			}
			std::cout << '\n';
		}
};

int main() {
	MyClass obj;
	int array[ARRAY_SIZE] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		obj[i] = i;
	}
	
	obj.print_array();
	obj(array);
	obj.print_array();
	
	system("pause>nul");
	return 0;
}
