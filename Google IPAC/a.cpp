#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include "gmpxx.h"
using namespace std;


int main() {
    int t;
    cin>>t;
    for(int ao=0;ao<t;ao++){
    string n,target;
    long double ans=1;
    cin>>n;
    if(n.length()==2 && n[0]!=n[1]){
        ans=4;
    }
    else if(n.length()>2){
        for(int i=0;i<n.length();i++){
            if(i==0){
                if(n[1]!=n[0])
                    ans*=2;
            }
            else if(i==n.length()-1){
                if(n[n.length()-2]!=n[n.length()-1])
                    ans*=2;
            }
            else if(n[i]==n[i+1] && n[i]==n[i-1] && n[i-1]!=n[i+1])
                ans*=2;

            else if(n[i]==n[i+1] && n[i]!=n[i-1] && n[i-1]==n[i+1])
                ans*=2;
            else if(n[i]==n[i+1] && n[i]!=n[i-1] && n[i-1]!=n[i+1])
                ans*=2;
            else if(n[i]!=n[i+1] && n[i]==n[i-1] && n[i-1]==n[i+1])
                ans*=2;
            else if(n[i]!=n[i+1] && n[i]==n[i-1] && n[i-1]!=n[i+1])
                ans*=2;
            else if(n[i]!=n[i+1] && n[i]!=n[i-1] && n[i-1]==n[i+1])
                ans*=2;
            else if(n[i]!=n[i+1] && n[i]!=n[i-1] && n[i-1]!=n[i+1])
                ans*=3;



        }
    }

    long int x=pow(10,9)+7;
    cout<<"Case #"<<(ao+1)<<": "<<fmod(ans,x)<<endl;
    }
    return 0;
}
