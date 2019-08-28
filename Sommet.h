/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 */
#ifndef _SOMMET_H
#define _SOMMET_H

#include <string>
#include <cstddef>    // nullptr_t, ptrdiff_t, size_t
#include <ostream>    // output stream

template<typename U>
class Sommet
{
	U& _info;
	Sommet *_p, *_fg, *_fd;
	public:
		//Construction
		explicit Sommet(U& info, Sommet *p=nullptr, Sommet *fg=nullptr, Sommet *fd=nullptr ) : _info(info),_p(p), _fg(fg), _fd(fd){}
		
		//Destruction
		virtual ~Sommet() = default;
		//copie
		Sommet(const Sommet& s) noexcept : _info(s.get_info()), _p(s.get_p()), _fg(s.get_fg()), _fd(s.get_fd()){} 
		//transfert
		Sommet(const Sommet&& s) noexcept{
			*this = &s;
		}

		//Accesseurs
		U& get_info(){ return _info;}
		Sommet<U>* get_p(){ return _p;}
		Sommet<U>* get_fg(){ return _fg;}
		Sommet<U>* get_fd(){ return _fd;}

		//Mutateurs
		void set_info(U& info){ _info = info;}
		void set_p(Sommet<U>* p){ _p = p;}
		void set_fg(Sommet<U>* fg){ _fg = fg;}
		void set_fd(Sommet<U>* fd){ _fd = fd;}
};

#endif // SOMMET_H