#include "function.h"

User All_User[25];                         //将用户信息调用至内存
Student All_Student[25];                   //将学生信息调用至内存

int flag = 0;
extern User User_Now;

/***************************选项位置*******************************/

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

void Init_Show(void)                          //初始化界面
{
    IMAGE Start;
    loadimage(&Start, "F:\\个人资料\\程序\\CourseManagement\\Image\\Start.jpg",1280,720);
    putimage(0,0,&Start);
    settextstyle(40, 15, "微软雅黑");
    outtextxy(520,500,"downloading...");
    Sleep(2000);                              //等待两秒
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
    Ensure = InputBox(user.Account, Lenth_Account, "请输入账号", "登录",0 , 0, 0, false);
    if (!Ensure)
        exit(0);

restart:

    int j = 0;
    if (strlen(user.Account) == 0)                                  //判断是否输入，如果没有输入，重新输入
    {
        InputBox(user.Account, Lenth_Account, "用户名为空，请重新输入", "登录");
        goto restart;
    }

    while(strcmp(user.Account, All_User[j].Account) != 0)           //判断是否有此用户，如果没有，重新输入
    {
        j++;
        if(j == User_Number)
        {
            InputBox(user.Account, Lenth_Account, "用户名不存在，请重新输入", "登录");
            goto restart;
        }
    }

    InputBox(user.Password, Lenth_Password, "请输入密码", "登录");

    if (strcmp(user.Password, All_User[j].Password) == 0)           //密码正确，进入系统
        return user = All_User[j];
  
    else                                                             //密码错误重新输入

    {
        InputBox(user.Password, Lenth_Account, "密码错误，请重新输入", "登录");

        if (strcmp(user.Password, All_User[j].Password) == 0)
            return user = All_User[j];

        else                                                           //第二次输入错误，重新登录
        {
            InputBox(user.Account, Lenth_Account, "密码错误，请重新登录", "登录");
            goto  restart;
        }
    }
}

void User_Common(void)                                      //普通用户操作界面
{
    int i = 0;
    IMAGE User;
    MOUSEMSG Mouse;
    Mouse = GetMouseMsg();                                  //等待鼠标信息
 
    loadimage(&User, "F:\\个人资料\\程序\\CourseManagement\\Image\\User_Common.jpg", 1280, 720);
    putimage(0, 0, &User);

    settextcolor(WHITE);
    settextstyle(30, 11, "微软雅黑");
    outtextxy(320, 145, User_Now.Account);
    outtextxy(360, 201, User_Now.Permission);

    for (i = 0; i < 3; i++)                               //选中有框，移开没有
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
        setlinecolor(RGB(68, 84, 106));                 //背景色rgb信息
        rectangle(Location_Common[j][0], Location_Common[j][1], Location_Common[j][2], Location_Common[j][3]);
    }

    if (Mouse.mkLButton)
    {
        switch (i)
        {
        case(0):Information_Queryc(); FlushMouseMsgBuffer(); break;              //信息查找
        case(1):Grade_Update(); FlushMouseMsgBuffer(); break;                   //报告提交
        case(2):exit(0);                                                        //退出系统
        }
    }
    
}

void User_Advanced(void)
{
    int i = 0;
    IMAGE User;
    MOUSEMSG Mouse;
    Mouse = GetMouseMsg();

    loadimage(&User, "F:\\个人资料\\程序\\CourseManagement\\Image\\User_Advanced.jpg", 1280, 720);
    putimage(0, 0, &User);
    settextcolor(WHITE);
    settextstyle(30, 11, "微软雅黑");
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
    loadimage(&Student_Management, "F:\\个人资料\\程序\\CourseManagement\\Image\\Student_Management.jpg", 1280, 720);
    putimage(0, 0, &Student_Management);

    while (1)                                           //在二级菜单内循环
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
            case(4):goto Menu;                                   //返回主菜单
            }
        }

   }
Menu:;
}

