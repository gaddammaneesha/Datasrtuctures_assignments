#include<iostream>
#include<string.h>
using namespace std;
typedef struct stack_implementation
{
	int top;
	int *s;
	int size;
};
//postfix
class evaluation
{
	char *str;
public:
	stack_implementation st;
	evaluation()
	{
		st.s = NULL;
		st.size = 0;
		st.top = -1;
		str = NULL;
	}
	void getdata()
	{
		cout << "enter size of string\n";
		cin >> st.size;
		st.s = new int[st.size + 1];
		str = new char[st.size + 1];
		cout << "enter string\n";
		cin >> str;
	}
	bool isfull()
	{
		if (st.top == (st.size - 1))
			return true;
		else
			return false;
	}
	void push(char el)
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
	int  pop()
	{
		int ch;
		if (!isempty())
			ch = st.s[st.top--];
		else
			cout << "stack underflow\n";
		return ch;
	}
	void calculate()
	{
		int i,x,y,l = strlen(str);
		char ch;	
		for (i = 0; i < l; i++)
		{
			ch = str[i];
			if (isdigit(ch))
				push(ch-'0');
			else
			{
				x = pop();
				y = pop();
				switch (ch)
				{
					case '*':push(x*y);
						break;
					case '/':push(y/x);
						break;
					case '+':push(x+y);
						break;
					case '-':push(y-x);
						break;
					default:;
				}
			}
		}
			
	}
	char peek()
	{
		return (st.s[st.top]);
	}
	void display()
	{
		cout << "evaluated postfix expression is:\n";
		cout<<pop();
	}
	~evaluation()
	{
		delete str;
		delete st.s;
	}
};
int main()
{
	evaluation c;
	c.getdata();
	c.calculate();
	c.display();
	return 0;

}