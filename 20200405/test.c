//��������в�������
struct ListNode {
	int val;
	struct ListNode *next;
	
};

struct ListNode* insertionSortList(struct ListNode* head) {
	struct ListNode* cur, *prev, *start,*newH;
	prev = head;
	cur = head->next;
	newH = (struct ListNode*)malloc(sizeof(struct ListNode));
	newH->next = head;
	while (cur) {
		if (cur->val >= prev->val) {
			prev = cur;
			cur = cur->next;
		}
		else {
			start = head;
			while (start->next&&start->next->val <= cur->val)
				start = start->next;
			prev->next = cur->next;
			cur->next = start->next;
			start->next = cur;
			cur = prev->next;
		}
	}
	cur = newH->next;
	free(newH);
	return cur;
}

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
/*��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬
�ظ��Ľ�㲻��������������ͷָ�롣 ���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5*/
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead){
		struct ListNode* prev, *cur, *next,*tmp;
		if (pHead == NULL || pHead->next == NULL)
			return pHead;
		prev = NULL;
		cur = pHead;
		next = cur->next;
		while (next) {
			if (cur->val != next->val) {
				prev = cur;
				cur = next;
				next = next->next;
			}
			else {
				while (next&&cur->val == next->val) {
					next = next->next;
				}
				while (cur != next) {
					tmp = cur->next;
					free(cur);
					cur = tmp;
				}
				if (prev = NULL) {//ɾ������ͷ���
					pHead = cur;
				}
				else {
					prev->next = cur;
				}
				if (next) {
					next = next->next;
				}
			}
		}
		return pHead;
	}
};