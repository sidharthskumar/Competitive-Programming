#include <bits/stdc++.h>


using namespace std;

const int MAXN = 150000;
int h[MAXN];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i <n;i++)cin>>h[i];
    int sum = 0;
    int mn = 0;
    for(int i=0;i<k;i++) sum+=h[i];
    int ind = k;
    int temp = sum;
    while(ind < n)
    {   
       temp += (h[ind] - h[ind-k]);
       if(temp < sum)
        {
          sum = temp;
          mn = ind-k+1;
        }
     ind++; 
    }
    cout<<mn+1;


    return 0;
}
