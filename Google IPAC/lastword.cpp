#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main()
{
	freopen("A-large-practice.in","r",stdin);
	freopen("outA.txt","w",stdout);
	int t;
	cin>>t;
	for(int t0=0;t0<t;t0++)
	{
		string x;
		string res;
		cin>>x;
		res.push_back(x[0]);
		char temp=x[0];
        for(int i=1;i <x.length();i++)
        {
            if(x[i] >=temp)
            {
                res=x[i]+res;
                temp=x[i];
            }

            else
                res.push_back(x[i]);
        }
        cout<<"Case #"<<t0+1<<": "<<res<<endl;
	}
	return 0;
}

