class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int>ans(256,-1);
        int l =0;
        int r = 0;
        int maxlen = 0;
        while(r<n)
        {
            if(ans[s[r]]!=-1)
            {
                if(ans[s[r]]>=l)
                {
                    l = ans[s[r]]+1;
                }
            }
            int len = r-l+1;
            maxlen = max(maxlen,len);
            ans[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};