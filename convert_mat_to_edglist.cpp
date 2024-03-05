// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin>>n;
//     int mat[n][n];
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             cin>> mat[i][j];
//         }
//     }
//     vector<pair<int,int>> edgeList;
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(mat[i][j]==1 && i!=j)
//             {
//                 edgeList.push_back({i,j});
//             }
//         }
//     }
//     for(pair<int,int> p: edgeList)
//     {
//         cout<<p.first<<" "<<p.second<<endl;
//     }
//     return 0;
// }

//convert mat to edge list with cost
#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int u,v,c;
    Edge(int u,int v, int c)
    {
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>> mat[i][j];
        }
    }
    vector<Edge> edgeList;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j]>0)
            {
                edgeList.push_back(Edge(i,j,mat[i][j]));
            }
        }
    }
    for(Edge e:edgeList)
    {
        cout<<e.u<<" "<<e.v<<" "<<e.c<<endl;
    }
    return 0;
}