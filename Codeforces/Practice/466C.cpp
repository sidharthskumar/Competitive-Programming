/*
	Template by Siddhartha Mishra(sid_m97)
*/
#include <bits/stdc++.h>

using namespace std;

#define inf (int)1e9
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
#define mem(a,b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SORT(v) sort(v.begin(),v.end());
#define inc(A, B, C)  A <= B && B <= C

/* important functions */

ll mod(ll a, ll b)
{ return (a%b+b)%b; }

ll fast_exp(int base, int exp ,int mod=MOD) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}

void prvec(vl a){
  rep(i,a.size()) cout<<a[i]<<" ";
  cout<<endl;
}

void prvec(vi a){
  rep(i,a.size()) cout<<a[i]<<" ";
  cout<<endl;
}

/* user define functions specific to problem */



/* main function */
ll n;
vl sum(n,0);
vi cntc(n,0);

    
ll get_sum(ll i, ll j){
  if(i != 0){
    return sum[j] - sum[i-1];
  }
  else return sum[j];
}

ll get_count(ll i, ll j){
  if(i != 0){
    return cntc[j] - cntc[i-1];
  }
  else return cntc[j];
}

int main() 
{
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);

  cin>>n;
  sum.resize(n);
  cntc.resize(n);
  vl a(n);
  ll s = 0;
  rep(i,n){
    cin>>a[i];
    s += a[i];
  }
  if(s%3 != 0){
    cout<<0;
    return 0;
  }
  sum[0] = a[0];
  f(i,1,n){
    sum[i] = sum[i-1] + a[i];
  }
  vi cnt(n,0);

  rep(i,n){
    if(get_sum(i,n-1) == s/3)
      cnt[i] = 1;
  }
  cntc[0] = cnt[0];
  f(i,1,n){
    cntc[i] = cntc[i-1] + cnt[i];
  }
  ll count = 0;
  
  f(i,1,n){
    if(get_sum(0,i-1) == s/3){
      count += get_count(i+1,n-1);
    }
  }
  cout<<count;
  return 0;
}


