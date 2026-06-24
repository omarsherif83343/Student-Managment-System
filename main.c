/**
===============================================================
NAME:- OMAR SHERIF AHMED MOHAMED

PROJECT:- STUDENT MANAGMENT SYSTEM
===============================================================
*/

#include "Linked.h"

int main(){

link * s;

STU e;

int op;

do{
    printf("STUDENT MANAGMENT SYSTEM\n");
    printf("=====================================\n");
    printf("[1] CREATE LIST:\n");
    printf("[2] SCAN STUDENT:\n"); ///append
    printf("[3] SCAN STUDENT AT FIRST:\n");///insert at first
    printf("[4] SCAN STUDENT AT MIDDLE:\n");///insert at middle
    printf("[5] SORT:\n");
    printf("[6] SEARCH DATA:\n");
    printf("[7] UPDATE DATA:\n");
    printf("[8] DELETE ALL INFORMATION OF STUDENTS:\n");
    printf("[9] DELETE LIST OF STUDENTS DATA:\n");
    printf("[10] RETRIVE ALL DATA:\n");
    printf("[11] EXIT:\n");
    printf("=====================================\n");
    printf("ENTER YOUR CHOICE:\n");
    scanf("%d",&op);
    fflush(stdin);
    if(op == 1){
     CREATELIST(&s);
    }else if(op == 2){
     SCANSANDAPPEND(&s,e);
    }else if(op == 3){
     INSERTATFIRST(&s,e);
    }else if(op == 4){
     INSERTATMIDDLE(&s,e);
    }else if(op == 5){
     SORTDATA(&s,e);
    }else if(op == 6){
     SEARCHDATA(&s,e);
    }else if(op == 7){
     UPDATE(&s,e);
    }else if(op == 8){
     DELETE(&s,e);
    }else if(op == 9){
     DELETELIST(&s,e);
    }else if(op == 10){
    SELECTALLDATA(&s);
    }else{
    printf("EXITED\n");
    }
}while(op != 11);


    return 0;
}

void CREATELIST(link * s){

s->head = NULL;

s->current = NULL;

}

bool ISEMPTY(link * s){

return (s->head == NULL);

}

void SCANSANDAPPEND(link * s,STU e){

node * newnode = (node*)malloc(sizeof(node));

printf("ENTER ID:-\n");

scanf("%d",&e.id);

fflush(stdin);

printf("ENTER NAME:-\n");

gets(e.name);

fflush(stdin);

printf("ENTER DEPARTMENT:-\n");

gets(e.department);

fflush(stdin);

printf("ENTER AGE:-\n");

scanf("%d",&e.age);

fflush(stdin);

if(newnode == NULL){
    printf("HEAP IS FULL\n");
}

newnode->data = e;

newnode->next = NULL;

if(ISEMPTY(s)){
    s->head = newnode;
}

else{

s->current->next = newnode;

}

s->current = newnode;

}

