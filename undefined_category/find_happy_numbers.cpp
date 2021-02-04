#include <iostream>

int const ITERATION_LIMIT = 1024;

bool lucky_number(int number) {
	int tmp_number = number;
	int sum_square_digits = 0;
	int tmp_sum_square_digits = sum_square_digits;
	int no_lucky_number[ITERATION_LIMIT] = {0};
	int no_lucky_number_level = 0;
	
	while (sum_square_digits != 1) {
		sum_square_digits = 0;
		
		while (tmp_number != 0) {
			sum_square_digits +=  (tmp_number%10) * (tmp_number%10);
			tmp_number /= 10; 
		}
		
		if (no_lucky_number_level != ITERATION_LIMIT) {
			for (int i = 1; i < no_lucky_number_level; i++) {
				if (sum_square_digits == no_lucky_number[i]) {
					goto exit;
				}
			}
			no_lucky_number[no_lucky_number_level++] = sum_square_digits;
		} else {
			return false;
		}
		
		tmp_number = sum_square_digits;
	}
	
	if (sum_square_digits == 1) {
		return true;
	} else {
		exit:
		return false;
	}
}

int main() {
	int limit;
	std::cout << "Enter to what date to search for the lucky numbers: ";
	std::cin >> limit;
	
	int counter = 0;
	for (int i = 0; i < limit; i++) {
		if (lucky_number(i)) {
			// std::cout << i << " ";
			counter++;
		}
	}
	std::cout << '\n' << "lucky numbers: " << counter;
	
	system("pause>nul");
	return 0;
}
