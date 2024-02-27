#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100][100];
bool vst[100][100];
int dst[100][100];
bool valid(int i, int j)
{
    if(i<0 || i>=n || j<0 || j>=m) return false;
    return true;
}
vector<pair<int,int>> v={{0,1},{0,-1},{-1,0},{1,0}};
void bfs(int si, int sj)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    vst[si][sj] = true;
    dst[si][sj] = 0;
    while(!q.empty())
    {
        pair<int,int> par = q.front();
        q.pop();
        int pi= par.first;
        int pj = par.second;
        cout<<a[pi][pj]<<endl;
        for(int i=0; i<4; i++)
        {
            int ci= pi+v[i].first;
            int cj =pj+v[i].second;
            if(valid(ci, cj) && !vst[ci][cj])
            {
                q.push({ci,cj});
                vst[ci][cj]=true;
                dst[ci][cj] = dst[pi][pj]+1;
            }
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
    memset(vst,false,sizeof(vst));
    memset(dst,-1,sizeof(dst));
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
    cout<<dst[3][4]<<endl;
    return 0;
}