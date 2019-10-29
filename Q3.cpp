//18/94087
//q3.reverse string using recursion

#include<iostream>
using namespace std;

void rev(string s)
{
	int n=s.size();
	if(n==1)	cout<<s;
	else
	{
		cout<<s[n-1];
		rev(s.substr(0,n-1));
	}
}

int main()
{
	string s;
	cout<<"String=";	getline(cin,s);
	cout<<"Reverse string==";	rev(s);
	cout<<"\n";
	return 0;
}
