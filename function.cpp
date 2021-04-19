#include "function.h"

User All_User[25];                         //���û���Ϣ�������ڴ�
Student All_Student[25];                   //��ѧ����Ϣ�������ڴ�

int flag = 0;
extern User User_Now;

/***************************ѡ��λ��*******************************/

int Location_Common[3][4] = {
                              {580, 105, 920, 270},
                              {940, 105, 1102, 270},
                              {580, 285, 1102, 625},
                            };

int Location_Advanced[4][4] = {                             
                                {577, 104, 1104, 271},
                                {577, 284, 1104, 450},
                                {578, 463, 924, 628},
                                {938, 463, 1104, 628}
                              };

int Location_Student[5][4] = {                              
                                {198, 610, 316, 645},
                                {382, 610, 502, 645},
                                {567, 610, 687, 645},
                                {750, 610, 870, 645},
                                {937, 610, 1080, 645},
                             };

int Location_User[4][4] = {                              
                            {285, 592, 410, 630},
                            {470, 592, 598, 630},
                            {653, 592, 778, 630},
                            {842, 592, 990, 630},
};

/*****************************************************************/

void Init_Show(void)                          //��ʼ������
{
    IMAGE Start;
    loadimage(&Start, "F:\\��������\\����\\CourseManagement\\Image\\Start.jpg",1280,720);
    putimage(0,0,&Start);
    settextstyle(40, 15, "΢���ź�");
    outtextxy(520,500,"downloading...");
    Sleep(2000);                              //�ȴ�����
}

void User_Init(void)
{
    int U = 0;
    FILE *Fp_User;
    
    if (fopen_s(&Fp_User, "User.txt", "r"))
    {         
        printf("Fail to open file!\n");
        exit(0);
    }

    else 
    {
        while (!feof(Fp_User))
        {
            fscanf_s(Fp_User, "%s %s %s",
                              All_User[U].Account, Lenth_Account,
                              All_User[U].Password, Lenth_Password,
                              All_User[U].Permission, Lenth_Permission);
            U++;
        }
        fclose(Fp_User);
    }

}

void Student_Init(void)
{
    int S = 0;
    FILE * Fp_Student;

    if (fopen_s(&Fp_Student, "Data.txt", "r"))
    {
        printf("Fail to open file!\n");
        exit(0);
    }

    else
    {
        while (!feof(Fp_Student))
        {
            fscanf_s(Fp_Student, "%s %s %s %s %s %s",
                                All_Student[S].ID_Number, Lenth_IDNumber,
                                All_Student[S].Name, Lenth_Name,
                                All_Student[S].Sex, Lenth_Sex,
                                All_Student[S].Age, Lenth_Age,
                                All_Student[S].Speciality, Lenth_Speciality,
                                All_Student[S].Design, Lenth_Design);
            S++;
        }
        fclose(Fp_Student);
    }

}

User Account_Check(void)
{
    User user;
    bool Ensure;
    Ensure = InputBox(user.Account, Lenth_Account, "�������˺�", "��¼",0 , 0, 0, false);
    if (!Ensure)
        exit(0);

restart:

    int j = 0;
    if (strlen(user.Account) == 0)                                  //�ж��Ƿ����룬���û�����룬��������
    {
        InputBox(user.Account, Lenth_Account, "�û���Ϊ�գ�����������", "��¼");
        goto restart;
    }

    while(strcmp(user.Account, All_User[j].Account) != 0)           //�ж��Ƿ��д��û������û�У���������
    {
        j++;
        if(j == User_Number)
        {
            InputBox(user.Account, Lenth_Account, "�û��������ڣ�����������", "��¼");
            goto restart;
        }
    }

    InputBox(user.Password, Lenth_Password, "����������", "��¼");

    if (strcmp(user.Password, All_User[j].Password) == 0)           //������ȷ������ϵͳ
        return user = All_User[j];
  
    else                                                             //���������������

    {
        InputBox(user.Password, Lenth_Account, "�����������������", "��¼");

        if (strcmp(user.Password, All_User[j].Password) == 0)
            return user = All_User[j];

        else                                                           //�ڶ�������������µ�¼
        {
            InputBox(user.Account, Lenth_Account, "������������µ�¼", "��¼");
            goto  restart;
        }
    }
}

