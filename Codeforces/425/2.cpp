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
#define rep(i,a,b) for(long long i = (a); i <= (b); i++)
#define rrep(i,a,b) for (long long i = (a) - 1; i >= b; i--)
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
const ll maxn = 2e5;
int good[28];
int dp[maxn][28];
/* user define functions specific to problem */




/* solve here */
void solve()
{
     string gd;
     cin>>gd;
     rep(i,0,gd.length()-1) good[gd[i] - 'a'] = 1;
     string pat;
     cin>>pat;
     int star = 0;
     rep(i,0,pat.length()-1)
     {
         if(pat[i] == '?'){
             rep(j,0,25){
                 if(good[j]) dp[i][j] = 1;
             }
         }
         else if(pat[i] == '*'){
            star = 1;
            rep(j,0,25) if(!good[j])dp[i][j] = 2;
            ll ind = i+1;
            while(ind < pat.length()){
                if(pat[ind]=='?') {rep(j,0,25)if(good[j]) dp[ind-1][j] = 1;}
                else dp[ind-1][pat[ind] - 'a'] = 1;
                ind++;
            }
         }
         else dp[i][pat[i] - 'a'] = 1;

     }
    // rep(i,0,pat.length()-1) {
         //rep(j,0,25) cout<<dp[i][j]<<" ";
       //  cout<<endl;
     //}
     ll mn = 0;
     if(star){
         mn = pat.length() - 1;
     }
     else mn =  pat.length();
     ll mx = pat.length();
     //cout<<mn<<mx<<endl;
     ll q;
     cin>>q;

     while(q--)
     {
         string str;
         cin>>str;
         int flag = 0;

         if(str.length() < mn || str.length() > mx) flag = 1;
         else {
             ll required = 0;
             rep(k,0,str.length()-1){
                 if(dp[k][str[k] - 'a'] == 0) {
                     flag = 1;
                     break;
                 }
                 if(dp[k][str[k]-'a'] == 2){
                    required=1;
                 }
             }
             if(required && str.length() != pat.length()) flag = 1;
         }
         if(flag == 0) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;

    }
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
