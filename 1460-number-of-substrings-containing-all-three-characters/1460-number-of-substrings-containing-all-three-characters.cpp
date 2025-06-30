class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int left =0;
        int right =0;
        vector<int>countArr(3,0);
        int finalcount=0;
        while(right<n)
        {
            countArr[s[right]-'a']++;
            while(countArr[0] && countArr[1] && countArr[2])
            {
                countArr[s[left]-'a']--;
                left++;
                finalcount+=(n-right);
            }
            right++;

        }  
        return finalcount;
    }
};