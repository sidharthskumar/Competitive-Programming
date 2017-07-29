#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 5050;

ll a[MAXN];
ll dp[MAXN][MAXN];
ll s[MAXN];


int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=1; i <=n ;i++)
    {
        cin>>a[i];
        s[i] = s[i-1]+a[i];
    }
    
    for(int i=1; i<= n;i++)
    {
        for(int j =0; j <= k;j++)
        {
            dp[i][j] = -1e18;
        }
    }
    
    for(int i=1; i<= n; i++)
    {
        for(int j=0; j <= k; j++)
        {
            dp[i][j]=dp[i-1][j];

            if(j > 0 && i >= m) dp[i][j] = max(dp[i][j], dp[i-m][j-1] + s[i] - s[i-m]);
        }
    }
    cout<<dp[n][k];
    return 0;
}


