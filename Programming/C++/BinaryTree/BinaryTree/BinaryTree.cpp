#include "pch.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <fstream>

using namespace std;

struct node
{
	node* left;
	node* right;
	node* ancestor;
	int key;
};

node* root = NULL;

void print_tree()
{
	queue <node*> q;
	q.push(root);
	int x = 1;
	int null_counter = 0;
	if (root == NULL)
	{
		null_counter = 1;
	}
	while ((q.size() != null_counter) || (x!=0))
	{
		if (x == 0)
		{
			cout << '\n';
			x = q.size();
		}
		if (q.front() == NULL)
		{
			cout << "*(*) ";
			null_counter++;
			q.push(NULL);
			q.push(NULL);
		}
		else
		{
			q.push(q.front()->left);
			if (q.front()->left == NULL)
			{
				null_counter++;
			}
			q.push(q.front()->right);
			if (q.front()->right == NULL)
			{
				null_counter++;
			}
			cout << q.front()->key << " ";
		}
		x--;
		q.pop();
	}
}

int height(node* pos)
{
	if (pos == NULL)
	{
		return 0;
	}
	return max(height(pos->left), height(pos->right)) + 1;
}

void balance(node* pos)
{
	if (pos != NULL)
	{
		int a = height(pos->left);
		int b = height(pos->right);
		while (abs(a - b) > 1)
		{
			if (a > b)
			{
				node* q = pos->left;
				swap(pos->left, pos->right);
				swap(q->left, q->right);
				swap(q->right, pos->left);
				if (q->right != NULL)
				{
					q->right->ancestor = q;
				}
				if (pos->left != NULL)
				{
					pos->left->ancestor = pos;
				}
				swap(pos->key, q->key);
				a--;
				b++;
			}
			else
			{
				node* q = pos->right;
				swap(pos->left, pos->right);
				swap(q->right, pos->right);
				if (q->right != NULL)
				{
					q->right->ancestor = q;
				}
				if (pos->right != NULL)
				{
					pos->right->ancestor = pos;
				}
				swap(q->left, q->right);
				swap(pos->key, q->key);
				a++;
				b--;
			}
		}
		/*balance(pos->left);
		balance(pos->right);*/
		balance(pos->ancestor);
	}
}

node* insert(int k, node* pos)
{
	if (pos == NULL)
	{
		node* q = new node;
		q->left = NULL;
		q->right = NULL;
		q->ancestor = NULL;
		q->key = k;
		return q;
	}
	else
	{
		if (k > pos->key)
		{
			pos->right = insert(k, pos->right);
			pos->right->ancestor = pos;
		}
		else
		{
			pos->left = insert(k, pos->left);
			pos->left->ancestor = pos;
		}
		return pos;
	}
}

node* find(int k, node* pos)
{
	if (pos == NULL)
	{
		return NULL;
	}
	if (pos->key == k)
	{
		return pos;
	}
	if (pos->key < k)
	{
		return find(k, pos->right);
	}
	else
	{
		return find(k, pos->left);
	}
}

void del (int k)
{
	node* pos = find(k, root);
	if (pos != NULL)
	{
		if ((pos->left == NULL) && (pos->right == NULL))
		{
			if (pos == root)
			{
				root = NULL;
			}
			else
			{
				if (pos->ancestor->left == pos)
				{
					pos->ancestor->left = NULL;
				}
				else
				{
					pos->ancestor->right = NULL;
				}
			}
			delete pos;
		}
		else
		{
			if (pos->left == NULL)
			{
				node *q = pos->right;
				pos->key = q->key;
				pos->left = q->left;
				pos->right = q->right;
				delete q;
			}
			else
			{
				if (pos->right == NULL)
				{
					node *q = pos->left;
					pos->key = q->key;
					pos->left = q->left;
					pos->right = q->right;
					delete q;
				}
				else
				{
					node *q = pos->right;
					while (q->left != NULL)
					{
						q = q->left;
					}
					if (q->ancestor != pos) 
					{
						q->ancestor->left = q->right;
					}
					else
					{
						q->ancestor->right = q->right;
					}
					if (q->right != NULL)
					{
						q->right->ancestor = q->ancestor;
					}
					pos->key = q->key;
					delete q;
				}
			}
		}
		if (root != NULL)
		{
			balance(pos);
		}
	}
}

void sort_tree(node* pos)
{
	if (pos != NULL)
	{
		sort_tree(pos->left);
		cout << pos->key << " ";
		sort_tree(pos->right);
	}
}

void back_sort_tree(node* pos)
{
	if (pos != NULL)
	{
		back_sort_tree(pos->right);
		cout << pos->key << " ";
		back_sort_tree(pos->left);
	}
}

void help()
{
	cout << "List of commands\n";
	cout << "Insert x: 1 x\n";
	cout << "Delete x: 2 x\n";
	cout << "Sorted from min to max: 3\n";
	cout << "Sorted from max to min: 4\n";
	cout << "Print tree: 5\n";
	cout << "Height of tree: 6\n";
	//cout << "Balance tree: 7\n";
	cout << "End execution of program: 0\n";
}



int main()
{
	help();
	int x = -1;
	do
	{
		cin >> x;
		switch (x)
		{
		case 1:
		{
			int a;
			cin >> a;
			if (find(a, root) == NULL)
			{
				root = insert(a, root);
				balance(find(a, root));
			}
			break;
		}
		case 2:
		{
			int a;
			cin >> a;
			node* x = find(a, root);
			del(a);
			//balance(x);
			break;
		}
		case 3:
		{
			sort_tree(root);
			cout << '\n';
			break;
		}
		case 4:
		{
			back_sort_tree(root);
			cout << '\n';
			break;
		}
		case 5:
		{
			print_tree();
			cout << '\n';
			break;
		}
		case 6:
		{
			cout << height(root) << '\n';
			break;
		}
		/*case 7:
		{
			balance(root);
			break;
		}*/
		case 0:
		{
			break;
		}
		default:
		{
			cout << "Incorrect command!\n";
			help();
			break;
		}
		}

	} while (x != 0);
	return 0;
}

