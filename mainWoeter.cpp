#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "Liste.h"
#include "Liste.cpp"
#include "Zaehler.h"
#include "Stoppuhr.h"

using namespace std ;

/***
* Zeit Einlesen:      2993.52 s
* Zeit InsertionSort: 23.168 s
* Zeit MergeSort:     0.34 s
 */
int main ( int narg, char* argv[] )
try
{
	// gebe Usage aus
	if ( narg < 2 )
	{
		cout << "Usage: " << argv[ 0 ] << "  dateiName  [anzahl]" << endl ;
		cout << "       dateiName: Name einer ASCII-Datei"		  << endl ;
		cout << "       anzahl   : (optional) natuerliche Zahl"	  << endl ;
		cout << "Zaehlt die in der Datei auftretenden Woerter"	  << endl ;
		cout << "und gibt sie nach absteigender Haeufigkeit aus." << endl ;
		cout << "Wenn anzahl gegeben wird, werden hoechstens"     << endl ;
		cout << "soviele Woerter ausgegeben, sonst alle."		  << endl ;

		return 0 ;
	}

/***  lese Parameter  ***/

	char*    dateiName = argv[ 1 ] ;
	size_t   anzahl    = ( narg >= 3 ? atoi( argv[ 2 ] ) : UINT_MAX ) ;

/***  öffne Datei  ***/

	ifstream datei( dateiName ) ;

	if ( ! datei )
	{
		cerr << "Datei " << dateiName << " kann nicht geoeffnet werden!" << endl ;
		return -1 ;		// melde Fehlerzustand
	}

/***  bearbeite Wörter aus der Datei  ***/

	char const	   SATZZEICHEN[] = ".,:;!?\"\'-" ;
	Liste<Zaehler> woerter ;
	string		   wort ;
	Stoppuhr	   uhr ;

	while ( datei >> wort )
	{
		// lösche alle Satzzeichen
		for ( size_t pos  = wort.find_first_of( SATZZEICHEN ) ;
					 pos != string::npos ;
					 pos  = wort.find_first_of( SATZZEICHEN, pos ) )
			wort.erase( pos, 1 ) ;

		// ignoriere leer gewordene Wörter (die nur Satzzeichen enthielten)
		if ( wort.empty() )
			continue ;

		// mache Anfangs-Großbuchstaben klein
		if ( wort[ 0 ] >= 'A'  &&  wort[ 0 ] <= 'Z' )
			wort[ 0 ] += 'a' - 'A' ;

	/***  zähle wort, wenn in Liste woerter vorhanden;
	      füge wort neu in woerter ein, wenn nicht      ***/

        Zaehler zaehler(wort);
        auto zaehlerIter = woerter.find(zaehler); // suche wort in woerter
        if (zaehlerIter != woerter.end()) // wenn wort in woerter stellt
            zaehlerIter->count(); // +1 count
        else // wenn nicht
            woerter.push_back(zaehler); // setze wort in woerter ein


	}  // while ( datei >> wort )
	datei.close() ;

	cout << "Zeit Einlesen:      " << uhr << endl ;

/***  sortiere Wörter nach absteigender Häufigkeit mit InsertionSort  ***/

	uhr.start() ;
	Liste<Zaehler> sortListe = woerter ;
	cout << "Zeit InsertionSort: " << uhr << endl ;

	// prüfe Korrektheit der Sortierung
	if ( ! sortListe.istSortiert() )
		cout << "Liste wurde nicht korrekt sortiert!" << endl ;

/***  sortiere Wörter nach absteigender Häufigkeit mit MergeSort  ***/

	uhr.start() ;
	woerter.mergeSort() ;
	cout << "Zeit MergeSort:     " << uhr << endl ;

	// prüfe Korrektheit der Sortierung
	if ( ! woerter.istSortiert() )
		cout << "Liste wurde nicht korrekt sortiert!" << endl ;

/***  gebe aufgetretene Wörter aus  ***/

	cout << endl ;
	cout << woerter.size() << " verschiedene Woerter:" << endl ;
	cout << left << endl ;

	for ( Zaehler const& z : woerter )
	{
		// begrenze Ausgabe auf vorgegebene Anzahl
		if ( anzahl-- == 0 )
			break ;

		cout << setw( 15 ) << z << endl ;
	}
	cout << endl ;
	
	return 0 ;

}  // main()

catch ( exception const& exc )
{
	cerr << exc.what() << endl ;
}
catch ( char const* text )
{
	cerr << text << endl ;
}