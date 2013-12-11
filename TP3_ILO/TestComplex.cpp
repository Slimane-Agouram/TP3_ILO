/*
 * TestComplexNew.cpp
 *
 *  Created on: 30 nov. 2012
 *      Author: davidroussel
 */

#include <cstdlib>

#include "Complex.h"
#include "CComplex.h"
#include "EComplex.h"

#include <iostream>	// pour le cout
#include <cmath>
using namespace std;

/**
 * @defgroup Main "Main program"
 */

/*@{*/

/**
 * Programme de test des nombres complexes
 * @return EXIT_SUCCESS si tout s'est bien passé, ou bien EXIT_FAILURE en cas
 * d'erreur
 */
int main()
{
	// ------------------------------------------------------------------------
	// Complexes cartésiens
	// ------------------------------------------------------------------------
	{
		cout << "Complexes cartésiens ----------------------------------------"
			<< endl;
		// --------------------------------------------------------------------
		// constructeurs
		// --------------------------------------------------------------------
		cout << "CComplex<double>() : ";
		CComplex<double> ccd0;
		cout << ccd0 << endl;

		cout << "CComplex<double>(4.5, 7.2) : ";
		CComplex<double> ccd1(4.5, 7.2);
		cout << ccd1 << endl;

		cout << "CComplex<double>(" << ccd1 << ") : ";
		CComplex<double> ccd2(ccd1);
		cout << ccd2 << endl;

		cout << "CComplex<float>(3.0, 5.1) : ";
		CComplex<float> ccf1(3.0, 5.1);
		cout << ccf1 << endl;

		cout << "CComplex<double><float>(" << ccf1 << ") : ";
		CComplex<double> ccd3(ccf1);
		cout << ccd3 << endl;

		cout << ccd0 << "::operator +=(" << ccd1 << ") : ";
		ccd0 += ccd1;
		cout << ccd0 << endl;

		cout << "CComplex<int>(3, 5) : ";
		CComplex<int> cci1(3, 5);
		cout << cci1 << endl;

		// CComplex<int> cci2(ccd3); // impossible on a pas spécialisé ce constructeur

		// --------------------------------------------------------------------
		// Propriétés
		// --------------------------------------------------------------------

		Complex<double> * pccd1 = new CComplex<double>(0.5, sqrt(3.0 / 4.0));
		cout << "Partie réelle de " << pccd1 << " : " << pccd1->real() << endl;
		cout << "Partie imaginaire de " << pccd1 << " : " << pccd1->imag()
			<< endl;

		cout << ccd0 << ".real() = " << pccd1 << "->real() = ";
		ccd0.real() = pccd1->real();
		cout << ccd0.real() << endl;
		cout << ccd0 << ".imag() = " << pccd1 << "->imag() = ";
		ccd0.imag() = pccd1->imag();
		cout << ccd0.imag() << endl;

		cout << "Norme de " << pccd1 << " : " << pccd1->abs() << endl;
		cout << "Argument de " << pccd1 << " : "
			<< (pccd1->arg() / M_PI) * 180.0 << "°" << endl;

		cout << "Argument de " << ccd0 << " : " << (ccd0.arg() / M_PI) * 180.0
			<< "°" << endl;

		CComplex<double> ccd1b;
		cout << "Argument de " << ccd1b << " : ";
		try
		{
			cout << (ccd1b.arg() / M_PI) * 180.0 << "°" << endl;
		}
		catch (Exception & e)
		{
			cout << e.what() << endl;
		}

		// --------------------------------------------------------------------
		// Self Operations
		// --------------------------------------------------------------------
		cout << ccd1b << " = " << ccd1 << " : ";
		ccd1b = ccd1;
		cout << ccd1b << endl;

		CComplex<double> ccd1c;
		cout << ccd1c << " = " << pccd1 << " : ";
		ccd1c = *pccd1;
		cout << ccd1c << endl;

		CComplex<double> ccd1d;
		cout << ccd1d << " = " << cci1 << " : ";
		ccd1d = cci1;// étrange : devrait utiliser "=" mais utilise CComplex<double><int>
		cout << ccd1d << endl;

		cout << ccd1b << " == " << ccd1 << " ?  : "
			<< (ccd1b == ccd1 ? "Ok" : "Ko") << endl;
		cout << ccd1c << " == " << *pccd1 << " ?  : "
			<< (ccd1c == *pccd1 ? "Ok" : "Ko") << endl;

		cout << ccd1d << " += " << ccd1b << " : ";
		ccd1d += ccd1b;
		cout << ccd1d << endl;
		cout << ccd1d << " -= " << ccd1b << " : ";
		ccd1d -= ccd1b;
		cout << ccd1d << endl;
		cout << ccd1d << " *= " << ccd1b << " : ";
		ccd1d *= ccd1b;
		cout << ccd1d << endl;
		cout << ccd1d << " /= " << ccd1b << " : ";
		ccd1d /= ccd1b;
		cout << ccd1d << endl;

		// --------------------------------------------------------------------
		// Operations
		// --------------------------------------------------------------------
		Complex<double> * pccd2 = new CComplex<double>(ccd1d);
		Complex<double> & rccd1 = *pccd1;
		Complex<double> & rccd2 = *pccd2;

		CComplex<double> add1 = ccd1d + ccd1c;
		cout << ccd1d << " + " << ccd1c << " = " << add1 << endl;

		Complex<double> * add2 = rccd2 + rccd1;
		cout << rccd2 << " + " << rccd1 << " = " << add2 << endl;

		CComplex<double> minus1 = ccd1d - ccd1c;
		cout << ccd1d << " - " << ccd1c << " = " << minus1 << endl;

		Complex<double> * minus2 = rccd2 - rccd1;
		cout << rccd2 << " - " << rccd1 << " = " << minus2 << endl;

		CComplex<double> mult1 = ccd1d * ccd1c;
		cout << ccd1d << " * " << ccd1c << " = " << mult1 << endl;

		Complex<double> * mult2 = rccd2 * rccd1;
		cout << rccd2 << " * " << rccd1 << " = " << mult2 << endl;

		CComplex<double> div1 = ccd1d / ccd1c;
		cout << ccd1d << " / " << ccd1c << " = " << div1 << endl;

		Complex<double> * div2 = rccd2 / rccd1;
		cout << rccd2 << " / " << rccd1 << " = " << div2 << endl;

		CComplex<double> invccd1d = ccd1d.inverse();
		cout << ccd1d << ".inverse() = " << invccd1d << endl;

		CComplex<double> conjccd1d = ccd1d.conjugate();
		cout << ccd1d << ".conjugate() = " << conjccd1d << endl;

		delete pccd1;
		delete pccd2;
		delete add2;
		delete minus2;
		delete mult2;
		delete div2;
	}
	// ------------------------------------------------------------------------
	// Complexes d'Euler
	// ------------------------------------------------------------------------
	{
		cout << "Complexes polaires ------------------------------------------"
			<< endl;
		// --------------------------------------------------------------------
		// constructeurs
		// --------------------------------------------------------------------
		cout << "EComplex<double>() : ";
		EComplex<double> ecd0;
		cout << ecd0 << endl;

		cout << "EComplex<double>(2.0, PI/4) : ";
		EComplex<double> ecd1(2.0, M_PI_4);
		cout << ecd1 << endl;

		cout << "EComplex<double>(" << ecd1 << ") : ";
		EComplex<double> ecd2(ecd1);
		cout << ecd2 << endl;

		cout << "EComplex<float>(3.0, PI/2) : ";
		EComplex<float> ecf1(3.0, M_PI_2);
		cout << ecf1 << endl;

		cout << "EComplex<double><float>(" << ecf1 << ") : ";
		EComplex<double> ecd3(ecf1);
		cout << ecd3 << endl;

		cout << ecd0 << "::operator +=(" << ecd1 << ") : ";
		ecd0 += ecd1;
		cout << ecd0 << endl;

		cout << "EComplex<int>(3, PI) : ";
		EComplex<int> eci1(3, M_PI);
		cout << eci1 << endl;

		// EComplex<int> eci2(ecd3); // impossible on a pas spécialisé ce constructeur

		// --------------------------------------------------------------------
		// Propriétés
		// --------------------------------------------------------------------

		Complex<double> * pecd1 = new EComplex<double>(1.0, M_PI / 3.0);
		cout << "Partie réelle de " << pecd1 << " : " << pecd1->real() << endl;
		cout << "Partie imaginaire de " << pecd1 << " : " << pecd1->imag()
			<< endl;
		cout << "Norme de " << pecd1 << " : " << pecd1->abs() << endl;
		cout << "Argument de " << pecd1 << " : "
			<< (pecd1->arg() / M_PI) * 180.0 << "°" << endl;

		cout << ecd0 << ".abs() = " << pecd1 << "->abs() = ";
		ecd0.abs() = pecd1->abs();
		cout << ecd0.abs() << endl;
		cout << ecd0 << ".arg() = " << pecd1 << "->arg() = ";
		ecd0.arg() = pecd1->arg();
		cout << (ecd0.arg()/M_PI)*180.0 << "°" << endl;

		EComplex<double> ecd1b;
		cout << "Argument de " << ecd1b << " : ";
		cout << (ecd1b.arg() / M_PI) * 180.0 << "°" << endl;

		// --------------------------------------------------------------------
		// Self Operations
		// --------------------------------------------------------------------
		cout << ecd1b << " = " << ecd1 << " : ";
		ecd1b = ecd1;
		cout << ecd1b << endl;

		EComplex<double> ecd1c;
		cout << ecd1c << " = " << pecd1 << " : ";
		ecd1c = *pecd1;
		cout << ecd1c << endl;

		EComplex<double> ecd1d;
		cout << ecd1d << " = " << eci1 << " : ";
		ecd1d = eci1;// étrange : devrait utiliser "=" mais utilise EComplex<double><int>
		cout << ecd1d << endl;

		cout << ecd1b << " == " << ecd1 << " ?  : "
			<< (ecd1b == ecd1 ? "Ok" : "Ko") << endl;
		cout << ecd1c << " == " << *pecd1 << " ?  : "
			<< (ecd1c == *pecd1 ? "Ok" : "Ko") << endl;

		cout << ecd1d << " += " << ecd1b << " : ";
		ecd1d += ecd1b;
		cout << ecd1d << endl;
		cout << ecd1d << " -= " << ecd1b << " : ";
		ecd1d -= ecd1b;
		cout << ecd1d << endl;
		cout << ecd1d << " *= " << ecd1b << " : ";
		ecd1d *= ecd1b;
		cout << ecd1d << endl;
		cout << ecd1d << " /= " << ecd1b << " : ";
		ecd1d /= ecd1b;
		cout << ecd1d << endl;

		// --------------------------------------------------------------------
		// Operations
		// --------------------------------------------------------------------
		Complex<double> * pecd2 = new EComplex<double>(ecd1d);
		Complex<double> & recd1 = *pecd1;
		Complex<double> & recd2 = *pecd2;

		EComplex<double> add1 = ecd1d + ecd1c;
		cout << ecd1d << " + " << ecd1c << " = " << add1 << endl;

		Complex<double> * add2 = recd2 + recd1;
		cout << recd2 << " + " << recd1 << " = " << add2 << endl;

		EComplex<double> minus1 = ecd1d - ecd1c;
		cout << ecd1d << " - " << ecd1c << " = " << minus1 << endl;

		Complex<double> * minus2 = recd2 - recd1;
		cout << recd2 << " - " << recd1 << " = " << minus2 << endl;

		EComplex<double> mult1 = ecd1d * ecd1c;
		cout << ecd1d << " * " << ecd1c << " = " << mult1 << endl;

		Complex<double> * mult2 = recd2 * recd1;
		cout << recd2 << " * " << recd1 << " = " << mult2 << endl;

		EComplex<double> div1 = ecd1d / ecd1c;
		cout << ecd1d << " / " << ecd1c << " = " << div1 << endl;

		Complex<double> * div2 = recd2 / recd1;
		cout << recd2 << " / " << recd1 << " = " << div2 << endl;

		EComplex<double> invecd1d = ecd1d.inverse();
		cout << ecd1d << ".inverse() = " << invecd1d << endl;

		EComplex<double> conjecd1d = ecd1d.conjugate();
		cout << ecd1d << ".conjugate() = " << conjecd1d << endl;

		delete pecd1;
		delete pecd2;
		delete add2;
		delete minus2;
		delete mult2;
		delete div2;
	}
	// ------------------------------------------------------------------------
	// Mélange complexes cartésiens et Euler
	// ------------------------------------------------------------------------
	{
		cout << "Complexes cartésiens et polaires -----------------------------"
			<< endl;

		// --------------------------------------------------------------------
		// constructeurs et propriétés
		// --------------------------------------------------------------------
		CComplex<double> cc1d(sqrt(3.0) / 2.0, 0.5);
		EComplex<double> ec1d(1.0, M_PI / 6.0);

		cout << cc1d << " <==> (" << cc1d.abs() << " exp i("
			<< (cc1d.arg() / M_PI) * 180.0 << "°))" << endl;
		cout << "(" << ec1d.real() << " + i " << ec1d.imag() << ") <==> "
			<< ec1d << endl;

		cout << "EComplex<double>(" << cc1d << ") = ";
		EComplex<double> ec2d(cc1d);
		cout << ec2d << endl;
		cout << "CComplex<double>(" << ec1d << ") = ";
		CComplex<double> cc2d(ec1d);
		cout << cc2d << endl;

		CComplex<float> cc1f(sqrt(3.0) / 2.0, 0.5);
		EComplex<float> ec1f(1.0, M_PI / 6.0);

		cout << "CComplex<double><float>(" << ec1f << ") = ";
		CComplex<double> cc1d2(ec1f);
		cout << cc1d2 << endl;

		cout << "EComplex<double><float>(" << cc1f << ") = ";
		EComplex<double> ec1d2(cc1f);
		cout << ec1d2 << endl;

		cout << cc1d << " == " << ec1d << " ? " << (cc1d == ec1d ? "Ok" : "Ko")
			<< endl;

		// --------------------------------------------------------------------
		// Self Operations
		// --------------------------------------------------------------------
		Complex<double> * pec1d2 = new EComplex<double>(ec1d2);
		Complex<double> * pcc1d2 = new CComplex<double>(cc1d2);

		CComplex<double> cc3d;
		cout << cc3d << " = " << ec1d2 << " : ";
		cc3d = ec1d2;
		cout << cc3d << endl;

		EComplex<double> ec3d;
		cout << ec3d << " = " << cc1d2 << " : ";
		ec3d = cc1d2;
		cout << ec3d << endl;

		CComplex<double> cc1d3;
		cout << cc1d3 << " = " << pec1d2 << " : ";
		cc1d3 = *pec1d2;
		cout << cc1d3 << endl;

		EComplex<double> ec1d3;
		cout << ec1d3 << " = " << pcc1d2 << " : ";
		ec1d3 = *pcc1d2;
		cout << ec1d3 << endl;

		cout << cc1d2 << " == " << ec1d2 << " ?  : "
			<< (cc1d2 == ec1d2 ? "Ok" : "Ko") << endl;
		cout << ec1d3 << " == " << *pec1d2 << " ?  : "
			<< (ec1d3 == *pec1d2 ? "Ok" : "Ko") << endl;

		cout << ec1d3 << " += " << cc1d2 << " : ";
		ec1d3 += cc1d2;
		cout << ec1d3 << endl;
		cout << ec1d3 << " -= " << cc1d2 << " : ";
		ec1d3 -= cc1d2;
		cout << ec1d3 << endl;
		cout << ec1d3 << " *= " << cc1d2 << " : ";
		ec1d3 *= cc1d2;
		cout << ec1d3 << endl;
		cout << ec1d3 << " /= " << cc1d2 << " : ";
		ec1d3 /= cc1d2;
		cout << ec1d3 << endl;

		cout << ec1d2 << " == " << ec1d2 << " ?  : "
			<< (ec1d2 == ec1d2 ? "Ok" : "Ko") << endl;
		cout << cc1d3 << " == " << *pec1d2 << " ?  : "
			<< (cc1d3 == *pec1d2 ? "Ok" : "Ko") << endl;

		cout << cc1d3 << " += " << ec1d2 << " : ";
		cc1d3 += ec1d2;
		cout << cc1d3 << endl;
		cout << cc1d3 << " -= " << ec1d2 << " : ";
		cc1d3 -= ec1d2;
		cout << cc1d3 << endl;
		cout << cc1d3 << " *= " << ec1d2 << " : ";
		cc1d3 *= ec1d2;
		cout << cc1d3 << endl;
		cout << cc1d3 << " /= " << ec1d2 << " : ";
		cc1d3 /= ec1d2;
		cout << cc1d3 << endl;

		// --------------------------------------------------------------------
		// Operations
		// --------------------------------------------------------------------
		Complex<double> * cadd1 = cc1d3 + ec1d3;
		cout << cc1d3 << " + " << ec1d3 << " = " << cadd1 << endl;
		Complex<double> * cadd2 = ec1d3 + cc1d3;
		cout << ec1d3 << " + " << cc1d3 << " = " << cadd2 << endl;

		Complex<double> * cminus1 = cc1d3 - ec1d3;
		cout << cc1d3 << " - " << ec1d3 << " = " << cminus1 << endl;
		Complex<double> * cminus2 = ec1d3 - cc1d3;
		cout << ec1d3 << " - " << cc1d3 << " = " << cminus2 << endl;

		Complex<double> * cmult1 = cc1d3 * ec1d3;
		cout << cc1d3 << " * " << ec1d3 << " = " << cmult1 << endl;
		Complex<double> * cmult2 = ec1d3 * cc1d3;
		cout << ec1d3 << " * " << cc1d3 << " = " << cmult2 << endl;

		Complex<double> * cdiv1 = cc1d3 / ec1d3;
		cout << cc1d3 << " / " << ec1d3 << " = " << cdiv1 << endl;
		Complex<double> * cdiv2 = ec1d3 / cc1d3;
		cout << ec1d3 << " / " << cc1d3 << " = " << cdiv2 << endl;
	}
	return EXIT_SUCCESS;
}

/*@}*/
