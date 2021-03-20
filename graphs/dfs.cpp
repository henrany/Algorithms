#include<bits/stdc++.h>

class Dfs{
    private:
       int numOfVertices;
       //adjacency list for the nodes
       std::list<int>*adjList;
       //getting the visited nodes 
       bool *visited;
    public:
       Dfs(int numOfVertices);
       //adding an edge to the adjacency matrix
       void addEdge(int src, int dst);
       //doing  a dfs search
       void dfs(int start);
       void print();
       ~Dfs();
};

Dfs::Dfs(int numOfVertices){
    this->numOfVertices = numOfVertices;
    adjList = new std::list<int>[numOfVertices];
    visited = new bool [numOfVertices];
    for(int i=0;i<numOfVertices;i++)
        visited[i] = false;
}

void Dfs::addEdge(int src, int dst){
    adjList[src].push_back(dst);
    adjList[dst].push_back(src);
}

void Dfs::dfs(int start){
    //a stack for getting the visited nodes to be processed
    std::stack<int> st;
    //push the start node into the stack
    st.push(start);
    //mark the node as visited
    visited[start] = true;
    //a parent node for keeping track of the path taken;
    std::vector<int> parent;
    //check whether the stack is not empty
    while(!st.empty()){
        //get the topmost element from the stack
        int currentNode = st.top();
        //print the node
        std::cout<<currentNode<<"->";
        //remove the node from the stack
        st.pop();
        //tranverse through the list
        for(auto i=adjList[currentNode].begin();i!=adjList[currentNode].end();i++){
            //if node is not visited
            if(!visited[*i]){
                //mark as visited
                visited[*i] = true;
                //push unto the stack
                st.push(*i);
                //to get the tree or the path taken 
                parent.push_back(currentNode);
            }
        }
    }
    std::cout<<"\n";
}

void Dfs::print(){
    for(int i = 0;i<numOfVertices;i++){
        for(auto j=adjList[i].begin();j!=adjList[i].end();j++){
            std::cout<<*j<<"->";
        }
        std::cout<<"\n";
    }
}

Dfs::~Dfs(){
    delete[] adjList;
    delete[] visited;
}

int main(){
   Dfs g(5);
    g.addEdge(1, 0); 
    g.addEdge(2, 1); 
    g.addEdge(3, 4); 
    g.addEdge(4, 0); 
    // g.addEdge(1, 4); 
  
    std::cout << "Following is Depth First Traversal\n"; 
    g.dfs(0); 
}