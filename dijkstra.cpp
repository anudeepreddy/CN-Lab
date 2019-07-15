#include<iostream>
#include<limits.h>
using namespace std;
void dijkstra(int n,void *vgraph,int src){
    int *graph[n];
    for(int i=0;i<n;i++)
    graph[i] = (int *)vgraph+n*i;
    /*for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)
    cout<<graph[i][j]<<" ";
    cout<<endl;}*/
    bool isIncluded[n];
    int dist[n],v,min=INT_MAX;
    for(int i=0;i<n;i++){
        dist[i] = INT_MAX;
        isIncluded[i] = false;
    }
    dist[src] = 0;
    for(int _=1;_<n;_++){
        min = INT_MAX;
        for(int i=0;i<n;i++){
            if(isIncluded[i]==false && dist[i]<min){
                v=i;
                min=dist[i];
            }
        }
        isIncluded[v] = true;
        for(int i=0;i<n;i++){
            if(!isIncluded[i] && graph[v][i] && graph[v][i]!=INT_MAX && dist[v]+graph[v][i]<dist[i])
                dist[i]=dist[v]+graph[v][i];
        }
    }
    cout<<"\nShortest Distance:\n";
    cout<<"Source\n";
    cout<<"  "<<src<<"   |  ";
    for(int i=0;i<n;i++){
        if(i!=src)
        cout<<dist[i]<<" ";
    }
}
int main(){
    int n,src;
    cout<<"Enter number of vertices in the graph:";
    cin>>n;
    int graph[n][n];
    cout<<"Enter the graph:";
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    cout<<"Enter the source vertex:";
    cin>>src;
    dijkstra(n,graph,src);
}



/*

{0, 4, 0, 0, 0, 0, 0, 8, 0},
{4, 0, 8, 0, 0, 0, 0, 11, 0},
{0, 8, 0, 7, 0, 4, 0, 0, 2},
{0, 0, 7, 0, 9, 14, 0, 0, 0},
{0, 0, 0, 9, 0, 10, 0, 0, 0},
{0, 0, 4, 14, 10, 0, 2, 0, 0},
{0, 0, 0, 0, 0, 2, 0, 1, 6},
{8, 11, 0, 0, 0, 0, 1, 0, 7},
{0, 0, 2, 0, 0, 0, 6, 7, 0}


 */