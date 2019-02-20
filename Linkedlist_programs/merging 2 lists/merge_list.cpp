#include<iostream>
using namespace std;
struct list
{
	int data;
	struct list *next;
};
class merge
{
public:
	void create(struct list **temp)
	{
		char ch;
		struct list *node;
		node = new list;
		*temp = node;
		do
		{
			cout << "\n enter data:";
			cin >> node->data;
			node->next = NULL;
			cout << "\n continue(yes/no)";
			cin >> ch;
			if (ch == 'y')
			{
				node->next = new list; //Grow the list
				node = node->next;
				node->next = NULL;
			}

		} while (ch == 'y' || ch == 'Y');
	}
	void show(struct list *node)
	{
		while (node->next != NULL)
		{
			cout << node->data << "\n" ;
			node = node->next;

		}
	}
	void merge_list(struct list *poly1, struct list *poly2, struct list **res)
	{
		struct list *poly;
		poly = new list;
		poly->next = NULL;
		*res = poly;
		while (poly1 != NULL&&  poly2 != NULL)
		{
			if (poly1->data<poly2->data)
			{
				poly->data = poly1->data;
				poly1 = poly1->next;
			}
			else 
			{
				poly->data = poly2->data;
				poly2 = poly2->next;
			}
			
			poly->next = new list;
			poly = poly->next;
			poly->next = NULL;
		}
		while (poly1 != NULL || poly2 != NULL)
		{
			if (poly1 != NULL)
			{
				poly->data = poly1->data;
				poly1 = poly1->next;
			}
			if (poly2 != NULL)
			{
				poly->data = poly2->data;
				poly2 = poly2->next;
			}
			poly->next = new list;
			poly = poly->next;
			poly->next = NULL;
		}
	}
};

int main()
{
	merge n;
	struct list *l1, *l2, *res;
	l1 = new list;
	l2 = new list;
	res = new list;
	cout << "\nenter 1st list:";
	n.create(&l1);
	cout << "\nenter 2nd list:";
	n.create(&l2);
	n.merge_list(l1, l2, &res);
	cout << "\nAfter merging the resulted list is :"<<"\n";
	n.show(res);
	return 0;
}
