class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0)
        {
            return 0;
        }
        int i=0;
        int maxi = 0;
        unordered_set<char>st;
        for(int j = 0;j<n;j++)
        {
            if(st.find(s[j])!=st.end())
            {
                while(i<j && st.find(s[j])!=st.end())
                {
                    st.erase(s[i]);
                    i++;
                }
            }
            st.insert(s[j]);
            maxi = max(maxi,j-i+1);
            
        }

        return maxi;
    }
};