#include <iostream>
using namespace std;
template <class X>class stack
{
	public:
	X *arr; int n, top;
	stack(int size)	
	{
		if(size<=0)
		{	cout<<"\nInvalid size.";	exit(0);	}
		n=size;	arr=new X[n];	top=-1;
	}
	
	bool isempty(){	return (top==-1);	}
	bool isfull(){	return (top==n-1);	}	
	void push(X x){	arr[++top]=x;	}
	X pop(){	return arr[top--];}
	void clear(){	while(!isempty())	arr[top--];	}
};

