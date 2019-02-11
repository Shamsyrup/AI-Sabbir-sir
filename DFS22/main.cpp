#include<iostream>
using namespace std;
#define Discover 1
#define Visited 2
#define Finished 3
int INF=310000,NIL=-1;
int num_v,num_e,time=0;
int adj[20][20],State[20],p[20],d[20],f[20];
void DFS_visit(int);

void build_adj_matrix()
{
    int i,a,b;
    cout<<"Vertices : "<<endl;
    cin>>num_v;
    cout<<"No of edges: "<<endl;
    cin>>num_e;
    cout<<"Enter the edges: "<<endl;
    for(i=1; i<=num_e; i++)
    {
        cin>>a>>b;
        adj[a][b]=1;
    }
}
void dfs()
{
    int i,u;
    for(i=1; i<=num_v; i++)
    {
        State[i]=Discover;
        p[i]=NIL;
    }
    for(u=1; u<=num_v; u++)
    {
        if(State[u]==Discover)
        {
            DFS_visit(u);
        }
    }
}
void DFS_visit(int u)
{
    int i,v;
    State[u]=Visited;
    time=time+1;
    d[u]=time;
    for(v=1; v<=num_v; v++)
    {
        if(adj[u][v]==1)
        {
            if(State[v]==Discover)
            {
                p[v]=u;
                DFS_visit(v);
            }
        }
    }
    State[u]=Finished;
    time=time+1;
    f[u]=time;
}
void distance_output()
{
    int i;
    cout<<"Discovery and Finish D/F:\n";
    for(i=1; i<=num_v; i++)
    {
        cout<<"Node "<<i<<" is "<<d[i]<<"/"<<f[i]<<" \n";
    }
}
int main()
{

    build_adj_matrix();
    dfs();
    distance_output();
    return 0;
}

