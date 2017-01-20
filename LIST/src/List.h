/*
 * List.h
 *
 *  Created on: 18 gen 2017
 *      Author: giuse
 */

#ifndef LIST_H_
#define LIST_H_

using namespace std;

template <class Type, class Position>
class List {

public:

	typedef Type 		value_type;           //Tipo elementi nella lista
	typedef Position 	position_type;        //Tipo posizioni della lista


	// operatori

	virtual void create() = 0;

	virtual bool empty() const = 0;

	virtual value_type read(position_type) const = 0;

	virtual void write(value_type, position_type) = 0;

	virtual position_type begin() const = 0;

	virtual bool end(position_type) const = 0;

	virtual position_type next(position_type) const = 0;

	virtual position_type previous(position_type) const = 0;

	virtual void insert(value_type, position_type) = 0;

	virtual void erase(position_type) = 0;

	// Funzioni  di servizio
	virtual void push_front(const value_type ) = 0;
	virtual void push_back(const value_type ) = 0;
	virtual void pop_front() = 0;
	virtual void pop_back() = 0;
	virtual void clear() = 0;

	virtual ~List() = 0;


};


// Operatore << per dati primitivi
template< class Type, class Position >
ostream& operator<<(ostream& os, const List<Type,Position> &list) {

	typename List<Type,Position>::position_type pos;

	pos = list.begin();
	cout << "[";

	while ( !list.end(pos) )
	{

		if ( pos != list.begin() ) {
			cout << ", " << list.read(pos);
		} else {
			cout << list.read(pos);
		}

		pos = list.next(pos);
	}

	cout << "]" << endl;

	return os;
}


#endif /* LIST_H_ */
