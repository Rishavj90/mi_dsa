#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    /*
    while( node->next != NULL){
        node->val = node->next->val;
        node = node->next;
    }
    node->next = NULL; 
    *******************we know this is NULL, the above loop just checked that
    *******************we needed a ptr that points to the node whose next pointer points to null
    *******************so check node->next->next != NULL if true node->next = NULL and cut all connections with dat Asshole
    */
    while( node->next->next != NULL){
        node->val = node->next->val;
        node = node->next;
    }
    node->val = node->next->val;
    node->next = NULL; 
}