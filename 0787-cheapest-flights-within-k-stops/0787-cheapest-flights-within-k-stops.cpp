class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int, vector<pair<int,int>>> mp;

        for(int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];

            mp[u].push_back({v, price});
        }

        
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > q;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        q.push({0, src, 0});
        dist[src][0] = 0;

        while(!q.empty()) {

            auto [cost, node, stops] = q.top();
            q.pop();

            if(node == dst)
                return cost;

            if(stops > k)
                continue;

            for(auto [nei, price] : mp[node]) {

                int newCost = cost + price;

                if(newCost < dist[nei][stops + 1]) {

                    dist[nei][stops + 1] = newCost;

                    q.push({
                        newCost,
                        nei,
                        stops + 1
                    });
                }
            }
        }

        return -1;
    }
};