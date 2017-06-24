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

def dfs(graph, start, path=[]):
  q=[start]
  while q:
    v=q.pop(0)
    if v not in path:
      path=path+[v]
      q=graph[v]+q
  return path

def bfs(graph, start, path=[]):
  q=[start]
  while q:
    v=q.pop(0)
    if not v in path:
      path=path+[v]
      q=q+graph[v]
  return path

