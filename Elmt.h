/* GNU C++ version 6 - "g++ -std=c++11"
 * Tombou Vincent Aubéric - Aout 2019 - <Main.cpp>
 * Matricule : 000472347
 * Structure de donnée Tableau abstrait
 */
#ifndef ELMT_H
#define ELMT_H

#include <string>
#include <cstddef>    // nullptr_t, ptrdiff_t, size_t
#include <ostream>    // output stream

template<typename T>
class Elmt
{
	std::ptrdiff_t _indice;
	T _valeur;

	public:
		//construction
		explicit Elmt(std::ptrdiff_t indice, T valeur) : _indice(indice), _valeur(valeur) {};
		Elmt(std::ptrdiff_t indice) : _indice(indice), _valeur(T()){};
		//destruction
		virtual ~Elmt() = default;
		//copie
		Elmt(const Elmt&) noexcept;
		//transfert
		Elmt(const Elmt&& s) noexcept{
			*this=&s;
		};
		//operator <
		bool operator< (Elmt const&);

		//operator ==
		bool operator== (Elmt const&);

		//operator =
		Elmt& operator= (const Elmt&) noexcept;
		//operator<<
		template<typename T1>
		friend std::ostream& operator<<(std::ostream& out, const Elmt<T1>& elmt );
		//Affichage standard d'un élément
		void affichage_cout(std::ostream&) const ;
		//Accesseurs
		std::ptrdiff_t get_indice() const{
			return _indice;
		}
		T get_valeur() const{
			return _valeur;
		}
		//Mutateurs
		void set_indice(std::ptrdiff_t indice){
			_indice = indice;
			return;
		}
		void set_valeur(T const& valeur){
			_valeur = valeur;
			return;
		}

};


//copie
template<typename T>
Elmt<T>::Elmt(const Elmt<T>& s) noexcept: _indice(s.get_indice()), _valeur(s.get_valeur()){
};

//operator <
template<typename T>
bool Elmt<T>::operator< (Elmt<T> const& s){
	bool ret = false;
	if (_indice < s.get_indice())
		ret = true;
	return ret;
};

//operator ==
template<typename T>
bool Elmt<T>::operator== (Elmt<T> const& s){
	bool ret = false;
	if (_indice == s.get_indice() && _valeur == s.get_valeur() )
		ret = true;
	return ret;
};

//operator =
template<typename T>
Elmt<T>& Elmt<T>::operator= (const Elmt<T>& elmt) noexcept{
	if(this!=&elmt){
		_indice = elmt.get_indice();
		_valeur = elmt.get_valeur();
	}

	return *this;
};

//Affichage standard
template<typename T>
void Elmt<T>::affichage_cout(std::ostream& out) const{
	out << _indice << "-" << _valeur << std::endl;
} 
//operator<<
template<typename T>
std::ostream& operator<<(std::ostream& out, const Elmt<T>& elmt ){
	 elmt.affichage_cout(out);
	 return out;
};


#endif // ELMT_H




