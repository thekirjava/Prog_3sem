#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	node* next;
	int x;
};

node* first = NULL;
node* last = NULL;

void insert_begin(int a)
{
	node* q = new node;
	q->x = a;
	q->next = first;
	first = q;
	if (last == NULL)
	{
		last = first;
	}
}

void insert_end(int a)
{
	node* q = new node;
	q->x = a;
	q->next = NULL;
	if (last == NULL)
	{
		last = q;
		first = q;
	}
	else
	{
		last->next = q;
		last = q;
	}
}

void insert_sort(int a)
{
	node* q = new node;
	q->x = a;
	q->next = NULL;
	if ((first == NULL) || (first->x > q->x))
	{
		insert_begin(a);
	}
	else
	{
		if (last->x < q->x)
		{
			insert_end(a);
		}
		else
		{
			node* p = first;
			while (p->next->x < q->x)
			{
				p = p->next;
			}
			q->next = p->next;
			p->next = q;
		}
	}
}

node* find_del(int a)
{
	for (node* q = first; (q != NULL) && (q->next != NULL); q = q->next)
	{
		if (q->next->x == a)
		{
			return q;
		}
	}
	return NULL;
}

node* find_add(int a)
{
	for (node* q = first; q != NULL; q = q->next)
	{
		if (q->x == a)
		{
			return q;
		}
	}
	return NULL;
}

void Delete(int a)
{
	node* q = find_del(a);
	if (q->next != NULL)
	{
		node* p = q->next;
		q->next = q->next->next;
		delete p;
	}
}

void Revert()
{
	node* q = first;
	node* prev = NULL;
	node* pos = first;
	while (pos != NULL)
	{
		pos = pos->next;
		q->next = prev;
		prev = q;
		q = pos;
	}
	swap(first, last);
}

void print_list()
{
	for (node* i = first; i != NULL; i = i->next)
	{
		cout << i->x << " ";
	}
	cout << '\n';
}
int main()
{
	int N;
	cout << "Input size of list\n";
	cin >> N;
	cout << "Input list\n";
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		insert_end(x);
	}
	print_list();
	Revert();
	print_list();
}