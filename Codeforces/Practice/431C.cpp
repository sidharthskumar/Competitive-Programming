#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int MAXN = 100;

int dp[MAXN+1][2];

int main()
{
    int n,k,d;
    cin>>n>>k>>d;
    dp[0][0]=1;    
    for(int i=1; i<= n;i++)
    {

        for(int j=1; j <= k; j++)
        {
            if(j >i)break;

            if(j < d)
            {
                dp[i][0] = (dp[i][0] + dp[i-j][0])%MOD;
                dp[i][1] = (dp[i][1] + dp[i-j][1])%MOD;       
            }
            else
            {
                dp[i][1] = (dp[i][1] + dp[i-j][0])%MOD;
                dp[i][1] = (dp[i][1] + dp[i-j][1])%MOD; 
            }
        }
    }
    cout<<dp[n][1];

    return 0;
}
