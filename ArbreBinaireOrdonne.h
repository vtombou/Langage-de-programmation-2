/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */

#ifndef ARBREBINAIREORDONNE_H
#define ARBREBINAIREORDONNE_H


#include <string>
#include <cstddef>    // nullptr_t, ptrdiff_t, size_t
#include <ostream>    // output stream
#include "ArbreBinaireRecherche.h"
#include "Sommet.h"

template<typename U>
class ArbreBinaireOrdonne : public ArbreBinaireRecherche<U>
{
	Sommet<U>* _racine;

	public:
		//Constructions
	    ArbreBinaireOrdonne() noexcept : ArbreBinaireRecherche<U>(), _racine(nullptr) {};
	    ArbreBinaireOrdonne(Sommet<U>& s ) noexcept : ArbreBinaireRecherche<U>(), _racine(&s) {};
	    //copie
	    ArbreBinaireOrdonne(ArbreBinaireOrdonne& abo) noexcept{
	    	this = &abo;
	    }
		//transfert
		ArbreBinaireOrdonne(ArbreBinaireOrdonne&& abo)noexcept{
	    	*this = &abo;
	    }

        //Destructeur
        virtual ~ArbreBinaireOrdonne() = default;

        //mutateur
        void set_racine(Sommet<U>* s){
        	_racine = s;
        	return;
        }
        //accesseur
        Sommet<U>* get_racine() const{
        	return _racine;
        }

        
        bool isEmpty() const override;
        using Arbre<U>::isEmpty;
        void affichage() const override;
        using ArbreBinaire<U>::affichage;
        int size_ab() const override;
        using ArbreBinaire<U>::size_ab;
        bool insertion(U& ) const override;
        using ArbreOrdonne<U>::insertion;
        U* recherche(std::ptrdiff_t ) const override;
        using ArbreBinaireRecherche<U>::recherche;
};

//détermine si un arbre est vide
template<typename U>
bool ArbreBinaireOrdonne<U>::isEmpty() const{
	return isEmpty(_racine);
};

//affichage d'un arbre binaire ordonnée
template<typename U>
void ArbreBinaireOrdonne<U>::affichage() const{
	affichage(_racine);
}

template<typename U>
int ArbreBinaireOrdonne<U>::size_ab() const{
	return size_ab(_racine);

}

template<typename U>
bool ArbreBinaireOrdonne<U>::insertion(U& elmt) const{
	return insertion(_racine, elmt);
}

template<typename U>
U* ArbreBinaireOrdonne<U>::recherche(std::ptrdiff_t indice) const{
    Sommet<U> *racine = _racine;
    U elmt(indice);
    
    return recherche(racine, elmt);
}



#endif // ARBREBINAIREORDONNE_H
