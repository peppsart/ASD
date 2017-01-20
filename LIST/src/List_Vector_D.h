
#ifndef List_Vector_D_H_
#define List_Vector_D_H_

using namespace std;

template <class Type>
class List_Vector_D : public List <Type, int>

{

public:

	typedef typename List<Type, int>:: value_type value_type;
	typedef typename List<Type, int>:: position_type position;

	//List_Vector_D(); //costruttore
	List_Vector_D(int = 0); //costruttore
	List_Vector_D(const List_Vector_D<Type>&); //costruttore di copia

	~List_Vector_D(); //distruttore

	// operatori
	void create();
	bool empty() const;
	value_type read(position) const;
	void write(value_type, position);
	position begin() const;
	bool end(position) const;
	position next(position) const;
	position previous(position) const;
	void insert(value_type, position);
	void erase(position);

	// Funzioni  di servizio
	void push_front(const value_type );
	void push_back(const value_type );
	void pop_front();
	void pop_back();
	void clear(); //reinizializza gli elementi di tutta la List_Vector_Da

	// funzioni di servizio
	void print();

private:

	value_type* elements;

	int length; // length della List_Vector_D
	int array_size; // lunghezza dell'array

};

// Implementazione della classe List_Vector_D

// costruttore
/*
template <class Type> List_Vector_D<Type>::List_Vector_D(){


	array_size = 0;
	create();

}
*/
template <class Type> List_Vector_D<Type>::List_Vector_D(int dim){

	array_size = dim;
	create();

}

// costruttore di copia

/* il costruttore di copia effettua una copia o clone di un oggetto. E' invocato, ad esempio,

quando un oggetto è passato per valore ad una funzione ovvero quando una funzione

restituisce un oggetto

 */

template <class Type>
List_Vector_D<Type>::List_Vector_D(const List_Vector_D<Type>& L){

	length = L.length;
	array_size = L.array_size;

	for (int i = 0; i<length; i++){

		elements[i] = L.elements[i];
	}

}

// distruttore

template <class Type> List_Vector_D<Type>::~List_Vector_D()

{

}

// operatori

template <class Type> void List_Vector_D<Type>::create(){

	length  =  0;
	this->elements = new Type [array_size];

}

template <class Type> bool List_Vector_D<Type>::empty() const{

	return(length == 0);

}

template <class Type>
typename List_Vector_D<Type>::position List_Vector_D<Type>::begin() const{

	return(1);

}

template<class Type>
typename List_Vector_D<Type>::position List_Vector_D<Type>::next(position p) const{

	if ((p>0) && (p<length+1)) // precondizione

		return(p+1);

	else

		return(p); //DA SISTEMARE CON THROW

}

template <class Type>
typename List_Vector_D<Type>::position List_Vector_D<Type>::previous(position p) const{

	if ((p>0) && (p<length+1)) // precondizione

		return(p-1);

	else

		return(p);

}

template <class Type> bool List_Vector_D<Type>::end(position p) const{

	if ((p>0) && (p<= length+1)) // precondizione

		return( p == length+1);

	else

		return(false);

}

template <class Type>
typename List_Vector_D<Type>::value_type List_Vector_D<Type>::read(position p) const{

	if ((p>0) && (p<length+1)) // precondizione
	{
		return (elements[p-1]);
	}

}

template <class Type> void List_Vector_D<Type>::write(value_type a, position p){

	if ((p>0) && (p<length+1)) // precondizione

		elements[p-1] = a;

}

template <class Type> void List_Vector_D<Type>::insert(value_type a, position p){

	if ((p>0) && (p<= length+1)) // precondizione

	{
		array_size++;
		value_type* temp = new Type [array_size];

		for(int i = 0; i < length; i++)
		{
			temp[i] = elements[i];
		}

		delete [] elements;
		elements = temp;



		for (int i = length; i>= p; i--)

			elements[i]  =  elements[i-1];

		elements[p-1] = a;

		length++;

	}

}

template <class Type> void List_Vector_D<Type>::erase(position p){

	if ((p>0) && (p<length+1)) // precondizione

		if (!empty())

		{

			for (int i = p-1;i<(length-1);i++)

				elements[i] = elements[i+1];

			length--;

		}

}

// Funzioni  di servizio //

template <class Type>
void List_Vector_D<Type>::push_front(const value_type value){

	insert( value, begin());

};

template <class Type>
void List_Vector_D<Type>::push_back(const value_type value){

	insert(value, length);

};

template <class Type>
void List_Vector_D<Type>::pop_front(){

	erase(begin());
};

template <class Type>
void List_Vector_D<Type>::pop_back(){
	erase(length);

};

/// da vedere ///
template <class Type>
void List_Vector_D<Type>::clear(){
	/*
	delete [] this->elements;
	this->array_dimension = starting_dim;

	this->elements = new Type[ starting_dim ];
	this->length = 0;*/

};

template <class Type> void List_Vector_D<Type>::print(){
	for(int i  =  0; i < length; i++)
	{
		cout << elements[i] << endl;
	}

}

#endif /* List_Vector_D_H_ */
