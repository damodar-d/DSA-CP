#include<iostream>
bool detect(vector<int>adj[],int parent, int node, int visited[]){

    //Mark the current visited node as 1 --> Visited
    visited[node]=1;

    for(auto adjNode:adj[node]){

        // Explore the neighbour only if it has not been visited.
        if(visited[adjNode]!=1){

            //If there is cycle in neighbour, there is cycle overall.
            if(detect(adj,node,adjNode,visited)){
                return true;
            }
        }
        //If the adjacent node has not been visited and it is not the node from where we came.
        else if (visited[adjNode]==1 && adjNode!=parent){
            return true;
        }
    }
    return false;
}