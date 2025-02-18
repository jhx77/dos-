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
//���뺯�������룩

int login() {
    int i,flag;
    int attempts = 3;
    char password[50];
    while (attempts>=1) { flag=-1;
        printf("�������û�ID: ");
        scanf("%d", &userId);
        printf("����������: ");
        scanf("%s", password);

for (i = 0; i < numUsers; i++)
    {
        if (userId==users[i].id)
             flag=i;
    }
    if(flag<0){ if(attempts>0)printf("�����ڴ��û��˺�ID������\n����������,��ʣ %d �γ��Ի���\n",--attempts);}
    else {
    if(strcmp(users[flag].password, password) == 0) return 1;
    else {
    attempts--;
    if(attempts>0)printf("�û�ID��������󣬻�ʣ %d �γ��Ի���\n", attempts);
    }
    }
}
    return 0; // ��½ʧ��
}

void showMenu() {
    printf("\n(����ʹ�����Ȱ���1 �����������Ϣ��ϵͳ������)\n");                                          //�˵�����
    printf("===== ���˵� =====\n");
    printf("1. ����û���Ϣ\n");
    printf("2. ���������˻�����\n");
    printf("3. �˳�ϵͳ\n");
    printf("==================\n");

}

void showMenu2() {
                                            //�˻��˵�����
    printf("===== �˻�������� =====\n");
    printf("1. ����������\n");
    printf("2. ��ѯ�û���Ϣ\n");
    printf("3. ������Ӧ�۳���ˮ��\n");
    printf("4. �˳��˻�\n");
    printf("==================\n");

}

void calculateWaterCost(int userId,float zongliang)   // ˮ�Ѽ��㺯��
{
char jumin[4]; char duli[4],tezhong[4],jmsj[4];int i,qylx,shuru; float shuijia,gongshui,wushui,zhuti,shenyu;
shuru=1;
while(shuru==1||shuru==0)
{
printf("����������Ϣ,�ǵ�����'yes',��������'no'��ĳһ��������󣬽�ȫ���������롣(����һ�һ�»س�)\n");
printf("�Ƿ����:");
scanf("%s", &jumin);
if (strcmp(jumin,"yes")==0) //�ж��Ƿ����
{
 shuru=2;
 printf("�Ƿ����:");
 scanf("%s",&duli);
   if(strcmp(duli,"yes")==0)//�ж��Ƿ�������Ǿ��������£�
   {
    if (zongliang<=216.0)
     {
      zhuti=zongliang;
      shuijia=2.9*zongliang;
      shenyu=216.0-zongliang;
     }
    else if(216<zongliang&&zongliang<=300)                      //����ˮ������
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
    shuijia=zongliang*2.95;               //���ñ�������
    wushui=zongliang;
    shuru=2;
   }
   else
   {
    printf("������󣨼Ȳ���yes��Ҳ����no.��ȫ���������롣��������\n");
    shuru=0;
   }
}
else if(strcmp(jumin,"no")==0)
{
 shuru=2;
 printf("�Ƿ�������ˮ:");
 scanf("%s",&tezhong);

    if(strcmp(tezhong,"yes")==0)  //�ж��Ƿ�������ˮ�����Ǿ��������£�
    {
     shuijia=zongliang*5.35;//������ˮ������
     wushui=zongliang*1.75;shuru=2;
    }
    else if(strcmp(tezhong,"no")==0)
    {
    printf("���Ǿ��񣬵��Ƿ��Ǿ���ˮ��:");
    scanf("%s",&jmsj);
      if(strcmp(jmsj,"yes")==0)//�ж��Ƿ����ˮ�ۣ�����������ˮ�������
      {
       shuijia=zongliang*3.20;//����ˮ�ۼ�����
       wushui=zongliang;shuru=2;
      }
      else if(strcmp(jmsj,"no")==0)
      {
        shuru=2;
        printf("��������ҵ���ͣ������ִ�����1.�ǹ�ҵ��ҵ; 2.��ҵ��ҵ; 3.����Ⱦ��ҵ\n");//�ж���ʲô��ҵ����
        printf("��ҵ���ʹ���:");
        scanf("%d",&qylx);
        if(qylx==1)
        {
         shuijia=zongliang*4.40;
         wushui=zongliang*2.05;
        }                               //��ҵ����������
        else if(qylx==2)                //�Ǿ���ˮ�ۼ�����
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
         printf("�������û����ѡ��ҵ����!������1��2��3��ѡ�񣡣�.��ȫ���������롣\n");
         shuru=0;
        }
      }
      else
          {
            printf("������󣨼Ȳ���yes��Ҳ����no.��ȫ���������롣��������\n");
             shuru=0;
          }
    }
    else
          {
            printf("������󣨼Ȳ���yes��Ҳ����no.��ȫ���������롣��������\n");
             shuru=0;
          }
}
else
{
 printf("������󣨼Ȳ���yes��Ҳ����no.��ȫ���������롣��������\n");
 shuru=0;
}

   if(shuru==2||shuru==3)
   {
    printf("��ˮ��=%.2fԪ\n",shuijia);
    gongshui=shuijia-wushui;
    printf("��ˮ��=%.2fԪ\n",gongshui);
    printf("��ˮ�����=%.2fԪ\n",wushui);
            if (strcmp(duli,"yes")==0&&shuru==3)
            {
            printf("��������ˮ����%.2f(m3)\n",zhuti);
             if (zongliang<300)
             {
              printf("��һ�ݶȵ�ʣ���ȣ�%.2f(m3)\n",shenyu);
             }
            }
   }
}
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            // �����û����
            users[i].balance -= shuijia; // ����ˮ��Ϊshuijia
            printf("�û� %d ������Ѹ���\n", userId);
            break;
        }
    }
    if (i == numUsers) {
        printf("�û� %d ������\n", userId);
    }
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {

            users[i].waterUsage=zongliang;}
            }
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            // �����û����
            users[i].shuijia=shuijia;}
            } // ����ˮ��Ϊshuijia
  for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {

            users[i].shuiyu=shenyu;}
            }
   for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {

            users[i].type=shuru-3;}
            }
}


