//18/94087
//q4.stack operations using linked list

#include<iostream>
using namespace std;
template <class X>
struct node
{
	X info;
	node *pre,*next;
	node(X info=0,node *pre=0,node *next=0)
	{
		this->info=info;
		this->pre=pre;
		this->next=next;
	}
};
template <class X>
class stack
{
	node <X>*top;
	public:
	void push()
	{
		cout<<"\nObject=";
		X s;	cin>>s;
		node <X>*nn=new node<X>(s,top);
		top=(!top?top:top->next)=nn;
		cout<<"\nPushed...["<<s<<"]";
	}
	
	void pop()
	{
		if(!top)	cout<<"\nEmpty stack.";
		else
		{
			node <X>*temp=top;
			top=top->pre;
			cout<<"\nPopped...["<<temp->info<<"]";
			delete temp;
		}
	}
	
	void clear()
	{
		node <X>*temp;
		while(top)
		{
			temp=top;
			top=top->pre;
			delete temp;
		}
		cout<<"\nCleared.";
	}
	
	void show()
	{
		if(!top)	cout<<"\nEmpty stack.";
		else
		{
			cout<<"\nStack==\n";
			node <X>*temp=top;
			while(temp) 
			{
				cout<<"["<<temp->info<<"]\n";
				temp=temp->pre;
			}
			delete temp;
		}
	}					

	void menu()
	{
		top=0;
		int ch;	char c;
		do
		{
			cout<<"\n1.Push\n2.Pop\n3.Clear\n100.Display\n0.Exit";
			cout<<"\nChoice=";	cin>>ch;
			switch(ch)
			{
				case 1:push();	break;
				case 2:pop();	break;
				case 3:clear();	break;
				case 100:show();	break;
				case 0:	exit(0);
				default:	cout<<"\nInvalid input.";
			}
			cout<<"\nContinue (y/n)=";	cin>>c;
		}while(c=='y'||c=='Y');
	}
};

int main()
{
	cout<<"\n\n*******STACK IN FORM OF LINKED LIST*******\n\n";
	stack<string> x;
	x.menu();
	return 0;
}
