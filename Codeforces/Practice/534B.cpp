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
ll v1, v2, t, d;
ll v[200][20][2];
/* user define functions specific to problem */




/* solve here */
void solve()
{
    cin>>v1>>v2;
    cin>>t>>d;
    t--;
    fill(v,INT_MIN);
    rep(k,2){
        rep(j,d){
            v[0][j][k] = v1;
        }
    }
    ll dist = v1;
    ll mxv = v1;
    FOR(i,1,t-1){
        ll lmx = INT_MIN;
        FOR(j,0,d){
            rep(k,2){
               int si = -1;
               if(k == 1) si *= -1; 
               v[i][j][k] = max(v[i][j][k],mxv + si*j);
               if(v[i][j][k] - (t-i)*d <= v2 && v[i][j][k] + (t-i)*d >= v2){
                   lmx = max(lmx,v[i][j][k]);     
               } 
            }   
        }
        mxv = lmx;
        dist += mxv;
    }
    dist += v2;    
    cout<<dist<<endl;
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
