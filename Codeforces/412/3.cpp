#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		double x,y,p,q;
		cin>>x>>y>>p>>q;
		double org_y = y;
		if(p == 0){
			if(x == 0)
				cout<<0<<endl;
			else
				cout<<-1<<endl;
		}
		else if(p==q) {
			if(x!= y)
				cout<<-1<<endl;
			else
				cout<<0<<endl;
	
		}
		else {
			long long countx = 0, county =0;
			int flag = 0;
			while(abs(x/y - p/q) > 0.000000000000001)
				if (x/y > p/q){
					y += 1;
					if(county > 0 && county > floor((p*y-x*q)/(q-p)))
					{
						flag = 1;
						break;

					}
					countx ++;
					county = 0;

				}
				else if(x/y < p/q) {
					if(countx >0 && countx <  ceil((x*q-p*y)/p)){
						flag = 1;
						break;
					}
					x++;
					y++;
					county ++;
					countx = 0;	
				
				}
			if(!flag)		
				cout << (int)(y - org_y)<<endl;
			else cout<<-1 <<endl;
		}
	}
	return 0;
}