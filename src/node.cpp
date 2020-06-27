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

#include <initializer_list>

#include <node.hpp>

Node::Node(int val):
	data(val),
	left(nullptr),
	right(nullptr)
{};

bool Node::compare(const Node* _this, const Node* other)
{
	if(_this == other)
	{
		return true;
	}
	else if(_this == nullptr || other == nullptr)
	{
		return false;
	}
	else
	{
		return _this->data == other->data &&
			compare(_this->left, other->left) &&
			compare(_this->right, other->right);
	}
}

Node* Node::makeNode(int val)
{
	return new Node(val);
}

Node::~Node()
{
	for(Node* c: {left, right})
	{
		if(c != nullptr)
			delete c;
	}
}

bool Node::operator==(const Node& other)
{
	return compare(this, &other);
}
