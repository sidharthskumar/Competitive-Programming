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
