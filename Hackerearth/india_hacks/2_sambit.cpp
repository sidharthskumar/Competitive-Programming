#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5;
int a[maxn],b[maxn],c[maxn],d[maxn];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i < n; i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
    int mx = -1;
    for(int h=0; h< 24; h++){
        for(int m = 0; m < 60; m++){
            int cnt = 0;
            for(int i = 0; i < n; i++){
                int flag = 0;
                if(h < a[i] || h > c[i]) flag = 1;
                if(h == a[i] && m < b[i]) flag = 1;
                if(h == c[i] && m > d[i]) flag = 1;
                if(!flag) cnt++;
            }
            mx = max(mx,cnt);

        }
    }
    cout<<mx;
}
