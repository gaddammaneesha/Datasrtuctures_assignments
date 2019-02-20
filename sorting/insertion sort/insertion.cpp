#include<iostream>
using namespace std;
//insertion sorting
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
		int i, j, temp;
		for (i = 1; i <=n - 1; i++)
		{
			j = i - 1;
			temp = a[i];
			while (j >= 0 && a[j ] > temp)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
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