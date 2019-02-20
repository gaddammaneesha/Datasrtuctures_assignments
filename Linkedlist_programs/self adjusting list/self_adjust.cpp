#include<iostream>
using namespace std;
//moving the search element to beginning
struct node
{
	int data;
	struct node *next;
};
class self_adjust
{
	struct node *start;
public:
	self_adjust()
	{
		start = NULL;
	}
	void insert(int);
	void adjust(int);
	void display();
};
void self_adjust::insert(int ele)
{
	struct node*temp, *curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if (start != NULL)
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
	else
		start = temp;
}
void self_adjust::display()
{
	cout << "elements displayed in forward traversal\n";
	if (start != NULL)
	{
		struct node *curr = start;
		while (curr != NULL)
		{
			cout << curr->data << "\n";
			curr = curr->next;
		}
	}
	else
		cout << "list is empty\n";
}

void self_adjust::adjust(int el)
{
	struct node*temp = start, *curr;
	if (start == NULL)
		cout << "list is empty\n";
	else if (start->data == el)
		cout << "list contains only one element\n";
	else
	{
		while (temp->next != NULL&&temp->next->data != el)
			temp = temp->next;
		if (temp->next != NULL)
		{
			curr = start;
			start = temp->next;
			temp->next = temp->next->next;
			start->next = curr;
		}
	}
}
int main()
{
	self_adjust s;
	int el, ch;
	while (1)
	{
		cout << "enter ur choice\n";
		cout << "1 insert\n 2 adjust\n 3 display\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter the element to be inserted\n";
			cin >> el;
			s.insert(el);
			break;
		case 2: cout << "enter element to be searched and adjusted\n";
			cin >> el;
			s.adjust(el);
			break;
		case 3:s.display();
			break;
		}
	}
}


