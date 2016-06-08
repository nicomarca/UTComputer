#ifndef LITTERALE_H_INCLUDED
#define LITTERALE_H_INCLUDED


/**
 * \file litterale.h
 * \brief file where the different class which inherits from Litterale are defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */


#include "manager.h"


using namespace std;



//////////////////////////////////////// LITTERALE NUMERIQUE ////////////////////////////////////////

/// \class The LiNumerique class
///
/// \brief abstract class which inherits from litterale
///
/// used to define liEntiere, LiReelle and LiRationnelle
///

class LiNumerique : public Litterale {
public:
    virtual string toString() const = 0;
    virtual Litterale* Clone() const = 0;
};




//////////////////////////////////////// LITTERALE ENTIERE ////////////////////////////////////////

/// \class The LiEntiere class
///
/// \brief Class which inherits from LiNumerique
///
/// 1 attribut of type int called value
/// used to represent the integers in the Calculator
///

class LiEntiere : public LiNumerique {
    int value; /*!< value : attribut of type int*/

public:

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiEntiere class
     *
     *  \param without any parameters, value will be initialize to 0.
     */
    LiEntiere():value(0) {}

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiEntiere class
     *
     *  \param with one parameter of type int to initialize value
     */
	LiEntiere(int v=0):value(v) {}

    /*!
     *  \brief toString() method
     *
     *  Method which takes value (integer) transforms it into a string and returns it
     *  Pure virtual method in Litterale, used in the afficher() method
     *
     *  \param no parameter
     *  \return string
     */
    string toString() const {stringstream ss; ss << value; return ss.str();}

    /*!
     *  \brief isZero() method
     *
     *  Method which inform us if the attribut is 0
     *  Pure virtual method in Litterale
     *
     *  \param no parameter
     *  \return true if value == 0 false otherwise
     */
    bool isZero() const { if(value == 0) return true; else return false; }

    /*!
     *  \brief getValue() method
     *
     *  Method which returns the value of an object LiEntiere
     *  Pure virtual method in Litterale
     *
     *  \param no parameter
     *  \return integer
     */
	int getValue() const { return value; }

    /*!
     *  \brief setValue() method
     *
     *  Method to set a new value to the attribut
     *
     *  \param 1 parameter of type int
     *  \return integer
     */
	int setValue(int n) { value=n; return n; }

    /*!
     *  \brief getNumerateur() method
     *
     *  Method which was defined in Litterale (pure virtual) for the LiRationnelle class
     *  Throws an error if called on an LiEntiere object (doesn't have numerateur)
     *
     *  \param no parameter
     *  \return int
     */
	int getNumerateur() const { throw LiException("error : pas de numerateur dans une LiEntiere"); }

    /*!
     *  \brief getDenominateur() method
     *
     *  Method which was defined in Litterale (pure virtual) for the LiRationnelle class
     *  Throws an error if called on an LiEntiere object (doesn't have denominateur)
     *
     *  \param no parameter
     *  \return int
     */
	int getDenominateur() const { throw LiException("error : pas de denominateur dans une LiEntiere"); }

    /*!
     *  \brief getReel() method
     *
     *  Method which was defined in Litterale (pure virtual) for the LiReelle class
     *  Throws an error if called on an LiEntiere object (doesn't have reel attribut)
     *
     *  \param no parameter
     *  \return int
     */
    double getReel() const { throw LiException("error : pas de reel dans une LiEntiere"); }

    /*!
     *  \brief overloaded operator+
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to add an LiEntiere object and a Litterale
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator+ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator-
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to substract to a LiEntiere object a Litterale
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator- (const Litterale& li) const;
    /*!
     *  \brief overloaded operator/
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to divide a LiEntiere by a Litterale
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator/ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator*
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to multiply to a LiEntiere object a Litterale oject
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator* (const Litterale& li) const;

    /*!
     *  \brief overloaded operator==
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere equals a Litterale
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to LiEntiere (with value = 1 if true, value = 0 otherwise)
     */
	LiEntiere* operator== (const Litterale& li) const;
    /*!
     *  \brief overloaded operator!=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere does not equal a Litterale
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to LiEntiere (with value = 1 if true, value = 0 otherwise)
     */
	LiEntiere* operator!= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is less than or equals to a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator<= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator>=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is greater than or equals to a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator>= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is less than a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator< (const Litterale& li) const;
    /*!
     *  \brief overloaded operator>
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is greater than a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator> (const Litterale& li) const;
    /*!
     *  \brief Neg() method
     *
     *  Changes the sign of value
     *
     *  \param no parameters
     *  \return pointer to LiEntiere (with value = 1 if true, value = 0 otherwise)
     */
    LiEntiere* Neg() { value = -value; return this; }

    /*!
     *  \brief DIV() method
     *
     *  Euclidean division (only between LiEntiere)
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale
     */
    Litterale* Div (const Litterale& li);

