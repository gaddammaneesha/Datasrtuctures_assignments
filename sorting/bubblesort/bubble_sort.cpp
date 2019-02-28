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
}
void sorting()
{
	int i, j, flag;
	for (i = 0; i < n -1; i++)
	{
		flag = 0;
		for (j = 0; j < n-1-i ; j++)
		{
			if (a[j] > a[j+1])
			{
				flag = 1;
				int temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	
		if (flag == 0)
			break;
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