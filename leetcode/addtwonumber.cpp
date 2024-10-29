#include <iostream>
#include<vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* addtion(ListNode* head1, ListNode* head2, int carry) {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;
        ListNode* head3 = new ListNode(0);
        ListNode* temp3 = head3;
        int sum = 0;

        while (temp1 != NULL || temp2 != NULL || carry != 0) {
            sum = carry;
            if (temp1 != NULL) {
                sum += temp1->val;
                temp1 = temp1->next;
            }
            if (temp2 != NULL) {
                sum += temp2->val;
                temp2 = temp2->next;
            }
            int digit = sum % 10;
            carry = sum / 10;
            temp3->next = new ListNode(digit);
            temp3 = temp3->next;
        }
        return head3->next;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* Next = NULL;
        ListNode* prev = NULL;
        while (temp != NULL) {
            Next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = Next;
        }
        return prev;
    }

    int length(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        int len1 = length(l1);
        int len2 = length(l2);

        if (len1 <= len2) {
            return addtion(l1, l2, 0);
        } else {
            return addtion(l1, l2, 0);
        }
    }
};

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        head = head->next;
        if (head != nullptr) cout << " -> ";
    }
    cout << endl;
}

// Helper function to create a linked list from an array of integers
ListNode* createList(const vector<int>& nums) {
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); i++) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    // Test case 1
    vector<int> num1 = {2, 4, 3}; // Represents 342
    vector<int> num2 = {5, 6, 4}; // Represents 465
    ListNode* l1 = createList(num1);
    ListNode* l2 = createList(num2);

    ListNode* result = solution.addTwoNumbers(l1, l2);
    cout << "Result: ";
    printList(result); // Expected Output: 7 -> 0 -> 8 (Represents 807)

    // Free allocated memory
    delete l1;
    delete l2;
    delete result;

    return 0;
}