    /*!
     *  \brief MOD() method
     *
     *  Modulo method (only between LiEntiere)
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale
     */
    Litterale* Mod (const Litterale& li);

    /*!
     *  \brief NUM() method
     *
     *  Returns the numerator of a LiEntiere (so itself)
     *
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
	Litterale* Num() { return this; }

    /*!
     *  \brief DEN() method
     *
     *  Returns the numerator of a LiEntiere (LiEntiere(1))
     *
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
	Litterale* Den() { return new LiEntiere(1); }

    /*!
     *  \brief RE() method
     *
     *  Returns the real part of a LiEntiere (so itself)
     *
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
	Litterale* Re() { return this; }

    /*!
     *  \brief IM() method
     *
     *  Returns the imaginay part of a LiEntiere (LiEntiere(0))
     *
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
	Litterale* Im() { return new LiEntiere(0); }

    /*!
     *  \brief AND() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator and
     *
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* And(const Litterale* li);

    /*!
     *  \brief OR() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator or
     *
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Or(const Litterale* li);

    /*!
     *  \brief NOT() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator and
     *
     *
     *  \param no parameter
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Not();

    virtual Litterale* Clone() const {
             return new LiEntiere(*this);
    }
};






//////////////////////////////////////// LITTERALE RATIONNELLE ////////////////////////////////////////

/// \class The LiRationnelle class
///
/// \brief Class which inherits from LiNumerique
///
/// 2 attributs of type LiEntiere
/// used to represent the rationnal numbers in the calculator
///


class LiRationnelle : public LiNumerique {
    LiEntiere numerateur;  /*!< numerateur : attribut of type LiEntiere*/
    LiEntiere denominateur;  /*!< denominateur : attribut of type LiEntiere*/

public:

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiRationnelle class
     *
     *  \param without any parameters, numerateur will be initialize to 0 and denominateur to 1 (no division by 0)
     *
     */
	LiRationnelle() :numerateur(0), denominateur(1) {}

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiRationnelle class
     *  Call of the LiEntiere constructor
     *  Call of the simplification method to make an irreductible fraction
     *
     *  \param 2 parameters of type int to intialize numerator and denominator
     *
     */
	LiRationnelle(int n, int d):numerateur(n), denominateur(d) { simplification(); }

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiRationnelle class
     *  Call of the simplification method to make an irreductible fraction
     *
     *  \param 2 parameters (const references to LiEntiere) to intialize numerator and denominator
     *
     */
    LiRationnelle(const LiEntiere& n, const LiEntiere& d):numerateur(n), denominateur(d) { simplification(); }

    /*!
     *  \brief toString() method
     *
     *  Pure virtual method in Litterale, used in the afficher() method
     *  Method which takes numerator and denominator, transforms them into a string and returns them
     *
     *  \param no parameter
     *  \return string
     */
	string toString() const {stringstream ss; ss << numerateur.getValue() << "/" << denominateur.getValue(); return ss.str();}

    /*!
     *  \brief simplification() method
     *
     *  Method which transforms this fraction into an irreductible one
     *
     *  \param no parameter
     *  \return void
     */
    void simplification();

    /*!
     *  \brief isZero() method
     *
     *  Pure virtual method in Litterale, used to test if this LiRationnelle is 0
     *  A LiRationnal is 0 if its numerator is 0 (its denominator can't be 0)
     *
     *  \param no parameter
     *  \return bool
     */
    bool isZero() const { if(numerateur.getValue() == 0) return true; else return false;}

    /*!
     *  \brief getValue() method
     *
     *  Pure virtual method in Litterale
     *  Throws an error used on LiRationnelle (only on LiEntiere)
     *
     *  \param no parameter
     *  \return int
     */
	int getValue() const { throw LiException("error : pas de value dans une LiRationnelle"); }

    /*!
     *  \brief getNumerator() method
     *
     *  Pure virtual method in Litterale
     *  Returns the numerator's value
     *
     *  \param no parameter
     *  \return int
     */
	int getNumerateur() const { return numerateur.getValue(); }

    /*!
     *  \brief getNumerator() method
     *
     *  Pure virtual method in Litterale
     *  Returns the denominator's value
     *
     *  \param no parameter
     *  \return int
     */
	int getDenominateur() const { return denominateur.getValue(); }

    /*!
     *  \brief getReel() method
     *
     *  Pure virtual method in Litterale
     *  Throws an error used on LiRationnelle (only on LiReelle)
     *
     *  \param no parameter
     *  \return int
     */
    double getReel() const { throw LiException("error : pas de reel dans une LiRationnelle"); }

