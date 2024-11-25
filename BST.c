#include <stdio.h>
#include <stdlib.h>
 struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the BST
Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// Function to find the minimum value node in the BST
Node* findMin(Node* root) {
    while (root && root->left != NULL) root = root->left;
    return root;
}

// Function to find the maximum value node in the BST
Node* findMax(Node* root) {
    while (root && root->right != NULL) root = root->right;
    return root;
}

// Function to search for a key in the BST
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key) return root;

    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Function for inorder traversal of the BST
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to free all nodes of the BST
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        printf("\n1. Insert\n2. Find Minimum\n3. Find Maximum\n4. Search\n5. Display (Inorder)\n6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                root = insert(root, value);
                break;
            case 2:
                if (root != NULL) {
                    printf("Minimum value: %d\n", findMin(root)->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 3:
                if (root != NULL) {
                    printf("Maximum value: %d\n", findMax(root)->data);
                } else {
                    printf("Tree is empty\n");
                }
                break;
            case 4:
                printf("Enter value to search: ");
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    while (getchar() != '\n');
                    continue;
                }
                if (search(root, value)) {
                    printf("Value %d found in the tree\n", value);
                } else {
                    printf("Value %d not found in the tree\n", value);
                }
                break;
            case 5:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}
