void bfs(vector< vector<int> > g, int n, int s,int to)
{
    queue<int> q;
    q.push(s);
    vector<bool> used(n);
    vector<int> d(n), p(n);
    used[s] = true;
    p[s] = -1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for(int i=0;i < g[v].size();i++)
        {
            int to = g[v][i];
            if(!used[to])
            {
                used[to] = true;
                q.push(to);
                d[to] = d[v]+1;
                p[to] = v;
            }
        }
    }

    /* shortest path in an unweighted graph is distance*/
    //Exact path can be obtained by backtracing
    if(!used[to])
    {
        cout<<"No path"<<endl;
    }
    else
    {
        vector<int> path;
        for(int v= to; v != -1; v = p[v])
        {
            path.push_back(v);
        }
        reverse(path.begin(),path.end());
        cout<<"Path: ";
        for(int i=0; i < path.size();i++)
            cout<<path[i] + 1<<" ";
    }
    
}

//make global vec bool used
void dfs(vector< vector<int> > g, int n, int v)
{
    
    used[v] = true;
    for(vector<int> :: iterator i = g[v].begin(); i != g[v].end(); i++)
    {
        if(!used[*i])
            dfs(g,n,*i);
    }
}

class UnionFind
{

public:
        struct subset
        {
            int parent;
            int rank;
        };
        subset* subsets;

        UnionFind(int n)
        {
            subsets = new subset[n];
            for(int i = 0; i < n; i++)
            {
                subsets[i].parent = i;
                subsets[i].rank = 0;
            }
        }

        int find(int i)
        {
            if (subsets[i].parent != i)
                subsets[i].parent = find(subsets[i].parent);
            return subsets[i].parent;

        }

        void Union(int x, int y)
        {
            int xroot = find(x);
            int yroot = find(y);

            if (subsets[xroot].rank < subsets[yroot].rank)
                subsets[xroot].parent = yroot;
            else if (subsets[xroot].rank > subsets[yroot].rank)
                subsets[yroot].parent = xroot;

            else
            {
                subsets[yroot].parent = xroot;
                subsets[xroot].rank++;
            }
        }
};


