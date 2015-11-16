search binary tree

return pointer that points to node or null

Node* BST::search(Node* head, int n) {	
	if (head->getValue() == n) return head;
	else {
		if (head->leftChild != 0) return search(head->leftChild);
		if (head->rightChild != 0) return search(head->rightChild);
	}	
	return 0;
	
	
}

Node* BST::preTraversal(int t[], int low, int high) {
	
}
