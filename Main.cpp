/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */

#include <cstddef>  // nullptr_t, ptrdiff_t, size_t
#include <cstdlib>  // abs, div, rand...
#include <iostream> // cin, cout...
#include "Elmt.h"
#include "Sommet.h"
#include "ArbreBinaireOrdonne.h"

int main () {

  
  Elmt<int> s9(6, 425);
  Elmt<int> s91(7, 425);
  Elmt<int> s92(8, 425);
  Elmt<int> s93(9, 425);
  Elmt<int> s(2, 425);
  Elmt<int> s2 = s;
  int a = 13;
  Sommet<Elmt<int>> s3(s);
  ArbreBinaireOrdonne<Elmt<int>> abo(s3);
  if (s2 == s){
    abo.insertion(s9);
  
    //int siz = abo.size_ab();
  	//Elmt<int> *ret = abo.recherche(2);
    abo.affichage();
  }
  return 0;
}
