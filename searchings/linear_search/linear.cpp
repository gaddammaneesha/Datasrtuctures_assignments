#include<iostream>
using namespace std;
class linear
{
	int *a, size;
public:
	linear()
	{
		a = NULL;
		size = 0;
	}
	void getdata()
	{
		int i;
		cout << "enter array size\n";
		cin >> size;
		a = new int[size];
		cout << "enter integer array elements\n";
		for (i = 0; i < size; i++)
			cin >> a[i];
	}
	void search()
	{
		int s_el,i,flag=0;
		cout << "enter element to be searched\n";
		cin >> s_el;
		for (i = 0; i < size; i++)
		{
			if (a[i] == s_el)
			{
				cout << "element found at index " << i;
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			cout << "element not found in array\n";

	}
};
int main()
{
	linear l;
	l.getdata();
	l.search();
	system("pause");
	return 0;
}