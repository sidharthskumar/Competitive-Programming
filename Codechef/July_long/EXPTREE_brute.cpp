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
  ll r;
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
template <typename T> 
void prnt(T beg, T end){
  for(auto it = beg; it != end; it++) cout<<*it<<" ";
  cout<<endl;
}

/* Declare variables here*/
ll T;
const ll maxn = 1e6;

/* user define functions specific to problem */


bool inc(ll a, ll b,ll c){
    return  a < b && b < c;
}

bool dec(ll a, ll b , ll c){
    return a > b && b > c;
}


/* solve here */
void solve()
{
  ll n;
  cin>>n;
  vll g[n+1];
  int coin[n+1];
  FOR(i,1,n) coin[i] = 1;
  rep(i,n-1){
      ll u,v;
      cin>>u>>v;
      g[u].pb(v);
      g[v].pb(u);
  }
  ll ans = 0;
  FOR(i,1,n)
  {
      coin[i] = 0;
      int valid = 1;
      int fc = 0;
      for(auto & v: g[i]){
          if(coin[v] == 1) fc++;
      }
      cout<<"testing"<<i<<" first level "<<fc<<endl;
      if(fc < 2) valid = 0;
     
      for(auto & v : g[i]){
          int nc = 0;
          if(coin[v] == 0)
          {
              for(auto & next : g[v]){
                  if(coin[next] == 1) nc++;  
              }
              if(nc < 2) { 
                  valid = 0; 
                  break;
              }
          }
          else 
          {
              int check = 0;
              for(auto& cur : g[v]){
                  if(coin[cur] == 1) { check = 1; break; }
                  for(auto & next : g[cur]){
                        if(coin[next] == 1 && (inc(v,cur,next) || dec(v,cur,next))) { check = 1; break;}
                  }
                  if(check==1) break;
              }
              if(!check){
                 valid = 0;
                 break;
              }
          }
          cout<<"checking neighbour "<<v<<" count"<<nc<<endl;  
      }
       if(!valid) {
           cout<<"could not remove "<<i<<endl;
           coin[i] = 1;
           ans++;
        }
  }
  cout<<ans<<endl;
}

/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  cin>>T;
  while(T--)
  solve();
  
  return 0;
}
