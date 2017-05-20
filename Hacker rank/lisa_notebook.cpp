#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

        int n,k,n_pages=0,n_special=0;
        cin>>n>>k;
        int n_p[n];
        for(int i=0;i<n;i++){
            cin>>n_p[i];

       }

       for(int i=0;i<n;i++){
           int check=0;
           if(n_p[i]%k!=0)
               check= 1;
           int index=1;

           for(int j=0;j<(n_p[i]/k)+check;j++){
                vector<int> inds;
               n_pages++;
               if(j<(n_p[i]/k)+check-1 || check==0){
               for(int x=index;x<index+k;x++){
                   inds.push_back(x);
               }
               index+=k;
               }
               else{
                   for(int y=index;y<index+n_p[i]%k;y++)
                    inds.push_back(y);
               }



               for(int h=0;h<inds.size();h++){
                    if(n_pages==inds[h]){
                        n_special++;

                    }

               }

           }


       }


        cout<<n_special;


    return 0;
}
