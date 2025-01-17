#include "pch.h"
#include <iostream>
#include <fstream>
using namespace std;

struct node
{
	node* next;
	int cnt;
	int data;
};

node* first = NULL;
node* last = NULL;

void insert_begin(int a)
{
	node* q = new node;
	q->data = a;
	q->cnt = 1;
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
	q->data = a;
	q->cnt = 1;
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
	q->data = a;
	q->cnt = 1;
	q->next = NULL;
	if ((first == NULL) || (first->data > q->data))
	{
		insert_begin(a);
	}
	else
	{
		if (last->data < q->data)
		{
			insert_end(a);
		}
		else
		{
			node* p = first;
			while (p->next->data < q->data)
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
		if (q->next->data == a)
		{
			return q;
		}
	}
	return NULL;
}

/* find_add(int a)
{
	for (node* q = first; q != NULL; q = q->next)
	{
		if (q->data == a)
		{
			return q;
		}
	}
	return NULL;
}*/

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

/*void Add(int a)
{
	node* q = find_add(a);
	if (q == NULL)
	{
		insert_sort(a);
	}
	else
	{
		q->cnt++;
	}
}*/
void help(int mode)
{
	switch (mode)
	{
	case 1:
	{
		cout << "1 x: Insert x to begin\n";
		cout << "2 x: Push x to end\n";
		cout << "3 x: Delete x\n";
		cout << "4: Print\n";
		cout << "0: End execution of programm\n";
		break;
	}
	case 2:
	{
		cout << "1 x: Insert x\n";
		cout << "2 x: Delete x\n";
		cout << "3: Print\n";
		cout << "0: End execution of programm\n";
		break;
	}
	}
}
void print()
{
	for (node* i = first; i != NULL; i = i->next)
	{
		cout << i->data << " ";
	}
	cout << '\n';
}
int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int mode;
	cout << "Choose list mode:\n";
	cout << "1: Simple list\n";
	cout << "2: Sorted list\n";
	cin >> mode;
	while ((mode < 1) || (mode > 2))
	{
		cout << "Error! Input 1 or 2\n";
		cin >> mode;
	}
	system("cls");
	help(mode);
	int task = -1;
	while (task != 0)
	{
		cin >> task;
		if (mode == 1)
		{
			switch (task)
			{
			case 1:
			{
				int x;
				cin >> x;
				insert_begin(x);
				break;
			}
			case 2:
			{
				int x;
				cin >> x;
				insert_end(x);
				break;
			}
			case 3:
			{
				int x;
				cin >> x;
				Delete(x);
				break;
			}
			case 4:
			{
				print();
				break;
			}
			case 0:
			{
				return 0;
				break;
			}
			default:
			{
				cout << "Wrong command!\n";
				help(1);
				break;
			}
			}
		}
		else
		{
			switch (task)
			{
			case 1:
			{
				int x;
				cin >> x;
				insert_sort(x);
				break;
			}
			case 2:
			{
				int x;
				cin >> x;
				Delete(x);
				break;
			}
			case 3:
			{
				print();
				break;
			}
			case 0:
			{
				return 0;
				break;
			}
			default:
			{
				cout << "Wrong command!\n";
				help(2);
				break;
			}
			}
		}
	}
	return 0;
}