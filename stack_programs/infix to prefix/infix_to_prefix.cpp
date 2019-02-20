#include<iostream>
#include<string.h>
using namespace std;
typedef struct stack_implementation
{
	int top;
	char  *s;
	int size;
};
//infix to prefix conversio
int k = 0;
class conversion
{
	char *str;
	char res[20];
public:
	stack_implementation st;
	conversion()
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
		_strrev(str);
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
		char ch;
		int l = strlen(str) + 1;
		if (!isempty())
		{
			ch = st.s[st.top--];
			if (ch != '('&&ch != '['&&ch != '{'&&ch != ')'&&ch != ']'&&ch != '}')
				res[k++] = ch;
		}
		else
			cout << "stack underflow\n";
	}
	int check_precedence(char ch)
	{
		if (ch == '+' || ch == '-')
			return 2;
		else if (ch == '*' || ch == '/')
			return 3;
		else
			return 1;
	}
	void convert()
	{
		int i, l = strlen(str);
		char ch;
		for (i = 0; i < l; i++)
		{
			ch = str[i];
			switch (ch)
			{
			case ')':
			case ']':
			case '}':
				push(ch);
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case '[':
			case '{':
				if (isempty())
					push(ch);
				else
				{
					if (check_precedence(ch) <= check_precedence(peek()))
					{
						while (check_precedence(ch) <= check_precedence(peek()) && (!isempty()))
							pop();
						push(ch);
					}
					else
						push(ch);
				}

				break;
			default:res[k++] = ch;
				break;
			}

		}
		if (str[i] == '\0' && (!isempty()))
		{
			while (!isempty())
				pop();
		}
	}
	char peek()
	{
		return (st.s[st.top]);
	}
	void display()
	{
		cout << "conevrted prefix expression from infix is:\n";
		cout << _strrev(res) << "\n";
	}
	~conversion()
	{
		delete str;
		delete st.s;
	}
};
int main()
{
	conversion c;
	c.getdata();
	c.convert();
	c.display();
	return 0;

}