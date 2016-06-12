#ifndef LIREELLE_H
#define LIREELLE_H

/**
 * \file lireelle.h
 * \brief file where the class LiRationnelle is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include"lientiere.h"


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
     *  Inline Method
     *
     *  \param without any parameters, value will be initialize to 0
     *
     */
    LiReelle():value(0) {}

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiReelle class
     *  Inline Method
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
     *  Inline Method
     *
     *  \param no parameter
     *  \return string
     */
    string toString() const {stringstream ss; ss << value; return ss.str();}

    /*!
     *  \brief isZero() method
     *
     *  Pure virtual method in Litterale, used to test if value = 0
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
     *
     *  \param no parameter
     *  \return int
     */
    double getReel() const { return value; }

    /*!
     *  \brief overloaded operator+
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator+ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator-
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator- (const Litterale& li) const;

    /*!
     *  \brief overloaded operator/
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator/ (const Litterale& li) const;

    /*!
     *  \brief overloaded operator*
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator* (const Litterale& li) const;

    /*!
     *  \brief overloaded operator==
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator== (const Litterale& li) const;

    /*!
     *  \brief overloaded operator!=
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator!= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<=
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator<= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator>=
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator>= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator< (const Litterale& li) const;

    /*!
     *  \brief overloaded operator>
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
     *  Inline Method
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
     *  Inline Method
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    Litterale* Num() { throw LiException("Error : LiReelle pas de num"); }

    /*!
     *  \brief DEN() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an error used on a Lireelle (can only be used on LiRationnelle to return the denominator)
     *  Inline Method
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    Litterale* Den() { throw LiException("Error : LiReelle pas de den"); }

    /*!
     *  \brief RE() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an error used on a Lireelle (can only be used on LiComplexe to return the real part)
     *  Inline Method
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    Litterale* Re() { return this; }

    /*!
     *  \brief RE() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an error used on a Lireelle (can only be used on LiComplexe to return the imaginary part)
     *  Inline Method
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    Litterale* Im() { return new LiEntiere(0); }

    /*!
     *  \brief AND() method
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* And(const Litterale* li);

    /*!
     *  \brief OR() method
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Or(const Litterale* li);

    /*!
     *  \brief NOT() method
     *
     *  \param const reference to Litterale
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Not();



    Litterale* Clone() const {
             return new LiReelle(*this);
    }
};



#endif // LIREELLE_H
