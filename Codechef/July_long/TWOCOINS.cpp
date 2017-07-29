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
int T;
const int maxn = 2e5;


/* user define functions specific to problem */

struct node {
    int v;
    bool flag;
};

/* solve here */
void solve()
{
  int n;
  cin>>n;
  if(n==1) {
      cout<<-1<<endl;
      return;
  }
  vector< unordered_set<int> > g(maxn);
  rep(i,n-1){
      int u,v;
      cin>>u>>v;
      g[u].insert(v);
      g[v].insert(u);
  } 
  queue<node> leaves; 
  for(int i=2 ; i<= n; i++){
      if(sz(g[i]) == 1){
          leaves.push({i,true});
      }   
  }
  vi coin(n+1,0);
  if(sz(g[1]) == 0) coin[1] = 1;
  else {
      int tcheck = 0;
      for(auto &v : g[1]){
          if(sz(g[v])){
               tcheck = 1;
               break;
          }
      }
      if(tcheck) coin[1] = 1;
  }
  bool last = false;
  while(sz(leaves) > 0){
      node fr = leaves.front();
      if(fr.flag) coin[fr.v] = 1;
      last = fr.flag;
      int par = *(g[fr.v].begin());
      g[par].erase(fr.v);
      if(sz(g[par])==1 && par != 1) leaves.push({par,!fr.flag });
      leaves.pop();
  }
  if(!last){
      coin[1] = 1;
  }
  ll cnt = 0;
  FOR(i,1,n) if(coin[i]==1) cnt++;
  cout<<cnt<<endl;
      

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
