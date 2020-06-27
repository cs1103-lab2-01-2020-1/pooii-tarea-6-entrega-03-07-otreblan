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

#pragma once

#include <vector>
#include <string_view>

#include <node.hpp>

enum class Order
{
	inOrder,
	preOrder
};

Node* buildTree(std::string_view str);
std::vector<int> inOrder(Node* root);
void inOrder(std::vector<int>& vec, Node* root);
int height(Node* root);
bool isFullTree(Node* root);
bool isSymmetric(Node* root);

Node* builTreePOSTOrd(std::vector<int>& inorder, std::vector<int>& preorder, int n);

Node* makeTree(int n);
void fillPreOrder(Node* root, std::vector<int>& vec, int& n);
void fillInOrder(Node* root, std::vector<int>& vec, int& n);
void fillTree(Node* root, std::vector<int>& vec, Order order);

void printLevels(Node* root);
