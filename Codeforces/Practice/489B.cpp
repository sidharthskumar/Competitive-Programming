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
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))

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

int n,m;
int a[100],b[100];
bool ta[100],tb[100];

template <typename T>
void prvec(T a){
  rep(i,a.size()) cout<<a[i]<<" ";
  cout<<endl;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    
    cin>>m;
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a,a+n);
    sort(b,b+m);
    int ind = 0;
    int jind = 0;
    int ans = 0;
    
    while(ind < n && jind < m) 
    {             
        while(ind < n && a[ind] < b[jind]-1) ind++;
        if(ind == n) break;
        while(jind < m && b[jind] < a[ind]-1) jind++;
        if(jind==m) break;
        if(abs(a[ind]-b[jind])<=1)
        {
            ind++;
            jind++;
            ans++;
        }
        
   }
    cout<<ans;
    return 0;
}
