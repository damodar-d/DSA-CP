// NOTES : 

// 1. Keeping track of parent is not required in directed graph as we'll not go back to parent because of the direction
// 2. If the incident node is not visited
//    2.1 GO VISIT IT. IF it says there is a cycle, THERE IS INDEED CYCLE.
// 3. If the incident node is already visited.
//    3.1 And the visit is part of the path which led us here.
//    3.2 There is definitely a cycle.


bool dfs(vector<vector<int>>&graph, vector<int>&pathVisited, vector<int> & visited, int node){

    visited[node] = 1;
    pathVisited[node]=1;
    for(auto adj: graph[node]){

        // If the incident node is not visited, GO VISIT IT. Lets see what it says.
        if(!visited[adj]){
            if(dfs(graph,pathVisited,visited,adj)){
                return true;
            }
        }

        // If the incident node has already been visited
        else{
            // And it comes in the path. That clearly means there is a cycle.
            if(pathVisited[adj]){
                return true;
            }
        }
    }
    pathVisited[node]= 0;
    return false;
}