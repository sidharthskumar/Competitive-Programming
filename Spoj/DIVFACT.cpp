#include <bits/stdc++.h>
using namespace std;


#define mp make_pair
#define pb push_back
#define ff first
#define ss second

#define ll long long
#define vi vector<int>
#define vf vector<float>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>

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
vl simpleSieve(int limit)
{
  bool mark[limit];
  memset(mark, true, sizeof(mark));
  vl result;
  // One by one traverse all numbers so that their
  // multiples can be marked as composite.
  for (ll p=2; p*p<limit; p++)
  {
      // If p is not changed, then it is a prime
      if (mark[p] == true)
      {
          // Update all multiples of p
          for (ll i=p*2; i<limit; i+=p)
              mark[i] = false;
      }
  }

  for (ll p=2; p<limit; p++)
      if (mark[p] == true)
          result.pb(p);

  return result;
}

template <typename T>
T mod(T a, T b)
{ return (a%b+b)%b; }

ll T;
    
/* solve here */
void solve()
{
  cin>>T;
  ll md = 1000000007;
  vl sieve = simpleSieve(50001);
  while(T--)
  {
    ll n;
    cin>>n;
    ll ans = 1;
    ll ind = upper_bound(all(sieve),n)-sieve.begin();
    rep(i,ind)
    {
      ll cnt = 0;
      ll p = sieve[i];
      ll curr = floor(n/p);
      while(curr != 0)
      {
        cnt+=curr;
        p *= sieve[i];
        curr = floor(n/p);  
      }
      ans = mod(ans*mod(cnt + 1,md),md);
    }

    cout<<ans<<endl;
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