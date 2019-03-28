#include <iterator>

template<class T>
class ListaD
{
public:
    struct Iterator; // Declaratie forward
    // Constructor - Initializarea listei
    ListaD() { head = tail = nullptr; /*Se creeaza lista vida*/ }
    // Destructor - Distrugerea listei
    ~ListaD() { if(!isEmpty()) clear(); }
    void push_front(T elem); // Inserare in fata primului nod
    void push_back(T elem);  // Inserare dupa ultimul nod
    void insert_before(T elem, Iterator nod); // Inserare inainte de nod
    void insert_after(T elem, Iterator nod);  // Inserare dupa nod
    Iterator search(T value) const; // Cauta value in lista
    void pop_front(); // Elimina nodul din fata
    void pop_back();  // Elimina ultimul nod
    void remove(Iterator nod); // Elimina nodul nod
    // Returneaza un iterator catre inceputul listei
    Iterator begin() const { return Iterator(head); }
    // Returneaza un iterator catre nodul tail
    Iterator end() const { return Iterator(nullptr); }
    bool isEmpty() const { return head == nullptr; } // Este lista vida?
    void clear(); // Stergerea completa a listei

private:
    struct Nod  // Clasa Helper; Implementeaza un nod de lista
    {
        T data;   // informatia propriu-zisa
        Nod * next; // urm
        Nod * previous; // ant
    };
    Nod * head; // prim
    Nod * tail; // ultim
public:
    struct Iterator : public std::iterator<std::random_access_iterator_tag, T>// Un pointer inteligent
    {
        friend class ListaD; // Lista are acces la membrii privati ai lui Iterator
        Iterator() { list = nullptr; }
        Iterator(Nod * ls) { list = ls; }
        // Supraincarc operatorul * (dereferentiere)
        T& operator*() { if(list != nullptr) return list->data; else throw "Null iterator!"; }
        // Prefix - Trec la urmatorul nod
        Iterator& operator++() { list = list->next; return *this; }
        // Postfix
        Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; }
        // Prefix - Trec la nodul anterior
        Iterator& operator--() { list = list->previous; return *this; }
        // Postfix
        Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; }
        bool operator==(const Iterator& it) const { if(it.list == this->list) return true; else return false; }
        bool operator!=(const Iterator& it) const { if(!(it == *this)) return true; else return false; }
    private:
        Nod * list;
    };
};


template<class T>
void ListaD<T>::push_front(T elem)
{
    // Daca lista este vida, atunci
    if(isEmpty())
    {
        head = new Nod; // Aloc memorie pentru primul nod
        head->data = elem;
        head->next = nullptr; // Fiind singurul nod, urmatorul este NIMIC adica NULL
        head->previous = nullptr; // Fiind singurul nod, anteriorul este NIMIC adica NULL
        tail = head; // si tail == head
    }
    else  // altfel
    {
        Nod * nod = new Nod; // Aloc memorie pentru noul nod
        nod->data = elem;    // Scriu informatia in data
        nod->previous = nullptr; // Devenind head, previous indica NULL
        nod->next = head;    // Leg nod de head
        head->previous = nod; // Predecesorul fostului head este 'nod'
        head = nod;          // nod devine noul head
    }
}

template<class T>
void ListaD<T>::push_back(T elem)
{
    // Daca lista este vida, atunci
    if(isEmpty())
    {
        head = new Nod; // Aloc memorie pentru primul nod
        head->data = elem;
        head->next = nullptr; // Fiind singurul nod, urmatorul este NIMIC adica NULL
        head->previous = nullptr; // Fiind singurul nod, anteriorul este NIMIC adica NULL
        tail = head; // si tail == head
    }
    else  // altfel
    {
        Nod * nod = new Nod; // Aloc memorie pentru noul nod
        nod->data = elem;    // Scriu informatia in data
        nod->next = nullptr; // Devenind nod terminal, va fi legat de NULL
        nod->previous = tail; // previous indica tail
        tail->next = nod;    // Fostul tail este legat de noul tail
        tail = nod;          // nod devine tail
    }
}

