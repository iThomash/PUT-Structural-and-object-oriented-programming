#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

void fill_progressive(vector<int>& vec) {
	for (int i = 0;i < vec.size();i++) {
		vec[i] = i + 1;
	}
}

void print_vector(vector<int> vec) {
	for (int i = 0;i < vec.size();i++) {
		cout << vec[i] << " ";
	}
}

void min_max(vector<double> values, double &min, double &max) {
	for (int i = 0; i < values.size(); i++) {
		
		if (values[i] < min) min = values[i];
		if (values[i] > max) max = values[i];

	}
}

uint64_t factorial(int number) {
	uint64_t s = 1;
	if (number == 0 || number == 1) return 1;
	for (int i = 1; i <= number; i++) {
		s *= i;
	}
	return s;
}

uint64_t factorial_r(int number) {
	if (number == 0) return 1;
	return factorial_r(number - 1) * number;

}

bool is_prime(int number) {
	for (int i = 2; i <= sqrt(number) ;i++) {
		if (number % i == 0) return false;
	}
	return true;
}

double pi_leibniz(double stop_at) {
	double ourPi = 1;
	int i = 1;
	while (abs((ourPi*4) - M_PI) > stop_at) {
		if (i % 2 == 1) 
		{
			ourPi = ourPi - (1.0 / double (i*2 + 1));
		}
		else 
		{
			ourPi = ourPi + (1.0 /  double (i*2 + 1));
		}
		i++;
	}
	return ourPi * 4;
}

void draw_square(int num, bool left_diagonal = false, bool right_diagonal = false) {

	for (int i = 0;i < num;i++) {
		for (int j = 0;j < num;j++) {
			if (i == 0 || j == 0 || i==num-1 || j==num-1) {
				cout << "#";
				continue;
			}
			if (left_diagonal == true && i == j) {
				cout << "#";
				continue;
			}
			if (right_diagonal == true && abs(num - i -1) == j) {
				cout << "#";
				continue;
			}
			cout << " ";

		}
		cout << "\n";
	}

}

int gcd(int a, int b) {
	while (a != b) {
		if (a > b) a -= b;
		else b -= a;
	}
	return a;
}

int main(void)
{
	//Exercise 1
	/*
	int a;
	cout << "Please give me size of vector: ";
	cin >> a;
	vector<int> vec(a);
	fill_progressive(vec);
	print_vector(vec);
	*/

	//Exercise 2
	/*
	double min = DBL_MAX;
	double max = DBL_MIN;
	std::vector<double> values = { -1.0, 100, 3.14, -999.9, 21.37 };
	min_max(values, min, max);
	cout << "Min: " << min << "\nMax: " << max;
	*/

	//Exercise 3
	/*
	uint64_t result = factorial(15);
	std::cout << result << std::endl;
	*/

	//Exercise 4
	/*
	uint64_t result = factorial_r(15);
	std::cout << result << std::endl;
	*/

	//Exercise 5
	/*
	int prime_or_not_prime = 13;
	if (is_prime(prime_or_not_prime)) {
		cout << prime_or_not_prime << " is prime!" << std::endl;
	}
	else {
		cout << prime_or_not_prime << " is not prime!" << std::endl;
	}
	*/

	/*
	int bottom, top;
	cout << "Give me a lower limit: ";
	cin >> bottom;
	cout << "\nGive me a higher limit: ";
	cin >> top;
	vector<int> vec;
	for (int i = bottom;i <= top;i++) {
		bool is = is_prime(i);
		if (is == true) vec.push_back(i);
	}
	print_vector(vec);
	*/

	//Exercise 6
	/*
	double stop_at = 0.001;
	double pi_approx = pi_leibniz(stop_at);

	cout << pi_approx << endl;
	cout << "error: " << pi_approx - M_PI << endl;
	*/

	//Exercise 7
	/*
	draw_square(4);
	draw_square(6, true, false);
	draw_square(6, false, true);
	draw_square(7, true, true);
	*/

	//Exercise 8
	/*
	int nwd = gcd(24, 36);
	cout << nwd;
	*/

	return 0;
}