//18/94087
//q13.polynomial using linked list

#include<iostream>
using namespace std;

template <class T>
struct node
{
	T coef,pow;	
	node *link;

	public:
	node(T coef=0, T pow=0,node *link=0)
	{
		this->coef=coef;
		this->pow=pow;
		this->link=link;
	}
};

template <class T>
class poly
{
	node <T>*head;
	public:
	void input()
	{
		head=0;
		node <T>*temp,*nn;

		cout<<"\nHighest power of polynomial=";
		T n,num;	cin>>n;	
		cout<<"\nCoefficient=\n";	
		while(n!=-1)
		{
			cout<<"x^"<<n<<"=";	cin>>num;
			nn=new node<T> (num,n);
			if(!head)	head=temp=nn;
			else	temp=temp->link=nn;
			n--;
		}
		temp=0;
		delete temp;
	}
	
	void show()
	{
		node<T> *t=head;	char c='+';
		while(t)
		{
			c=t->coef>0?'+':'\0';
			if(t->coef==0){}
			else 
			{	
				cout<<c<<t->coef;
				if(t->pow!=0)	cout<<"x^"<<t->pow;
			}
			t=t->link;
		}
		t=0;	delete t;
	}
	
	void add()
	{
		head=0;
		cout<<"\n1st polynomial...";
		poly<T> a;	a.input();
		cout<<"\n2nd polynomial...";
		poly<T> b;	b.input();
		node<T> *t1=a.head,*t2=b.head, *nn,*temp;
		while(t1)
		{
			if(t1->pow>t2->pow)
			{	nn=new node<T>(t1->coef,t1->pow);	t1=t1->link;	}
			else if(t1->pow<t2->pow)
			{	nn=new node<T>(t2->coef,t2->pow);		t2=t2->link;	}
			else
			{	
				nn=new node<T>(t1->coef+t2->coef,t1->pow);	
				t1=t1->link;	t2=t2->link;
			}
			if(!head)	head=temp=nn;
			else	temp=temp->link=nn;
		}
		cout<<"\n1st polynomial=";	a.show();
		cout<<"\n2nd polynomial=";	b.show();
		cout<<"\nSum of both polynomial=";	show();
	}
	
	
};

int main()
{
	cout<<"\n\n*******POLYNOMIAL USING LINKED LIST*******\n\n";
	poly <float>x;		//reference variable of class poly
	x.add();	cout<<"\n";
	return 0;
}