void SORTDATA(link * s,STU e){

int op1;
char i1[30];
char i2[30];
int i3;
int i4;

printf("[1] SORT BY NAME:\n");
printf("[2] SORT BY DEPARTMENT:\n");
printf("[3] SORT BY AGE:\n");
scanf("%d",&op1);
fflush(stdin);
if(op1 == 1){
    for(node * temp1 = s->head;temp1!=NULL;temp1 = temp1->next){

        for(node *temp2 = temp1->next;temp2!=NULL;temp2 = temp2->next){

            if(strcmp(temp1->data.name,temp2->data.name)==1){

                strcpy(i1,temp1->data.name);

                strcpy(temp1->data.name,temp2->data.name);

                strcpy(temp2->data.name,i1);
            }
        }
    }
}else if(op1 == 2){

for(node *temp3 = s->head;temp3!=NULL;temp3 = temp3->next){

    for(node * temp4 = temp3->next;temp4!=NULL;temp4 = temp4->next){

        if(strcmp(temp3->data.department,temp4->data.department)==1){

            strcpy(i2,temp3->data.department);

            strcpy(temp3->data.department,temp4->data.department);

            strcpy(temp4->data.department,i2);
        }
    }
}

}else if(op1 == 3){

for(node * temp5 = s->head;temp5!=NULL;temp5 = temp5->next){

    for(node * temp6 = temp5->next;temp6!=NULL;temp6 = temp6->next){

        if(temp5->data.age < temp6->data.age){

            i3 = temp5->data.age;

            temp5->data.age = temp6->data.age;

            temp6->data.age = i3;
        }
    }
}

}else{

printf("INVALID NUMBER\n");

}

}
void SEARCHDATA(link * s,STU e){

int id1;

int flag = 0;

printf("ENTER ID:-\n");

scanf("%d",&id1);

fflush(stdin);

for(node * temp = s->head;temp != NULL;temp = temp->next){
    if(id1 == temp->data.id){
        flag = 1;
        printf("ID:\n");
        printf("%d\n",temp->data.id);
        printf("NAME:\n");
        puts(temp->data.name);
        printf("DEPARTMENT:\n");
         puts(temp->data.department);
        printf("AGE:\n");
        if(temp->data.age == 0){
            printf("INVALID AGE\n");
        }else if(temp->data.age >= 1 && temp->data.age <= 24){
        printf("%d\n",temp->data.age);
        }else{
        printf("INVALID AGE:\n");
        }
        printf("---------------------------------------\n");
        break;
    }
}
if(flag == 0){
    printf("ID IS NOT FOUND\n");
}
}

void UPDATE(link * s,STU e){

int flag2 = 0;

int id2;

int op3;

char a1[30];

char a2[30];

int a3;

printf("ENTER ID:\n");

scanf("%d",&id2);

fflush(stdin);

for(node * temp = s->head;temp != NULL;temp = temp->next){

    if(id2 == temp->data.id){

        flag2 = 1;

        printf("[1] UPDATE NAME:\n");

        printf("[2] UPDATE DEPARTMENT:\n");

        printf("[3] UPDATE AGE:\n");


        scanf("%d",&op3);

        fflush(stdin);

        if(op3 == 1){
            printf("ENTER A NEW NAME:\n");
            gets(a1);
            fflush(stdin);
            strcpy(temp->data.name,a1);
            printf("THE NAME IS UPDATED\n");
        }else if(op3 == 2){
        printf("ENTER A NEW DEPARTMENT:\n");
        gets(a2);
        fflush(stdin);
        strcpy(temp->data.department,a2);
        printf("THE DEPARTMENT IS UPDATED\n");
        }else if(op3 == 3){
        printf("ENTER A NEW AGE:\n");
        scanf("%d",&a3);
        fflush(stdin);
        temp->data.age = a3;
        printf("THE AGE IS UPDATED\n");

        }

        break;
    }
}

if(flag2 == 0){
    printf("ID IS NOT FOUND\n");
}

}
void SELECTALLDATA(link * s){
    for(node * temp = s->head;temp != NULL;temp = temp->next){
        printf("ID:\n");
        printf("%d\n",temp->data.id);
        printf("NAME:\n");
        puts(temp->data.name);
        printf("DEPARTMENT:\n");
        puts(temp->data.department);
        printf("AGE:\n");
        if(temp->data.age == 0){
            printf("INVALID AGE\n");
        }else if(temp->data.age >= 1 && temp->data.age <= 24){
        printf("%d\n",temp->data.age);
        }else{
        printf("INVALID AGE\n");
        }
        printf("---------------------------------------\n");
    }
}

void DELETE(link * s,STU e){

for(node * temp = s->head;temp!=NULL;temp = temp->next){
            s->head = temp->next;
            free(temp->data.name);

            free(temp->data.department);

            free(temp->data.age);
    }
}

