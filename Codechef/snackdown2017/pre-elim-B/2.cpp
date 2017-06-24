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
    vector<vector<int>> a(n, vector<int>(m));
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
    map<ll, vl> mp,mp2; 
    rep(i,n)
    {
      rep(j,m)
      {
        if(a[i][j]==mx)
        {
          mp[i].pb(j);
          mp2[j].pb(i);
        }
      }
    }

    vector<ll> r,c;
    for(map<ll,vl>::iterator it = mp.begin(); it != mp.end(); ++it) {
      r.push_back(it->first);
    }

    for(map<ll,vl>::iterator it = mp2.begin(); it != mp2.end(); ++it) {
      c.push_back(it->first);
    }

    ll limitr = r.size();
    ll limitc = c.size();
    
    ll nmax = -1;
    rep(k,n)
    {
      ll l = lower_bound(all(r),k) - r.begin();
      vl posr;
      if(l != limitr)
      {
        posr.pb(l);
        if(l > 0)
          posr.pb(l-1);
      }
      else
      {
        posr.pb(l-1);
      }
      cout<<k<<endl;
      rep(j,m)
      {
        ll jk = lower_bound(all(c),j) - c.begin();
        vl posc;  
        if(jk != limitc)
        {
          posc.pb(jk);
          if(jk > 0)
            posr.pb(jk-1);
        }
        else
        {
          posr.pb(jk-1);
        }
        int mn = 999999;
        repv(p,posr)
        {
          ll jl = lower_bound(all(mp[r[posr[p]]]),j) - mp[r[posr[p]]].begin();
          if(jl != mp[r[posr[p]]].size())
          {
            if(max(abs(r[posr[p]] - k),abs(mp[r[posr[p]]][jl] - j)) < mn)
              mn = max(abs(r[posr[p]] - k),abs(mp[r[posr[p]]][jl] - j));
            if(jl > 0)
            {
              if(max(abs(r[posr[p]] - k),abs(mp[r[posr[p]]][jl-1] - j)) < mn)
                mn = max(abs(r[posr[p]] - k),abs(mp[r[posr[p]]][jl-1] - j));
            }
          }
          else
          {
            if(max(abs(r[posr[p]] - k),abs(mp[r[posr[p]]][jl-1] - j)) < mn)
              mn = max(abs(r[posr[p]] - k),abs(mp[r[posr[p]]][jl-1] - j));
          }

        }
        repv(v,posc)
        {
          ll il = lower_bound(all(mp2[c[posc[v]]]),j) - mp2[c[posc[v]]].begin();
          if(il != mp2[c[posc[v]]].size())
          {
            if(max(abs(c[posc[v]] - j),abs(mp2[c[posc[v]]][il] - k)) < mn)
              mn = max(abs(c[posc[v]] - j),abs(mp2[c[posc[v]]][il] - k));
            if(il > 0)
            {
              if(max(abs(c[posc[v]] - j),abs(mp2[c[posc[v]]][il-1] - k)) < mn)
                mn = max(abs(c[posc[v]] - j),abs(mp2[c[posc[v]]][il-1] - k));
            }
          }
          else
          {
            if(max(abs(c[posc[v]] - j),abs(mp2[c[posc[v]]][il-1] - k)) < mn)
              mn = max(abs(c[posc[v]] - j),abs(mp2[c[posr[v]]][il-1] - k));
          }           
        }
        cout<<" j "<<j<<" "<<mn<<endl;
        if(mn > nmax)
          nmax = mn;
      }
      cout<<endl;
    }
    
  
    cout<<nmax<<endl; 
  } 

  return 0;
}


