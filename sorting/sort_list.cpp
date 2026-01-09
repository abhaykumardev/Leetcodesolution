/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
ListNode* getMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head->next; // fast starts one step ahead

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

ListNode* merge(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    // pick the first node as head
    ListNode* head = nullptr;
    if (l1->val < l2->val) {
        head = l1;
        l1 = l1->next;
    } else {
        head = l2;
        l2 = l2->next;
    }

    // curr points to the last node in the merged list
    ListNode* curr = head;

    // iterate until one list becomes empty
    while (l1 && l2) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }

    // attach the remaining nodes
    if (l1) curr->next = l1;
    if (l2) curr->next = l2;

    return head;
}


public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;

        // Step 1: Split list into halves
        ListNode* mid = getMiddle(head);
        ListNode* rightHead = mid->next;
        mid->next = NULL; // break the list

        // Step 2: Sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(rightHead);

        // Step 3: Merge sorted halves
        return merge(left, right);
        
    }
};