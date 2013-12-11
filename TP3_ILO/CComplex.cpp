#include <cmath>		// pour les fonctions math�matiques
#include <iostream>		// pour les flux I/O
#include <string>		// pour les string
#include <sstream>		// pour les ostringstream
#include <typeinfo>		// pour le typeid
#include <math.h>
using namespace std;

#include "CComplex.h"

// ----------------------------------------------------------------------------
// Constructeurs / Desctructeur
// ----------------------------------------------------------------------------
/*
 * Constructeur d'un complexe cart�sien
 * @param r la partie r�elle
 * @param i la partie imaginaire
 */
template <class T>
CComplex<T>::CComplex(const T r, const T i) :
	Complex<T>() // TODO compl�ter la liste d'initialisation
{
	CComplex<T>::NbInstances++;
	clog << "CComplex<" << typeid(T).name() << ">["
    << instanceNumber << "]( "<< endl;
}

/*
 * Constructeur de copied'un complexe cart�sien
 * @param c le complexe cart�sien dont on doit copier les valeurs
 */
template <class T>
CComplex<T>::CComplex(const Complex<T> & c) :
	Complex<T>(c) // TODO compl�ter la liste d'initialisation
{
	Complex<T>::NbInstances++;
	clog << "CComplex<" << typeid(T).name() << ">["
    << instanceNumber << "]( "<< c  << ")" << endl;
}

/*
 * Constructeur de copie/conversion d'un complexe cart�sien de nature diff�rente
 * @param c le complexe cart�sien d'un autre type dont on doit
 * copier les valeurs
 */
template <class T>
template <class U>
CComplex<T>::CComplex(const Complex<U> & c) :
	Complex<T>(c) // TODO compl�ter la liste d'initialisation
{
    this->_real = (T)c.real();
    this->_imag = (T)c._imag();
}

template <class T>
CComplex<T>::~CComplex()
{
	clog << "~CComplex<" << typeid(T).name() << ">["
    << instanceNumber << "]" << endl;
	CComplex<T>::NbInstances--;
}

// ----------------------------------------------------------------------------
// Propri�t�s des nombres complexes
// ----------------------------------------------------------------------------
/*
 * partie r�elle (accesseur en lecture seule)
 * @return la partie r�elle du nombre complexe
 */
template <class T>
T CComplex<T>::real() const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return (T)0;
}

/*
 * partie r�elle (accesseur en lecture/�criture)
 * @return une r�f�rence vers la partie r�elle du nombre complexe
 */
template <class T>
T & CComplex<T>::real()
{
	return _real;
	
}


/*
 * Partie imaginaire (accesseur en lecture seule)
 * @return la partie imaginaire du nombre complexe
 */
template <class T>
T CComplex<T>::imag() const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
    return _imag;
}

/*
 * Partie imaginaire (accesseur en lecture/�criture)
 * @return une r�f�rence vers la partie imaginaire du nombre complexe
 */
template <class T>
T & CComplex<T>::imag()
{
    return  _real;
}

/*
 * Norme du nombre complexe dans le plan complexe
 * @return la norme du nombre dans le plan complexe
 */
template <class T>
double CComplex<T>::abs() const
{
	return sqrt(pow(_real, 2)+pow(_imag, 2));
    
}

/*
 * L'angle du nombre dans le plan complexe.
 * a > 0 			==> theta = atan(b/a) ou atan2(b,a)
 * a < 0 & b >= 0	==> theta = atan(b/a) + ou - PI
 * a < 0 & b < 0	==> theta = atan(b/a) - ou + PI
 * a = 0 & b > 0 	==> PI/2
 * a = 0 & b < 0	==> -PI/2
 * a = 0 & b = 0	==> ind�termin�
 * @return l'angle du nombre dans le plan complexe
 */
template <class T>
double CComplex<T>::arg() const throw (Exception)
{
	if(_real==0 && _imag==0)
    {
        throw Exception("indetermine");
    }
    else if (_real==0 && _imag<0)
    {
        return -M_1_PI/2;
    }
    else if(_real==0 && _imag>0)
    {
        return M_1_PI/2;
    }
    else if(_real>0 && _imag>0)
    {
        return atan(_imag/_real) + M_1_PI;
    }
    else if(_real<0 && _imag>=0)
    {
        return atan(_imag/_real) + M_1_PI;
    }
    else
        return atan(_imag/_real);
}

/**
 * [Optionnel] Sp�cialisation de l'angle du nombre dans le plan complexe pour les ints.
 * @return l'angle du nombre dans le plan complexe
 */
template <>
double CComplex<int>::arg() const throw (Exception)
{
	/*
	 * TODO remplacer par l'impl�mentation
	 * Si impossible de calculer l'argument alors :
	 * 	stringstream message;
	 * 	message << "CComplex<T>::arg() : ind�termin�";
	 * 	message << " sur " << this;
	 * 	throw Exception(message.str());
	 */
	return 0.0;
}

