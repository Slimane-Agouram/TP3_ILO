#include <cmath>		// pour cos, sin, etc
#include <iostream>		// pour les flux I/O
#include <string>		// pour les string
#include <sstream>		// pour les [i/o]stringstream
#include <typeinfo>		// pour le typeid
using namespace std;

#include "EComplex.h"

// ----------------------------------------------------------------------------
// Constructeurs / Desctructeur
// ----------------------------------------------------------------------------
/*
 * Constructeur d'un Complex d'Euler
 * @param norm la norme du complexe
 * @param l'angle du complexe
 */
template <class T>
EComplex<T>::EComplex(const T norm, const double angle) :
	Complex<T>() // TODO compléter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire à celui de Complex<T>(c) :
	 * EComplex<typedid(T).name>[n° d'instance]( val de norm, val de angle)
	 */
}

/*
 * Constructeur de copie d'un Complex d'Euler
 * @param c le complexe dont on doit copier les valeurs
 */
template <class T>
EComplex<T>::EComplex(const Complex<T> & c) :
	Complex<T>(c) // TODO compléter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire à celui de Complex<T>(c) :
	 * EComplex<typedid(T).name>[n° d'instance]( val de c )
	 */
}

/*
 * Constructeur de copie d'un Complex cartésien
 * @param c le complexe dont on doit copier les valeurs
 */
template <class T>
template <class U> EComplex<T>::EComplex(const Complex<U> & c) :
	Complex<T>(c) // TODO compléter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire à celui de Complex<T>(c) :
	 * EComplex<typedid(T).name>[n° d'instance]<typeid(U).name>( val de c )
	 */
}

template <class T>
EComplex<T>::~EComplex()
{
	/*
	 * TODO Envoyer dans clog un message similaire à celui de ~Complex<T>() :
	 * ~CComplex<typeid(T).name>[n° d'instance]
	 */
}

// ----------------------------------------------------------------------------
// Propriétés des nombres complexes
// ----------------------------------------------------------------------------
/*
 * partie réelle (méthode abstraite)
 * @return la partie réelle du nombre complexe
 */
template <class T>
T EComplex<T>::real() const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return (T)0;
}

/*
 * Partie imaginaire (accesseur en lecture seule)
 * @return la partie imaginaire du nombre complexe
 */
template <class T>
T EComplex<T>::imag() const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return (T)0;
}

/*
 * Norme du nombre complexe dans le plan complexe  (accesseur en lecture /
 *  écriture)
 * @return une référence vers le module du nombre dans le plan complexe
 */
template <class T>
T & EComplex<T>::abs()
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	T dummy = (T)0;
	return dummy;
}

/*
 * Norme du nombre complexe dans le plan complexe  (accesseur en lecture
 * seule)
 * @return le module du nombre dans le plan complexe
 */
template <class T>
double EComplex<T>::abs() const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return 0.0;
}

/*
 * L'angle du nombre dans le plan complexe  (accesseur en lecture seule)
 * @return l'angle du nombre dans le plan complexe
 */
template <class T>
double EComplex<T>::arg() const throw (Exception)
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return 0.0;
}

/*
 * L'angle du nombre dans le plan complexe  (accesseur en
 * lecture/écriture)
 * @return une référence vers l'angle du nombre dans le plan complexe
 */
template <class T>
double & EComplex<T>::arg()
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	double dummy = 0.0;
	return dummy;
}


/*
 * Calcule un argument à partir d'une partie réelle
 * et d'une partie imaginaire
 * @param reel une partie réelle
 * @param imag une partie imaginaire
 * @return l'argument correspondant ces parties réelles et imaginaires
 */
template <class T>
double EComplex<T>::computeArgument(const T reel, const T imag) const
	throw (Exception)
{
	/*
	 * TODO remplacer par l'implémentation
	 * Si impossible de calculer l'argument alors :
	 * 	stringstream message;
	 * 	message << "CComplex<T>::arg() : indéterminé";
	 * 	message << " sur " << this;
	 * 	throw Exception(message.str());
	 */
	return 0.0;
}

// ----------------------------------------------------------------------------
// Self Operations
// ----------------------------------------------------------------------------
/*
 * Opérateur d'affectation à partir de n'importe quel complexe
 * @param la référence d'un autre nombre complexe
 * @return la référence vers le nouveau nombre complexe
 */
