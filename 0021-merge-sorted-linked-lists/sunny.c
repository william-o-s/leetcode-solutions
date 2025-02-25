#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    struct ListNode *p1 = list1, *p2 = list2, *head = NULL, *curr = NULL;
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL && p2 != NULL) {
            struct ListNode *smaller = (p1->val <= p2->val) ? p1 : p2;
            if (head == NULL) {
                head = smaller;
                curr = smaller;
            } else {
                curr->next = smaller;
                curr = smaller;
            }

            if (smaller == p1) {
                p1 = p1->next;
            } else {
                p2 = p2->next;
            }
        } else {
            struct ListNode *not_null = (p1 != NULL) ? p1 : p2;
            if (head == NULL) {
                head = not_null;
                curr = not_null;
            } else {
                curr->next = not_null;
                curr = not_null;
            }

            if (not_null == p1) {
                p1 = p1->next;
            } else {
                p2 = p2->next;
            }
        }
    }
    return head;
}

struct ListNode *insert(struct ListNode *head, int val) {
    struct ListNode *l = malloc(sizeof(*l));
    l->val = val;
    l->next = NULL;
    l->next = head;
    return l;
}

void print(struct ListNode *head) {
    if (head == NULL) {
        printf("X\n");
        return;
    }
    printf("%d -> ", head->val);
    print(head->next);
}

int main() {
    struct ListNode *l1 = insert(NULL, 4);
    l1 = insert(l1, 2);
    l1 = insert(l1, 1);

    struct ListNode *l2 = insert(NULL, 4);
    l2 = insert(l2, 3);
    l2 = insert(l2, 1);

    struct ListNode *merged = mergeTwoLists(l1, l2);

    /*
    printf("l1: ");
    print(l1);
    printf("l2: ");
    print(l2);
    */

    printf("\nmerged: ");
    print(merged);
}

