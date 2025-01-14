#include "pch.h"
#include <iostream>
using namespace std;

int N;

struct stack
{
	pair <char, int> *s;
	int size_Stack;
};

void Init(stack &st, int sizest)
{
	st.size_Stack = 0;
	st.s = new pair<char, int>[sizest];
}

void push(stack &st, int x, char color)
{
	if (st.size_Stack < N)
	{
		st.s[st.size_Stack] = make_pair(color, x);
		st.size_Stack++;
	}
	else
	{
		cout << "Error! Array is already full";
	}
}

void pop(stack &st)
{
	if (st.size_Stack != 0)
	{
		st.size_Stack--;
	}
	else
	{
		cout << "Error! Array is already empty";
	}
}

pair <char, int> top(stack &st)
{
	if (st.size_Stack != 0)
	{
		return st.s[st.size_Stack - 1];
	}
	else
	{
		cout << "Error! Array is empty, there is nothing to return.";
		return make_pair(' ', -1);
	}
}

int main()
{
	stack st;
	cout << "Enter number of railway carriages ";
	cin >> N;
	Init(st, N);
	pair <char, int> *ans;
	ans = new pair <char, int>[N];
	cout << "Enter sequence of railway carriages " << '\n';
	cout << "If railway carriage is black - enter B, else enter W" << '\n';
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		char color;
		cin >> color;
		while ((color != 'B') && (color != 'W'))
		{
			cout << "Incorrect character! Try again" << '\n';
			cin >> color;
		}
		if (i == 0)
		{
			ans[k].second = i + 1;
			ans[k].first = color;
			k++;
		}
		else
		{
			if (st.size_Stack != 0)
			{
				pair <char, int> p = top(st);
				if (p.first != ans[k - 1].first)
				{
					ans[k] = p;
					pop(st);
					k++;
				}
			}
			if (ans[k - 1].first != color)
			{
				ans[k] = make_pair(color, i + 1);
				k++;
			}
			else
			{
				push(st, i + 1, color);
			}
		}
	}
	while (st.size_Stack != 0)
	{
		ans[k] = top(st);
		pop(st);
		k++;
	}
	for (int i = 0; i < k; i++)
	{
		cout <<  ans[i].second << "(" <<  ans[i].first << ") ";
	}
	return 0;
}