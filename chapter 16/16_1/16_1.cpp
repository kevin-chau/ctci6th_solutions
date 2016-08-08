// Number Swapper: Write a function to swap a number in place (no temporary variables)

// Using addition and subtraction
#include <iostream>
using namespace std;

void swap (int * a, int * b){
	if (*a > *b){
		*a = *b - *a;
		*b = *b + *a;
		*a = *b - *a;
	} else {
		*b = *a - *b;
		*a = *b + *b;
		*b = *b - *a;
	}
}

void swapXOR (int * a, int * b){
	*a = *a^*b;
	*b = *a^*b;
	*a = *a^*b;
}

int main () {
	int a = 9;
	int b = 5;
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	swap(a,b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	swap(a,b);
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	return 0;
}