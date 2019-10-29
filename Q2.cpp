//18/94087
//q2.compute b^r using recursion

#include<iostream>
using namespace std;

float comp(int b,int r)
{
	if(r==0) return 1;
	else if (r<0) return (1.0/b)*comp(b,r+1);
	else	return b*comp(b,r-1);
}

int main()
{
	int b,r;
	cout<<"\n\n***b^r***\n\n";
	cout<<"b=";	cin>>b;
	cout<<"r=";	cin>>r;
	cout<<b<<"^"<<r<<"=="<<comp(b,r)<<"\n";
	return 0;
}
