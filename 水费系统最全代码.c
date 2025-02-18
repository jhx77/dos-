#include <stdio.h>
#include <string.h>

#define MAX_USERS 50

struct User {
    int id;
    char name[50];
    char password[50];
    int type;
    float waterUsage;
    float balance;
    float shuijia,shuiyu;
};

struct User users[MAX_USERS];
int numUsers = 0;
int userId ;
//登入函数（密码）

int login() {
    int i,flag;
    int attempts = 3;
    char password[50];
    while (attempts>=1) { flag=-1;
        printf("请输入用户ID: ");
        scanf("%d", &userId);
        printf("请输入密码: ");
        scanf("%s", password);

for (i = 0; i < numUsers; i++)
    {
        if (userId==users[i].id)
             flag=i;
    }
    if(flag<0){ if(attempts>0)printf("不存在此用户账号ID！！！\n请重新输入,还剩 %d 次尝试机会\n",--attempts);}
    else {
    if(strcmp(users[flag].password, password) == 0) return 1;
    else {
    attempts--;
    if(attempts>0)printf("用户ID或密码错误，还剩 %d 次尝试机会\n", attempts);
    }
    }
}
    return 0; // 登陆失败
}

void showMenu() {
    printf("\n(初次使用请先按“1 ”添加您的信息到系统！！！)\n");                                          //菜单函数
    printf("===== 主菜单 =====\n");
    printf("1. 添加用户信息\n");
    printf("2. 登入您的账户管理\n");
    printf("3. 退出系统\n");
    printf("==================\n");

}

void showMenu2() {
                                            //账户菜单函数
    printf("===== 账户管理界面 =====\n");
    printf("1. 您的余额管理\n");
    printf("2. 查询用户信息\n");
    printf("3. 计算相应扣除的水费\n");
    printf("4. 退出账户\n");
    printf("==================\n");

}

void calculateWaterCost(int userId,float zongliang)   // 水费计算函数
{
char jumin[4]; char duli[4],tezhong[4],jmsj[4];int i,qylx,shuru; float shuijia,gongshui,wushui,zhuti,shenyu;
shuru=1;
while(shuru==1||shuru==0)
{
printf("对于下列信息,是的输入'yes',不是输入'no'。某一项输入错误，将全部重新输入。(输完一项按一下回车)\n");
printf("是否居民:");
scanf("%s", &jumin);
if (strcmp(jumin,"yes")==0) //判断是否居民
{
 shuru=2;
 printf("是否独立:");
 scanf("%s",&duli);
   if(strcmp(duli,"yes")==0)//判断是否独立（是居民的情况下）
   {
    if (zongliang<=216.0)
     {
      zhuti=zongliang;
      shuijia=2.9*zongliang;
      shenyu=216.0-zongliang;
     }
    else if(216<zongliang&&zongliang<=300)                      //独立水运算区
     {
      zhuti=zongliang-216.0;
      shuijia=626.4+zhuti*(3.85);
      shenyu=300.0-zongliang;
     }
    else if(zongliang>300)
     {
      shuijia=(949.8+(zongliang-300)*6.70);
      zhuti=(zongliang-300.0);
     }
    wushui=zongliang;shuru=3;
   }
   else if(strcmp(duli,"no")==0)
   {
    shuijia=zongliang*2.95;               //合用表运算区
    wushui=zongliang;
    shuru=2;
   }
   else
   {
    printf("输入错误（既不是yes，也不是no.请全部重新输入。）！！！\n");
    shuru=0;
   }
}
else if(strcmp(jumin,"no")==0)
{
 shuru=2;
 printf("是否特种用水:");
 scanf("%s",&tezhong);

    if(strcmp(tezhong,"yes")==0)  //判断是否特种用水（不是居民的情况下）
    {
     shuijia=zongliang*5.35;//特种用水运算区
     wushui=zongliang*1.75;shuru=2;
    }
    else if(strcmp(tezhong,"no")==0)
    {
    printf("不是居民，但是否是居民水价:");
    scanf("%s",&jmsj);
      if(strcmp(jmsj,"yes")==0)//判断是否居民水价（不是特种用水的情况）
      {
       shuijia=zongliang*3.20;//居民水价计算区
       wushui=zongliang;shuru=2;
      }
      else if(strcmp(jmsj,"no")==0)
      {
        shuru=2;
        printf("请输入企业类型（用数字代表）：1.非工业企业; 2.工业企业; 3.高污染企业\n");//判断是什么企业类型
        printf("企业类型代码:");
        scanf("%d",&qylx);
        if(qylx==1)
        {
         shuijia=zongliang*4.40;
         wushui=zongliang*2.05;
        }                               //企业类型运算区
        else if(qylx==2)                //非居民水价计算区
        {
          shuijia=zongliang*4.70;
         wushui=zongliang*2.05;
        }
        else if(qylx==3)
        {
          shuijia=zongliang*5.1;
         wushui=zongliang*2.45;
        }
        else if(qylx!=1&&qylx!=2&&qylx!=3)
        {
         printf("输入错误，没有所选企业！！!（请在1，2，3中选择！）.请全部重新输入。\n");
         shuru=0;
        }
      }
      else
          {
            printf("输入错误（既不是yes，也不是no.请全部重新输入。）！！！\n");
             shuru=0;
          }
    }
    else
          {
            printf("输入错误（既不是yes，也不是no.请全部重新输入。）！！！\n");
             shuru=0;
          }
}
else
{
 printf("输入错误（既不是yes，也不是no.请全部重新输入。）！！！\n");
 shuru=0;
}

   if(shuru==2||shuru==3)
   {
    printf("总水价=%.2f元\n",shuijia);
    gongshui=shuijia-wushui;
    printf("供水价=%.2f元\n",gongshui);
    printf("污水处理费=%.2f元\n",wushui);
            if (strcmp(duli,"yes")==0&&shuru==3)
            {
            printf("主体已用水量：%.2f(m3)\n",zhuti);
             if (zongliang<300)
             {
              printf("下一梯度的剩余额度：%.2f(m3)\n",shenyu);
             }
            }
   }
}
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            // 更新用户余额
            users[i].balance -= shuijia; // 假设水费为shuijia
            printf("用户 %d 的余额已更新\n", userId);
            break;
        }
    }
    if (i == numUsers) {
        printf("用户 %d 不存在\n", userId);
    }
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {

            users[i].waterUsage=zongliang;}
            }
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            // 更新用户余额
            users[i].shuijia=shuijia;}
            } // 假设水费为shuijia
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {

            users[i].shuiyu=shenyu;}
            }
   for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {

            users[i].type=shuru-3;}
            }
}


