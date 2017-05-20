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

LLI s,t;


LLI mod(LLI a, LLI b)
{ return (a%b+b)%b; }

int main()
{
  LLI n;
  cin>>n>>s>>t;
  LLI r0 , g, sd, p;
  cin>>r0>>g>>sd>>p;
  VLLI r;
  r.push_back(r0);
  REPL(i,n-1){
   r.push_back((r[r.size()-1] *g + sd)%p);  
  }
  queue<LLI> Q;
  bool flag = false;
  VLLI distances(n,0);
  vector<bool> V(n,false);
  Q.push(s);
  V[s] = true;
  while(Q.size())
  {
      REPL(i,n)
        cout<<distances[i]<<" ";
      cout<<endl;      
      int i = Q.front();
      if(i == t) {
        flag = true;
        cout<<distances[i]<<endl;
        break;
      }
      else {
        Q.pop();
        FORL(j,1,r[i]+1,1){
          if(r[mod(i- j,n)] && !V[mod(i- j,n)]) {
              Q.push(mod(j- i,n));
              V[mod(i- j,n)] = true;
              distances[mod(i- j,n)] = distances[i] + 1;
          }

          if(r[mod(j + i,n)] && !V[mod(j + i,n)]) {
              Q.push(mod(j + i,n));
              V[mod(j + i,n)] = true;
              distances[mod(j + i,n)] = distances[i] + 1;
          }    

        }        
    }
  }


  if(!flag) 
  {
    cout<<-1<<endl;
  }
  
  return 0;
}