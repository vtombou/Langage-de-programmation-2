/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */
#ifndef ARBRE_H
#define ARBRE_H

#include "Sommet.h"

template<typename U>
class Arbre
{
	protected:
		//Construction
	    Arbre(){};
	    //copie
	    Arbre(const Arbre<U>& a) noexcept{
	    	this = &a;
	    }
		//transfert
		Arbre(const Arbre<U>&& a) noexcept{
			*this=&a;
		};

	public:    
	    //Destructeur
	    virtual ~Arbre() noexcept = 0;
				
		/**
		* Retourne true, si l'arbre est vide
		**/
		bool isEmpty(Sommet<U>*) const;
		virtual bool isEmpty() const = 0;
};

//Destructeur de la classe
template<typename U>
Arbre<U>::~Arbre() noexcept = default;

//détermine si un arbre est vide
template<typename U>
bool Arbre<U>::isEmpty(Sommet<U>* s) const{
	if( s)
		return true;
	return false;
}

#endif // ARBRE_H