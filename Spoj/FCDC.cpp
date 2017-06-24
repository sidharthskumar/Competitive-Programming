#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vf vector<float>
#define vs vector<string>
#define vl vector<ll>

#define loop(i, a, b, x) for(ll i = a;i <b; i += x)
#define f(i,a,b) loop(i,a,b,1)
#define rep(i,n) f(i,0,n)
#define repv(i,a) rep(i,a.size()) 
#define loopr(i,a,b,x) for(ll i = a; i>=b;i--)
#define fr(i,a,b) loopr(i,a,b,1)
#define repr(i,n) fr(i,n-1,0)
#define repvr(i,a) repr(i,a.size())
#define mem(a,b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SORT(v) sort(v.begin(),v.end());
#define inc(A, B, C)  A <= B && B <= C

/* user define functions specific to problem */
template <typename T>
T gcd(T a, T b) {
  T r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

bitset<10000001> simpleSieve()
{
  bitset<10000001> mark;
  mark.flip();
  // One by one traverse all numbers so that their
  // multiples can be marked as composite.
  for (ll p=2; p*p<10000001; p++)
  {
      // If p is not changed, then it is a prime
      if (mark[p])
      {
          // Update all multiples of p
          for (ll i=p*2; i<10000001; i+=p)
              mark[i] = 0;
      }
  }

  return mark;
}

/* solve here */
void solve()
{
  ll a,b;
  bitset<10000001> sieve = simpleSieve();
  cin>>a>>b;
  ll prod1 = a;
  ll prod2 = b;
  ll num = 2;
  while(prod1  != 1)
  {
    prod1 /= gcd(num,prod1);
    if(sieve[prod1] && num < prod1){
      num = prod1+1; 
      break;
    }
    num++;
  }
  ll num1 = 2;
  while(prod2 != 1)
  {
    prod2 /= gcd(num1,prod2);
    if(sieve[prod2] && num1 < prod2){
      num1 = prod2 + 1;
      prod2 ;
      break;
    }
    num1++;
  }
  if(num1 > num)cout<<num1-num<<endl;  
  else cout<<0<<endl;
      
}


/* main function */

int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 

  solve();

  return 0;
}