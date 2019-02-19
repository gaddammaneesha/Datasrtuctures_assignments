#include<iostream>
using namespace std;
typedef struct queue_implementation
{
	int rear,front;
	int *s;
	int size;
};
class _queue
{
public:
	queue_implementation st;
	_queue()
	{
		st.rear=st.front= -1;
		st.s = NULL;
		st.size = 0;
	}
	void get_size(int n)
	{
		st.size = n;
		st.s = new int[n];
	}
	bool overflow()
	{
		if (st.rear== (st.size - 1))
			return true;
		else
			return false;
	}
	void enque(int el)
	{
		if (underflow())
		{
			st.front = 0;
			st.s[++st.rear] = el;
		}
		else if (!overflow())
			st.s[++st.rear] = el;
		else
			cout << " overflow\n";
	}
	bool underflow()
	{
		if (st.front== -1&&st.rear==-1)
			return true;
		else
			return false;
	}
	int deque()
	{
		int x = -999;
		if (!underflow())
			x = st.s[st.front++];
		else
			cout << " underflow\n";
		return x;
	}
	
	void display()
	{
		int i;
		cout << "queue elements are\n";
		for (i = st.front; i <= st.rear; i++)
			cout << st.s[i] << "\n";
	}
	~_queue()
	{
		delete st.s;
	}
};
int main()
{
	_queue p;
	int a, y, ch;
	cout << "enter size\n";
	cin >> a;
	p.get_size(a);
	while (1)
	{
		cout << "\n1 enque\n 2 deque\n 3 display\n";
		cout << "enter choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter element\n";
			cin >> a;
			p.enque(a);
			break;
		case 2: y = p.deque();
			cout << "element deleted is:\n" << y;
			break;
		case 3:p.display();
			break;
		default:;
		}
	}
	return 0;
}