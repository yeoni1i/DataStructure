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