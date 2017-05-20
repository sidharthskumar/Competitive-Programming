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


/****** Template of some basic operations *****/
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
/**********************************************/




/****** Template of Fast I/O Methods *********/
template <typename T> inline void write(T x)
{
 int i = 20;
 char buf[21];
 // buf[10] = 0;
 buf[20] = '\n';




 do
 {
  buf[--i] = x % 10 + '0';
  x/= 10;
 }while(x);
 do
 {
  putchar(buf[i]);
 } while (buf[i++] != '\n');
}




template <typename T> inline T readInt()
{
 T n=0,s=1;
 char p=getchar();
 if(p=='-')
  s=-1;
 while((p<'0'||p>'9')&&p!=EOF&&p!='-')
  p=getchar();
 if(p=='-')
  s=-1,p=getchar();
 while(p>='0'&&p<='9') {
  n = (n<< 3) + (n<< 1) + (p - '0');
  p=getchar();
 }




 return n*s;
}
/************************************/








/**************************************/



LLI fast_exp(int base, int exp ,int mod=MOD) {
    LLI res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}




/******** User-defined Function *******/

/**************************************/








/********** Main()  function **********/
int main()
{
  freopen("A-large.in","r",stdin);
  freopen("out1.txt","w",stdout);
  LLI t;
  cin>>t;
  REPL(a,t)
  {
    string s;
    LLI k;
    cin>>s>>k;
    LLI n = s.length();
    LLI ans = 0;
    int flag = 0;
    LLI ind = 0;
    while(ind < n)
    {
      while(s[ind]=='+')
          ind++;
      if(ind==n) break;
      else if(n - ind < k)
      {
          flag = 1;
          break;
      }
      else
      {
          FORL(i,ind,ind+k,1)
          {
            if(s[i] == '+')
              s[i] = '-';
            else
              s[i] = '+';
          }
      }
      ans += 1;
    }
      if(flag)
        cout<<"Case #"<<(a+1)<<": IMPOSSIBLE"<<endl;
      else
        cout<<"Case #"<<(a+1)<<": "<<ans<<endl; 
  }
  

    
}