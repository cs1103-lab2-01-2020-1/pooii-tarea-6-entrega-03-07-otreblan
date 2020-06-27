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


struct Node {
private:
	Node(int val);

	static bool compare(const Node* _this, const Node* other);

public:
	int data;
	Node* left;
	Node* right;

	static Node* makeNode(int val);

	~Node();

	bool operator==(const Node& other);
};
