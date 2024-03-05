// // convert edge list(without cost) to mat
// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n,e;
//     cin>>n>>e;
//     int mat[n][n];
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             if(i==j) mat[i][j] = 1;
//             else mat[i][j]=0;
//         }
//     }
//     while(e--)
//     {
//         int a,b;
//         cin>>a>>b;
//         mat[a][b]=1;
//         mat[b][a]=1;
//     }
//     for(int i=0; i<n; i++)
//     {
//         for(int j=0; j<n; j++)
//         {
//             cout<<mat[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }

// convert edge list(wit cost) to mat
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,e;
    cin>>n>>e;
    int mat[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i==j) mat[i][j] = 0;
            else mat[i][j]=-1;
        }
    }
    while(e--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        mat[a][b]=c;
        mat[b][a]=c;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}