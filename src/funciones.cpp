// Tarea 6
// Copyright © 2020 otreblan
//
// tarea-6 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// tarea-6 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with tarea-6.  If not, see <http://www.gnu.org/licenses/>.

#include <stack>
#include <queue>
#include <iostream>

#include <funciones.hpp>

Node* builTreePOSTOrd(std::vector<int>& inorder, std::vector<int>& preorder, int n)
{
	Node* r1 = makeTree(n);
	Node* r2 = makeTree(n);

	fillTree(r1, inorder, Order::inOrder);
	fillTree(r2, preorder, Order::preOrder);

	if(*r1 == *r2)
	{
		delete r2;

		return r1;
	}
	else
	{
		delete r1;
		delete r2;

		return nullptr;
	}
}

Node* makeTree(int n)
{
	if(n <= 0)
		return nullptr;

	Node* root = Node::makeNode(0);

	std::queue<Node*> nodes;
	nodes.push(root);

	Node* head_ref = nullptr;
	int childs = 0;
	for(int i = 1; i < n; ++i)
	{
		head_ref = nodes.front();
		switch(childs++)
		{
			case 0:
				head_ref->left = Node::makeNode(0);
				nodes.push(head_ref->left);

				break;

			case 1:
			default:
				head_ref->right = Node::makeNode(0);
				nodes.push(head_ref->right);

				nodes.pop();
				childs = 0;
				break;
		}
	}

	return root;
}

void fillPreOrder(Node* root, std::vector<int>& vec, int& n)
{
	if(root == nullptr)
		return;

	root->data = vec[vec.size()-(n--)];

	for(Node* ptr: {root->left, root->right})
	{
		fillPreOrder(ptr, vec, n);
	}
}

void fillInOrder(Node* root, std::vector<int>& vec, int& n)
{
	if(root == nullptr)
		return;

	fillInOrder(root->left, vec, n);

	root->data = vec[vec.size()-(n--)];

	fillInOrder(root->right, vec, n);
}

void fillTree(Node* root, std::vector<int>& vec, Order order)
{
	int size = vec.size();

	switch(order)
	{
		case Order::inOrder:
			fillInOrder(root, vec, size);
			break;

		case Order::preOrder:
			fillPreOrder(root, vec, size);
			break;
	}
}

void printLevels(Node* root)
{
	if(root == nullptr)
		return;

	std::queue<std::pair<Node*, int>> levels;
	levels.push({root, 0});

	while(!levels.empty())
	{
		std::pair head = levels.front();

		std::cerr << head.second << '-' << head.first->data << '\n';

		for(Node* ptr: {head.first->left, head.first->right})
		{
			if(ptr != nullptr)
				levels.push({ptr, head.second+1});
		}
		levels.pop();
	}
}
