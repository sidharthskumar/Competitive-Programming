#include <bits/stdc++.h>

using namespace std;

int a[100];
int mx[100];
int en[100];
int sm[101];
int main()
{
    int n;
    cin>>n;
    sm[0] = 0;
    for(int i=0;i <n;i++){
        cin>>a[i];
        sm[i+1] = sm[i]+a[i];
    }
    int mx = -1;
    for(int i=0;i <n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if( sm[n] + j- i + 1 - 2*(sm[j+1] - sm[i]) > mx)
                mx =  sm[n] + j- i + 1 - 2*(sm[j+1] - sm[i]);
        }
    }
    cout<<mx;
     
    return 0;
}
