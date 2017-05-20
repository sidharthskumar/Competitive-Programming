#include<bits/stdc++.h>

using namespace std;




/*******  All Required define Pre-Processors and typedef Constants *******/

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)

#define REP(i, j) FOR(i, 0, j, 1)

#define MP make_pair
#define PB push_back
#define INF (int)1e9

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

struct abc
{
    LLI a;
    LLI b;
    LLI c;
};



/********** Main()  function **********/
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n;
        scanf("%d",&n);
        VLII numbers;
        REP(i,n)
        {
            LLI x,y;
            scanf("%I64d %I64d",&x,&y);
            numbers.PB(MP(x,y));
        }
        int flag=0;
        abc coef[n][n];
        FOR(i,0,n-1,1)
        {
            FOR(j,i+1,n,1)
            {
                coef[i][j].a = (numbers[j].S - numbers[i].S);
                coef[i][j].b = (numbers[j].F - numbers[i].F);
                coef[i][j].c= numbers[i].S * (numbers[j].F - numbers[i].F) - numbers[i].F * (numbers[j].S - numbers[i].S);
            }
        }
        FOR(i,0,n-1,1)
        {
            FOR(j,i+1,n,1)
            {
                LLI count=0;
                REP(k,n)
                {
                    if(coef[i][j].a * numbers[k].F - coef[i][j].b * numbers[k].S + coef[i][j].c == 0) count++;

                }
                if(count == 2) {flag=1;break;}

            }
        }
        if(flag) printf("yes\n");
        else printf("no\n");

    }
}
