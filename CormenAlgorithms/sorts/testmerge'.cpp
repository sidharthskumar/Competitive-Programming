#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    vector<int> ar(n);
    for(int i=0;i<n;i++)
        cin>>n;
    int pivotindex=n-1;
    int ans;
    while(pivotindex>=0){
         int pivot=ar[pivotindex];
            vector<int> leftarray,rightarray;
        for(int i=0;i<n;i++){
            if(ar[i]<=pivot){
                leftarray.push_back(ar[i]);
            }
            else{
                rightarray.push_back(ar[i]);
            }
        }
        if(leftarray.size()==rightarray.size()){
             ans=pivot;
            break;}
        else
            pivotindex--;
        }
    cout<<ans;
    return 0;
}
