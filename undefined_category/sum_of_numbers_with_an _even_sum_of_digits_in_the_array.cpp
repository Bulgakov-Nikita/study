#include <iostream>

bool the_sum_of_the_digits_of_the_number_is_even(int number) {
	int sum_of_digits = 0;
	
	while (number != 0) {
		sum_of_digits++;
		number /= 10;
	}

	if (sum_of_digits%2 == 0 and sum_of_digits != 0) {
		return true;
	} else {
		return false;
	}
}

int the_number_of_numbers_with_an_even_sum_of_digits(int* array, int size) {
	int counter = 0;
	
	for (int i = 0; i < size; i++) {
		if (the_sum_of_the_digits_of_the_number_is_even(array[i])) {
			counter++;
		}
	}
	
	return counter;
}

int main() {
	int size;
	std::cout << "Enter array size: ";
	std::cin >> size;
	
	int array[size];
	std::cout << "Enter array elements: ";
	for (int i = 0; i < size; i++) {
		std::cin >> array[i];
	}

    std::cout << "Number of numbers with an even sum of digits: " 
	          << the_number_of_numbers_with_an_even_sum_of_digits(array, size)
			  << '\n';
	
	system("pause>nul");
	return 0;
}
