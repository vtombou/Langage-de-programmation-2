/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */
#ifndef _NOEUD_H
#define _NOEUD_H
#include "Sommet.h"

template<typename U>
class Noeud
{
	Sommet<U>* _info; //sommet
	Noeud *_next;
	public:
		//Construction
		explicit Noeud(Sommet<U>* info) :_info(info), _next(nullptr){}
		
		//Destruction
		virtual ~Noeud() = default;
		//copie
		Noeud(const Noeud<U>& elt) noexcept : _info(elt.get_info()), _next(elt.get_next()){} 
		//transfert
		Noeud(const Noeud<U>&& elt) noexcept{
			*this = &elt;
		}

		//Accesseurs
		Sommet<U>* get_info(){ return _info;}
		Noeud* get_next(){ return _next;}
		
		//Mutateurs
		void set_info(Sommet<U>* info){ _info = info;}
		void set_next(Noeud<U>* next){ _next = next;}
};

#endif // NOEUD_H