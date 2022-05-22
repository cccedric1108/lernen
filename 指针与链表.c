#include<stdlib.h>
#include<alloc.h>

4个函数头文件  stdlib.h 和 alloc.h
动态分配一段内存空间函数  malloc(){
        
    申请长度为 size大小的连续空间  返回指向存储空间起始地址的指针
    例如
        int *p = (int*)malloc(sizeof(int));
        struct stud *p = (struct stud*)malloc(sizeof(struct stud));

/* 
#include <stdio.h>
#include<stdlib.h>

void main(){

    int *pi=(int*)malloc(sizeof(int));
    *pi=100;
    printf("%d",*pi);

}
 */


}

动态分配连续内存空间函数calloc(){

    申请n个长度为size字节的存储空间，并返回空间的其实地址
        int *p = (int*)calloc(10,sizeof(int));
        等价于
        int *p = (int*)malloc(sizeof(int)*10);


>
//创建连续内存存储空间，realloc与malloc
/* void main(){

    char *ch1=(char*)malloc(26*sizeof(char));
    char *ch2=(char*)calloc(26,sizeof(char));

    for (int i = 0; i < 26; i++)
    {
        ch1[i]=65+i;//等价 *(ch1+i)=65+i
        ch2[i]=97+i;

    }
    
    printf("26个大写字母:\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c",ch1[i]);
        printf("\n");
    }
    
    printf("26个小写字母:\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c",ch2[i]);
        printf("\n");
    }
    

}
 */

}

改变指针指向空间大小的函数realloc(){

    将指针指向大小改变为大小为size的空间，返回值是指向新地址的指针

    double *p = (double*)malloc(sizeof(double));
    int *p = realloc(p,sizeof(int));

//realloc()重新分配内存
/*     void main(){

    int *q;
    double *p=(double*)malloc(sizeof(double));
    printf("指针p指向内存空间起始地址： %p\n",p);
    printf("指针p指向内存空间大小，%d字节\n",sizeof(*p));
    q=realloc(p,sizeof(int));
    printf("指针q指向内存空间的起始地址：%p\n",q);
    printf("指针q指向内存空间的大小，%d字节\n",sizeof(*q));
    

} */

}

释放存储空间函数free(){

/* void main(){

    int *p;
    p=(int*)malloc(sizeof(int));
    *p=200;
    printf("%d\n",*p);
    free(p);
    printf("%d",*p);


} */
}



单链表{

特点 
1)head指针变量，指向头结点地址
2)头结点指针域 head->next 存放首元素结点的地址
3)每个结点含有 数据域 和 指针域 
4)最后一个结点指针域为空指针 NULL 即 尾指针
5)相邻结点物理位置不一定相连

学生管理_初始化，创建，输出
/* //定义结构体
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
void main(){

    LinkList ha,hb;
    ha=InitList();
    hb=InitList();
    CreatByRear(ha);
    OutPut(ha);
    CreatByHead(hb);
    OutPut(hb);

} */

