#include<bits/stdc++.h>

class Graph{
   private:
      //number of vertices to be used
      int numOfVertices;
      //adjacency list for storing the nodes to be visited
      std::list<int> *adjList;
      //holding visited nodes 
      //prevent visiting a node twice
      bool *visited;
   public:
   //initialized the list
      Graph(int vertices);
      //add edge to the graph
      void add_edge(int src, int dest);
      //bfs algorithm with the starting vertice as s
      void bfs(int s);
};

Graph::Graph(int vertices){
    numOfVertices = vertices;
    adjList = new std::list<int>[vertices];
}

void Graph::add_edge(int src, int dest){
    //pushing elemen into the list
    adjList[src].push_back(dest);
    adjList[dest].push_back(src);
}

void Graph::bfs(int s){
    //initialized all element as false
    visited = new bool[numOfVertices];
    for(int i=0;i<numOfVertices;i++)
        visited[i] = false;

    //a queue for storing the seen nodes
    std::queue<int> qb;
    qb.push(s);    

    //initialized the start vertices as true in visited array
    visited[s] = true;
    //check if the queue is not empty
    //if empty , the algorigthm will hault
    while(!qb.empty()){
        //get the current vertice and process it
        int currVertice = qb.front();
        std::cout<<currVertice<<" ";
        //remove first element from the queue
        qb.pop();
        std::list<int>::iterator i;
        for(i=adjList[currVertice].begin();i != adjList[currVertice].end();i++){
            //not to process seen vertices
            if(!visited[*i]){
                visited[*i] = true;
                qb.push(*i);
            }
        }
    } 
    std::cout<<"\n";
}


int main(){
    Graph g(4);
  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 0);
  g.add_edge(2, 3);
  g.add_edge(3, 3);

  g.bfs(2);
}