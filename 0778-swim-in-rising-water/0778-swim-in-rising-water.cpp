class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
        return 0;
        vector<pair<int, int>> xy{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> dis(n, vector<int> (n, 5e3));
        pq.push({grid[0][0], 0});
        while (!pq.empty())
        {
            int d = pq.top().first;
            int a = pq.top().second / n;
            int b = pq.top().second % n;
            pq.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = a + xy[i].first;
                int y = b + xy[i].second;
                if ((x >= 0) && (x < n) && (y >= 0) && (y < n))
                {
                    int mx = max(d, grid[x][y]);
                    if (dis[x][y] <= mx)
                    continue;
                    dis[x][y] = mx;
                    pq.push({mx, x*n + y});
                }
            }
        }
        return dis[n - 1][n - 1];
    }
};