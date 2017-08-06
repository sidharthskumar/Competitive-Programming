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

/* Declare variables here*/
ll T;
const ll maxn=30;
ll mat[maxn][maxn];
ll n,m,l;
ll used[maxn][maxn];
int dirx[4] = { 0, 1, 0, -1 };
int diry[4] = {-1, 0 , 1 , 0};
/* user define functions specific to problem */
void dfs(ll i,ll j, ll &siz){
    used[i][j] = 1;
    siz += 1;
    rep(a,4) {
        if(i + dirx[a] >= 0 && i + dirx[a] < n && j + diry[a] >= 0 && j + diry[a] < m && !(used[i+dirx[a]][j + diry[a]]) && (mat[i+dirx[a]][j+diry[a]] == 1 )) {
            dfs(i+dirx[a],j+diry[a],siz);
        }
    }
}

/* solve here */
void solve()
{
     cin>>n>>m;
     cin>>l;
     rep(i,n) rep(j,m) cin>>mat[i][j];
     vll szes;
     rep(i,n){
         rep(j,m){
             if(!used[i][j] && mat[i][j] == 1) {
                 ll siz = 0;
                 dfs(i,j,siz);
                 szes.pb(siz);     
             }
         }
     }
     sort(all(szes));
     ll ind = sz(szes) - 1;
     ll cnt = 0;
     ll ans = 0;
     while(ind >= 0 )
     {
         cnt++;
         ans += szes[ind];
         if(cnt == l) break;
         ind--;
     }
     cout<<ans<<" "<<sz(szes)<<endl;

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
