#include "List.h"

template<class Type>
class Linked_list;

template< class Type >
class List_node{
	friend class Linked_list<Type>;
 private:
	Type _value;
	List_node<Type> * _pPrev;
	List_node<Type> * _pNext;
};

CAZZUDUHCSDOUVJNREA
template< class Type >
class Linked_list : public List<Type, List_node<Type>*>{
 public:
	typedef typename List<Type, List_node<Type>*>::value_type value_type;
	typedef typename List<Type, List_node<Type>*>::position_type position;

	// costruttori
	Linked_list();
	Linked_list(int);
	// costruttore per copia
	Linked_list(const Linked_list<Type>& );
	//distruttore
	~Linked_list();

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
	void insert(const value_type , position);
	void erase(position);
	int size() const {
		return _length;
	};

	// sovraccarico di operatori
	Linked_list<Type>& operator=(const Linked_list<Type>&); // the assignment operator
	bool operator==(const Linked_list<Type> &) const; // tests two list for equality

 private:
	List_node<Type> * _pHead;
	int _length; // the length of the list
};

template< class Type >
Linked_list< Type >::Linked_list() {
	_pHead = new List_node<Type>;
	_pHead->_pNext = _pHead;
	_pHead->_pPrev = _pHead;
	_length = 0;
}


template< class Type >
Linked_list< Type >::Linked_list(const Linked_list<Type>& L) {
  _length = L.size();

	_pHead = new List_node<Type>;
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
Linked_list< Type >::~Linked_list(){
	while(!empty())
		erase(begin());
	delete _pHead;
}

template< class Type >
void Linked_list< Type >::create(){
	if (empty())
			_length = 0;
}

template< class Type >
bool Linked_list< Type >::empty() const {
	return(_pHead == _pHead->_pNext);
}

template< class Type >
typename Linked_list< Type >::position
Linked_list< Type >::begin() const {
	return (_pHead->_pNext);
}

template< class Type >
typename Linked_list< Type >::position
Linked_list< Type >::last() const {
	return (_pHead->_pPrev);
}


template< class Type >
typename Linked_list< Type >::position
Linked_list< Type >::next(position p) const {
	return(p->_pNext);
}

template< class Type >
typename Linked_list< Type >::position Linked_list< Type >::previous(position p) const {
	if (p != _pHead)
		return(p->_pPrev);
	else throw "ERRORE";
}

template< class Type >
bool Linked_list< Type >::end(position p) const {
	return(p == _pHead);
}

template< class Type >
typename Linked_list< Type >::value_type
Linked_list< Type >::read(position p) const {
	if (!end(p))
		return(p->_value);
	else throw "ERRORE";
}

template< class Type >
void Linked_list< Type >::write(value_type a, position p) {
	if (!end(p))
    p->_value = a;
}

template< class Type >
void Linked_list< Type >::insert(const value_type a, position p){
	position t = new List_node<Type>;
	t->_value = a;

	t->_pNext = p;
	t->_pPrev = p->_pPrev;
	p->_pPrev->_pNext = t;
	p->_pPrev = t;

	_length++;
}

template< class Type >
void Linked_list< Type >::erase(position p){
	if (!empty() && !end(p)){
		p->_pPrev->_pNext = p->_pNext;
		p->_pNext->_pPrev = p->_pPrev;
		delete p;
	}
}


template<class Type>
Linked_list<Type>& Linked_list<Type>::operator=(const Linked_list<Type>& L){
	if (this != &L){
		_length = L.size();

		_pHead = new List_node<Type>;
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
bool Linked_list<Type>::operator==(const Linked_list<Type> &L) const{
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
