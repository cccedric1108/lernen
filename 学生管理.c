#include <stdio.h>
#include<string.h>
#include<stdlib.h>

//定义结构体
typedef struct node{

    char name[20];
    int number;
    struct node *next;          //指向结构体类型的指针

}NODE,*LinkList;
//LinkList head == NODE *head == struct node *head

//链表初始化 即 创建一个头结点
LinkList InitList(){

    LinkList head;      //头指针变量
    head=(NODE*)malloc(sizeof(NODE));       //头指针指向分配的头结点的内存
    head->next=NULL;        //头结点的指针域为空
    return head;        //返回头结点的地址

}

//尾插法创建单链表
void CreatByRear(LinkList head){

    NODE *s,*r;     //r是头结点，s是首结点
    char name[20];
    int number;
    r=head;     //指向头结点
    printf("please input your name and number:\n");
    while (1)
    {
        scanf("%s",&name);
        scanf("%d",&number);
        if (number==0)
        {
            break;
        }
        s=(NODE*)malloc(sizeof(NODE));      //分配结点内存空间
        strcpy(s->name,name);       
        s->number=number;
        r->next=s;      //原结点指向新结点
        r=s;        //r指向新结点

    }
    
    r->next=NULL;       //尾结点指向null

}

//头插法
void CreatByHead(LinkList head){

    NODE *s;     
    char name[20];
    int number;
    printf("please input your name and number:\n");
    while (1)
    {
        scanf("%s",&name);
        scanf("%d",&number);
        if (number==0)
        {
            break;
        }
        s=(NODE*)malloc(sizeof(NODE));      //分配结点内存空间
        strcpy(s->name,name);       
        s->number=number;
        s->next=head->next;        
        head->next=s;

    }
}
//遍历输出
void OutPut(LinkList head){

    NODE *p;        //循环用的临时指针
    p=head->next;
    while (p)
    {
        printf("%d\t%s\n",p->number,p->name);
        p=p->next;
    }
    

}
    
//主函数
/* void main(){

    LinkList ha,hb;
    ha=InitList();
    hb=InitList();
    CreatByRear(ha);
    OutPut(ha);
    CreatByHead(hb);
    OutPut(hb);

}
   */  

//在链表第i个位置插入一个新节点
void Insert(LinkList head,int i){

    NODE *p=head,*s;
    int j=0;
    while (p && j<i-1)      //找到第i-1个结点的地址
    {
        p=p->next;
        j++;        
    }
    
    if (p)
    {
        printf("please input your name and number:\n");
        s=(NODE*)malloc(sizeof(NODE));
        scanf("%s",s->name);
        scanf("%d",p->number);
        s->next=p->next;
        p->next=s;

    }
    
}

//表首位置后添加结点
void InsertHead(LinkList head){

    NODE *s;
    printf("please input your name and number:\n");
    s=(NODE*)malloc(sizeof(NODE));
    scanf("%s",s->name);
    scanf("%d",&s->number);
    s->next=head->next;
    head->next=s;

}

//在表末尾添加结点
void InsertRear(LinkList head){

    NODE *p=head,*s;
    while (p && p->next)
    {
        p=p->next;
    }
    
    if (p)
    {
    printf("please input your name and number:\n");
    s=(NODE*)malloc(sizeof(NODE));
    scanf("%s",s->name);
    scanf("%d",&s->number);
    p->next=s;
    s->next=NULL;

    }
    

}

//单链表的删除操作
void Delete(LinkList head,int pos){

    NODE *p=head,*q;        //q是指向第pos个元素的指针
    int j=0;
    printf("\n*****删除第%d个学生*****\n",pos);
    while (j<pos-1 && p)
    {
        p=p->next;
        j++;
    }
    if (p==NULL || p->next==NULL)
    {
        printf("the pos is ERROR\n");
    }
    else{

        q=p->next;
        p->next=q->next;
        free(q);

    }

}

//单链表查询
NODE *Search(LinkList head,char name[]){

    NODE *p=head->next;
    while (p)
    {
        if (strcmp(p->name,name)!=0)
        {
            p=p->next;
        }
        else 
            break;
    }
    if (p==NULL)
    {
        printf("404 not find\n");
    }
    
    return p;

}

