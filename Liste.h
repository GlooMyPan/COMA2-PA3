//
// Created by Xuantong on 2021/6/15.
//

#ifndef PA3_LISTE_H
#define PA3_LISTE_H
#include <list>

template <class T>
class Liste
    : public std::list<T>
{
public:
/***  Konstruktoren  ***/
    Liste(){}
    Liste(Liste const &l);
/***  get-Methoden  ***/
    bool istSortiert() const;

    auto find(T const &t);

/***  set-Methoden  ***/
    void mergeSort();
};

#endif //PA3_LISTE_H
