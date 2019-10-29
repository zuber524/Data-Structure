//18/94087
//q11.doubly linked list

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
class dll
{
	node <T>*head,*tail;
	public:
	void input()
	{
		node <T>*nn;		//<node for creating new node
		head=tail=0;	//<pointer>initialising head and tail to null	
		cout<<"\nLinked list ended with you=\n";
		T num;	cin>>num;		
		while(num!="you")
		{
			nn=new node <T>(num,tail);
			if(!head)	head=tail=nn;
			else	tail=tail->next=nn;
			cin>>num;
		}
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
	
	void insert()
	{	
		cout<<"\nNode=";
		T num;	cin>>num;
		node <T>*nn;
		if(!head)
		{
			nn=new node<T> (num);
			head=tail=nn;
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
					nn=new node <T>(num,0,head);
					head=nn;
					cout<<"\nDone.";
					break;
				}
				case 2:
				{
					nn=new node <T>(num,tail);
					tail=tail->next=nn;
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
							nn=new node <T>(num,0,head);
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
									nn=new node<T>(num,temp,temp->next);
									if(temp->next)
									temp->next->pre=nn;
									temp->next=nn;
									f=1;
									cout<<"\nDone.";
									break;	
								}
								else
								{
									f=0;
									temp=temp->next;
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
		else if(!head->next)
		{
			head=tail=0;
			cout<<"\nDone.";
		}
		else
		{
			cout<<"\nDelete at=";
			cout<<"\n1.First\n2.Last\n3.Given position\n4.Given node";
			cout<<"\nChoice=";
			int ch;	cin>>ch;
			switch(ch)
			{
				case 1:
				{
					head=head->next;
					head->pre=0;
					cout<<"\nDone.";
					break;
				}
				case 2:
				{
					tail=tail->pre;
					tail->next=0;
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
							head=head->next;
							head->pre=0;
							cout<<"\nDone.";
						}
						else
						{
							int count=2;
							bool f;
							node <T> *temp=head->next;
							while(temp)
							{
								if(n==count)
								{
									f=1;
									node <T>*p=temp->pre;
									p->next=temp->next;
									if(temp->next)
									temp->next->pre=p;
									else
									tail=temp->pre;
									temp->pre=temp->next=0;
									cout<<"\nDone.";
									p=0;	delete p;
									break;
								}
								else
								{
									f=0;
									count++;
									temp=temp->next;
								}
							}
							if(n+1>count&&!f)
							cout<<"\nInvalid position.";
							temp=0;	delete temp;
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
						head=head->next;
						head->pre=0;
						f=1;
					}
					else
					{
						node  <T>*temp=head->next;
						while(temp)
						{
							if(temp->info==t)
							{
								f=1;
								node <T>*p=temp->pre;
								p->next=temp->next;
								if(temp->next)
								temp->next->pre=p;
								temp->next=temp->pre=0;
								p=0;	delete p;
								break;
							}
							else
							{
								f=0;
								temp=temp->next;
							}
						}
						temp=0;	delete temp;
					}
					if(f==1)		cout<<"\nDone.";
					else	cout<<"\nNode not found.";
					break;
				}	
				default:
				cout<<"Invalid input.\n";
			}
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
					if(!head->next)
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
						while(temp->next)
						{
							if(temp->info==num)
							{
								f;
								break;	
							}
							else
							{
								temp=temp->next;
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
						if(!head->next)
						{
							if(n==1)
							{
								cout<<"\nThe data of node at provided position==";
								cout<<head->info<<"\n";
							}
							else
							cout<<"\nInvalid position.";
						}
						else
						{
							int count=1;	bool f;
							while(temp->next)
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
									temp=temp->next;
								}
							}
							if(f||(!temp->next&&n==count))
							{
								cout<<"\nThe data of node at provided position==";
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
		else	if(!head->next)
		cout<<"\nOnly one node in the linked list.";
		else
		{
			node<T> *t=tail->next;
			head=tail;
			while(tail)
			{
				tail->next=tail->pre;
				tail->pre=t;
				t=tail;
				tail=t->next;
			}
			tail=t;
			cout<<"\nDone.";
			t=0;	delete t;	
		}
	}

	void concate(dll a)
	{
		if(!a.head)	cout<<"\nEmpty 2nd linked list.";
		else if(!head)
		{
			head=a.head;
			tail=a.tail;
			cout<<"\nDone.";
		}
		else
		{
			tail->next=a.head;
			tail=a.tail;
			cout<<"\nDone.";
		}
	}
	
	dll operator+(dll a)
	{
		dll<T> res;
		res.head=0;	res.tail=0;
		node<T> *t1=head,*t2=a.head,*t3=res.head;
		node <T>*nn;
		while(t1)
		{
			nn=new node<T>(t1->info,res.tail);
			t1=t1->next;
			res.tail=nn;
			if(!res.head)	t3=res.head=nn;
			else	t3=t3->next=nn;
		}
		while(t2)
 		{
			nn=new node<T>(t2->info,res.tail);
			t2=t2->next;
			res.tail=nn;
			if(!res.head)	t3=res.head=nn;
			else	t3=t3->next=nn;
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
					dll a;	a.input();
					concate(a);
					break;
				case 6:
				{
					dll a,b,c;
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
	cout<<"\n\n*******DOUBLY LINKED LIST*******\n\n";
	dll <string>x;		//reference variable of class dll
	x.menu();
	return 0;
}

