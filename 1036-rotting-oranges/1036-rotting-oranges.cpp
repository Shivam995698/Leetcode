class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> v(n, vector<int>(m, 0));
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    v[i][j]=2;
                }
                else if(grid[i][j] == 1) {
                    v[i][j] = 1;
                }
            }
        }
        int nrow[] = {-1,0,1,0};
        int ncol[] = {0,1,0,-1};
        int tm = 0;
        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            tm = max(tm,q.front().second);
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int nr = r+nrow[i];
                int nc = c+ncol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && v[nr][nc]!=2)
                {
                    v[nr][nc]=2;
                    q.push({{nr,nc},tm+1});
                }
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(v[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return tm;
    }
};