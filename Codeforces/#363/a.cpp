#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
int n;cin>>n;
vector <int> a(n);
for(int i=0;i<n;i++)
    cin>>a[i];
if(n==2){
    if(a[0]==a[1])
        cout<<1<<" "<<2<<endl;
}

int sum[n][n]={0};
for(int i=0;i<n-1;i++)
    for(int j=i+1;j<n;j++)
        {sum[i][j]=a[i]+a[j];}

for(int i=0;i<n-1;i++){
    int flag3=0;
    for(int y=i+1;y<n;y++)
    {
    int flag[n-1]={0};
    int x=sum[i][y];
    for(int k=0;k<n-1;k++)
        for(int j=k+1;j<n;j++){
            if(sum[k][j]==x)
                flag[k]=1;
    }

    int flag1=0;
    int count=0;
    for(int k=0;k<n-1;k++)
        if(flag[k]==1){
            count++;
        }

    //cout<<count<<" ";

    if(count>=n/2){
        int zarr[n-1]={0},yarr[n-1]={0},u=0,v=0;
        for(int z=0;z<n-1;z++)
            for(int y=z+1;y<n;y++){
                if(sum[z][y]==x ){
                        int flag2=0;
                        for(int l=0;l<n-1;l++){
                            if(zarr[l]==z+1 || yarr[l]==y+1 || zarr[l]==y+1 || yarr[l]==z+1)
                                flag2=1;
                        }
                    if(flag2==0){
                        cout<<z+1<<" "<<y+1<<endl;
                        zarr[u++]=z+1;
                        yarr[v++]=y+1;
                    }
                }
            }
        flag3=1;
        break;

    }

    }
            if(flag3==1)
            break;
}

return 0;
}
