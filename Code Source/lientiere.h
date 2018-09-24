#ifndef LIENTIERE_H
#define LIENTIERE_H

/**
 * \file lientiere.h
 * \brief file where the class LiEntiere is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "linumerique.h"




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
     *  Inline Method
     *
     *  \param without any parameters, value will be initialize to 0.
     */
    LiEntiere():value(0) {}

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiEntiere class
     *  Inline Method
     *
     *  \param with one parameter of type int to initialize value
     */
    LiEntiere(int v=0):value(v) {}

    /*!
     *  \brief toString() method
     *
     *  Method which takes value (integer) transforms it into a string and returns it
     *  Pure virtual method in Litterale, used in the afficher() method
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
     *
     *  \param no parameter
     *  \return integer
     */
    int getValue() const { return value; }

    /*!
     *  \brief setValue() method
     *
     *  Method to set a new value to the attribut
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
     *
     *  \param no parameters
     *  \return pointer to LiEntiere (with value = 1 if true, value = 0 otherwise)
     */
    LiEntiere* Neg() { value = -value; return this; }

    /*!
     *  \brief DIV() method
     *
     *  Division euclidienne (only between LiEntiere)
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
     *  Inline Method
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    Litterale* Num() { return this; }

    /*!
     *  \brief DEN() method
     *
     *  Returns the numerator of a LiEntiere (LiEntiere(1))
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
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

    Litterale* Clone() const {
             return new LiEntiere(*this);
    }
};




#endif
