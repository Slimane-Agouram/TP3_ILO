#ifndef COMPLEX_H_
#define COMPLEX_H_
#include <iostream>	// pour les flux d'entrée/sortie
#include <string>	// pour les string
using namespace std;

#include "Exception.h"

// déclaration préalable pour les futures déclarations amies des opérateurs
template <class T> class Complex;
template <class T> ostream & operator <<(ostream & out, const Complex<T> & c);
template <class T> ostream & operator <<(ostream & out, const Complex<T> * c);

/**
 * Class abstraite pour les nombres complexes
 * @param T le type des nombres utilisés
 */
template <class T> class Complex
{
	protected:
		/**
		 * Constante utilisée pour déterminer l'égalité à EPSILON près entre
		 * deux complexes.
		 * Elément minimal de comparaison
		 */
		static T const EPSILON;

		/**
		 * Elément nul.
		 */
		static T const ZERO;

		/**
		 * Nombre d'instanciations des complexes
		 */
		static size_t NbInstances;

		/**
		 * N° d'instance
		 */
		size_t instanceNumber;

		// --------------------------------------------------------------------
		// Constructeurs protégés (uniquement utilisés par les classes filles)
		// --------------------------------------------------------------------
		/**
		 * Constructeur par défaut (n'est en principe jamais utilisé par
		 * l'utilisateur puisque la classe Complex<T> est abstraite)
		 * mais est appelé par défaut par tous les constructeurs des classes
		 * filles.
		 * @post incrémente #NbInstances et affiche un message
		 * de création dans le flux clog
		 */
		Complex(void);

		/**
		 * Constructeur de copie d'un autre complexe (n'est en principe jamais
		 * utilisé par l'utilisateur puisque la classe Complex<T> est abstraite)
		 * mais est appelé par défaut par tous les constructeurs des classes
		 * filles.
		 * @param c le complexe à copier.
		 * @post incrémente #NbInstances et affiche un message
		 * de création dans le flux clog
		 */
		Complex(const Complex<T> & c);

	public:
		/**
		 * Destructeur virtuel
		 * @post décrémente #NbInstances et affiche un message dans clog
		 */
		virtual ~Complex();

		// --------------------------------------------------------------------
		// Accesseurs des propriétés des nombres complexes
		// --------------------------------------------------------------------
		/**
		 * partie réelle (méthode abstraite)
		 * @return la partie réelle du nombre complexe
		 */
		virtual T real() const = 0;

		/**
		 * Partie imaginaire (méthode abstraite)
		 * @return la partie imaginaire du nombre complexe
		 */
		virtual T imag() const = 0;

		/**
		 * Norme du nombre complexe dans le plan complexe (méthode abstraite)
		 * @return la abs du nombre dans le plan complexe
		 */
		virtual double abs() const = 0;

		/**
		 * L'angle du nombre dans le plan complexe (méthode abstraite)
		 * @return l'angle du nombre dans le plan complexe
		 */
		virtual double arg() const throw (Exception) = 0;

		// --------------------------------------------------------------------
		// Self Operations (opérations affectant l'instance courante)
		// --------------------------------------------------------------------
		/**
		 * Opérateur d'affectation (méthode abstraite)
		 * @param c la référence d'un autre nombre complexe
		 * @return la référence vers le nouveau nombre complexe de manière à
		 * pouvoir cumuler l'opérateur
		 * @see operator= (Complex<T> * c)
		 */
		virtual Complex<T> & operator =(const Complex<T> & c) = 0;

		/**
		 * Opérateur de self addition (méthode abstraite)
		 * @param c le complexe à ajouter au complexe courant
		 * @return une référence vers le complexe courant
		 */
		virtual Complex<T> & operator +=(const Complex<T> & c) = 0;

		/**
		 * Opérateur de self soustraction (méthode abstraite)
		 * @param c le complexe à soustraire au complexe courant
		 * @return une référence vers le complexe courant
		 */
		virtual Complex<T> & operator -=(const Complex<T> & c) = 0;

		/**
		 * Opérateur de self multiplication (méthode abstraite)
		 * @param c le complexe à multiplier au complexe courant
		 * @return une référence vers le complexe courant
		 */
		virtual Complex<T> & operator *=(const Complex<T> & c) = 0;

		/**
		 * Opérateur de self division (méthode abstraite)
		 * @param c le complexe qui divise le complexe courant
		 * @return une référence vers le complexe courant
		 */
		virtual Complex<T> & operator /=(const Complex<T> & c) = 0;

		// --------------------------------------------------------------------
		// Opérations (opérations créant un résultat)
		// La classe Complex<T> étant abstraite, elle ne peut pas
		// avoir d'instances, il faut donc utiliser soit des références, soit
		// des pointeurs
		// --------------------------------------------------------------------
		/**
		 * Opérateur d'addition de deux nombres complexes quelconques
		 * (méthode abstraite)
		 * @param c la référence vers un autre nombre complexe
		 * @return un poiteur vers un nouveau nombre complexe résultant de
		 * l'addition
		 */
		virtual Complex<T> * operator +(const Complex<T> & c) const = 0;

		/**
		 * Opérateur de soustraction de deux nombres complexes (méthode abstraite)
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de la soustraction
		 */
		virtual Complex<T> * operator -(const Complex<T> & c) const = 0;

		/**
		 * Opérateur de multiplication de deux nombres complexes (méthode abstraite)
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de la multiplication
		 */
		virtual Complex<T> * operator *(const Complex<T> & c) const = 0;

		/**
		 * Opérateur de division de deux nombres complexes (méthode abstraite)
		 * @param c la référence vers un autre nombre complexe
		 * @return un nouveau nombre complexe résultant de la division
		 */
		virtual Complex<T> * operator /(const Complex<T> & c) const = 0;

		// --------------------------------------------------------------------
		// Comparaison
		// --------------------------------------------------------------------
		/**
		 * Opérateur de comparaison de deux nombres complexes
		 * @param c la référence d'un combre complexe
		 * @return vrai si les parties réelles et imaginaires des deux nombres
		 * complexes sont identiques à epsilon près.
		 */
		virtual bool operator ==(const Complex<T> & c) const;

		/**
		 * Opérateur de différentiation de deux nombres complexes
		 * @param c la référence d'un combre complexe
		 * @return vrai si les parties réelles et imaginaires des deux nombres
		 * complexes sont identiques à epsilon près.
		 * @see operator== (const Complex<T> & c) const
		 */
		virtual bool operator !=(const Complex<T> & c) const;

		// --------------------------------------------------------------------
		// Affichage
		// --------------------------------------------------------------------
		/**
		 * Chaine de caractères représentant l'objet (méthode abstraite).
		 * Seule cette partie devra être implémentée par les classes filles
		 * On pourra ainsi définir l'opérateur de sortie << dans cette classe
		 * en utilisant le toString spécialisé pour chaque type de complexe.
		 * @return une chaine de caractères représentant le Complexe
		 */
		virtual string toString() const = 0;

		/**
		 * Opérateur de sortie standard à partir d'une référence
		 * @param out le flux de sortie vers lequel on écrit
		 * @param c le nombre complexe à écrire sur le flux
		 * @return une référence vers le flux de sortie de manière à pouvoir
		 * cumuler les opérateurs
		 * @see toString() const
		 * @see operator<<(ostream & out, const Complex<T> * c)
		 */
		friend ostream & operator <<<>(ostream & out, const Complex<T> & c);
		// Notez que ceci -----------^ est obligatoire, sans quoi cet operateur
		// ami serait considéré comme une "non-template function"

		/**
		 * Opérateur de sortie standard à partir d'un pointeur
		 * @param out le flux de sortie vers lequel on écrit
		 * @param c le nombre complexe à écrire sur le flux
		 * @return une référence vers le flux de sortie de manière à pouvoir
		 * cumuler les opérateurs
		 * @see toString() const
		 * @see operator<<(ostream & out, const Complex<T> & c)
		 */
		friend ostream & operator <<<>(ostream & out, const Complex<T> * c);
};

#endif /*COMPLEX_H_*/
