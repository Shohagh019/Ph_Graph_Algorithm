/* bellman ford work on negative weight and it can detect negative cycle*/
#include <bits/stdc++.h>
using namespace std;
int dst[1005];
class Edge
{
public:
    int u, v, c;
    Edge(int u, int v, int c)
    {
        this->u = u;
        this->v = v;
        this->c  = c;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edgeList;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }
    for (int i = 0; i < n; i++)
    {
        dst[i] = INT_MAX;
    }
    dst[0] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (Edge e : edgeList)
        {
            int u = e.u;
            int v = e.v;
            int c = e.c;
            if (dst[u] < INT_MAX && dst[u] + c < dst[v])
            {
                dst[v] = dst[u] + c;
            }
        }
    }
    for(int i=0; i < n; i++)
    {
        cout<<i<<"->"<<dst[i]<<endl;
    }
    return 0;
}