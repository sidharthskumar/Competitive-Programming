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
void sieve(ll N, vll & s)
{
    vector <bool> p(N+1, false);
    for (ll i=2; i<=N; i+=2) s[i] = 2;
    for (ll i=3; i<=N; i+=2)
    {
        if (!p[i]){
            s[i] = i;
            for (ll j=i; j<=N; j+=i){
                if (p[j])
                {
                    p[j] = true;
                    s[j] = i;
                }
            }
        }
    }
}


/* solve here */
void solve()
{
   ll n;
   const ll maxn = 2e6;
   vll s(maxn+1), a(maxn+1) , b(maxn+1) , mark(maxn+1,-1) , markb(maxn+1,-1); 
   cin>>n;
   rep(i,n)cin>>a[i];
   rep(i,n)cin>>b[i]; 
  
   sieve(maxn,s);
   s[1] = 2;
   cout<<"a= ";
   rep(i,n)
   {
       ll anum = a[i];
       while(anum >= 1)
       {
           cout<<anum<<" ";
          if(mark[anum] == -1) mark[anum] = i;
          else if(a[mark[anum]] < a[i]) mark[anum] = i;
          if(anum == 1) break;
          anum /= s[anum]; 
       }
   }
   
   rep(i,n)
   {
       ll bnum = b[i];
       while(bnum >= 1)
       {
          cout<<bnum<<" ";
          if(markb[bnum] == -1) markb[bnum] = i;
          else if(b[markb[bnum]] < b[i]) markb[bnum] = i;  
          if(bnum == 1) break;
          bnum /= s[bnum];
       }
   }
   cout<<endl;
   ll cn = 1e6;
   while(cn >= 1){ 
       if(mark[cn] != -1 && markb[cn] != -1) {
           cout<<cn<<" "<<a[mark[cn]]+b[markb[cn]];
           break;
       }
       cn--;
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
