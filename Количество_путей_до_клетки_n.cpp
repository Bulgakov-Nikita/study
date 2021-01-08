#include <iostream>

void numbers_of_patchs(int n) {
	int *options = new int[n+1];
	options[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		options[i] = options[i-1] + (i%2 == 0 ? options[i/2]: 0);
	}
	
	std::cout << '\n' << options[n];
}

int main() {
	int n;
	std::cout << "Ånter the number of cells: ";
	std::cin >> n;
	
	numbers_of_patchs(n);
	
	system("pause>nul");
	return 0;
}
