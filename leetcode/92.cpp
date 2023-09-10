// Given the head of a singly linked list and two integers left and right where
// left <= right, reverse the nodes of the list from position left to position
// right, and return the reversed list.

//

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]
// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || left == right) {
      return head; // If the list is empty or left equals right, there is
                   // nothing to reverse, so return the original list.
    }

    ListNode dummy(0);       // Create a dummy node to simplify the code.
    dummy.next = head;       // Link the dummy node to the head of the list.
    ListNode *prev = &dummy; // Initialize a pointer to the dummy node.

    // Move to the node just before the left position.
    for (int i = 1; i < left; i++) {
      prev = prev->next; // Traverse the list until you reach the node before
                         // the left position.
    }

    ListNode *curr = prev->next; // Initialize a pointer to the left node.
    ListNode *next = nullptr;    // Initialize a pointer to the next node.

    // Reverse the sublist from left to right.
    for (int i = left; i < right; i++) {
      next = curr->next;       // Store the next node in the original list.
      curr->next = next->next; // Update the current node's next pointer to skip
                               // the next node.
      next->next = prev->next; // Update the next node's next pointer to point
                               // to the beginning of the reversed sublist.
      prev->next = next; // Update the previous node's next pointer to point to
                         // the current node.
    }

    return dummy.next; // Return the modified list.
  }
};
