#ifndef HOSPITAL_MANGEMENT_H_INCLUDED
#define HOSPITAL_MANGEMENT_H_INCLUDED

#ifndef l
#define l 100
#endif
static int count=0;
struct info{
    int appointment_no;
    char name[l];
    char gender[l];
    int age;
    char mobile_no[l];
    char address[l];
    char aadhar_id[l];

};
struct skip_node{
    struct info node;
    struct skip_node*right;
    struct skip_node*up;
    struct skip_node*down;
    struct skip_node*left;
};
struct skip_node*insertion(struct skip_node*ptr,struct skip_node*level_1,
    struct skip_node*level_2,struct skip_node*level_3);
struct skip_node* input(struct skip_node*ptr);
void display(struct skip_node*ptr);
struct skip_node*create_skipnode(struct skip_node*n);
struct skip_node*copy(struct skip_node*x);
struct skip_node*nulify(struct skip_node*x);
void deletion_by_appointment_no(struct skip_node*ptr,struct skip_node*level_1,struct skip_node*level_2,struct skip_node*level_3,int node_no,int ap_no);
int search(struct skip_node*level1,int ap_no);
void element_search(struct skip_node*ptr,int ap_number);
void skiplist_search(struct skip_node*ptr,int p);
#endif // HOSPITAL_MANGEMENT_H_INCLUDED
