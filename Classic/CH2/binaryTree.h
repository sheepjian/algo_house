/*
 * binaryTree.h
 *
 *  Created on: Jun 16, 2014
 *      Author: jerry
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include <cstddef>
#include <vector>
using namespace std;

struct treeNode {
	int val;
	treeNode* left;
	treeNode* right;
	treeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class binaryTree {
public:
	binaryTree();
	~binaryTree();

	void insert(int key);
	treeNode *search(int key);
	void destroy_tree();

    int getSize(){return size;}
    int getRootVal(){return root->val;}
    treeNode* getRoot(){return root;}


private:
    int size;
	treeNode* root;
	void destroy_tree(treeNode *leaf);
	void insert(int key, treeNode *leaf);
	treeNode *search(int key, treeNode *leaf);
};

vector<int> postorderTraversal(treeNode *root);
vector<int> preorderTraversal(treeNode *root);
vector<int> inorderTraversal(treeNode *root);

#endif /* BINARYTREE_H_ */
