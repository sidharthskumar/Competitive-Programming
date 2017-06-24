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

/* user define functions specific to problem */



/* main function */

int main() 
{
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
  ll t;
  cin>>t;
  rep(i,t) {
    ll n;
    cin>>n;
    vl strip(n);
    rep(i,n) cin>>strip[i];
    int flag = 0;
    if(n%2 == 0) {flag = 1;}
    else {
      rep(i,(n/2)+1){
        if(strip[i] != (i+1)){
          flag = 1;
          break;
        }
      }
      f(i,(n/2)+1,n){
        if(strip[i] != strip[n- 1-i]){
          flag  = 1;
          break;
        }
      }
    }

    if(flag) cout<<"no"<<endl;
    else cout<<"yes"<<endl;
  } 

	return 0;
}


