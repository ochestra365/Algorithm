#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//레드블랙트리는 균형이진탐색트리를 업그레이드한 버전이다.--> 완전 균형이진탐색트리
/*
1. 모든 노드는 빨간색 또는 검은색의 색을 가진다.
2. 루트 노드는 검은색이다.
3. 잎 노드는 검은색이다.
4. 빨간 노드의 자식은 모두 검은색이다. 하지만 검은색 노드의 자식이 빨강일 필요는 없다.
(레드 노드는 연달아 나타날 수 없으며, 블랙 노드만이 레드 노드의 부모 노드가 될 수 있다.)
5. 루트 노드에서 모든 잎 노드 사이에 존재한느 검은색 노드의 수는 모두 동일하다.
*/

enum Color{RED, BLACK};//레드 블랙 트리 열거체
struct RBTNode{
  struct RBTNode* parent; //부모 포인터
  struct RBTNode* left;//좌측 포인터
  struct RBTNode* right;//우측 포인터
  
  int data;
  enum Color color;
};
static RBTNode* NIL;//leaf

void RBT_SET();//레드블랙트리 세팅

void RBT_RotateRight(RBTNode** root, RBTNode * parent);//우회전에 필요한 매개변수는 root와 해당 노드의 부모 노드이다.
void RBT_RotateLeft(RBTNode** root, RBTNode* parent);//

