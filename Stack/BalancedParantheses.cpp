// Program to check whether the expression has Balanced Parantheses 
// Time Complexity - O(n)
// Space Complexity - O(n)
#include<iostream>
#include<stack> // Using C++ STL

using namespace std;

bool IsOpenParantheses(char s)
{
	if(s =='(' || s =='[' || s =='{')
	{
		return true;
	}
	return false;
}

bool IsClosedParantheses(char s)
{
	if(s ==')' || s ==']' || s =='}')
	{
		return true;
	}
	return false;
}

bool areParanthesesBalanced(string exp)
{
	stack<char> S;
	for(int i=0;i<exp.length();i++)
	{
		if(IsOpenParantheses(exp[i]))
		{
			S.push(exp[i]);
		}
		else if(IsClosedParantheses(exp[i]))
		{
			if(S.empty())
			{
				return false;
			}
			else if(S.top()=='(' && exp[i] != ')')
			{
				return false;
			}
			else if(S.top()=='[' && exp[i] != ']')
			{
				return false;
			}
			else if(S.top()=='{' && exp[i] != '}')
			{
				return false;
			}
			S.pop();
		}
	}
	return S.empty() ? true:false;
}

int main()
{
	string expression;
	cin>>expression;
	bool result = areParanthesesBalanced(expression);
	cout<<((result)?"YES":"NO");
	return 0;
}