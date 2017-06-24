/*******************************
You should enjoy the little detours...
Because that's where you'll find the things
more important than what you want...

Version	:	1.63
Author	:	Harshwardhan Praveen
*******************************/
#include <bits/stdc++.h>
using namespace std;

#define pi 			3.141592653593
#define MOD         1000000007
#define EPS 		0.000000001

#define cns 		ios_base::sync_with_stdio(false)
#define DEBUG(x) 	cout << '>' << #x << ':' << x << endl
#define REP(i,n) 	for(ll i=0;i<(n);i++)
#define FOR(i,a,b) 	for(ll i=(a);i<(b);i++)
#define DFOR(i,a,b) for(ll i=(a);i>=(b);i--)
#define pb 			push_back
#define mp 			make_pair
#define all(v) 		v.begin(),v.end()
#define rall(v) 	v.rbegin(),v.rend()
#define vi 			vector<int>
#define vl 			vector<ll>
#define vii 		vector<vector<int> >
#define vll 		vector<vector<ll> >
#define vs 			vector<string>
#define vb			vector<bool>
#define si 			set<int>
#define pii	 		pair<int,int>
#define pll			pair<ll,ll>
#define F 			first
#define S 			second
#define ll 			long long
#define ull 		unsigned long long

int main(){
/*	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	*/
	int T;
	cin >> T;
	REP(I,T){
		int n, m;
		cin >> n >> m;
		vi degree(n+1, 0);
		si adjacency[n+1];
		REP(i, m){
			int x,y;
			cin >> x >> y;
			adjacency[x].insert(y);
			adjacency[y].insert(x);
			degree[x]++;
			degree[y]++;
		}
		si graph[n+1];
		FOR(i, 1, n+1){
			graph[degree[i]].insert(i);
		}
/*
		FOR(j, 1, n+1){
			cout << j << " -> ";
			for(auto i : adjacency[j])
				cout << i << " ";
			cout << endl;
		}
*/
		int it = 0;
		while(it < n){
			FOR(d, 1, it + 1){
				for (auto i : graph[d]){
					for( auto j : adjacency[i]){
						if(degree[j]>0){
							adjacency[j].erase(i);
							graph[degree[j]].erase(j);
							degree[j]--;
							graph[degree[j]].insert(j);

						}
					}
					graph[degree[i]].erase(i);
					degree[i]--;
					graph[degree[i]].insert(i);
				}
			}

			if(graph[0].size() == n)
				cout << graph[0].size() - 1 << " ";
			else
				cout << graph[0].size() << " ";
			it++;
		}

	}	
}