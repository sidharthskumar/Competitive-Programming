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


/* user define functions specific to problem */
struct node{
    ll d;
    ll t;
    ll s;
}; 

struct nodee{
    ll s;
    ll ind;
};
bool vcomp(const node & a, const node & b)
{
    return a.d < b.d;
}

struct pcomp{
    bool operator()(const nodee &a, const nodee &b)
    {
       return a.s < b.s;
    }
};


/* solve here */
void solve()
{
   ll n,d;
   cin>>n>>d;
   vector<node> vn(n);
   rep(i,n) cin>>vn[i].d>>vn[i].t>>vn[i].s;
   sort(all(vn),vcomp);
   priority_queue<nodee,vector<nodee>,pcomp> pq;
   ll curr = 0;
   FOR(day,1,d)
   {
      while(curr < n && vn[curr].d <= day)
      {
              nodee newnodee = {vn[curr].s,curr};
              pq.push(newnodee);
              curr++;
      }
      if(pq.empty()) continue;
      nodee mx = pq.top();   
      vn[mx.ind].t --;
      if(vn[mx.ind].t == 0) pq.pop();
   }
   ll ans = 0;
   for(auto& el :vn) ans += el.t*el.s;
   cout<<ans<<endl;

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
