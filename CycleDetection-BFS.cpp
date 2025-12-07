#include<iostream>
using namespace std;

bool detect(vector<int>adj[], int src, int visited[]){

    visited[src] = 1;
    queue<<pair<int,int>>q;
    q.push({src,-1});

    while(!q.empty()){
        int parent = q.front().second;
        int node = q.front().first;
        q.pop();

        for(auto adjNode:adj[node]){
            if(visited[adjNode]!=1){
                visited[adjNode] = 1;
                q.push({adjNode,node});
            }
            else if(visited[adjNode]==1 && parent !=adjNode){
                return true;
            }
        }
    }

}

int main(){

}