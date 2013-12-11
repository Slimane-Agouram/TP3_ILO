#include "Complex.h"
#include <typeinfo>

using namespace std;

/**
 * Initialisation du nombre d'instances de nombres complexes � 0
 */
template <class T> size_t Complex<T>::NbInstances = 0;

/*
 * Constructeur par d�faut (n'est en principe jamais utilis� par
 * l'utilisateur puisque la classe Complex<T> est abstraite
 * mais est appel� par d�faut par tous les constructeurs des classes
 * filles.
 * @post incr�mente #NbInstances et affiche un message
 * de cr�ation dans le flux clog
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
 * @param c le complexe � copier.
 * @post incr�mente #NbInstances et affiche un message
 * de cr�ation dans le flux clog
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
 * Op�rateur de comparaison de deux nombres complexes
 * @param la r�f�rence d'un combre complexe
 * @return vrai si les parties r�elles et imaginaires des deux nombres
 * complexes sont identiques � epsilon pr�s.
 */
template <class T>
bool Complex<T>::operator ==(const Complex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return false;
}

/*
 * Op�rateur de diff�rentiation de deux nombres complexes
 * @param la r�f�rence d'un combre complexe
 * @return vrai si les parties r�elles et imaginaires des deux nombres
 * complexes sont identiques � epsilon pr�s.
 */
template <class T>
bool Complex<T>::operator !=(const Complex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation en utilisant operator ==(...)
	 */
	return false;
}

/*
 * Op�rateur de sortie standard � partir d'une r�f�rence
 * @param out le flux de sortie vers lequel on �crit
 * @param c le nombre complexe � �crire sur le flux
 * @return une r�f�rence vers le flux de sortie de mani�re � pouvoir
 * cumuler les op�rateurs
 */
template <class T>
ostream & operator <<(ostream & out, const Complex<T> & c)
{
	return operator <<(out, &c);
}

/*
 * Op�rateur de sortie standard � partir d'un pointeur
 * @param out le flux de sortie vers lequel on �crit
 * @param c le nombre complexe � �crire sur le flux
 * @return une r�f�rence vers le flux de sortie de mani�re � pouvoir
 * cumuler les op�rateurs
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

// instanciation des op�rateurs externes sur les templates protoinstanci�s
template ostream & operator <<(ostream &, const Complex<double> &);
template ostream & operator <<(ostream &, const Complex<double> *);

template ostream & operator <<(ostream &, const Complex<float> &);
template ostream & operator <<(ostream &, const Complex<float> *);

template ostream & operator <<(ostream &, const Complex<int> &);
template ostream & operator <<(ostream &, const Complex<int> *);

// Sp�cialisation des m�thodes et attributs en fonction de types sp�cifiques
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
 * instanciation de l'�l�ment nul pour les doubles
 */
template <> const double Complex<double>::ZERO = 0.0;

/**
 * instanciation de l'�l�ment nul pour les floats
 */
template <> const float Complex<float>::ZERO = 0.0;

/**
 * instanciation de l'�l�ment nul pour les ints
 */
template <> const int Complex<int>::ZERO = 0;
