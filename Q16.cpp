//18/94087
//q16.array sorting searching

#include<iostream>
using namespace std;
template <class T>
class arr
{
	T *a,n;
	public :
	void input()
	{
		cout<<"\nSize of list=";	cin>>n;
		a=new T[n];
		cout<<"\nElements of list=\n";
		for(int i=0;i<n;i++)	cin>>a[i];
	}
	
	void show()
	{		
		cout<<"\nList=[";
		for(int i=0;i<n;i++)	cout<<a[i]<<",";
		cout<<"\b]";	
	}
	
	void swap(T *x,T *y)
	{	T temp=*x;*x=*y;*y=temp;	}
	
	void menu()
	{
		char c='r';
		do
		{
			if(c=='r')	input();
			cout<<"\n\nSORT...\n1.Bubble\n2.Insertion\n3.Selection\n4.Merge\n5.Quick";
			cout<<"\n\nSEARCH...\n6.Linear\n7.Binary\n100.Display\n0.Exit";
			cout<<"\nChoice=";
			int  ch;	cin>>ch;
			switch(ch)
			{
				case 1:bbl();	break;
				case 2:ist();	break;
				case 3:slc();	break;
				case 4:mrg(0,n);		cout<<"\nSorted.";
				break;
				case 5:qck(0,n);		cout<<"\nSorted.";
				break;
				case 6:lnr();	break;
				case 7:bnr();	break;
				case 100:show();	break;
				case 0:exit(0);
				default:cout<<"\nInvalid input.";
			}
			cout<<"\nContinue/Re-enter(y/r/...)=";
			cin>>c;
		}while(c=='y'||c=='r');
	}
	
	void bbl()
	{
		cout<<"\nNumber of comparison after each pass=\n";
		for(int i=1;i<n;i++)
		{
			int count=0;
			for(int j=0;j<n-i;j++)
			{
			 	if(a[j]>a[j+1])
			 	{	swap(&a[j],&a[j+1]);	}	
				count++;  
			}
			cout<<"["<<i<<"]="<<count<<"\t";
		}
		cout<<"\nSorted.";
	}
	
	void ist()
	{
		cout<<"\nNumber of comparison after each pass=\n";
		for(int i=1;i<n;i++)
		{
			int count=0;
			for(int j=i-1;j>=0;j--)
			{	
				count++;
			    if(a[j]>a[j+1])
			    {	swap(&a[j],&a[j+1]);	}
	    		else break;
			}
			cout<<"["<<i<<"]="<<count<<"\t";
		}
		cout<<"\nSorted.";
	}
	
	void slc()
	{
		cout<<"\nNumber of comparison after each pass=\n";
		for(int i=0;i<n-1;i++)
		{
			int count=0,min=a[i],loc=i;	
			for(int j=i+1;j<n;j++)
			{	
				count++;
				if(min>a[j])
				{	min=a[j];	loc=j;	}
			}
			swap(&a[i],&a[loc]);
			cout<<"["<<i+1<<"]="<<count<<"\t";
		}
		cout<<"\nSorted.";
	}
	
	int partition(int beg,int end)
	{
		int p=beg,pivot=a[beg];
		for(int loc=beg+1;loc<=end;loc++)
		{
			if(pivot>a[loc])
			{
				a[p]=a[loc];
				a[loc]=a[p+1];
				a[p+1]=pivot;
				p=p+1;
			}
		}
		return p;
	}
	
	void qck(int beg,int end)
	{
		if(beg<end)
		{
			int p=partition(beg,end);
			qck(beg,p-1);
			qck(p+1,end);
		}
	}
	
	int merge(int beg,int end,int mid)
	{
		int i=beg,j=mid+1,k=beg,c[50];
		while(i<=mid&&j<=end)
		{
			if(a[i]<a[j])
			{
				c[k]=a[i];
				k++;	i++;
			}
			else
			{
				c[k]=a[j];
				k++;	j++;
			}
		}
		while(i<=mid)
		{
			c[k]=a[i];
			k++;	i++;
		}
		while(j<=end)
		{
			c[k]=a[j];
			k++;	j++;
		}
		for(i=beg;i<k;i++)
		a[i]=c[i];
	}
	
	void mrg(int beg,int end)
	{
		int mid;
		if(beg<end)
		{
			mid=(beg+end)/2;
			mrg(beg,mid);
			mrg(mid+1,end);
			merge(beg,end,mid);
		}
	}
	
					
	void lnr()
	{
		cout<<"\nSearch=";
		T s;	cin>>s;
		bool flag=1; int count=0;
		for(int i=0;i<n;i++)
		{
			count++;
			if(a[i]==s)
			{	flag=1;		cout<<"\nPosition=["<<i+1<<"]";		break;	}
			else	flag=0;
		}
		if(!flag)
		cout<<"\nNot found."<<endl;
		else			cout<<"\nTotal number of comparison\n"<<count;	
	}
	
	void bnr()
	{
		cout<<"\nSearch=";
		T s;	cin>>s;
		bool flag=0;int f=0,l=n,mid,count=0;
		while(flag!=1)
		{
			count++;
			mid=(f+l)/2;
			if(a[mid]==s)
			{
				flag=1;
				cout<<"\nPosition=["<<mid+1<<"]";
				break;
			}
			else if(a[mid]>s)
			{	l=mid;	}
			else	f=mid;
			flag=0;
		}
		if(!flag)
		cout<<"\nNot found."<<endl;	
		else			cout<<"\nTotal number of comparison\n"<<count;	
				
	}
};

int main()
{
	arr<int> a;
	a.menu();
	return 0;
}
