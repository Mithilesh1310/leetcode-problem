class Solution {
public:
    int count = 0;
    void dfs(int u, int parent,unordered_map<int,vector<pair<int,int>>>&mp)
    {
        for(auto &p : mp[u])
        {
            int v = p.first;
            int check = p.second;

            if(v != parent)
            {
                if(check == 1)
                {
                    count++;
                }

                dfs(v,u,mp);
            }


            
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<pair<int,int>>>mp;

        for(auto & p : connections)
        {
            int u = p[0];
            int v = p[1];

            mp[u].push_back({v,1});
            mp[v].push_back({u,0});

        }
        
        dfs(0,-1,mp);

        return count;

    }
};