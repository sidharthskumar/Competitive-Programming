#include <iostream>
#include <vector>

using namespace std;

class ZigZag {
	public:
	
	int longestZigZag(vector<int> x){
		int n = x.size();
		vector<int> diff(n);
		for(int i=1; i < n; i++) {
			diff[i]=x[i]-x[i-1]; 
		}
		int flag = 0; //positive 
		int count = 0;
		for(int i=1;i < n;i++){
			 if( (count == 0 || !flag) && diff[i] < 0)
			 {
			 	flag = 1;
			 	count++;
			 }
			 else if((count == 0 || flag) && diff[i] > 0)
			 {
			 	flag = 0;
			 	count++;
			 }
			
		}
		return count+1;
	}

};