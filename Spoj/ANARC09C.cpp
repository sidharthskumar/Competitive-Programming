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
int T;
int n, q;

/* user define functions specific to problem */


vl sieveOfEratosthenes(int N)
{
    vector <bool> prime(N+1, false);
    vl s(N+1,0);
    for (ll i=2; i<=N; i+=2)
        s[i] = 2;
 
    for (ll i=3; i<=N; i+=2)
    {
        if (prime[i] == false)
        {
            s[i] = i;
            for (ll j=i; j*i<=N; j+=2)
            {
                if (prime[i*j] == false)
                {
                    prime[i*j] = true;
                    s[i*j] = i;
                }
            }
        }
    }
    return s;
}


/* solve here */
void solve()
{
  vl s = sieveOfEratosthenes(1000000);
  ll a,b;
  cin>>a>>b;
  ll cnt=1;
  while(a != 0 || b != 0)
  {

    vll va,vb;
    ll ans = 0;
    ll ord = 0;
    if(a != 1)
    {
      ll num = a;
      ll curr = s[num];  
      ll cnt = 1;
      while (num > 1)
      {
          num /= s[num];
          if (curr == s[num])
          {
              cnt++;
              continue;
          }
          va.pb(mp(curr,cnt));
          curr = s[num];
          cnt = 1;
      }
    }

    if(b != 1)
    {
      ll num = b;
      ll curr = s[num];  
      ll cnt = 1;
      while (num > 1)
      {
          num /= s[num];
          if (curr == s[num])
          {
              cnt++;
              continue;
          }
          vb.pb(mp(curr,cnt));
          curr = s[num];
          cnt = 1;
      }
    }

    if(va.size()==0){
      ord = vb.size();
      rep(i,vb.size()) ans += vb[i].ss;
    }
    else if(vb.size()==0){
      ord = va.size();
      rep(i,va.size()) ans += va[i].ss;
    }
    else {
      rep(i,va.size())
      {
        int flag = 0;
        rep(j,vb.size())
        {
          if(va[i].ff==vb[j].ff){
            ans += abs(va[i].ss-vb[j].ss);
            flag = 1;
            break;
          }
        }
        if(!flag){
          ans += va[i].ss;
        }
        ord++;
      }
      rep(i,vb.size())
      {
        int flag = 0;
        rep(j,va.size())
        {
          if(vb[i].ff==va[j].ff){
            flag = 1;
            break;
          }
        }
        if(!flag){
          ans += vb[i].ss;
          ord++;
        }
      }
    }

    cout<<cnt<<". "<<ord<<":"<<ans<<endl;
    cnt++;
    cin>>a>>b;
      
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