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
#include <sstream>
#include <optional>

#include <funciones.hpp>

Node* buildTree(std::string_view str)
{
	std::istringstream is(str.data());

	std::string buffer;

	is >> buffer;

	if(buffer == "N")
		return nullptr;

	Node* root = Node::makeNode(std::stoi(buffer));

	std::queue<Node*> nodes;
	nodes.push(root);

	Node* head_ref = nullptr;
	int childs = 0;

	while(is >> buffer)
	{
		Node* newNode = nullptr;
		if(buffer != "N")
			newNode = Node::makeNode(std::stoi(buffer));

		head_ref = nodes.front();
		switch(childs++)
		{
			case 0:
				head_ref->left = newNode;

				break;

			case 1:
			default:
				head_ref->right = newNode;

				nodes.pop();
				childs = 0;
				break;
		}

		if(newNode != nullptr)
			nodes.push(newNode);
	}

	return root;
}

std::vector<int> inOrder(Node* root)
{
	std::vector<int> vec;

	inOrder(vec, root);

	return vec;
}

void inOrder(std::vector<int>& vec, Node* root)
{
	if(root == nullptr)
		return;

	inOrder(vec, root->left);
	vec.push_back(root->data);
	inOrder(vec, root->right);
}

int height(Node* root)
{
	if(root == nullptr)
		return 0;

	return 1+std::max(height(root->left), height(root->right));
}

bool isFullTree(Node* root)
{
	if(root == nullptr)
		return true;

	int childs = 0;
	for(Node* ptr: {root->left, root->right})
	{
		if(ptr != nullptr)
			childs++;
	}

	return ((childs == 2) || (childs == 0)) &&
		isFullTree(root->left) &&
		isFullTree(root->right)
	;
}

bool isSymmetric(Node* root)
{
	if(root == nullptr)
		return false;

	std::queue<std::optional<Node*>> levels;
	levels.push(root);
	levels.push(nullptr);

	bool levelHasChildren = false;

	std::vector<bool> levelMask;

	while(true)
	{
		auto head = levels.front();

		if(!head.has_value())
		{
			levels.push(std::nullopt);

			levelMask.push_back(0);
		}
		else if(head.value() == nullptr)
		{
			levels.push(nullptr);

			bool l, r;
			for(size_t i = 0; i < levelMask.size()/2; ++i)
			{
				l = levelMask.at(i);
				r = levelMask.at(levelMask.size()-1-i);

				if(l != r)
					return false;
			}

			levelMask.clear();

			if(levelHasChildren)
				levelHasChildren = false;
			else
				break;
		}
		else
		{
			//std::cerr << level << '-' << head.value()->data << '\n';

			for(Node* ptr: {head.value()->left, head.value()->right})
			{
				if(ptr != nullptr)
				{
					levels.push(ptr);
					levelHasChildren = true;
				}
				else
					levels.push(std::nullopt);
			}

			levelMask.push_back(1);
		}

		levels.pop();
	}

	return true;
}

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

	std::queue<Node*> levels;
	levels.push(root);
	levels.push(nullptr);

	int level = 1;

	while(levels.size() > 1)
	{
		Node* head = levels.front();

		if(head == nullptr)
		{
			levels.push(nullptr);
			level++;
		}
		else
		{
			std::cerr << level << '-' << head->data << '\n';

			for(Node* ptr: {head->left, head->right})
			{
				if(ptr != nullptr)
					levels.push(ptr);
			}
		}
		levels.pop();
	}
}
