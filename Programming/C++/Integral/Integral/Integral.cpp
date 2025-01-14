#include "pch.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;

double function(double x)
{
	return x * x;
}

int main()
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	double l;
	double r;
	cout << "Input min x ";
	cin >> l;
	cout << "Input max x ";
	cin >> r;
	if (l > r)
	{
		cout << "Error. Min x is larger than max x";
		return 0;
	}
	int A;
	cout << "Input precision P, precision = 10^(-p) ";
	cin >> A;
	double p = 1;
	for (int i = 0; i < A; i++)
	{
		p /= 10;
	}
	double prev = -1000000;
	double step = r - l;
	double ans = -1000000;
	double delta = 1000000;
	do
	{
		prev = ans;
		ans = 0;
		for (double i = l; i <= r; i+=step)
		{
			if ((i == l) || (i == r))
			{
				ans += function(i);
			}
			else
			{
				ans += 2 * function(i);
			}
		}
		ans *= step;
		ans /= 2;
		step /= 2;
		if (delta > (fabs(ans - prev)))
		{
			delta = fabs(ans - prev);
		}
	} 
	while (delta > p);
	cout << fixed;
	cout << setprecision(A);
	cout << ans;
	return 0;
}