#include <iostream>
#include <cmath>

class Discriminant {
	private:
	void discr() {
		D = b*b - 4*a*c;
	}
	
	public:
		double D;
		double a;
		double b;
		double c;	
	
	setOdds(double A, double B, double C) {
		a = A;
		b = B;
		c = C;
	}
	
	showAll() {
		std::cout << "a, b, c: " << a << " " << b << " " << c
		          << "\nD: " << D << "\n";
	}
	
	Discriminant() {
		a = 0;
		b = 0;
		c = 0;
		discr();
	}
	
	Discriminant(double A, double B, double C) {
		a = A;
		b = B;
		c = C;
		discr();
	}
};

class QuadraticEquation: public Discriminant {
	public:
		void roots() {
			if (D > 0) {
				std::cout << "x_1: " << (-b - std::sqrt(D))/2*a
				          << "\nx_2: " << (-b + std::sqrt(D))/2*a;
			} else if (D == 0) {
				std::cout << "x: " << -b/2*a;
			} else {
					std::cout << "\nno real roots\n";
			}
		}
		
	QuadraticEquation(): Discriminant() {
	}	
	
	QuadraticEquation(double A, double B, double C): Discriminant(A, B, C) {
	}
};

int main() {
	QuadraticEquation objA(1, 12, 25);
	
	objA.showAll();
	objA.roots();
	
	system("pause>nul");
	return 0;
}
