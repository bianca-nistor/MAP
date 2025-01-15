#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structura nodului arborelui
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Funcția pentru a crea un nou nod
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Funcția pentru a insera un nod în BST
Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Traversarea în pre-ordine
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Traversarea în in-ordine
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Traversarea în post-ordine
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Funcția pentru traversarea pe niveluri (level-order traversal)
void levelOrderTraversal(Node* root) {
    if (root == NULL) return;

    // Coadă pentru a stoca nodurile pe niveluri
    Node* queue[100];
    int front = 0, rear = 0;
    
    queue[rear++] = root;  // Inserare rădăcină în coadă
    
    while (front < rear) {
        Node* currentNode = queue[front++];
        
        printf("%d ", currentNode->data);
        
        if (currentNode->left != NULL) {
            queue[rear++] = currentNode->left;
        }
        if (currentNode->right != NULL) {
            queue[rear++] = currentNode->right;
        }
    }
}

// Funcția principală
int main() {
    Node* root = NULL;

    // Inițializare generator de numere aleatorii
    srand(time(0));

    // Generare și inserare elemente aleatorii
    int n = 10;  // Numărul de elemente de inserat
    printf("Elementele inserate: ");
    for (int i = 0; i < n; i++) {
        int elem = rand() % 100;  // Generare număr aleator între 0 și 99
        printf("%d ", elem);
        root = insert(root, elem);
    }
    printf("\n");

    printf("Pre-ordine: ");
    preorderTraversal(root);
    printf("\n");

    printf("In-ordine: ");
    inorderTraversal(root);
    printf("\n");

    printf("Post-ordine: ");
    postorderTraversal(root);
    printf("\n");

    printf("Pe nivel: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
