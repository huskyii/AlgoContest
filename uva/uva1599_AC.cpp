#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<iostream>
using namespace std;

const int maxn = 100010;
vector<int> g[maxn];
vector<int> c[maxn];
int step[maxn],ans[2*maxn];
int min_[maxn];
bool vis[maxn];

void bfs1(int n)
{
    queue<int> q;
    step[n]=0;
    q.push(n);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        int sz=g[u].size();
        for(int v=0;v<sz;v++)
        {
            int vv=g[u][v];
            if(vv==1)
            {
                step[1]=step[u]+1;
                return;
            }
            if(step[vv]==-1)
            {
                step[vv]=step[u]+1;
                q.push(vv);
            }
        }
    }
    return;
}
void bfs2()
{
    memset(vis,false,sizeof(vis));
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {

        int u=q.front();q.pop();
        if(step[u]==0) return;
        int sz=g[u].size();
        int min_=-1;
        for(int i=0;i<sz;i++)
        {
            int vv=g[u][i];
            if(step[vv]==step[u]-1)
            {
                if(min_==-1)
                    min_=c[u][i];
                else
                    min_=min(min_,c[u][i]);
            }
        }
        int ttt=step[1]-step[u];
        if(ans[ttt]==0) ans[ttt]=min_;
        else
        ans[ttt]=min(min_,ans[ttt]);
        for(int v=0;v<sz;v++)
        {
            int vv=g[u][v];
            if(vis[vv]==false&&step[vv]==step[u]-1&&c[u][v]==min_)
            {
                q.push(vv);
                vis[vv]=true;
            }
        }
    }
    return;
}
int main()
{
    int n,m;
    int a,b,c1;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<maxn;i++)
            g[i].clear();
        for(int i=0;i<maxn;i++)
            c[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c1);
            if(a==b) continue;
            g[a].push_back(b);
            g[b].push_back(a);
            c[a].push_back(c1);
            c[b].push_back(c1);
        }
        memset(step,-1,sizeof(step));
        memset(ans,0,sizeof(ans));
        step[n]=-1;
        bfs1(n);
        bfs2();
        printf("%d\n",step[1]);
        for(int i=0;i<step[1];i++)
        {
            if(i) printf(" ");
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
