// MCD_EUCLIDES.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


using namespace std;

int fe_modulo(int a, int n) {
	int q = a / n;
	int r = a - (n * q);

	if (r < 0) {
		if (q <= 0)
			q = q - 1;
		else
			q = q + 1;

		r = a - (n * q);
	}

	return r;
}
int mcd(int a, int b) {
	int r1 = a;
	int r2 = b;
	int q = 0;
	int r = 0;
	//int r  = fe_modulo(a, n);
	while (r2 > 0) {
		q = r1 / r2;
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
	}
	return r1;
}
int main()
{
    //maximo comun divisor
	int er = mcd(250, 111);
	cout << er << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
