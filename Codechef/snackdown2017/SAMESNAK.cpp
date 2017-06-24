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
#define F first
#define S second

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
  rep(i,t){
    pll a,b,c,d;
    cin>>a.F>>a.S>>b.F>>b.S;
    cin>>c.F>>c.S>>d.F>>d.S;
    int flag = 0;

    if(a==c || a==d || b==c || b==d){
      flag = 1;
    }
    if(!flag){
      if(a.S == b.S) {
        if(c.S == d.S) {
          if(a.F > b.F) swap(a.F,b.F);
          if(c.F > d.F) swap(c.F,d.F);
          if((inc(a.F,c.F,b.F) )|| (inc(c.F,a.F,d.F))){
            flag = 1;
          }
        }
      }
      else {
        if(c.F == d.F){
          if(a.S > b.S) swap(a.S,b.S);
          if(c.S > d.S) swap(c.S,d.S);
          if((inc(a.S,c.S,b.S)) || (inc(c.S,a.S,d.S))){
            flag = 1; 
          }
        }
      }
    }
    if(flag) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
  }
	return 0;
}


