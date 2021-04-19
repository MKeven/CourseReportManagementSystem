// CourseManagement.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <iostream>
#include <easyx.h>
#include <stdlib.h>
#include "function.h"

User User_Now;

int main()
{   

    initgraph(1280, 720);                // 初始化图形模式
    setbkmode(TRANSPARENT);              // 背景混合模式
    setlinestyle(PS_SOLID, 3);           // 画线样式为实线，3磅

    Init_Show();                         // 初始界面
    User_Init();                         // 调用用户信息至内存
    Student_Init();                      // 调用学生信息至内存
    User_Now = Account_Check();          // 登录验证

    while (1)
    {
        if (strcmp(User_Now.Permission, "普通") == 0)

            User_Common();

        else

            User_Advanced();
    }

    closegraph();
    return 0;

}

