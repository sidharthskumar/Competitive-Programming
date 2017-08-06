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
#define rep(i,a,b) for(long long i = (a); i <= (b); i++)
#define rrep(i,a,b) for (long long i = (a) - 1; i >= b; i--)
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
ll q;
const ll maxn = 111;
ll dp[maxn][maxn];
ll mark[maxn][maxn][maxn];
int g[maxn][maxn];
/* user define functions specific to problem */




/* solve here */
void solve()
{
     cin>>n>>m;
     rep(i,1,m){
        ll a,b,c;
        cin>>a>>b>>c;
        g[a][b] = 1;
        mark[a][b][c] = 1;
        dp[a][b]++;
     } 
     rep(k,1,n){
        rep(i,1,n){ 
            rep(j,1,n) {
                if(i == j || j==k || k == i) continue;
                 ll inci = min(i,j), incj = max(i,j);

                rep(c,1,m){
                    if(i <= k && k <= j){
                        if(mark[i][k][c] && mark[k][j][c] && !mark[inci][incj][c]){
                            mark[inci][incj][c] = 1;
                            dp[inci][incj]++;
                        }
                    }
                    else if(i > k && k <= j){
                         if(mark[k][i][c] && mark[k][j][c] && !mark[inci][incj][c]){
                            mark[inci][incj][c] = 1;
                            dp[inci][incj]++;
                        }
                    }
                    else if(i <= k && k > j){
                         if(mark[i][k][c] && mark[j][k][c] && !mark[inci][incj][c]){
                            mark[inci][incj][c] = 1;
                            dp[inci][incj]++;
                        }
                    }
                    else {
                         if(mark[k][i][c] && mark[j][k][c] && !mark[inci][incj][c]){
                            mark[inci][incj][c] = 1;
                            dp[inci][incj]++;
                        }
                    }
                }
             }
        }
     }
    cin>>q;
    while(q--){
        ll u,v;
        cin>>u>>v;
        if(u > v) swap(u,v);
        cout<<dp[u][v]<<endl;
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
