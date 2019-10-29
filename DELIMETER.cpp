//18/94087
//delimiter matching using stack

#include "STACK.cpp"
void display(char a[],int top)
{	for(int i=0;i<=top;i++)	cout<<a[i];	}
	
void check()
{
	string s;
	cout<<"\nStatement=";	getline(cin,s); 
	stack<char> a(s.length());
	int i=0;
	cout<<"\nSteps of checking and matching delimiter...\n";
	while(i!=a.n)
	{
		if(s[i]=='['||s[i]=='{'||s[i]=='(')
		{
			a.push(s[i]);
			display(a.arr,a.top);
			cout<<"\t.....pushing\n";
		}	
		else	if(s[i]==']'||s[i]=='}'||s[i]==')')
		{
			if((s[i]==']'&&a.arr[a.top]=='[')||(s[i]=='}'&&a.arr[a.top]=='{')||(a.arr[a.top]=='('&&s[i]==')'))
			{
				a.pop();
				display(a.arr,a.top);
				cout<<"\t.....popping\n";
			}
			else
			{
				cout<<"\nDelimiters mismatched.\n";	display(a.arr,a.top);
				cout<<s[i]<<"\n";
				exit(0);
			}
		}
		i++;
	}
	if(!a.isempty())
	{	cout<<"\nDelimiters  not closed.\n";	display(a.arr,a.top);	}
	else	cout<<"\nAll delimiters matched.\n";	
}

int main()
{
	check();
	return 0;
}   
