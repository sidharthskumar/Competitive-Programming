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
ll n,k;
const ll maxn = 3000;
const ll bbmaxn = 2e7 , bbmin = 4e6;
ll a[maxn] , b[maxn] , s[maxn];
ll bb[bbmaxn];
/* user define functions specific to problem */




/* solve here */
void solve()
{
   cin>>k>>n;
   rep(i,k) cin>>a[i]; 

   ll mx = LLONG_MIN;
   rep(i,n) { cin>>b[i]; bb[bbmin+b[i]] = 1;  mx = max(mx,b[i]);}
   s[0] = a[0];
   FOR(i,1,k-1) s[i] = s[i-1] + a[i];
   ll inda = k-1;
   ll cnt = 0;
   unordered_map<ll,ll> added;
   while(inda >= 0){
       rep(i,n) bb[bbmin+b[i]]  = 1;
       ll bbcnt = n;
       ll st = mx - s[inda]; 
       if(added.count(st)){ inda--; continue; }
       added[st] = 1;
       ll curra = k-1;
       int flag = 0;
       while(curra >= 0){
           if(bb[bbmin+s[curra] + st] == 1){
               //cout<<"scur"<<s[curra] <<"st"<<st<<endl; 
               bb[bbmin+s[curra] + st] = 0;
               bbcnt--;
               if(bbcnt == 0){
                   flag = 1;
                   break;
               }
           } 
           curra--;
       }
       if(flag) cnt++;
       inda--;
   }
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
