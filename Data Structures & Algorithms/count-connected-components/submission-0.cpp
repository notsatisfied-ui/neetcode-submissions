class Solution {
public:
    void dfs(int start, vector<vector<int>>& graph, vector<bool>& vis){
        vis[start] = true;
        for(int i=0;i<graph[start].size();i++){
            if(!vis[graph[start][i]])
            dfs(graph[start][i], graph, vis);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n, false);
        int count=0;
        for(int i=0; i<edges.size();i++){
            for(int j=0; j<2; j++){
                graph[edges[i][0]].push_back(edges[i][1]);
                graph[edges[i][1]].push_back(edges[i][0]);
            }
        }
        for(int i=0;i<graph.size();i++){
            if(!vis[i]){
                dfs(i, graph, vis);
                count++;
            }
        }
        return count;
    }
};
