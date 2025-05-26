class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0)
        {
            return 0;
        }
        int maxi = 0;
        for(int i =0;i<n;i++)
        {
            unordered_set<char>st;
            for(int j =i;j<n;j++)
            {
                if(st.find(s[j])!=st.end())
                {
                    maxi = max(maxi,j-i);
                    break;
                }
                st.insert(s[j]);
            }
            maxi = max(maxi,(int)st.size());
        }
        return maxi;
    }
};