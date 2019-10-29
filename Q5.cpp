//18/94087
//q5.stack operation

#include "STACK.cpp"
template <class X>
void menu()
{	
	cout<<"\nSize=";
	int n;	cin>>n;
	stack <string>a(n);
	char ch='y';	int m;
	do
	{
		cout<<"\n1.Push\n2.Pop\n3.Clear\n100.Display\n0.Exit";
		cout<<"\nChoice=";	cin>>m;
		switch(m)
		{
			case 1:
			{
				if(a.isfull())	cout<<"\nFull stack.";
				else
				{
					X data;
					cout<<"\nObject=";	cin>>data;
					a.push(data);
					cout<<"\nPushed...["<<data<<"]";
				}
				break;
			}
				
			case 2:
			{
				if(a.isempty())	cout<<"\nEmpty stack.";
				else
				{	X data=a.pop();	cout<<"\nPopped...["<<data<<"]";	}
				break;
			}
				
			case 3:
			{
				a.clear();
				cout<<"\nCleared.";
				break;
			}	
				
			case 100:
			{
				if(a.isempty())	cout<<"\nEmpty stack.";
				else	
				{	
					cout<<"\nStack==\n";	
					for(int i=a.top;i>=0;i--)	cout<<"["<<a.arr[i]<<"]\n";	
				}
				break;
			}
			
			case 0:	exit(0);			
			default:	cout<<"\nInvalid input.";	
		}
		cout<<"\nContinue (y/n)=";	cin>>ch;
	}while(ch=='y'||ch=='Y');
}

int main()
{
	cout<<"\n\n*******STACK*******\n\n";
	menu<string>();
	return 0;
}
