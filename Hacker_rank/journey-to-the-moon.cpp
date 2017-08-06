/*
 *   Template by Siddhartha Mishra(sid_m97)
 *   */

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
{ return (a%b+b)%b;  }


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
int n,p;
vector<bool> used;
ll ans;
ll saa;
ll sa;
/* user define functions specific to problem */
void dfs(vector< vector<int> > g, int n, int v,int &cnt)
{
    used[v] = true;
    cnt++;
    for(vector<int> :: iterator i = g[v].begin(); i != g[v].end(); i++)
    {
        if(!used[*i])
        {
            dfs(g,n,*i,cnt);

        }

    }

}




/* solve here */
void solve()
{
    cin>>n>>p;
    used.resize(n);
    vector < vector <int> > g(n);
    rep(i,p){
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);

    }
    fill(all(used),false);
    rep(i,n)
    {
        if(!used[i])
        {
            int c = 0;
            dfs(g,n,i,c);
            sa += c;
            saa += c*c;

        }


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
    //  //while(T--)
    //    solve();
    //      
    //        return 0;
    //
}
