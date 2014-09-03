/******************************** *
* Convert a binary tree to a list *
* No additional node can be used  *
* ********************************/

#include <iostream>
#include <vector>

struct Node
{
  Node(int v, Node* l, Node* r): value(v), left(l), right(r) {}

  int value;
  Node* left;
  Node* right;
};

//create a sample
//       10
//      /  \
//     6     14
//    / \   /  \
//   4   8 12   16

Node* createSample()
{
  static std::vector<int> insertNums = {10, 6, 14, 4, 8, 12, 16};
  Node* root = NULL;
  for(int i: insertNums)
  {
    if(!root)
    {
      root = new Node(i, NULL, NULL);
      continue;
    }

    Node** temp = &root;
    while(*temp)
    {
      Node*& p = *temp;
      temp = (i < p->value) ? &(p->left) : &(p->right);
    }
    
    *temp = new Node(i, NULL, NULL);
  }

  return root;
}

void printSample(Node* root)
{
  if(root->left)
  {
    printSample(root->left);
  }

  if(root)
  {
    std::cout << root->value << " " << std::endl;
  }

  if(root->right)
  {
    printSample(root->right);
  }
}

Node* convertTreeToList(Node* n, Node* last)
{
  if(!n)
  {
    return NULL;
  }

  Node* ret = NULL;

  if(n->right)
  {
    last = convertTreeToList(n->right, last);
  }
  
  if(last)
  {
    last->left = n;
  }
  n->right = last;
  ret = n;

  if(n->left)
  {
    ret = convertTreeToList(n->left, n);
  }

  return ret;
}

int main()
{
  Node* root = createSample();
  //printSample(root);

  Node* head = convertTreeToList(root, NULL);
  
  Node* temp = head;
  while(temp)
  {
    std::cout << temp->value << " " << std::endl;
    temp = temp->right;
  }

  return 0;
}

