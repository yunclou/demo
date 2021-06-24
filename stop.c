#include "stop.h"


 int c_price(int minute)
{
    int  price;
    time_t now ;
    struct tm *tm_now ;
    time(&now) ;
    tm_now = localtime(&now) ;
    price = (tm_now->tm_min -  minute) *Price;
    return price;
}

int  insert_car(S_car *head)
{
    char license[20];
    time_t now ;
    struct tm *tm_now ;
    time(&now) ;
    tm_now = localtime(&now) ;
    //异常判断
    if(head == NULL)
    {
        S_FAIL;  
    }
    while(head->next != NULL)
    {
        head = head->next;
    }
    printf("enter  car's  license:");
    getchar();
    fgets(license, 20, stdin);
     S_car *pNode = (S_car *)malloc(sizeof(S_car));
    if(pNode == NULL)
    {
          return S_FAIL;      
    }     
    strcpy(pNode->license,license) ;
    pNode->hour=tm_now->tm_hour;
    pNode->minute=tm_now->tm_min;
    pNode->second=tm_now->tm_sec;
    head->next = pNode;
    pNode->next =NULL;
    
     printf("insert  succed!\n");
    return S_OK;
}

int display_cars(S_car *head)
{
    if(head == NULL)
    {
        return S_FAIL;    
    }
    printf("------------display-----------\n");
    
    S_car*pNode = head->next;
    while(pNode != NULL)
    {
        printf("license:%s",pNode->license);
        printf("start  time::%d:%d:%d\n\n",pNode->hour,pNode->minute,pNode->second);
        pNode = pNode->next;    
    }
    
    return S_OK;
}

int delete_car(S_car *head)
{
    if(head == NULL)
    {
        return S_FAIL;    
    }
    time_t now ;
    struct tm *tm_now ;
    time(&now) ;
    tm_now = localtime(&now) ;
    char license[20];
    int  price;
    printf("enter  car's license:");
    getchar();
    fgets(license, 20, stdin);
    S_car *pPrev =  head;
    S_car *pNode = head->next;
    while(pNode  != NULL)
    {
        if(strcmp(pNode->license,license) == 0)
        {
           S_car *p = pNode;
           price =  c_price(p->minute);
           printf("car   license:%s",p->license);
           printf("start time:  %d:%d:%d\n" ,p->hour,p->minute,p->second);
           printf("leave  time: %d:%d:%d\n", tm_now->tm_hour,tm_now->tm_min,tm_now->tm_sec);
           printf("price: %d\n",price);
           pPrev->next = pNode->next;
           if (p != NULL)
           {
                  free(p);
                  p = NULL;
            }
            printf("delete  succed!\n");
    
            return S_OK;
        }
        pPrev = pNode;
        pNode = pNode->next;
    }
    return S_FAIL;
}

    void menu(S_car *head)
    {
             int option;
             printf("------------------Welcome    my          park!----------------------\n");
            printf ("enter your choice:  1.insert    2. display   3.delete   4.exit\n");
            scanf("%d",&option);
            switch (option)
           {
                case  1:
                             {
                               // insert_car(head);
                                insert_car(head);
                                menu(head);
                                break;
                                }
                case  2: 
                            {
                              display_cars(head);
                              menu(head);
                              break;
                            }
                case 3: 
                           {
                               delete_car(head);
                               menu(head);
                               break;
                           }
                case 4: break;
                default:
                 { 
                printf("**********      请输入正确的指令！    **********\n");
                menu(head);
               break;
                }
                 
    }
}
