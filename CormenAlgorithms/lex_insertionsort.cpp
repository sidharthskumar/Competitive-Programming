
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    //freopen("C-small-practice-1.in","r",stdin);
    //freopen("outC.txt","w",stdout);
    int t;
    cin>>t;
    for(int ao=0;ao<t;ao++){
    int n;
    cin>>n;
    string ar[n];
    int count=0;
    int x = 0;
    for (string word; getline(cin,word) && x<n; x++)
        ar[x] = word;
    for(int i=1;i<n;i++){
        string key=ar[i];
        int j=i-1;
        while(j>=0 && ar[j].compare(key)>0){
            ar[j+1]=ar[j];
            j-=1;
            count++;
        }
        ar[j+1]=key;
    }
    cout<<"Case #"<<(ao+1)<<": "<<count<<endl;
    }
    return 0;
}
