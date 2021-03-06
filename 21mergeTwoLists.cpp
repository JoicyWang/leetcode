#include <stdint.h>
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l = new ListNode(0);
		ListNode* p = l;
		while ((l1 != NULL) && (l2 != NULL)) {
			if (l1->val > l2->val) {
				p->next = l2;
				l2 = l2->next;
				p = p->next;
			}
			else {
				p->next = l1;
				l1 = l1->next;
				p = p->next;
			}
		}
		if (l1 != NULL) {
			p->next = l1;
		}
		else if (l2 != NULL) {
			p->next = l2;
		}
		p = l->next;
		delete l;
		return p;
	}
};