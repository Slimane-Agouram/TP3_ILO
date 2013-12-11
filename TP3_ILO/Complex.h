#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>	// pour les flux d'entr�e/sortie
#include <string>	// pour les string
using namespace std;

#include "Exception.h"

// d�claration pr�alable pour les futures d�clarations amies des op�rateurs
template <class T> class Complex;
template <class T> ostream & operator <<(ostream & out, const Complex<T> & c);
template <class T> ostream & operator <<(ostream & out, const Complex<T> * c);

/**
 * Class abstraite pour les nombres complexes
 * @param T le type des nombres utilis�s
 */
template <class T> class Complex
{
	protected:
		/**
		 * Constante utilis�e pour d�terminer l'�galit� � EPSILON pr�s entre
		 * deux complexes.
		 * El�ment minimal de comparaison
		 */
		static T const EPSILON;

		/**
		 * El�ment nul.
		 */
		static T const ZERO;

		/**
		 * Nombre d'instanciations des complexes
		 */
		static size_t NbInstances;

		/**
		 * N� d'instance
		 */
		size_t instanceNumber;

		// --------------------------------------------------------------------
		// Constructeurs prot�g�s (uniquement utilis�s par les classes filles)
		// --------------------------------------------------------------------
		/**
		 * Constructeur par d�faut (n'est en principe jamais utilis� par
		 * l'utilisateur puisque la classe Complex<T> est abstraite)
		 * mais est appel� par d�faut par tous les constructeurs des classes
		 * filles.
		 * @post incr�mente #NbInstances et affiche un message
		 * de cr�ation dans le flux clog
		 */
		Complex(void);

		/**
		 * Constructeur de copie d'un autre complexe (n'est en principe jamais
		 * utilis� par l'utilisateur puisque la classe Complex<T> est abstraite)
		 * mais est appel� par d�faut par tous les constructeurs des classes
		 * filles.
		 * @param c le complexe � copier.
		 * @post incr�mente #NbInstances et affiche un message
		 * de cr�ation dans le flux clog
		 */
		Complex(const Complex<T> & c);

	public:
		/**
		 * Destructeur virtuel
		 * @post d�cr�mente #NbInstances et affiche un message dans clog
		 */
		virtual ~Complex();

		// --------------------------------------------------------------------
		// Accesseurs des propri�t�s des nombres complexes
		// --------------------------------------------------------------------
		/**
		 * partie r�elle (m�thode abstraite)
		 * @return la partie r�elle du nombre complexe
		 */
		virtual T real() const = 0;

		/**
		 * Partie imaginaire (m�thode abstraite)
		 * @return la partie imaginaire du nombre complexe
		 */
		virtual T imag() const = 0;

		/**
		 * Norme du nombre complexe dans le plan complexe (m�thode abstraite)
		 * @return la abs du nombre dans le plan complexe
		 */
		virtual double abs() const = 0;

		/**
		 * L'angle du nombre dans le plan complexe (m�thode abstraite)
		 * @return l'angle du nombre dans le plan complexe
		 */
		virtual double arg() const throw (Exception) = 0;

		// --------------------------------------------------------------------
		// Self Operations (op�rations affectant l'instance courante)
		// --------------------------------------------------------------------
		/**
		 * Op�rateur d'affectation (m�thode abstraite)
		 * @param c la r�f�rence d'un autre nombre complexe
		 * @return la r�f�rence vers le nouveau nombre complexe de mani�re �
		 * pouvoir cumuler l'op�rateur
		 * @see operator= (Complex<T> * c)
		 */
		virtual Complex<T> & operator =(const Complex<T> & c) = 0;

		/**
		 * Op�rateur de self addition (m�thode abstraite)
		 * @param c le complexe � ajouter au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		virtual Complex<T> & operator +=(const Complex<T> & c) = 0;

		/**
		 * Op�rateur de self soustraction (m�thode abstraite)
		 * @param c le complexe � soustraire au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		virtual Complex<T> & operator -=(const Complex<T> & c) = 0;

		/**
		 * Op�rateur de self multiplication (m�thode abstraite)
		 * @param c le complexe � multiplier au complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		virtual Complex<T> & operator *=(const Complex<T> & c) = 0;

		/**
		 * Op�rateur de self division (m�thode abstraite)
		 * @param c le complexe qui divise le complexe courant
		 * @return une r�f�rence vers le complexe courant
		 */
		virtual Complex<T> & operator /=(const Complex<T> & c) = 0;

		// --------------------------------------------------------------------
		// Op�rations (op�rations cr�ant un r�sultat)
		// La classe Complex<T> �tant abstraite, elle ne peut pas
		// avoir d'instances, il faut donc utiliser soit des r�f�rences, soit
		// des pointeurs
		// --------------------------------------------------------------------
		/**
		 * Op�rateur d'addition de deux nombres complexes quelconques
		 * (m�thode abstraite)
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un poiteur vers un nouveau nombre complexe r�sultant de
		 * l'addition
		 */
		virtual Complex<T> * operator +(const Complex<T> & c) const = 0;

		/**
		 * Op�rateur de soustraction de deux nombres complexes (m�thode abstraite)
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de la soustraction
		 */
		virtual Complex<T> * operator -(const Complex<T> & c) const = 0;

		/**
		 * Op�rateur de multiplication de deux nombres complexes (m�thode abstraite)
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de la multiplication
		 */
		virtual Complex<T> * operator *(const Complex<T> & c) const = 0;

		/**
		 * Op�rateur de division de deux nombres complexes (m�thode abstraite)
		 * @param c la r�f�rence vers un autre nombre complexe
		 * @return un nouveau nombre complexe r�sultant de la division
		 */
		virtual Complex<T> * operator /(const Complex<T> & c) const = 0;

		// --------------------------------------------------------------------
		// Comparaison
		// --------------------------------------------------------------------
		/**
		 * Op�rateur de comparaison de deux nombres complexes
		 * @param c la r�f�rence d'un combre complexe
		 * @return vrai si les parties r�elles et imaginaires des deux nombres
		 * complexes sont identiques � epsilon pr�s.
		 */
		virtual bool operator ==(const Complex<T> & c) const;

		/**
		 * Op�rateur de diff�rentiation de deux nombres complexes
		 * @param c la r�f�rence d'un combre complexe
		 * @return vrai si les parties r�elles et imaginaires des deux nombres
		 * complexes sont identiques � epsilon pr�s.
		 * @see operator== (const Complex<T> & c) const
		 */
		virtual bool operator !=(const Complex<T> & c) const;

		// --------------------------------------------------------------------
		// Affichage
		// --------------------------------------------------------------------
		/**
		 * Chaine de caract�res repr�sentant l'objet (m�thode abstraite).
		 * Seule cette partie devra �tre impl�ment�e par les classes filles
		 * On pourra ainsi d�finir l'op�rateur de sortie << dans cette classe
		 * en utilisant le toString sp�cialis� pour chaque type de complexe.
		 * @return une chaine de caract�res repr�sentant le Complexe
		 */
		virtual string toString() const = 0;

		/**
		 * Op�rateur de sortie standard � partir d'une r�f�rence
		 * @param out le flux de sortie vers lequel on �crit
		 * @param c le nombre complexe � �crire sur le flux
		 * @return une r�f�rence vers le flux de sortie de mani�re � pouvoir
		 * cumuler les op�rateurs
		 * @see toString() const
		 * @see operator<<(ostream & out, const Complex<T> * c)
		 */
		friend ostream & operator <<<>(ostream & out, const Complex<T> & c);
		// Notez que ceci -----------^ est obligatoire, sans quoi cet operateur
		// ami serait consid�r� comme une "non-template function"

		/**
		 * Op�rateur de sortie standard � partir d'un pointeur
		 * @param out le flux de sortie vers lequel on �crit
		 * @param c le nombre complexe � �crire sur le flux
		 * @return une r�f�rence vers le flux de sortie de mani�re � pouvoir
		 * cumuler les op�rateurs
		 * @see toString() const
		 * @see operator<<(ostream & out, const Complex<T> & c)
		 */
		friend ostream & operator <<<>(ostream & out, const Complex<T> * c);
};

#endif /*COMPLEX_H_*/
