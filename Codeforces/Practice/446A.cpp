#include <bits/stdc++.h>


using namespace std;

const int MAXN = 100000;
int a[MAXN];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    vector < pair<int,int> > dp;

    int ind = 0;
    while(ind < n)
    {
        int j = ind+1;
        while(j < n && a[j] > a[j-1])j++;
        dp.push_back(make_pair(ind,j-ind));
        ind = j;
    }

    int mx = 1;
    for(int i=0;i < dp.size()-1;i++)
    {
        int fl = dp[i].second;
        int fs = dp[i].first + fl - 1;
        int sf = dp[i+1].first;
        int sl = dp[i+1].second;
      //  cout<<"fs"<<fs<<"fl"<<fl<<"sf"<<sf<<"sl"<<sl<<endl;
        if(fl+1 >mx)mx =fl+1;
        if(sl +1 > mx) mx = sl+1;
        if(sl > 1 && a[sf+1] > a[fs]+1 && fl + sl > mx) mx = fl + sl;
        if(fl > 1 && a[fs-1] < a[sf] - 1 && fl + sl >mx) mx = fl + sl;
    }
    if(dp[dp.size()-1].second > mx) mx = dp[dp.size()-1].second;
    cout<<mx;
    return 0;
}
