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


/* user define functions specific to problem */




/* solve here */
void solve()
{
    int n;
    cin>>n;
    cin.ignore();
      rep(i,n)
      {
        string s;
       getline(cin,s);
       int nspaces = count(all(s),' ');
       int ns = 0;
       string::iterator it = s.begin();
       vs str(3);
       while(it != s.end()){
          while(it != s.end() && *it != ' '){
            str[ns] += *it;
            it++;
           }
          if(it != s.end()) {
              it++;
              ns++;
           }
       }
       if(nspaces == 0){
           FOR(i,1,str[0].length()) str[0][i] = tolower(str[0][i]);
          str[0][0] = toupper(str[0][0]);
          cout<<str[0]<<endl;
       }
       else if(nspaces == 1){
           str[0][0] =toupper(str[0][0]);
           FOR(i,1,str[1].length()) str[1][i] = tolower(str[1][i]);
           str[1][0] = toupper(str[1][0]);
           cout<<str[0][0]<<". "<<str[1]<<endl;
       }
       else {
           str[0][0] = toupper(str[0][0]);
           FOR(i,1,str[1].length()) str[1][i] = tolower(str[1][i]);

           str[1][0] = toupper(str[1][0]);
           FOR(i,1,str[2].length()) str[2][i] = tolower(str[2][i]);

           str[2][0] = toupper(str[2][0]);
           cout<<str[0][0]<<". "<<str[1][0]<<". "<<str[2]<<endl;
       }
             
      }
 }

/* main function */

int main() 
{
  //std::ios::sync_with_stdio(false);
  ///cin.tie(0);
  //cout.tie(0); 
  //cin>>T;
  //while(T--)
  solve();
  
  return 0;
}
