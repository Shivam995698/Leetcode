class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n!=0)
        {
            int num = n%10;
            n=n/10;
            ans.push_back(num);
        }
        int size = ans.size();
        if(size == 1)
        {
            return ans[0];
        }
        int mul = 1;
        int maxi = INT_MIN;
        for(int i =0;i<size;i++)
            {
                for(int j =i+1;j<size;j++)
                    {
                        int num = ans[i]*ans[j];
                        maxi = max(maxi,num);
                    }
            }
        return maxi;
    }
};