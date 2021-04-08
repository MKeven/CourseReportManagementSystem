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

#define Lenth_Account 12                          //�û��ַ����Ⱥ궨��
#define Lenth_Password 12
#define Lenth_Permission 12

#define Lenth_IDNumber 15                         //ѧ����Ϣ���Ⱥ궨��
#define Lenth_Name 15
#define Lenth_Sex 15
#define Lenth_Age 15
#define Lenth_Speciality 15
#define Lenth_Design 15

#define User_Number 25
#define Student_Number 25

/*********************************��������******************************************/

typedef struct Student                            //ѧ����Ϣ
{
    char ID_Number[Lenth_IDNumber];
    char Name[Lenth_Name];
    char Sex[Lenth_Sex];                          //��/Ů
    char Age[Lenth_Age];
    char Speciality[Lenth_Speciality];
    char Design[Lenth_Design];                    //δ�ύ/δ����/������
};

typedef struct User                               //�û���Ϣ
{
    char Account[Lenth_Account];                  //�˺�
    char Password[Lenth_Password];
    char Permission[Lenth_Permission];            
};

/**********************************************************************************/

/*********************************���ܺ���******************************************/

void Init_Show(void);                             // ��ʾ��ʼ��
void User_Init(void);                             // �����û���Ϣ���ڴ�
void Student_Init(void);                          // ����ѧ����Ϣ���ڴ�
User Account_Check(void);                         // ��¼��֤

void User_Common(void);                           // ��ͨ�û�����
void User_Advanced(void);                         // �߼��û�����

void Student_Management(void);                    // ѧ����Ϣ����
void User_Management(void);                       // �û���Ϣ����

void Information_Query(void);                     // ��Ϣ��ѯ
void Information_Queryc(void);
void Grade_Report(void);                          // ���ı���
void Grade_Update(void);

void User_Add(void);                              // �û���Ϣ¼��
void User_Modify(void);                           // �û���Ϣ�޸�
void User_Delete(void);                           // �û���Ϣɾ��
void User_Output(User user, int i);               // �û���Ϣ���

void Student_Add(void);                           // ѧ����Ϣ¼��
void Student_Modify(void);                        // ѧ����Ϣ�޸�
void Student_Delete(void);                        // ѧ����Ϣɾ��

void User_Information_Save(void);                 // �û���Ϣд���ļ�
void Student_Information_Save(void);              // ѧ����Ϣд���ļ�



/***********************************************************************************/

#endif // !_FUNCTION_H_
