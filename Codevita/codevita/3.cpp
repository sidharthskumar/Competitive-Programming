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
#define ll long long 
#define SS stringstream
using namespace std;

/* user define functions specific to problem */
ll n;
ll a[100][7];
ll s[100][7];


/* solve here */
void solve()
{
    cin>>n;
    rep(i,n){
        string s;
        cin>>s;
        ll ind = 0;
        rep(j,5) {
            a[i][j]  = 0;
            ll st = ind;
            while(ind < (ll) s.length() && s[ind] != ','){
                ind++;
            }
            ll curr = ind-1;
            ll prod = 1;
            while(curr >= st){
                a[i][j] += (s[curr] - '0')*prod;
                curr--;
                prod *= 10;
            }
            ind++;
            
        }

    }
    rep(i,n){
        rep(j,5){
            s[i][j] = a[i][j];
        }
    }
    FOR(i,1,n-1){
        FOR(j,0,i-1){
            rep(c,5){
                rep(d,5){
                    if(a[i][c] > a[j][d] && s[i][c] < s[j][d] + a[i][c]){
                        s[i][c] = s[j][d] + a[i][c];
                    }
                }
            }
        }
    }
    ll mx = INT_MIN;
    rep(i,n){
        rep(j,5){
            mx = max(s[i][j],mx);
        }
    }
    cout<<mx<<endl;
}

/* main function */

int main() 
{
  //std::ios::sync_with_stdio(false);
  //cin.tie(0);
  //cout.tie(0); 
  //cin>>T;
  //while(T--)
  solve();
  
  return 0;
}
