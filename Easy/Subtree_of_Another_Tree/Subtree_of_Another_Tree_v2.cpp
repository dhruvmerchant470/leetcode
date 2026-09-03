class Solution {
private:
    vector<TreeNode*> candidateNodes;

public:
    void findCandidates(TreeNode* currentNode, int targetValue) {
        if (currentNode == NULL) return;
        if (currentNode->val == targetValue) candidateNodes.push_back(currentNode);
        findCandidates(currentNode->left, targetValue);
        findCandidates(currentNode->right, targetValue);
    }

    bool isSameTree(TreeNode* nodeA, TreeNode* nodeB) {
        if (nodeA == NULL && nodeB == NULL) return true;
        else if (nodeA && !nodeB) return false;
        else if (!nodeA && nodeB) return false;
        if (nodeA->val != nodeB->val) return false;
        bool leftMatch = isSameTree(nodeA->left, nodeB->left);
        bool rightMatch = isSameTree(nodeA->right, nodeB->right);
        return leftMatch && rightMatch;
    }

    bool isSubtree(TreeNode* mainRoot, TreeNode* subRoot) {
        findCandidates(mainRoot, subRoot->val);
        for (int i = 0; i < candidateNodes.size(); i++) {
            if (isSameTree(candidateNodes[i], subRoot)) return true;
        }
        return false;
    }
};
