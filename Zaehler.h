//
// Created by Xuantong on 2021/6/15.
//

#ifndef PA3_ZAEHLER_H
#define PA3_ZAEHLER_H

#include <iostream> // für cout
#include <string>


class Zaehler
{
/***  private Elemente ***/
    std::string _s; // wort
    size_t _count; // zählt die Häufigkeit der Worter
public:
    friend
    std::ostream &operator<<(std::ostream &cout, Zaehler const &zaehler);

/***  Konstruktoren  ***/
    Zaehler(std::string const &s)
    {
        _s = s;
        _count = 1;
    }

/***  get-Methoden  ***/
    std::string get_string() const
    {
        return _s;
    }


    size_t get_count() const
    {
        return _count;
    }

/***  set-Methoden  ***/
    void count()
    {
        ++_count;
    }

/***  Interaktionsmethoden, z.B. Vergleiche  ***/
    bool operator>(Zaehler const & zaehler) const
    {
        return get_count() > zaehler.get_count();
    }

    bool operator==(Zaehler const & zaehler) const
    {
        return get_string() == zaehler.get_string();
    }
};
/***  globale Funktionen  ***/
std::ostream &operator<<(std::ostream &cout, Zaehler const &zaehler)
{
    return std::cout << zaehler.get_string();
}


#endif //PA3_ZAEHLER_H
