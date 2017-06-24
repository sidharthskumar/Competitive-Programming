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

ll gcd(ll a, ll b) {
  ll r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}




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

vl simpleSieve(int limit)
  {
    bool mark[limit];
    memset(mark, true, sizeof(mark));
    vl result;
    // One by one traverse all numbers so that their
    // multiples can be marked as composite.
    for (ll p=2; p*p<limit; p++)
    {
        // If p is not changed, then it is a prime
        if (mark[p] == true)
        {
            // Update all multiples of p
            for (ll i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
 
    for (ll p=2; p<limit; p++)
        if (mark[p] == true)
            result.pb(p);

    return result;
  }

/* main function */

int main() 
{
  //std::ios::sync_with_stdio(false);
  //cin.tie(0);
  //cout.tie(0); 

  vl primes = simpleSieve(1000);
  int t;
  cin>>t;
  rep(i,t){
    int k;
    cin>>k;
    ll num = 30;
    int count = 0;
    while(count != k){
      ll n = num,c = 0, ind =0;
      while(c < 3 && ind < primes.size() && primes[ind] <= n){
        if(n % primes[ind] == 0){
          c++;
          while(n % primes[ind] == 0)
            n /= primes[ind];
        }
        else ind++;
      }
      if(c==3) count++;
      num++;  
    }
    cout<<num-1<<endl;

  }


  return 0;
}


