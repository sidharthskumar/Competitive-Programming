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
ll n,m;
ll used[50];
ll cnt[4];
/* user define functions specific to problem */
void dfs(vvi g,int v, vi & a)
{
    used[v]=1;
    a.pb(v);
    for(auto vert: g[v]){
        if(!used[vert]){
            dfs(g,vert,a);
        }
    }
}



/* solve here */
void solve()
{
     cin>>n>>m;
     vvi g(n+1);
     rep(i,m){
         int u,v;
         cin>>u>>v;
         g[u].pb(v);
         g[v].pb(u);
     }
     int flag = 0;
     vvi ans;
     FOR(i,1,n){        
         if(!used[i]){
            vi a;
            dfs(g,i,a);
            if(sz(a) > 3){
                flag = 1;
                break;
            }
            else { 
                ans.pb(a);
                cnt[sz(a)]++;
            }    
         }
     }
     if(flag || cnt[2] > cnt[1]) {
         cout<<-1;
         return;
     }
     sort(all(ans),[](const vi& a, const vi &b){ return sz(a) < sz(b); });
     int i = 0;
     int j = 0;
     int k = 0;
     while(i < sz(ans) && sz(ans[i]) != 1)i++;
     while(j < sz(ans) && sz(ans[j]) != 2) j++;
     while(k < sz(ans) && sz(ans[k]) != 3) k++;
     FOR(p,k,sz(ans)-1){
        rep(q,3) cout<<ans[p][q]<<" ";
            cout<<endl;
     }
     FOR(p,j,k-1){
         cout<<ans[p][0]<<" "<<ans[p][1]<<" "<<ans[i][0]<<endl;
         i++;
     }
     while(i < j){
         cout<<ans[i][0]<<" "<<ans[i+1][0]<<" "<<ans[i+2][0]<<endl;
         i += 3;
     }      


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
