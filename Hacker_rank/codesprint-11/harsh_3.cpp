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
#define DFOR(i,a,b) for(ll i=(a);i>(b);i--)
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
#define pii 		pair<int,int>
#define pll			pair<ll,ll>
#define F 			first
#define S 			second
#define ll 			long long
#define ull 		unsigned long long

map < string, priority_queue<int, vi, greater<int> > > file;

string crt(string name1){
	DEBUG(file[name1].size());
	if(file[name1].size() == 0){
		file[name1].push(1);
		return name1;
	}
	else{
		int next = file[name1].top();
		file[name1].pop();
		if(file[name1].size() == 0)
			file[name1].push(next+1);
		if(next == 0)
			return name1;
		return name1 + "(" + to_string(next) + ")"; 
	}
}

string del(string name1){
	int x = 0;
	if(name1[name1.size()-1]==')'){
		int it = name1.size() - 2;
		while(name1[it]!='('){
			x += (name1[it]-'0')*pow(10,(name1.size()-it-2));
			it--;
		}
		file[name1.substr(0,it)].push(x);
		DEBUG(file[name1.substr(0,it)].size());
	}
	else{
		file[name1].push(0);
		DEBUG(file[name1].size());
	}
	return name1;
}
int main(){
/*	freopen("input.txt","r",stdin);	
	freopen("output.txt","w",stdout);	*/
	int q;
	cin >> q;
	REP(I, q){
		string cmd, name1, name2;
		cin >> cmd;
		if(cmd == "crt"){
			cin >> name1;
			cout << "+ " << crt(name1) << endl;
		}
		else if(cmd == "del"){
			cin >> name1;
			cout << "- " << del(name1) << endl; 
		}
		else{
			cin >> name1 >> name2;
			cout << "r " << del(name1) << " -> " << crt(name2) << endl; 
		}
	}
}