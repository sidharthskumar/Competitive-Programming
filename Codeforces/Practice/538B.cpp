#include <bits/stdc++.h>


using namespace std;
const int MAXN = 1000000;
int a[MAXN+1];
int main()
{   
    int n;
    cin>>n;
    string curr = to_string(n);
    int cnt=0;
    while(stoi(curr) != 0)
    {
        string ext;
        for(int i=0;i < curr.length();i++)
        {
            if(curr[i] != '0')
            {
                ext += '1';
                curr[i]--;
            }
            else ext += '0';
        }
        int ind = 0; 
        while(ext[ind] == '0')ind++;
        cnt++;
        a[cnt-1]=stoi(ext.substr(ind));
    }
    cout<<cnt<<endl;
    for(int i=0;i < cnt;i++)cout<<a[i]<<" ";
    return 0;
}
