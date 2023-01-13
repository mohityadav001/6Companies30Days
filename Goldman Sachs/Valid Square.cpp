class Solution
{
public:
    double distanceBetPoints(vector<int> p1, vector<int> p2)
    {
        return (((p2[0] - p1[0]) * (p2[0] - p1[0])) + ((p2[1] - p1[1]) * (p2[1] - p1[1])));
    }
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> points = {p1, p2, p3, p4};
        set<double> set;
        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                double dis = distanceBetPoints(points[i], points[j]);
                if (dis != 0)
                    set.insert(dis);
                else
                    return false;
            }
        }
        return set.size() == 2;
    }
};