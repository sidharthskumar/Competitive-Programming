#include <bits/stdc++.h>

const int MOD = 1000000007;

using namespace std;

int main()
{
    int n;
    cin>>n;
    int abc = 0;
    int d = 1;

    for(int i= 1; i<= n;i++)
    {
        int d1 = (3ll* abc)%MOD;
        abc = ((abc*2ll)%MOD + d)%MOD;
        d = d1;
        //cout<<abc<<" "<<d<<endl;

    }
    cout<<d;

    return 0;
}
