/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> ans1;
        vector<int> ans2;
        vector<int> ans3(ans1.size() + ans2.size());

        stack<TreeNode *> s;
        while (true)
        {
            if (root1 != NULL)
            {
                s.push(root1);
                root1 = root1->left;
            }
            else
            {
                if (s.empty())
                    break;
                root1 = s.top();
                ans1.push_back(root1->val);
                s.pop();
                root1 = root1->right;
            }
        }

        stack<TreeNode *> s2;
        while (true)
        {
            if (root2 != NULL)
            {
                s2.push(root2);
                root2 = root2->left;
            }
            else
            {
                if (s2.empty())
                    break;
                root2 = s2.top();
                ans2.push_back(root2->val);
                s2.pop();
                root2 = root2->right;
            }
        }
        int i = 0, j = 0, k = 0;
        while (i < ans1.size() && j < ans2.size())
        {
            if (ans1[i] < ans2[j])
            {
                ans3.push_back(ans1[i]);
                i++;
            }
            else
            {
                ans3.push_back(ans2[j]);
                j++;
            }
        }
        while (i < ans1.size())
        {
            ans3.push_back(ans1[i]);
            i++;
        }
        while (j < ans2.size())
        {
            ans3.push_back(ans2[j]);
            j++;
        }
        return ans3;
    }
};