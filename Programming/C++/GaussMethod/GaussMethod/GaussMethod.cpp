#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Fraction.h"
using namespace std;

ifstream in("input.txt");
ofstream out ("output.txt");

int main()
{
	int N, M;
	cout << "Input number of equations\n";
	in >> N;
	cout << "Input number of roots\n";
	in >> M;
	vector <Fraction> ans(M);
	vector <vector<Fraction> > slau(N, vector<Fraction>(M + 1));
	Fraction zero(0, 1);
	cout << "Input system of equations as matrix\n";
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= M; j++)
		{
			in >> slau[i][j];
		}
	}
	
	if (M > N)
	{
		cout << "Can't be solved\n";
		return 0;
	}	
	for (int i = 0; i < M; i++)
	{
		/*for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= M; j++)
			{
				cout << slau[i][j] << " ";
			}
			cout << '\n';
		}
		cout << '\n';*/
		bool flag = false;
		for (int j = i; j < N; j++)
		{
			if (slau[j][i] != zero)
			{
				flag = true;
				swap(slau[j], slau[i]);
				break;
			}
		}
		if (flag)
		{
			for (int j = i + 1; j < N; j++)
			{
				Fraction delta;
				delta = slau[j][i] / slau[i][i];
				reduction(delta);
				for (int k = i; k <= M; k++)
				{
					slau[j][k] -= (delta*slau[i][k]);
					reduction(slau[j][k]);
				}
			}
		}
	}
	for (int i = M; i < N; i++)
	{
		if (slau[i][M] != zero)
		{
			cout << "Can't be solved\n";
			return 0;
		}
	}
	for (int i = M - 1; i >= 0; i--)
	{
		for (int j = M - 1; j > i; j--)
		{
			slau[i][M] -= (slau[i][j] * ans[j]);
			reduction(slau[i][M]);
		}
		ans[i] = slau[i][M] / slau[i][i];
	}
	for (int i = 0; i < M; i++)
	{
		reduction(ans[i]);
		cout << ans[i] << " ";
	}
	cout << '\n';
	return 0;
}