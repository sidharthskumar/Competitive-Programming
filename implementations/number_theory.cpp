// Number theoritic functions 
//pow mod
int powmod (int a, int b, int m) {
    int res = 1;
    while (b > 0)
        if (b & 1) {
            res = (res * a) % m;
            --b;

        }
        else {
            a = (a * a) % m;
            b >>= 1;

        }
    return res % m;

}

int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    return g == 1 ? mod(x,m) : -1;
}
 
int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1;
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

//primes < 1000
int primes[] = {
     2 ,    3  ,   5  ,   7  ,  11  ,  13  ,  17  ,  19  ,  23  ,  29  ,  31  ,  37 ,
    41  ,  43  ,  47  ,  53  ,  59  ,  61  ,  67  ,  71  ,  73  ,  79  ,  83  ,  89 ,
    97  , 101  , 103  , 107  , 109  , 113  , 127  , 131  , 137  , 139  , 149  , 151 ,
   157  , 163  , 167  , 173  , 179  , 181  , 191  , 193  , 197  , 199  , 211  , 223 ,
   227  , 229  , 233  , 239  , 241  , 251  , 257  , 263  , 269  , 271  , 277  , 281 ,
   283  , 293  , 307  , 311  , 313  , 317  , 331  , 337  , 347  , 349  , 353  , 359 ,
   367  , 373  , 379  , 383  , 389  , 397  , 401  , 409  , 419  , 421  , 431  , 433 ,
   439  , 443  , 449  , 457  , 461  , 463  , 467  , 479  , 487  , 491  , 499  , 503 ,
   509  , 521  , 523  , 541  , 547  , 557  , 563  , 569  , 571  , 577  , 587  , 593 ,
   599  , 601  , 607  , 613  , 617  , 619  , 631  , 641  , 643  , 647  , 653  , 659 ,
   661  , 673  , 677  , 683  , 691  , 701  , 709  , 719  , 727  , 733  , 739  , 743 ,
   751  , 757  , 761  , 769  , 773  , 787  , 797  , 809  , 811  , 821  , 823  , 827 ,
   829  , 839  , 853  , 857  , 859  , 863  , 877  , 881  , 883  , 887  , 907  , 911 ,
   919  , 929  , 937  , 941  , 947  , 953  , 967  , 971  , 977  , 983  , 991  , 997 ,
  };

vl fast_sieve(ll N) {
    ll lp[N+1];
    vector<ll> pr;

    for (ll i=2; i<=N; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
      }
      for (ll j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
        lp[i * pr[j]] = pr[j];
    }
    return pr;
}
inline void smallestPrime(int N)
{
    for (int i=2; i<=N; i++)
    { 
        if (!prime[i])
        { 
            s[i] = i;
            for (int j=2*i; j<=N; j+=i)
            {
                prime[j] = 1;
                s[j] = i;
            }
        }
    }
}


vl simpleSieve(int limit)
{
    bool mark[limit];
    memset(mark, true, sizeof(mark));
    vl result;
    for (ll p=2; p*p<=limit; p++)
    {
        if (mark[p] == true)
        {
            for (ll i=p*2; i<=limit; i+=p)
                mark[i] = false;
        }
    }

    for (ll p=2; p<limit; p++)
        if (mark[p] == true)
            result.pb(p);

    return result;
}

void segmentedSieve(int n)
{
    int limit = floor(sqrt(n))+1;
    vector<int> prime;  
    simpleSieve(limit, prime); 
    int low  = limit;
    int high = 2*limit;
 
    while (low < n)
    {
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
 
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }
 
        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                cout << i << "  ";
        low  = low + limit;
        high = high + limit;
        if (high >= n) high = n;
    }
}

//euler function
//phi(ab) = phi(a)*phi(b) -if a and b are co prime 
// a ^ (phi(m)) % m = 1 where a and m are co prime
int phi (int n) {
    int result = n;
    for (int i=2; i*i<=n; ++i)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;

        }
    if (n > 1)
        result -= result / n;
    return result;

}


int discrete_log (int a, int b, int m) {
    int n = (int) sqrt (m + .0) + 1;

    int an = 1;
    for (int i=0; i<n; ++i)
        an = (an * a) % m;

    map<int,int> vals;
    for (int i=1, cur=an; i<=n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;

    }

    for (int i=0, cur=b; i<=n; ++i) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - i;
            if (ans < m)
                return ans;

        }
        cur = (cur * a) % m;

    }
    return -1;

}





