class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n <= 2)
            return n; // base condition
        int result = 0;

        // number of points with same slope will indicate that they are on same line.
        for (auto p1 : points)
        {
            unordered_map<double, int> unmap;
            double x1 = p1[0], y1 = p1[1];
            for (auto p2 : points)
            {
                if (p2 == p1)
                    continue;
                double x2 = p2[0], y2 = p2[1];
                double slope;
                if (x2 - x1 == 0)
                {
                    slope = INT_MAX; // In case where line is vertical
                }
                else
                {
                    slope = (y2 - y1) / (x2 - x1);
                }
                unmap[slope]++;
                result = max(unmap[slope], result);
            }
        }
        return result + 1;
    }
};