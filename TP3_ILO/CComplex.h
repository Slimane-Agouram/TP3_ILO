#ifndef CARTESIANCOMPLEX_H_
#define CARTESIANCOMPLEX_H_

#include <iostream>
using namespace std;

#include "Complex.h"

// d�claration pr�alable pour les futures d�clarations amies des op�rateurs
template <class T> class CComplex;
template <class T> istream & operator >>(istream & in, CComplex<T> & c);

/**
 * Classe des nombres complexes cart�siens \f$ a + ib\f$
 * avec
 * 	- a la partie r�elle
 * 	- b la patrie imaginaire
 * @param T le type des nombres utilis�s
 */
template <class T> class CComplex: public Complex<T>
{
	/*
	 * Rappel des membres de Complex<T> que l'on va utiliser ici, sans quoi
	 * il faudra toujours y acc�der avec Complex<T>::membre recherch�
	 * Ceci est une particularit� des templates
	 */
	using Complex<T>::instanceNumber;

	protected:

		/**
		 * La partie r�elle du nombre complexe
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
		 * Constructeur d'un Complex cart�sien
		 * @param r la partie r�elle
		 * @param i la partie imaginaire
		 */
		CComplex(const T r = Complex<T>::ZERO, const T i = Complex<T>::ZERO);

		/**
		 * Constructeur de copie d'un complexe
		 * @param c le complexe cart�sien dont on doit copier les valeurs
		 */
		CComplex(const Complex<T> & c);

		/**
		 * Constructeur de conversion d'un complexe dont
		 * le param�tre de type n'est pas forc�ment le m�me.
		 * @param c le complexe cart�sien d'un autre type dont on doit
		 * copier les valeurs
		 * @post les parties r�elles et imaginaires de c (de type U)
		 *  sont converties en parties r�elles et imaginaires de type T
		 * @note Ce constructeur devra �tre sp�cialis� dans les types de
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
		 * Destructeur d'un complexe cart�sien
		 */
		virtual ~CComplex();

		// --------------------------------------------------------------------
		// Propri�t�s des complexes
		// --------------------------------------------------------------------
		/**
		 * partie r�elle (accesseur en lecture)
		 * @return la partie r�elle du nombre complexe
		 */
		T real() const;

		/**
		 * partie r�elle (accesseur en lecture/�criture)
		 * @return une r�f�rence vers la partie r�elle du nombre complexe
		 */
		T & real();

		/**
		 * Partie imaginaire (accesseur en lecture)
		 * @return la partie imaginaire du nombre complexe
		 */
		T imag() const;

		/**
		 * Partie imaginaire (accesseur en lecture/�criture)
		 * @return une r�f�rence vers la partie imaginaire du nombre complexe
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
		 * @throw Exception si l'argument ne peux pas �tre d�termin� du fait
		 * que reel et imag sont nuls.
		 */
		double arg() const throw (Exception);

		// --------------------------------------------------------------------
		// Self Operations (op�rations affectant l'instance courante)
		// --------------------------------------------------------------------
		/**
		 * Op�rateur d'affectation � partir de n'importe quel complexe
		 * @param c la r�f�rence d'un autre nombre complexe
		 * @return la r�f�rence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const Complex<T> & c);

		/**
		 * Op�rateur d'affectation � partir d'un complexe cart�sien
		 * @param c la r�f�rence d'un autre nombre complexe
		 * @return la r�f�rence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const CComplex<T> & c);

		/**
		 * Op�rateur de self addition.
		 * @param c le complexe � ajouter au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		Complex<T> & operator +=(const Complex<T> & c);

		/**
		 * Op�rateur de self soustraction.
		 * @param c le complexe � soustraire au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		Complex<T> & operator -=(const Complex<T> & c);

		/**
		 * Op�rateur de self multiplication.
		 * @param c le complexe � multiplier au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		Complex<T> & operator *=(const Complex<T> & c);

		/**
		 * Op�rateur de self division.
		 * @param c le complexe qui divise le complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		Complex<T>& operator /=(const Complex<T> & c);

		// --------------------------------------------------------------------
		// Op�rations (op�rations cr�ant un r�sultat)
		// --------------------------------------------------------------------
		/**
		 * Op�rateur d'addition d'un complexe cart�sien avec un autre complexe.
		 * \f[(a + ib) + (c + id) = (a+b) + i(c+d)\f]
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de l'addition
		 * @see operator+ (const Complex<T> * c) const
		 */
		CComplex<T> operator +(const CComplex<T> & c) const;

		/**
		 * Op�rateur d'addition de deux nombres complexes quelconques
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un poiteur vers un nouveau nombre complexe r�sultant de
		 * l'addition (La classe Complex<T> �tant abstraite, elle ne peut pas
		 * avoir d'instances, il faut donc utiliser soit des r�f�rences, soit
		 * des pointeurs)
		 */
		Complex<T> * operator +(const Complex<T> & c) const;

		/**
		 * Op�rateur de soustraction d'un complexe cart�sien avec un autre complexe.
		 * \f[(a + ib) - (c + id) = (a-b) + i(c-d)\f]
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de la soustraction
		 * @see operator - (const Complex<T> * c) const
		 */
		CComplex<T> operator -(const CComplex<T> & c) const;

		/**
		 * Op�rateur de soustraction de deux nombres complexes quelconques
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe r�sultant de
		 * la soustraction
		 */
		Complex<T> * operator -(const Complex<T> & c) const;

		/**
		 * Op�rateur de multiplication d'un complexe cart�sien avec un autre complexe.
		 * \f[(a + ib) * (c + id) = (ac-bd) + i(ad+bc)\f]
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de la multiplication
		 * @see operator* (const Complex<T> * c) const
		 */
		CComplex<T> operator *(const CComplex<T> & c) const;

		/**
		 * Op�rateur de multiplication de deux nombres complexes quelconques
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe r�sultant de
		 * la multiplication
		 */
		Complex<T> * operator *(const Complex<T> & c) const;

		/**
		 * Op�rateur de division d'un complexe cart�sien par un autre complexe.
		 * \f[
		 * 	\frac{(a + ib)}{(c + id)}  =
		 * 	\frac{(a + ib)(c - id)}{(c + id)(c - id)} =
		 * 	\frac{(ac + bd) + i(bc - ad)}{c^2 + d^2} =
		 * 	\left(\frac{ac + bd}{c^2 + d^2}\right)
		 * 	+ i \left(\frac{bc - ad}{c^2 + d^2}\right)
		 * \f]
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de la division
		 */
		CComplex<T> operator /(const CComplex<T> & c) const;

		/**
		 * Op�rateur de division de deux nombres complexes quelconques
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe r�sultant de
		 * la division
		 */
		Complex<T> * operator /(const Complex<T> & c) const;

		/**
		 * Inverse d'un complexe cart�sien.
		 * \f[ \frac{1}{a + ib} = \frac{a - ib}{a^2 + b^2} \f]
		 * @return le complexe invers�
		 */
		CComplex<T> inverse() const;

		/**
		 * Complexe conjugu�.
		 * \f[ \overline{a + ib} = a - ib \f]
		 * @return une r�f�rence vers le complexe conjugu�
		 */
		CComplex<T> conjugate() const;

		// --------------------------------------------------------------------
		// Affichage
		// --------------------------------------------------------------------
		/**
		 * Chaine de caract�res repr�sentant l'objet
		 * @return une chaine de caract�res repr�sentant le Complexe
		 */
		string toString() const;

		/**
		 * Op�rateur d'entr�e � partir d'une r�f�rence.
		 * @pre le Complexe doit d�j� exister
		 * @param in le flux d'entr�e � partir duquel on lit
		 * @param c r�f�rence vers le Complexe � remplir
		 * @return une r�f�rence vers le flux d'entr�e de mani�re � pouvoir
		 * cumuler les op�rateurs
		 * @posst le Complexe est remplit avec les valeurs lue sur le flux
		 * d'entr�e
		 */
		friend istream & operator >><>(istream & in, CComplex<T> & c);
};

#endif /*CARTESIANCOMPLEX_H_*/
