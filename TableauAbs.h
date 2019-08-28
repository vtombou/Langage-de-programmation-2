/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 * Structure de donnée Tableau abstrait
 */
#ifndef _TABLEAUABS_H
#define _TABLEAUABS_H

#include <string>
#include <cstddef>    // nullptr_t, ptrdiff_t, size_t
#include <ostream>    // output stream

template<typename T>
class TableauAbs
{
	protected:
		//Constructions 
        explicit TableauAbs(std::ptrdiff_t taille):_taille(taille){} ;
        //copie
        TableauAbs(TableauAbs const& tab) noexcept : _taille(tab.get_taille()){}
        //Transfert
        TableauAbs (TableauAbs&& tab) noexcept {
            *this = &tab;
        }

    public:
        //Opérator=
        virtual TableauAbs& operator= (const TableauAbs&)= 0;
        virtual TableauAbs& operator= (TableauAbs& ) = 0;
        //Opérator[]
  		virtual T& operator[] (std::ptrdiff_t index) const noexcept = 0;
        
		//Destruction
        virtual ~TableauAbs() = 0;

};

template<typename T>
TableauAbs<T>::~TableauAbs() = default;

#endif // TABLEAUABS_H