def sieve(limit):
    a = [True] * limit                          # Initialize the primality list
    a[0] = a[1] = False
    l = []
    for (i, isprime) in enumerate(a):
        if isprime:
            l.append(i)
            for n in xrange(i*i, limit, i):     # Mark factors non-prime
                a[n] = False
    return l

t = input()
for i in range(t):
	k = input()
	primes = sieve(1000)
	num = 30
	count = 0
	while(count != k):
		n,c,ind = num,0,0
		while(c < 3 and ind < len(primes) and primes[ind] <= n):
			if(n % primes[ind] == 0):
				c+=1
				while(n % primes[ind] == 0):
					n /= primes[ind]
			else :
				ind+=1
		if(c==3) :
			count+=1
		num+=1  
	print num-1
