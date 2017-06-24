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
#define repr(i,n) fr(i,n-1,0)
#define repvr(i,a) repr(i,a.size())
#define repv(i,a) rep(i,a.size()) 
#define loopr(i,a,b,x) for(ll i = a; i>=b;i--)
#define fr(i,a,b) loopr(i,a,b,1)
#define mem(a,b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SORT(v) sort(v.begin(),v.end());
#define inc(A, B, C)  A <= B && B <= C

/* important functions */
template <typename T>
T minm(initializer_list<T> list)
{ 
  T m = numeric_limits<T>::max();
  for( auto elem : list)
  {
    if(elem < m)
      m = elem;
  }

  return m;
}

template <typename T>
T maxm(initializer_list<T> list)
{
  T m = numeric_limits<T>::min();
  for( auto elem : list)
  {
    if(elem > m)
      m = elem;
  }

  return m;
} 

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

/* user define functions specific to problem */


/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n;
  cin>>n;
  while(n != -1) {
    vll pairs;
    rep(i,n) {
      ll s,e;
      cin>>s>>e;
      pairs.pb(mp(s,e));
    }
    sort(all(pairs));
    vl a(n,-1);
    vl cnt(n,0);
    rep(i,n-1){
      ll beg = i+1, end = n-1;
      while(true){
        if(beg > end)
          break;
        ll mid = (beg + end) / 2;
        if(pairs[i].ss <= pairs[mid].ff){
          a[i] = mid;
          end = mid - 1;
        }
        else{
          beg = mid + 1;
        }
      }
       
    }
    
    repvr(i,a){
      if(a[i] != -1){
        cnt[i] = 1;
        if(a[a[i]] != -1) {
          cnt[i] += cnt[a[i]];
        }
      }
    }

    prvec(cnt);

    ll md = 100000000;
    ll min = n;
    ll ans = 0;
    repv(i,cnt){
      if(a[i] != -1){
        if(a[i] < min){
          ans += fast_exp((ll)2,cnt[i]+1,md) - 1;
          if(i < min){
            ans += 2*(min - a[i] - cnt[i]+1);
            ans += (n - min +1);  
          }
          min = a[i];
        }
        else if(i < min){
          ans += (n-a[i]);
        }
      }
      else if(i < min){
        ans++;
      }
    }
    cout<<ans<<endl;
    cin>>n;
  } 

  return 0;
}


