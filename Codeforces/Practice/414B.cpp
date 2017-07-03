#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;
const int MOD = 1000000007;
int dp[MAXN+1][MAXN+1];
int main()
{
    int n,k;
    cin>>n>>k;
    int s = 0;
    for(int i = 1; i <= n;i++) dp[1][i] = 1;
    for(int i = 1 ; i < k; i++)
    {
        for(int j = 1;j <= n; j++)
        {
           for (int k = j; k <= n ;k += j)
           {
               dp[i+1][k] = (dp[i+1][k] + dp[i][j])%MOD;
           }
        }
    }
    
    for(int i=1 ; i<= n;i++) s = (s + dp[k][i])%MOD;

    cout<<s;
    return 0;
}
