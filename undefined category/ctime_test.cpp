#include <iostream>
#include <ctime>

const long long int LOOP_ITERARIONS = 1000000000;

int main() {	
	int sum = 0;
	for (int i = 0; i < LOOP_ITERARIONS; i++) {
	    sum += i;
	}
	    
	const clock_t t = clock();
	std::cout << float(t)/CLOCKS_PER_SEC << '\n';    
	    
	std::cout << '\n' << sum;   
	    
	system("pause>nul");
	return 0;
}
