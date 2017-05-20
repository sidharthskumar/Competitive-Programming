#include <vector>
using namespace std;

class BadNeighbors {
	public:
	int maxDonations(vector<int> donations) {
		int n = donations.size();
		return max(rec(donations, 0 , n-1) , rec(donations, 1 , n));
	} 

	int rec(vector<int> donations, int start , int end) {
		if(start == end) 
			return donations[start];
		vector<int> s(40,0);
		s[start] = donations[start];
		s[start+1] = max(donations[start], donations[start+1]);
		for(int i = start+2; i < end; i++) {
			s[i] = max(s[i-2] + donations[i], s[i-1]);
		} 
		return s[end-1];
	}

};
