/*
  Template by Siddhartha Mishra(sid_m97)
*/
#include <bits/stdc++.h>

using namespace std;

#define inf 1e9
#define eps 1e-9
const double pi = acos(-1.0);
#define MOD 1000000007

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

#define ll long long
#define vi vector<int>
#define vf vector<float>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define mpii map<int,int>
#define seti set<int>
#define mseti multiset<int>

#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >

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

/* important functions */
template <typename T>
T minm(initializer_list<T> list)
{ 
  T m = numeric_limits<T>::max();
  for( auto elem : list)
  {
    if(elem < m)
      m = elem;
  }

  return m;
}

template <typename T>
T maxm(initializer_list<T> list)
{
  T m = numeric_limits<T>::min();
  for( auto elem : list)
  {
    if(elem > m)
      m = elem;
  }

  return m;
} 

template <typename T>
T mod(T a, T b)
{ return (a%b+b)%b; }

template <typename T>
T xdiv(T a, T b)
{
  if(a%b == 0) return a/b;
  else return a/b + 1;
}

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

template <typename T>
T fast_exp(T base, T exp ,T mod=MOD) {
    T res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}
template <typename T>
void prvec(T a){
  rep(i,a.size()) cout<<a[i]<<" ";
  cout<<endl;
}

int maxSubarrayXOR(int set[], int n)
{
    // Initialize index of chosen elements
    int index = 0;

    // Traverse through all bits of integer starting from
    // the most significant bit (MSB)
    for (int i=INT_BITS-1; i>=0; i--)
    {
        // Initialize index of maximum element and the maximum element
        int maxInd = index, maxEle = INT_MIN;
        for (int j=index; j<n; j++)
        {
             // If i'th bit of set[j] is set and set[j] is greater
             // than max so far.
             if ( (set[j]&(1<<i))!= 0 && set[j]>maxEle )
                maxEle = set[j], maxInd = j;
        }

        // If there was no element with i'th bit set, move to smaller i
        if (maxEle == INT_MIN)
           continue;

        // Put maximum element with i'th bit set at index 'index'
        swap(set[index], set[maxInd]);

        // Update maxInd and increment index
        maxInd = index;

        // Do XOR of set[maxIndex] with all numbers having i'th
        // bit as set.
        for (int j=0; j<n; j++)
        {
            // XOR set[maxInd] those numbers which have the i'th
            // bit set
            if ((j!=maxInd) && ((set[j] & (1<<i)) !=0))
                set[j] = set[j]^set[maxInd];
        }

        // Increment index of chosen elements
        index++;
    }

    // Final result is XOR of all elements
    int res = 0;
    for (int i=0; i<n; i++)
        res ^= set[i];
    return res;
}



/* main function */

int main() 
{
  //std::ios::sync_with_stdio(false);
  //cin.tie(0);
  //cout.tie(0);
  ll n ,m;
  cin>>n>>m;
  vl a(n);
  rep(i,n) cin>>a[i];
  rep(i,m)
  {
    vl b = a;
    ll l ,r,x;
    cin>>l>>r>>x;
    sort(b.begin()+l-1, b.begin()+r);
    if(a[x-1] == b[x-1])
      cout<<"Yes"<<endl;
    else 
      cout<<"No"<<endl;
  }
   

  return 0;
}


