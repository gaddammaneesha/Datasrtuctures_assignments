# include <iostream>
using namespace std;
struct queue
{
	int rear, front;
	int *s;
	int size;
};
class cqueue
{
	struct queue st;
public:
	cqueue()
	{
		st.rear = st.front = -1;
		st.s = NULL;
		st.size = 0;
	}
	void get_size()
	{
		cout << "eneter size\n";
		cin>>st.size ;
		st.s = new int[st.size];
	}
	bool overflow()
	{
		if ( st.front == (st.rear + 1)%(st.size))
		{
			cout<< "Queue Overflow \n";
			return true;
		}
		else
			return false;
	}
	bool underflow()
	{
		if (st.front == -1)
		{
			cout << "Queue Underflow\n";
			return true;
		}
		else
			return false;
	}
	void insert(int);
	int delete_el();
	void display();
};
void cqueue::insert(int val)
{
	if (st.front == -1) 
	{
		st.front = 0;
		st.rear = 0;
		st.s[st.rear] = val;
	}
	else
	{
		st.rear = (st.rear + 1) % (st.size);
		st.s[st.rear] = val;
	}
}
int cqueue::delete_el()
{
	int x;
	x = st.s[st.front];
	st.front= (st.front + 1) % (st.size);
	return x;
}
void cqueue::display()
{
	if (st.front == -1) 
	{
		cout << "Queue is empty" << endl;
		return;
	}
	if (!underflow())
	{
		int i;
		for (i = st.front; i != st.rear; i = (i + 1) % (st.size))
			cout << st.s[i] << "\n";
	}
	
}
int main()
{
	cqueue c;
	c.get_size();
	int ch, val,del;
	cout << "1)Insert\n";
	cout << "2)Delete\n";
	cout << "3)Display\n";
	cout << "4)Exit\n";
	do {
		cout << "Enter choice : " << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Input for insertion: " << endl;
			cin >> val;
			c.insert(val);
			break;

		case 2:del=c.delete_el();
			cout << "element deleted is \n" << del;
			break;

		case 3:
			c.display();
			break;

		case 4:
			cout << "Exit\n";
			break;
		default: cout << "Incorrect!\n";
		}
	} while (ch != 4);
	return 0;
}