// ----------------------------------------------------------------------------
// Self Operations
// ----------------------------------------------------------------------------
/*
 * Op�rateur d'affectation � partir de n'importe quel complexe
 * @param la r�f�rence d'un autre nombre complexe
 * @return la r�f�rence vers le nouveau nombre complexe
 */
template <class T>
Complex<T> & CComplex<T>::operator =(const Complex<T> & c)
{
    if(strcmp(typeid(c).name(),"CComplex")==0)
    {
	this->_real = c.real();
    this->_imag = c.imag();
    }
    else
    {
        this->_real = c.abs();
        this->_imag = c.arg();
    }
	return *this;
}

/*
 * Op�rateur d'affectation � partir d'un complexe cart�sien
 * @param la r�f�rence d'un autre nombre complexe
 * @return la r�f�rence vers le nouveau nombre complexe
 */
template <class T>
Complex<T> & CComplex<T>::operator =(const CComplex<T> & c)
{
	this->_real = (T)c.real();
    this->_imag = (T)c.imag();
	return *this;
}

/*
 * Op�rateur de self addition.
 * @param c le complexe � ajouter au complexe courant
 * @return une r�f�rence vers le complexe courant
 */
template <class T>
Complex<T> & CComplex<T>::operator +=(const Complex<T> & c)
{
	this->_real = c.real() + this->_real;
    this->_imag = c.imag() + this->_imag;
	return *this;
}

/*
 * Op�rateur de self soustraction.
 * @param c le complexe � soustraire au complexe courant
 * @return une r�f�rence vers le complexe courant
 */
template <class T>
Complex<T>& CComplex<T>::operator -=(const Complex<T> & c)
{
    this->_real = c.real() - this->_real;
    this->_imag = c.imag() - this->_imag;
	return *this;
}

/*
 * Op�rateur de self multiplication.
 * @param c le complexe � multiplier au complexe courant
 * @return une r�f�rence vers le complexe courant
 */
template <class T>
Complex<T>& CComplex<T>::operator *=(const Complex<T> & c)
{
	/*
	 * TODO A compl�ter ...
	 * (a+ ib)*(c +id) = (ac-bd) + i(bc+ad)
	 */
    this->_real = this->_real*c.real() - this->_imag*c.imag();
    this->_imag = this->_imag* c.real() + this->_real*c.imag();
	return *this;
}

/*
 * Op�rateur de self division.
 * @param c le complexe qui divise le complexe courant
 * @return une r�f�rence vers le complexe courant
 */
template <class T>
Complex<T> & CComplex<T>::operator /=(const Complex<T> & c)
{
	/*
	 * TODO A compl�ter ...
	 * (a + ib)      ac + bd         bc - ad
	 * -------- =  ----------- + i -----------
	 * (c + id)     c^2 + d^2       c^2 + d^2
	 */
    this->_real =(this->_real*c.real() - this->_imag*c.imag())/(pow(c.real(), 2)+pow(c.imag(), 2));
    this->_imag = ((this->_imag* c.real() + this->_real*c.imag())/(pow(c.real(), 2)+pow(c.imag(), 2)));

	return *this;
}

// ----------------------------------------------------------------------------
// Operations
// ----------------------------------------------------------------------------
/*
 * Op�rateur d'addition de deux nombres complexes.
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
CComplex<T> CComplex<T>::operator +(const CComplex<T> & c) const
{
    CComplex<T> ret ;
	ret._real = this->_real + c.real();
   ret._imag = this->_imag + c.imag();
    
	return ret;
    
}

/*
 * Op�rateur d'addition de deux nombres complexes quelconques
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un poiteur vers un nouveau nombre complexe r�sultant de
 * l'addition (La classe Complex<T> �tant abstraite, elle ne peut pas
 * avoir d'instances, il faut donc utiliser soit des r�f�rences, soit
 * des pointeurs)
 */
template <class T>
Complex<T> * CComplex<T>::operator + (const Complex<T> & c) const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 */
	return new CComplex<T>();
}

/*
 * Op�rateur de soustraction de deux nombres complexes
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
CComplex<T> CComplex<T>::operator -(const CComplex<T> & c) const
{
    CComplex<T> ret ;
	ret._real = this->_real - c.real();
    ret._imag = this->_imag - c.imag();
    
	return ret;
}

/*
 * Op�rateur de soustraction de deux nombres complexes quelconques
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe r�sultant de
 * la soustraction
 */
template <class T>
Complex<T> * CComplex<T>::operator -(const Complex<T> & c) const
{
    CComplex<T> *ret = new CComplex<T>()  ;
	ret->_real = this->_real + c.real();
    ret->_imag = this->_imag + c.imag();
    
	return ret;
}

/*
 * Op�rateur de multiplication de deux nombres complexes
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
CComplex<T> CComplex<T>::operator *(const CComplex<T> & c) const
{
	CComplex<T> ret ;
	ret._real = this->_real*c.real() - this->_imag*c.imag();
    ret._imag = this->_imag* c.real() + this->_real*c.imag();

    
	return ret;

}

/*
 * Op�rateur de multiplication de deux nombres complexes quelconques
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe r�sultant de
 * la multiplication
 */
