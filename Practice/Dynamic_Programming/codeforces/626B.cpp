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
#define RFOR(i,a,b) for(long long i = (a); i>= (b); i--)
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
int mark[202][202][202];
int  n;
string s;
int cr= 0, cb = 0, cg = 0;

/* user define functions specific to problem */

void dfs(ll r, ll g, ll b)
{
    if(mark[r][g][b]) return;
    mark[r][g][b] = 1;
    if(r >= 2) dfs(r-1,g,b);
    if(g >= 2) dfs(r,g-1,b);
    if(b >= 2) dfs(r,g,b-1);

    if(r>=1 && g>=1) dfs(r-1,g-1,b+1);
    if(r>=1 && b>=1) dfs(r-1,g+1,b-1);
    if(b>=1 && g>=1) dfs(r+1,g-1,b-1);
   }


/* solve here */
void solve()
{
   cin>>n>>s;
   rep(i,s.length()){
       if(s[i] == 'R') cr++;
       else if(s[i] == 'G') cg++;
       else if(s[i] == 'B') cb++;
   }
   dfs(cr,cg,cb);  
   if(mark[0][0][1]) cout<<'B';
   if(mark[0][1][0]) cout<<'G';
   if(mark[1][0][0]) cout<<'R';
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
