#include <bits/stdc++.h>

using namespace std;

int main()
{   
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> dp1(n) , dp2(n);
    
    for(int i = 0;i <n ;i++)
    {
        cin>>a[i];
        dp1[i]=i;
        dp2[i]=i;
    }
    int ind = 0;
    while(ind < n)
    {
        int jind = ind+1;
        while(jind < n && a[jind] >= a[jind-1])jind++;
        for(int j = ind; j < jind;j++)
        {
            dp1[j] = jind-1;
        }
        ind = jind;
    }
    ind = 0;
    while(ind < n)
    {
        int jind = ind+1;
        while(jind < n && a[jind] <= a[jind-1])jind++;
        for(int j = ind; j < jind;j++)
        {
            dp2[j] = jind-1;
        }
        ind = jind;
    }

    for(int i = 0;i < m;i++)
    {
        int l,r;
        cin>>l>>r;
        l--;r--;
        if(dp1[l] >= r || (dp1[l] < r && dp2[dp1[l]] >= r) )
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }


    return 0;
}
