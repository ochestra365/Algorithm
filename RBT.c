#include "RTT.h"
#include <stdlib.h>
void RBT_SET()
{
  NIL=(RBTNode*)malloc(sizeof(RBTNode));
  NIL->color=BLACK;
}
void RBT_RotateRight(RBTNode** root, RBTNode* parent)
{
 RBTNode* leftChild=parent->left;
  parent->left=leftChild->right;
  if(leftChild->right!=NIL) leftChild->right->parent=parent;
  leftCHild->parent=parent->parent;
  if(parent->parent==NULL)(*root)=leftChild;
  else{
   if(parent==parent->parent->left) parent->parent->left=leftChild;
    else parent->parent->right=leftChild;
  }
  leftChild->right=parent;
  parent->parent=leftChild;
}
void RBT_RotateLeft(RBTNode** root, RBTNode* parent)
{
RBTNode* rightChild=parent->right;
  parent->right=rightChild->left;
  if(rightChild->left!=NIL) rightChild->left->parent=parent;
  rightChild->parent=parent->parent;
  if(parent->parent==NULL)(*root)=rightChild;
  else{
   if(parent==parent->parent->right)parent->parent->right;
    else parent->parent->left=rightChild;
  }
  rightChild->left=parent;
  parent->parent=rightChild;
}
void RBT_InsertNode(RBTNode** root, RBTNode){
  //BST처럼 재귀를 통해 노드 삽입
RBT_InsertNodeHelper(root,newNode);
  //새 노드에 색을 칠하고 자식 NIL을 연결
  newNode->color=RED;
  newNode->left=NIL;
  newNode->right=NIL;
  
  //무너진 RBT 규칙 조정
  RBT_RebuildAfterInsert(root,newNode);
}
void RBT_InsertNodeHelper(RBTNode** root, RBTNode* newNode)
{
  RBTNode* tree=(*root);
  if(tree->data < newNode->data)
  {
    if(tree->right==NULL)
    {
      tree->right=newNode;
      newNode->parent=tree;
    }
    else RBT_InsertNodeHelper(&tree->right,newNode);
  }
  else if(tree -> data > newNode->data)
  {
   if(tree->left==NULL)
   {
     tree->left=newNode;
     newNode->parent=tree;
   }
    else RBT_InsertNodeHelper(&tree->left,newNode);
  }
  
  void RBT_RebuildAfterInsert(RBTNode** root, RBTNode* node)
  {
   while(node!=(*root)&&node->parent->color==RED)
   {
    if(node->parent==node->parent->parent->left){
     RBTNode* uncle=node->parent->parent->right;
      if(uncle->color==RED)
      {
        node->parent->color=BLACK;
        uncle->color=BLACK;
        node->parent->parent->color=RED;
      }
      else{
       if(node==node->parent->right)
       {
         node=node->parent;
         RBT_RotateLeft(root,node);
       }
        node->parent->color=BLACK;
        node->parent->parent->color=RED:
        RBT_RotateRight(root, node->parent->parent);
      }
    }
     else{
      RBTNode* uncle=node->parent->parent->left;
       if(uncle->color==RED)
       {
         node->parent->color=BLACK;
         uncle->color=BLACK;
         node->parent->parent->color=RED;
       }
       else{
         if(node==node->parent->left){
          node=node->parent;
           RBT_RotateRight(root,node);
         }
         node->parent->color=BLACK;
         node->parent->parent->color=RED;
         RBT_RotateLeft(root,node->parent->parent);
       }
     }
   }
    (*root)->color=BLACK;
  }
}
