结构体变量的定义
struct student
{
    /* data */
};
struct student stu1,stu2;


struct student2
{
    /* data */
}stu1,stu2;

struct 
{
    /* data */
}stu1,stu2;//这种方法为一次性定义，在别的地方不可再定义stu1，stu2


类型相同的结构体变量可以相互赋值：  stu1=stu2
但是不可以对其进行逻辑操作：==  !=


/* #include <stdio.h>


    struct date
    {
        int year;
        int month;
        int day;
    };

    struct student
    {
        char num[9];
        char name[21];
        char sex;
        int age;
        struct date birthday;
        int score[3];
        float aver;
        
    };
    
    main(){


        struct student stu;
        int i,sum=0;
        printf("please input the information:\n");
        printf("please input num:\n");
        scanf("%s",&stu.num);
        printf("please input name:\n");
        scanf("%s",&stu.name);
        printf("please input sex:\n");
        scanf("%c",&stu.sex);
        printf("please input age:\n");
        scanf("%d",&stu.age);
        printf("please input birthday:\n");
        scanf("%d%d%d",&stu.birthday.year,&stu.birthday.month,&stu.birthday.day);
        printf("please input score:\n");
        for ( i = 0; i < 3; i++)
        {
                scanf("%d",&stu.score[i]);
        }
        for ( i = 0; i < 3; i++)
        {
            sum+=stu.score[i];
        }
        stu.aver=sum/3.0;

        

    } */



结构体数组
struct student
{
        char num[9];
        char name[21];
        char sex;
        int age;
}stu[5];//含有五个结构体元素的结构体数组

访问元素时

stu.[0].sex
strcpy(stu[0].num,"04213120")


//统计选票
/* #include <stdio.h>
#include<string.h>

struct person
{
    char name[20];
    int count;
};

int main(){

    struct person leader[3]={"fu",0,"lu",0,"shou",0};
    struct person t;//作为交换的辅助
    int i,j,k;
    int n=3,m;
    char name[20];
    printf("please input count of votes:\n");
    scanf("%d",&m);//选票数
    printf("please input the elections name:\n");
    for ( i = 1; i <=m; i++)
    {
        printf("NO.%d:",i);
        scanf("%s",name);
        for ( j = 0; j < 3; j++){
        
            if (strcmp(name,leader[j].name)==0)
            {
                leader[j].count++;
            }
            }
    }    
        for ( i = 0; i < 2; i++)    //排序
        {
            k=i;
            for ( j = i+1; j < n; j++)
            
                if (leader[k].count<leader[j].count)
                
                    k=j;
                
            if (k!=i)
                {
                    t=leader[i];
                    leader[i]=leader[j];
                    leader[k]=t;
                }
                
            
            
        }

        
        printf("the vote of leaders is:\n");
        for ( i = 0; i < n; i++)
        {
            printf("%s\t%d\n",leader[i].name,leader[i].count);
        }
        
    
return 0;

} */


typedef语句{

    typedef char NAME[20];
    "NAME a" == "char a[20]"

    对结构体：
    typedef struct student STUDENT;
    定义：
    typedef struct student{

        int id;
        char name[20];
        int score[3];
        float aver;

    }STUDENT,*STU;
或：
    typedef struct {

        ...

    }STUDENT,*STU;
其中:
STUDENT stu1 等价于 struct student stu1
STU stu2     等价于 struct student *stu2



}


指针与结构体{

定义指向结构体类型数据的指针变量前，需要先定义结构体
引用指针前需要把结构体变量的地址赋给它

typedef struct student{

        int id;
        char name[20];
        int score[3];
        float aver;

    }STUDENT,*STU;

STUDENT s,*p=&s;//结构体指针p存储 s 的地址

以下三种引用方式等价
1)s.name
2)(*p).name//必须使用圆括号
3)s->name

//输出结构体数组中的元素
/* typedef struct student{

        int id;
        char name[20];
        int score[3];
        float aver;

    }STUDENT,*STU;

int main(){

    STUDENT st[3]={{10101,"Li Lin",98},{10102,"Zhang Fen",87},{10103,"Wang Min"},79};
    STU p;//定义结构体指针变量t
    for (p=st; p<st+3 ; p++)
    {
        printf("%-6d%s\t%d\n",p->id,(*p).name,p->score);//(*p).name等价于p->name
    }
    
} */

注意 () [] -> .  的优先级都为最高

}
