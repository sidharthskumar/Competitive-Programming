#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    vector<int> val(n+1,INT_MIN);
    val[0] = 0;
    for(int i = 1 ;i <= n;i++)
    {
        if(i >= a  && 1 + val[i-a] > val[i])
        {
             val[i] = 1 + val[i-a];
        }
        if(i >= b && 1 + val[i-b] > val[i])
        {
             val[i] = 1 + val[i-b];
        }
        if(i >= c  && 1 + val[i-c] > val[i])
        {
             val[i] = 1 + val[i-c];
        }
    }
    cout<<val[n];
    return 0;
}
