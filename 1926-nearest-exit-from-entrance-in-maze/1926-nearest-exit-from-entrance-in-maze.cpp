class Solution {
public:
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m,false));

        q.push({entrance[0], entrance[1]});
        visited[entrance[0]][entrance[1]] = true;

        int step = 0;

        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [r,c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++)
                {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                        continue;

                    if(maze[nr][nc] == '+')
                        continue;

                    if(visited[nr][nc])
                        continue;

                    if(nr == 0 || nr == n-1 ||
                       nc == 0 || nc == m-1)
                    {
                        return step + 1;
                    }

                    visited[nr][nc] = true;
                    q.push({nr,nc});
                }
            }

            step++;
        }

        return -1;
    }
};