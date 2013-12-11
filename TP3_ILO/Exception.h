/*
 * Exception.h
 *
 *  Created on: Nov 2, 2009
 *      Author: david.roussel
 */

#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <iostream>		// pour les flux d'entr�e/sortie
#include <string>		// pour les string
#include <exception>	// pour la classe de base des exceptions
using namespace std;

/**
 * Classe d'exception pour les complexes
 */
class Exception : public exception
{
	protected:
		/**
		 * Le message de l'exception : la raison de sa cr�ation
		 */
		string message;
	public:
		/**
		 * Constructeur de l'exception
		 * @param message le message de l'exception
		 */
		Exception(string message);

		/**
		 * Destructeur de l'exception : efface le message
		 */
		virtual ~Exception() throw ();

		/**
		 * Description de l'exception
		 * @return une chaine de caract�res d�crivant l'exception
		 */
		virtual const char* what() const throw ();

		/**
		 * Op�rateur de sortie standard pour les Exception
		 * @param out le flux de sortie
		 * @param c l'exception � afficher
		 * @return une r�f�rence vers le flux de sortie
		 */
		friend ostream & operator << (ostream & out, const Exception & c);
};

#endif /* EXCEPTION_H_ */
