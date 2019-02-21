#include<iostream>
using namespace std;
//merge sort
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
		merge_sort(0, n - 1);

	}
	void merge_sort(int low, int high)
	{
		int mid;

		if (low<high)
		{
			mid = (low + high) / 2;
			merge_sort(low, mid);        //left recursion
			merge_sort(mid + 1, high);    //right recursion
			merging(low, mid, mid + 1, high);    //merging of two sorted sub-arrays
		}
	}

	void merging(int i1, int j1, int i2, int j2)
	{
		int temp[50];    //array used for merging
		int i, j, k;
		i = i1;    //beginning of the first list
		j = i2;    //beginning of the second list
		k = 0;

		while (i <= j1 && j <= j2)    //while elements in both lists
		{
			if (a[i]<a[j])
				temp[k++] = a[i++];
			else
				temp[k++] = a[j++];
		}

		while (i <= j1)    //copy remaining elements of the first list
			temp[k++] = a[i++];

		while (j <= j2)    //copy remaining elements of the second list
			temp[k++] = a[j++];

		//Transfer elements from temp[] back to a[]
		for (i = i1, j = 0; i <= j2; i++, j++)
			a[i] = temp[j];
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