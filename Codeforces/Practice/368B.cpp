#include <bits/stdc++.h>
#define fill(a,b) memset(a,b,sizeof(a)) 
using namespace std;

const int MAXN = 100000;

int a[MAXN];
int ss[MAXN+1];
int main()
{
    int n,m;
    cin>>n>>m;
    vector< pair<int,int> > ds(MAXN+1);
    for(int i=0;i<=MAXN;i++)
    {
        ds[i].second = 0;
        ds[i].first = -1;
    }
    for(int i=0;i < n;i++)cin>>a[i];
    
    for(int i=0;i < n;i++)
    {
        if(ds[a[i]].second == 0) ds[a[i]].second = 1;
        ds[a[i]].first=i;
    }
    sort(ds.begin(),ds.end());
    for(int i=1;i<=MAXN;i++) ss[i] = ss[i-1]+ ds[i].second;

    for(int i=0;i<m;i++)
    {
        int l;
        cin>>l;
        l--;
        int ind = lower_bound(ds.begin(),ds.end(),make_pair(l,INT_MIN))- ds.begin();
        cout<<ss[MAXN]-ss[ind-1]<<endl;
    }

    return 0;
}
