#include "stdafx.h"
#include <iostream>
#include "Queue.h"
#include <queue>
using namespace std;

int main()
{
	Queue < pair<int, int> > q;
	for (int i = 0; i < 5; i++)
	{
		q.push(make_pair(i, i+1));
	}
	while (q.size() != 0)
	{
		cout << q.front().first << " " << q.back().first <<" "<<q.front().second<<" "<<q.back().second;
		q.pop();
	}
    return 0;
}

