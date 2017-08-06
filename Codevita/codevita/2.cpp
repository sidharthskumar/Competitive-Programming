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
ll n,p;
const ll maxn = 120;

/* user define functions specific to problem */




/* solve here */
void solve()
{
   cin>>n>>p;
   ll h[maxn];
   ll checked[maxn];
   vll mv[maxn];
   ll mx = INT_MIN;
   rep(i,n) { cin>>h[i]; mv[h[i]].pb(i); mx = max(h[i],mx);}
   rep(i,maxn) checked[i] = 0;
   stack<ll> tc[maxn];
   rep(i,sz(mv[mx])){  tc[mx].push(mv[mx][i]); checked[mv[mx][i]] = 1; }
   for(ll curr = mx; curr >= 1 ; curr--){
       rep(j,sz(mv[curr])) {
           if(!checked[mv[curr][j]]) tc[curr].push(mv[curr][j]);
       } 
       while( !tc[curr].empty()){
            ll tp = tc[curr].top();
            tc[curr].pop();
            if(tp >= 1 && !checked[tp-1]) {
                if(h[tp-1] < h[tp] - 1){
                h[tp-1] = curr - 1;
                tc[curr-1].push(tp-1);
                checked[tp-1] = 1;

            }}
            if(tp < n - 1 && !checked[tp+1]){
                if(h[tp+1] < h[tp] - 1){
                h[tp+1] = curr - 1;
                tc[curr-1].push(tp+1);
                checked[tp+1] = 1;
            }

       }
   }}
   cout<<h[p-1]<<endl;

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
