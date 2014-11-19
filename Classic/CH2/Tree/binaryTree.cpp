/*
 * binaryTree.cpp
 *
 *  Created on: Jun 16, 2014
 *      Author: jerry
 */

#include "binaryTree.h"
#include <vector>
using namespace std;

binaryTree::binaryTree() {
	root = NULL;
	size = 0;
}

void binaryTree::destroy_tree(treeNode *leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void binaryTree::destroy_tree() {
	destroy_tree(root);
	size = 0;
}

binaryTree::~binaryTree() {
	destroy_tree();
}

void binaryTree::insert(int key, treeNode *leaf) {
	if (key < leaf->val) {
		if (leaf->left != NULL)
			insert(key, leaf->left);
		else {
			leaf->left = new treeNode(key);
		}
	} else if (key >= leaf->val) {
		if (leaf->right != NULL)
			insert(key, leaf->right);
		else {
			leaf->right = new treeNode(key);
		}
	}
}

void binaryTree::insert(int key) {
	if (root != NULL)
		insert(key, root);
	else {
		root = new treeNode(key);
	}
	size++;
}

treeNode *binaryTree::search(int key, treeNode *leaf) {
	if (leaf != NULL) {
		if (key == leaf->val)
			return leaf;
		if (key < leaf->val)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	} else
		return NULL;
}

treeNode *binaryTree::search(int key) {
	return search(key, root);
}

vector<int> postorderTraversal(treeNode *root) {
	vector<int> visitedNode;
	vector<treeNode*> nodeStack;
	if (root == NULL)
		return visitedNode;

	treeNode* p = root;
	treeNode* lastVisited = root;

	while (!nodeStack.empty() || p != NULL) {
		if (p != NULL) {
			nodeStack.push_back(p);
			p = p->left;
		} else {
			p = nodeStack.back();
			if (p->right != NULL && lastVisited != p->right) {
				p = p->right;
			} else {
				visitedNode.push_back(p->val);
				nodeStack.pop_back();
				lastVisited = p;
				p = NULL;
			}
		}
	}
	return visitedNode;
}

vector<int> preorderTraversal(treeNode *root) {
	vector<int> visitedNode;
	vector<treeNode*> nodeStack;
	if (root == NULL)
		return visitedNode;

	treeNode* p = root;
	nodeStack.push_back(p);

	while (!nodeStack.empty()) {
		p = nodeStack.back();
		nodeStack.pop_back();
		visitedNode.push_back(p->val);

		if (p->right != NULL)
			nodeStack.push_back(p->right);

		if (p->left != NULL)
			nodeStack.push_back(p->left);
	}
	return visitedNode;
}

vector<int> inorderTraversal(treeNode *root) {
	vector<int> visitedNode;
	vector<treeNode*> nodeStack;
	if (root == NULL)
		return visitedNode;

	treeNode* p = root;
	treeNode* lastVisited = root;

	while (!nodeStack.empty() || p != NULL) {
		if (p != NULL) {
			nodeStack.push_back(p);
			p = p->left;
		} else {
			p = nodeStack.back();
			visitedNode.push_back(p->val);
			nodeStack.pop_back();

			p = p->right;
		}
	}
	return visitedNode;
}

