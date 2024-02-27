#include<bits/stdc++.h>
using namespace std;
int a[20][20];
bool vst[20][20];
int n,m;
bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}
vector<pair<int,int>> v={{0,1},{0,-1},{-1,0},{1,0}};
void dfs(int s, int j)
{
    cout<<a[s][j]<<endl;
    vst[s][j] = true;
    for(int i=0; i<4; i++)
    {
        int ci=s+v[i].first;
        int cj=j+v[i].second;
        if(valid(ci,cj) && !vst[ci][cj])
        {
            dfs(ci,cj);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            vst[i][j]=false;
        }
    }
    int si,sj;
    cin>>si>>sj;
    dfs(si,sj);
    return 0;
}