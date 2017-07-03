/*
  Template by Siddhartha Mishra(sid_m97)
*/

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;


const int inf = INT_MAX; 
const double eps = 1e-9;
const double pi = acos(-1.0);
const int  MOD =  1000000007;

/* important functions */
template <typename T>
T mod(T a, T b)
{ return (a%b+b)%b; }

template <typename T>
T xdiv(T a, T b)
{
  if(a%b == 0) return a/b;
  else return a/b + 1;
}

template <typename T>
T gcd(T a, T b) {
  T r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

template <typename T>
T fast_exp(T base, T exp ,T mod=MOD) {
    T res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}
template <typename T>
void prvec(T a){
  rep(i,a.size()) cout<<a[i]<<" ";
  cout<<endl;
}
/* Declare variables here*/
ll T;
const ll MAXN = 50000; 
ll n,k,a[MAXN],sum[MAXN+1];

/* user define functions specific to problem */




/* solve here */
void solve()
{
    cin>>n>>k;
    rep(i,n)cin>>a[i];
    rep(i,n) sum[i+1] = sum[i]+a[i];

    ll lo = 0, hi = MAXN*1e9;
    while(lo < hi)
    {
        ll mid = lo + ((hi-lo)>>1);

        ll cnt = 0;
        ll l = 0, h = n-1;
        //cout<<"lo ="<<lo<<" mid= "<<mid<<" hi= "<<hi<<endl;
        for(int i = 0; i< n; i++)
        {
            l = i;
            while(h >= l && sum[h+1] - sum[l] > mid)h--;
            cnt += max(h - l+1,0ll);
            //cout<<"i= "<<i<<" upd cnt by"<<h-l+1<<endl;
        }
        //cout<<endl;
        if(cnt >= k) hi = mid;
        else lo = mid + 1;
    }
    cout<<lo;
}

/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 

  solve();

  return 0;
}