void manageBalance(int userId, float amount) {              // ���û���ֵ����
    int i;
    for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            users[i].balance += amount;
            printf("�û� %d ������Ѹ���\n", userId);

        } else  printf("�û� %d ������\n", userId);
    }

}
void showUseryue(int userId) {                                 //��ѯ����
    int i,found = 0;
    for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            if(users[i].type==0)
            printf("���: %.2f\n", users[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ��û��˺�IDΪ %d ���û�\n", userId);
    }
}
void showUserDetails(int userId) {                                 //��ѯ����
    int i,found = 0;
    for (i = 0; i < numUsers; i++) {
        if (users[i].id == userId) {
            printf("�û��˺�ID: %d\n", users[i].id);
            printf("�û���: %s\n", users[i].name);
            printf("���һ����ˮ��: %.2f\n", users[i].waterUsage);
            printf("���һ��ˮ��: %.2f\n", users[i].shuijia);
            if(users[i].type==0)
            printf("������һ�ݶȵ�ˮ��: %.2f\n", users[i].shuiyu);
            printf("���: %.2f\n", users[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("δ�ҵ��û��˺�IDΪ %d ���û�\n", userId);
    }
}

int main() {                                               //������
    int choice, option;int choice2;
    float amount, usage;

    do {
        showMenu();
        printf("\n��ѡ����(��1-3���ִ���)��");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // ����û���Ϣ
                printf("����û���Ϣ��\n");
                if (numUsers < MAX_USERS) {
                    printf("�����û��˺�ID���������֣���");
                    scanf("%d", &users[numUsers].id);
                    printf("�����û�������Ӣ�Ŀ����֣���");
                    scanf("%s", users[numUsers].name);
                    printf("�����������: ");
                    scanf("%s",users[numUsers].password);
                    printf("������");
                    scanf("%f", &users[numUsers].balance);
                    numUsers++;
                    printf("�û���Ϣ�����\n");
                } else {
                    printf("�Ѵﵽ����û���\n");
                }
                break;

            case 2:
                   if(login()){  printf("\n\n��ӭ���룡����");
                    do{ printf("\n\n");
               showMenu2();
                printf("\n��ѡ����(��1-4���ִ���)��");
                scanf("%d", &choice2);
                    switch (choice2) {
             case 3:
                // �����û���ź���ˮ��������ˮ�Ѻ����
                printf("������ˮ����");
                scanf("%f", &usage);
                calculateWaterCost(userId,usage);
                break;
             case 1:
                // ��ֵ���ѯ���

                printf("1. ��ֵ\n2. ����ѯ\n");
                printf("��ѡ������ڣ�1-2����");
                scanf("%d", &option);
                if (option == 1) {
                 printf("��ӭ�����ֵϵͳ������\n");
                    printf("�����ֵ��");
                    scanf("%f", &amount);
                    manageBalance(userId, amount);
                }
                    else if (option == 2) {
                    printf("��ӭ�����ѯ���ϵͳ������\n");
                    showUseryue(userId);
                }
                     else {
                    printf("����������Чѡ��\n");
                }
                break;
            case 2:
                // ��ѯ�û���Ϣ
                printf("��ӭ�����ѯϵͳ����\n");
                showUserDetails(userId);
                break;
             case 4:  // �˳��˻�
                printf("\n���˳��˻�������\n��ӭ�����ٴε��룡����\n");
                break;
             default:
                printf("��Чѡ��\n");
                   }
                   }while(choice2!=4); }
              else   printf("�û�����������������³���\n"); printf("\n");
                   break;


            case 3:
                // �˳�����
                printf("\n���˳����򣡣���\n��ӭ�����ٴ�ʹ�ã�����\n\n");
                break;
            default:
                printf("��Чѡ��\n");
        }
    } while (choice!= 3);

    return 0;
}
