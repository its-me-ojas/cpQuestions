// Given the head of a sorted linked list, delete all duplicates such that each
// element appears only once. Return the linked list sorted as well.

//

// Example 1:

// Input: head = [1,1,2]
// Output: [1,2]
// Example 2:

// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

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
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }

    ListNode *current = head;

    while (current->next) {
      if (current->val == current->next->val) {
        ListNode *temp = current->next;
        current->next = current->next->next;
        delete temp; // Free the memory of the duplicate node
      } else {
        current = current->next;
      }
    }

    return head;
  }
};
