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
const int MAXN = 100001;
int x[MAXN];
int h[MAXN];
int s[MAXN];
int l[MAXN];
int r[MAXN];

/* user define functions specific to problem */




/* solve here */
void solve()
{
    int n;
    cin>>n;
    rep(i,n)
    {
        int xi,hi;
        cin>>xi>>hi;
        x[i] = xi;
        h[i] = hi;
    }
    x[n] = INT_MAX;
    h[n] = INT_MAX;
    l[0]++; 
    if(n > 1 && x[0]+h[0] < x[1]) r[0]++;
    for(int i=1;i < n;i++)
    {
        s[i] = max(s[i-1],max(l[i-1],r[i-1]));
        l[i] = l[i-1];
        if(x[i] - h[i] > x[i-1]) l[i] = max(l[i]+1,s[i-1]+1);
        if(x[i] - h[i] > x[i-1] + h[i-1]) l[i] = max(l[i],r[i-1]+1);
        
        if(x[i] + h[i] < x[i+1]) r[i] =  max(s[i-1],max(l[i-1],r[i-1]))+1;
    }
    cout<<max(s[n-1],max(l[n-1],r[n-1]));

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
