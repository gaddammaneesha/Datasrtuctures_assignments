#include<iostream>
using namespace std;
//queue using linkedlist
struct node
{
	int data;
	struct node *next;
};
class queue
{
	struct node *start;
public:
	queue()
	{
		start = NULL;
	}
	~queue()
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
	int delete_end();
	void display();
};
void queue::insert_at_beg(int ele)
{
	struct node*temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
int queue::delete_end()
{
	int x = -999;
	if (start != NULL)
	{
		if (start->next != NULL)
		{
			struct node*temp;
			temp = start;
			while (temp->next->next != NULL)
				temp = temp->next;
			x = temp->next->data;
			delete temp->next;
			temp->next = NULL;
		}
		else
		{
			x = start->data;
			delete start;
			start = NULL;
		}
	}
	else
		cout << "list is empty\n";
	return x;
}
void queue::display()
{
	cout << "queue elements are\n";
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
	queue p;
	int ch, y, a;
	while (1)
	{
		cout << "\n1 enque\n 2 dequeue\n 3display\n";
		cout << "enter choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter element\n";
			cin >> a;
			p.insert_at_beg(a);
			break;
		case 2: y = p.delete_end();
			cout << "element popped is:\n" << y;
			break;
		case 3:p.display();
			break;
		default:;
		}
	}
	return 0;
}
