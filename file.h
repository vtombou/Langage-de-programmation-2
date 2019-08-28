/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */
#ifndef _FILE_H
#define _FILE_H

#include <string>
#include <cstddef>    // nullptr_t, ptrdiff_t, size_t
#include <ostream>    // output stream
#include "Noeud.h"

template<typename U>
class File
{
	Noeud<U> *_tete;
	public:
		//Construction
		explicit File(Sommet<U>* s){
			Noeud<U> tete(s);
			_tete = &tete;
		}
		
		//Destruction
		virtual ~File() = default;
		//copie
		File(const File& f) noexcept : _tete(f.get_tete()){} 
		//transfert
		File(const File&& f) noexcept{
			*this = &f;
		}

		//Accesseurs
		File<U>* get_tete(){ return _tete;}
		
		//Mutateurs
		void set_info(File<U>* tete){ _tete = tete;}

		//methodes
		void enfiler(Sommet<U>* s);
		Sommet<U>* defiler();
		bool filevide();
};


template<typename U> 	//U = sommet<U>
void File<U>::enfiler(Sommet<U>* s){
	Noeud<U> tete(s);
	if(_tete == nullptr){
		_tete = &tete;
	}else{
		Noeud<U>* it = _tete;
		while(it->get_next()){
			it = it->get_next(); 
		}  
		it->set_next(&tete);
	}
	return;
}

template<typename U>
Sommet<U>* File<U>::defiler(){
	if(!filevide()){
		Noeud<U>* x = _tete;
		_tete = _tete->get_next();
		Sommet<U>* ret = _tete->get_info();
		delete(x);

		return ret;
	}

	return nullptr;
}

template<typename U>
bool File<U>::filevide(){
	bool ret = false;
	if(_tete == nullptr)
		ret = true;
	return ret;
}


#endif // FILE_H




