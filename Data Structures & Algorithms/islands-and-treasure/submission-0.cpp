class Solution {
public:
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
const int INF = INT_MAX;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int m = grid.size(), n=grid[0].size(), dist=1;
        // vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        //Find all treasure
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        //Start BFS
        while(!q.empty()){
            int q_size = q.size();
            for(int i=0;i<q_size;i++){
                pair<int,int> cell = q.front();
                q.pop();
                int x = cell.first, y = cell.second ;
                for(int i=0;i<4;i++){
                    int nx= x + dx[i];
                    int ny= y + dy[i];
                    if((nx>=0 && nx<m) && (ny>=0 && ny<n)){
                        if(grid[nx][ny]==INF ){
                            // vis[nx][ny] = true;
                            q.push({nx,ny});
                            grid[nx][ny] = dist;
                        }
                    }
                }
            }
            dist++;

        }
        
        
    }
};
