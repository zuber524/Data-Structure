//18/94087
//q14.ordered linked list

#include<iostream>
using namespace std;

template <class T>
struct node
{
	T info;			//containing info of that particular node 
	node <T> *next,*pre;		//<pointer>containing address of next linked node

	public:
	node(T info=0,node *pre=0,node *next=0)
	{
		this->info=info;
		this->pre=pre;
		this->next=next;
	}
};

template <class T>
class oll
{
	node <T>*head,*tail;
	public:
	void input()
	{
		node <T>*nn;		//<node for creating new node
		head=tail=0;	//<pointer>initialising head and tail to null	
		cout<<"\n Ordered linked list ended with 999=\n";
		T num;	cin>>num;		
		while(num!=999)
		{
			nn=new node <T>(num,tail);
			if(!head)	head=tail=nn;
			else	tail=tail->next=nn;
			cin>>num;
		}
		if(!check())	
		{	cout<<"\nUnordered linked list.\nInput again."; return input();	}
	}
	
	bool check()
	{
		node<T> *t=head->next;
		while(t)
		{
			if(t->info>=t->pre->info) t=t->next;
			else return false;
		}
		return true;
	}
	
	void show()
	{
		if(!head)	cout<<"\nEmpty linked list.";		
		else
		{
			node <T> *temp=head;
			cout<<"\nThe linked list==\n";
			while(temp)
			{
				cout<<temp->info<<"\n";
				temp=temp->next;
			}
			temp=0;
			delete temp;
		}
	}
	
	void insert(T num)
	{	
		node <T>*nn=new node<T> (num);
		if(!head)
		{		head=tail=nn;	}
		else if(head->info>=nn->info)
		{	head->pre=nn;	nn->next=head;	head=nn;	}
		else if(tail->info<=nn->info)
		{	tail->next=nn;	nn->pre=tail;	tail=nn;	}
		else
		{
			node<T> *t=head;
			while(t)
			{
				if(t->info>nn->info)
				{
					nn->next=t;	nn->pre=t->pre;
					nn->pre->next=nn;	t->pre=nn;	
					break;
				}
				else t=t->next;
			}
			t=0;	delete t;
		}
	}

	void del()
	{	
		cout<<"\nNode=";
		T num;	cin>>num;
		node<T> *t;	bool f=1;
		if(!head)	cout<<"\nEmpty linked list.";
		else if(head->info==num)
		{	t=head;	head=head->next;	delete t;	}
		else if(tail->info==num)
		{	t=tail;	tail=tail->pre;		delete t;	}
		else
		{
			t=head;
			while(t)
			{
				if(t->info==num)
				{
					f;	t->pre->next=t->next;
					t->next->pre=t->pre;
					delete t;	break;
				}
				else {	!f;	t=t->next;	}
			}		
		}
		if(!f)	cout<<"\nNode not found.";
		else	cout<<"\nDeleted.";
	}
	
	void merge()
	{
		cout<<"\n2nd list...";
		oll<T> x;	x.input();
		node<T> *t1=head, *t2=x.head;
		while(t2)
		{
			insert(t2->info);
			t2=t2->next;
		}
		cout<<"\nMerged in primary list.";
	}
		
	void menu()
	{
		input();
		char c;
		do
		{
			cout<<"\n1.Insert\n2.Delete\n3.Merge\n100.Display\n0.Exit";
			cout<<"\nChoice=";
			int  ch;	cin>>ch;
			switch(ch)
			{
				case 1:
					cout<<"\nNode=";
					T num;	cin>>num;
					insert(num);
					cout<<"\nInserted.";
					break;
				case 2:
					del();
					break;
				case 3:
					merge();
					break;
				case 100:
					show();
					break;
				case 0:	exit(0);
				default:	cout<<"\nInvalid input.";			
			}
			cout<<"\nContinue (y/n)=";	cin>>c;
		}while(c=='y'||c=='Y');
	}
};

int main()
{
	cout<<"\n\n*******ORDERED LINKED LIST*******\n\n";
	oll <float>x;		//reference variable of class oll
	x.menu();
	return 0;
}

