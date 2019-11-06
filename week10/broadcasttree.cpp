#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of routers:";
    cin>>n;
    int connect[n][n];
    cout<<"Enter the range adjacency matrix[0/1]:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin>>connect[i][j];
    }
    int root;
    cout<<"Enter the router id:";
    cin>>root;
    cout<<"Routers that are in range of router "<<root<<":\n";
    for(int i=0;i<n;i++){
        if(connect[i][root-1]==1 || connect[root-1][i]==1)
            cout<<i+1<<" ";
    }
    cout<<"\nRouters that are not in range from router "<<root<<":\n";
    for(int i=0;i<n;i++){
        if(connect[i][root-1]==0 && connect[root-1][i]==0 && i!=root-1)
            cout<<i+1<<" ";
    }
}