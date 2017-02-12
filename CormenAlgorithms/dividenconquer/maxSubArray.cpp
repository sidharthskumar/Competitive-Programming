#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

int* max_cross_subarray(int *A,int low ,int mid,int high){
    int left_sum=numeric_limits<int>::min();
    int result[3];
    int sum=0,max_left;
    for(int i=mid;i>=0;i--){
        sum+=A[i];
        if(sum> left_sum){
            left_sum=sum;
            max_left=i;
        }
    }
    int right_sum=numeric_limits<int>::min();
    sum=0;
    int max_right;
    for(int i=mid+1;i<=high;i++){
        sum+=A[i];
        if(sum> right_sum){
            right_sum=sum;
            max_right=i;
        }
    }
    result[0]=max_left;
    result[1]=max_right;
    result[2]=left_sum+right_sum;

    return result;
}

int* max_subarray(int *A ,int low ,int high){
    int result[3];
    if(high==low){
        result[0]=high;
        result[1]=high;
        result[2]=A[high];
        return result;
    }
    else {
        int mid=floor((low+high)/2);
        int* left_result=max_subarray(A,low,mid);
        int* right_result=max_subarray(A,mid+1,high);
        int* cross_result=max_cross_subarray(A,low,mid,high);
        if(left_result[2]>=right_result[2] && left_result[2]>=cross_result[2])
            return left_result;
        else if(right_result[2]>=left_result[2] && right_result[2]>=cross_result[2])
            return right_result;
        else
            return cross_result;
    }
}


int main() {
    int n;
    int* res;
    cin>>n;
    int ar[n];
    for(int x=0;x<n;x++)
        cin>>ar[x];
    res=max_subarray(ar,0,n-1);
    cout<<res[2]<<endl;



     return 0;
}
