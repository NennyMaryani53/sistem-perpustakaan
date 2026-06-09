#include "bst.h"
#include <iostream>

using namespace std;

struct Node {
    string judul;
    Node* left;
    Node* right;
};

Node* root = NULL;

Node* insert(Node* node, string judul) {
    if(node == NULL) {
        Node* baru = new Node;

        baru->judul = judul;
        baru->left = NULL;
        baru->right = NULL;

        return baru;
    }

    if(judul < node->judul) {
        node->left = insert(node->left, judul);
    }else if(judul >node->judul){
        node->right = insert(node->right, judul);
    }

    return node;
}

void insertBST(string judul) {
    root = insert(root, judul);
}

Node* search(Node* node, string judul) {
    if(node == NULL || node->judul == judul) {
        return node;
    }

    if(judul < node->judul) {
        return search(node->left, judul);
    }

    return search(node->right, judul);
}

void searchBST(string judul) {
    Node* hasil = search(root, judul);

    if(hasil != NULL) {
        cout << "Buku ditemukan : " << hasil->judul << endl;
    }else {
        cout << "Buku tidak ditemukan." << endl;
    }
}

void inorderTranversal(Node* node) {
    if(node != NULL) {
        inorderTranversal(node->left);

        cout << node->judul << endl;

        inorderTranversal(node->right);
    }
}

void inorder() {
    inorderTranversal(root);
}
