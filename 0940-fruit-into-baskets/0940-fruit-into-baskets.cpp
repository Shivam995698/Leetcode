class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // int n = fruits.size();
        
        // int maxlen = INT_MIN;
        // for(int i =0;i<n;i++)
        // {
        //     set<int>st;
        //     for(int j =i;j<n;j++)
        //     {
        //         st.insert(fruits[j]);
        //         if(st.size()<=2)
        //         {
        //             maxlen = max(maxlen,j-i+1);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        // return maxlen;

        int left = 0;
        int right = 0;
        int maxlen = 0;
        unordered_map<int,int>mp;
        int n = fruits.size();
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
                    int len = right-left+1;
                    maxlen = max(maxlen,len);
                }
            right++;
        }
        return maxlen;
    }
};