#include<bits/stdc++.h>
#define ll long long
using namespace std;

#define max 10000
int vect[max][max];

void populate(int n) {
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) {
            vect[i][j] = 0;
        }
    }
}

//function to add the edges to the array
//this is for directed graph;
void add_edge(int n) {
    for (int i=0;i<n;i++) {
        int a=0, b=0;
        cin>>a>>b;
        vect[a][b] = 1;
    }
}

//adding edge to be used in case of an undirected graph
void add_edge_undirected_graph(int n){
    for(int i=0;i<n;i++){
        int a=0,b=0;
        cin>>a>>b;
        vect[a][b]= 1;
        vect[b][a] = 1;
    }
}

//function to display the array
void display(int n) {
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            cout<<vect[i][j]<<" ";
        }
        cout<<"\n";
   }
}

int main(){
        int n;
        cin>>n;
        populate(n);
        add_edge(n);
        display(n);
}