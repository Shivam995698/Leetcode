class Solution {
    public int firstUniqChar(String s) {
        int n = s.length();
        HashMap<Character,Integer>mp= new HashMap<>();
        for(char ch: s.toCharArray())
        {
            mp.put(ch,mp.getOrDefault(ch,0)+1);
        }
        for(int i = 0;i<n;i++)
        {
            char ch = s.charAt(i);
            if(mp.get(ch)==1)
            {
                return i;
            }
        }
        return -1;
        
    }
}