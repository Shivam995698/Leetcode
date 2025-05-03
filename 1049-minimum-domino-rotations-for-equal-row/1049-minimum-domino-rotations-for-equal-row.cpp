class Solution {
public:
    int solve(vector<int>&tops,vector<int>&bottoms,int value)
    {
        int topshow=0;
        int down =0;
        int n = tops.size();
        for(int i =0;i<n;i++)
        {
        if(tops[i]!=value && bottoms[i]!=value)
        {
            return -1;
        }
        else if(tops[i]!=value)
        {
            topshow++;
        }
        else if(bottoms[i]!=value){
            down++;
        }
        }
        return min(topshow,down);

    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int mini = INT_MAX;
        for(int value =1;value<=6;value++)
        {
            int ans = solve(tops,bottoms,value);
            if(ans != -1)
                mini = min(mini,ans);
        }        
        return (mini ==INT_MAX)?-1:mini;
    }
};