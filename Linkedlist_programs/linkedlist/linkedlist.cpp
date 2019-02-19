#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *next;
};
class list
{
	struct node *start;
public:
	list()
	{
		start = NULL;
	}
	void insert_at_beg(int ele);
	void insert_at_end(int ele);
	void insert_before(int,int);
	void insert_after(int ,int);
	int delete_beg();
	int delete_end();
	void delete_specific(int ele);
	void traverse_forward();
	friend void print(struct node*);
	void traverse_backward()
	{
		cout << "elements displayed in backward traversal\n";
		if (start != NULL)
			print(start);
	}
	void reverse();
	void display();
	~ list()
	{
		struct node*temp;
		while (start != NULL)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
	}
};
void list::insert_at_beg(int ele)
{
	struct node*temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void list::insert_at_end(int ele)
{
	struct node*temp,*curr;
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
void list::insert_before(int sele,int ele)
{
	if (start == NULL)
		cout << "list is empty\n";
	else
	{
		struct node*temp, *curr;
		temp = new node;
		temp->data = ele;
		if (start->data == sele)
		{
			temp->next = start;
			start = temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL&&curr->next->data != sele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp->next = curr->next;
				curr->next = temp;
			}
			else
				cout << "element not found\n";
		}
	}

}
void list::insert_after(int sele,int ele)
{
	if (start == NULL)
		cout << "list is empty\n";
	else
	{
		struct node*temp, *curr;
		temp = new node;
		temp->data = ele;
		curr = start;
		while (curr != NULL&&curr->data != sele)
			curr = curr->next;
		if (curr != NULL)
		{
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "element not found\n";
	}

}
int list::delete_beg()
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
int list::delete_end()
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
void list::delete_specific(int ele)
{
	int x = -999;
	if (start != NULL)
	{
		struct node*temp,*curr;
		temp = new node;
		if (start->data==ele)
		{
			temp = start;
			start = temp->next;
			delete temp;
		}
		else
		{
			curr = start;
			while (curr->next != NULL&&curr->next->data != ele)
				curr = curr->next;
			if (curr->next != NULL)
			{
				temp = curr->next;
				curr->next = temp->next;
				delete temp;
			}
			else
				cout << "element not found\n";
		}
	}
	else
		cout << "list is empty\n";
	
}
void list::traverse_forward()
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
void print(struct node *curr)
{
	if (curr != NULL)
	{
		print(curr->next);
		cout << curr->data << "\n";
	}
	
}
void list::reverse()
{
	struct node *temp,*rev = NULL;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		temp->next = rev;
		rev = temp;
	}
	start = rev;
}
int main()
{
	list l;
	int ch,el,sel,del;
	while (1)
	{
		cout << "1 insert at beginning\n2 insert at end\n 3insert before\n 4 insert after\n 5 delete at begin\n 6 delete at end\n7 delete element\n 8 traverse forward\n 9 traverse backward\n10 reverse\n";
		cout << "enter ur choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "eneter the element to be inserted at begin\n";
			cin >> el;
			l.insert_at_beg(el);
			break;
		case 2:cout << "eneter the element to be inserted at end\n";
			cin >> el;
			l.insert_at_end(el);
			break;
		case 3:cout << "eneter the element to be inserted before element\n";
			cin >> el;
			cout << "eneter the element before which u want to insert\n";
			cin >> sel;
			l.insert_before(sel, el);
			break;
		case 4:cout << "eneter the element to be inserted after element\n";
			cin >> el;
			cout << "eneter the element after which u want to insert\n";
			cin >> sel;
			l.insert_after(sel, el);
			break;
		case 5:del = l.delete_beg();
			cout << "element deleted at beginning is \n" << del;
			break;
		case 6:del = l.delete_end();
			cout << "element deleted at end is \n" << del;
			break;
		case 7:cout << "enter element  to be deleted is \n";
			cin >> del;
			l.delete_specific(del);
			break;
		case 8:l.traverse_forward();
			break;
		case 9:l.traverse_backward();
			break;
		case 10:l.reverse();
			break;
		}
	}
	return 0;
}