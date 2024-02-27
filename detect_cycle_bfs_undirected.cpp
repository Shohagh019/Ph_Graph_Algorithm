#include<bits/stdc++.h>
using namespace std;
bool vst[1005];
int parent[1005];
bool ans;
vector<int> v[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vst[src] = true;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        cout << par << endl;
        for(int child: v[par])
        {
            if(vst[child] && child != parent[par])
            {
                ans=true;
            }
            if(!vst[child])
            {
                vst[child] = true;
                parent[child] = par; // update parent array
                q.push(child);
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vst,false,sizeof(vst));
    memset(parent,-1,sizeof(parent));
    ans = false;
    for(int i=0; i<n; i++)
    {
        if(!vst[i])
        {
            bfs(i);
        }
    }
    if(ans) cout<<"Cycle Detected!"<<endl;
    else cout<<"NO Cycle Detected!"<<endl;
    return 0;
}