void User_Management(void)
{
    IMAGE User_Management;
    loadimage(&User_Management, "F:\\个人资料\\程序\\CourseManagement\\Image\\User_Management.jpg", 1280, 720);
    putimage(0, 0, &User_Management);

    while (1)                                           //在二级菜单内循环
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
            case(3):goto Menu;                                   //返回主菜单
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
    InputBox(Information, 15, "请输入任意一项信息", "信息查询");

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

        IMAGE Student_Management;                                               //清屏
        loadimage(&Student_Management, "F:\\个人资料\\程序\\CourseManagement\\Image\\Student_Management.jpg", 1280, 720);
        putimage(0, 0, &Student_Management);

        for (int s = 0; s < j; s++)
        {
            settextstyle(25, 9, "微软雅黑");
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
    InputBox(Information, 15, "请输入任意一项信息", "信息查询");
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

            IMAGE Student_Management;                                               //清屏
            loadimage(&Student_Management, "F:\\个人资料\\程序\\CourseManagement\\Image\\Common.jpg", 1280, 720);
            putimage(0, 0, &Student_Management);

            for (int s = 0; s < j; s++)
            {
                settextstyle(25, 9, "微软雅黑");
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

    InputBox(user.Account, Lenth_Account, "请输入账号：", "添加用户");
    InputBox(user.Password, Lenth_Password, "请输入密码：", "添加用户");
    InputBox(user.Permission, Lenth_Permission, "请输入用户类型：（普通/高级）", "添加用户");

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

    InputBox(user, 15, "请输入要修改信息的用户名", "修改信息");
    InputBox(inf, 15, "请输入要修改信息类别", "修改信息");
    InputBox(res, 15, "请输入要修改为", "修改信息");

    for (i = 0; i < User_Number; i++)
    {
        if (strcmp(user, All_User[i].Account) == 0)
            break;
    }

    if (strcmp(inf, "用户名") == 0)
        for (int j = 0; j < 15; j++)
            All_User[i].Account[j] = res[j];

    if (strcmp(inf, "密码") == 0)
        for (int j = 0; j < 15; j++)
            All_User[i].Password[j] = res[j];

    if (strcmp(inf, "用户类型") == 0)
        for (int j = 0; j < 15; j++)
            All_User[i].Permission[j] = res[j];

    User_Information_Save();
    User_Init();
}

void User_Delete(void)
{
    char user[15];
    InputBox(user, 15, "请输入要删除的用户名", "删除用户"); 

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

    InputBox(Stu.Name, Lenth_Name, "请输入学生姓名：", "添加学生");
    InputBox(Stu.ID_Number, Lenth_IDNumber, "请输入学生学号：", "添加学生");
    InputBox(Stu.Age, Lenth_Age, "请输入学生年龄：", "添加学生");
    InputBox(Stu.Sex, Lenth_Sex, "请输入学生性别：", "添加学生");
    InputBox(Stu.Speciality, Lenth_Speciality, "请输入学生专业：", "添加学生");

    if (fopen_s(&fp, "Data.txt", "a"))
    {
        printf("Fail to open file!\n");
        exit(0);
    }

    else {
        fprintf(fp, "%s %s %s %s %s 未提交\n",
            Stu.ID_Number,
            Stu.Name,
            Stu.Sex,
            Stu.Age,
            Stu.Speciality,
            Stu.Design);
        fclose(fp);
    }

    Student_Init();                                         //信息更新

}

void Student_Modify(void)
{
    char stu[15],inf[15],res[15];
    int i = 0;
    InputBox(stu, 15, "请输入要修改信息的学生学号", "修改信息");
    InputBox(inf, 15, "请输入要修改信息类别", "修改信息");
    InputBox(res, 15, "请输入要修改为", "修改信息");

    for (i = 0; i < Student_Number; i++)
    {
        if (strcmp(stu, All_Student[i].ID_Number) == 0)
            break;
    }

        if (strcmp(inf, "姓名") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Name[j] = res[j];
        
        if (strcmp(inf, "学号") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].ID_Number[j] = res[j];

        if (strcmp(inf, "专业") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Speciality[j] = res[j];

        if (strcmp(inf, "性别") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Sex[j] = res[j];

        if (strcmp(inf, "年龄") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Age[j] = res[j];

        if (strcmp(inf, "报告提交情况") == 0)
            for (int j = 0; j < 15; j++)
                All_Student[i].Design[j] = res[j];

        Student_Information_Save();
        Student_Init();
}

void Student_Delete(void)
{
    char stu[15];
    InputBox(stu, 15, "请输入要删除的学生学号", "删除用户");

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
    char common[Lenth_IDNumber], grade[5], remark[100], na[] = "已批改";
    InputBox(common, Lenth_IDNumber, "请输入要批改的学生学号", "打开报告");
   
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

    InputBox(grade, Lenth_IDNumber, "请输入分数", "批改");
    InputBox(remark, 100, "请输入评语", "批改");

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
    char stu[Lenth_IDNumber], na[] = "已提交";

    InputBox(stu, Lenth_IDNumber, "请输入要提交报告的学生学号", "提交报告");

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