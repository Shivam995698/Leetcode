class Solution {
public:
    string pushDominoes(string dominoes) {
                int n = dominoes.length();
        vector<int>leftforce(n,0);
        vector<int>Rightforce(n,0);

        int force =0;
        for(int i =0;i<n;i++)
        {
            if(dominoes[i]=='R'){ 
                force = n;
            }
            else if(dominoes[i]=='L')
            {
                force = 0;
            }
            else{
                force = max(force-1,0);
            }
            Rightforce[i]=force;
        }
        force =0;
        for(int i =n-1;i>=0;i--)
        {
            if(dominoes[i]=='R'){
                force = 0;
            }
            else if(dominoes[i]=='L')
            {
                force = n;
            }
            else{
                force = max(force-1,0);
            }
            leftforce[i]=force;
        }
        string ans = "";
        for(int i =0;i<n;i++)
        {
            if(leftforce[i]>Rightforce[i])
            {
                ans+="L";
            }
            else if(leftforce[i]<Rightforce[i])
            {
                ans+="R";
            }
            else if(leftforce[i]==Rightforce[i])
            {
                ans+=".";
            }

        }
        return ans;
    }
};