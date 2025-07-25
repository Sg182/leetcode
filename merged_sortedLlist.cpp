#include <iostream>
using namespace std;

// Definition for singly‐linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Merges two sorted lists by splicing nodes and returns the head of the merged list.
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify edge cases
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // While both lists have nodes, pick the smaller head
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Append whatever remains
        tail->next = (l1 != nullptr) ? l1 : l2;

        return dummy.next;
    }
};

// Helper to print a list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << "->";
        head = head->next;
    }
    cout << "\n";
}

int main() {
    // Example 1: [1,2,4] + [1,3,4] -> [1,1,2,3,4,4]
    ListNode* a1 = new ListNode(1);
    a1->next = new ListNode(2);
    a1->next->next = new ListNode(4);

    ListNode* b1 = new ListNode(1);
    b1->next = new ListNode(3);
    b1->next->next = new ListNode(4);

    Solution sol;
    ListNode* merged1 = sol.mergeTwoLists(a1, b1);
    printList(merged1);  // Output: 1->1->2->3->4->4

    // Example 2: [] + [] -> []
    ListNode* merged2 = sol.mergeTwoLists(nullptr, nullptr);
    printList(merged2);  // Output: (prints nothing)

    return 0;
}
