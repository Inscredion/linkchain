// linkchain.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include <stdio.h>
#include<stdlib.h>
#include"linklist.h"

int main()
{
    Node* p = CreateList(4);
    Visit(p);
    //AlterNode(p, 1,-1);
    //Visit(p);
    //DeleteNode(p, 2);  
    //Visit(p);
   AddNode(p, 0, -1);
   Visit(p);
    return 0;
}



