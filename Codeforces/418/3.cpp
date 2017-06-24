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
  int n;
  cin>>n;
  string s;
  cin>>s;
  map<char,vi> l;
  vector<char> letters;  
  rep(i,s.length()){
    if(l.find(s[i])==l.end())
    {
      l[s[i]]=vector<int> (n,0);
      letters.pb(s[i]);
    }
  }
  
  rep(i,letters.size())
  {
    string temp = s;
    int c = 0;
    cout<<letters[i]<<endl;
    rep(j,n){
      int mnind = -1;
      int mnl = 99999;
      int mnr = 99999;
      rep(k,n){
        int ind = k;
        int l = 0 , r = 0;
        while(ind > 0 && temp[ind-1] != letters[i]){
          l++;
          ind--;
        }
        ind = k;
        while(ind < n-1 && temp[ind+1] != letters[i]){
          r++;
          ind++;
        }
        if(l+r < mn){
          mnind = k;
          mnl = l;
          mnr = r;
        }
      }
      temp[mnind]=letters[i];
      cout<<j<<" "<<temp<<endl;
      l[letters[i]][j] = mx;
    }
  }
  int q;
  cin>>q;
  
  rep(i,q)
  {
    int m;
    char c;
    cin>>m>>c;
    cout<<l[c][m-1]<<endl;
  } 

  return 0;
}


