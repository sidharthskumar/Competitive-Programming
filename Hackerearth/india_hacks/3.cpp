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
ll n;

/* user define functions specific to problem */
const ll maxn = 4e5;

ll M[maxn][20];
ll A[maxn];
ll ans[maxn];
void build(int N)
{
      ll i, j;
   
      for (i = 0; i < N; i++)
          M[i][0] = i;
      for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] > A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}  

ll query(int i, int j)
{
    ll k = floor(log2(j-i+1));
    ll ind = j-(ll) pow(2,k) + 1;
    if(A[M[i][k]] >= A[M[ind][k]]) return M[i][k];
    else return M[ind][k];
}

void split(ll l,ll r,ll s)
{
    if(l < 0 || l >= n || r < 0 || r >= n || l > r) return;
    ll mxind = query(l,r);
    if(mxind < 0) return;
    ans[s] += A[mxind];
    split(l,mxind-1,s+1);
    split(mxind+1,r,s+1);

}
/* solve here */
void solve()
{ 
    cin>>n;
    rep(i,0,n-1)cin>>A[i];
    build(n);
    split(0,n-1,1);
    ll ind = 1;
    while(ans[ind] > 0){
        cout<<ans[ind]<<endl;
        ind++;
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
