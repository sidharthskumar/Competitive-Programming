#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int mins = 0;
    while(a > 2 || b > 2)
    {
        if(max(a,b)==a)
        {
            a -= 2;
            b += 1;
        }
        else
        {
            a += 1;
            b -= 2;
        }
        mins++;
    }
    if(a> 1 || b>1)mins++;
    cout<<mins;
    return 0;
}
