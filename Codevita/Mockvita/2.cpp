#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<long long,long long> &a, const pair<long,long> &b)
{
    return (abs(a.second) > abs(b.second));
}
int main()
{
    long long n,k;
    cin>>n>>k;
    vector< pair<long long,long long> > p(n); 
    for(int i=0;i <n;i++)cin>>p[i].first;   
    for(int i=0;i<n;i++)cin>>p[i].second;
    sort(p.begin(),p.end(),sortbysec);
    long long s = 0;

    if(p[0].second>0)
    {
        s += p[0].first*p[0].second - 2*k*p[0].second;
    }
    else
    {
        s += p[0].first*p[0].second + 2*k*p[0].second;
    }

    for(int i=1;i < n;i++)
    {
        s += p[i].first*p[i].second;
    }
       
    cout<<s;
    return 0;
}
