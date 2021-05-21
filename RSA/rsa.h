#pragma once
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

class RSA
{
public:
	RSA();
	
	int simbolo_n(int a, int b) {
		int n = (a - 1) * (b - 1);
		return n;
	};
	int calcular_N(int a, int b) {
		int N = a * b;
		return N;
	};
	int fe_modulo(int a, int n) {

		int q = a / n;
		int r = a % n;

		if (r < 0)
		{
			q = q - 1;
			r = a - (q * n);
		}
		return r;
	};
	int generar_primos() {
		int val = 1;
		int* number = new int;
		srand(time(NULL));
		while (val == 1) {

			*number = rand() % 10;

			cout << *number << endl;
			for (int i = 2; i < *number; i++) {
				if (*number % i == 0) {
					val = 1;
					break;
				}
				else if (i == (*number) / 2) {

					val = 2;
				}


			}

		}
		return *number;
		delete number;
	};
	int* mcd_ex(int a, int b) {
		int r1 = a;
		int s1 = 1;
		int t1 = 0;
		int r2 = b;
		int s2 = 0;
		int t2 = 1;
		int q, r, s, t;
		while (r2 > 0) {
			q = r1 / r2;
			r = r1 - (q * r2);
			r1 = r2;
			r2 = r;
			s = s1 - (q * s2);
			s1 = s2;
			s2 = s;
			t = t1 - (q * t2);
			t1 = t2;
			t2 = t;

		}
		int val[] = { r1, s1, t1 };

		return val;
	};
	int mcd(int a, int b) {
		int r1 = a;
		int r2 = b;
		int q = 0;
		int r = 0;

		while (r2 > 0) {
			q = r1 / r2;
			r = r1 - (q * r2);
			r1 = r2;
			r2 = r;
		}
		return r1;
	}
	bool inversa_comp(int a, int b) {
		bool comprobante = mcd(a, b);
		if (comprobante == 1)
			cout << "no hay inversa" << endl;
		else
			return a;
	};
	int inversa(int a, int b) {
		int res;
		res = mcd_ex(a, b)[1];
		if (res < 0) {
			res = fe_modulo(a, b);
		}
		return res;
	};
	int powermod(int x, int y,int z)
	{
		int res = 1;		
		while (y)
		{			
			if (y % 2 == 1)
				res = (res * x);
			y = y >> 1;
			x = (x * x);
		}

		res = fe_modulo(res, z);

		return res;
	}

private:

};

