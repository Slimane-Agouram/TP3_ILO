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
	Complex<T>() // TODO compl�ter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * EComplex<typedid(T).name>[n� d'instance]( val de norm, val de angle)
	 */
}

/*
 * Constructeur de copie d'un Complex d'Euler
 * @param c le complexe dont on doit copier les valeurs
 */
template <class T>
EComplex<T>::EComplex(const Complex<T> & c) :
	Complex<T>(c) // TODO compl�ter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * EComplex<typedid(T).name>[n� d'instance]( val de c )
	 */
}

/*
 * Constructeur de copie d'un Complex cart�sien
 * @param c le complexe dont on doit copier les valeurs
 */
template <class T>
template <class U> EComplex<T>::EComplex(const Complex<U> & c) :
	Complex<T>(c) // TODO compl�ter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * EComplex<typedid(T).name>[n� d'instance]<typeid(U).name>( val de c )
	 */
}

template <class T>
EComplex<T>::~EComplex()
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de ~Complex<T>() :
	 * ~CComplex<typeid(T).name>[n� d'instance]
	 */
}

// ----------------------------------------------------------------------------
// Propri�t�s des nombres complexes
// ----------------------------------------------------------------------------
/*
 * partie r�elle (m�thode abstraite)
 * @return la partie r�elle du nombre complexe
 */
template <class T>
T EComplex<T>::real() const
{
	/*
	 * TODO remplacer par l'impl�mentation
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
	 * TODO remplacer par l'impl�mentation
	 */
	return (T)0;
}

/*
 * Norme du nombre complexe dans le plan complexe  (accesseur en lecture /
 *  �criture)
 * @return une r�f�rence vers le module du nombre dans le plan complexe
 */
template <class T>
T & EComplex<T>::abs()
{
	/*
	 * TODO remplacer par l'impl�mentation
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
	 * TODO remplacer par l'impl�mentation
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
	 * TODO remplacer par l'impl�mentation
	 */
	return 0.0;
}

/*
 * L'angle du nombre dans le plan complexe  (accesseur en
 * lecture/�criture)
 * @return une r�f�rence vers l'angle du nombre dans le plan complexe
 */
template <class T>
double & EComplex<T>::arg()
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	double dummy = 0.0;
	return dummy;
}


/*
 * Calcule un argument � partir d'une partie r�elle
 * et d'une partie imaginaire
 * @param reel une partie r�elle
 * @param imag une partie imaginaire
 * @return l'argument correspondant ces parties r�elles et imaginaires
 */
template <class T>
double EComplex<T>::computeArgument(const T reel, const T imag) const
	throw (Exception)
{
	/*
	 * TODO remplacer par l'impl�mentation
	 * Si impossible de calculer l'argument alors :
	 * 	stringstream message;
	 * 	message << "CComplex<T>::arg() : ind�termin�";
	 * 	message << " sur " << this;
	 * 	throw Exception(message.str());
	 */
	return 0.0;
}

// ----------------------------------------------------------------------------
// Self Operations
// ----------------------------------------------------------------------------
/*
 * Op�rateur d'affectation � partir de n'importe quel complexe
 * @param la r�f�rence d'un autre nombre complexe
 * @return la r�f�rence vers le nouveau nombre complexe
 */
template <class T>
Complex<T> & EComplex<T>::operator =(const Complex<T> & c)
{
	/*
	 * TODO A compl�ter ...
	 */
	return *this;
}

/*
 * Op�rateur d'affectation � partir d'un complexe d'Euler
 * @param c la r�f�rence d'un autre nombre complexe
 * @return la r�f�rence vers le nouveau nombre complexe
 */
template <class T>
Complex<T> & EComplex<T>::operator =(const EComplex<T> & c)
{
	/*
	 * TODO A compl�ter ...
	 */
	return *this;
}

/*
 * Op�rateur de self addition.
 * @param c le complexe � ajouter au complexe courant
 * @return une r�f�rence vers le complexe courant
 * @note Pas de solution miracle ici, il faut recr�er des parties r�elles
 * et imaginaire, puis les additionner puis recalculer une norme et un
 * argument.
 * @throw Exception lorsque l'argument ne peut pas �tre estim� par
 * #computeArgument(r,i)
 */
template <class T>
Complex<T> & EComplex<T>::operator +=(const Complex<T> & c) throw (Exception)
{
	/*
	 * TODO A compl�ter ...
	 */
	return *this;
}

/*
 * Op�rateur de self soustraction.
 * @param c le complexe � soustraire au complexe courant
 * @return une r�f�rence vers le complexe courant
 * @note Pas de solution miracle ici, il faut recr�er des parties r�elles
 * et imaginaire, puis les soustraire puis recalculer une norme et un
 * argument.
 * @throw Exception lorsque l'argument ne peut pas �tre estim� par
 * #computeArgument(r,i)
 */
template <class T>
Complex<T>& EComplex<T>::operator -=(const Complex<T> & c) throw (Exception)
{
	/*
	 * TODO A compl�ter ...
	 */
	return *this;
}

/*
 * Op�rateur de self multiplication.
 * @param c le complexe � multiplier au complexe courant
 * @return une r�f�rence vers le complexe courant
 */
