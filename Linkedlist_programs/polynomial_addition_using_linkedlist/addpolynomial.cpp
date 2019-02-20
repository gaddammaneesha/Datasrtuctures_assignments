#include<iostream>
using namespace std;
//adding polynomials using linkedlist 
struct list
{
	int pow;
	signed int coef;
	struct list *next;
};
class poly
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
			cout << "\n enter coeff:";
			cin >> node->coef;
			cout << "\n enter power:";
			cin >> node->pow;
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
			cout << node->coef << "x^" << node->pow;
			node = node->next;
			if (node->next != NULL)
				cout << "+";
		}
	}
	void polyadd(struct list *poly1, struct list *poly2, struct list **res)
	{
		struct list *poly;
		poly = new list;
		poly->next = NULL;
		*res = poly;
		while (poly1 != NULL&&  poly2 != NULL)
		{
			if (poly1->pow>poly2->pow)
			{
				poly->pow = poly1->pow;
				poly->coef = poly1->coef;
				poly1 = poly1->next;
			}
			else if (poly1->pow<poly2->pow)
			{
				poly->pow = poly2->pow;
				poly->coef = poly2->coef;
				poly2 = poly2->next;
			}
			else
			{
				poly->pow = poly1->pow;
				poly->coef = poly1->coef + poly2->coef;
				poly1 = poly1->next;
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
				poly->pow = poly1->pow;
				poly->coef = poly1->coef;
				poly1 = poly1->next;
			}
			if (poly2 != NULL)
			{
				poly->pow = poly2->pow;
				poly->coef = poly2->coef;
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
	poly n;
	struct list *l1, *l2, *res;
	l1 = new list;
	l2 = new list;
	res = new list;
	cout << "\nenter 1st number:";
	n.create(&l1);
	cout << "\nenter 2nd number:";
	n.create(&l2);
	n.polyadd(l1, l2, &res);
	cout << "\nAdded polynomial:";
	n.show(res);
	return 0;
}
