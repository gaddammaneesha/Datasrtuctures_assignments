#include<iostream>
using namespace std;
//selection sorting
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
	}
	void sorting()
	{
		int loc, i, j;
		for (i = 0; i <n - 1; i++)
		{
			j = i +1;
			loc=i;
			while (j <=n-1)
			{
				if (a[j] < a[loc])
					loc = j;
				j++;
			}
			int temp = a[i];
			a[i] = a[loc];
			a[loc] = temp;
		}
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
	s.sorting();
	cout << "after sorting elements are:\n";
	s.display();
	return 0;
}