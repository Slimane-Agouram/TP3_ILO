#include "Complex.h"
#include <typeinfo>

using namespace std;

/**
 * Initialisation du nombre d'instances de nombres complexes à 0
 */
template <class T> size_t Complex<T>::NbInstances = 0;

/*
 * Constructeur par défaut (n'est en principe jamais utilisé par
 * l'utilisateur puisque la classe Complex<T> est abstraite
 * mais est appelé par défaut par tous les constructeurs des classes
 * filles.
 * @post incrémente #NbInstances et affiche un message
 * de création dans le flux clog
 */
template <class T>
Complex<T>::Complex(void) :
	instanceNumber(Complex<T>::NbInstances + 1)
{
	Complex<T>::NbInstances++;
	clog << "Complex<" << typeid(T).name() << ">["
		<< instanceNumber << "]()" << endl;
}

/*
 * Constructeur de copie d'un autre complexe
 * @param c le complexe à copier.
 * @post incrémente #NbInstances et affiche un message
 * de création dans le flux clog
 */
template <class T>
Complex<T>::Complex(const Complex<T> & c) :
	instanceNumber(Complex<T>::NbInstances + 1)
{
	Complex<T>::NbInstances++;
	clog << "Complex<" << typeid(T).name() << ">["
		<< instanceNumber << "]( "<< c  << ")" << endl;

}

/*
 * Destructeur virtuel
 */
template <class T>
Complex<T>::~Complex()
{
	clog << "~Complex<" << typeid(T).name() << ">["
		<< instanceNumber << "]" << endl;
	Complex<T>::NbInstances--;
}

/*
 * Opérateur de comparaison de deux nombres complexes
 * @param la référence d'un combre complexe
 * @return vrai si les parties réelles et imaginaires des deux nombres
 * complexes sont identiques à epsilon près.
 */
template <class T>
bool Complex<T>::operator ==(const Complex<T> & c) const
{
	/*
	 * TODO remplacer par l'implémentation
	 */
	return false;
}

/*
 * Opérateur de différentiation de deux nombres complexes
 * @param la référence d'un combre complexe
 * @return vrai si les parties réelles et imaginaires des deux nombres
 * complexes sont identiques à epsilon près.
 */
template <class T>
bool Complex<T>::operator !=(const Complex<T> & c) const
{
	/*
	 * TODO remplacer par l'implémentation en utilisant operator ==(...)
	 */
	return false;
}

/*
 * Opérateur de sortie standard à partir d'une référence
 * @param out le flux de sortie vers lequel on écrit
 * @param c le nombre complexe à écrire sur le flux
 * @return une référence vers le flux de sortie de manière à pouvoir
 * cumuler les opérateurs
 */
template <class T>
ostream & operator <<(ostream & out, const Complex<T> & c)
{
	return operator <<(out, &c);
}

/*
 * Opérateur de sortie standard à partir d'un pointeur
 * @param out le flux de sortie vers lequel on écrit
 * @param c le nombre complexe à écrire sur le flux
 * @return une référence vers le flux de sortie de manière à pouvoir
 * cumuler les opérateurs
 */
template <class T>
ostream & operator <<(ostream & out, const Complex<T> * c)
{
	out << c->toString();

	return out;
}

// proto instanciation des templates
template class Complex<double> ;
template class Complex<float> ;
template class Complex<int> ;

// instanciation des opérateurs externes sur les templates protoinstanciés
template ostream & operator <<(ostream &, const Complex<double> &);
template ostream & operator <<(ostream &, const Complex<double> *);

template ostream & operator <<(ostream &, const Complex<float> &);
template ostream & operator <<(ostream &, const Complex<float> *);

template ostream & operator <<(ostream &, const Complex<int> &);
template ostream & operator <<(ostream &, const Complex<int> *);

// Spécialisation des méthodes et attributs en fonction de types spécifiques
/**
 * instantiation de la constante epsilon pour les doubles
 */
template <> const double Complex<double>::EPSILON = 1e-6;
/**
 * instantiation de la constante epsilon pour les float
 */
template <> const float Complex<float>::EPSILON = 1e-3;
/**
 * instantiation de la constante epsilon pour les entiers
 */
template <> const int Complex<int>::EPSILON = 0;

/**
 * instanciation de l'élément nul pour les doubles
 */
template <> const double Complex<double>::ZERO = 0.0;

/**
 * instanciation de l'élément nul pour les floats
 */
template <> const float Complex<float>::ZERO = 0.0;

/**
 * instanciation de l'élément nul pour les ints
 */
template <> const int Complex<int>::ZERO = 0;
