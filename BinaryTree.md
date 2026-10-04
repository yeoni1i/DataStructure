# 📌 이진트리 노드 클래스

## 1. 개념

> 이 개념이 무엇인지 한두 문장으로 정리

내용 작성`BinaryNode`는 이진 트리(Binary Tree)를 구성하는 하나의 노드를 표현하는 클래스이다.

하나의 노드는 다음 세 가지 정보를 가진다.

- 저장할 데이터
- 왼쪽 자식 노드
- 오른쪽 자식 노드
---

## 2. 왜 사용하는가?
left에는 BinaryNode 객체 자체가 들어가는 것이 아니라
다른 BinaryNode 객체의 주소가 저장된다.
즉, 현재 노드 → 왼쪽 자식 노드와 같은 연결 관계를 만들 수 있다.
---

## 3. 기본 문법

```cpp
//생성자
BinaryNode(
    int val = 0,
    BinaryNode* l = NULL,
    BinaryNode* r = NULL
)
    : data(val),
      left(l),
      right(r)
{}
'''

객체를 생성하면서
- data ← val
- left ← l
- right ← r
로 초기화(변수를 만들자마자 처음 값을 정해주는 것)한다. 초기화를 하지 않으면 자동으로 우리가 원하는 값이 된다고 보장할 수 없음