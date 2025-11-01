#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
 
/*int presentInArray(int *nums, int numsSize, int data){
    for(int i=0;i<numsSize;i++){
        if(data==nums[i])
            return 1;       
    }
    return 0;
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    typedef struct ListNode node;
    node *c=head;
    node *p=head;
    if(c){
        while(c!=NULL){
            if(presentInArray(nums,numsSize,c->val)){
                if(head==c){
                    head=c->next;
                    free(c);
                    c=head;
                    p=head;
                }else{
                    p->next=c->next;
                    free(c);
                    c=p->next;
                }
            }else{
                p=c;
                c=c->next;
            }
        }
    }
    return head;
}*/


typedef struct ListNode node_t;

void printList(node_t* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// Helper functions for testing
node_t* createList(int arr[], int n) {
    node_t* head = NULL;
    node_t* tail = NULL;
    for (int i = 0; i < n; i++) {
        node_t* newNode = (node_t*)malloc(sizeof(node_t));
        newNode->val = arr[i];
        newNode->next = NULL;
        if (!head)
            head = tail = newNode;
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    bool present[100001] = {false};
    for(int i = 0; i < numsSize; i++){
        present[nums[i]] = true;
    }

    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* p = &dummy;

    while(p->next!=NULL){
        if(present[p->next->val]){
            p->next = p->next->next;
        }
        else{
            p = p->next;
        }
    }
    return dummy.next;
}
int main() {
    int nums[] = {1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int arr[] = {1, 2, 1, 2, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    node_t* head = createList(arr, n);

    printf("Original List: ");
    printList(head);

    head = modifiedList(nums, numsSize, head);

    printf("Modified List: ");
    printList(head);
    return 0;
}