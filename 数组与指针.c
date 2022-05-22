#include<stdio.h>


const 设置数组为只读：
const int days[12]={31,28,......}

初始化器：int a[10]={[5]=2}


/* int main(){

    int days[12]={31,28,31,20,31,30,31,31,30,31,30,31};
    int index;

    for(index=0;index<12;index++){
        printf("month %2d has %d days\n",index,*(days+index));//days是首地址，加index后使用去地址符
    }


    return 0;
} 
 */

传递实参时：
int sum(int *ar,int n) == int sum(int *,int n) == int sum(int ar[],int n) == int sum(int [], int )

/*  int sum(int *ar,int n){

    int i;
    int total=0;

    for ( i = 0; i < n; i++)
    {
        total+=*(ar+i);

    }
    printf("The size of ar is %zd bytes.\n",sizeof ar);
}  */




指针运算：
指针与整数n相加/减；指针向后移动n位，等于地址加n*类型所占字节
递增递减：指针向前或向后移动
指针求差：两指针指向元素之间的元素个数


int *pt;
*pt = 5;//严重错误：指针没有初始化，不知指针指向哪个地址，故无法存储

在函数中对数组进行处理时容易错误的修改数组中的数据

解决方法：
int sum(const int *ar ,int n);//使用const

但是将const指针赋值给非const指针非常不安全，因为可以通过非const指针修改const指针内存储的值


二维数组：
int zippo[0][0]
zippo 与zippo[0]的值相同

zippo指向对象占两个int大小，而zippo[0]只占一个int大小
所以zippo+1的值 和 zippo[0]+1 的值不同
ps：zippo相当于首元素地址的地址，要获得存储值，需要使用两次解引用

即：  **zippo == *&zippo[0][0] == zippo[0][0]
zippo[2][1] == (*(zippo+2)+1)
