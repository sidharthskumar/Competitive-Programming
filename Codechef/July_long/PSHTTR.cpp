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
{ return (a%b+b)%b;  }


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
int T;
/* user define functions specific to problem */
const int maxn=500005;

int o;
int use[maxn],edge[maxn],first[maxn],last[maxn];
struct node{
    int v;
    int wt;

};
vector<node> f[maxn];
void dfs(node p, node s){
    use[s.v] = 1;
    for (auto& vert: f[s.v]){
        if (use[vert.v]==0)
        {
            use[vert.v]=1;
            if(first[s.v]==-1) first[s.v] = o;
            last[vert.v] = o;
            edge[o] = vert.wt;
            o++;
            dfs(s, vert);

        }

    }
    if(p.v != 0) {
        if(first[s.v]==-1) first[s.v] = o;
        last[p.v] = o;
        edge[o] = s.wt;
        o++;

    }

}


    vector<int> tree[3*maxn];
    vector<ll> cxor[3*maxn]; 
    void merge(int curr)
    {
        int i = 0, j =0 , k = 0;
        int n1 = tree[2*curr+1].size();
        int n2 = tree[2*curr+2].size();
        tree[curr].resize(n1+n2); 
         
        while (i < n1 && j < n2)
        {
            if (tree[2*curr+1][i] <= tree[2*curr+2][j])
            {
                tree[curr][k] = tree[2*curr+1][i];
                i++;
            }
            else
            {
                tree[curr][k] = tree[2*curr+2][j];
                j++;
            }
            k++;
        }
     
        while (i < n1)
        {
            tree[curr][k] = tree[2*curr+1][i];
            i++;
            k++;
        }
     
        while (j < n2)
        {
            tree[curr][k] = tree[2*curr+2][j];
            j++;
            k++;
        }
        
    }
    void build_tree(int cur ,int l ,int r)
    {
        if(l==r)
        {
            tree[cur].resize(1);
            cxor[cur].resize(1);
            tree[cur][0] = edge[l];
            cxor[cur][0] = edge[l];
            return ;

        }
        int mid = l+((r-l)>>1);
        build_tree(2*cur+1 , l , mid ); 
        build_tree(2*cur+2 , mid+1 , r ); 
        merge(cur);
        cxor[cur].resize(tree[cur].size());
        cxor[cur][0]= tree[cur][0];
        for(int ind = 1;ind <= tree[cur].size()-1; ind++){
            cxor[cur][ind] =  cxor[cur][ind-1]^tree[cur][ind];
        }

    }
    ll query(int cur, int l,int r,int x, int y, int k )
    {
        if( r < x || l > y   )
        {
            return 0; 

        }
        if( x<=l && r<=y )
        {
            int ul = 0 , hi = tree[cur].size();
            while(ul < hi)
            {
                int md = ul + ((hi-ul)>>1);
                if(tree[cur][md] > k) hi = md;
                else ul = md + 1;
            }
       
            if(ul != 0) return cxor[cur][ul-1];
            else return 0;

        }
        int mid=l+((r-l)>>1);
        return query(2*cur+1,l,mid,x,y,k)^query(2*cur+2,mid+1,r,x,y,k);

    }


/* main function */

int main() 
{
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d",&n);
        FOR(i,1,n) f[i].clear();
        rep(i,n-1){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            f[u].pb({v,c});
            f[v].pb({u,c});

        }
        memset(use,0,sizeof(use));
        memset(first,-1,sizeof(first));
        memset(last,-1,sizeof(last));
        o=0;
        dfs({0,0},{1,0});
        build_tree(0,0,o-1);
            
        scanf("%d",&m);
        while(m--)
        {
            int u,v,k;
            scanf("%d%d%d",&u,&v,&k);     
            if(n==1 || (u == v)){
                printf("0\n");
                continue;

            }
            ll lef = first[u];
            ll rig = last[v];
            if(lef > rig) printf("%lld\n", query(0,0,o-1,lef,o-1,k) ^ query(0,0,o-1,0,rig,k));
            else printf("%lld\n",query(0,0,o-1,lef,rig,k));

        }
        o = 0;

    }
    return 0;

}   
