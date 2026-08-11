class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>mp;

        for(int i =0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            
            mp[u].push_back({v,prob});
            mp[v].push_back({u,prob});
        }

        priority_queue<pair<double,int>,vector<pair<double,int>>>q;
        
        vector<double>res(n,0);

        q.push({1.0,start_node});

        res[start_node] = 1.0;

        while(!q.empty())
        {
            auto [p,node] = q.top();
            q.pop();
            for(auto [nei,pro] : mp[node])
            {
                if(p*pro > res[nei])
                {
                    res[nei] = p*pro;
                    q.push({p*pro,nei});
                }
            }
        }

        return res[end_node];

        
    }
};