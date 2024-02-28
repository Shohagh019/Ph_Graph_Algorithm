#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<pair<int,int>> v[1005];
int dst[N];
void dijkstra(int src)
{
    queue<pair<int,int>> q;
    q.push({src,0});
    dst[src]= 0;
    while(!q.empty())
    {
        pair<int,int> parent = q.front();
        q.pop();
        int parentNode = parent.first;
        int parentCost = parent.second;
        
        for(pair<int,int> child:v[parentNode])
        {
            int childNode= child.first;
            int childCost= child.second;
            if(parentCost+ childCost < dst[childNode])// path relaxation
            {
                dst[childNode] = parentCost+childCost; // distance of child update
                q.push({childNode, dst[childNode]});
            }
        } 
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0; i<e; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=0; i<n; i++)
    {
        dst[i]= INT_MAX;
    }
    dijkstra(0);
    for(int i=0; i<n; i++)
    {
        cout<<i<<" ->"<<" "<<dst[i]<<endl;
    }
    return 0;
}