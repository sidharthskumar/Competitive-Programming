/*
  Template by Siddhartha Mishra(sid_m97)
*/

#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define fill(x, y) memset(x, y, sizeof(x))

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef long long ll;
typedef double D;
typedef long double LD;
typedef pair<ll, ll> pll;


const int inf = INT_MAX; 
const double eps = 1e-9;
const double pi = acos(-1.0);
const int  MOD =  1000000007;

/* important functions */
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
/* Declare variables here*/
ll T;


/* user define functions specific to problem */




/* solve here */
void solve()
{
   //priority_queue<int,vector<int>, greater<int>> pq;
   ll n;
   cin>>n;
   ll cnt = 0;
   int flag = 0;
   set<int> s; 
   int nsort = 0;
   vi st;
   for(ll i = 0;i <2*n ;i++)
   {
       string cmd;
       ll num;
       cin>>cmd;
       if(cmd == "add"){
         flag = 1;  
         cin>>num;
         st.push_back(num);
         if(!s.size() || num < *s.begin()){
            s.insert(num);
         }
         else {
            s.insert(num);
            nsort = 1;
         }
       } else {  
         if(nsort && flag) cnt++;
         s.erase(st[st.size()-1]);
         st.pop_back();
         flag = 0;
         nsort = 0;
       }    
   }
   cout<<cnt;
}

/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 

  solve();

  return 0;
}
