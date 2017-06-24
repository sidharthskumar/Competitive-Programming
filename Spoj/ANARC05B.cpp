/*
  Template by Siddhartha Mishra(sid_m97)
*/
#include <bits/stdc++.h>

using namespace std;

#define inf 1e9
#define eps 1e-9
const double pi = acos(-1.0);
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

#define ll long long
#define vi vector<int>
#define vf vector<float>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define mpii map<int,int>
#define seti set<int>
#define mseti multiset<int>

#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

#define loop(i, a, b, x) for(ll i = a;i <b; i += x)
#define f(i,a,b) loop(i,a,b,1)
#define rep(i,n) f(i,0,n)
#define repv(i,a) rep(i,a.size()) 
#define loopr(i,a,b,x) for(ll i = a; i>=b;i--)
#define fr(i,a,b) loopr(i,a,b,1)
#define repr(i,n) fr(i,n-1,0)
#define repvr(i,a) repr(i,a.size())
#define mem(a,b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SORT(v) sort(v.begin(),v.end());
#define inc(A, B, C)  A <= B && B <= C

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
ll get_sum(vl cum,ll i,ll j)
{
  if(i < 0) i = 0;
  if(i >= cum.size()) i = cum.size() - 1;
  if(j < 0) return 0;
  if(j >= cum.size()) j = cum.size() - 1;
  if(i > j) return 0;
  else if(i == 0) return cum[j];
  else return cum[j] - cum[i-1];
}



/* solve here */
void solve()
{
  int n,m;
  cin>>n;
  while(n != 0)
  {
    vl a(n);
    vl cuma(n);
    rep(i,n) cin>>a[i];
    cuma[0] = a[0];
    f(i,1,n){
      cuma[i] = cuma[i-1] + a[i];
    }
    cin>>m;
    vl b(m);
    vl cumb(m);
    rep(i,m) cin>>b[i];
    cumb[0] = b[0];
    f(i,1,m){
      cumb[i] = cumb[i-1] + b[i];
    }
    vl inda,indb;
    rep(i,n) {
      ll lb = lower_bound(all(b),a[i]) - b.begin();
      if(b[lb]==a[i]){
        inda.pb(i);
        indb.pb(lb);
      }
    }
    ll ans = 0;
    if(inda.size() == 0)
    {
      ans = max(cuma[n-1],cumb[m-1]);
    }
    else
    {
      ans = max(get_sum(cuma,0,inda[0]-1),get_sum(cumb,0,indb[0]-1));
      f(i,0,inda.size()-1)
      {
        ans += max(get_sum(cuma,inda[i],inda[i+1]-1),get_sum(cumb,indb[i],indb[i+1]-1)); 
      }
      ans += max(get_sum(cuma,inda[inda.size()-1],n-1),get_sum(cumb,indb[indb.size()-1],m-1));
    }
    cout<<ans<<endl;
    cin>>n;
  }


}

void solver(int test)
{
  if(test) {
    cin>>T;
    rep(i,T) {solve();}
    return;
  }
  solve();
}


/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 

  solver(0);

  return 0;
}