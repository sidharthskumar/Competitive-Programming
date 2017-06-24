#include <bits/stdc++.h>


using namespace std;

const int MAXN = 100000;
int a[MAXN];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i <n;i++)cin>>a[i];
    int ind = 0;
    int mx = 1;
    while(ind < n-1)
    {
        int j = ind;
        while(j < n -1 &&  a[j] < a[j+1]) j++;
        if(j-ind+1 > mx) mx = j - ind+1;
        ind = j+1;
    }
    cout<<mx;
    return 0;
}
