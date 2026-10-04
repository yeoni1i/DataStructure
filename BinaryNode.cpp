#include <iostream>
using namespace std;

class BinaryNode
{
    public:
    //멤버 변수 선언
    int data;
    BinaryNode* left;
    BinaryNode* right;

    //생성자
    BinaryNode(
        int val = 0, //노드에 저장할 값 
        BinaryNode* l =NULL,
        BinaryNode* r=NULL
    )
    : data (val),
    left(l),
    right(r){}

    //소멸자 : 객체가 사용하던 자원을 정리하기 위해서 필요
    ~BinaryNode(){}

    void setData(int val) {data = val;}
    void setLeft( BinaryNode* l) {left =l;}
    void setLeft( BinaryNode* r) {right=r;}

    int getData() { return data; }
    BinaryNode* getLeft() { return left;}
    BinaryNode* getRight() { return right;}

    bool isLeaf() {
    return left == NULL && right == NULL;}
 };


 //BinaryTree 클래스
 class BinaryTree
{
    BinaryNode* root;

    public:
    //생성자
    BinaryTree() : root(NULL){}

    //소멸자 
    ~BinaryTree(){}

    void setRoot( BinaryNode* node) {root=node;}
    BinaryNode* getRoot() {return root;}
    bool isEmpty() { return root==NULL;}

    //트리 작업
    //노드개수
    int getCount( BinaryNode* node){
        if (node == NULL)
            return 0;
        
            return 1
        + getCount(node->getLeft())
        + getCount(node->getRight());
}

    //단말노드 개수
    int getLeafCount(BinaryNode* node) {
    if (node == NULL)
        return 0;

    if (node->isLeaf())
        return 1;

    else
        return getLeafCount(node->getLeft())
             + getLeafCount(node->getRight());
}

    //트리 높이
    int getHeight(BinaryNode* node){
        if(node == NULL)
            return 0;
        int hLeft = getHeight(node->getLeft()); // 왼쪽 서브트리의 높이
        int hRight = getHeight(node->getRight());  // 오른쪽 서브트리의 높이

        if (hLeft > hRight) {
             return 1 + hLeft;
        }
        else {
             return 1 + hRight;
        }
    } 
 };
