/*********************************************************************************************/
/*  			             		Harsh Agarwal                                    */
/*				         Template taken from Adarsh Pugalia 					 			 */
/*     https://github.com/adarshpugalia/Competitive-Programming/blob/master/template.cpp     */
/*********************************************************************************************/

#include <bits/stdc++.h>

/* Data types and structures. */
#define ll long long int
#define llu long long int unsigned
#define vi vector <int>
#define vl vector <ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vpii vector <pii >
#define vpll vector <pll >

/* Data structure helpers. */
#define f first
#define s second
#define pb push_back
#define pob pop_back
#define mp make_pair
#define sz(n) (int)n.size()-1
#define all(n) n.begin(), n.end()
#define has(it,s) if(it!=s.end())

/* Input output defines. */
#define sd(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define slf(n) scanf("%lf", &n)
#define pd(n) printf("%d", n);
#define pl(n) printf("%lld", n);
#define plf(n) printf("%0.9lf", n);
#define ps printf(" ")
#define pe printf("\n")

/* loops */
#define rep(i,j,k) for(int i=j; i<=k; i++)
#define repd(i,j,k) for(int i=j; i>=k; i--)
#define iter(it, s) for(auto it=s.begin(); it!=s.end(); it++)

/* constraints. */
#define max_size 100005
#define max_sieve_size 1000005
#define max_matrix_size 100
#define max_log 17
#define INF 1000000000000000000
#define MOD 1000000007
#define EPS 0.0000000001
#define GCD_EPS 0.0001
#define PI 3.14159265358979323846
#define mod(a) ((a)%MOD)
#define bcnt __builtin_popcount

/* General maths functions. */
ll ciel(double a) { ll ret = a; if(a-ret>EPS) ret++; return ret; }
ll gcd(ll a, ll b) { if(a<b)return gcd(b, a); if(a%b==0)return b; return gcd(b, a%b); }
double fgcd(double a, double b) { if(fabs(a)<fabs(b)) return fgcd(b, a); if(fabs(b)<GCD_EPS) return a; return fgcd(b, fmod(a,b)); }

/* This method compares whether two doubles are (almost) equal. */
bool db_db_cmp(double a, double b) { return (a+EPS>b && a-EPS<b); }

/* This method generates modular factorials. */
#define max_fact_size 100005
ll fact[max_fact_size];
void generate_factorials() { fact[0] = fact[1] = 1; rep(i,2,max_fact_size-1) fact[i] = mod(fact[i-1]*i); }

/* This method does modular exponentiation in log(n). */
ll mod_pow(ll n, ll p) {if(p==0)return 1; if(n<=1)return n;ll res = 1;while(p){if(p&1) res = mod(res*n);n = mod(n*n);p /= 2;} return res;}

/* This method returns the modular inverse of a number (MOD must be prime). */
ll get_inverse(ll n) { return mod_pow(n, MOD-2);}

/* This method return nCr modulo MOD. */
ll get_nCr(ll n, ll r) { return mod(fact[n]*get_inverse(mod(fact[r]*fact[n-r]))); }

/* End of maths functions. */
using namespace std;

int main(int argc, char *argv[])
{
    ll testcases;
	int n,m,d,D;
	cin>>testcases;
	while (testcases--) {
	    cin>>n>>m>>d>>D;
		if(d>n){cout<<-1<<endl;}
		else if(d==n && m>n*n){
			cout<<-1<<endl;
		}
		else {
		if(d*n <= m && m <= D*n){
			int lop = m/n;
			int rem = m%n;
			int offset = 0;
			for (int i=0; i < lop; i++) {
				for(int j=1;j<=n;j++){
					if(j+offset == n)
						cout<<j<<" "<<n<<endl;
					else
						cout<<j<<" "<<(j+offset)%n<<endl;

				}
				offset++;
			}
			//	cout<<"h h h"<<endl;
			for(int j=1;j<=rem;j++){
					if(j+offset == n)
						cout<<j<<" "<<n<<endl;
					else
						cout<<j<<" "<<(j+offset)%n<<endl;	   		}
		}

		else{
			cout<<"-1\n";
		}
		}
	}
    return 0;
}



