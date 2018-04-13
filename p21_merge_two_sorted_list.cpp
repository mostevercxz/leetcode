#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(const int x = 0) : val(x), next(NULL) {}
};

void printList(ListNode *head)
{
	while (head) {
		std::cout << head->val << "-->";
		head = head->next;
	}
	cout << endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	if (l1 == nullptr) {return l2;}
	if (l2 == nullptr) {return l1;}
        ListNode *insertStartPos = l1;
        ListNode *head = l1;
		for (ListNode *p = l2; p != nullptr;)
		{
			// 找到插入位置,第一个小于链表1节点值的位置
			ListNode *preq = nullptr;
			ListNode *q = insertStartPos;
			for (; q != nullptr && p->val >= q->val; q = q->next){
				preq = q;
			}
			if (preq){
				preq->next = p;
			}
			// 如果 q为链表头,说明待插入元素小于当前链表最小值,那么将p设为新的链表头
			if (head == q){
				head = p;
			}
			ListNode *tobeInserted = p->next;
			p->next = q;
			insertStartPos = p;
			p = tobeInserted;
		}
        
        return head;
}

ListNode *newList(vector<int> l)
{
	ListNode *head = nullptr;
	ListNode *pre = nullptr;
	ListNode *current = nullptr;
	for (const auto &val : l){
		current = new ListNode(val);
		if (head == nullptr){
			head = current;
		}
		if (pre != nullptr){
			pre->next = current;
		}
		pre = current;
	}

	return head;
}


int main(int argc, char const* argv[])
{
	printList(mergeTwoLists(newList({1,2,4}), newList({1,3,4})));
	printList(mergeTwoLists(newList({1,2,4}), newList({})));
	printList(mergeTwoLists(newList({1}), newList({2})));
	printList(mergeTwoLists(newList({2}), newList({1})));
	return 0;
}
