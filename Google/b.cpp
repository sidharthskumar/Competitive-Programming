#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

unsigned long qxor(unsigned long a,unsigned long b,unsigned long c,unsigned long d){
    return ((a^b)^(c^d));
}
int main() {
    freopen("B-small-attempt1.in","r",stdin);
    freopen("outB.txt","w",stdout);
    int t;
    cin>>t;
    int count=0;
    for(int ao=0;ao<t;ao++){
    unsigned long int n,k;
    cin>>n>>k;
    vector<unsigned long int >aa(n),bb(n),cc(n),dd(n);
    for(int i=0;i<n;i++)
        cin>>aa[i];
    for(int i=0;i<n;i++)
        cin>>bb[i];
    for(int i=0;i<n;i++)
        cin>>cc[i];
    for(int i=0;i<n;i++)
        cin>>dd[i];

    for(int a=0;a<n;a++)
        for(int b=0;b<n;b++)
            for(int c=0;c<n;c++)
                for(int d=0;d <n;d++){
                    if(qxor(aa[a],bb[b],cc[c],dd[d])==k)
                    {

                        count++;
                    }
                }

    cout<<"Case #"<<(ao+1)<<": "<<count<<endl;
    }
    return 0;
}
