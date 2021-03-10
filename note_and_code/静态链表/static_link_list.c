#include <stdio.h>
#include <stdint.h>

#define OK 0
#define ERROR 1
#define LEN_OF_LIST 1024

/* 静态链表元素结构体 */
typedef struct sllist_element_struct {
    int32_t data;
    uint32_t cursor;    //游标
} static_element_stru;

/* 初始化静态链表 */
uint32_t init_list(static_element_stru *static_list,
                   uint32_t len_of_list)
{
    uint32_t i;

    //检查入参指针
    if (NULL == static_list) {
        printf("[ERROR]init_list:the pointer is null !\n");
        return ERROR;
    }
    //检查链表长度
    if (len_of_list <= 0) {
        printf("[ERROR]init_list:len_of_list=%d,it must > 0\n", len_of_list);
        return ERROR;
    }
    //初始化的时候各个数组元素的游标是下一个数组元素的下标
    for(i=0; i<len_of_list; ++i)
    {
        static_list[i].cursor = i + 1;
    }

    //空静态链表中，最后一个元素指向第一个元素,
    //即最后一个元素的游标为第一个数组元素的数组下标
    static_list[len_of_list - 1].cursor = 0;

    return OK;
}

int main(void)
{
    uint32_t ret;

    static_element_stru static_list[LEN_OF_LIST];

    //初始化静态链表
    ret = init_list(static_list, LEN_OF_LIST);
    if (ret == ERROR) {
        printf("[ERROR]main: init_list fail !\n");
        return ERROR;
    }


    return 0;
}
