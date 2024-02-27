#include<bits/stdc++.h>
using namespace std;
bool vst[1005];
int level[100];
int parent[100];
vector<int> v[1005];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vst[src] = true;
    level[src] = 1;
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        cout<<par<<"->"<<level[par]<<endl;
        for(int child: v[par])
        {
            if(!vst[child])
            {
                q.push(child);
                vst[child] = true;
                level[child] = level[par]+1; // level tracking
                parent[child] = par; // path printing
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
    int src;
    cin>>src;
    int des;
    cin>>des;
    memset(vst,false,sizeof(vst));
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    bfs(src);
    int x=des;
    vector<int>path;
    while(x!=-1)
    {
        path.push_back(x);
        x=parent[x];
    }
    reverse(path.begin(),path.end());
    cout<<"path"<<" "<<"of"<<" "<<src<<" "<<"to"<<" "<<des<<"-> ";
    for(int v:path)
    {
        cout<<v<<" ";
    }
    return 0;
}