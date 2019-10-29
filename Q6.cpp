//18/94087
//q6.queue operation

#include <iostream>
using namespace std;

template <class X>class queue
{
	public:
	X *arr; int size,in,out;
	queue(int size)	
	{
		if(size<=0)
		{
			cout<<"\nInvalid size.";
			exit(0);
		}
		this->size=size+1;
		arr=new X[this->size];
		in=out=0;
	}
	bool isfull(){	return (in+1)%size==out;	}
	bool isempty()	{	return in==out;	}
	void enque(X x){	arr[in]=x;	in=(in+1)%size;	}
	X deque(){		X x=arr[out];	out=(out+1)%size;	return x;	}
	void clear(){	while(!isempty())	deque();	}

	void menu()
	{	
		char ch;	int m;
		do
		{
			cout<<"\n1.Enqueue\n2.Dequeue\n3.Clear\n100.Display\n0.Exit";
			cout<<"\nChoice=";	cin>>m;
			switch(m)
			{
				case 1:
					if(isfull())	cout<<"\nFull queue.";
					else 
					{	
						X data;	cout<<"\nObject=";	cin>>data;	enque(data);	
						cout<<"\nEnqueued...["<<data<<"]";	
					}
					break;	
				
				case 2:
					if(isempty())	cout<<"\nEmpty queue.";
					else 
					{	X  data=deque();	cout<<"\nDequeued...["<<data<<"]";	}	
					break;
				
				case 3:clear(); 	cout<<"\nCleared.";	break;
				
				case 100:
					if(isempty())	cout<<"\nEmpty queue.";
					else	
					{	
						cout<<"\nQueue==";
						for(int i=out;i!=in;i=(i+1)%size)	cout<<"["<<arr[i]<<"]";
					}
					break;
					
				case 0:	exit(0);			
				default:	cout<<"\nInvalid input.";	
			}
			cout<<"\nContinue (y/n)=";	cin>>ch;
		}while(ch=='y'||ch=='Y');
	}
};	
	
int main()
{
	cout<<"\n\n*******QUEUE*******\n\n";
	cout<<"\nSize=";	int n;	cin>>n;
	queue <string> a(n);
	a.menu();
	return 0;
}
