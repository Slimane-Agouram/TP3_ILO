#ifndef ECOMPLEX_H_
#define ECOMPLEX_H_

#include <iostream>
using namespace std;

#include "Complex.h"

// d�claration pr�alable pour les futures d�clarations amies des op�rateurs
template <class T> class EComplex;
template <class T> istream & operator >>(istream & in, EComplex<T> & c);

/**
 * Classe des nombres complexes d'Euler \f$ \_abs e^{i\_arg}\f$
 * avec
 * 	- \f$ \rho \f$ la norme du nombre complexe
 * 	- \f$ \_arg \f$ l'argument du nombre complexe (son angle)
 * @param T le type des nombres utilis�s pour la module
 */
template <class T> class EComplex: public Complex<T>
{
	/*
	 * Rappel des membres de Complex<T> que l'on va utiliser ici, sans quoi
	 * il faudra toujours y acc�der avec Complex<T>::membre recherch�.
	 * Ceci est une particularit� des templates
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
		 * Calcule un argument � partir d'une partie r�elle
		 * et d'une partie imaginaire
		 * @param reel une partie r�elle
		 * @param imag une partie imaginaire
		 * @return l'argument correspondant ces parties r�elles et imaginaires
		 * @throw Exception si l'argument  ne peux pas �tre d�termin� du fait
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
		 * param�tre de type n'est pas forc�ment le m�me
		 * @param c le complexe dont on doit copier les valeurs
		 * @post la norme et l'argument du complexe � copier (de type U)
		 * sont converties dans le type T
		 */
		template <class U> EComplex(const Complex<U> & c);

		/**
		 * Destructeur d'un complexe d'Euler
		 */
		virtual ~EComplex();

		// --------------------------------------------------------------------
		// Propri�t�s des complexes
		// --------------------------------------------------------------------
		/**
		 * partie r�elle.
		 * \f[
		 * x = \_abs cos(\_arg)
		 * \f]
		 * @return la partie r�elle du nombre complexe
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
		 * @return une r�f�rence vers le module du nombre dans le plan complexe
		 */
		T & abs();

		/**
		 * L'angle du nombre dans le plan complexe  (accesseur en lecture seule)
		 * @return l'angle du nombre dans le plan complexe
		 * @throw Une Exception lorsque l'argument ne peu pas �tre d�termin�
		 * car les parties r�elles et imaginaires sont nulles
		 */
		double arg() const throw (Exception);

		/**
		 * L'angle du nombre dans le plan complexe  (accesseur en
		 * lecture/�criture)
		 * @return une r�f�rence vers l'angle du nombre dans le plan complexe
		 */
		double & arg();

		// --------------------------------------------------------------------
		// Self Operations (op�rations affectant l'instance courante)
		// --------------------------------------------------------------------
		/**
		 * Op�rateur d'affectation
		 * @param c la r�f�rence d'un autre nombre complexe
		 * @return la r�f�rence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const Complex<T> & c);

		/**
		 * Op�rateur d'affectation � partir d'un complexe d'Euler
		 * @param c la r�f�rence d'un autre nombre complexe
		 * @return la r�f�rence vers le nouveau nombre complexe
		 */
		Complex<T> & operator =(const EComplex<T> & c);

		/**
		 * Op�rateur de self addition.
		 * @param c le complexe � ajouter au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 * @note Pas de solution miracle ici, il faut recr�er des parties r�elles
		 * et imaginaire, puis les additionner puis recalculer une norme et un
		 * argument.
		 * @throw Exception lorsque l'argument ne peut pas �tre estim� par
		 * #computeArgument(r,i)
		 */
		Complex<T> & operator +=(const Complex<T> & c) throw (Exception);

		/**
		 * Op�rateur de self soustraction.
		 * @param c le complexe � soustraire au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 * @note Pas de solution miracle ici, il faut recr�er des parties r�elles
		 * et imaginaire, puis les soustraire puis recalculer une norme et un
		 * argument.
		 * @throw Exception lorsque l'argument ne peut pas �tre estim� par
		 * #computeArgument(r,i)
		 */
		Complex<T> & operator -=(const Complex<T> & c) throw (Exception);

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
		 * Op�rateur d'addition de deux nombres complexes.
		 * On utilise pour ce faire la conversion en polaire / cart�sien
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de l'addition
		 */
		EComplex<T> operator +(const EComplex<T> & c) const;

		/**
		 * Op�rateur d'addition de deux nombres complexes quelconques
		 * (m�thode abstraite)
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un poiteur vers un nouveau nombre complexe r�sultant de
		 * l'addition (La classe Complex<T> �tant abstraite, elle ne peut pas
		 * avoir d'instances, il faut donc utiliser soit des r�f�rences, soit
		 * des pointeurs)
		 */
		Complex<T> * operator +(const Complex<T> & c) const;

		/**
		 * Op�rateur de soustraction de deux nombres complexes
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de l'addition
		 */
		EComplex<T> operator -(const EComplex<T> & c) const;

		/**
		 * Op�rateur de soustraction de deux nombres complexes quelconques
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe r�sultant de
		 * la soustraction
		 */
		Complex<T> * operator -(const Complex<T> & c) const;

		/**
		 * Op�rateur de multiplication de deux nombres complexes
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de l'addition
		 */
		EComplex<T> operator *(const EComplex<T> & c) const;

		/**
		 * Op�rateur de multiplication de deux nombres complexes quelconques
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe r�sultant de
		 * la multiplication
		 */
		Complex<T> * operator *(const Complex<T> & c) const;

		/**
		 * Op�rateur de division de deux nombres complexes
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de l'addition
		 */
		EComplex<T> operator /(const EComplex<T> & c) const;

		/**
		 * Op�rateur de division de deux nombres complexes quelconques
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un pointeur vers un nouveau nombre complexe r�sultant de
		 * la division
		 */
		Complex<T> * operator /(const Complex<T> & c) const;

		/**
		 * Inverse d'un complexe
		 * @return le complexe invers�
		 */
		EComplex<T> inverse() const;

		/**
		 * Complexe conjugu�
		 * @return une r�f�rence vers le complexe conjugu�
		 */
		EComplex<T> conjugate() const;

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
		 * @post le Complexe est remplit avec les valeurs
		 * lue sur le flux d'entr�e
		 */
		friend istream & operator >><>(istream & in, EComplex<T> & c);
};

#endif /*ECOMPLEX_H_*/
