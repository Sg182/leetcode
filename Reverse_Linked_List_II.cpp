
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Reverse nodes from position left to right
Node* reverseBetween(Node* head, int left, int right) {

    if (head == nullptr || left == right) return head;

    Node dummy{0, head};
    Node* before = &dummy;

    // Move to the node before 'left'
    for (int i = 1; i < left; i++) {
        before = before->next;
    }

    Node* segmentTail = before->next;

    Node* prev = nullptr;
    Node* curr = segmentTail;

    // Reverse the required portion
    for (int i = left; i <= right; i++) {

        Node* nextNode = curr->next;

        curr->next = prev;

        prev = curr;
        curr = nextNode;
    }

    // Reconnect the reversed portion
    before->next = prev;
    segmentTail->next = curr;

    return dummy.next;
}

int main() {

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node{1, nullptr};

    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    Node* temp1 = head;
    while (temp1 != nullptr) {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }

    int left = 2;
    int right = 4;

    head = reverseBetween(head, left, right);
    cout << endl;
    // Print reversed list
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;

    // Free memory
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
