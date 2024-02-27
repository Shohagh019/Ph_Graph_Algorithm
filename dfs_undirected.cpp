#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int> v[N];
bool vst[N];
void dfs(int s)
{
    cout<<s<<" ";
    vst[s]=true;
    for(int child: v[s])
    {
        if(!vst[child])
        {
            dfs(child);
            vst[child]=true;
        }

    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vst,false,sizeof(vst));
    int src;
    cin>>src;
    dfs(src);
    return 0;
}