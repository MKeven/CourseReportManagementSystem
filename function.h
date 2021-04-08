#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <graphics.h>
#include <easyx.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define Lenth_Account 12                          //用户字符长度宏定义
#define Lenth_Password 12
#define Lenth_Permission 12

#define Lenth_IDNumber 15                         //学生信息长度宏定义
#define Lenth_Name 15
#define Lenth_Sex 15
#define Lenth_Age 15
#define Lenth_Speciality 15
#define Lenth_Design 15

#define User_Number 25
#define Student_Number 25

/*********************************数据类型******************************************/

typedef struct Student                            //学生信息
{
    char ID_Number[Lenth_IDNumber];
    char Name[Lenth_Name];
    char Sex[Lenth_Sex];                          //男/女
    char Age[Lenth_Age];
    char Speciality[Lenth_Speciality];
    char Design[Lenth_Design];                    //未提交/未批改/已批改
};

typedef struct User                               //用户信息
{
    char Account[Lenth_Account];                  //账号
    char Password[Lenth_Password];
    char Permission[Lenth_Permission];            
};

/**********************************************************************************/

/*********************************功能函数******************************************/

void Init_Show(void);                             // 显示初始化
void User_Init(void);                             // 调用用户信息至内存
void Student_Init(void);                          // 调用学生信息至内存
User Account_Check(void);                         // 登录验证

void User_Common(void);                           // 普通用户界面
void User_Advanced(void);                         // 高级用户界面

void Student_Management(void);                    // 学生信息管理
void User_Management(void);                       // 用户信息管理

void Information_Query(void);                     // 信息查询
void Information_Queryc(void);
void Grade_Report(void);                          // 批改报告
void Grade_Update(void);

void User_Add(void);                              // 用户信息录入
void User_Modify(void);                           // 用户信息修改
void User_Delete(void);                           // 用户信息删除
void User_Output(User user, int i);               // 用户信息输出

void Student_Add(void);                           // 学生信息录入
void Student_Modify(void);                        // 学生信息修改
void Student_Delete(void);                        // 学生信息删除

void User_Information_Save(void);                 // 用户信息写入文件
void Student_Information_Save(void);              // 学生信息写入文件



/***********************************************************************************/

#endif // !_FUNCTION_H_
