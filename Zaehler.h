//
// Created by Xuantong on 2021/6/15.
//

#ifndef PA3_ZAEHLER_H
#define PA3_ZAEHLER_H

#include <iostream> // für cout
#include <string>
#include <utility>

/**
* Klasse f¨ur einzelne W¨orter mit Z¨ahler f¨ur H¨aufigkeit
**/

class Zaehler
{
/***  private Elemente ***/
    std::string _s; // wort
    size_t _count; // zählt die Häufigkeit der Worter
public:
    friend
    std::ostream &operator<<(std::ostream &cout, Zaehler const &zaehler)
    {
        return std::cout << zaehler._s << " "<< zaehler._count;;
    }

/***  Konstruktoren  ***/
    Zaehler(std::string const& s)
        :_s(s),
         _count(1)
    {}

/***  set-Methoden  ***/
    void count()
    {
        ++_count;
    }

/***  Vergleichesoperatoren  ***/
    bool operator>(Zaehler const & zaehler) const
    {
        return _count < zaehler._count;
    }

    bool operator==(Zaehler const & zaehler) const
    {
        return _s == zaehler._s;
    }
};

#endif //PA3_ZAEHLER_H
