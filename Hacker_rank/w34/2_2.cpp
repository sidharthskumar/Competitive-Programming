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
const ll maxn = 1e6+5;
int s[maxn] ,prime[maxn],a[maxn],b[maxn];

/* user define functions specific to problem */

/* solve here */

/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  ll n;
  cin>>n;
  rep(i,n) cin>>a[i];
  rep(i,n) cin>>b[i];
  vll marka(maxn,-1), markb(maxn,-1),vma(maxn,-1),vmb(maxn,-1);
  rep(i,n){
      vma[a[i]] = i;
      vmb[b[i]] = i;
  } 
  for(ll i= 1; i < maxn; i++){
      for(ll j=i;j < maxn;j += i){
          if(vma[j] != -1){
                if(marka[i] == -1) marka[i] = vma[j];
                else if(a[marka[i]] < j) marka[i] = vma[j];
                cout<<marka[i]<<endl;
          }
          if(vmb[j] != -1){
               if(markb[i] == -1) markb[i] = vmb[j];
               else if(b[markb[i]] < j) markb[i] = vmb[j];
               cout<<markb[i]<<endl;
          }
      }
  }
  ll ind = 1e6;
  while(ind >= 1){
      if(marka[ind] != -1 && markb[ind] != -1){
          cout<<a[marka[ind]]+ b[markb[ind]];
          break;
      }
      ind--;
  }
  return 0;
}
