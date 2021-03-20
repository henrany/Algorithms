#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> adj;

vector<bool>visited;

void dfs(int v){
    visited[v] = true;
    for(int i: adj[v]){
        if(!visited[i]){
            dfs(i);
        }
    }
}