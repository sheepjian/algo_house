/*
File Name : q0315.h
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2016-01-17 15:37:50
*/

class TreeNode {
public:
    TreeNode* left;
    TreeNode* right;
    int value;
    int childCount;
    int dupCount; //duplicate node counter
    int height;
    
    TreeNode(int v) {
        left = NULL;
        right = NULL;
        value = v;
        childCount = 0;
        dupCount = 1;
        height = 1;
    }
};

class BST {
public:
    BST() {
        root = NULL;
    }

    int insert(int val) {
        int result = 0;
        root = insert(root, val, result);
        return result;
    }

    void printInorder() {
        inorder(root);
    }

private:

    void inorder(TreeNode* p) {
        if(p==NULL)
            return;

        inorder(p->left);
        cout<<"node value: "<<p->value<<", child nums: "<<p->childCount<<endl;
        inorder(p->right);
    }

    TreeNode* insert(TreeNode* t, int val, int& result) {
        if(t==NULL) {
            t = new TreeNode(val);
        } else if(val < t->value) {
            t->childCount++;
            t->left = insert(t->left, val, result);
        } else if(val > t->value) {
            t->childCount++;
            result += getSubNodesCount(t->left);
            result += t->dupCount;
            t->right = insert(t->right, val, result);
        } else {
            t->dupCount++;
            result += getSubNodesCount(t->left);
        }
        return t;
    }

    int getSubNodesCount(TreeNode* p) {
        if(p) {
            return p->childCount + p->dupCount;
        } else {
            return 0;
        }
    }

    TreeNode* root;
};

class AVLTree {
public:
    int insert(int val) {
        int result = 0;
        root = insert(val, root, result);
        return result;
    }

    AVLTree() {
        root = NULL;
    }

private:
    TreeNode* root;

    TreeNode* insert(int val, TreeNode* t, int& result) {
        if(t==NULL) {
            t = new TreeNode(val);
        } else if(val<t->value) {
            t->left = insert(val, t->left, result);
        }
        else if(val>t->value) {
            result += getSmallerNumberCount(t);
            t->right = insert(val, t->right, result);
        } else {
            t->dupCount = t->dupCount + 1;
            result += getSmallerNumberCount(t->left);
        }

        setHeight(t);

        int balance = getBalance(t);

        //left left
        if(balance > 1 && val < t->left->value) {
            t = rightRotate(t);
        }

        //left right
        if(balance > 1 && val > t->left->value) {
            t->left = leftRotate(t->left);
            t = rightRotate(t);
        }

        //right left
        if(balance < -1 && val < t->right->value) {
            t->right = rightRotate(t->right);
            t = leftRotate(t);
        }

        //right right
        if(balance < -1 && val > t->right->value) {
            t = leftRotate(t);
        }

        return t;
    }

    void setChildCount(TreeNode* p) {
        p->childCount = getSubNodesCount(p->left)
                    + getSubNodesCount(p->right);
    }

    int getSubNodesCount(TreeNode* p) {
        if(p) {
            return p->childCount + p->dupCount;
        } else {
            return 0;
        }
    }

    void setHeight(TreeNode* p) {
        p->height = max(getHeight(p->left),
                    getHeight(p->right)) + 1;
    }

    int getHeight(TreeNode* p) {
        if(p)
            return p->height;
        else
            return 0;
    }

    int getBalance(TreeNode* p) {
        if(p) 
            return getHeight(p->left)-getHeight(p->right);
        else
            return 0;
    }

    int getSmallerNumberCount(TreeNode* p) {
        if(p==NULL)
            return 0;

        if(p->left==NULL)
            return p->dupCount;
        else
            return p->left->childCount 
                +p->left->dupCount
                +p->dupCount;
    }

    TreeNode* leftRotate(TreeNode* p) {
        TreeNode* pRight = p->right;
        TreeNode* pRightLeft = p->right->left;

        p->right = pRightLeft;
        pRight->left = p;

        setHeight(p);
        setHeight(pRight);

        setChildCount(p);
        setChildCount(pRight);

        return pRight;
    }

    TreeNode* rightRotate(TreeNode* p) {
        TreeNode* pLeft = p->left;
        TreeNode* pLeftRight = p->left->right;

        p->left = pLeftRight;
        pLeft->right = p;

        setHeight(p);
        setHeight(pLeft);

        setChildCount(p);
        setChildCount(pLeft);

        return pLeft;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        AVLTree* tree = new AVLTree();
        for(int i = n-1; i>=0; i--) {
            result[i] = tree->insert(nums[i]);
        }
        return result;
    }

    vector<int> countSmaller2(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n);
        if(n>0) {
            vector<int> counts(n);
            vector<pair<int, int>> kk;
            
            for(int i=0; i<n; i++) {
                kk.push_back(make_pair(nums[i],i));
            }
            sort(kk.begin(), kk.end());
            
            for(int i=0; i<n; i++) {
                int left=0, right=n-1, id = kk[i].second;
                int count = 0;
                
                while(left<=right) {
                    int mid = (left+right)/2;
                    if(mid==id) {
                        results[mid] = count+counts[mid];
                        counts[mid] += 1;
                        break;
                    } else if(mid>id) {
                        count += counts[mid];
                        right = mid-1;
                    } else {
                        counts[mid] += 1;
                        left = mid+1;
                    }
                }
            }
        }
        return results;   
    }

    vector<int> countSmaller3(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        BST* tree = new BST();
        for(int i = n-1; i>=0; i--) {
            cout<<"insert "<<nums[i]<<endl;
            tree->printInorder();
            result[i] = tree->insert(nums[i]);
        }
        return result;
    }
};
