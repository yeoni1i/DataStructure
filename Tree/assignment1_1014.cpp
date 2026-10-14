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
        BinaryNode* l = NULL,
        BinaryNode* r = NULL
    )
        : data(val),
        left(l),
        right(r) {
    }

    //소멸자 : 객체가 사용하던 자원을 정리하기 위해서 필요
    ~BinaryNode() {}

    void setData(int val) { data = val; }
    void setLeft(BinaryNode* l) { left = l; }
    void setRight(BinaryNode* r) { right = r; }

    int getData() { return data; }
    BinaryNode* getLeft() { return left; }
    BinaryNode* getRight() { return right; }

    bool isLeaf() {
        return left == NULL && right == NULL;
    }
};


//BinaryTree 클래스
class BinaryTree : public BinaryNode
{
public:

    BinaryNode* root;

    //생성자
    BinaryTree() : root(NULL) {}

    //소멸자 
    ~BinaryTree() {}

    void setRoot(BinaryNode* node) { root = node; }
    BinaryNode* getRoot() { return root; }
    bool isEmpty() { return root == NULL; }


    int getCount(BinaryNode* node) {
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
    int getHeight(BinaryNode* node) {
        if (node == NULL)
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

    int getCount() {
        return getCount(root);
    }

    int getLeafCount() {
        return getLeafCount(root);
    }

    int getHeight() {
        return getHeight(root);
    }
};


//BST 클래스
class BST : public BinaryTree
{
public:
    BST() {}
    ~BST() {}

    BinaryNode* search(int key);
    BinaryNode* search(BinaryNode* n, int key);
    void insert(BinaryNode* n);
    void insert(BinaryNode* r, BinaryNode* n);
    void remove(int key);
    void remove(BinaryNode* parent, BinaryNode* n);
    void inorder(BinaryNode* n);
};

//매개변수 없는 버전(호출용
BinaryNode* BST::search(int key) {

    BinaryNode* node = search(getRoot(), key);

    if (node != NULL)
        cout << "탐색 성공 : 키 값이 " << node->getData() << " 인 노드 = 0x " << node << endl;
    else
        cout << "탐색 실패 : 키 값이 " << key << "인 노드 없음" << endl;

    return node;
}

BinaryNode* BST::search(BinaryNode* n, int key) {
    if (n == NULL)
        return NULL;
    if (key == n->getData())
        return n;

    else if (key < n->getData())
        return search(n->getLeft(), key);

    else(key > n->getData());
    return search(n->getRight(), key);
}

void BST::insert(BinaryNode* n) {
    if (n == NULL)
        return;

    if (isEmpty())
        setRoot(n);

    else
        insert(getRoot(), n);
}

//r = 현재 비교하고 있는 노드
//n = 새로 삽입하려는 노드
void BST::insert(BinaryNode* r, BinaryNode* n) {
    //중복 노드 있는지 확인
    if (n->getData() == r->getData())
        return;

    else if (n->getData() < r->getData()) {
        if (r->getLeft() == NULL)
            r->setLeft(n);
        else
            insert(r->getLeft(), n);
    }

    else {
        if (r->getRight() == NULL)
            r->setRight(n);
        else
            insert(r->getRight(), n);
    }
}

void BST::remove(int key) {
    BinaryNode* parent = NULL;
    BinaryNode* node = root;

    while (node != NULL) {
        if (key == node->getData())
            break;

        parent = node;

        if (key < node->getData())
            node = node->getLeft();
        else
            node = node->getRight();
    }

    if (node == NULL) {
        cout << "삭제할 노드가 없습니다." << endl;
        return;
    }

    remove(parent, node);
}



void BST::remove(BinaryNode* parent, BinaryNode* n) {
    if (n == NULL)
        return;

    BinaryNode* child;

    // case 1: 삭제하려는 노드가 리프 노드인 경우
    if (n->isLeaf()) {
        if (parent == NULL)
            root = NULL;
        else {
            if (parent->getLeft() == n)
                parent->setLeft(NULL);
            else
                parent->setRight(NULL);
        }
    }

    // case 2: 삭제하려는 노드가 자식을 하나만 가진 경우
    else if (n->getLeft() == NULL || n->getRight() == NULL) {

        if (n->getLeft() != NULL)
            child = n->getLeft();
        else
            child = n->getRight();

        if (n == root)
            root = child;
        else {
            if (parent->getLeft() == n)
                parent->setLeft(child);
            else
                parent->setRight(child);
        }
    }

    // case 3: 삭제하려는 노드가 자식을 두 개 가진 경우
    else {
        BinaryNode* succp = n;
        BinaryNode* succ = n->getRight();

        while (succ->getLeft() != NULL) {
            succp = succ;
            succ = succ->getLeft();
        }

        if (succp->getLeft() == succ)
            succp->setLeft(succ->getRight());
        else
            succp->setRight(succ->getRight());

        n->setData(succ->getData());
        n = succ;
    }

    delete n;
}

void BST::inorder(BinaryNode* n) {
    if (n == NULL)
        return;

    inorder(n->getLeft());
    cout << n->getData();
    inorder(n->getRight());
}


int main()
{

    BST tree;
    int N;
    // 갯수
    char op;
    int number;
    // 연산자 I, D
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> op;
        cin >> number;
        switch (op)
        {
        case 'I': tree.insert(new BinaryNode(number));
            break;
        case 'D': tree.remove(number);
            break;
        }
    }
    tree.inorder(tree.getRoot());
}
