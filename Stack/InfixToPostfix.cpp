// Program to convert an Infix expression to Postfix expression
// Time Complexity - 
// Space Complexity - 

#include<iostream>
#include<stack>
using namespace std;

stack<char> S;

bool IsOperator(char C)
{
	if( C =='+' || C =='-' || C =='*' || C =='/') return true;
	return false;
}

bool IsOperand(char C)
{
	if(C >= '0' && C <= '9') return true;
	if(C >= 'a' && C <= 'z') return true;
	if(C >= 'A' && C <= 'Z') return true;
	return false;
}

bool IsOpeningParantheses(char C)
{
	if(C =='(' || C =='[' || C =='{') return true;
	return false;
}

bool IsClosingParantheses(char C)
{
	if(C ==')' || C ==']' || C =='}') return true;
	return false;
}

int getOperatorWeight(char opr)
{
	int weight = -1;
	switch(opr)
	{
		case '+':
		case '-':
			weight = 1;
			break;
		case '*':
		case '/':
			weight = 2;
			break;
	}
	return weight;
}

bool hasHigherPrecedence(char op1,char op2)
{
	int op1Weight = getOperatorWeight(op1);
	int op2Weight = getOperatorWeight(op2);

	return (op1Weight >= op2Weight)? true:false;
}

string InfixToPostfix(string exp)
{
	string postfix = "";
	
	for(int i=0;i<exp.length();i++)
	{
		if(exp[i] == ' ' || exp[i] == ',') continue;
		
		else if(IsOperand(exp[i]))
		{
			postfix += exp[i];
		}
		
		else if(IsOperator(exp[i]))
		{
			while(!S.empty() && !IsOpeningParantheses(S.top()) && hasHigherPrecedence(S.top(),exp[i]))
			{
				postfix += S.top();
				S.pop();
			}
			S.push(exp[i]);
		}
		
		else if(IsOpeningParantheses(exp[i]))
		{
			S.push(exp[i]);
		}
		
		else if(IsClosingParantheses(exp[i]))
		{
			while(!S.empty() && !IsOpeningParantheses(S.top()))
			{
				postfix += S.top();
				S.pop();
			}
			S.pop();
		}
	}
	
	while(!S.empty())
	{
		postfix += S.top();
		S.pop();
	}

	return postfix;
}

int main()
{
	string expression;
	getline(cin,expression);
	string postfix = InfixToPostfix(expression);
	cout<<postfix;
	return 0;
}