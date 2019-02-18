#include<iostream>
#include<string.h>
using namespace std;
//checking for balanced 
typedef struct stack_implementation
{
	int top;
	char  *s;
	int size;
};
class balance
{
	char *str;
public:
	stack_implementation st;
	balance()
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
		st.s = new char[st.size + 1];
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
	void pop()
	{
		if (!isempty())
			st.top--;
		else
			cout << "stack underflow\n";
	}
	char peek()
	{
		return (st.s[st.top]);
	}
	void check_bal()
	{
		int i, l = strlen(str), flag = 0;
		char ch;
		for (i = 0; i < l; i++)
		{
			ch = str[i];
			switch (ch)
			{
			case '(':
			case '[':
			case '{':
				push(ch);
				break;
			case ')':
			case ']':
			case '}':
				if (!isempty())
				{
					if ((ch == ')'&&peek() == '(') || (ch == ']'&&peek() == '[') || (ch == '}'&&peek() == '{'))
						pop();
					else
					{
						cout << "not balanced expression";
						flag = 1;
					}
				}
				else
				{
					cout << "not balanced expression";
					flag = 1;
				}
				break;
			default:;
			}
			if (flag == 1)
				break;
		}
		cout << str[i];
		if (isempty())
		{
			if (flag == 0 && str[i] == '\0')
				cout << "balanced expression";
		}
		else
			cout << "not balnced";
	}
	~balance()
	{
		delete str;
		delete st.s;
	}
};
int main()
{
	balance p;
	p.getdata();
	p.check_bal();
	return 0;
}