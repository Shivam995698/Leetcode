class Solution {
public:
    // int longcoRecc(string text1,string text2,int i,int j)
    // {
    //     if(i>=text1.size() || j>= text2.size())
    //     {
    //         return 0;
    //     }
    //     int match =0;
    //     int notmatch =0;
    //     if(text1[i]==text2[j])
    //     {
    //         match = 1+ longcoRec(text1,text2,i+1,j+1);
    //     }
    //     else
    //     {
    //         notmatch = max(
    //             longcoRec(text1,text2,i,j+1),longcoRec(text1,text2,i+1,j));
    //     }
    //     int ans =max(match,notmatch);
    //     return ans;

    // }
    int usingmemo(string& text1,string& text2,int i,int j,vector<vector<int>>&dp)
    {
        if(i>=text1.size() || j>= text2.size())
        {
            return 0;
        }
        int match =0;
        int notmatch =0;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(text1[i]==text2[j])
        {
            match = 1+ usingmemo(text1,text2,i+1,j+1,dp);
        }
        else
        {
            notmatch = max(
                usingmemo(text1,text2,i,j+1,dp),usingmemo(text1,text2,i+1,j,dp));
        }
        dp[i][j] =max(match,notmatch);
        return dp[i][j];

    }
    int solvetabu(string& a,string& b,int i,int j)
    {
        vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
        
        for(int i_index=a.length()-1;i_index>=0;i_index--)
        {
            int ans =0;
            for(int j_index=b.length()-1;j_index>=0;j_index--)
            {
            if(a[i_index]==b[j_index])
            {
                ans = 1+ dp[i_index+1][j_index+1];
            }
            else
            {
                ans = max(
                    dp[i_index][j_index+1],dp[i_index+1][j_index]);
            }
            dp[i_index][j_index] =ans;
            }
        } 
        return dp[0][0];   
    }
    int solveusingspace(string a,string b,int i,int j)
    {
        vector<int>curr(a.length()+1,0);
        vector<int>next(a.length()+1,0);
        for(int j_index=b.length()-1;j_index>=0;j_index--)
        {
            for(int i_index=a.length()-1;i_index>=0;i_index--)
            {
                int ans=0;

                    if(a[i_index]==b[j_index])
                    {
                        ans = 1+next[i_index+1];
                    }
                    else
                    {
                        ans=0 + max(next[i_index],curr[i_index+1]);
                    }
                    curr[i_index]=ans;
                }
                //shifting
                next = curr;
            }
        return next[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int i = 0;
        int j =0;
        // vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length()+1,-1));
        int ans = solveusingspace(text1,text2,i,j);
        return ans;
    }
};