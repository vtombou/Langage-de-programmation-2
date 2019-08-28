/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */

#ifndef ARBREBINAIRERECHERCHE_H
#define ARBREBINAIRERECHERCHE_H

#include <string>
#include <cstddef>    // nullptr_t, ptrdiff_t, size_t
#include <ostream>    // output stream
#include "ArbreBinaire.h"
#include "ArbreOrdonne.h"

template<typename U>
class ArbreBinaireRecherche : public ArbreOrdonne<U>, public ArbreBinaire<U>
{
	protected:
		//Constructions
	    explicit ArbreBinaireRecherche() noexcept: Arbre<U>(), ArbreOrdonne<U>(), ArbreBinaire<U>(){};
	    //copie
	    ArbreBinaireRecherche(ArbreBinaireRecherche& ab) noexcept{
	    	this = &ab;
	    }
		//transfert
		ArbreBinaireRecherche(ArbreBinaireRecherche&& ab) noexcept{
	    	*this = &ab;
	    }

    public:
        //Destructeur
        virtual ~ArbreBinaireRecherche() = default;
        //affichage de l'arbre
        U* recherche(Sommet<U>*, U& ) const;
        virtual U* recherche(std::ptrdiff_t ) const = 0;
};

template<typename U>
U* ArbreBinaireRecherche<U>::recherche(Sommet<U>* s, U& elmt) const{ 
	Sommet<U>* it = s;
	
	while( (it!= nullptr) and !(elmt == s->get_info())){
		std::cout << "in" << std::endl;
		if( it->get_info() < elmt){
			it = it->get_fg();
		}else{
			it = it->get_fg();
		}
	}
	if(it != nullptr){
		return &it->get_info();
	}
	
	delete it;
	return nullptr;
}

#endif // ARBREBINAIRERECHERCHE_H