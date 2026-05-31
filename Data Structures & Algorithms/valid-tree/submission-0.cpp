class Solution {
public:
    bool checkCycle(int start, int curParent, vector<vector<int>> &adj, vector<bool> &vis) {
        vis[start] = true;
        for(int i = 0; i<adj[start].size() ;i++) {
            if(vis[adj[start][i]] && adj[start][i]!=curParent)
                return false;
            if(!vis[adj[start][i]])
                if(!checkCycle(adj[start][i], start, adj, vis)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(int i=0; i<edges.size() ; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        if(!checkCycle(0, -1, adj, vis)) return false;

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                return false;
            }
        }
        return true;
    }
};
