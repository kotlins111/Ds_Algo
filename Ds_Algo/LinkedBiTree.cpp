

/*
1.在n个结点的二叉链表中 有n+1个空指针域 线索二叉树

*/
#include <iostream>
using namespace std;
typedef char TElemType;

#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define NOTFOUND -3


//三叉链表 二叉链表新增一个prior指针 用来寻找父结点地址
typedef struct TriNode{
    TElemType data;
    TriNode *lchild,*rchild,*parent;
}TriNode,*TriTree;

//二叉树的链式存储 
typedef struct BiNode{
    TElemType data;
    BiNode *lchild,*rchild;
}BiNode,*BiTree;

typedef int Status;


typedef BiNode SElemType;


//栈的 顺序存储结构体定义

/*top 指向栈顶的上一个元素 base 指向栈底元素 
 栈的判空 base==top  
栈的判满 top-size==stacksize */
typedef struct {
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;


//顺序栈的初始化
Status InitStack(SqStack &s){
    s.base = new SElemType[MAXSIZE];
    if (!s.base)
    {
        /* code */
        exit(OVERFLOW);
    };
    s.top = s.base; //栈顶指针等于栈底指针 空栈
    s.stacksize =MAXSIZE;
    return OK;
}

//栈的判空
bool StackEmpty(SqStack s){

    return s.base == s.top;
}

//栈的判满
bool StackFull(SqStack s){
    return (s.top-s.base)==s.stacksize;
}
//求栈的长度
int StackLength(SqStack s){
    return s.top-s.base;
}

//清空顺序栈
Status ClearStack(SqStack S){
    if(S.base){
        S.top =S.base;
    }
    return OK;
}

//销毁一个顺序栈

Status DestroyStack(SqStack &s){
    if(s.base){
        delete s.base; //只是释放了base指针后的一段数组内存空间 指针的指向没有改变
        s.stacksize=0;
        s.base=s.top=NULL;
    }
    return OK;
}

/*
顺序栈的入栈 
1.判断栈是是否已经满
2.元素e压入栈顶
3.top指针上移*/
Status Push(SqStack &S,SElemType e){
    if (StackFull(S)) return ERROR;
    *S.top = e;
    S.top++; //top指针上移
    // *S.top++=e;
    return OK;
}

/*顺序栈的出栈
1.栈判空
2.top--
3.获取栈顶元素e 
*/
Status Pop(SqStack &S,SElemType &e){
    if(StackEmpty(S)) return ERROR;
    --S.top;
    e=*S.top;
    //e=*--S.top;
    return OK;
}

/*
二叉树的遍历
1.先序遍历(PreOrderTraverse)
先访问根结点，再访问左子树 最后访问右子树

2.中序遍历(InOrderTraverse)

左子树->根节点->右子树

3.后序遍历(PostOrderTraverse)
左子树->右子树->根节点
*/
void opeartion(BiNode *T);
Status PreOrderTraverse(BiTree T){
    if(T==NULL) return OK;
    else{
        opeartion(T); 
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
}

Status InOrderTraverse(BiTree T){
    if(T==NULL) return OK;
    else{
        InOrderTraverse(T->lchild);
        opeartion(T);
        InOrderTraverse(T->rchild);
    }
    return OK;
}


Status PostOrderTraverse(BiTree T){
    if(T==NULL) return OK;
    else{
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        opeartion(T); 
    }
    return OK;
}

void opeartion(BiNode *T){
    printf("%d\t",T->data);
}


//非递归遍历二叉树  使用辅助栈

Status InOrderTraverse_(BiTree T){
    BiTree p,q;
    SqStack S;
    InitStack(S);
    p=T;
    while (p||!StackEmpty(S))
    {
        /* code */
        if(p){
            Push(S,p); p=p->lchild;
        }else{
            Pop(S,q); opeartion(q);
            p=q->rchild;
        }
    }
    return OK;
}

int main(){
    return 0;
}
