class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		
		ListNode* header = new ListNode(0);
		int next_temp_num = 0;

		ListNode* pend = header;

		ListNode* p1 = l1;
		ListNode* p2 = l2;

		while (p1 && p2)
		{
			ListNode*  new_node = new ListNode(0);
			int new_value = 0;
			int sum = p1->val + p2->val + next_temp_num;
			if (sum >= 10) {
				next_temp_num = 1;
				new_value = sum - 10;
			}
			else {
				next_temp_num = 0;
				new_value = sum;
			}

			new_node->val = new_value;

			pend->next = new_node;
			pend = pend->next;

			p1 = p1->next;
			p2 = p2->next;

		}

		if (p1 == NULL) {
			while (p2) {
				int new_value = 0;
				int sum = p2->val + next_temp_num;
				if (sum >= 10) {
					next_temp_num = 1;
					new_value = sum - 10;
				}
				else {
					next_temp_num = 0;
					new_value = sum;
				}
				ListNode* new_node = new ListNode(new_value);
				pend->next = new_node;
				pend = new_node;
				p2 = p2->next;
			}

		}
		
		if (p2 == NULL) {
			while (p1) {
				int new_value = 0;
				int sum = p1->val + next_temp_num;
				if (sum >= 10) {
					next_temp_num = 1;
					new_value = sum - 10;
				}
				else {
					next_temp_num = 0;
					new_value = sum;
				}
				ListNode * new_node = new ListNode(new_value);
				pend->next = new_node;
				pend = new_node;
				p1 = p1->next;
			}
		}
		
		if (p1 == NULL && p2 == NULL && next_temp_num == 1)
		{
			ListNode* new_node = new ListNode(next_temp_num);
			pend->next = new_node;
			pend = new_node;
		}

		return header->next;

	}
};