void manageBalance(int userId, float amount) {              // 给用户充值函数
    int i;
    for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            users[i].balance += amount;
            printf("用户 %d 的余额已更新\n", userId);

        } else  printf("用户 %d 不存在\n", userId);
    }

}
void showUseryue(int userId) {                                 //查询函数
    int i,found = 0;
    for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            if(users[i].type==0)
            printf("余额: %.2f\n", users[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("未找到用户账号ID为 %d 的用户\n", userId);
    }
}
void showUserDetails(int userId) {                                 //查询函数
    int i,found = 0;
    for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            printf("用户账号ID: %d\n", users[i].id);
            printf("用户名: %s\n", users[i].name);
            printf("最近一次用水量: %.2f\n", users[i].waterUsage);
            printf("最近一次水费: %.2f\n", users[i].shuijia);
            if(users[i].type==0)
            printf("距离下一梯度的水量: %.2f\n", users[i].shuiyu);
            printf("余额: %.2f\n", users[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("未找到用户账号ID为 %d 的用户\n", userId);
    }
}

int main() {                                               //主函数
    int choice, option;int choice2;
    float amount, usage;

    do {
        showMenu();
        printf("\n请选择功能(用1-3数字代替)：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // 添加用户信息
                printf("添加用户信息中\n");
                if (numUsers < MAX_USERS) {
                    printf("输入用户账号ID（仅限数字）：");
                    scanf("%d", &users[numUsers].id);
                    printf("输入用户名（可英文可数字）：");
                    scanf("%s", users[numUsers].name);
                    printf("输入登入密码: ");
                    scanf("%s",users[numUsers].password);
                    printf("输入余额：");
                    scanf("%f", &users[numUsers].balance);
                    numUsers++;
                    printf("用户信息已添加\n");
                } else {
                    printf("已达到最大用户数\n");
                }
                break;

            case 2:
                   if(login()){  printf("\n\n欢迎登入！！！");
                    do{ printf("\n\n");
               showMenu2();
                printf("\n请选择功能(用1-4数字代替)：");
                scanf("%d", &choice2);
                    switch (choice2) {
             case 3:
                // 输入用户编号和用水量，计算水费和余额
                printf("输入用水量：");
                scanf("%f", &usage);
                calculateWaterCost(userId,usage);
                break;
             case 1:
                // 充值或查询余额

                printf("1. 充值\n2. 余额查询\n");
                printf("请选择功能入口（1-2）：");
                scanf("%d", &option);
                if (option == 1) {
                 printf("欢迎登入充值系统！！！\n");
                    printf("输入充值金额：");
                    scanf("%f", &amount);
                    manageBalance(userId, amount);
                }
                    else if (option == 2) {
                    printf("欢迎登入查询余额系统！！！\n");
                    showUseryue(userId);
                }
                     else {
                    printf("您输入了无效选项\n");
                }
                break;
            case 2:
                // 查询用户信息
                printf("欢迎登入查询系统！！\n");
                showUserDetails(userId);
                break;
             case 4:  // 退出账户
                printf("\n已退出账户！！！\n欢迎您的再次登入！！！\n");
                break;
             default:
                printf("无效选项\n");
                   }
                   }while(choice2!=4); }
              else   printf("用户名或密码错误，请重新尝试\n"); printf("\n");
                   break;


            case 3:
                // 退出程序
                printf("\n已退出程序！！！\n欢迎您的再次使用！！！\n\n");
                break;
            default:
                printf("无效选项\n");
        }
    } while (choice!= 3);

    return 0;
}
