#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* base;   //用作基准的链表
        ListNode* insert; //拆解插入基准链表
        if(list1 == nullptr && list2 == nullptr) return list1;
        if(list1 == nullptr && list2 != nullptr) return list2;
        if(list1 != nullptr && list2 == nullptr) return list1;
        if (list1->val >= list2->val) {
            base = list2;
            insert = list1;
        } else {
            base = list1;
            insert = list2;
        }
        ListNode* last = base;
        while (insert->next != nullptr) {
            while (base->val <= insert->val && base->next != nullptr) {
                if (base->next->val <= insert->val) {
                    base = base->next;
                }
                else{
                    break;
                }
            }
            ListNode* tmp = insert -> next;
            insert -> next = base -> next;
            base -> next = insert;
            insert = tmp;
            base = base -> next;
        }
        while (base->val <= insert->val && base->next != nullptr) {
            if (base->next->val <= insert->val) {
                base = base->next;
            }
            else{
                break;
            }
        }
        if(base->next!= nullptr && base->next->val >= insert->val){
            insert -> next = base -> next;
            base -> next = insert;
        }
        else{
            base->next = insert;
        }
        return last;
    }

};


int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    Solution solution;

    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << std::endl;


    return 0;

}