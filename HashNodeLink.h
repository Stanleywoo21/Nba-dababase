#include "HashNode.h"
#include <iostream>
#include <string>

class HashNodeLink {
private:

public:
	HashNode* head;
	HashNode* tail;

	int listCount;

	HashNodeLink() {
		head = NULL;
		tail = NULL;
		listCount = 0;
	}

	~HashNodeLink() {
		HashNode* temp = head;
		for (int i = 0; i < listCount; i++) {
			HashNode* holder = temp->next;
			delete temp;
			if(temp != NULL) {
				temp = holder;
			}
			else {
				break;
			}
		}
	}

	HashNode* getHead() {
		return head;
	}

	HashNode* getTail() {
		return tail;
	}

	int getListCount() {
		return listCount;
	}

	void setHead(HashNode* h) {
		head = h;
	}

	void setTail(HashNode* t) {
		tail = t;
	}

	void setListCount(int x) {
		listCount = x;
	}
};