void User_Common(void)                                      //��ͨ�û���������
{
    int i = 0;
    IMAGE User;
    MOUSEMSG Mouse;
    Mouse = GetMouseMsg();                                  //�ȴ������Ϣ
 
    loadimage(&User, "F:\\��������\\����\\CourseManagement\\Image\\User_Common.jpg", 1280, 720);
    putimage(0, 0, &User);

    settextcolor(WHITE);
    settextstyle(30, 11, "΢���ź�");
    outtextxy(320, 145, User_Now.Account);
    outtextxy(360, 201, User_Now.Permission);

    for (i = 0; i < 3; i++)                               //ѡ���п��ƿ�û��
    {
        if (Location_Common[i][0] < Mouse.x && Mouse.x < Location_Common[i][2] && Location_Common[i][1] < Mouse.y && Mouse.y < Location_Common[i][3])
        {
            setlinecolor(WHITE);
            rectangle(Location_Common[i][0], Location_Common[i][1], Location_Common[i][2], Location_Common[i][3]);
            break;
        }
    }

    for (int j = 0; j < i; j++)
    {
        setlinecolor(RGB(68, 84, 106));                 //����ɫrgb��Ϣ
        rectangle(Location_Common[j][0], Location_Common[j][1], Location_Common[j][2], Location_Common[j][3]);
    }

    if (Mouse.mkLButton)
    {
        switch (i)
        {
        case(0):Information_Queryc(); FlushMouseMsgBuffer(); break;              //��Ϣ����
        case(1):Grade_Update(); FlushMouseMsgBuffer(); break;                   //�����ύ
        case(2):exit(0);                                                        //�˳�ϵͳ
        }
    }
    
}

void User_Advanced(void)
{
    int i = 0;
    IMAGE User;
    MOUSEMSG Mouse;
    Mouse = GetMouseMsg();

    loadimage(&User, "F:\\��������\\����\\CourseManagement\\Image\\User_Advanced.jpg", 1280, 720);
    putimage(0, 0, &User);
    settextcolor(WHITE);
    settextstyle(30, 11, "΢���ź�");
    outtextxy(320, 145, User_Now.Account);
    outtextxy(360, 201, User_Now.Permission);

    for (i = 0; i < 4; i++)
    {
        if (Location_Advanced[i][0] < Mouse.x && Mouse.x < Location_Advanced[i][2] && Location_Advanced[i][1] < Mouse.y && Mouse.y < Location_Advanced[i][3])
        {
            setlinecolor(WHITE);
            rectangle(Location_Advanced[i][0], Location_Advanced[i][1], Location_Advanced[i][2], Location_Advanced[i][3]);
            break;
        }
    }

    for (int j = 0; j < i; j++)
    {
        setlinecolor(RGB(68, 84, 106));
        rectangle(Location_Advanced[j][0], Location_Advanced[j][1], Location_Advanced[j][2], Location_Advanced[j][3]);
    }

    if (Mouse.mkLButton)
    {
        switch (i)
        {
        case(0):Student_Management(); FlushMouseMsgBuffer(); break;
        case(1):User_Management(); FlushMouseMsgBuffer(); break;
        case(2):Grade_Report(); FlushMouseMsgBuffer(); break;
        case(3):exit(0); 
        }
    }
}

void Student_Management(void)
{
    IMAGE Student_Management;
    loadimage(&Student_Management, "F:\\��������\\����\\CourseManagement\\Image\\Student_Management.jpg", 1280, 720);
    putimage(0, 0, &Student_Management);

    while (1)                                           //�ڶ����˵���ѭ��
    {
        int i = 0;
        MOUSEMSG Mouse;
        Mouse = GetMouseMsg();

        for (i = 0; i < 5; i++)
        {
            if (Location_Student[i][0] < Mouse.x && Mouse.x < Location_Student[i][2] && Location_Student[i][1] < Mouse.y && Mouse.y < Location_Student[i][3])
            {
                setlinecolor(WHITE);
                rectangle(Location_Student[i][0], Location_Student[i][1], Location_Student[i][2], Location_Student[i][3]);
                break;
            }
        }

        for (int j = 0; j < i; j++)
        {
            setlinecolor(RGB(34, 42, 53));
            rectangle(Location_Student[j][0], Location_Student[j][1], Location_Student[j][2], Location_Student[j][3]);
        }

        if (Mouse.mkLButton)
        {
            switch (i)
            {
            case(0):Information_Query(); FlushMouseMsgBuffer(); break;
            case(1):Student_Add(); FlushMouseMsgBuffer(); break;
            case(2):Student_Modify(); FlushMouseMsgBuffer(); break;
            case(3):Student_Delete(); FlushMouseMsgBuffer(); break;
            case(4):goto Menu;                                   //�������˵�
            }
        }

   }
Menu:;
}

