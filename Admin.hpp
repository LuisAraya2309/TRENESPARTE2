#include <iostream>
using namespace std;

class TreeNode {
  int *keys;
  string *nombres;
  int t;
  TreeNode **C;
  int n;
  bool leaf;

   public:
  TreeNode(int temp, bool bool_leaf);

  void insertNonFull(int k,string pnombre);
  void splitChild(int i, TreeNode *y);
  void traverse();

  TreeNode *search(int k);

  friend class BTree;
};

class BTree {
  TreeNode *root;
  int t;

   public:
  BTree(int temp) {
    root = NULL;
    t = temp;
  }

  void traverse() {
    if (root != NULL)
      root->traverse();
  }

  TreeNode *search(int k) {
    return (root == NULL) ? NULL : root->search(k);
  }

  void insert(int k,string pnombre);
};

TreeNode::TreeNode(int t1, bool leaf1) {
  t = t1;
  leaf = leaf1;

  keys = new int[2 * t - 1];
  C = new TreeNode *[2 * t];
  nombres = new string[2 * t - 1];

  n = 0;
}

void TreeNode::traverse() {
  int i;
  for (i = 0; i < n; i++) {
    if (leaf == false)
      C[i]->traverse();
    cout <<keys[i]<<"-"<<nombres[i]<<"->";
  }

  if (leaf == false)
    C[i]->traverse();
}

TreeNode *TreeNode::search(int k) {
  int i = 0;
  while (i < n && k > keys[i])
    i++;

  if (keys[i] == k)
    return this;

  if (leaf == true)
    return NULL;

  return C[i]->search(k);
}

void BTree::insert(int k,string pnombre) {
  if (root == NULL) {
    root = new TreeNode(t, true);
    root->keys[0] = k;
    root->nombres[0] = pnombre;
    root->n = 1;
  } else {
    if (root->n == 2 * t - 1) {
      TreeNode *s = new TreeNode(t, false);

      s->C[0] = root;

      s->splitChild(0, root);

      int i = 0;
      if (s->keys[0] < k)
        i++;
      s->C[i]->insertNonFull(k,pnombre);

      root = s;
    } else
      root->insertNonFull(k,pnombre);
  }
}

void TreeNode::insertNonFull(int k,string pnombre) {
  int i = n - 1;

  if (leaf == true) {
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      nombres[i+1] = nombres[i];
      i--;
    }

    keys[i + 1] = k;
    nombres[i+1] = pnombre;
    n = n + 1;
  } else {
    while (i >= 0 && keys[i] > k)
      i--;

    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]);

      if (keys[i + 1] < k)
        i++;
    }
    C[i + 1]->insertNonFull(k,pnombre);
  }
}

void TreeNode::splitChild(int i, TreeNode *y) {
  TreeNode *z = new TreeNode(y->t, y->leaf);
  z->n = t - 1;

  for (int j = 0; j < t - 1; j++){
  	z->keys[j] = y->keys[j + t];
  	z->nombres[j] = y->nombres[j+t];
  }
    

  if (y->leaf == false) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }

  y->n = t - 1;
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];

  C[i + 1] = z;

  for (int j = n - 1; j >= i; j--){
  	keys[j + 1] = keys[j];
  	nombres[j+1] = nombres[j];
  }
  keys[i] = y->keys[t - 1];
  nombres[i] = y->nombres[t-1];
  n = n + 1;
}

int main() {
  BTree t(5);
  
  t.insert(8,"Luis");
  t.insert(9,"Sebas");
  t.insert(10,"Gabriel");
  t.insert(11,"Pau");
  
  t.traverse();
}
