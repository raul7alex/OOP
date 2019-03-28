#include <iostream>

template <class T>
class Lista
{
public:
    struct Iterator;    //Declaratie forward
    Lista();            //Constructroul clasei
     ~Lista();           //Destructorul clasei
    inline Lista& operator = (const Lista& list);
   	inline friend std::istream& operator >> (std::istream& is, Lista&lista){
		return is >> lista.T;} 
	inline friend std::ostream& operator << (std::ostream& os, const Lista& lista){	
		return os << lista.T;} 
    void push_front(T elem); // Inserare in fata primului nod
    void push_back(T elem);  // Inserare dupa ultimul nod
    void insert_before(T elem, Iterator nod); // Inserare inainte de nod
    void insert_after(T elem, Iterator nod);  // Inserare dupa nod
    Iterator search(T value) const; // Lista contine value?
    void pop_front(); // Elimina nodul din fata
    void pop_back();  // Elimina ultimul nod
    void remove(Iterator nod); // Elimina nodul nod
    Iterator begin() const; // Returneaza un iterator catre inceputul listei
    Iterator end() const; // Returneaza un iterator catre sfarsitul listei
    bool isEmpty() const; // Este lista vida?
    void clear(); // Stergerea completa a listei


private:
    struct Nod  // Clasa Helper; Implementeaza un nod de lista
    {
		Nod(T data, Nod* next): data{data}, next{next} {}
		Nod(const Nod& a)
		{
			Nod b = new Nod();
			b->data = a->data;
			b->next = a->next;
			this = b;
		}
		Nod() { this->next = nullptr; }
        T data;   // informatia propriu-zisa
        Nod * next; // urm
    };
    Nod * head; // prim

public:
    struct Iterator
    {
        friend class Lista; //Lista are acees la membri privati ai lui iterator
        Iterator()  {list = nullptr; }
        Iterator(Nod* ls) { list = ls; }
        //supraincararea operatorului de deferentiere
        T& operator*() {if(list != nullptr) return list->data; else throw "Null iterator";}
        //Prefix - Trec la urmatorul nod
         Iterator& operator++() { list = list->next; return *this; }
        // Postfix
        Iterator operator++(int a) { Iterator temp = *this; ++(*this); return temp;}
        bool operator==(const Iterator& it) const { if(it.list == this->list) return true; else return false; }
        bool operator!=(const Iterator& it) const { if(!(it == *this)) return true; else return false; }
    private:
        Nod* list;
    };
};
template <typename T>
Lista<T>::Lista()
{
    head  = nullptr;
}
template <typename T>
bool Lista<T>::isEmpty() const
{
    return head == nullptr;
}
template <typename T>
void Lista<T>::push_front(T elem)
{
     if(isEmpty())
    {
        head = new Nod;      // Aloc memorie pentru primul nod
        head->data = elem;   //Scriu informatia in data
        head->next = nullptr; // Fiind singurul nod, urmatorul este NIMIC adica NULL
    }
    else
    {
        Nod * nod = new Nod; // Aloc memorie pentru noul nod
        nod->data = elem;    // Scriu informatia in data
        nod->next = head;    // Leg nod de head
        head = nod;          // nod devine noul head
    }
}

template <typename T>
void Lista<T>::push_back(T elem)
{
    if(isEmpty())
    {
        head = new Nod;        // Aloc memorie pentru primul nod
        head->data = elem;     //Scriu informatia in data
        head->next = nullptr;  // Fiind singurul nod, urmatorul este NIMIC adica NULL

    }
    else
    {
        Nod * nod = new Nod; // Aloc memorie pentru noul nod
        nod->data = elem;    // Scriu informatia in data
        nod->next = nullptr; // Devenind nod terminal, va fi legat de NULL

        Nod* temp = head;      //parcurge cu un temporal pana la ultimul nod din lista,
        while(temp->next != nullptr)
            temp = temp->next;

        temp->next = nod;   //lega nod la sfarsitul listei
    }
}
template <typename T>
void Lista<T>::insert_after(T elem, Iterator nod)
{
    Nod * newNod = new Nod; // Aloc memorie pentru noul nod
    newNod->data = elem;    // Scriu informatia in data
    newNod->next = nod.list->next; // newNod se leaga de succesorul lui 'nod'
    nod.list->next = newNod; // Nodul 'nod' se leaga de newNod

}

template <typename T>
void Lista<T>::insert_before(T elem, Iterator nod)
{
   Nod * newNod = new Nod; // Aloc memorie pentru noul nod
    // --- Interschimb informatia --- //
    newNod->data = nod.list->data; // Copiez informatia din 'nod' in newNod
    nod.list->data = elem; // 'nod' va memora informatia care trebuie adaugata la lista
    // ------------------------------ //
    newNod->next = nod.list->next; // newNod se leaga de succesorul lui 'nod'
    nod.list->next = newNod; // Nodul 'nod' se leaga de newNod

}
template<typename T>
typename Lista<T>::Iterator Lista<T>::search(T value) const
{
    for(Nod* it = head; it != nullptr; it = it->next)
    {
        if(it->data == value) return Iterator(it); // Daca am gasit nodul il returnez
    }
    return end(); // Nu am gasit nimic
}

template <typename T>
void Lista<T> ::pop_front()
{
    if(isEmpty()) throw "Empty List"; // Daca lista este vida
    if(head == nullptr) // Daca lista are un singur nod
    { delete head; head = nullptr; return; }
    Nod * temp = head; // Salvez adresa obiectului head
    head = head->next; // Succesorul lui head devine noul head
    delete temp; // Eliberez memoria ocupata de vechiul obiect head
}

template <typename T>
void Lista<T>::pop_back()
{
    if(isEmpty()) throw "Empty List"; // Daca lista este vida
    if(head == nullptr) // Daca lista are un singur nod
    { delete head; head  = nullptr; return; }

    Nod * pred = head;  //parcurg cu un temporal pana la penultimul element din lista
    while(pred->next->next != nullptr)
        pred = pred->next;
    Nod* temp = pred->next; //un alt temporal va lua adresa ultimului element
    pred ->next = nullptr;  //succesorul penultimului element va fi nullptr
    delete temp;            //sterge temporlalul care contine adresa ultimului nod
}

template <typename T>
void Lista<T>::remove(Iterator nod)
{
    if(isEmpty()) throw "Empty List"; // Daca lista este vida
    if(head == nullptr) // Daca lista are un singur nod
    { delete head; head =  nullptr; return; }
    Nod * temp = nod.list->next; // Salvez adresa succesorului lui 'nod'
    // Copiez toata informatia succesorului in 'nod'
    nod.list->data = nod.list->next->data;
    nod.list->next = nod.list->next->next;
    delete temp; // Eliberez memoria ocupata de succesor; il elimin

}

template <typename T>
void Lista<T>::clear()
{
    Nod *it = head, *temp;
    while(it != nullptr)
    {
        temp = it; // Salvez adresa nodului curent
        it = it->next; // Trec mai departe
        delete temp; // Distrug nodul curent
    }
    head  = nullptr; // Lista Vida
}

template <typename T>
Lista<T>::~Lista()
{
    if(!isEmpty()) clear();
}
template <typename T>
Lista<T>& Lista<T>::  operator = (const Lista& list){
	
	clear();
	
    Lista<T>::Iterator it;
	for(it = list.begin(); it != list.end(); it++)
	{
		push(*it);
	}
    
}


template<typename T>
typename Lista<T>::Iterator Lista<T>::begin() const { return Iterator(head); }
template<typename T>
typename Lista<T>::Iterator Lista<T>::end() const { return Iterator(nullptr); }

