#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <iostream>

namespace std {

template<typename T>
struct Node{
	T 			data;
	Node<T>* 	next;
};

template<typename T>
class LinkedList {
protected:
	Node<T>*   	head;
	Node<T>*   	tail;
	int 		count;
public:
	LinkedList();
	virtual ~LinkedList();
	LinkedList(const LinkedList &other);
	LinkedList& operator=(const LinkedList &other);

	bool isEmpty();
	int length();

	Node<T>* search(const T& val);
	void insertFirst(const T &val);
	void insertLast(const T &val);

	void insertAt(const int idx, const T &val);
	void insertAfter(const T &sVal, const T &val);
	void insertBefore(const T &sVal, const T &val);

	void deleteNode(const T &val);
	void clearList();
	void copyList(const LinkedList<T> &other);
	T front();
	T back();

	template <typename S>
	friend ostream& operator<<(ostream& out, const LinkedList<S> &list);

protected:
	Node<T>* getPrevNodeOf(const Node<T> *node);
};

template <typename T>
LinkedList<T>::LinkedList() {
	head = tail = NULL;
	count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList() {
	clearList();
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) {
	head = tail = NULL;
	Node<T> *p = other.head;

	while (p != NULL){
		insertLast(p->data);
		p = p->next;
	}
	count = other.count;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList &other) {
	clearList();
	if (other.count == 0)
		return *this;

	Node<T> *p = other.head;
	while(p != NULL){
		insertLast(p->data);
		p = p->next;
	}
	return *this;
}


template <typename T>
bool LinkedList<T>::isEmpty(){
	return (count == 0);
}

template <typename T>
int LinkedList<T>::length(){
	return count;
}

template <typename T>
Node<T>* LinkedList<T>::search(const T &val){
	bool found = false;
	Node<T> *p = head;
	while ((p != NULL) && !found){
		if (p->data == val)
			found = true;
		else
			p = p->next;
	}
	return p;
}

template <typename T>
void LinkedList<T>::insertFirst(const T &val){
	Node<T> *p = new Node<T>;
	p->data= val;
	p->next = head;
	head = p;
	if (tail == NULL)
		tail = p;

	count++;
}

template <typename T>
void LinkedList<T>::insertLast(const T &val){
	Node<T> *p = new Node<T>;
	p->data = val;
	p->next = NULL;

	if (head != NULL){
		tail->next = p;
		tail = p;
	}
	else{
		head = tail = p;
	}
	count++;
}

template <typename T>
void LinkedList<T>::insertAt(const int idx, const T &val){
	if (idx > count){
//		cout << "Given index is greater than the number of element, so appending to list"<<endl;
		insertLast(val);
	}
	else if (idx <= 1){
//		cout << "Given index value is less than or equal to 1, so inserting as the first element"<<endl;
		insertFirst(val);
	}
	else{ // insert at given position
		Node<T> *prevNode = head;
		int cnt=2;
		while (cnt < idx){
			prevNode = prevNode->next;
		} // we found (idx-1)'th node

		Node<T> *newNode = new Node<T>;
		newNode->data = val;
		newNode->next = prevNode->next;
		prevNode->next = newNode;
	}
	count++;
}

template <typename T>
void LinkedList<T>::insertAfter(const T &sVal, const T &val){
	Node<T> *searchItem = search(sVal); // search for sVal in the list
	if (searchItem == NULL){
		cout << "The value "<<sVal<<" is not found in the list, so nothing will be inserted."<<endl;
	}
	else{ // we found searched item
		Node<T> *newNode = new Node<T>;
		newNode->data = val;
		newNode->next = searchItem->next;
		searchItem->next = newNode;
		count++;
	}
}

template <typename T>
void LinkedList<T>::insertBefore(const T &sVal, const T &val){
	Node<T> *searchItem = search(sVal); // search for sVal in the list
	if (searchItem == NULL){
		cout << "The value "<<sVal<<" is not found in the list, so nothing will be inserted."<<endl;
	}
	else{ // we found searched item
		Node<T> *newNode = new Node<T>;
		newNode->data = val;
		if (searchItem == head) { // insert as first element
			newNode->next = head;
			head = newNode;
		} else {
			Node<T> *prevNode = getPrevNodeOf(searchItem);
			newNode->next = prevNode->next;
			prevNode->next = newNode;
		}
		count++;
	}
}

template <typename T>
void LinkedList<T>::deleteNode(const T &val){
	Node<T> *delItem = search(val); // search val in the list

	if (delItem == NULL){ // not found in the list
		cout << "Item "<< val << " is not in the list, nothing to delete!"<<endl;
	}
	else{ // found in the list and delItem points to that node
		// depending on the position, delete appropriately
		if (delItem == head){ // delete first node
			head = delItem->next; // or head = head->next; both are same
		}
		else {
			Node<T> *prevNode = getPrevNodeOf(delItem); // find the previous node
			if (delItem == tail) { // if last item is to be deleted
				prevNode->next = NULL;
				tail = prevNode;
			} else {
				prevNode->next = delItem->next;
			}
		}
		delete delItem;
		count--;
	}
}

template <typename T>
void LinkedList<T>::clearList() {
	Node<T> *p;

	while (head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	tail = NULL;
	count = 0;
}

template <typename T>
void LinkedList<T>::copyList(const LinkedList<T> &other){
	*this = other; // calls assignment operator
}

template <typename T>
T LinkedList<T>::front(){
	assert(head != NULL);
	return head->data;
}

template <typename T>
T LinkedList<T>::back(){
	assert(tail != NULL);
	return tail->data;
}

template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T> &list){
	Node<T> *p = list.head;
	while(p != NULL){
		cout << p->data << " ";
		p = p->next;
	}
	return out;
}

template <typename T>
Node<T>* LinkedList<T>::getPrevNodeOf(const Node<T> *node){
	if (node == head)
		return NULL; // if the node is the first element, then return NULL

	Node<T> *prevNode = head;
	while (prevNode->next != node){
		prevNode = prevNode->next;
	}
	return prevNode;
}

} /* namespace std */

#endif /* LINKEDLIST_H_ */
