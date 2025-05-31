#include <iostream>
using namespace std;


struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int height(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

void updateHeight(Node* node) {
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
}

Node* insert(Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else 
        return node;

    updateHeight(node);

    int balance = getBalance(node);


    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else 
                *root = *temp;

            delete temp;
        }
        else {
            Node* temp = minValueNode(root->right);

            
            root->key = temp->key;

          
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    updateHeight(root);

    int balance = getBalance(root);


    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

bool search(Node* root, int key) {
    if (root == NULL)
        return false;

    if (root->key == key)
        return true;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void NLR(Node* root) {
    if (root != NULL) {
        cout << root->key << " ";
        NLR(root->left);
        NLR(root->right);
    }
}

void LNR(Node* root) {
    if (root != NULL) {
        LNR(root->left);
        cout << root->key << " ";
        LNR(root->right);
    }
}

void LRN(Node* root) {
    if (root != NULL) {
        LRN(root->left);
        LRN(root->right);
        cout << root->key << " ";
    }
}


void destroyTree(Node* root) {
    if (root != NULL) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}

void test() {
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

   

    cout << "Sau them:" << endl;
    cout << "NLR: "; NLR(root); cout << endl;  
    cout << "LNR: "; LNR(root); cout << endl;   
    cout << "LRN: "; LRN(root); cout << endl;  
    cout << "Tree height: " << height(root) << endl;    
    cout << "Can Bang: " << (abs(getBalance(root)) <= 1 ? "Yes" : "No") << endl; 


    cout << "\nSearch 25: " << (search(root, 25) ? "Found" : "Not found") << endl;
    cout << "Search 35: " << (search(root, 35) ? "Found" : "Not found") << endl;  


    root = deleteNode(root, 10);
    root = deleteNode(root, 20);

    cout << "\nSau Xoa:" << endl;
    cout << "NLR: "; NLR(root); cout << endl;   
    cout << "LNR: "; LNR(root); cout << endl;    
    cout << "LRN: "; LRN(root); cout << endl;  
    cout << "Tree height: " << height(root) << endl;     
    cout << "Can Bang: " << (abs(getBalance(root)) <= 1 ? "Yes" : "No") << endl; 

 

    
}
int main() {
	test();
	return 0;
}