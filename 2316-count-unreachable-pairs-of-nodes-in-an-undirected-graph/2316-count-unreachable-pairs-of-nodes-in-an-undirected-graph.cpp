class Solution {
public:
    void dfs(int node,unordered_map<int,vector<int>>&mp,vector<bool>&visited,long long &size)
    {
        visited[node] = true;
        size++;
 
        for(auto &v : mp[node])
        {
            if(!visited[v])
        {
            dfs(v,mp,visited,size);
        }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>mp;

        for(auto &p : edges)
        {
            int u = p[0];
            int v = p[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool>visited(n,false);
        long long ans = 0;
        long long totalnodes = n;

        for(int i =0;i<n;i++)
        {
            
            if(!visited[i])
            {
                long long size = 0;
                dfs(i,mp,visited,size);
                ans+= (size)* (totalnodes - size);

                totalnodes -= size;
            }
        }

        return ans;
    }
};