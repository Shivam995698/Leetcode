class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0;
        int right = 0;
        unordered_map<int,int>mp;
        int n = fruits.size();
        int maxlen = INT_MIN;
        while(right<n)
        {
            mp[fruits[right]]++;
            if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fruits[left]]--;
                    if(mp[fruits[left]]==0)
                    {
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            if(mp.size()<=2)
            {
                maxlen =  max(right-left+1,maxlen);
            }
            right++;
        }
        return maxlen;
    }
};