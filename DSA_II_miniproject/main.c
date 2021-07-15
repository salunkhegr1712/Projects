//programme for authority management in with skip list
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include "hospital_mangement.h"

struct skip_node* input(struct skip_node*ptr){
    ptr=(struct skip_node*)malloc(sizeof(struct skip_node));
    printf("ENTER THE APPOINTMENT NO ::\n");
    scanf("%d",&(ptr->node.appointment_no));
    printf("ENTER THE FULL NAME::\n");
    scanf("%s",ptr->node.name);
    printf("ENTER GENDER OF PERSON::\n");
    scanf("%s",ptr->node.gender);
    printf("ENTER  AGE OF PERSON::\n");
    scanf("%d",&ptr->node.age);
    printf("ENTER CONTACT NO::\n");
    scanf("%s",ptr->node.mobile_no);
    printf("ENTER AADHAR ID / NO::\n");
    scanf("%s",ptr->node.aadhar_id);
    printf("ENTER ADDRESS::\n");
    scanf("%s",ptr->node.address);
    printf("------------------------------------------------- \n");
    return ptr;
}

void display(struct skip_node*ptr){
    printf("\nAPPOINTMENT NO. OF PATIENT::%d\n",ptr->node.appointment_no);
    printf("\nNAME OF PATIENT::%s\n",ptr->node.name);
    printf("\n AGE OF PATIENT::%d\n",ptr->node.age);
    printf("\nGENDER OF PATIENT::%s\n",ptr->node.gender);
    printf("\nCONTACT NO. OF PATIENT::%s\n",ptr->node.mobile_no);
    printf("\nADDRESS OF PATIENT::%s\n",ptr->node.address);
    printf("\nAADHAR ID OF PATIENT::%s\n",ptr->node.aadhar_id);
    printf("-------------------------------------------------");
}

struct skip_node*create_skipnode(struct skip_node*n){
    n=(struct skip_node*)malloc(sizeof(struct skip_node));
    n=input(n);
   // n->left=NULL;
    n->right=NULL;
    n->up=NULL;
    n->down=NULL;
    n->left=NULL;
    return n;
};
struct skip_node*copy(struct skip_node*x){
    struct skip_node*y=malloc(sizeof(struct skip_node));
    y->node.appointment_no=x->node.appointment_no;
    strcpy(y->node.name,x->node.name);
    strcpy(y->node.gender,x->node.gender);
    y->node.age=x->node.age;
    strcpy(y->node.mobile_no,x->node.mobile_no);
    strcpy(y->node.address,x->node.address);
    strcpy(y->node.aadhar_id,x->node.aadhar_id);
    y->left=NULL;
    y->right=NULL;
    y->up=NULL;
    y->down=NULL;
    return y;
};
struct skip_node*nulify(struct skip_node*x){
    x=(struct skip_node*)malloc(sizeof(struct skip_node));
    x->node.appointment_no=0;
     char y[l]="null";
    strcpy(x->node.name,y);
    strcpy(x->node.gender,y);
    x->node.age=0;
    strcpy(x->node.mobile_no,y);
    strcpy(x->node.address,y);
    strcpy(x->node.aadhar_id,y);
    x->left=NULL;
    x->right=NULL;
    x->up=NULL;
    x->down=NULL;

    return x;

}
void deletion_by_appointment_no(struct skip_node*ptr,struct skip_node*level_1,
    struct skip_node*level_2,struct skip_node*level_3,int node_no,int ap_no){
    struct skip_node*p,*q,*r,*s,*m,*n,*o,*t,*u,*a,*b,*c,*d;
    p=level_1;
    q=level_2;
    r=level_3;
    s=ptr;
    int i=1;
    if(node_no%2==0 && node_no%4!=0){
        while(ap_no!=q->node.appointment_no){

            m=q;
            q=q->right;
            t=q->right;
        }
        m->right=q->right;
        t->left=m;
        free(q);
        while(ap_no!=s->node.appointment_no){
            n=s;
            s=s->right;
            u=s->right;
        }
        n->right=s->right;
        u->left=n;
        free(s);
    }
    else if(node_no%4==0){
        while (ap_no!=r->node.appointment_no){
            o=r;
            r=r->right;
            a=r->right;
        }
        o->right=r->right;
        a->left=o;
        free(r);

        while(ap_no!=q->node.appointment_no){
            m=q;
            q=q->right;
            b=q->right;
        }
        m->right=q->right;
        b->left=m;
        free(q);
        while(ap_no!=s->node.appointment_no){
            n=s;
            s=s->right;
            c=s->right;
        }
        n->right=s->right;
        s->left=n;
        free(s);
    }
    else{
        while(ap_no!=s->node.appointment_no){
            n=s;
            s=s->right;
            d=s->right;
        }
        n->right=s->right;
        s->left=n;
        free(s);
    }
    count--;

}

