#include "nbaPlayoff.h"
#include <iostream>
#include <string>

class HashNode {
public:
	int key;
	nbaPlayoff* value;
	HashNode* next;

	HashNode() {//constructor
		key = 0;
		value = NULL;
		next = NULL;
	}

	HashNode(int k, nbaPlayoff* v) {//constructor
		key = k;
		value = v;
		next = NULL;
	}

	~HashNode() {//destructor
		if (value != NULL) {
			delete value;
		}
	}

	int getKey() {
		return key;
	}

	nbaPlayoff* getValue() {
		return value;
	}

	HashNode* getNext() {
		return next;
	}

	void setNext(HashNode* x) {
		next = x;
	}

	void setValue(nbaPlayoff* x) {
		value = x;
	}

	void setKey(int k) {
		key = k;
	}
};
