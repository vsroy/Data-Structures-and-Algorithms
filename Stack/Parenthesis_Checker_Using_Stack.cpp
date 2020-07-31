/*Given an expression string exp. Examine whether the pairs and the orders of “{“,”}”,”(“,”)”,”[“,”]” are correct in exp.*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool CheckBalancedParenthesis(string& str)
{
	stack<char> parenthesisStack;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			parenthesisStack.push(str[i]);
		else
		{
			if (str[i] == ')')
			{
				if (parenthesisStack.top() != '(')
					return false;
				else
					parenthesisStack.pop();
				
			}
			else if (str[i] == '}')
			{
				if (parenthesisStack.top() != '{')
					return false;
				else
					parenthesisStack.pop();
			}
			else if (str[i] == ']')
			{
				if (parenthesisStack.top() != '[')
					return false;
				else
					parenthesisStack.pop();
			}
		}
	}
	if (!parenthesisStack.empty())
		return false;
	else
		return true;
}

int main()
{
	string expr = "{()}[]";
	cout << CheckBalancedParenthesis(expr);
	return 0;
}