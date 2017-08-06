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
ll a[103][103];
ll suc[103];
/* user define functions specific to problem */




/* solve here */
void solve()
{
   cin>>n>>m;
   rep(i,1,n) {
       string s;
       cin>>s;
       rep(j,0,s.length()-1) a[i][j+1] = s[j]-'0';
   }
   rep(j,1,m) {
       ll mx = -1;
       rep(i,1,n){
           if(a[i][j] > mx){
               mx = a[i][j];
           }     
       }
       rep(i,1,n) if(a[i][j] == mx) suc[i] = 1;
    }
   ll cnt = 0;
   rep(i,1,n) if(suc[i])cnt++;
   cout<<cnt;
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
