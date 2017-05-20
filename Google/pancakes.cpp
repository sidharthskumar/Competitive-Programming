#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	freopen("B-small-practice.in","r",stdin);
	freopen("outP.txt","w",stdout);
	int t;
	cin>>t;
	for(int t0=0;t0<t;t0++)
	{

		string x;
		cin>>x;
		int flag=0,count=0;
		if(x[0]=='+')
			flag=1;
		for(int i=1;i<x.length();i++)
		{
			if(x[i]!=x[i-1])
			{
				if(flag)
					flag=0;
				else
					flag=1;
				count+=1;

			}
		}
		if(!flag)
			count+=1;
		cout<<"Case #"<<t0+1<<": "<<count<<endl;
	}
	return 0;
}
