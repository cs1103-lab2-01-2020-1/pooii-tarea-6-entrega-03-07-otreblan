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

#include <iostream>
#include <vector>
#include <string>

#include <ejercicios.hpp>
#include <funciones.hpp>
#include <node.hpp>

void ejercicio1() {
//	int t;
//	std::string tc;
//	getline(std::cin, tc);
//	t = stoi(tc);
//	while (t--) {
//		std::string s;
//		getline(cin, s);
//		Node* root = buildTree(s); //Implementar buildTree
//		std::vector<int> res = inOrder(root); //Implementar inOrder
//		for (size_t i = 0; i < res.size(); i++)
//			std::cout<<res[i]<<" ";
//		std::cout << '\n';
//		std::cout << "The root of the tree is: " << height(root) << '\n';//Implementar height
//
//		std::cout<<"Is the tree full? "<< isFullTree(root) << '\n';//Implementar isFullTree
//
//		if (isSymmetric(root)) { //Implementar isSymmetric
//			std::cout << "The tree is Symmetric\n";
//		} else {
//			std::cout << "The tree is not Symmetric\n";
//		}
//	}
}

void ejercicio2() {
	std::cout << "Construir un arbol a partir de arrays en inorder y preorder\n";
	int n = 6;

	int inorder[] = {3, 1, 4, 0, 5, 2};
	int preorder[] = {0, 1, 3, 4, 2, 5};
	Node* root = builTreePOSTOrd(inorder, preorder, n);
}
