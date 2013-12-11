#ifndef ECOMPLEX_H_
#define ECOMPLEX_H_

#include <iostream>
using namespace std;

#include "Complex.h"

// déclaration préalable pour les futures déclarations amies des opérateurs
template <class T> class EComplex;
template <class T> istream & operator >>(istream & in, EComplex<T> & c);

/**
 * Classe des nombres complexes d'Euler \f$ \_abs e^{i\_arg}\f$
 * avec
 * 	- \f$ \rho \f$ la norme du nombre complexe
 * 	- \f$ \_arg \f$ l'argument du nombre complexe (son angle)
 * @param T le type des nombres utilisés pour la module
 */
template <class T> class EComplex: public Complex<T>
{
	/*
	 * Rappel des membres de Complex<T> que l'on va utiliser ici, sans quoi
	 * il faudra toujours y accéder avec Complex<T>::membre recherché.
	 * Ceci est une particularité des templates
	 */
	using Complex<T>::instanceNumber;

	protected:
		/**
		 * Le module du nombre complexe
		 */
		T _abs;

		/**
		 * L'argument du nombre complexe
		 */
		double _arg;

		/**
		 * Calcule un argument à partir d'une partie réelle
		 * et d'une partie imaginaire
		 * @param reel une partie réelle
		 * @param imag une partie imaginaire
		 * @return l'argument correspondant ces parties réelles et imaginaires
		 * @throw Exception si l'argument  ne peux pas être déterminé du fait
		 * que reel et imag sont nuls.
		 */
		double computeArgument(const T reel, const T imag) const throw (Exception);

	public:
		// --------------------------------------------------------------------
		// Constructeurs
		// --------------------------------------------------------------------
		/**
		 * Constructeur d'un Complex d'Euler
		 * @param norm la module du complex
		 * @param angle l'angle du complex
		 */
		EComplex(const T norm = Complex<T>::ZERO, const double angle =
			Complex<T>::ZERO);

		/**
		 * Constructeur de copie d'un Complex d'Euler
		 * @param c le complexe dont on doit copier les valeurs
		 */
		EComplex(const Complex<T> & c);

		/**
		 * Constructeur de conversion d'un complexe dont le
		 * paramètre de type n'est pas forcément le même
		 * @param c le complexe dont on doit copier les valeurs
		 * @post la norme et l'argument du complexe à copier (de type U)
		 * sont converties dans le type T
		 */
		template <class U> EComplex(const Complex<U> & c);

		/**
		 * Destructeur d'un complexe d'Euler
		 */
		virtual ~EComplex();

		// --------------------------------------------------------------------
		// Propriétés des complexes
		// --------------------------------------------------------------------
		/**
		 * partie réelle.
		 * \f[
		 * x = \_abs cos(\_arg)
		 * \f]
		 * @return la partie réelle du nombre complexe
		 */
		T real() const;

		/**
		 * Partie imaginaire.
		 * \f[
		 * y = \_abs sin(\_arg)
		 * \f]
		 * @return la partie imaginaire du nombre complexe
		 */
		T imag() const;

		/**
		 * Norme du nombre complexe dans le plan complexe  (accesseur en lecture
		 * seule)
		 * @return le module du nombre dans le plan complexe
		 */
		double abs() const;

		/**
		 * Norme du nombre complexe dans le plan complexe  (accesseur en lecture
		 * seule)
		 * @return une référence vers le module du nombre dans le plan complexe
		 */
		T & abs();

		/**
		 * L'angle du nombre dans le plan complexe  (accesseur en lecture seule)
		 * @return l'angle du nombre dans le plan complexe
		 * @throw Une Exception lorsque l'argument ne peu pas être déterminé
		 * car les parties réelles et imaginaires sont nulles
		 */
		double arg() const throw (Exception);

		/**
		 * L'angle du nombre dans le plan complexe  (accesseur en
		 * lecture/écriture)
		 * @return une référence vers l'angle du nombre dans le plan complexe
		 */
		double & arg();

		// --------------------------------------------------------------------
		// Self Operations (opérations affectant l'instance courante)
		// --------------------------------------------------------------------
		/**
		 * Opérateur d'affectation
		 * @param c la référence d'un autre nombre complexe
		 * @return la référence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const Complex<T> & c);

		/**
		 * Opérateur d'affectation à partir d'un complexe d'Euler
		 * @param c la référence d'un autre nombre complexe
		 * @return la référence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const EComplex<T> & c);

		/**
		 * Opérateur de self addition.
		 * @param c le complexe à ajouter au complexe courant
		 * @return une référence vers le complexe courant
		 * @note Pas de solution miracle ici, il faut recréer des parties réelles
		 * et imaginaire, puis les additionner puis recalculer une norme et un
		 * argument.
		 * @throw Exception lorsque l'argument ne peut pas être estimé par
		 * #computeArgument(r,i)
		 */
		Complex<T> & operator +=(const Complex<T> & c) throw (Exception);

		/**
		 * Opérateur de self soustraction.
		 * @param c le complexe à soustraire au complexe courant
		 * @return une référence vers le complexe courant
		 * @note Pas de solution miracle ici, il faut recréer des parties réelles
		 * et imaginaire, puis les soustraire puis recalculer une norme et un
		 * argument.
		 * @throw Exception lorsque l'argument ne peut pas être estimé par
		 * #computeArgument(r,i)
		 */
		Complex<T> & operator -=(const Complex<T> & c) throw (Exception);

		/**
		 * Opérateur de self multiplication.
		 * @param c le complexe à multiplier au complexe courant
		 * @return une référence vers le complexe courant
		 */
		Complex<T> & operator *=(const Complex<T> & c);

		/**
		 * Opérateur de self division.
		 * @param c le complexe qui divise le complexe courant
		 * @return une référence vers le complexe courant
		 */
		Complex<T>& operator /=(const Complex<T> & c);

		// --------------------------------------------------------------------
		// Opérations (opérations créant un résultat)
		// --------------------------------------------------------------------
		/**
		 * Opérateur d'addition de deux nombres complexes.
		 * On utilise pour ce faire la conversion en polaire / cartésien
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de l'addition
		 */
		EComplex<T> operator +(const EComplex<T> & c) const;

		/**
		 * Opérateur d'addition de deux nombres complexes quelconques
		 * (méthode abstraite)
		 * @param c la référence vers un autre nombre complexe
		 * @return un poiteur vers un nouveau nombre complexe résultant de
		 * l'addition (La classe Complex<T> étant abstraite, elle ne peut pas
		 * avoir d'instances, il faut donc utiliser soit des références, soit
		 * des pointeurs)
		 */
		Complex<T> * operator +(const Complex<T> & c) const;

		/**
		 * Opérateur de soustraction de deux nombres complexes
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de l'addition
		 */
		EComplex<T> operator -(const EComplex<T> & c) const;

		/**
		 * Opérateur de soustraction de deux nombres complexes quelconques
		 * @param c la référence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe résultant de
		 * la soustraction
		 */
		Complex<T> * operator -(const Complex<T> & c) const;

		/**
		 * Opérateur de multiplication de deux nombres complexes
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de l'addition
		 */
		EComplex<T> operator *(const EComplex<T> & c) const;

		/**
		 * Opérateur de multiplication de deux nombres complexes quelconques
		 * @param c la référence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe résultant de
		 * la multiplication
		 */
		Complex<T> * operator *(const Complex<T> & c) const;

		/**
		 * Opérateur de division de deux nombres complexes
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de l'addition
		 */
		EComplex<T> operator /(const EComplex<T> & c) const;

		/**
		 * Opérateur de division de deux nombres complexes quelconques
		 * @param c la référence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe résultant de
		 * la division
		 */
		Complex<T> * operator /(const Complex<T> & c) const;

		/**
		 * Inverse d'un complexe
		 * @return le complexe inversé
		 */
		EComplex<T> inverse() const;

		/**
		 * Complexe conjugué
		 * @return une référence vers le complexe conjugué
		 */
		EComplex<T> conjugate() const;

		/**
		 * Chaine de caractères représentant l'objet
		 * @return une chaine de caractères représentant le Complexe
		 */
		string toString() const;

		/**
		 * Opérateur d'entrée à partir d'une référence.
		 * @pre le Complexe doit déjà exister
		 * @param in le flux d'entrée à partir duquel on lit
		 * @param c référence vers le Complexe à remplir
		 * @return une référence vers le flux d'entrée de manière à pouvoir
		 * cumuler les opérateurs
		 * @post le Complexe est remplit avec les valeurs
		 * lue sur le flux d'entrée
		 */
		friend istream & operator >><>(istream & in, EComplex<T> & c);
};

#endif /*ECOMPLEX_H_*/
