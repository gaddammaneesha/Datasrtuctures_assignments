#include<iostream>
using namespace std;
typedef struct stack_implementation
{
	int top;
	int *s;
	int size;
};
class _stack
{
public:
	stack_implementation st;
	_stack()
	{
		st.top = -1;
		st.s = NULL;
		st.size = 0;
	}
	void get_size(int n)
	{
		st.size = n;
		st.s = new int[n];
	}
	bool isfull()
	{
		if (st.top == (st.size - 1))
			return true;
		else
			return false;
	}
	void push(int el)
	{
		if (!isfull())
			st.s[++st.top] = el;
		else
			cout << "stack overflow\n";
	}
	bool isempty()
	{
		if (st.top == -1)
			return true;
		else
			return false;
	}
	int pop()
	{
		int x = -999;
		if (!isempty())
			x = st.s[st.top--];
		else
			cout << "stack underflow\n";
		return x;
	}
	int peek()
	{
		return (st.s[st.top]);
	}
	void display()
	{
		int i;
		cout << "stack elements are\n";
		for (i = 0; i <= st.top; i++)
			cout << st.s[i] << "\n";
	}
	~_stack()
	{
		delete st.s;
	}
};
int main()
{
	_stack p;
	int a, y, ch;
	cout << "enter size\n";
	cin >> a;
	p.get_size(a);
	while (1)
	{
		cout << "\n1 push\n 2 pop\n 3 peek 4 display\n";
		cout << "enter choice\n";
		cin >> ch;
		switch (ch)
		{
		case 1:cout << "enter element\n";
			cin >> a;
			p.push(a);
			break;
		case 2: y = p.pop();
			cout << "element popped is:\n" << y;
			break;
		case 3: y = p.peek();
			cout << "element in the top is:\n" << y;
			break;
		case 4:p.display();
			break;
		default:;
		}
	}
	return 0;
}