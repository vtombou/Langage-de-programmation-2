/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */

#ifndef _VECTEURCREUX_H
#define _VECTEURCREUX_H

#include "TableauAbs.h"
#include "Elmt.h"

template<typename T, typename U>
class VecteurCreux : public TableauAbs<T>, public ArbreBinaireOrdonne<U>{
	int _taille;

	
	public:
		//Construction
		explicit VecteurCreux(int taille) noexcept : TableauAbs<T>(taille), ArbreBinaireOrdonne<U>(){}

		//Override methode
		VecteurCreux& operator= (const TableauAbs& t) override{
			if (this != &t) { //Test d'auto-affectation
				if ( const VecteurCreux*  tab = dynamic_cast<const VecteurCreux*>(&t)){ 
					_taille = tab->get_taille();
				}
			}
		  return *this;
		}
	    VecteurCreux& operator= (TableauAbs& t) override{
	    	if (this != &t) { //Test d'auto-affectation
				if ( const VecteurCreux*  tab = dynamic_cast<const VecteurCreux*>(&t)){ 
					_taille = tab->get_taille();
				}
			}

			return *this;
	    }
	    
	    //Opérator[]
		T& operator[] (std::ptrdiff_t index) const noexcept override{
			
		}
		
		//Accesseur
	    int get_taille() const{
	    	return _taille;
	    }
	    //Mutateur
	    void set_taille(int taille){
	    	_taille = taille;
	    }

}

#endif // VECTEURCREUX_H