class Solution {
public:
    bool issimiler(string s1,string s2)
    {
        int m = s1.size();

        int diff = 0;

        for(int i =0;i<m;i++)
        {
            if(s1[i] != s2[i])
            diff++;
        }

        if(diff <=2)
        return true;

        return false;
    }

    void  dfs(int u,unordered_map<int,vector<int>>&mp,vector<bool>&visited)
    {
        visited[u] = true;

        for(auto &v : mp[u])
        {
            if(!visited[v])
            dfs(v,mp,visited);
        }
    }


    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        unordered_map<int,vector<int>>mp;

        for(int i = 0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(issimiler(strs[i],strs[j]))
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }

        vector<bool>visited(n,false);
        int count = 0;

        for(int i =0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(i,mp,visited);
                count++;

            }
        }

        return count;


    }
};