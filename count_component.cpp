#include <bits/stdc++.h>
using namespace std;
bool vst[1005];
vector<int> v[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vst[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        cout << par << " ";
        for (int child : v[par])
        {
            if (!vst[child])
            {
                q.push(child);
                vst[child] = true;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vst, false, sizeof(vst));
    int compo = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vst[i])
        {
            bfs(i);
            compo++;
        }
    }
    cout << endl;
    cout << compo << endl;
    return 0;
}