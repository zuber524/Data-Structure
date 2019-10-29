//18/94087
//q12.circular singly linked list

#include<iostream>
using namespace std;

template <class T>
struct node
{
	T info;			//containing info of that particular node 
	node *link;		//<pointer>containing address of next linked node

	public:
	node(T info=0,node *link=0)
	{
		this->info=info;
		this->link=link;
	}
};

template <class T>
class csll
{
	node <T>*head,*tail;
	public:
	void input()
	{
		node <T>*nn;		//<node for creating new node
		head=tail=0;	//<pointer>initialising head to null	
		cout<<"\nLinked list ended with you=\n";
		T num;	cin>>num;		
		while(num!="you")
		{
			nn=new node<T> (num,head);
			if(!head)	head=tail=nn;
			else	tail=tail->link=nn;
			cin>>num;
		}
	}
		
	void show()
	{
		if(!head)	cout<<"\nEmpty linked list.";		
		else
		{
			node  <T>*temp=head;
			cout<<"\nThe linked list==\n";
			while(temp->link!=head)
			{
				cout<<temp->info<<"\n";
				temp=temp->link;
			}
			cout<<temp->info<<"\n";
			temp=0;
			delete temp;
		}
	}
	
	void insert()
	{	
		cout<<"\nNode=";
		T num;	cin>>num;
		node <T>*nn=new node <T>(num);
		if(!head)
		{
			head=tail=nn;
			cout<<"\nDone.";
		}
		else
		{
			cout<<"\nInsert at=";
			cout<<"\n1.First\n2.Last";
			cout<<"\nChoice=";
			int ch;	cin>>ch;
			switch(ch)
			{
				case 1:
				{		
					nn->link=head;
					head=nn;
					tail->link=head;
					cout<<"\nDone.";
					break;
				}
				case 2:
				{
					tail=tail->link=nn;
					tail->link=head;
					cout<<"\nDone.";
					break;
				}		
				default:		cout<<"\nInvalid input.";
			}
		}
	}

	void del()
	{
		if(!head)
		cout<<"\nEmpty linked list.";
		else if(head->link==head)
		{
			head=tail=0;
			cout<<"\nDone.";
		}
		else
		{
			cout<<"\nDelete at=";
			cout<<"\n1.First\n2.Last";
			cout<<"\nChoice=";
			int ch;	cin>>ch;
			node  <T>*temp=head;
			switch(ch)
			{
				case 1:
				{
					head=head->link;
					temp->link=0;
					tail->link=head;
					cout<<"\nDone.";
					break;
				}
				case 2:
				{
					while(temp->link!=tail)	
					temp=temp->link;
					tail=temp;
					tail->link=head;
					cout<<"\nDone.";
					break;
				}	
				default:
				cout<<"Invalid input.\n";
			}
			temp=0;
			delete temp;
		}
	}
			
	void search()
	{
		if(!head)	cout<<"\nEmpty linked list.";
		else
		{
			cout<<"\nSearch a node =";
			node  <T>*temp=head;
			cout<<"\nData=";
			T num;	cin>>num;
			if(head->link==head)
			{
				if(head->info==num)
				cout<<"\nNode is at 1st position.";
				else
				cout<<"\nNode not found.";
			}
			else
			{
				bool f;
				int count=1;
				while(temp->link!=head)
				{
					if(temp->info==num)
					{
						f;
						break;	
					}
					else
					{
						temp=temp->link;
						!f;
						count++;
					}
				}
				if(f||temp->info==num)
				cout<<"\nNode is at "<<count<<" position.";
				else
				cout<<"\nNode not found.";	
			}
			temp=0;
			delete temp;
		}
	}
		
	void reverse()
	{
		if(!head)	cout<<"\nEmpty linked list.";
		else	if(head->link==head)
		cout<<"\nOnly one node in the linked list.";
		else
		{
			node  <T> *pre=0,*cur=head,*next;
			tail->link=0;
			tail=head;
			while(cur)
			{	
				next=cur->link;
				cur->link=pre;
				pre=cur;
				cur=next;
			}
			head=pre ;
			tail->link=head;
			cout<<"\nDone.";
			pre=cur=next=0;
			delete pre,cur,next;	
		}
	}
	
	void alt()
	{
		if(!head)	cout<<"\nEmpty linked list.";
		else
		{
			node <T>*temp=head;
			tail->link=0;
			while(temp)
			{
				cout<<temp->info<<"\n";
				if(!temp->link)
				temp=temp->link;
				else temp=temp->link->link;
			}
			tail->link=head;
		}
	}

	void menu()
	{
		input();
		char c;
		do
		{
			cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Reverse";
			cout<<"\n5.Alternate element skip\n100.Display\n0.Exit";
			cout<<"\nChoice=";
			int  ch;	cin>>ch;
			switch(ch)
			{
				case 1:
					insert();
					break;
				case 2:
					del();
					break;
				case 3:
					search();
					break;		
				case 4:
					reverse();
					break;
				case 5:
					alt();
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
	cout<<"\n\n*******CIRCULAR SINGLY LINKED LIST*******\n\n";
	csll <string>x;
	x.menu();
	return 0;
}

