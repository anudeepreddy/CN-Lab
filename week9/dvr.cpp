#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of routers:";
    cin>>n;
    int subgraph[n][n],dist[n][n],from[n][n];
    cout<<"Enter the subgraphs:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>subgraph[i][j];
            subgraph[i][i]=0;
            dist[i][j]=subgraph[i][j];
            from[i][j]=j;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dist[i][j]>(dist[i][k]+dist[k][j])){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    from[i][j]=k;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<"For router "<<i+1<<"\n";
        cout<<"Dest\t\t"<<"Next Hop\t"<<"Dist\n";
        for(int j=0;j<n;j++){
            cout<<j+1<<"    \t\t"<<from[i][j]+1<<"    \t\t"<<dist[i][j]<<"\n";
        }
        cout<<"\n";
    }
}