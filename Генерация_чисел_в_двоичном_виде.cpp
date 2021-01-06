#include <iostream>

void generate_binary_all_numbers(int n) {
	// Генерируются всевозможные комбинации чисел из цифр 0 и 1 с количеством разрядов равным n
	static int numbersOfDigit = n;
	static int array[24];
	static int topIndex = 0;
	
	if (n == 0) {
		for (int i=0; i<numbersOfDigit; i++) {
			std::cout << array[i];
		}
		std::cout << '\n';
		
		topIndex--; 
	} else {
		array[topIndex++] = 0;
		generate_binary_all_numbers(n-1);
		
		array[topIndex++] = 1;
		generate_binary_all_numbers(n-1);
		
		topIndex--; 
	}
}

int main () {
	int n = 0;
	std::cin >> n;
	std::cout << '\n';
	
	generate_binary_all_numbers(n);
	
	system("pause>nul");
	return 0;
}

