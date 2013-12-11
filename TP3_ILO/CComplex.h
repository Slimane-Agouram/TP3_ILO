#ifndef CARTESIANCOMPLEX_H_
#define CARTESIANCOMPLEX_H_

#include <iostream>
using namespace std;

#include "Complex.h"

// déclaration préalable pour les futures déclarations amies des opérateurs
template <class T> class CComplex;
template <class T> istream & operator >>(istream & in, CComplex<T> & c);

/**
 * Classe des nombres complexes cartésiens \f$ a + ib\f$
 * avec
 * 	- a la partie réelle
 * 	- b la patrie imaginaire
 * @param T le type des nombres utilisés
 */
template <class T> class CComplex: public Complex<T>
{
	/*
	 * Rappel des membres de Complex<T> que l'on va utiliser ici, sans quoi
	 * il faudra toujours y accéder avec Complex<T>::membre recherché
	 * Ceci est une particularité des templates
	 */
	using Complex<T>::instanceNumber;

	protected:

		/**
		 * La partie réelle du nombre complexe
		 */
		T _real;

		/**
		 * La partie imaginaire du nombre complexe
		 */
		T _imag;

	public:
		// --------------------------------------------------------------------
		// Constructeurs
		// --------------------------------------------------------------------
		/**
		 * Constructeur d'un Complex cartésien
		 * @param r la partie réelle
		 * @param i la partie imaginaire
		 */
		CComplex(const T r = Complex<T>::ZERO, const T i = Complex<T>::ZERO);

		/**
		 * Constructeur de copie d'un complexe
		 * @param c le complexe cartésien dont on doit copier les valeurs
		 */
		CComplex(const Complex<T> & c);

		/**
		 * Constructeur de conversion d'un complexe dont
		 * le paramètre de type n'est pas forcément le même.
		 * @param c le complexe cartésien d'un autre type dont on doit
		 * copier les valeurs
		 * @post les parties réelles et imaginaires de c (de type U)
		 *  sont converties en parties réelles et imaginaires de type T
		 * @note Ce constructeur devra être spécialisé dans les types de
		 * conversions que l'on souhaite :
		 * @code
		 * template <>
		 * template <>
		 * CComplex<double>::CComplex(const Complex<float> & c) : ... { ... }
		 * template <>
		 * template <>
		 * CComplex<double>::CComplex(const Complex<int> & c) : ... { ... }
		 * template <>
		 * template <>
		 * CComplex<float>::CComplex(const Complex<int> & c) : ... { ... }
		 * @endcode
		 */
		template <class U> CComplex(const Complex<U> & c);

		/**
		 * Destructeur d'un complexe cartésien
		 */
		virtual ~CComplex();

		// --------------------------------------------------------------------
		// Propriétés des complexes
		// --------------------------------------------------------------------
		/**
		 * partie réelle (accesseur en lecture)
		 * @return la partie réelle du nombre complexe
		 */
		T real() const;

		/**
		 * partie réelle (accesseur en lecture/écriture)
		 * @return une référence vers la partie réelle du nombre complexe
		 */
		T & real();

		/**
		 * Partie imaginaire (accesseur en lecture)
		 * @return la partie imaginaire du nombre complexe
		 */
		T imag() const;

		/**
		 * Partie imaginaire (accesseur en lecture/écriture)
		 * @return une référence vers la partie imaginaire du nombre complexe
		 */
		T & imag();

		/**
		 * Norme du nombre complexe dans le plan complexe.
		 * \f[
		 * 	\|(a + ib)\| = \sqrt{a^2 + b^2}
		 * \f]
		 * @return la module du nombre dans le plan complexe
		 */
		double abs() const;

		/**
		 * L'angle du nombre dans le plan complexe.
		 * \f{eqnarray*}
		 * 	\theta &=& arctan\left( \frac{b}{a} \right) \rightarrow a > 0\\
		 * &=& arctan\left( \frac{b}{a} \right) \pm \pi \rightarrow a < 0, b \ge 0\\
		 * &=& arctan\left( \frac{b}{a} \right) \pm \pi \rightarrow a < 0, b < 0\\
		 * &=& +\frac{\pi}{2} \rightarrow a = 0, b > 0\\
		 * &=& -\frac{\pi}{2} \rightarrow a = 0, b < 0\\
		 * &=& \mathrm{undefined} \rightarrow a = 0, b = 0\\
		 * \f}
		 * @return l'angle du nombre dans le plan complexe
		 * @throw Exception si l'argument ne peux pas être déterminé du fait
		 * que reel et imag sont nuls.
		 */
		double arg() const throw (Exception);

		// --------------------------------------------------------------------
		// Self Operations (opérations affectant l'instance courante)
		// --------------------------------------------------------------------
		/**
		 * Opérateur d'affectation à partir de n'importe quel complexe
		 * @param c la référence d'un autre nombre complexe
		 * @return la référence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const Complex<T> & c);

		/**
		 * Opérateur d'affectation à partir d'un complexe cartésien
		 * @param c la référence d'un autre nombre complexe
		 * @return la référence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const CComplex<T> & c);

		/**
		 * Opérateur de self addition.
		 * @param c le complexe à ajouter au complexe courant
		 * @return une référence vers le complexe courant
		 */
		Complex<T> & operator +=(const Complex<T> & c);

		/**
		 * Opérateur de self soustraction.
		 * @param c le complexe à soustraire au complexe courant
		 * @return une référence vers le complexe courant
		 */
		Complex<T> & operator -=(const Complex<T> & c);

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
		 * Opérateur d'addition d'un complexe cartésien avec un autre complexe.
		 * \f[(a + ib) + (c + id) = (a+b) + i(c+d)\f]
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de l'addition
		 * @see operator+ (const Complex<T> * c) const
		 */
		CComplex<T> operator +(const CComplex<T> & c) const;

		/**
		 * Opérateur d'addition de deux nombres complexes quelconques
		 * @param c la référence vers un autre nombre complexe
		 * @return un poiteur vers un nouveau nombre complexe résultant de
		 * l'addition (La classe Complex<T> étant abstraite, elle ne peut pas
		 * avoir d'instances, il faut donc utiliser soit des références, soit
		 * des pointeurs)
		 */
		Complex<T> * operator +(const Complex<T> & c) const;

		/**
		 * Opérateur de soustraction d'un complexe cartésien avec un autre complexe.
		 * \f[(a + ib) - (c + id) = (a-b) + i(c-d)\f]
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de la soustraction
		 * @see operator - (const Complex<T> * c) const
		 */
		CComplex<T> operator -(const CComplex<T> & c) const;

		/**
		 * Opérateur de soustraction de deux nombres complexes quelconques
		 * @param c la référence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe résultant de
		 * la soustraction
		 */
		Complex<T> * operator -(const Complex<T> & c) const;

		/**
		 * Opérateur de multiplication d'un complexe cartésien avec un autre complexe.
		 * \f[(a + ib) * (c + id) = (ac-bd) + i(ad+bc)\f]
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de la multiplication
		 * @see operator* (const Complex<T> * c) const
		 */
		CComplex<T> operator *(const CComplex<T> & c) const;

		/**
		 * Opérateur de multiplication de deux nombres complexes quelconques
		 * @param c la référence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe résultant de
		 * la multiplication
		 */
		Complex<T> * operator *(const Complex<T> & c) const;

		/**
		 * Opérateur de division d'un complexe cartésien par un autre complexe.
		 * \f[
		 * 	\frac{(a + ib)}{(c + id)}  =
		 * 	\frac{(a + ib)(c - id)}{(c + id)(c - id)} =
		 * 	\frac{(ac + bd) + i(bc - ad)}{c^2 + d^2} =
		 * 	\left(\frac{ac + bd}{c^2 + d^2}\right)
		 * 	+ i \left(\frac{bc - ad}{c^2 + d^2}\right)
		 * \f]
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de la division
		 */
		CComplex<T> operator /(const CComplex<T> & c) const;

		/**
		 * Opérateur de division de deux nombres complexes quelconques
		 * @param c la référence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe résultant de
		 * la division
		 */
		Complex<T> * operator /(const Complex<T> & c) const;

		/**
		 * Inverse d'un complexe cartésien.
		 * \f[ \frac{1}{a + ib} = \frac{a - ib}{a^2 + b^2} \f]
		 * @return le complexe inversé
		 */
		CComplex<T> inverse() const;

		/**
		 * Complexe conjugué.
		 * \f[ \overline{a + ib} = a - ib \f]
		 * @return une référence vers le complexe conjugué
		 */
		CComplex<T> conjugate() const;

		// --------------------------------------------------------------------
		// Affichage
		// --------------------------------------------------------------------
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
		 * @posst le Complexe est remplit avec les valeurs lue sur le flux
		 * d'entrée
		 */
		friend istream & operator >><>(istream & in, CComplex<T> & c);
};

#endif /*CARTESIANCOMPLEX_H_*/
