#include<bits/stdc++.h>
using namespace std;
bool vst[1005];
int parent[1005];
bool ans;
vector<int> v[1005];
void dfs(int s)
{
    vst[s] = true;
    for(int child: v[s])
    {
        if(vst[child] && parent[s]!=child)
        {
            ans = true;
        }
        if(!vst[child])
        {
         
            parent[child] = s;
            dfs(child);
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
            dfs(i);
        }
    }
    if(ans) cout<<"Cycle Detected!"<<endl;
    else cout<<"No Cycle Detected"<<endl;
    return 0;
}