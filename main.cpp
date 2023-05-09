#include <stdio.h>
#include <stdlib.h>
// types of operation
typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV
} TypeTag;
// implementation of Node
typedef struct Node {
    TypeTag type;
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// fibonacci function using dynamic programming
int fibonacci(int n,int y){
    n = abs(n);
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n-1; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n-1];
}

// function to calculate the value of a node
int calc(Node* node) {
    // base case
    if(node->value!=NULL){
        return node->value;
    }
        // calculate fibonacci
    else if(node->right->type ==NULL){
        return fibonacci(calc(node->left),0);
    }
    else if(node->left->value ==NULL){
        return fibonacci(calc(node->right),0);
    }
        // add operation
    else if (node->type == ADD) {
        return calc(node->left) + calc(node->right);
    }
        // sub operation
    else if (node->type == SUB) {
        return calc(node->right) - calc(node->left);
    }
        // mul operation
    else if (node->type == MUL) {
        return calc(node->left) * calc(node->right);
    }
        // divide operation
    else if (node->type == DIV) {
        return calc(node->right) / calc(node->left);
    } else
    {
        printf("Invalid node type %d\n", node->type);
        exit(1);
    }
}

//add function
Node *addFun(int value1, int value2) {
    // Allocate memory to our new node and its type
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->type = ADD;
    newNode->value=NULL;

    // Allocate memory to left and right node
    Node *left = (Node *) malloc(sizeof(Node));
    Node *right = (Node *) malloc(sizeof(Node));
    // Assign value to the left node
    left->value=value1;
    left->type=(TypeTag)value1;
    // Assign value to the right node
    right->value=value2;
    right->type=(TypeTag)value2;

    newNode->left=left;
    newNode->right=right;
    return newNode;
}



//sub function
Node *subFun(int value1, int value2){
    // Allocate memory to our new node and its type
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = SUB;
    newNode->value=NULL;
    // Allocate memory to left and right node
    Node *left = (Node *) malloc(sizeof(Node));
    Node *right = (Node *) malloc(sizeof(Node));
    // Assign value to the left node
    left->value= value1;
    left->type= (TypeTag)value1;
    // Assign value to the right node
    right->value=value2;
    right->type=(TypeTag)value2;

    newNode->left=left;
    newNode->right=right;
    return newNode;
}
//mul function
Node *mulFun(int value1, int value2){
    // Allocate memory to our new node and its type
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = MUL;
    newNode->value=NULL;
    // Allocate memory to left and right node
    Node *left = (Node *) malloc(sizeof(Node));
    Node *right = (Node *) malloc(sizeof(Node));
    // Assign value to the left node
    left->value=value1;
    left->type=(TypeTag)value1;
    // Assign value to the right node
    right->value=value2;
    right->type=(TypeTag)value2;

    newNode->left=left;
    newNode->right=right;
    return newNode;
}
//divide function
Node *divideFun(int value1, int value2){
    // Allocate memory to our new node and its type
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = DIV;
    newNode->value=NULL;
    // Allocate memory to left and right node
    Node *left = (Node *) malloc(sizeof(Node));
    Node *right = (Node *) malloc(sizeof(Node));
    // Assign value to the left node
    left->value=value1;
    left->type=(TypeTag)value1;
    // Assign value to the right node
    right->value=value2;
    right->type=(TypeTag)value2;

    newNode->left=left;
    newNode->right=right;
    return newNode;
}

// function to create a new node with its type and its left and right node
Node *(*makeFunc(TypeTag type))(int x,int y) {
    switch (type) {
        case ADD:
            return &addFun;
        case SUB:
            return &subFun;
        case MUL:
            return &mulFun;
        case DIV:
            return &divideFun;
        default:
            return NULL;
    }
}

int main() {
    Node *add = (*makeFunc(ADD))(10,6);
    Node *mul = (*makeFunc(MUL))(4,5);
    Node *sub = (*makeFunc(SUB))(calc(mul), calc(add));
    Node *fibo = (*makeFunc(SUB))(calc(sub),NULL);

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));
    return 0;
}




