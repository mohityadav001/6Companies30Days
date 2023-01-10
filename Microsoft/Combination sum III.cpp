class Solution
{
public:
    void findSum(int ind, int k, int n, vector<int> &ds, vector<vector<int>> &ans)
    {
        if (n == 0)
        {
            if (ds.size() == k)
            {
                ans.push_back(ds);
            }
            return;
        }

        for (int i = ind; i <= 9; i++)
        {
            ds.push_back(i);
            findSum(i + 1, k, n - i, ds, ans);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findSum(1, k, n, ds, ans);
        return ans;
    }
};