#include<iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;


int main() {
    freopen("A-small-practice-1.in","r",stdin);
    freopen("out.txt","w",stdout);
  int t;
  cin>>t;
  for(int ao=0;ao < t;ao++){
    int m;
    cin>>m;
    vector<string> badname1,badname2;

    bool flag=true;
    for(int i=0;i<m;i++){
        string x,y;
        cin>>x>>y;
        if(i==0){
            badname1.push_back(x);
            badname2.push_back(y);
        }
        else{
            if(find(badname1.begin(),badname1.end(),x)==badname1.end()){
                if(find(badname2.begin(),badname2.end(),x)!=badname2.end()){

                badname1.push_back(x);

                }
                else
                    flag=false;
            }
            else if(find(badname1.begin(),badname1.end(),x)!=badname1.end()){
                if(find(badname2.begin(),badname2.end(),x)==badname2.end()){

                badname2.push_back(x);

                }
                else
                    flag=false;
            }


            if(find(badname1.begin(),badname1.end(),y)!=badname1.end()){
                if(find(badname2.begin(),badname2.end(),y)==badname2.end()){
                badname2.push_back(y);

                }
                else
                    flag=false;
            }
            else if(find(badname1.begin(),badname1.end(),y)==badname1.end()){
                if(find(badname2.begin(),badname2.end(),y)!=badname2.end()){
                badname1.push_back(y);

                }
                else
                    flag=false;
            }

        }
    }
    if(flag)
        cout<<"Case #"<<ao+1<<": "<<"Yes"<<endl;
    else
        cout<<"Case #"<<ao+1<<": "<<"No"<<endl;


  }


  return 0;
}
