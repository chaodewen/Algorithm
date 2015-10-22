//
//  main.cpp
//  ReverseLinkedList
//
//  Created by Dewen Chao on 15/10/22.
//  Copyright © 2015年 Dewen Chao. All rights reserved.
//

#include <iostream>

using namespace std;

struct Node {
    char content;
    Node *next;
};

// 一般都会用到Node *类型
typedef Node *pNode;

// 创建链表的函数，注意要使用引用类型
void insertLinkedList(pNode &pHead, char content) {
    if(pHead == NULL) {
        pHead = new Node;
        pHead -> content = content;
        pHead -> next = NULL;
    }
    else {
        pNode p = pHead;
        while(p -> next) {
            p = p -> next;
        }
        p -> next = new Node;
        p -> next -> content = content;
        p -> next -> next = NULL;
    }
}

// 链表反序函数，遍历逐个进行顺序调整，还有一种方法是入栈出栈进行反序
// 此处注意要使用引用类型
void reverseLinkedList(pNode &pHead) {
    if(pHead && (pHead -> next)) {
        // 上述判断保证至少有两个节点，因为没有节点和一个节点的情况都无需处理
        // 若以下声明写在判断之前则pHead有可能是NULL，再调用pHead -> next会出错
        pNode pNew = pHead, pOld = pHead -> next, pHeadBackup = pHead;
        while(pOld) {
            // pNew为当前要放在pHead位置的节点
            pNew = pOld;
            // pOld变为下一个要处理的节点
            pOld = pOld -> next;
            // pNew的下一个节点变为之前pHead位置的节点
            pNew -> next = pHead;
            // pHead的下一个节点变为pNew
            pHead = pNew;
        }
        pHeadBackup -> next = NULL;
    }
}

// 释放链表空间
void destroyLinkedList(pNode pHead) {
    // pHead为NULL时无需操作
    while(pHead) {
        pNode p = pHead;
        delete p;
        pHead = pHead -> next;
    }
}

void printLinkedList(pNode pHead) {
    pNode p = pHead;
    while(p) {
        cout << p -> content << " ";
        p = p -> next;
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    char c = 'A';
    pNode pHead = NULL;
    
    srand((unsigned int) time(NULL));
    
    for(int i = 0; i < rand() % 11; i ++) {
        insertLinkedList(pHead, c + rand() % 26);
    }
    printLinkedList(pHead);
    reverseLinkedList(pHead);
    printLinkedList(pHead);
    // 注意释放空间
    destroyLinkedList(pHead);
    
    return 0;
}
