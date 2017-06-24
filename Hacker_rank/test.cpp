#include <iostream>


#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;




/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define FORL(i, j, k, in) for (LLI i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REPL(i, j) FORL(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define SORT(v) sort(v.begin(),v.end());
#define IN(A, B, C) assert( B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define F first
#define S second
const double pi=acos(-1.0);
typedef long int LI;
typedef unsigned long int ULI;
typedef long long int LLI;
typedef unsigned long long int  ULLI;
typedef long  double LLD;
typedef vector<LLI> VLLI;
typedef pair<int, int> PII;
typedef pair<LLI , LLI> PLII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<PLII> VLII;
typedef vector<VI> VVI;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;

LLI n,s,t;

VLLI rr;
LLI mod(LLI a, LLI b)
{ return (a%b+b)%b; }


int inSet(LLI &min_l,LLI &max_r, LLI &t){
    if(min_l <= max_r) {
      if(min_l <= t && t <= max_r) {
        return 1;
      }
    }
    else {
        if(min_l <= t || t <= max_r) {
            return 1;
        }   
    }
    return 0;
}

int updateMinMax(LLI &min_l,LLI &max_r, LLI& ind){
	if(rr[ind] == 0)
    {
        ind = mod(ind + 1,n);
        return 0;    
    }
    LLI new_l = mod(ind - rr[ind],n) , new_r = mod(ind + rr[ind],n); 
    if(min_l <= max_r) {
  		if(new_l < min_l || new_l > max_r){
  			min_l = new_l;
  		}
        else {
            if(new_l >= ind) {
                return 1;
            }
        }
  		if(new_r < min_l || new_r > max_r){
  			max_r = new_r;
  		}
        else {
            if(new_r <= ind){
                return 1;
            }
        }
  		
  	}
  	else {
  		if(new_l < min_l && new_l > max_r) {
  			min_l = new_l;
  		}
        else {
            if(inSet(ind,max_r,new_l)) return 1;
        }
  		if(new_r < min_l && new_r > max_r) {
  			max_r = new_r;
  		}
        else {
            if(inSet(min_l,ind,new_r)) return 1; 
        }  		
  	}
  	ind = mod(ind + 1,n);

    return 0;

}

int main()
{
	  cin>>n>>s>>t;
	  LLI r0 , g, sd, p;
	  cin>>r0>>g>>sd>>p;
	  rr.push_back(r0);
	  REPL(i,n-1){
	   rr.push_back((rr[rr.size()-1] *g + sd)%p);  
	  }
      REPL(i,n){
        cout<<rr[i]<<" ";
      }
      cout<<endl;
	  int flag = 0;
	  LLI dist = 1;
	  LLI min_l = mod(s - rr[s],n), max_r = mod(s + rr[s],n);

	  LLI l = min_l, r = max_r;
	  LLI ind = l;

	  while(ind != mod(r+1,n)){
	  	if(updateMinMax(min_l,max_r,ind)){
            flag = 1;
            dist++;
            cout<<dist;
            break;
        }
	  }
        
 	  while(!flag && (l != min_l || r != max_r)){
          cout<<min_l<<" "<<max_r<<endl;
		  dist++;
		  if(inSet(min_l,max_r,t)) {
		  	flag = 1;
		  	cout<<dist<<endl;
		  	break;
		  }

		  ind = min_l;
		  LLI prev_l = min_l;
		  while(ind != l){
		  	if(updateMinMax(min_l,max_r,ind)){
                flag = 1;
                dist++;
                cout<<dist;
                break;
            }	
		  }
          l =prev_l;
		  ind = r + 1;
		  r = max_r;
		  while(ind != mod(max_r+1,n)){
		  	if(updateMinMax(min_l,max_r,ind)){
                flag = 1;
                dist++;
                cout<<dist;
                break;
            }
          }
	  }

	  if(!flag) {
		cout<<-1<<endl;
	  }

}