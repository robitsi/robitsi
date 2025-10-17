#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;

        for (auto& desc : descriptions) {
            int parentVal = desc[0], childVal = desc[1], isLeft = desc[2];

            if (!nodes.count(parentVal))
                nodes[parentVal] = new TreeNode(parentVal);
            if (!nodes.count(childVal))
                nodes[childVal] = new TreeNode(childVal);

            if (isLeft)
                nodes[parentVal]->left = nodes[childVal];
            else
                nodes[parentVal]->right = nodes[childVal];

            children.insert(childVal);
        }

        for (auto& [val, node] : nodes) {
            if (!children.count(val))
                return node;
        }

        return nullptr; 
    }
};
