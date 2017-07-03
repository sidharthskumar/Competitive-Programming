#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll MAXN = 100000ll;
const ll MOD = 1000000007ll;

ll w[MAXN+1];
ll r[MAXN+1];
ll s[MAXN+1];

int main()
{
    ll n,k;
    cin>>n>>k;
    w[0] = 1;
    r[1] = 1;
    if(k==1) w[1]=1;
    for(int i=2;i <= MAXN;i++)
    {
        r[i] = (r[i-1]+w[i-1])%MOD;
        w[i] = (i >= k) ?  (w[i-k] + r[i-k])%MOD: 0;
    }
    for(int i=1;i <= MAXN;i++) s[i] = (s[i-1]+(r[i]+w[i])%MOD)%MOD;
    for(int i=0;i <n;i++)
    {
        ll a,b;
        cin>>a>>b;
        cout<<((s[b]-s[a-1])%MOD+MOD)%MOD<<endl;
    }
    return 0;
}