template <class T>
Complex<T>& EComplex<T>::operator *=(const Complex<T> & c)
{
	/*
	 * TODO A compl�ter ...
	 * rho_1 exp i(theta_1) * rho_2 exp i(theta2)
	 * = (rho_1 rho_2) exp i(theta_1+theta_2)
	 */
	return *this;
}

/*
 * Op�rateur de self division.
 * @param c le complexe qui divise le complexe courant
 * @return une r�f�rence vers le complexe courant
 */
template <class T>
Complex<T> & EComplex<T>::operator /=(const Complex<T> & c)
{
	/*
	 * TODO A compl�ter ...
	 * rho_1 exp i(theta_1) / rho_2 exp i(theta2)
	 * = (rho_1/rho_2) exp i(theta_1-theta_2)
	 */
	return *this;
}

// ----------------------------------------------------------------------------
// Operations
// ----------------------------------------------------------------------------
/*
 * Op�rateur d'addition de deux nombres complexes.
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator +(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return EComplex<T>();
}

/*
 * Op�rateur d'addition de deux nombres complexes quelconques
 * (m�thode abstraite)
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un poiteur vers un nouveau nombre complexe r�sultant de
 * l'addition (La classe Complex<T> �tant abstraite, elle ne peut pas
 * avoir d'instances, il faut donc utiliser soit des r�f�rences, soit
 * des pointeurs)
 */
template <class T>
Complex<T> * EComplex<T>::operator +(const Complex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return new EComplex<T>();
}

/*
 * Op�rateur de soustraction de deux nombres complexes
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator -(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return EComplex<T>();
}

/*
 * Op�rateur de soustraction de deux nombres complexes quelconques
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe r�sultant de
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
 * Op�rateur de multiplication de deux nombres complexes
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator *(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return EComplex<T>();
}

/*
 * Op�rateur de multiplication de deux nombres complexes quelconques
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe r�sultant de
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
 * Op�rateur de division de deux nombres complexes
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
EComplex<T> EComplex<T>::operator /(const EComplex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return EComplex<T>();
}

/*
 * Op�rateur de division de deux nombres complexes quelconques
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe r�sultant de
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
 * @return le complexe invers�
 */
template <class T>
EComplex<T> EComplex<T>::inverse() const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 * 1 /(_abs exp i(_arg)) = (1/_abs) exp i(-_arg)
	 */
	return EComplex<T>();
}

/*
 * Complexe conjugu�
 * @return une r�f�rence vers le complexe conjugu�
 */
template <class T>
EComplex<T> EComplex<T>::conjugate() const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 * conjugate(_abs expi(_arg)) = (_abs)expi(-_arg)
	 */
	return EComplex<T>();
	//
}

// ----------------------------------------------------------------------------
// Affichage
// ----------------------------------------------------------------------------
/*
 * Chaine de caract�res repr�sentant l'objet
 * @return une chaine de caract�res repr�sentant le Complexe
 */
template <class T>
string EComplex<T>::toString() const
{
	ostringstream outstring;

	/*
	 * TODO compl�ter outstring par :
	 * ( abs, (arg/M_PI)*180.0� )[n�d'instance]
	 */

	return outstring.str();
}

/*
 * Op�rateur d'entr�e � partir d'une r�f�rence.
 * @pre le Complexe doit d�j� exister et est remplit avec les valeurs
 * lue sur le flux d'entr�e
 * @param in le flux d'entr�e � partir duquel on lit
 * @param c r�f�rence vers le Complexe � remplir
 * @return une r�f�rence vers le flux d'entr�e de mani�re � pouvoir
 * cumuler les op�rateurs
 */
template <class T>
istream & operator >>(istream & in, EComplex<T> & c)
{
	/*
	 * TODO � compl�ter par la lecture de _abs puis de _arg depuis in
	 */

	return in;
}

// ----------------------------------------------------------------------------
// Instanciations et sp�cialisations
// ----------------------------------------------------------------------------
// proto instanciation des templates
template class EComplex<double> ;
template class EComplex<float> ;
template class EComplex<int> ;

// Sp�cialisation des constructeurs de conversion de la classe EComplex pour
// les double, float et int
template <> template <> EComplex<double>::EComplex(const Complex<float> & c) :
	_abs((double) c.abs()), _arg(c.arg())
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * EComplex<double>[n� d'instance]<float>( val de c )
	 */
}
template <> template <> EComplex<double>::EComplex(const Complex<int> & c) :
	_abs((double) c.abs()), _arg(c.arg())
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * EComplex<double>[n� d'instance]<int>( val de c )
	 */
}
template <> template <> EComplex<float>::EComplex(const Complex<int> & c) :
	_abs((float) c.abs()), _arg(c.arg())
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * EComplex<float>[n� d'instance]<int>( val de c )
	 */
}

// instanciation des op�rateurs externes sur les templates protoinstanci�s
template istream & operator >>(istream &, EComplex<double> &);
template istream & operator >>(istream &, EComplex<float> &);
template istream & operator >>(istream &, EComplex<int> &);
