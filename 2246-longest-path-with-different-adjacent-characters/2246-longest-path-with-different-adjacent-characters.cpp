class Solution {
public:
      
    int result;

    int dfs(unordered_map<int,vector<int>>&mp,int curr, int par, string &s)
    {
        int longest = 0;
        int seclongest = 0;

        for( int &child : mp[curr])
        {
            if(child == par)
            continue;
            int child_longest_length = dfs(mp,child,curr,s);
            if(s[child] == s[curr])
            continue;
            if(child_longest_length > seclongest)
            seclongest = child_longest_length;

            if(seclongest > longest)
            swap(seclongest,longest);
        }
        
        int oneg = max(seclongest,longest) +1;
        int onlyroot = 1;
        int neeche = 1 + longest + seclongest;
        
        result = max({result,oneg,onlyroot,neeche});

        return max(oneg,onlyroot);

    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        unordered_map<int,vector<int>>mp;

        result = 0;
        for(int i =1;i<n;i++)
        {
            int u = i;
            int v = parent[i];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        dfs(mp,0,-1,s);
        return result;
    }
};