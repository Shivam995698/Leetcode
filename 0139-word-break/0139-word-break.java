class Solution {
    boolean solve(String s,HashSet<String>hs,HashMap<String,Boolean>mp)
    {
        if(s.length()==0)
        {
            return true;
        }
        if(mp.containsKey(s))
        {
            return mp.get(s);
        }
        for(int i = 1;i<=s.length();i++)
        {
            String prefix = s.substring(0,i);
            if(hs.contains(prefix))
            {
                String remaining = s.substring(i);
                boolean ans = solve(remaining,hs,mp);
                if(ans)
                {
                    mp.put(s,true);
                    return true;
                }
            }
        }
        mp.put(s,false);
        return false;
    }
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String>hs = new HashSet<>(wordDict);
        HashMap<String,Boolean>mp = new HashMap<>();
        boolean ans = solve(s,hs,mp);
        return ans;
    }
}