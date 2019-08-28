/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */

#ifndef ARBREORDONNE_H
#define ARBREORDONNE_H

#include "Arbre.h"


template<typename U>
class ArbreOrdonne : virtual public Arbre<U>
{
	protected:
		//Constructions
	    explicit ArbreOrdonne() noexcept {};
	    //copie
	    ArbreOrdonne(const ArbreOrdonne& ab) noexcept{
	    	this = &ab;
	    }
		//transfert
		ArbreOrdonne(const ArbreOrdonne&& ab) noexcept{
	    	*this = &ab;
	    }

    public:
        //Destructeur
        virtual ~ArbreOrdonne() = default;
        //Inserrer un nouvel élément dans l'arbre
        virtual bool insertion(U& ) const = 0;
		bool insertion(Sommet<U>*, U& ) const;

		/*
		virtual bool suppression(U& ) = 0;
		void suppression(Sommet<U>*, U& );
		void transplant(Sommet<U>*, Sommet<U>&, Sommet<U>& );*/
};

template<typename U>
bool ArbreOrdonne<U>::insertion(Sommet<U>* s, U& elmt) const{
	Sommet<U>* s1 = nullptr;
	Sommet<U>* s2 = s;
	//on cherche la position de elmt dans notre arbre
	while(s2){
		s1=s2;
		if(elmt < s2->get_info() ){
			s2 = s2->get_fg();
		}else{
			s2 = s2->get_fd();
		}
	}//s1 contient l'adresse du parent de elmt
	
	//on cree un sommet avec elmt et s1 comme parent
	Sommet<U> s_elmt(elmt, s1);
	//on recherche la position de s_elmt par rapport à son parent
	if(!s1){
		s = &s_elmt;
	}
	else if(s_elmt.get_info() < s1->get_info() ){
		s1->set_fg(&s_elmt);
	}
	else{ 
		s1->set_fd(&s_elmt);
	}
	return true;
}
/*
template<typename U>
void ArbreOrdonne<U>::transplant(Sommet<U>* s, Sommet<U>& u, Sommet<U>& v){
	if (!u.get_p())
	{
		s = &v;
	}else if( &u == u.get_p().get_fd() ){
		u.get_p()->set_fg(&v);
	}else{
		u.get_p()->set_fd(&v);
	}

	if (v){
		v.get_p()->set_p(u.get_p());
	}

}

template<typename U>
void ArbreOrdonne<U>::suppression(Sommet<U>* s, Sommet<U>& elmt){
	if (!elmt.get_fg()){
		ArbreOrdonne<U>::transplant(s, elmt, elmt.get_fd());
	}else if (!elmt.get_fd()){
		ArbreOrdonne<U>::transplant(s, elmt, elmt.get_fg());
	}else{

	}
}*/

#endif // ARBREORDONNE_H