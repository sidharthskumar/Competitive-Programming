#include <bits/stdc++.h>

using namespace std;
const long long limit = 1200000000;
bitset<limit> mark;
long long cum = 2;
long long cnt = 0;
long long num;
void segmented_sieve()
{ 
  int sqrt = (int) std::sqrt(limit);
  int segment_size = sqrt;

  long long count = (limit < 2) ? 0 : 1;
  long long s = 3;
  long long n = 3;

  // generate small primes <= sqrt
  std::vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  // vector used for sieving
  std::vector<char> sieve(segment_size);
  std::vector<int> primes;
  std::vector<int> next;

  for (long long low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    long long high = std::min(low + segment_size - 1, limit);

    // add new sieving primes <= sqrt(high)
    for (; s * s <= high; s += 2)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    
    // sieve the current segment
    for (std::size_t i = 0; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low]) // n is a prime
      {
        mark[n]=1;
      }      
    }   
}


int main()
{  
    cin>>num;
    segmented_sieve();
   

    long long ind = 3;
    while(1)
    {
        if(mark[ind])
        {
            if(cum + ind <= num)
            {
                cum += ind;
                if(mark[cum])
                {
                    cnt++;
                }
            }
            else
            {
                break;
            }
    
         }
         ind++;
    }
    cout<<cnt;
    return 0;
}
