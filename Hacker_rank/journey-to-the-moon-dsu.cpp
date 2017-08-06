/*
  Template by Siddhartha Mishra(sid_m97)
*/

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((long long) (x).size())
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define FOR(i,a,b) for(long long i = (a); i <= (b); i++)
#define rrep(i, n) for (long long i = (n) - 1; i >= 0; i--)
#define fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef long long ll;
typedef vector<ll> vll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll inf = 1e18; 
const double eps = 1e-9;
const double pi = acos(-1.0);
const ll  MOD =  1e9+7;

/* important functions */
ll mod(ll a,ll b=MOD)
{ return (a%b+b)%b; }


ll xdiv(ll a,ll b)
{
  if(a%b == 0) return a/b;
  else return a/b + 1;
}

ll gcd(ll a, ll b) {
  ll r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

ll powmod(ll base, ll exp ,ll mod=MOD) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}

ll inv(ll a, ll m = MOD)
{
    return powmod(a, m-2,m);
}

void prnt(auto beg, auto end){
  for(auto it = beg; it != end; it++) cout<<*it<<" ";
  cout<<endl;
}

/* Declare variables here*/
ll T;
ll n,p;
ll sa,saa;
map <int, ll> cnt;
/* user define functions specific to problem */
class UnionFind
{

public:
        struct subset
        {
            int parent;
            int rank;
        };
        subset* subsets;

        UnionFind(int n)
        {
            subsets = new subset[n];
            for(int i = 0; i < n; i++)
            {
                subsets[i].parent = i;
                subsets[i].rank = 0;
            }
        }

        int find(int i)
        {
            if (subsets[i].parent != i)
                subsets[i].parent = find(subsets[i].parent);
            return subsets[i].parent;

        }

        void Union(int x, int y)
        {
            int xroot = find(x);
            int yroot = find(y);

            if (subsets[xroot].rank < subsets[yroot].rank)
                subsets[xroot].parent = yroot;
            else if (subsets[xroot].rank > subsets[yroot].rank)
                subsets[yroot].parent = xroot;

            else
            {
                subsets[yroot].parent = xroot;
                subsets[xroot].rank++;
            }
        }
};





/* solve here */
void solve()
{
    cin>>n>>p;
    UnionFind dsu(n);
    rep(i,p){
        int u,v;
        cin>>u>>v;
        dsu.Union(u,v);
    }
    rep(i,n)
    {
        cnt[dsu.find(i)]++;
    }
    for(auto key: cnt){
        sa += key.se;
        saa += key.se*key.se;
    }
    cout<<(sa*sa - saa)/2; 

}

/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
  //cin>>T;
  //while(T--)
  solve();
  
  return 0;
}
