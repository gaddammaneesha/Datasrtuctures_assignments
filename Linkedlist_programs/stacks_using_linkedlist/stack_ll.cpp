#include<iostream>
using namespace std;
//stack implemnted using linkedlist 
struct node
{
	int data;
	struct node *next;
};
class stack
{
	struct node *start;
public:
	stack()
	{
		start = NULL;
	}
	~stack()
	{
		struct node*temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
	void insert_at_beg(int);
	int delete_beg();
	void display();
};
void stack::insert_at_beg(int ele)
{
	struct node*temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int stack::delete_beg()
{
	int x = -999;
	if (start != NULL)
	{
		struct node*temp;
		temp = start;
		start = temp->next;
		x = temp->data;
		delete temp;
	}
	else
		cout << "list is empty\n";
	return x;
}
void stack::display()
{
	cout << "stack elemets are:\n";
	struct node *curr;
	curr = start;
	while (curr != NULL)
	{
		cout << curr->data << "\n";
		curr = curr->next;
	}
}

int main()
{
	stack p;
	int ch, y, a;
	while (1)
	{
		cout << "\n1 push\n 2 pop\n 3display\n";
		cout << "enter choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter element\n";
			cin >> a;
			p.insert_at_beg(a);
			break;
		case 2: y = p.delete_beg();
			cout << "element popped is:\n" << y;
			break;
		case 3:p.display();
			break;
		default:;
		}
	}
	return 0;
}
