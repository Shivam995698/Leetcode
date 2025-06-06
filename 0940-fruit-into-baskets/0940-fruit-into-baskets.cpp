class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // unordered_set<int>st;
        
        // int n = fruits.size();
        // int maxlen =0;
        // for(int i =0;i<n;i++)
        // {
        //     unordered_set<int>st;
        //     for(int j =i;j<n;j++)
        //     {
        //         st.insert(fruits[j]);
        //         if(st.size()<=2)
        //         {
        //             int len = j-i+1;
        //             maxlen = max(len,maxlen);
        //         }
        //     }
        // }
        // return maxlen;



        //approch 2
        // int left =0;
        // int right=0;
        // int maxlen =0;
        // unordered_map<int,int>mp;
        // int n = fruits.size();
        // while(right<n)
        // {
        //     mp[fruits[right]]++;
        //     if(mp.size()>2)
        //     {
        //         while(mp.size()>2)
        //         {
        //             mp[fruits[left]]--;
        //             if(mp[fruits[left]]==0)
        //             {
        //                 mp.erase(fruits[left]);
        //             }
        //             left++;
        //         }
        //     }
        //     if(mp.size()<=2)
        //     {
        //         int len = right-left+1;
        //         maxlen = max(len,maxlen);
        //     }
        //     right++;
        // }
        // return maxlen;


        //approch 3
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int n = fruits.size();
        map<int,int>mp;
        while(right<n)
        {
            mp[fruits[right]]++;
            if(mp.size()>2)
            {
                mp[fruits[left]]--;
                if(mp[fruits[left]]==0)
                {
                    mp.erase(fruits[left]);
                    
                }
                left++;
                
            }
            if(mp.size()<=2)
            {
                maxlen = max(maxlen,right-left+1);
            }
            right++;
        }
        return maxlen;
    }
};