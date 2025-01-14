#include "pch.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>

using namespace std;

ifstream in ("input.txt");
ofstream fout ("output.txt");

struct element
{
	long long x;
	char symbol;
	bool type;
};

void out(vector <element> polish)
{
	for (int i = 0; i < polish.size(); i++)
	{
		if (polish[i].type)
		{
			fout << polish[i].x;
		}
		else
		{
			fout << polish[i].symbol;
		}
		fout << " ";
	}
	fout << '\n';
}
int main()
{
	vector <element> polish;
	stack < pair<char, long long> > st;
	string s;
	getline(in, s);
	element e;
	pair <long long, bool> a;
	a.first = 0;
	a.second = false;
	int minus = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= '0') && (s[i] <= '9'))
		{
			a.second = true;
			a.first *= 10;
			a.first += s[i] - '0';
		}
		else
		{
			if (a.second)
			{
				a.second = false;
				e.type = true;
				e.x = a.first;
				e.x *= minus;
				minus = 1;
				a.first = 0;
				polish.push_back(e);
			}
			if ((s[i] == '-') && ((i == 0) || (!((s[i - 1] >= '0') && (s[i - 1] <= '9')))))
			{
				minus = -1;
			}
			else
			{
				int operation;
				if (s[i] == '^')
				{
					operation = 4;
				}
				if ((s[i] == '*') || (s[i] == '/'))
				{
					operation = 3;
				}
				if ((s[i] == '-') || (s[i] == '+'))
				{
					operation = 2;
				}
				if ((s[i] == '(') || (s[i] == ')'))
				{
					operation = 1;
				}
				if (operation >= 2)
				{
					while ((st.size() != 0) && (st.top().second >= operation))
					{
						e.symbol = st.top().first;
						e.type = false;
						polish.push_back(e);
						st.pop();
					}
					st.push(make_pair(s[i], operation));
				}
				else
				{
					if (s[i] == '(')
					{
						st.push(make_pair(s[i], operation));
					}
					else
					{
						while (st.top().first != '(')
						{
							e.type = false;
							e.symbol = st.top().first;
							polish.push_back(e);
							st.pop();
						}
						st.pop();
					}
				}
			}
		}
	}
	if (a.second)
	{
		e.type = true;
		e.x = a.first;
		polish.push_back(e);
	}
	while (st.size() != 0)
	{
		e.type = false;
		e.symbol = st.top().first;
		polish.push_back(e);
		st.pop();
	}
	out(polish);
	while (polish.size() != 1)
	{
		for (int i = 0; i < polish.size(); i++)
		{
			if ((!(polish[i].type)) && (polish[i-1].type) && (polish[i-2].type))
			{
				switch (polish[i].symbol)
				{
				case '+':
				{
					polish[i - 2].x += polish[i - 1].x;
					break;
				}
				case '-':
				{
					polish[i - 2].x -= polish[i - 1].x;
					break;
				}
				case '*':
				{
					polish[i - 2].x *= polish[i - 1].x;
					break;
				}
				case '/':
				{
					polish[i - 2].x /= polish[i - 1].x;
					break;
				}
				case '^':
				{
					long long z = polish[i - 2].x;
					for (int j = 1; j < polish[i - 1].x; j++)
					{
						polish[i - 2].x *= z;
					}
					break;
				}
				}
				polish.erase(polish.begin() + i);
				i--;
				polish.erase(polish.begin() + i);
				i--;
				out(polish);
			}
		}
	}
	return 0;
}