template <class T>
Complex<T> & EComplex<T>::operator =(const Complex<T> & c)
{
	/*
	 * TODO A compléter ...
	 */
	return *this;
}

/*
 * Opérateur d'affectation à partir d'un complexe d'Euler
 * @param c la référence d'un autre nombre complexe
 * @return la référence vers le nouveau nombre complexe
 */
template <class T>
Complex<T> & EComplex<T>::operator =(const EComplex<T> & c)
{
	/*
	 * TODO A compléter ...
	 */
	return *this;
}

/*
 * Opérateur de self addition.
 * @param c le complexe à ajouter au complexe courant
 * @return une référence vers le complexe courant
 * @note Pas de solution miracle ici, il faut recréer des parties réelles
 * et imaginaire, puis les additionner puis recalculer une norme et un
 * argument.
 * @throw Exception lorsque l'argument ne peut pas être estimé par
 * #computeArgument(r,i)
 */
template <class T>
Complex<T> & EComplex<T>::operator +=(const Complex<T> & c) throw (Exception)
{
	/*
	 * TODO A compléter ...
	 */
	return *this;
}

/*
 * Opérateur de self soustraction.
 * @param c le complexe à soustraire au complexe courant
 * @return une référence vers le complexe courant
 * @note Pas de solution miracle ici, il faut recréer des parties réelles
 * et imaginaire, puis les soustraire puis recalculer une norme et un
 * argument.
 * @throw Exception lorsque l'argument ne peut pas être estimé par
 * #computeArgument(r,i)
 */
template <class T>
Complex<T>& EComplex<T>::operator -=(const Complex<T> & c) throw (Exception)
{
	/*
	 * TODO A compléter ...
	 */
	return *this;
}

/*
 * Opérateur de self multiplication.
 * @param c le complexe à multiplier au complexe courant
 * @return une référence vers le complexe courant
 */
template <class T>
Complex<T>& EComplex<T>::operator *=(const Complex<T> & c)
{
	/*
	 * TODO A compléter ...
	 * rho_1 exp i(theta_1) * rho_2 exp i(theta2)
	 * = (rho_1 rho_2) exp i(theta_1+theta_2)
	 */
	return *this;
}

/*
 * Opérateur de self division.
 * @param c le complexe qui divise le complexe courant
 * @return une référence vers le complexe courant
 */
template <class T>
Complex<T> & EComplex<T>::operator /=(const Complex<T> & c)
{
	/*
	 * TODO A compléter ...
	 * rho_1 exp i(theta_1) / rho_2 exp i(theta2)
	 * = (rho_1/rho_2) exp i(theta_1-theta_2)
	 */
	return *this;
}

// ----------------------------------------------------------------------------
// Operations
// ----------------------------------------------------------------------------
/*
 * Opérateur d'addition de deux nombres complexes.
 * @param la référence vers un autre nombre complexe
 * @return un nouveau nombre complexe résultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator +(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return EComplex<T>();
}

/*
 * Opérateur d'addition de deux nombres complexes quelconques
 * (méthode abstraite)
 * @param c la référence vers un autre nombre complexe
 * @return un poiteur vers un nouveau nombre complexe résultant de
 * l'addition (La classe Complex<T> étant abstraite, elle ne peut pas
 * avoir d'instances, il faut donc utiliser soit des références, soit
 * des pointeurs)
 */
template <class T>
Complex<T> * EComplex<T>::operator +(const Complex<T> & c) const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return new EComplex<T>();
}

/*
 * Opérateur de soustraction de deux nombres complexes
 * @param la référence vers un autre nombre complexe
 * @return un nouveau nombre complexe résultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator -(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return EComplex<T>();
}

/*
 * Opérateur de soustraction de deux nombres complexes quelconques
 * @param c la référence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe résultant de
 * la soustraction
 */
template <class T>
Complex<T> * EComplex<T>::operator -(const Complex<T> & c) const
{
	EComplex<T> * newComplex = new EComplex<T>(*this);

	newComplex->operator -=(c);

	return newComplex;
}

