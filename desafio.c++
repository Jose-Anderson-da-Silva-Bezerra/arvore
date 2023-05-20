#include <iostream>

using namespace std;

// Estrutura do nó da árvore
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

// Função para obter a altura de um nó
int getHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height;
}

// Função para obter o máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para criar um novo nó
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1; // Inicializa a altura como 1
    return node;
}

// Função para realizar uma rotação simples à direita
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Realiza a rotação
    x->right = y;
    y->left = T2;

    // Atualiza as alturas
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Função para realizar uma rotação simples à esquerda
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Realiza a rotação
    y->left = x;
    x->right = T2;

    // Atualiza as alturas
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Função para obter o fator de balanceamento de um nó
int getBalanceFactor(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}

// Função para inserir um nó na árvore
Node* insertNode(Node* root, int key) {
    // Realiza a inserção como em uma árvore de busca binária normal
    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    } else {
        // Chaves duplicadas não são permitidas
        return root;
    }

    // Atualiza a altura do nó pai
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Verifica o fator de balanceamento do nó pai
    int balanceFactor = getBalanceFactor(root);

    // Realiza as rotações se necessário
    if (balanceFactor > 1) {
        // Caso left-left
        if (key < root->left->key) {
            return rotateRight(root);
        }
        // Caso left-right
       
