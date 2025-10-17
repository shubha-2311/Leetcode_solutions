#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
// Function to create a new node
struct ListNode* newNode(int value) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end
struct ListNode* insertEnd(struct ListNode* head, int value) {
    struct ListNode* node = newNode(value);
    if (head == NULL)
        return node;
    struct ListNode* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = node;
    return head;
}

// Function to print a linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    typedef struct ListNode node;
    node *p = (node *)malloc(sizeof(node));
    node *merge = (node *)malloc(sizeof(node));
    merge=NULL;
    while(list1!=NULL && list2!=NULL){
        if(list1->val<list2->val){
            node *n = (node *)malloc(sizeof(node));
            n->val=list1->val;
            n->next=NULL;
            list1=list1->next;
            p->next=n;
            p=p->next;
        }else{
            node *n = (node *)malloc(sizeof(node));
            n->val=list2->val;
            n->next=NULL;
            list2=list2->next;
            p->next=n;
            p=p->next;
        }
        if(merge==NULL) merge=p;
    }
    while(list1!=NULL){
        node *n = (node *)malloc(sizeof(node));
        n->val=list1->val;
        n->next=NULL;
        list1=list1->next;
        p->next=n;
        p=p->next;
        if(merge==NULL) merge=p;
    }
    while(list2!=NULL){
        node *n = (node *)malloc(sizeof(node));
        n->val=list2->val;
        n->next=NULL;
        list2=list2->next;
        p->next=n;
        p=p->next;
        if(merge==NULL) merge=p;
    }
    return merge;
}

int main() {
    struct ListNode *list1 = NULL, *list2 = NULL;
    int n1, n2, val;

    printf("Enter number of elements in list1: ");
    scanf("%d", &n1);
    printf("Enter elements of list1 (sorted): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        list1 = insertEnd(list1, val);
    }

    printf("Enter number of elements in list2: ");
    scanf("%d", &n2);
    printf("Enter elements of list2 (sorted): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        list2 = insertEnd(list2, val);
    }

    printf("\nList1: ");
    printList(list1);
    printf("List2: ");
    printList(list2);

    struct ListNode* merged = mergeTwoLists(list1, list2);
    printf("\nMerged Sorted List: ");
    printList(merged);

    return 0;
}