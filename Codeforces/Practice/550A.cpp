#include <bits/stdc++.h>

using namespace std;

int main()
{
    string x;
    cin>>x;
    vector <int> a,b;
    int n =x.length();
    for(int i=0;i < n;i++)
    {
        if(x[i] == 'A' && i < n-1 && x[i+1]== 'B')
        {
            a.push_back(i);
        }
        if(x[i] == 'B' && i < n -1 && x[i+1] == 'A')
        {
            b.push_back(i);
        }
    }

    if(a.size() && b.size() && (abs(a[0] - b[b.size()-1]) > 1 || abs(a[a.size()-1] - b[0]) > 1))
        cout<<"YES";
    else cout<<"NO";
   
    return 0;
}
