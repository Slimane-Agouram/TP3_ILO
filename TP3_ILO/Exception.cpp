/*
 * Exception.cpp
 *
 *  Created on: Nov 2, 2009
 *      Author: david.roussel
 */

#include "Exception.h"

/*
 * Constructeur de l'exception
 * @param message le message de l'exception
 */
Exception::Exception(string message) : message(message)
{
}

/*
 * Destructeur de l'exception : efface le message
 */
Exception::~Exception() throw ()
{
	message.clear();
}

/*
 * Description de l'exception
 * @return une chaine de caractères décrivant l'exception
 */
const char* Exception::what() const throw()
{
	return message.c_str();
}

/*
 * Opérateur de sortie standard pour les Complex Exception
 * @param out le flux de sortie
 * @param c l'exception à afficher
 * @return une référence vers le flux de sortie
 */
ostream & operator << (ostream & out, const Exception & c)
{
	out << "ComplexException::" << c.message;
	return out;
}