void DELETELIST(link * s,STU e){

int id6;

int f = 0;

printf("ENTER ID:\n");

scanf("%d",&id6);

fflush(stdin);

for(node * temp1 = s->head;temp1 != NULL;temp1 = temp1->next){

    if(id6 == temp1->data.id){

     f = 1;

     s->head = temp1->next;

     free(temp1);

     return;

     break;

   }

 }


if(f == 0){
    printf("ID IS NOT FOUND\n");
}
}

void INSERTATFIRST(link * s,STU e){

char u1[30];

char u2[30];

int u3;

node * newnode = (node*)malloc(sizeof(node));

printf("ENTER ID:\n");

scanf("%d",&e.id);

fflush(stdin);

printf("ENTER NAME:\n");

gets(e.name);

fflush(stdin);

printf("ENTER DEPARTMENT:\n");

gets(e.department);

fflush(stdin);

printf("ENTER AGE:\n");

scanf("%d",&e.age);

fflush(stdin);


if(newnode == NULL){

    printf("THE HEAP IS FULL\n");

}


newnode->data = e;

newnode->next = s->head;

s->head = newnode;

for(node * t = s->head;t!=NULL;t = t->next){
    for(node * t2 = t->next;t2 != NULL;t2 = t2->next){

        if(strcmp(t->data.name,t2->data.name)==1){
            strcpy(u1,t->data.name);
            strcpy(t->data.name,t2->data.name);
            strcpy(t2->data.name,u1);
        }
       }
    }

    for(node * t3 = s->head;t3 != NULL;t3 = t3->next){

      for(node * t4 = t3->next;t4 != NULL;t4 = t4->next){

        if(strcmp(t3->data.department,t4->data.department)==1){
            strcpy(u2,t3->data.department);
            strcpy(t3->data.department,t4->data.department);
            strcpy(t4->data.department,u2);
        }
      }
     }

      for(node * t5 = s->head;t5 != NULL;t5 = t5->next){
        for(node * t6 = t5->next;t6 != NULL;t6 = t6->next){
            if(t5->data.age < t6->data.age){
                u3 = t5->data.age;
                t5->data.age = t6->data.age;
                t6->data.age = u3;
          }
        }
      }
    }

    void INSERTATMIDDLE(link * s,STU e){

    char i4[30];
    char i5[30];
    int i6;

    node * newnode = (node*)malloc(sizeof(node));

    printf("ENTER ID:\n");

    scanf("%d",&e.id);

    fflush(stdin);

    printf("ENTER NAME:\n");

    gets(e.name);

    fflush(stdin);

    printf("ENTER DEPARTMENT:\n");

    gets(e.department);

    fflush(stdin);

    printf("ENTER AGE:\n");

    scanf("%d",&e.age);

    fflush(stdin);

   if(newnode == NULL){

   printf("THE HEAP IS FULL\n");

   }

   newnode->data = e;

   newnode->next = s->current;

   s->current = s->head;

   s->head = newnode;

for(node * t7 = s->head;t7 != NULL;t7 = t7->next){
    for(node * t8 = t7->next;t8 != NULL;t7 = t7->next){
        if(strcmp(t7->data.name,t8->data.name)==1){
            strcpy(i4,t7->data.name);
            strcpy(t7->data.name,t8->data.name);
            strcpy(t8->data.name,i4);
        }
    }
}

for(node * t9 = s->head;t9 != NULL;t9 = t9->next){
    for(node * t10 = t9->next;t10 != NULL;t10 = t10->next){
        if(strcmp(t9->data.department,t10->data.department)==1){
            strcpy(i5,t9->data.department);
            strcpy(t9->data.department,t10->data.department);
            strcpy(t10->data.department,i5);
        }
    }
}

for(node * t11 = s->head;t11 != NULL;t11 = t11->next){
    for(node * t12 = t11->next;t12 != NULL;t12 = t12->next){
        if(t11->data.age < t12->data.age){
            i6 = t11->data.age;
            t11->data.age = t12->data.age;
            t12->data.age = i6;
        }
    }
}

}