template <class T>
Complex<T> * CComplex<T>::operator *(const Complex<T> & c) const
{
	
	CComplex<T> *ret = new CComplex<T>() ;
	ret->_real = this->_real*c.real() - this->_imag*c.imag();
    ret->_imag = this->_imag* c.real() + this->_real*c.imag();
    
    
	return ret;
}

/*
 * Op�rateur de division de deux nombres complexes
 * @param la r�f�rence vers un autre nombre complexe
 * @return un nouveau nombre complexe r�sultant de l'addition
 */
template <class T>
CComplex<T> CComplex<T>::operator /(const CComplex<T> & c) const
{
	
	CComplex<T> ret ;
	ret._real = (this->_real*c.real() - this->_imag*c.imag())/(pow(c.real(), 2)+pow(c.imag(), 2));
    ret._imag = ((this->_imag* c.real() + this->_real*c.imag())/(pow(c.real(), 2)+pow(c.imag(), 2)));

    
	return ret;

}

/**
 * Op�rateur de division de deux nombres complexes quelconques
 * @param c la r�f�rence vers un autre nombre complexe
 * @return un pointeur vers un nouveau nombre complexe r�sultant de
 * la division
 */
template <class T>
Complex<T> * CComplex<T>::operator /(const Complex<T> & c) const
{
	CComplex<T> *ret = new CComplex<T>() ;
    
	ret->_real = (this->_real*c.real() - this->_imag*c.imag())/(pow(c.real(), 2)+pow(c.imag(), 2));
    ret->_imag = ((this->_imag* c.real() + this->_real*c.imag())/(pow(c.real(), 2)+pow(c.imag(), 2)));
    
    
	return ret;
}

/*
 * Inverse d'un complexe
 * @return le complexe invers�
 */
template <class T>
CComplex<T> CComplex<T>::inverse() const
{
	/*
	 * TODO remplacer par l'impl�mentation
	 *     1       a - ib
	 * -------- = ---------
	 * (a + ib)   a^2 + b^2
	 */
	CComplex<T> ret ;
    ret._real = this->real() /(pow(this->real(), 2)+ pow(this->imag(), 2));
    ret._imag =  -this->imag() /(pow(this->real(), 2)+ pow(this->imag(), 2));
    return ret;

}

/*
 * Complexe conjugu�
 * @return une r�f�rence vers le complexe conjugu�
 */
template <class T>
CComplex<T> CComplex<T>::conjugate() const
{
	CComplex<T> ret ;
    ret._real = this->real();
    ret._imag = -this->imag();
    return ret;
}

// ----------------------------------------------------------------------------
// Affichage
// ----------------------------------------------------------------------------
/*
 * Chaine de caract�res repr�sentant l'objet
 * @return une chaine de caract�res repr�sentant le Complexe
 */
template <class T>
string CComplex<T>::toString() const
{
	// ostringstream s'utilise comme un flux de sortie
	ostringstream outstring;

	/*
	 * TODO compl�ter outstring par :
	 * ( real, imag )[n�d'instance]
	 */

	return outstring.str();
}

/*
 * Op�rateur d'entr�e � partir d'une r�f�rence.
 * @pre le Complexe doit d�j� exister et est remplit avec les valeurs
 * lue sur le flux d'entr�e : on lit d'abord la partie r�elle puis la partie
 * imaginaire
 * @param in le flux d'entr�e � partir duquel on lit
 * @param c r�f�rence vers le Complexe � remplir
 * @return une r�f�rence vers le flux d'entr�e de mani�re � pouvoir
 * cumuler les op�rateurs
 */
template <class T>
istream & operator >>(istream & in, CComplex<T> & c)
{
	/*
	 * TODO � compl�ter par la lecture de _real puis de _imag depuis in
	 */

	return in;
}

// ----------------------------------------------------------------------------
// Instanciations et sp�cialisations
// ----------------------------------------------------------------------------
// proto instanciation des templates
template class CComplex<double> ;
template class CComplex<float> ;
template class CComplex<int> ;

// Sp�cialisation des constructeurs de conversion de la classe CComplex pour
// les double, float et int
template <> template <> CComplex<double>::CComplex(const Complex<float> & c) // TODO compl�ter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * CComplex<double>[n� d'instance]<float>( val de c )
	 */
}
template <> template <> CComplex<double>::CComplex(const Complex<int> & c) // TODO compl�ter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * CComplex<double>[n� d'instance]<int>( val de c )
	 */
}
template <> template <> CComplex<float>::CComplex(const Complex<int> & c) // TODO compl�ter la liste d'initialisation
{
	/*
	 * TODO Envoyer dans clog un message similaire � celui de Complex<T>(c) :
	 * CComplex<float>[n� d'instance]<int>( val de c )
	 */
}

// instanciation des op�rateurs externes sur les templates protoinstanci�s
template istream & operator >>(istream &, CComplex<double> &);
template istream & operator >>(istream &, CComplex<float> &);
template istream & operator >>(istream &, CComplex<int> &);
