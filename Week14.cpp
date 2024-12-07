#include <iostream>
using namespace std;

const int MAX = 100;

struct Node {
    char val;
    Node* left; 
    Node* right;
};
typedef struct Node* PNode;
bool isEmpty(PNode T) {
    return T == NULL;
}

PNode createNode(char data) {
    PNode node = new Node;
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

typedef struct stack {
    int Top;
    PNode data[MAX];
} stack;

void init(stack& s) {
    s.Top = 0;
}

bool isempty(stack& s) {
    return s.Top == 0;
}

bool isfull(stack& s) {
    return s.Top == MAX;
}

void push(stack& s, PNode t) {
    if (isfull(s)) {
        cout << "Stack Overflow" << endl;
    }
    else {
        s.data[s.Top++] = t;
    }
}

PNode pop(stack& s) {
    if (isempty(s)) {
        cout << "Stack Underflow" << endl;
    }
    else {
        PNode x = s.data[--s.Top];
        return x;
    }
}

PNode top(stack s) {
    return s.data[s.Top];
}

PNode constructTree(const char* s) {
    stack st;
    init(st);  
    PNode t = NULL;
    int i = strlen(s) - 1;  

    while (i >= 0) {
        if (!isOperator(s[i])) {
            t = createNode(s[i]);
            push(st, t);  
        }
        else {
            t = createNode(s[i]);  
            t->left = pop(st);  
            t->right = pop(st); 
            push(st, t);       
        }
        i--;
    }
    t = pop(st);  
    return t;
}

void TienTo(PNode root) {
    if (root != NULL) {
        cout << root->val;
        TienTo(root->left);
        TienTo(root->right);
    }
}
void TrungTo(PNode root) {
    if (root != NULL) {
        if (root->left || root->right) cout << "(";
        TrungTo(root->left);
        cout << root->val;
        TrungTo(root->right);
        if (root->left || root->right) cout << ")";
    }
}
void HauTo(PNode root) {
    if (root != NULL) {
        HauTo(root->left);
        HauTo(root->right);
        cout << root->val;
    }
}

int main() {
    Node* T = constructTree("+-*a5*b/^c6d*-hf^e/12");
    cout << "Tien to: ";
    TienTo(T);
    cout << endl;
    cout << "Trung to: ";
    TrungTo(T);
    cout << endl;
    cout << "Hau to: ";
    HauTo(T);
    return 0;
}