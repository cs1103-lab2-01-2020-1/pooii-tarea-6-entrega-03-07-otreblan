//
// Author: marvin on 6/25/20.
//

#ifndef NODE_H
#define NODE_H

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};



#endif //NODE_H
