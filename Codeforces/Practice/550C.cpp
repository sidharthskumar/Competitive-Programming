#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int li = -1,lj = -1,lk = -1;
    int n = s.length();
    for(int i=0;i<n;i++)
    {
        for(int j= i+1;j <n;j++){
            for(int k=j+1;k<n;k++)
            {
                int x = (s[i]-'0')*100+(s[j]-'0')*10+(s[k]-'0');
                if(x%8==0)
                {
                    li = i;
                    lj = j;
                    lk = k;  
                }
            }
        }
    }
    if(li == -1)
    {
        for(int j=0;j <n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int n0 = s[j] - '0';
                int n1 = (s[k] - '0');
                int n2 = n0*10+n1;
                if(n2%8 == 0) 
                {
                    cout<<"YES"<<endl<<s[j]<<s[k];
                    lj = j;
                    break;                
                }
            }
            if(lj != -1)break;
        }
        if(lj == -1)
        {
            for(int k =0;k <n;k++)
            {
                int n1 = s[k] - '0';
                if(n1%8==0)
                {
                    cout<<"YES"<<endl<<s[k];
                    lk = k;
                    break;
                }
            }
            if(lk == -1)
            {
                cout<<"NO";
            }
        }
    }
    else
    {
        cout<<"YES"<<endl;
        int ind = 0;
        while(ind <= li)
        {
            cout<<s[ind];
            ind++;
        }
        cout<<s[lj];
        cout<<s[lk];
    }

    return 0;
}
