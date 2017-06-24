#include <bits/stdc++.h>

using namespace std;

int a[501];

int main()
{   
    int n,k;
    cin>>n>>k;
    for(int i=0;i < n;i++)cin>>a[i];
    int s=0;
    for(int i=1;i < n;i++)
    {
        if(a[i]+a[i-1]<k)
        {
            s += (k-a[i-1]-a[i]);
            a[i] = k -a[i-1];
        }
    }    
    cout<<s<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