/*
 * Opérateur de multiplication de deux nombres complexes
 * @param la référence vers un autre nombre complexe
 * @return un nouveau nombre complexe résultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator *(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return EComplex<T>();
}

/*
 * Opérateur de multiplication de deux nombres complexes quelconques
 * @param c la référence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe résultant de
 * la multiplication
 */
template <class T>
Complex<T> * EComplex<T>::operator *(const Complex<T> & c) const
{
	EComplex<T> * newComplex = new EComplex<T>(*this);

	newComplex->operator *=(c);

	return newComplex;
}

/*
 * Opérateur de division de deux nombres complexes
 * @param la référence vers un autre nombre complexe
 * @return un nouveau nombre complexe résultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator /(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return EComplex<T>();
}

/*
 * Opérateur de division de deux nombres complexes quelconques
 * @param c la référence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe résultant de
 * la division
 */
template <class T>
Complex<T> * EComplex<T>::operator /(const Complex<T> & c) const
{
	EComplex<T> * newComplex = new EComplex<T>(*this);

	newComplex->operator /=(c);

	return newComplex;
}

/*
 * Inverse d'un complexe
 * @return le complexe inversé
 */
template <class T>
EComplex<T> EComplex<T>::inverse() const
{
	/*
	 * TODO remplacer par l'implémentation
	 * 1 /(_abs exp i(_arg)) = (1/_abs) exp i(-_arg)
	 */
	return EComplex<T>();
}

/*
 * Complexe conjugué
 * @return une référence vers le complexe conjugué
 */
template <class T>
EComplex<T> EComplex<T>::conjugate() const
{
	/*
	 * TODO remplacer par l'implémentation
	 * conjugate(_abs expi(_arg)) = (_abs)expi(-_arg)
	 */
	return EComplex<T>();
	//
}

// ----------------------------------------------------------------------------
// Affichage
// ----------------------------------------------------------------------------
/*
 * Chaine de caractères représentant l'objet
 * @return une chaine de caractères représentant le Complexe
 */
template <class T>
string EComplex<T>::toString() const
{
	ostringstream outstring;

	/*
	 * TODO compléter outstring par :
	 * ( abs, (arg/M_PI)*180.0° )[n°d'instance]
	 */

	return outstring.str();
}

/*
 * Opérateur d'entrée à partir d'une référence.
 * @pre le Complexe doit déjà exister et est remplit avec les valeurs
 * lue sur le flux d'entrée
 * @param in le flux d'entrée à partir duquel on lit
 * @param c référence vers le Complexe à remplir
 * @return une référence vers le flux d'entrée de manière à pouvoir
 * cumuler les opérateurs
 */
template <class T>
istream & operator >>(istream & in, EComplex<T> & c)
{
	/*
	 * TODO à compléter par la lecture de _abs puis de _arg depuis in
	 */

	return in;
}

// ----------------------------------------------------------------------------
// Instanciations et spécialisations
// ----------------------------------------------------------------------------
// proto instanciation des templates
template class EComplex<double> ;
template class EComplex<float> ;
template class EComplex<int> ;

// Spécialisation des constructeurs de conversion de la classe EComplex pour
// les double, float et int
template <> template <> EComplex<double>::EComplex(const Complex<float> & c) :
	_abs((double) c.abs()), _arg(c.arg())
{
	/*
	 * TODO Envoyer dans clog un message similaire à celui de Complex<T>(c) :
	 * EComplex<double>[n° d'instance]<float>( val de c )
	 */
}
template <> template <> EComplex<double>::EComplex(const Complex<int> & c) :
	_abs((double) c.abs()), _arg(c.arg())
{
	/*
	 * TODO Envoyer dans clog un message similaire à celui de Complex<T>(c) :
	 * EComplex<double>[n° d'instance]<int>( val de c )
	 */
}
template <> template <> EComplex<float>::EComplex(const Complex<int> & c) :
	_abs((float) c.abs()), _arg(c.arg())
{
	/*
	 * TODO Envoyer dans clog un message similaire à celui de Complex<T>(c) :
	 * EComplex<float>[n° d'instance]<int>( val de c )
	 */
}

// instanciation des opérateurs externes sur les templates protoinstanciés
template istream & operator >>(istream &, EComplex<double> &);
template istream & operator >>(istream &, EComplex<float> &);
template istream & operator >>(istream &, EComplex<int> &);
