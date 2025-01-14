#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct node
{
	node* next;
	node* prev;
	int cnt;
	string s;
};

node* first = NULL;
node* last = NULL;

void insert_begin(string a)
{
	node* q = new node;
	first->prev = q;
	q->next = first;
	q->prev = NULL;
	q->s = a;
	q->cnt = 1;
	if (last == NULL)
	{
		first = q;
		last = q;
	}
	else
	{
		first->prev = q;
	}
}

void insert_end(string a)
{
	node* q = new node;
	last->next = q;
	q->s = a;
	q->cnt = 1;
	q->next = NULL;
	q->prev = last;
	if (first == NULL)
	{
		first = q;
		last = q;
	}
	else
	{
		last->next = q;
	}
}

void insert_sort(string a)
{
	node* q = new node;
	q->s = a;
	q->cnt = 1;
	q->next = NULL;
	q->prev = NULL;
	if ((first == NULL) || (first->s > q->s))
	{
		insert_begin(a);
	}
	else
	{
		if (last->s < q->s)
		{
			insert_end(a);
		}
		else
		{
			node* p = first;
			while (p->next->s < q->s)
			{
				p = p->next;
			}
			q->next = p->next;
			q->prev = p;
			p->next->prev = q;
			p->next = q;
		}
	}
}

node* find(string a)
{
	for (node* q = first; q != NULL; q = q->next)
	{
		if (q->s == a)
		{
			return q;
		}
	}
	return NULL;
}

void Delete(string a)
{
	node* q = find(a);
	if (q != NULL)
	{
		q->prev->next = q->next;
		q->next->prev = q->prev;
		delete q;
	}
}

void print()
{
	for (node* i = first; i != NULL; i = i->next)
	{
		cout << i->s << '\n';
	}
}
int main()
{
	return 0;
}