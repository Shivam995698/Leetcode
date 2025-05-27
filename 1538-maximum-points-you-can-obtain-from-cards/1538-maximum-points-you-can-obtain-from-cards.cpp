class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum =0;
        if(k>=n)
        {
            for(int i =0;i<n;i++)
            {
                sum+=cardPoints[i];
            }
            return sum;
        }
        for(int i =0;i<k;i++)
        {
            sum+=cardPoints[i];
        }
        int maxsum = sum;
        for(int i =1;i<=k;i++)
        {
            sum = sum-cardPoints[k-i]+cardPoints[n-i];
            if(sum>maxsum)
            {
                maxsum = sum;
            }
        }
        return maxsum;
    }
};