#include<iostream>
using namespace std;
class sort
{
	int *a;
	int n;
public:
	sort()
	{
		a = NULL;
		n = 0;
	}
	void getdata()
	{
		int i;
		cout << "enter size\n";
		cin >> n;
		a = new int[n];
		cout << "enter elements\n";
		for (i = 0; i < n; i++)
			cin >> a[i];
		heap_sort();
	}
	void heap_sort()
	{
		int i,j;
		for (i = (n / 2) - 1; i >= 0; i--)
			build_heap(i, n);
		for (j = 1; j <= n - 1; j++)
		{
			swap(&a[0],&a[ n - j]);
			build_heap(0, n - j);
		}

	}
	void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	void build_heap(int i, int j)
	{
		int c,temp = a[i];
		for (; (2 * i + 1) < j; i=c)
		{
			c = 2 * i + 1;
			if (c + 1 < j&&a[c + 1] > a[c])
				c++;
			if (a[c] > temp)
				a[i] = a[c];
			else
				break;
		}
		a[i] = temp;
	}
	void display()
	{
		int i;
		for (i = 0; i < n; i++)
			cout << a[i] << "\t";
	}
};
int main()
{
	sort s;
	s.getdata();
	cout << "after sorting elements are:\n";
	s.display();
	return 0;
}

