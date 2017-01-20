
#ifndef List_Pointer_H_
#define List_Pointer_H_

#include "List.h"

template<class Type>
class List_Pointer;

template< class Type >
class Node{
	friend class List_Pointer<Type>;
 private:
	Type _value;
	Node<Type> * _pPrev;
	Node<Type> * _pNext;
};


template< class Type >
class List_Pointer : public List<Type, Node<Type>*>{
 public:
	typedef typename List<Type, Node<Type>*>::value_type value_type;
	typedef typename List<Type, Node<Type>*>::position_type position;

	// costruttori
	List_Pointer();
	List_Pointer(int);
	// costruttore per copia
	List_Pointer(const List_Pointer<Type>& );
	//distruttore
	~List_Pointer();

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(value_type , position);
	position begin() const;
	position last() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(value_type , position);
	void erase(position);
	int size() const {
		return _length;
	};

	 void push_front(const value_type ) = 0;
		void push_back(const value_type ) = 0;
		void pop_front() = 0;
		void pop_back() = 0;
		void clear() = 0;

	// sovraccarico di operatori
	List_Pointer<Type>& operator=(const List_Pointer<Type>&); // the assignment operator
	bool operator==(const List_Pointer<Type> &) const; // tests two list for equality

 private:
	Node<Type> * _pHead;
	int _length; // the length of the list
};

template< class Type >
List_Pointer< Type >::List_Pointer() {
	_pHead = new Node<Type>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}


template< class Type >
List_Pointer< Type >::List_Pointer(const List_Pointer<Type>& L) {
  _length = L.size();

	_pHead = new Node<Type>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;

	if (!L.empty()){
		position p = L.last();
		for (int i=0; i <= L._length; i++){
			insert(L.read(p), begin());
			p = L.previous(p);
		}
	}
}


template< class Type >
List_Pointer< Type >::~List_Pointer(){
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class Type >
void List_Pointer< Type >::create(){
	if (empty())
			_length = 0;
}

template< class Type >
bool List_Pointer< Type >::empty() const {
	return(_pHead == _pHead->_pNext);
}

template< class Type >
typename List_Pointer< Type >::position
List_Pointer< Type >::begin() const {
	return (_pHead->_pNext);
}

template< class Type >
typename List_Pointer< Type >::position
List_Pointer< Type >::last() const {
	return (_pHead->_pPrev);
}


template< class Type >
typename List_Pointer< Type >::position
List_Pointer< Type >::next(position p) const {
	return(p->_pNext);
}

template< class Type >
typename List_Pointer< Type >::position List_Pointer< Type >::previous(position p) const {
	if (p != _pHead)
		return(p->_pPrev);
	else throw "ERRORE";
}

template< class Type >
bool List_Pointer< Type >::end(position p) const {
	return(p == _pHead);
}

template< class Type >
typename List_Pointer< Type >::value_type
List_Pointer< Type >::read(position p) const {
	if (!end(p))
		return(p->_value);
	else throw "ERRORE";
}

template< class Type >
void List_Pointer< Type >::write(value_type a, position p) {
	if (!end(p))
    p->_value = a;
}

template< class Type >
void List_Pointer< Type >::insert(value_type a, position p){
	position t = new Node<Type>;
	t->_value = a;

	t->_pNext = p;
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;
}

template< class Type >
void List_Pointer< Type >::erase(position p){
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
	}
}


template<class Type>
List_Pointer<Type>& List_Pointer<Type>::operator=(const List_Pointer<Type>& L){
	if (this != &L){
		_length = L.size();

		_pHead = new Node<Type>;
		_pHead->_pNext = _pHead;
		_pHead->_pPrev = _pHead;

        cout << L.empty();
        cout << L.size();
		if (!L.empty()){
            position p = L.last();
			for (int i=0; i < L.size(); i++){
				cout << i, L.read(p);
				insert(L.read(p), begin());
				p = L.previous(p);
			}
		}
	}
	return *this;
}


template<class Type>
bool List_Pointer<Type>::operator==(const List_Pointer<Type> &L) const{
	if (L.size() != _length)
		return false;
	position p, pL;
	p = begin();
	pL = L.begin();
	while (!end(p)){
		if (p->_value != pL->_value)
			return false;
		p = p->_pNext;
		pL = pL->_pNext;
	}
	return true;
}

#endif /* List_Pointer_H_*/
