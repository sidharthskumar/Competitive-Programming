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


/* user define functions specific to problem */
const ll MAXN = 1000000;

ll cnt[MAXN+1];
ll flag[MAXN+1];
ll c[MAXN+1];
/* solve here */
void solve()
{
   ll n,a;
   cin>>n>>a;
   fill(flag,-1);
   rep(i,n)
   {
       cin>>c[i];
   }
   ll ans = -1;
   flag[a] = 0;
   rep(i,n)
   {   
       cnt[c[i]]++;
       if(cnt[c[i]] >= cnt[a] && flag[c[]]) flag[c[i]] = 1;
       else flag[c[i]]=0;
   }


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
