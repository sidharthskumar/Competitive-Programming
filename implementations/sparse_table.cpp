ll M[maxn][20];
ll A[maxn];
ll ans[maxn];
void build(int N)
{
      ll i, j;
   
      for (i = 0; i < N; i++)
          M[i][0] = i;
      for (j = 1; 1 << j <= N; j++)
          for (i = 0; i + (1 << j) - 1 < N; i++)
              if (A[M[i][j - 1]] > A[M[i + (1 << (j - 1))][j - 1]])
                  M[i][j] = M[i][j - 1];
              else
                  M[i][j] = M[i + (1 << (j - 1))][j - 1];
}  

ll query(int i, int j)
{
    ll k = floor(log2(j-i+1));
    ll ind = j-(ll) pow(2,k) + 1;
    if(A[M[i][k]] >= A[M[ind][k]]) return M[i][k];
    else return M[ind][k];
}

