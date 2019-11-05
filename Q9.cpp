//18/94087
//postfix using stack;

#include "STACK.cpp"

class pf
{
	public:
	double postfix(string s)
	{
		int i=0,n=s.length();
		stack <double>st(n);
		while(s[i]!='\0')
		{
			if(isdigit(s[i]))
			st.push(s[i++]-'0');	
			
			else if(isoperator(s[i]))
			{
				int a,b; double s1;
				if(!st.isempty())
				{
					b=st.pop();
					if(!st.isempty())	a=st.pop();
					else
					{
						cout<<"Invalid expression1.";
						return -999;
					}
				}
				else
				{
					cout<<"Invalid expression1.";
					return -999;
				}
				switch(s[i])
				{
					case '+':s1=a+b;	break;
					case '-':s1=a-b;	break;
					case '*':s1=a*b;	break;
					case '/':s1=a*1.0/b;	break;
				}
				st.push(s1);
				i++;
			}
			else
			{
				cout<<"Invalid expression2.";
				return -999;
			}
		}
		if(st.top==0)	 return st.pop();	
		else	cout<<"Invalid expression3.";
	}
	
	bool isdigit(char x)
	{
		int c=(int)x;
		if(c>47&&c<=57)	return true;
		else 	return false;
	}
	
	bool isoperator(char x)
	{	
		switch(x)
		{
			case '+':case '-':case '*':case '/':return true;
			default:return false;
		}
	}
};
int main()
{
	cout<<"Expression=";
	string s;cin>>s;
	pf a;
	cout<<"\nFinal value="<<a.postfix(s)<<"\n";
	return 0;
}
	
				
