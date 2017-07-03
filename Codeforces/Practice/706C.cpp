#include <bits/stdc++.h>
#define ll long long 
#define fill(a,b) memset(a,b,sizeof(a)); 
using namespace std;

const int MAXN = 1e6;

ll C[MAXN];
ll NR[MAXN];
ll R[MAXN];

int main()
{
    vector<string> s,sr;
    int n;
    cin>>n;
    for(int i=0;i <n;i++)cin>>C[i];
    for(int i=0;i <n;i++)
    {
        string z;
        cin>>z;
        s.push_back(z);
        reverse(z.begin(),z.end());
        sr.push_back(z);
    }
    for(int i=0;i <n;i++)
    {
        NR[i] = 1ll << 60;
        R[i] = 1ll << 60;
    }
    NR[0] = 0ll;
    R[0] = C[0];
       //for(int i=0;i <n;i++) cout<<sr[i]<<" "; cout<<endl;
    for(int i= 1; i < n;i++)
    {
        int flag = 0;
        if(s[i] >= s[i-1]){
             NR[i] = min(NR[i-1],NR[i]);
        }
        if(s[i] >= sr[i-1]){
            NR[i] = min(NR[i],R[i-1]);
        } 
        if(sr[i] >= s[i-1]){
            R[i] = min(R[i],NR[i-1]+C[i]);
        }
        if(sr[i] >= sr[i-1]){
            R[i] = min(R[i],R[i-1]+C[i]);
        }               
    }
    ll ans = min(NR[n-1],R[n-1]);
    if(ans > 1ll << 50) cout<<-1;
    else cout<<ans;
    return 0;
}