    /*!
     *  \brief overloaded operator+
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to add a LiRationnelle object and a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator+ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator-
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to substract to a LiRationnelle object a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator- (const Litterale& li) const;

    /*!
     *  \brief overloaded operator/
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to divide a LiRationnelle object by a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator/ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator*
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to multiply a LiRationnelle object and a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator* (const Litterale& li) const;

    /*!
     *  \brief overloaded operator==
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiRationnelle equals a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (LiEntiere(1) if true, LiEntiere(0) if false)
     */
	Litterale* operator== (const Litterale& li) const;

    /*!
     *  \brief overloaded operator!=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiRationnelle does not equal a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (LiEntiere(1) if true, LiEntiere(0) if false)
     */
	Litterale* operator!= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is less than or equals to a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator<= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator>=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is greater than or equals to a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator>= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is less than a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator< (const Litterale& li) const;

    /*!
     *  \brief overloaded operator>=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if a LiEntiere value is greater than a Litterale value
     *  const method (attribut sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator> (const Litterale& li) const;

    /*!
     *  \brief NEG() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Changes the sign of a LiRationnelle
     *  Calls the simplification method
     *
     *  \param 1 no parameters
     *  \return pointer to LiRationnelle
     */
    LiRationnelle* Neg() { numerateur.Neg(); simplification(); return this; }

    /*!
     *  \brief NUM() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Returns a pointer to the numerator
     *
     *  \param 1 no parameters
     *  \return pointer to Litterale
     */
	Litterale* Num() { return &numerateur; }

    /*!
     *  \brief DEN() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Returns a pointer to the denominator
     *
     *  \param 1 no parameters
     *  \return pointer to Litterale
     */
	Litterale* Den() { return &denominateur;}

    /*!
     *  \brief RE() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Returns a pointer to the real part of a LiRationnelle (so itself)
     *
     *  \param 1 no parameters
     *  \return pointer to Litterale
     */
	Litterale* Re() { return this; }

    /*!
     *  \brief IM() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Returns a pointer to the imaginary part of a LiRationnelle
     *  It does not have any so LiEntiere(0)
     *
     *  \param 1 no parameters
     *  \return pointer to Litterale
     */
	Litterale* Im() { return new LiEntiere(0); }

    /*!
     *  \brief AND() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator and
     *
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* And(const Litterale* li);

    /*!
     *  \brief OR() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator or
     *
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Or(const Litterale* li);

    /*!
     *  \brief NOT() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator not
     *
     *
     *  \param no parameter
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Not();


    Litterale* Clone() const {
             return new LiRationnelle(*this);
    }
};







//////////////////////////////////////// LITTERALE REELLE ////////////////////////////////////////

/// \class The LiReelle class
///
/// \brief Class which inherits from LiNumerique
///
/// 1 attribut of type double
/// used to represent the real numbers (nombres à virgule) in the calculator
///

class LiReelle : public LiNumerique {
    double value; /*!< value : attribut of type double*/
public:

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiReelle class
     *
     *  \param without any parameters, value will be initialize to 0
     *
     */
    LiReelle():value(0) {}

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiRationnelle class
     *
     *  \param 1 parameter of type dpouble to initialize value
     *
     */
	LiReelle(double v) :value(v) {}

    /*!
     *  \brief toString() method
     *
     *  Pure virtual method in Litterale, used in the afficher() method
     *  Method which takes value (of type double), transforms them into a string and returns them
     *
     *  \param no parameter
     *  \return string
     */
	string toString() const {stringstream ss; ss << value; return ss.str();}

    /*!
     *  \brief isZero() method
     *
     *  Pure virtual method in Litterale, used to test if value = 0
     *
     *  \param no parameter
     *  \return bool
     */
    bool isZero() const { if(value == 0.) return true; else return false;}

    /*!
     *  \brief getValue() method
     *
     *  Pure virtual method in Litterale
     *  Used to get the value of a LiEntiere
     *  Throws an error used on LiReelle (can only e used on LiEntiere)
     *
     *  \param no parameter
     *  \return int
     */
	int getValue() const { throw LiException("error : pas de value dans une LiReelle"); }

    /*!
     *  \brief getNumerateur() method
     *
     *  Pure virtual method in Litterale
     *  Used to get the numerateur of a LiRationnelle
     *  Throws an error used on LiReelle (can only e used on LiRationnelle)
     *
     *  \param no parameter
     *  \return int
     */
	int getNumerateur() const { throw LiException("error : pas de numerateur dans une LiReelle"); }

    /*!
     *  \brief getDenominateur() method
     *
     *  Pure virtual method in Litterale
     *  Used to get the denominateur of a LiRationnelle
     *  Throws an error used on LiReelle (can only e used on LiRationnelle)
     *
     *  \param no parameter
     *  \return int
     */
	int getDenominateur() const { throw LiException("error : pas de denominateur dans une LiReelle"); }

