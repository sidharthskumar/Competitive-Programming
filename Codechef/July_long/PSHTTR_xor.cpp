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
  ll r;
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
template <typename T> 
void prnt(T beg, T end){
  for(auto it = beg; it != end; it++) cout<<*it<<" ";
  cout<<endl;
}

/* Declare variables here*/
ll T;

const int maxn=400005;

int o;
int use[maxn],ansl[maxn],ansr[maxn],edge[maxn],first[maxn],last[maxn];
ll xr[maxn],edgexr[maxn];
struct node{
    int v;
    int wt;

};

void dfs(vector<vector<node>> & f,node p, node s){
    use[s.v] = 1;
    for (auto& vert: f[s.v]){
        if (use[vert.v]==0)
        {
            use[vert.v]=1;
            ansl[o] = s.v;
            ansr[o] = vert.v;
            edge[o] = vert.wt;
            o++;
            dfs(f, s, vert);

        }

    }
    if(p.v != 0) {
        ansl[o] = s.v;
        ansr[o] = p.v;
        edge[o] = s.wt;
        o++;

    }

}


/* user define functions specific to problem */




inline void solve()
{
    int n,m;
    scanf("%d",&n);
    vector<vector<node>> f(n+1);
    vll e;
    rep(i,n-1){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        f[u].pb({v,c});
        f[v].pb({u,c});
        e.pb(c);
    }
    memset(use,0,sizeof(use));
    memset(first,-1,sizeof(use));
    memset(last,-1,sizeof(last));
    o=0;
    dfs(f,{0,0},{1,0});
    ll curr = o - 1;
    
    for(int i=0; i<= o-1;i++){
        if(first[ansl[i]] == -1) first[ansl[i]] = i;
        last[ansr[i]] = i;
        if(i == 0) edgexr[i] = edge[i];
        else edgexr[i] = edgexr[i-1] ^ edge[i];
    }
    sort(all(e));
    prnt(all(e));
    xr[0] = e[0];
    for(int i=1; i < n -1 ;i++){
        xr[i] = xr[i-1]^e[i];
    }
    scanf("%d",&m);
    while(m--)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        ll ind = upper_bound(all(e),k) - e.begin();
        if(n==1 || (u == v) || ind == 0){
            printf("0\n");
            continue;

        } 
        
        ll lef = first[u];
        ll rig = last[v];
        ll ans = 0;
        if(lef == 0)
            ans ^= edgexr[rig];
        else ans ^= edgexr[rig] ^ edgexr[lef-1];
        printf("first %lld\n",ans);
        ll temp = ans;
        ans ^= xr[ind-1];
        printf("second %lld\n",ans);
        ans ^= temp;
        printf("third %lld\n", ans);
    }
    o = 0;

}

/* main function */

int main() 
{
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0); 
    scanf("%lld",&T);
    while(T--)
        solve();

    return 0;

}  
