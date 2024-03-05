// // convert matrix to adj list(without cost)
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
//             cin>>mat[i][j];
//         }
//     }
//     vector<int> adj[n];
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(mat[i][j]==1)
//             {
//                 adj[i].push_back(j);
//             }
            
//         }
//     }
//     for(int i=0; i<n; i++)
//     {
//         cout<<i<<"->";
//         for(int e: adj[i])
//         {
//             cout<<e<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// convert matrix to adj list(with cost)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<pair<int,int>> adj[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(mat[i][j]>0)
            {
                adj[i].push_back({j,mat[i][j]});
            }
            
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<i<<"->";
        for(pair<int,int> p: adj[i])
        {
            cout<<p.first<<" "<<p.second<<" ";
        }
        cout<<endl;
    }
    return 0;
}