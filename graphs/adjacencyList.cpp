#include<bits/stdc++.h>
#define max 1000000
//implementation of the adjacency list of graph using stls

std::list<int> adjacencyList[max];

//adding vertices and edges to the list
void add_edge(int numOfVertices){
    for(int i=0;i<numOfVertices;i++){
        int u=0,v=0;
        std::cin>>u>>v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
}

//display the list
void displayGraph(int numOfVertices){
    for(int i=1;i<numOfVertices;i++){
        std::cout<<"vertex "<<i;
        for(auto a : adjacencyList[i]){
            std::cout<<"-->"<<a;
        }
        std::cout<<"\n";
    }
}

int main(){
    int numOfVertices =0;
    std::cin>>numOfVertices;
    add_edge(numOfVertices);
    displayGraph(numOfVertices);
}
