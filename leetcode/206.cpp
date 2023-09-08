
// Given the head of a singly linked list, reverse the list, and return the
// reversed list.

//

// Example 1:

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
// Example 2:

// Input: head = [1,2]
// Output: [2,1]
// Example 3:

// Input: head = []
// Output: []

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
  ListNode *reverseList(ListNode *head) {
    // Check if the linked list is empty
    if (!head)
      return NULL;

    // Initialize pointers for current, previous, and next nodes
    ListNode *curr = head;
    ListNode *prev = NULL;

    // Iterate through the linked list
    while (curr->next != NULL) {
      // Store the next node in a temporary variable
      ListNode *next = curr->next;

      // Reverse the direction of the current node's pointer
      curr->next = prev;

      // Move the prev and curr pointers one step forward
      prev = curr;
      curr = next;
    }

    // Reverse the last node's pointer to the previous node
    curr->next = prev;

    // Return the new head of the reversed linked list
    return curr;
  }
};
