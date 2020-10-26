// Program to evaluate prefix or postfix expression 
// Time Complexity - O(n)
// Space Complexity - O(n)
#include<iostream>
#include<stdlib.h>
#include<limits>
using namespace std;

int stack[10],top = -1;

void Push(int x)
{
	stack[++top] = x;
}

int Pop()
{
	return stack[top--];
}

int Top()
{
	if(top!=-1) return stack[top];
	return -1;
}

void Print()
{
	if(top==-1) return;
	cout<<"Stack :";
	for(int i=0;i<=top;i++)
	{
		cout<<stack[i]<<" ";
	}
	cout<<"\n";
}

bool IsOperator(char x)
{
	if( x=='+' || x=='-' || x=='*' || x=='/') return true;
	return false;
}


int arithmetic(int a,int b,char key)
{
	switch(key)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		default:
			return 0;
	}
}

int evaluatePostfix(string exp)
{
	cout<<"Postfix Evaluation\n";
	int a,b,res;
	for(int i=0;i<exp.length();i++) 
	{
		if(exp[i] == ' ' || exp[i] == ',') continue;
		
		else if(IsOperator(exp[i]))
		{
			b = Pop();
			a = Pop();
			res = arithmetic(a,b,exp[i]);
			Push(res);
			Print();
		}
		else
		{
			// Converting char to int
			Push(exp[i]-'0');	
		}
	}
	return Top();
}

int evaluatePrefix(string exp)
{
	cout<<"Prefix Evaluation\n";
	int a,b,res;
	for(int i=exp.length()-1;i>=0;i--)
	{
		if(IsOperator(exp[i]))
		{
			a = Pop();
			b = Pop();
			res = arithmetic(a,b,exp[i]);
			Push(res);
			Print();
		}
		else
		{
			Push(exp[i]-'0');
		}
	}
	return Top();
}

int main()
{ 
	int key,result;
	string expression;
	cout<<
		"Option:1 Evaluate Prefix\n"
		"Option:2 Evaluate Postfix\n\n";
	cin>>key;
	// To ignore the rest of the current line, up to '\n'
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	getline(cin,expression);
	switch(key)
	{
		case 1:
			result = evaluatePrefix(expression);
			cout<<result;
			break;
		case 2:
			result = evaluatePostfix(expression);
			cout<<result;
			break;
		default:
			cout<<"Select a valid option\n";
			break;
	}
	cout<<"\n";
	return 0;
}