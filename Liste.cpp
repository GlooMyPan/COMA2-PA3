//
// Created by Xuantong on 2021/6/15.
//

#include "Liste.h"

/***  Konstruktoren  ***/
template<class T>
Liste<T>::Liste(const Liste<T> &l) // InsertionSort
{
    for (const T &t : l)
    {
        auto i = this->begin();
        while (i != this->end() && t > *i) // suche die erste Zahl groesser als t
            ++i;
        this->insert(i, t); // insert t vor die naechste groesser Zahl
    } // ich wollte es eigentlich mit binaere such zu machen, aber irgendwie kriege ich nicht hin.

} // Liste(const Liste<T> &l) O(n^2)

/***  get-Methoden  ***/
template<class T>
bool Liste<T>::istSortiert() const
{
    auto i1 = this->begin(); // schneller Iterator
    auto i2 = i1++; // lansamer Iterator
    while (i1 != this->end())
    {
        if (*i2 > *i1)
            return false;
        i2 = i1++; // beide Iteratoren werden sich vergroessern
    }
    return true;
} // istSortiert() O(n)

template<class T>
auto Liste<T>::find(const T &t)  {
    auto iter = this->begin();
    while (iter != this->end()) // laeuft die Iterator von begin() nach end()
    {
        if (*iter == t)
            break;
        else
            ++iter;
    }
    return iter;
} // find(const T &t) O(n)

/***  set-Methoden  ***/
template<class T>
void Liste<T>::mergeSort()
{
    size_t n = this->size();
    if (n < 2) // nicht noetig zu sort
        return;
    size_t middle = size_t(floor(n/2));
    auto miditer = this->begin();
    advance(miditer, middle); // finde mitte Iterator
    Liste<T> l2; // neue Objekt darzustellen
    l2.splice(l2.begin(), *this, this->begin(), miditer); // l2 haben die begin() nach mitte Iterator Daten von original Objekt
    this->mergeSort(); // rekursion
    l2.mergeSort(); //rekursion
    auto i1 = this->begin(); // begin() von original Objekt
    auto i2 = l2.begin(); // begin() von neue Objekt
    while (i1 != this->end() && i2 != l2.end()) // wenn der Iterator nicht am Ende stellt
    {
        while (i1 != this->end() && *i2 > *i1) // suche die Stelle, dass *i1 >= *i2 ist, wenn diese Stelle sich nicht gibt, dann stellt i1 am Ende
            ++i1;
        this->splice(i1, l2, i2++); // splicen i2 zu i1, und i2 wird sich vergroessern
    }
} //mergeSort() nlog(n)


