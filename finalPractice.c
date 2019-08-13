#define TYPE int
struct hlink
{
    TYPE value;
    struct hlink *next;
};
struct hashTable
{
    struct hlink **table;
    int tablesize;
    int count;
};

int hashTableContains(struct hashTable *ht, TYPE testElement)
{
    int hash = HASH(testElement) % ht->tablesize;

    struct hlink *curr = ht->table[hash];
    while (curr != NULL)
    {
        if (curr->value == testElement)
            return 1;
        curr = curr->next;
    }

    return 0;
}

//Worksheet 29

struct Node
{
    TYPE value;
    struct Node *left;
    struct Node *right;
};
struct BinarySearchTree
{
    struct Node *root;
    int size;
};

struct Node *_nodeAddBST(struct Node *current, TYPE newValue)
{

    if (current == NULL)
    {
        struct Node *newNode = malloc(sizeof(struct Node));
        assert(newNode);
        newNode->value = newValue;
        newNode->left = newNode->right = NULL;
        return (newNode);
    }

    if (newValue < current->value)
        current->left = _nodeAddBST(current->left, newValue);
    else
    {
        current->right = _nodeAddBST(current->right, newValue);
    }
    return current;
}

int containsBST(struct BinarySearchTree *tree, TYPE d)
{

    assert(tree && tree->root);
    struct Node *curr = tree->root;
    while (curr != NULL)
    {
        if (compare(curr->value, d) == 0)
            return 1;
        else if(curr->value > d)
            curr = curr->left;
        else
        {
            curr = cur-r>right;
        }
        
    }

    return 0
}

void removeBST(struct BinarySearchTree *tree, TYPE d)
{
if (containsBST(tree, d) {
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
}
}
TYPE _leftMostChild (struct Node * current){
    assert(current)
    while(current->left != 0){
        current = current->left;
    }
    return current->value;
}

struct node * _removeLeftmostChild (struct Node *current) {
    if(current->left == NULL){
        struct  Node * temp = current->right;
        free(current);
        return temp;
    }
    else{
        current->left =  _removeLeftmostChild(current);
        return current;
    }
}

struct Node * _nodeRemoveBST (struct Node * current, TYPE d) {
    if(current->value == d){
        if(current->right == NULL){
            struct Node* temp = current;
            current = temp->left;
            free(temp);
        }
        else{
            current->value = _leftMostChild(current->right);
            current->right = _removeLeftmostChild(current->right);
        }
    }else{
        if(current->value > d)
        current->left = _nodeRemoveBST(current->left, d);
        else         current->right = _nodeRemoveBST(current->left, d);

    }
}


//Worksheet 31

struct AVLnode * _rotateLeft (struct AVLnode * current) {
    assert(current);
    struct AVLnode * newTop = current->right;
    current->right = newTop->left;
    newTop->left = current;
    setHeight(current);
    setHeight(newTop);
    return newTop;
}

struct AVLnode * _rotateRight (struct AVLnode * current) {
    assert(current);
    struct AVLnode * newTop = current->left;
    current->left = newTop->right;
    newTop->right = current;
    setHeight(current);
}


struct AVLNode *_removeNode(struct AVLNode *cur, TYPE val) {
    if(cur == val){
        if(curr->right == NULL){
            struct AVLNode * temp = cur->left;
            free(cur);
            return temp;
        }
        else{
            curr->val = _leftMost(cur);
            curr->right = _removeLeftmostChild(curr->right);
            return cur;
        }
    }
    if(val < curr->val){
        cur->left = _removeNode(cur->left, val);
    }
    else{
        curr->right = _removeNode(cur->right, val);
    }

    return _balance(cur);
}

//Worksheet 32

void treeSort (TYPE *data, int n){
    AVLtree tree;

    AVLtreeInit(&tree);
    for(int i = 0; i < n; i++){
        AVLTreeAdd(&tree, data[i]);
    }

    AVLItr* itr = initItr(&tree);

    i = 0;
    while(AVLItrHasNext(&itr)){
        data[i++] = AVLItrNext(&itr);
    }

}