class Solution {
public:
    int findLar(vector<vector<int>>&mat,int mid,int n)
    {
        int index=-1;
        int maxi =-1;
        for(int i =0;i<n;i++)
        {
            if(mat[i][mid] >maxi)
            {
                index = i;
                maxi = mat[i][mid];
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m-1;
        vector<int>ans;
        while (low<=high)
        {
            int mid = low+(high-low)/2;
            int largest = findLar(mat,mid,n);
            int left = (mid>0?mat[largest][mid-1]:-1);
            int right = (mid+1<m?mat[largest][mid+1]:-1);
            if(mat[largest][mid]>right && mat[largest][mid]>left)
            {
                ans.push_back(largest);
                ans.push_back(mid);
                return ans;

            }
            if(mat[largest][mid]<right)
            {
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return vector<int>{-1,-1};
    }
};