//18/94087
//q7.queue using linked list

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
class que
{
	node <T>*front,*rear;
	public:
		
	void show()
	{
		if(!front)	cout<<"\nEmpty queue.";		
		else
		{
			node  <T>*temp=front;
			cout<<"\nQueue==";
			while(temp)
			{
				cout<<"["<<temp->info<<"]";
				temp=temp->link;
			}
			delete temp;
		}
	}
	
	void enque()
	{	
		cout<<"\nData=";
		T num;	cin>>num;
		node <T>*nn=new node <T>(num);
		rear=(!front?front:rear->link)=nn;
		cout<<"\nEnqueued...["<<rear->info<<"]";
	}

	void deque()
	{
		if(!front)	cout<<"\nEmpty queue.";	
		else
		{
			node <T>*temp=front;
			front=front->link;
			cout<<"\nDequeued..["<<temp->info<<"]";
			delete temp;
		}
	}
	
	void clear()
	{
		while(front)
		{
			node <T>*temp=front;
			front=front->link;
			delete temp;
		}
		cout<<"\nCleared.";
	}
	
	void menu()
	{
		front=rear=0;
		char c;
		do
		{
			cout<<"\n1.Enqueue\n2.Dequeue\n3.Clear\n100.Display\n0.Exit";
			cout<<"\nChoice=";
			int  ch;	cin>>ch;
			switch(ch)
			{
				case 1:enque();	break;				
				case 2:deque();	break;
				case 3:clear();	break;
				case 100:show();break;
				case 0:	exit(0);
				default:	cout<<"\nInvalid input.";			
			}
			cout<<"\nContinue (y/n)=";	cin>>c;
		}while(c=='y'||c=='Y');
	}
};

int main()
{
	cout<<"\n\n*******QUEUE USING LINKED LIST*******\n\n";
	que <string>x;
	x.menu();
	return 0;
}