void User_Management(void)
{
    IMAGE User_Management;
    loadimage(&User_Management, "F:\\��������\\����\\CourseManagement\\Image\\User_Management.jpg", 1280, 720);
    putimage(0, 0, &User_Management);

    while (1)                                           //�ڶ����˵���ѭ��
    {
        int i = 0;
        MOUSEMSG Mouse;
        Mouse = GetMouseMsg();

        for (i = 0; i < 4; i++)
        {
            if (Location_User[i][0] < Mouse.x && Mouse.x < Location_User[i][2] && Location_User[i][1] < Mouse.y && Mouse.y < Location_User[i][3])
            {
                setlinecolor(WHITE);
                rectangle(Location_User[i][0], Location_User[i][1], Location_User[i][2], Location_User[i][3]);
                break;
            }
        }

        for (int j = 0; j < i; j++)
        {
            setlinecolor(RGB(34, 42, 53));
            rectangle(Location_User[j][0], Location_User[j][1], Location_User[j][2], Location_User[j][3]);
        }

        if (Mouse.mkLButton)
        {
            switch (i)
            {
            case(0):User_Add(); FlushMouseMsgBuffer(); break;
            case(1):User_Modify(); FlushMouseMsgBuffer(); break;
            case(2):User_Delete(); FlushMouseMsgBuffer(); break;
            case(3):goto Menu;                                   //�������˵�
            }
        }

    }
Menu:;
}

void Information_Query(void)
{
    int j = 0;
    char Information[15];
    Student Stu[Student_Number];
    InputBox(Information, 15, "����������һ����Ϣ", "��Ϣ��ѯ");

    if (strlen(Information) != 0)
    {
        for (int i = 0; i < Student_Number; i++)
        {
            if (strcmp(Information, All_Student[i].Age) == 0)
                Stu[j++] = All_Student[i];

            if (strcmp(Information, All_Student[i].ID_Number) == 0)
                Stu[j++] = All_Student[i];

            if (strcmp(Information, All_Student[i].Name) == 0)
                Stu[j++] = All_Student[i];

            if (strcmp(Information, All_Student[i].Sex) == 0)
                Stu[j++] = All_Student[i];

            if (strcmp(Information, All_Student[i].Speciality) == 0)
                Stu[j++] = All_Student[i];

            if (strcmp(Information, All_Student[i].Design) == 0)
                Stu[j++] = All_Student[i];
        }

        IMAGE Student_Management;                                               //����
        loadimage(&Student_Management, "F:\\��������\\����\\CourseManagement\\Image\\Student_Management.jpg", 1280, 720);
        putimage(0, 0, &Student_Management);

        for (int s = 0; s < j; s++)
        {
            settextstyle(25, 9, "΢���ź�");
            settextcolor(BLACK);

            outtextxy(217, 152 + 33 * s, Stu[s].ID_Number);

            outtextxy(410, 152 + 33 * s, Stu[s].Name);

            outtextxy(540, 152 + 33 * s, Stu[s].Sex);

            outtextxy(637, 152 + 33 * s, Stu[s].Age);

            outtextxy(752, 152 + 33 * s, Stu[s].Speciality);

            outtextxy(950, 152 + 33 * s, Stu[s].Design);
        }
    }
}

