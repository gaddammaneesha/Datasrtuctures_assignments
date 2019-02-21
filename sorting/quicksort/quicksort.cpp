#include<iostream>
using namespace std;
//qick sort
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
		quick_sort(0, n-1);
	}
	void quick_sort( int l, int u)
	{
		int i=l+1,pivot=a[l],j=u;
		if (l<u)
		{
			while (1)
			{
				while (i <= j&&a[i] < pivot)
					i++;
				while (a[j] > pivot)
					j--;
				if (i < j)
					swap(&a[i],&a[j]);
				else
					break;
			}
			swap(&a[l], &a[j]);
			quick_sort(l, j-1);
			quick_sort( j + 1, u);
		}
	}

	void swap(int *a, int *b)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
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