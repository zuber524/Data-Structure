//18/94087
//q8.adding numbers using stack

#include "STACK.cpp"
void add()
{
	string s1,s2;
	cout<<"1st number=";		cin>>s1; 
	cout<<"2nd number=";		cin>>s2;
	stack<int> res((s1.length()>s2.length()?s1.length():s2.length())+1);
	stack<int> a(s1.length());
	stack<int> b(s2.length());
	int i=0;
	while(s1[i])	a.push(s1[i++]-'0');
	i=0;
	while(s2[i])	b.push(s2[i++]-'0');
	int x,y,s,c=0;
	while(!a.isempty()||!b.isempty())
	{
		x=(a.isempty())?0:a.pop();
		y=(b.isempty())?0:b.pop();
		s=x+y+c;
		c=s/10;
		s%=10;
		res.push(s);
	}
	if(c!=0)	res.push(c);	
	cout<<s1<<"+"<<s2<<"==";
	while(!res.isempty())	cout<<res.pop();
	cout<<"\n";
}

int main()
{
	add();
	return 0;
} 
