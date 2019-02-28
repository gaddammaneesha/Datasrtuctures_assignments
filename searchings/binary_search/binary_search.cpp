#include<iostream>
using namespace std;
class linear
{
	int *a, size,s_el;
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
		cout << "enter integer array elements in sorting order for binary search\n";
		for (i = 0; i < size; i++)
			cin >> a[i];
		cout << "enter element to be searched\n";
		cin >> s_el;
		binary_search(0, size - 1);
	}
	void binary_search(int low,int high)
	{
		int mid, flag = 0;;
		while (low < high)
		{
			mid = (low + high) / 2;
			if (s_el < a[mid])
				binary_search(low, mid - 1);
			else if (s_el > a[mid])
				binary_search(mid + 1, high);
			else
			{
				cout << "element found at index" << mid<<"\n";
				flag = 1;
				break;
			}

		}
		if (flag == 0)
			cout << "element not found\n";
	}
};
int main()
{
	linear l;
	l.getdata();
	system("pause");
	return 0;
}