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

 
vl maxIndexDiff(vl arr)
{
    ll n = arr.size();
    vl maxDiff(n,-1);
    int i, j;
 
    vl LMin(n);
    vl RMax(n);
 
    LMin[0] = arr[0];
    for (i = 1; i < n; ++i)
        LMin[i] = min(arr[i], LMin[i-1]);
 
    RMax[n-1] = arr[n-1];
    for (j = n-2; j >= 0; --j)
        RMax[j] = max(arr[j], RMax[j+1]);
    
    i = 0, j = 0;
    while (j < n && i < n)
    {
        if (LMin[i] < RMax[j])
        {
            maxDiff[i] = max(maxDiff[i], j);
            j = j + 1;
        }
        else
            i = i+1;
    }
 
    return maxDiff;
}


ll get_sum(vl arr, ll i , ll j)
{
  if(i > j) return 0;
  else if(i == 0) return a[j];
  else return a[j]  - a[i-1];
}
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
    ll n , l, a,b;
    cin>>n>>l>>a>>b;
    ll min_dist = INT_MAX;
    vl s(n);
    vl arr(n);
    vl ls(n);
    vl rs(n);

    rep(i,n) cin>>s[i];
    
    sort(all(s));
/*    arr[0] = s[0];
    f(i,1,n)
    {
      arr[i] = arr[i-1] + s[i];
    }

    rep(i,n)
    {
      ls[i] = s[i] - i*l;
      rs[i] = s[i] + i*l; 
    }
    vl mapL = maxIndexDiff(ls);
    vl mapR = maxIndexDiff(rs);
*/
    ll ind = 0;

    while(ind < n){
      ll dist = 0;
      ll ns = s[ind]; 
      if(s[ind] - ind*l < a)
      {
        ll shift = (a - s[ind] - ind*l);
        ns += shift;
        dist += shift;
      }
      if(s[ind] + (n-1-ind)*l  > b)
      {
        ll shift = (s[ind] + (n-1-ind)*l - b);
        ns -= shift;
        dist += shift;
      }
      ll new_dist = dist;
      ll cc = ind-1;
      ll p = s[ind] - l;

      if(new_dist < min_dist) 
      {  
        min_dist = new_dist;
      } 
      
      ind++;
    }

    cout<<min_dist<<endl; 

  }

  return 0;
}