void Information_Queryc(void)
{
    int j = 0;
    char Information[15];
    Student Stu[Student_Number];
    InputBox(Information, 15, "����������һ����Ϣ", "��Ϣ��ѯ");
    while (1)
    {
        if (strlen(Information) != 0)
        {
            for (int i = 0; i < Student_Number; i++)
            {
                if (strcmp(Information, All_Student[i].Age) == 0)
                    Stu[j++] = All_Student[i];

                if (strcmp(Information, All_Student[i].ID_Number) == 0)
                    Stu[j++] = All_Student[i];

                if (strcmp(Information, All_Student[i].Name) == 0)
                    Stu[j++] = All_Student[i];

                if (strcmp(Information, All_Student[i].Sex) == 0)
                    Stu[j++] = All_Student[i];

                if (strcmp(Information, All_Student[i].Speciality) == 0)
                    Stu[j++] = All_Student[i];

                if (strcmp(Information, All_Student[i].Design) == 0)
                    Stu[j++] = All_Student[i];
            }

            IMAGE Student_Management;                                               //����
            loadimage(&Student_Management, "F:\\��������\\����\\CourseManagement\\Image\\Common.jpg", 1280, 720);
            putimage(0, 0, &Student_Management);

            for (int s = 0; s < j; s++)
            {
                settextstyle(25, 9, "΢���ź�");
                settextcolor(BLACK);

                outtextxy(217, 152 + 33 * s, Stu[s].ID_Number);

                outtextxy(410, 152 + 33 * s, Stu[s].Name);

                outtextxy(540, 152 + 33 * s, Stu[s].Sex);

                outtextxy(637, 152 + 33 * s, Stu[s].Age);

                outtextxy(752, 152 + 33 * s, Stu[s].Speciality);

                outtextxy(950, 152 + 33 * s, Stu[s].Design);
            }
        }
        while (1)
        {
            int i = 0;
            MOUSEMSG Mouse;
            Mouse = GetMouseMsg();

            if (937 < Mouse.x && Mouse.x < 1080 && 610 < Mouse.y && Mouse.y < 645)
            {
                setlinecolor(WHITE);
                rectangle(937, 610, 1080, 645);
                if (Mouse.mkLButton)
                    break;
            }
            else
            {

                setlinecolor(RGB(34, 42, 53));
                rectangle(937, 610, 1080, 645);
            }
        }
        break;
    }
}

void User_Add(void)
{
    FILE* fp;
    User user;

    InputBox(user.Account, Lenth_Account, "�������˺ţ�", "����û�");
    InputBox(user.Password, Lenth_Password, "���������룺", "����û�");
    InputBox(user.Permission, Lenth_Permission, "�������û����ͣ�����ͨ/�߼���", "����û�");

    if (fopen_s(&fp, "User.txt", "a"))
    {           
        printf("Fail to open file!\n");
        exit(0);
    }

    else {
        fprintf(fp, "%s %s %s\n", user.Account, user.Password, user.Permission);
        fclose(fp);
    }
}

void User_Modify(void)
{
    int i = 0;
    char user[15], inf[15], res[15];

    InputBox(user, 15, "������Ҫ�޸���Ϣ���û���", "�޸���Ϣ");
    InputBox(inf, 15, "������Ҫ�޸���Ϣ���", "�޸���Ϣ");
    InputBox(res, 15, "������Ҫ�޸�Ϊ", "�޸���Ϣ");

    for (i = 0; i < User_Number; i++)
    {
        if (strcmp(user, All_User[i].Account) == 0)
            break;
    }

    if (strcmp(inf, "�û���") == 0)
        for (int j = 0; j < 15; j++)
            All_User[i].Account[j] = res[j];

    if (strcmp(inf, "����") == 0)
        for (int j = 0; j < 15; j++)
            All_User[i].Password[j] = res[j];

    if (strcmp(inf, "�û�����") == 0)
        for (int j = 0; j < 15; j++)
            All_User[i].Permission[j] = res[j];

    User_Information_Save();
    User_Init();
}

void User_Delete(void)
{
    char user[15];
    InputBox(user, 15, "������Ҫɾ�����û���", "ɾ���û�"); 

    for (int i = 0; i < 25; i++)
    {
        if (strcmp(user, All_User[i].Account) == 0)
            for (int j = 0; j < User_Number; j++)
                All_User[i] = All_User[i + 1];
    }

    User_Information_Save();
    User_Init();
}

void User_Information_Save(void)
{
    FILE* fp;

    if (fopen_s(&fp, "User.txt", "w"))
    {
        printf("Fail to open file!\n");
        exit(0);
    }

    else {
        for (int i = 0; i < User_Number; i++)
            fprintf(fp, "%s %s %s\n", All_User[i].Account, All_User[i].Password, All_User[i].Permission);

        fclose(fp);
    }
}

