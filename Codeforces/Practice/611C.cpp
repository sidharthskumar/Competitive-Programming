#include <bits/stdc++.h>


using namespace std;
const int MAXN = 500;

int hor[MAXN+1][MAXN+1];
int ver[MAXN+1][MAXN+1];
char a[MAXN+1][MAXN+1];


int main()
{
    int h,w;
    cin>>h>>w;
    for(int i= 0; i< h; i++)
    {
        for(int j=0;j < w;j++) cin>>a[i][j];
    }
    for(int i=1; i <= h;i++)
    {
        for(int j=1 ; j <= w;j++)
        {
             hor[i][j] = hor[i][j-1]+ hor[i-1][j] - hor[i-1][j-1]; 
             if(j < w && a[i-1][j]=='.' && a[i-1][j-1] == '.')
             {
                 hor[i][j]++;
             }
             ver[i][j] = ver[i][j-1] + ver[i-1][j] - ver[i-1][j-1];
             if(i < h && a[i][j-1] == '.' && a[i-1][j-1] == '.')
             {
                 ver[i][j]++;
             }   
        }   
    }
    
    for(int i=0;i <= h;i++)
    {
        for(int j=0; j <= w ;j++) cout<<hor[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
     for(int i=0;i <= h;i++)
    {
        for(int j=0; j <= w ;j++) cout<<ver[i][j]<<" ";
        cout<<endl;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;c1--;
        int ans = 0;
        ans += hor[r2][c2] - hor[r2][c2-1] - hor[r1-1][c2] + hor[r1-1][c1-1] ;
        ans += ver[r2][c2] - ver[r2][c2-1] - ver[r1-1][c2] + ver[r1-1][c1-1];
        cout<<ans<<endl;
    }

    return 0;
}
