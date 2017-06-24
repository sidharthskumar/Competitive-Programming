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

ll a,b;
ll min_dig(){
  return a == 0 ? b : b+1;
}

/* main function */

int main() 
{
	//std::ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0); 
  ll m,s;
  cin>>m>>s;
  a= s%9;
  b = s/9;
  if(m==1 && s <= 9) cout<<s<<" "<<s;
  else if(min_dig() > m || (s==0)){
    cout<<-1<<" "<<-1;
  }
  else {
    if(min_dig() == m){
      if(a != 0)cout<<a;
      rep(i,b) cout<<9;
    }
    else {
      cout<<1;
      rep(i,m-b-2) cout<<0;
      if(a>=1){
        cout<<a-1;
        rep(i,b) cout<<9;  
      }
      else {
        cout<<0;
        cout<<8;
        rep(i,b-1) cout<<9;
      } 
      
    }
    cout<<" ";
    rep(i,b) cout<<9;
    if(m>b) cout<<a;
    rep(i,m-b-1) cout<<0;
  }



	return 0;
}


