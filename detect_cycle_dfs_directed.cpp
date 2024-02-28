#include<bits/stdc++.h>
using namespace std;
vector<int> v[1005];
bool vst[1005];
bool pathVisit[1005];
int ans;
void dfs(int parent)
{
    vst[parent]= true;
    pathVisit[parent]= true;
    for(int child: v[parent])
    {
        if(pathVisit[child])
        {
            ans = true;
        }
        if(!vst[child])
        {
            dfs(child);
        }
    }
    // work done. now make the path visit false
    pathVisit[parent]=false;
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
    }
    memset(vst,false,sizeof(vst));
    memset(pathVisit,false,sizeof(pathVisit));
    ans=false;
    for(int i=0; i<n; i++)
    {
        if(!vst[i])
        {
            dfs(i);
        }
    }
    if (ans) cout<<"Cycle Detected!"<<endl;
    else cout<<"No Cycle Detected!"<<endl;
    return 0;
}

/* to detect cycle in undirected graph we need to track 
parent of the child by a parent array. but in directed graph
we need to track the visiting path by a path visit array*/