/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */

#ifndef ARBREBINAIRE_H
#define ARBREBINAIRE_H

#include <queue> //Utiliser pour gerer une file
#include "Arbre.h"
#include "file.h"

template<typename U>
class ArbreBinaire : virtual public Arbre<U>
{
	protected:
		//Constructions
	    explicit ArbreBinaire() noexcept {};
	    //copie
	    ArbreBinaire(const ArbreBinaire& ab) noexcept{
	    	this = &ab;
	    }
		//transfert
		ArbreBinaire(const ArbreBinaire&& ab) noexcept{
	    	*this = &ab;
	    }

    public:
        //Destructeur
        virtual ~ArbreBinaire() = default;
        //affichage de l'arbre
        void affichage(Sommet<U>*) const;
        virtual void affichage() const = 0;
		//nombre d'élément de l'arbre
		int size_ab(Sommet<U>* ) const;
		virtual int size_ab() const = 0;
};

template<typename U>
void ArbreBinaire<U>::affichage(Sommet<U>* s) const{
	std::cout <<"s : " << s << " s-fg : " << s->get_fg() << " s-fd : " << s->get_fd() << std::endl;
	if (s != nullptr)
	{
		ArbreBinaire<U>::affichage(s->get_fg());
		std::cout << s->get_info() << std::endl;
		ArbreBinaire<U>::affichage(s->get_fd());
	}
	return;
}

template<typename U>
int ArbreBinaire<U>::size_ab(Sommet<U>* s) const{
	int cpt = 0;
	File<U> file(s);
	while(!file.filevide()){	
		//on retire l'element qui vient d'etre traiter de la file d'attente
		Sommet<U>* s1 = file.defiler();
		if (s1 != nullptr){
			//on incremente compteur
			cpt++;
			//on fg et fd à la file d'attente.
			file.enfiler(s1->get_fg());
			file.enfiler(s1->get_fd());
		}
	}

	return cpt;
}

#endif // ARBREBINAIRE_H
