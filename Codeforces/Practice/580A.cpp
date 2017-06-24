#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int ind = 0;
    int mx = -1;
    while(ind < n)
    {
        int j = ind+1;
        while(j < n && a[j] >= a[j-1])j++;
        if(j - ind > mx) mx = j - ind;
        ind = j;
    }
    cout<<mx;

    return 0;
}
