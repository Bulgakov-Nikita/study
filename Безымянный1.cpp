#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class MyFirstClass {
	private:
		// fields(����):
	    std::string name;
	    double money;
	    double rate;
	    int time;
	    // methods(������):
	    double calculate() {
	    	double s = money;
	    	for (int i = 0; i < time; i++) {
	    		s *= (1 + rate/100);  
			}
			return s;
		}
	public:	
		void showAll() {
			std::cout << std::setprecision(2) << std::fixed
			          << "���: " << name << '\n'
			          << "�����: " << money << '\n'
			          << "������ (%): " << rate << '\n'
			          << "������ (���): " << time << '\n'
			          << "�������� �����: " << calculate() << '\n';
		}
		void setAll(std::string n, double m, double r, int t) {
			name = n;
			money = m;
			rate = r;
			time = t;
		}
};

int main() {
	std::setlocale(LC_ALL, "ru");
	system("chcp 1251>nul");
	
	MyFirstClass test1, test2;
	
	// ������������ �������� �����
    test1.setAll("���� ��������", 250000, 5, 10);
    test2.setAll("���� ������", 1000000, 8, 10);
	
	// ����� ������ ��� �������� ���������� ������
	test1.showAll();
	std::cout << '\n';
	test2.showAll();
	 
	system("pause>nul");
	return 0;
}
