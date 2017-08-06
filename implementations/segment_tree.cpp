class RMQ {
    vll M;
    vll A;
    ll N;
    RMQ(ll arr[], ll arrsz)
    {
        A.resize(maxn);
        rep(i,0,arrsz-1) A[i] = arr[i];
        N = arrsz;
        build(1,0,N-1);
    }
    RMQ(vll &arr)
    {
        M.resize(4*maxn);
        A.resize(maxn);
        A = arr;
        N = A.size();
        build(1,0,N-1);
    }
    void build(ll node, ll b, ll e)
    {
          if (b == e)
              M[node] = b;
          else
           {
              build(2 * node, b, (b + e) / 2, M, A, N);
              build(2 * node + 1, (b + e) / 2 + 1, e, M, A, N);
              if (A[M[2 * node]] <= A[M[2 * node + 1]])
                  M[node] = M[2 * node];
              else
                  M[node] = M[2 * node + 1]; 
          }
    }

    ll query(ll node, ll b, ll e, ll i, ll j)
    {
          int p1, p2;
       
          if (i > e || j < b)
              return -1;
       
          if (b >= i && e <= j)
              return M[node];
       
          p1 = query(2 * node, b, (b + e) / 2, M, A, i, j);
          p2 = query(2 * node + 1, (b + e) / 2 + 1, e, M, A, i, j);
       
          if (p1 == -1)
              return M[node] = p2;
          if (p2 == -1)
              return M[node] = p1;
          if (A[p1] <= A[p2])
              return M[node] = p1;
          return M[node] = p2;
    }

    ll getMin(ll l, ll r)
    {
        return query(1,0,N-1,l,r);
    }
};
