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
  ll n;
  cin>>n;
  while(n != 0)
  {
     int flag  = 0;
     if(n == 1)
     {
       cout<<"yes"<<endl;
       cin>>n;
       continue;
     }  
     vl a(n);
     vl r;
     vl d;
     rep(i,n) cin>>a[i];
     d.pb(max(a[0],a[1]));
     r.pb(min(a[0],a[1]));

     if(d[0] != n && r[0] != 1)
     {
        cout<<"no"<<endl;
        cin>>n;
        continue;
     }

     f(i,2,n)
     {
      ll dtop = d[d.size()-1];
      ll rtop = r[r.size()-1]; 
      if(a[i] == rtop + 1)
      {
        r.pb(a[i]);
      }
      else if(a[i] == dtop - 1)
      {
        d.pb(a[i]);
      }
      else
      {
        
        while(d.size() && d[d.size()-1] + 1 <= a[i])
        {
          r.pb(d[d.size()-1]);
          d.pop_back(); 
        }

        if(a[i] == r[r.size()-1] + 1)
        {
          r.pb(a[i]);
        }
        else if(!d.size() || a[i] == d[d.size()-1] - 1)
        {
          d.pb(a[i]);
        }
        else
        {
            flag = 1;
            break;    
        }

      }
        
     }

     if(flag) cout<<"no"<<endl;
    else cout<<"yes"<<endl;   

     cin>>n;
  }
 
  return 0;
}


