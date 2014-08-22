ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
	ListNode *start = NULL, *end = NULL;
	int carry = 0;
	while (l1 != NULL && l2 != NULL){
		int sum = l1->val + l2->val + carry;
		carry = sum / 10;
		sum = sum % 10;
		if (!end) {
			end = new ListNode(sum);
			start = end;
		}
		else{
			end = pushback(end, sum);
		}
		l1 = l1->next;
		l2 = l2->next;
	}

	while (l1 != NULL){
		int sum = l1->val + carry;
		end = pushback(end, sum % 10);
		carry = sum / 10;
		l1 = l1->next;
	}

	while (l2 != NULL){
		int sum = l2->val + carry;
		end = pushback(end, sum % 10);
		carry = sum / 10;
		l2 = l2->next;
	}

	if (carry) {
		end = pushback(end, carry);
	}

	return start;
}

ListNode *pushback(ListNode *end, int val) {
	ListNode *newNode = new ListNode(val);
	end->next = newNode;
	return newNode;
}