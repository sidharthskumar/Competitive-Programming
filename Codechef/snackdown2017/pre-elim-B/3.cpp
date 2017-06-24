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
  //std::ios::sync_with_stdio(false);
  //cin.tie(0);
  //cout.tie(0);
  ll t;
  cin>>t;
  rep(i,t)
  {
    ll n,m;
    cin>>n>>m;
    vector<vector<int> > a(n, vector<int>(m));
    rep(i,n)
    {
      rep(j,m)
      {
        cin>>a[i][j];
      }
    }
    ll mx = -1;
    rep(i,n)
    {
      rep(j,m)
      {
        if(a[i][j] > mx) mx = a[i][j];
      }
    }
    
    vector<vector<bool> > flag(n, vector<bool>(m,false));
    
    vl mi(m*n,0);
    vl mii(m*n,0);

    ll count = 0;

    rep(i,n)
    {
      rep(j,m)
      {
        if(a[i][j] == mx)
        {
          mi[count] = i;
          mii[count] = j;
          flag[i][j] = true;
          count++;
        }
      }
    }

    ll rad = 0;
    bool check = true;
    while(check)
    {
      rep(i,n)
      {
        rep(j,m)
        {
          if(!flag[i][j])
          {
            check = false;
            cout<<rad<<endl;
            i = n;
            j = m;
          }
        }
        
      }
      if(!check)break;
      check = true;
      rep(it,count)
      {
          ll k=mi[it];
          ll l=mii[it];
          for(ll i=max((ll)0,k-rad-1);i<=min(k+rad+1,n-1);i++){
            for(ll j=max((ll)0,l-rad-1);j<=min(l+rad+1,m-1);j++){
              flag[i][j]=true;
            }
          }
      }
      rad++;
    }
  }    
  

  return 0;
}