struct skip_node*insertion(struct skip_node*ptr,struct skip_node*level_1,
    struct skip_node*level_2,struct skip_node*level_3){
    struct skip_node*n;
    n=create_skipnode(n);
    struct skip_node*gh;

    gh=level_1;
    while(gh->right!=NULL){
        gh=gh->right;
    }
        gh->right=n;
        n->left=gh;
    if(count%2==0 && count %4 !=0){
        struct skip_node*y;
        y=level_2;
        while(y->right!=NULL){
            y=y->right;
        }
        struct skip_node*n1;
        n1=copy(n);
        n->up=n1;
        n1->down=n;
        y->right=n1;
        n1->left=y;

    }
    else if(count%4==0 ){
        struct skip_node*p;
        struct skip_node*q;
        p=level_3;
        q=level_2;
        while(p->right!=NULL){
            p=p->right;
        }
        while(q->right!=NULL){
            q=q->right;
        }
        struct skip_node*n1;
        n1=copy(n);
        struct skip_node*n2;
        n2=copy(n);

        n->up=n1;
        n1->down=n;
        q->right=n1;
        n1->left=q;
        n2->down=n1;
        n1->up=n2;
        p->right=n2;
        n2->left=p;

    }
    count++;
    return ptr ;
}
int search(struct skip_node*level1,int ap_no){
    struct skip_node*p;
    p=level1;
    int i=1;
    while(p->right!=NULL){
        if(p->node.appointment_no==ap_no){
            return i;
        }
        p=p->right;
        i++;

    }
    if(p->node.appointment_no==ap_no)
        return i;
    else
        return -1;

}
void element_search(struct skip_node*ptr,int ap_number){
    if (search(ptr,ap_number)!=-1)
    {
        printf("\n node no: %d\n",search(ptr,ap_number)-1);
        printf("\n entry found\n");
    }
    else
        printf("\n entry not found\n");

}
void display_perticular(struct skip_node*ptr,int a){
    struct skip_node*p=ptr;
    int hell=0;
    while(hell < a){
        p=p->right;
        hell++;
    }
    display(p);
}


int main()
{   //first node of the skip list
    struct skip_node*ptr;
    ptr=nulify(ptr);
    count++;
    //block of level which needed to implement
    //level 1
    struct skip_node*level1;
    level1=nulify(level1);
   //level 2
    struct skip_node*level2;
    level2=nulify(level2);
   //level 3
    struct skip_node*level3;
    level3=nulify(level3);
    //Arrangement of the pointer to node
    level1->up=level2;
    level2->up=level3;
    level3->down=level2;
    level2->down=level1;
    level1->right=ptr;
    ptr->left=level1;
    int i=0;
    int m,j,k,op;
    struct skip_node*z,*grs;
    z=ptr;
    char choice;
    struct skip_node*rs=level3;
    while(rs->right!=NULL){
        rs=rs->right;
    }

do {
        printf("\nCHOOSE OPTION BETWEEN FOLLOWING ::");
        printf("\nPRESS 1 FOR ADD A NEW ENTRY");
        printf("\nPRESS 2 TO SHOW ALL ENTRIES");
        printf("\nPRESS 3 TO SHOW PRESENT COUNT OF PATIENT");
        printf("\nPRESS 4 TO SEARCH A PATIENT NO FROM APPOINTMENT NO");
        printf("\nPRESS 5 TO DELETE TAKE A INPUT TO DELETE NODE ");
        printf("\nPRESS 6 TO DELETE A ENTRY OF PATIENT ");
        printf("\nPRESS 7 TO SHOW ALL ENTRIES in reverse order");
        printf("\nPRESS 8 TO SHOW A PERTICULAR NODE");
        printf("\nPRESS 0 TO EXIT\n");
        printf("YOUR RESPONCE::");
        scanf("%d",&m);


        switch(m)
        {
            case 1:
                ptr=insertion(ptr,level1,level2,level3);
                printf("\nentry complete\n");
                break;

            case 2:
                z=ptr->right;
                while(z->right!=NULL){
                    display(z);
                    z=z->right;
                }
                display(z);
                break;

            case 3:
                printf("\n current total no. of patients:: %d\n",count-1);
                break;

            case 4:
                printf("ENTER THE APPOINTMENT NO::\n");
                scanf("%d",&j);
                element_search(ptr,j);
                break;
            case 5:
                printf("ENTER THE APPOINTMENT NO::\n");
                scanf("%d",&k);
                printf("enter the node no::");
                scanf("%d",&op);
                //break;
            case 6:
                deletion_by_appointment_no(ptr,level1,level2,level3,op,k);
                break;
            case 7:
                grs=level1;
                while(grs->right!=NULL){
                    grs=grs->right;
                }
                while(grs->left!=NULL){
                    display(grs);
                    grs=grs->left;
                }
                display(grs);

                break;
            case 8:
                printf("\nENTER THE NODE NO:");
                scanf("\n%d",&op);
                display_perticular(ptr,op);
                break; 

            case 0:
                printf("\n process ended\n");
                exit(0);    // terminates the complete program execution
            default:printf("\nWrong choice!\n");
        }
        printf("\nDo you want to continue? (Press y/n)");
        scanf("\n%c",&choice);
    }while(choice=='y');


    return 0;
}
