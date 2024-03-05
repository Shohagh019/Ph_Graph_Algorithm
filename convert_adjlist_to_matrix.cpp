// convert adj list(without cost) to matrix 
// #include<bits/stdc++.h>
// using namespace std;
// void convert_adjlist_mat(int n, vector<int> adj[])
// {
//     int mat[n][n];
//     memset(mat,0,sizeof(mat));
//     for(int i=0; i<n; i++)
//     {
//         for(int ed: adj[i])
//         {
//             mat[i][ed] = 1;
//         }
//     }
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             cout<<mat[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     int n,e;
//     cin>>n>>e;
//     vector<int> adj[n];
//     while(e--)
//     {
//         int a,b;
//         cin>>a>>b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }
//     convert_adjlist_mat(n,adj);
//     return 0;
// }

// convert adj list(with cost) to matrix 
#include<bits/stdc++.h>
using namespace std;
void convert_adj_to_mat(int n, vector<pair<int,int>> adj[])
{
    int mat[n][n];
    memset(mat,-1, sizeof(mat));
    for(int i=0; i<n; i++)
    {
        for(pair<int,int> p: adj[i])
        {
            mat[i][p.first]= p.second;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    vector<pair<int,int>> adj[n];
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
    }
    convert_adj_to_mat(n,adj);
    return 0;
}