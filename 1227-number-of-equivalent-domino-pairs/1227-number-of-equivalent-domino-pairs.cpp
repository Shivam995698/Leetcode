class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n = dominoes.size();
        int count =0;
        for(int i =0;i<n;i++)
        {
            int element1 = dominoes[i][0];
            int element2 = dominoes[i][1]; 
            for(int j =i+1;j<n;j++)
            {
                int element3 = dominoes[j][0];
                int element4 = dominoes[j][1];
                if((element1==element3 && element2 == element4)|| (element1==element4 &&      element2 == element3))
                {
                    count++;
                }
            }
            
        }
        return count;

    }
};