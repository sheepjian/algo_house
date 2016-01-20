/*
File Name : q0327.h
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2016-01-15 21:57:13
*/

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int childCount;
    long long value;

    TreeNode(long long v) {
        left = NULL;
        right = NULL;
        value = v;
        childCount = 0;
    }
};

class BST {
public:
    BST() {
        root = NULL;
    }

    int greaterThan(long long val) {
        TreeNode* p = root;
        int result = 0;
        while(p) {
            if(val<=p->value) {
                result += getSubNodesCount(p->right);
                if(p->value>val) {
                    result++;
                }
                p = p->left;
            }
            else {
                p = p->right;
            }
        }
        return result;
    }

    void insert(long long val) {
        root = insert(root, val );
    }

private:
    TreeNode* insert(TreeNode* t, long long val) {
        if(t==NULL) {
            t = new TreeNode(val);
        } else if(val <= t->value) {
            t->childCount++;
            t->left = insert(t->left, val);
        } else {
            t->childCount++;
            t->right = insert(t->right, val);
        }

        return t;
    }

    int getSubNodesCount(TreeNode* p) {
        if(p) {
            return p->childCount+1;
        } else {
            return 0;
        }
    }

    TreeNode* root;
};


class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int result = 0;
        int n = nums.size();
        long long prefixSum = 0;
        BST* tree = new BST();
        tree->insert(0);
        for(int i=0; i<n; i++) {
            prefixSum += nums[i];
            int top = tree->greaterThan(prefixSum-upper-1);
            int bottom = tree->greaterThan(prefixSum-lower);
            result += (top-bottom);
            tree->insert(prefixSum);
        }
        return result;
    }
};