template<class T>
void ListaD<T>::insert_after(T elem, Iterator nod)
{
    Nod * newNod = new Nod; // Aloc memorie pentru noul nod
    newNod->data = elem;    // Scriu informatia in data
    newNod->next = nod.list->next; // newNod se leaga de succesorul lui 'nod'
    newNod->previous = nod.list; // Predecesorul lui newNod este 'nod'
    // Daca nodul 'nod' a fost ultimul nod, atunci nodul newNod devine nod terminal
    if(nod.list == tail) tail = newNod;
    else nod.list->next->previous = newNod; // Predecesorul succesorului lui 'nod' este newNod
    nod.list->next = newNod; // Nodul 'nod' se leaga de newNod
}

template<class T>
void ListaD<T>::insert_before(T elem, Iterator nod)
{
    Nod * newNod = new Nod; // Aloc memorie pentru noul nod
    newNod->data = elem; // Scriu informatia in data
    newNod->next = nod.list; // Succesorul lui newNod este 'nod'
    newNod->previous = nod.list->previous; // Predecesorul lui newNod este predecesorul lui 'nod'
    // Daca nodul 'nod' a fost primul nod, atunci nodul newNod devine head
    if(nod.list == head) head = newNod;
    else nod.list->previous->next = newNod; // Succesorul predecesorului lui 'nod' este newNod
    nod.list->previous = newNod; // Predecesorul lui 'nod' este newNod
}

template<class T>
typename ListaD<T>::Iterator ListaD<T>::search(T value) const
{
    for(Nod* it = head; it != nullptr; it = it->next)
    {
        if(it->data == value) return Iterator(it); // Daca am gasit nodul il returnez
    }
    return nullptr; // Nu am gasit nimic
}

template<class T>
void ListaD<T>::pop_front()
{
    if(isEmpty()) throw "Empty List"; // Daca lista este vida
    if(head == tail) // Daca lista are un singur nod
    { delete head; head = tail = nullptr; return; }
    Nod * temp = head; // Salvez adresa obiectului head
    head->next->previous = nullptr; // Predecesorul succesorului lui head devine NULL
    head = head->next; // Succesorul lui head devine noul head
    delete temp; // Eliberez memoria ocupata de vechiul obiect head
}

template<class T>
void ListaD<T>::remove(Iterator nod)
{
    if(isEmpty()) throw "Empty List"; // Daca lista este vida
    if(head == tail) // Daca lista are un singur nod
    { delete head; head = tail = nullptr; return; }
    if(nod == head) //daca nod este primul element din lista
    {
         nod.list->next->previous = nullptr;   //predecesorul urmatorului element devine nullptr
         head = nod.list->next;                 //succesorul lui nod devine head
    }
    else
        if(nod == tail) //daca nod este ultimul element
        {
            nod.list->previous->next = nullptr; // predecesorul lui nod va avea next ca nullptr
            tail = nod.list->previous;          // predecesorul lui nod va fi noul tail
        }
            else
            {
                nod.list->previous->next = nod.list->next; // Leg predecesorul lui 'nod' de succesorul acestuia
                nod.list->next->previous = nod.list->previous; // Predecesorul succesorului lui 'nod' indica predecesorul lui 'nod'
            }
    delete nod.list; // Elimin nodul 'nod'
}

template<class T>
void ListaD<T>::pop_back()
{
    if(isEmpty()) throw "Empty List"; // Daca lista este vida
    if(head == tail) // Daca lista are un singur nod
    { delete head; head = tail = nullptr; return; }
    Nod * temp = tail; // Salvez adresa obiectului tail
    tail->previous->next = nullptr; // Succesorul predecesorului lui tail devine NULL
    tail = tail->previous; // Predecesorul lui tail devine noul tail
    delete temp; // Eliberez memoria ocupata de vechiul obiect tail
}

template<class T>
void ListaD<T> ::clear()
{
    Nod *it = head, *temp;
    while(it != nullptr)
    {
        temp = it; // Salvez adresa nodului curent
        it = it->next; // Trec mai departe
        delete temp; // Distrug nodul curent
    }
    head = tail = nullptr; // Lista Vida
}

