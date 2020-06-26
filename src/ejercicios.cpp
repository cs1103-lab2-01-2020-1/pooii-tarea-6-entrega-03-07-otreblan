//
// Author: marvin on 6/17/20.
//

#include "ejercicios.h"
#include "funciones.h"
#include "../bt/node.h"

void ejercicio1() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s); //Implementar buildTree
        vector<int> res = inOrder(root); //Implementar inOrder
        for (int i = 0; i < res.size(); i++)
            cout<<res[i]<<" ";
        cout<<endl;
        cout<<"The root of the tree is: "<<height(root)<<endl;//Implementar height

        cout<<"Is the tree full? "<<isFullTree(root)<<endl;//Implementar isFullTree

        if (isSymmetric(root)) { //Implementar isSymmetric
            cout<<"The tree is Symmetric"<<endl;
        } else {
            cout<<"The tree is not Symmetric"<<endl;
        }
    }
}

void ejercicio2() {
    cout<<"Construir un arbol a partir de arrays en inorder y preorder"<<endl;
    int n = 6;

    int inorder[] = {3, 1, 4, 0, 5, 2};
    int preorder[] = {0, 1, 3, 4, 2, 5};
    Node* root = builTreePOSTOrd(inorder, preorder, n);
}