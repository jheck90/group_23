//Using the approach described, complete the following implementation:

struct Node {
   TYPE value;
   struct Node * left;
   struct Node * right;
};	

struct BinarySearchTree {
   struct Node *root;
   int size;
};


void initBST(struct BinarySearchTree *tree) { tree->size = 0; tree->root = 0: }

void addBST(struct BinarySearchTree *tree, TYPE newValue) {
   tree->root = _nodeAddBST(tree->root, newValue);  tree->size++; }

int sizeBST (struct BinarySearchTree *tree) { return tree->size; }

struct Node * _nodeAddBST (struct Node *current, TYPE newValue) {
   
  


}

int containsBST (struct BinarySearchTree *tree, TYPE d) {

	



}
void removeBST (struct BinarySearchTree *tree, TYPE d) {
   if (containsBST(tree, d) {
      tree->root = _nodeRemoveBST(tree->root, d);
      tree->size--;
   }
}

TYPE _leftMostChild (struct Node * current) {


}

struct node * _removeLeftmostChild (struct Node *current) {

}

  



struct Node *  _nodeRemoveBST (struct Node * current, TYPE d) {


  

 
}