    /*!
     *  \brief getDenominateur() method
     *
     *  Pure virtual method in Litterale
     *  Used to get the real part of a LiComplexe
     *  Throws an error used on LiReelle (can only e used on LiRationnelle)
     *
     *  \param no parameter
     *  \return int
     */
    double getReel() const { return value; }

    /*!
     *  \brief overloaded operator+
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to add a LiReelle object and a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator+ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator-
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to substract a LiReelle object and a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator- (const Litterale& li) const;

    /*!
     *  \brief overloaded operator/
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to divid a LiReelle object by a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator/ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator*
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to multiply a LiReelle object by a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator* (const Litterale& li) const;

    /*!
     *  \brief overloaded operator==
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if the value of a LiReelle equals the value of a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
	Litterale* operator== (const Litterale& li) const;

    /*!
     *  \brief overloaded operator!=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if the value of a LiReelle does not equal the value of a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator!= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if the value of a LiReelle is less than or equal to the value of a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator<= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator>=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if the value of a LiReelle is greater than or equal to the value of a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator>= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if the value of a LiReelle is less than the value of a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
	Litterale* operator< (const Litterale& li) const;

    /*!
     *  \brief overloaded operator>
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to test if the value of a LiReelle is greater than the value of a Litterale
     *  const method (attributs sould not be modified)
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator> (const Litterale& li) const;

    /*!
     *  \brief NEG() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Used to change the sign of value
     *
     *  \param no parameter
     *  \return pointer to LiReelle
     */
	LiReelle* Neg() { value = -value; return this; }

    /*!
     *  \brief NUM() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an error used on a Lireelle (can only be used on LiRationnelle to return the numerator)
     *
     *  \param no
     *  \return pointer to Litterale
     */
	Litterale* Num() { throw LiException("Error : LiReelle pas de num"); }

    /*!
     *  \brief DEN() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an error used on a Lireelle (can only be used on LiRationnelle to return the denominator)
     *
     *  \param no
     *  \return pointer to Litterale
     */
	Litterale* Den() { throw LiException("Error : LiReelle pas de den"); }

    /*!
     *  \brief RE() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an error used on a Lireelle (can only be used on LiComplexe to return the real part)
     *
     *  \param no
     *  \return pointer to Litterale
     */
	Litterale* Re() { return this; }

    /*!
     *  \brief RE() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an error used on a Lireelle (can only be used on LiComplexe to return the imaginary part)
     *
     *  \param no
     *  \return pointer to Litterale
     */
	Litterale* Im() { return new LiEntiere(0); }

    /*!
     *  \brief AND() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator and
     *
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* And(const Litterale* li);

    /*!
     *  \brief OR() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator or
     *
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Or(const Litterale* li);

    /*!
     *  \brief NOT() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Logic operator not
     *
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Not();



    Litterale* Clone() const {
             return new LiReelle(*this);
    }
};





//////////////////////////////////////// LITTERALE COMPLEXE ////////////////////////////////////////


class LiComplexe : public Litterale {
	LiNumerique* re;
	LiNumerique* im;
public:
	LiComplexe(LiNumerique* r, LiNumerique* i);
	LiComplexe(const LiComplexe& lc);
	LiComplexe& operator=(const LiComplexe& lc);
	~LiComplexe() { delete re; delete im; }

	string toString() const;
    bool isZero() const { return (re->isZero() && im->isZero()); }

	LiNumerique& getReelle() const { return *re; }
	LiNumerique& getImage() const { return *im; }

	Litterale* operator+ (const Litterale& li) const;
	Litterale* operator- (const Litterale& li) const;
	Litterale* operator/ (const Litterale& li) const;
	Litterale* operator* (const Litterale& li) const;
	Litterale* operator== (const Litterale& li) const;
	Litterale* operator!= (const Litterale& li) const;
	Litterale* operator<= (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	Litterale* operator>= (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	Litterale* operator< (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	Litterale* operator> (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	//LiComplexe& operator= (Litterale& li);
    LiComplexe* Neg() { re->Neg(); return this; }
	Litterale* Num() { throw LiException("Error : LiComplexe pas de num"); }
	Litterale* Den() { throw LiException("Error : LiComplexe pas de den"); }
	Litterale* Re() { return re; }
	Litterale* Im() { return im; }
	Litterale* Div(const Litterale& li) { throw LiException("Error : pas de DIV entre LiComplexes"); }
	Litterale* Mod(const Litterale& li) { throw LiException("Error : pas de MOD entre LiComplexes"); }
    Litterale* And(const Litterale* li);
    Litterale* Or(const Litterale* li);
    Litterale* Not();
    Litterale* Clone() const {
        LiNumerique* r = dynamic_cast<LiNumerique*>(re->Clone());
        LiNumerique* i = dynamic_cast<LiNumerique*>(im->Clone());
        return new LiComplexe(r, i);
    }
};





#endif // LITTERALE_H_INCLUDED

