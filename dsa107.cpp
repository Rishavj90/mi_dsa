#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* vector_toDLL(vector<int>& vec){
    ListNode* head = new ListNode(vec[0]);
    ListNode*mover = head;
    for(int i = 1; i < vec.size(); i++){
        ListNode* temp = new ListNode(vec[i]);
        mover->next= temp;
        mover = mover->next;  
    }
    return head;
}

// ListNode* removeNthFromEnd(ListNode* head, int n) {
//     if(head == nullptr || head->next == nullptr) return nullptr;
//     int total = 0;
//     ListNode* i = head;
//     while(i != nullptr){
//         total++;
//         i = i->next;
//     }
//     if(total == n){
//         ListNode* temp = head;
//         head = head->next;
//         delete temp;
//         return head;
//     }
//     i = head;
//     while (i != nullptr){
//         if(total == n+1){
//             ListNode* prev = i;
//             ListNode* del_node = i->next;
//             ListNode* front = i->next->next;
//             prev->next = front;
//             del_node->next = nullptr;
//             delete del_node;
//             break;
//         }
//         total--;
//         i = i->next;
//     }
//     return head;
// }

ListNode* removeNthFromEnd(ListNode* head, int n){
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* fast = head, *slow = head;
    int i = 0;
    while(i < n){
        fast = fast->next;
        i++;
    }
    if(fast == nullptr){
        ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    while(fast->next != nullptr){
        slow = slow->next;
        fast = fast->next;
    }
    ListNode* del_node = slow->next;
    slow->next = slow->next->next;
    free(del_node);
    return head;
}

int main(){
    vector<int> vec = {1,2,3,4,5};
    ListNode* head = vector_toDLL(vec);
    head = removeNthFromEnd(head, 2);
    ListNode* i = head;
    while(i != NULL){
        cout << i->val<< " ";
        i = i->next;
    }
    return 0;
}