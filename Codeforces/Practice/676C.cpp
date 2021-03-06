/*
  Template by Siddhartha Mishra(sid_m97)
*/

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((long long) (x).size())
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define FOR(i,a,b) for(long long i = (a); i <= (b); i++)
#define rrep(i, n) for (long long i = (n) - 1; i >= 0; i--)
#define fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll inf = 1e18; 
const double eps = 1e-9;
const double pi = acos(-1.0);
const ll  MOD =  1e9+7;

/* important functions */
ll mod(ll a,ll b=MOD)
{ return (a%b+b)%b; }


ll xdiv(ll a,ll b)
{
  if(a%b == 0) return a/b;
  else return a/b + 1;
}

ll gcd(ll a, ll b) {
  ll r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ll powmod(ll base, ll exp ,ll mod=MOD) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}

ll inv(ll a, ll m = MOD)
{
    return powmod(a, m-2,m);
}

void prnt(auto beg, auto end){
  for(auto it = beg; it != end; it++) cout<<*it<<" ";
  cout<<endl;
}

/* Declare variables here*/
ll T;
const ll MAXN = 2e6;
ll s[MAXN];
string z;
ll n,k;

/* user define functions specific to problem */
bool predicate(ll mid)
{
    bool flag = false;
    rep(i,n-mid+1){
        ll na = s[i+mid] - s[i];
        ll nb = mid - na;
        if(min(na,nb) <= k) flag = true;
    }
    return !flag;
}


/* solve here */
void solve()
{
    cin>>n>>k;
    cin>>z;
    ll lo = 1, hi = n+1;
    rep(i,n) if(z[i] == 'a') s[i+1] = s[i]+1; else s[i+1]=s[i];
    //prnt(s,s+n+1);
    while(lo < hi)
    {
        ll mid = lo + ((hi-lo)>>1);
        //cout<<"lo "<<lo<<"hi "<<hi<<"mid "<<mid<<endl;
        if(predicate(mid)) hi = mid;
        else lo = mid+1;
    }
    cout<<lo-1;

}

/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  //cin>>T;
  //while(T--)
  solve();
  
  return 0;
}
