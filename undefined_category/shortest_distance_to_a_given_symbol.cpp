#include <iostream>
#include <string>

inline int int_abs(int n) {
	if (n < 0) {
		return -n;
	} else {
		return n;
	}
}

void data_input(std::string& S, char& C) {
	std::cout << "Enter the string: ";
	std::getline(std::cin, S);
	std::cout << "Enter the symbol: ";
	std::cin >> C;
}

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void shortest_distance(std::string S, char C, int* arr, int s_length) {
	for (int i = 0; i < s_length; i++) {
		arr[i] = s_length;
	}
	
	int char_in_str = -1;
	for (int i = 0; i < s_length; i++) {
		if (S[i] == C and char_in_str == -1) {
			char_in_str = i;
			i = 0;
		}
		
		if (S[i] == C and char_in_str != -1) {
			std::swap(char_in_str, i);
		}
		
		if (arr[i] > int_abs(char_in_str-i) and char_in_str != -1) {
			arr[i] = int_abs(char_in_str-i);
		}
	}
}

int main() {
	std::string S;
	char C;
	data_input(S, C);
	int s_length = S.length();
	
	int arr[s_length];
	for (int i = 0; i < s_length; i++) {
		arr[i] = s_length;
	}
	
	shortest_distance(S, C, arr, s_length);
	
	std::cout << "\nShortest distance to a given symbol: \n";
	print_array(arr, s_length);
	
	system("pause>nul");
	return 0;
}
