#ifndef LINKLIST_H
#define LINKLIST_H

struct Node
{
    int val;
    Node* next;
};

void NullErr(); //链表为空报错
void OutOfRange(); //索引超出范围报错

Node* CreateNode(int newVal);   //创建节点
void AddTailNode(Node* newNode, Node* node);    //尾部增加节点
void DeleteTailNode(Node* node);    //删除尾部节点
Node* CreateList(int len);      //创建链表
void Visit(Node* node);      //遍历链表
bool SearchNode(Node* node, int newVal);    //查找节点
void DeleteNode(Node* node, int index);     //删除节点
void AddNode(Node* node, int index, int newVal);    //增加节点
void AlterNode(Node* node, int index, int newVal);      //修改节点
void DestroyList(Node* node);   //销毁链表
int ListLength(Node* node);     //链表长度

#endif
