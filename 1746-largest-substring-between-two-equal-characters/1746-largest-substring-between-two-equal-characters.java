class Solution {
    public int maxLengthBetweenEqualCharacters(String s) {
        int n = s.length();
        int maxi = -1;
        for(int i =0;i<n;i++)
        {
            int index = 0;
            for(int j = i+1;j<n;j++)
            {
                if(s.charAt(i)==s.charAt(j))
                {
                    index = j;
                }
            }
            if(index>=i+1 && index<n)
             
            // int len = str.length();
            maxi = Math.max(s.substring(i+1,index).length(),maxi);
        }
        return maxi;
    }
}