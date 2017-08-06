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
#define rrep(i,a,b) for (long long i = (a) ; i >= b; i--)
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
const ll maxn = 2e6;
ll dpl[maxn] ,dpr[maxn];
/* user define functions specific to problem */




/* solve here */
void solve()
{
     string s;
     cin>>s;
     ll n = s.length();
     s = '0'+s;
     rep(i,0,maxn-1) dpl[i] = 0 , dpr[i] = n+1;
     rep(i,2,n-1){
         if(s[dpl[i-1]+1] == s[i]) dpl[i] = dpl[i-1] + 1;
         else if(s[i] == s[1]) dpl[i] = 1;
     }
     rrep(i,n-1,2){
         if(s[dpr[i+1]-1] == s[i]) { dpr[i] = dpr[i+1] - 1;}
         else if(s[i] == s[n]) dpr[i] = n;
     }
     prnt(dpl+1,dpl+n+1);
     prnt(dpr+1,dpr+n+1);
     ll mx = -10;
     ll mxind = -1;
     ll ind = 2;
     while(ind <= n-1){
         if(dpl[ind] == 1){
             ll temp = ind;
             while(ind <= n-1 && dpl[ind] != 0 && dpr[ind] != n+1) ind++;
             if(dpr[ind-1] == n){
                 ll len = ind - temp;
                 if(len > mx){
                     mx = len;
                     mxind = temp;
                 }
             }
         }
         ind++;
     }
     if(mxind == -1 || mx == 0) {
         cout<<"Just a legend";
         return;
     }
     rep(i,mxind,mxind+mx-1) cout<<s[i];

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
