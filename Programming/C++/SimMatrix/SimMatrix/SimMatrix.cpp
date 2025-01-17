#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in ("input.txt");
	ofstream out ("output.txt");
	int N;
	cout << "Enter N "; //size of vector
	cin >> N;
	int sz = 0;
	for (int i = 1; i <= N; i++)
	{
		sz += i;
	}
	int* m;
	m = new int[sz];
	int* v;
	v = new int[N];
	int* ans;
	ans = new int[N];
	cout << "Enter matrix as array" << '\n';
	for (int i = 0; i < sz; i++)
	{
		cin >> m[i];
	}
	cout << "Enter vector" << '\n';
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}
	for (int i = 0; i < N; i++)
	{
		ans[i] = 0;
		int k = N - 1;
		int jump = i;
		int j = i;
		int pos = 0;
		while (jump > 0)
		{
			ans[i] += m[j] * v[pos];
			pos++;
			j += k;
			k--;
			jump--;
		}
		while (pos < N)
		{
			ans[i] += m[j] * v[pos];
			j++;
			pos++;
		}
	}
	for (int i = 0; i < N; i++)
	{
		out << ans[i] << " ";
	}
	return 0;
}