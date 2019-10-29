//18/94087
//q10.singly linked list

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
class sll
{
	node <T>*head;
	public:
	void input()
	{
		node <T>*temp;		//temporary pointer to use
		node <T>*nn;		//<node for creating new node
		head=0;	//<pointer>initialising head to null	
		cout<<"\nLinked list ended with you=\n";
		T num;	cin>>num;		
		while(num!="you")
		{
			nn=new node<T> (num);
			if(!head)	head=temp=nn;
			else	temp=temp->link=nn;
			cin>>num;
		}
		temp=0;
		delete temp;
	}
		
	void show()
	{
		if(!head)	cout<<"\nEmpty linked list.";		
		else
		{
			node  <T>*temp=head;
			cout<<"\nThe linked list==\n";
			while(temp)
			{
				cout<<temp->info<<"\n";
				temp=temp->link;
			}
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
			head=nn;
			cout<<"\nDone.";
		}
		else
		{
			cout<<"\nInsert at=";
			cout<<"\n1.First\n2.Last\n3.Given position";
			cout<<"\nChoice=";
			int ch;	cin>>ch;
			switch(ch)
			{
				case 1:
				{		
					nn->link=head;
					head=nn;
					cout<<"\nDone.";
					break;
				}
				case 2:
				{
					node <T> *temp=head;		//temporary pointer
					while(temp->link)
					temp=temp->link;
					temp->link=nn;
					cout<<"\nDone.";
					temp=0;
					delete temp;
					break;
				}
				case 3:
				{
					cout<<"\nPosition=";
					int n;	cin>>n;
					if(n>0)
					{
						if(n==1)
						{
							nn->link=head;
							head=nn;
							cout<<"\nDone.";
						}
						else
						{
							node <T> *temp=head;
							int count=2;
							bool f;
							while(temp)
							{
								if(count==n)
								{
									node <T> *p=temp->link;
									temp->link=nn;
									nn->link=p;
									f=1;
									cout<<"\nDone.";
									p=0;
									delete p;
									break;	
								}
								else
								{
									f=0;
									temp=temp->link;
									count++;
								}
							}
							if(n+1>count&&!f)
							cout<<"\nInvalid position.";
							temp=0;
							delete temp;
						}	
					}
					else
					cout<<"\nInvalid position.";
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
		else if(!head->link)
		{
			head=0;
			cout<<"\nDone.";
		}
		else
		{
			cout<<"\nDelete at=";
			cout<<"\n1.First\n2.Last\n3.Given position\n4.Given node";
			cout<<"\nChoice=";
			int ch;	cin>>ch;
			node  <T>*temp=head;
			switch(ch)
			{
				case 1:
				{
					head=head->link;
					temp->link=0;
					cout<<"\nDone.";
					break;
				}
				case 2:
				{
					while(temp->link->link)	
					temp=temp->link;
					temp->link=0;
					cout<<"\nDone.";
					break;
				}
				case 3:
				{
					cout<<"\nPosition=";
					int n;	cin>>n;
					if(n>0)
					{
						if(n==1)
						{
							head=head->link;
							temp->link=0;
							cout<<"\nDone.";
						}
						else
						{
							int count=2;
							bool f;
							node  <T>*pre=temp;
							temp=temp->link;	
							while(temp)
							{
								if(n==count)
								{
									f=1;
									pre->link=temp->link;
									temp->link=0;
									cout<<"\nDone.";
									break;
								}
								else
								{
									f=0;
									count++;
									temp=temp->link;
									pre=pre->link;
								}
							}
							if(n+1>count&&!f)
							cout<<"\nInvalid position.";
						}
					}
					else
					cout<<"\nInvalid position.";
					break;
				}
				case 4:
				{
					cout<<"\nNode=";
					T t;	cin>>t;
					bool f;
					if(head->info==t)
					{
						head=head->link;
						temp->link=0;
						f=1;
					}
					else
					{
						node  <T>*pre=0;
						while(temp)
						{
							if(temp->info==t)
							{
								f=1;
								pre->link=temp->link;
								temp->link=0;
								break;
							}
							else
							{
								f=0;
								pre=temp;
								temp=temp->link;
							}
						}
						pre=0;
						delete pre;
					}
					if(f==1)		cout<<"\nDone.";
					else	cout<<"\nNode not found.";
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
			cout<<"\n1.Data\n2.Position";
			cout<<"\nChoice=";
			int ch;	cin>>ch;	
			node  <T>*temp=head;
			switch(ch)
			{
				case 1:
				{
					cout<<"\nData=";
					T num;	cin>>num;
					if(!head->link)
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
						while(temp->link)
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
					break;
				}		
				case 2:
				{
					cout<<"\nPosition=";
					int n;	cin>>n;
					if(n<=0)	cout<<"\nInvalid position.";
					else
					{
						if(!head->link)
						{
							if(n==1)
							{
								cout<<"\nData of node==";
								cout<<head->info<<"\n";
							}
							else
							cout<<"\nInvalid position.";
						}
						else
						{
							int count=1;	bool f;
							while(temp->link)
							{
								if(n==count)
								{
									f=1;
									break;
								}
								else
								{
									f=0;
									count++;
									temp=temp->link;
								}
							}
							if(f||(!temp->link&&n==count))
							{
								cout<<"\nData of node==";
								cout<<temp->info<<"\n";
							}
							else 
							cout<<"\nInvalid position.";
						}
					}
					temp=0;
					delete temp;
					break;
				}
				default:	cout<<"Invalid input.\n";
			}
		}
	}
		
	void reverse()
	{
		if(!head)	cout<<"\nEmpty linked list.";
		else	if(!head->link)
		cout<<"\nOnly one node in the linked list.";
		else
		{
			node  <T> *pre=0,*cur=head,*next;
			while(cur)
			{	
				next=cur->link;
				cur->link=pre;
				pre=cur;
				cur=next;
			}
			head=pre ;
			cout<<"\nDone.";
			pre=cur=next=0;
			delete pre,cur,next;	
		}
	}

	void concate(sll a)
	{
		if(!a.head)	cout<<"\nEmpty 2nd linked list.";
		else if(!head)
		{
			head=a.head;
			cout<<"\nDone.";
		}
		else
		{
			node <T>*temp=head;
			while(temp->link)	temp=temp->link;
			temp->link=a.head;
			cout<<"\nDone.";
			temp=0;
			delete temp;
		}
	}
	
	sll operator+(sll a)
	{
		sll res;
		res.head=0;
		node <T> *t1=head,*t2=a.head,*t3=res.head;
		node <T> *nn;
		while(t1)
		{
			nn=new node<T>(t1->info);
			t1=t1->link;
			if(!res.head)	t3=res.head=nn;
			else	t3=t3->link=nn;
		}
		while(t2)
		{
			nn=new node<T>(t2->info);
			t2=t2->link;
			if(!res.head)	t3=res.head=nn;
			else	t3=t3->link=nn;
		}
		cout<<"\nDone.";
		t1=t2=t3=0;
		delete t1,t2,t3;
		return res;
	}
	
	void menu()
	{
		input();
		char c;
		do
		{
			cout<<"\n1.Insert\n2.Delete\n3.Search\n4.Reverse";
			cout<<"\n5.Concatenate\n6.+operator overloading\n100.Display\n0.Exit";
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
					cout<<"\n2nd linked list--";
					sll a;	a.input();
					concate(a);
					break;
				case 6:
				{
					sll a,b,c;
					cout<<"\n1st linked list--";	a.input();
					cout<<"\n2nd linked list--";	b.input();
					c=a+b;
					cout<<"\n3rd linked list--";	c.show();
					break;
				}
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
	cout<<"\n\n*******SINGLY LINKED LIST*******\n\n";
	sll <string>x;		//reference variable of class sll
	x.menu();
	return 0;
}

