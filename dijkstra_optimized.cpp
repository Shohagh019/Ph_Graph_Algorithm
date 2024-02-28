#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> v[1005];
int dst[1005];
class cmp
{
    public:
    bool operator()(pair<int,int> a, pair<int,int> b)
    {
        return a.second> b.second;
    }
};
void dijkstra(int src)
{
    // priority_queue<int,vector<int>> pq--- structure of priority queue
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq; // priority queue with custom compare class
    pq.push({src,0});
    dst[src]=0;
    while(!pq.empty())
    {
        pair<int,int> parent= pq.top();
        pq.pop();
        int parentNode=parent.first;
        int parentCost= parent.second;
        for(pair<int,int> child: v[parentNode])
        {
            int childNode= child.first;
            int childCost= child.second;
            if(parentCost+childCost< dst[childNode])
            {
                dst[childNode]= parentCost+ childCost;
                pq.push({childNode, dst[childNode]});
            }
        }
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    for(int i=0; i<n; i++)
    {
        dst[i]=INT_MAX;
    }
    dijkstra(0);
    for(int i=0; i<n; i++)
    {
        cout<<i<<"->"<<dst[i]<<endl;
    }
    return 0;
}