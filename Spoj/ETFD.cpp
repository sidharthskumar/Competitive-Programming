#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vf vector<float>
#define vs vector<string>
#define vl vector<ll>

#define loop(i, a, b, x) for(ll i = a;i <b; i += x)
#define f(i,a,b) loop(i,a,b,1)
#define rep(i,n) f(i,0,n)
#define repv(i,a) rep(i,a.size()) 
#define loopr(i,a,b,x) for(ll i = a; i>=b;i--)
#define fr(i,a,b) loopr(i,a,b,1)
#define repr(i,n) fr(i,n-1,0)
#define repvr(i,a) repr(i,a.size())
#define mem(a,b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SORT(v) sort(v.begin(),v.end());
#define inc(A, B, C)  A <= B && B <= C

/* user define functions specific to problem */
vl sieveOfEratosthenes(int N)
{
    vector <bool> prime(N+1, false);
    vl s(N+1,0);
    for (ll i=2; i<=N; i+=2)
        s[i] = 2;
 
    for (ll i=3; i<=N; i+=2)
    {
        if (prime[i] == false)
        {
            s[i] = i;
            for (ll j=i; j*i<=N; j+=2)
            {
                if (prime[i*j] == false)
                {
                    prime[i*j] = true;
                    s[i*j] = i;
                }
            }
        }
    }
    return s;
}

/* solve here */
void solve()
{
  vl s = sieveOfEratosthenes(1000000);
  ll counter = 0;
  ll t;
  cin>>t;
  vl etf(1000001);
  vl depth(1000001);
  f(i,1,1000001){  
    ll num = i;
    ll curr = s[num];  
    ll cnt = 1;
    ll prod  = num;
    while (num > 1)
    {
        num /= s[num];
        if (curr == s[num])
        {
            cnt++;
            continue;
        }
        prod *= (curr-1);
        prod /= (curr);
        curr = s[num];
        cnt = 1;
    }
    etf[i] = prod;
   }
   f(i,1,1000001)
   {
     ll dp = 0;
     ll curr = i;
     while(curr != 1)
     {
       dp++;
       curr = etf[curr];
     }
     depth[i] = dp;
   }
   unordered_map<ll,vl> ref;
   f(i,1,1000001)
   {
     ref[depth[i]].push_back(i);
   }
   while(t--)
   {
      ll m,n,k;
      cin>>m>>n>>k;
      ll lind = lower_bound(all(ref[k]),m) - ref[k].begin();
      ll uind = upper_bound(all(ref[k]),n) - ref[k].begin();
      cout<< uind - lind<<endl;      
   }
      
}


/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 

  solve();

  return 0;
}