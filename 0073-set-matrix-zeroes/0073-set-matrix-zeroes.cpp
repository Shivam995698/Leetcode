class Solution {
public:
    void setTO(vector<vector<int>>&mat,int row,int col,vector<vector<bool>>&Track)
    {
        int rowsize = mat.size();
        int colsize = mat[0].size();
        for(int col1=0;col1<colsize;col1++)
        {
            if(mat[row][col1]!=0){
            mat[row][col1]=0;
            Track[row][col1]=false;
            }
        }
        for(int row1 = 0;row1<rowsize;row1++)
        {
            if(mat[row1][col]!=0)
            {
            mat[row1][col]=0;
            Track[row1][col]=false;
            }
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>>track(n,vector<bool>(m,true));
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(track[i][j] && matrix[i][j]==0 )
                {
                    setTO(matrix,i,j,track);
                }
            }
        }
    }
};