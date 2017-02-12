#include <iostream>
using namespace std;


int main() {
    cout<<"Enter the size of the array you want to Sort"<<endl;
    int n;
    cin>>n;
    int ar[n];
    cout<<"Enter the elements of the array"<<endl;
    for(int x=0;x<n;x++)
        cin>>ar[x];
    for(int i=1;i<n;i++){
        int key=ar[i];
        int j=i-1;
        while(j>=0 && ar[j]>key){
            ar[j+1]=ar[j];
            j-=1;
        }
        ar[j+1]=key;
    }
    cout<<"The sorted array is "<<endl;
    for(int i=0;i<n;i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    return 0;
}