void Student_Add(void)
{
    Student Stu ;
    FILE* fp;

    InputBox(Stu.Name, Lenth_Name, "������ѧ��������", "���ѧ��");
    InputBox(Stu.ID_Number, Lenth_IDNumber, "������ѧ��ѧ�ţ�", "���ѧ��");
    InputBox(Stu.Age, Lenth_Age, "������ѧ�����䣺", "���ѧ��");
    InputBox(Stu.Sex, Lenth_Sex, "������ѧ���Ա�", "���ѧ��");
    InputBox(Stu.Speciality, Lenth_Speciality, "������ѧ��רҵ��", "���ѧ��");

    if (fopen_s(&fp, "Data.txt", "a"))
    {
        printf("Fail to open file!\n");
        exit(0);
    }

    else {
        fprintf(fp, "%s %s %s %s %s δ�ύ\n",
            Stu.ID_Number,
            Stu.Name,
            Stu.Sex,
            Stu.Age,
            Stu.Speciality,
            Stu.Design);
        fclose(fp);
    }

    Student_Init();                                         //��Ϣ����

}

void Student_Modify(void)
{
    char stu[15],inf[15],res[15];
    int i = 0;
    InputBox(stu, 15, "������Ҫ�޸���Ϣ��ѧ��ѧ��", "�޸���Ϣ");
    InputBox(inf, 15, "������Ҫ�޸���Ϣ���", "�޸���Ϣ");
    InputBox(res, 15, "������Ҫ�޸�Ϊ", "�޸���Ϣ");

    for (i = 0; i < Student_Number; i++)
    {
        if (strcmp(stu, All_Student[i].ID_Number) == 0)
            break;
    }

        if (strcmp(inf, "����") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Name[j] = res[j];
        
        if (strcmp(inf, "ѧ��") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].ID_Number[j] = res[j];

        if (strcmp(inf, "רҵ") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Speciality[j] = res[j];

        if (strcmp(inf, "�Ա�") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Sex[j] = res[j];

        if (strcmp(inf, "����") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Age[j] = res[j];

        if (strcmp(inf, "�����ύ���") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Design[j] = res[j];

        Student_Information_Save();
        Student_Init();
}

void Student_Delete(void)
{
    char stu[15];
    InputBox(stu, 15, "������Ҫɾ����ѧ��ѧ��", "ɾ���û�");

    if (strlen(stu) != 0)
    {
        for (int i = 0; i < Student_Number-1; i++)
        {
            if (strcmp(stu, All_Student[i].ID_Number) == 0)
                for (int j = 0; j < Student_Number; j++)
                    All_Student[i] = All_Student[i + 1];
        }

        Student_Information_Save();
        Student_Init();
    }

}

void Student_Information_Save(void)
{
    FILE* fp;

    if (fopen_s(&fp, "Data.txt", "w"))
    {
        printf("Fail to open file!\n");
        exit(0);
    }

    else {
        for (int i = 0; i < Student_Number; i++)
            fprintf(fp, "%s %s %s %s %s %s\n",
                All_Student[i].ID_Number,
                All_Student[i].Name,
                All_Student[i].Sex,
                All_Student[i].Age,
                All_Student[i].Speciality,
                All_Student[i].Design);

        fclose(fp);
    }
}

void Grade_Report(void)
{
    char common[Lenth_IDNumber], grade[5], remark[100], na[] = "������";
    InputBox(common, Lenth_IDNumber, "������Ҫ���ĵ�ѧ��ѧ��", "�򿪱���");
   
    int i;
    for (i = 0; i < Student_Number; i++)
    {
        if (strcmp(common, All_Student[i].ID_Number) == 0)
        {
            for(int k = 0; k<Lenth_Design;k++)
            All_Student[i].Design[k] = na[k];
            break;
        }
    }

    Student_Information_Save();
    Student_Init();

    strcat_s(common,".doc");
    system(common);

//    Sleep(2000);

    InputBox(grade, Lenth_IDNumber, "���������", "����");
    InputBox(remark, 100, "����������", "����");

    FILE* fp;

    if (fopen_s(&fp, "Grade.txt", "a"))
    {
        printf("Fail to open file!\n");
        exit(0);
    }

    else 
    {
        fprintf(fp, "%s %s %s\n", All_Student[i].ID_Number, grade, remark);
        fclose(fp);
    }

}

void Grade_Update(void)
{
    char stu[Lenth_IDNumber], na[] = "���ύ";

    InputBox(stu, Lenth_IDNumber, "������Ҫ�ύ�����ѧ��ѧ��", "�ύ����");

    int i;
    for (i = 0; i < Student_Number; i++)
    {
        if (strcmp(stu, All_Student[i].ID_Number) == 0)
        {
            for (int k = 0; k < Lenth_Design; k++)
                All_Student[i].Design[k] = na[k];
            break;
        }
    }

    Student_Information_Save();
    Student_Init();
}