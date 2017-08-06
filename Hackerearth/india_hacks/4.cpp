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
const ll maxn = 2e5;
ll a[maxn],b[maxn],temp[maxn],pos[maxn];

/* user define functions specific to problem */
ll merge(ll l, ll mid , ll r)
{
    ll inv = 0;
    ll i = l, j = mid+1, k = l;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j]){ b[k++] = a[i++]; }
        else { b[k++] = a[j++]; inv += (mid- i+1); }
    }
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    rep(ind,l,r) a[ind] = b[ind];
    return inv;
}

ll merge_sort(ll l , ll r)
{
    ll inv = 0;
    if(l < r)
    {
        ll mid = (l + r)/2;
        inv += merge_sort(l,mid);
        inv += merge_sort(mid+1,r);
        inv += merge(l, mid , r);
    }
    return inv;
}




/* solve here */
void solve()
{
    ll n;
    cin>>n;
    rep(i,0,n-1) { cin>>a[i]; temp[i] = a[i]; }
    ll cnt = merge_sort(0,n-1);
    rep(i,0,n-1) pos[a[i]] = i;
    ll cx = cnt;
    rep(i,0,n-2) { 
        cnt = (cnt+(n-1-pos[temp[i]]) - pos[temp[i]]); 
        cx ^= cnt; 
    }
    cout<<cx<<endl;
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
