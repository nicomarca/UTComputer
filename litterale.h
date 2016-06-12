#ifndef LITTERALE_H_INCLUDED
#define LITTERALE_H_INCLUDED

/**
 * \file litterale.h
 * \brief file where the class LiRationnelle is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "liexception.h"



//////////////////////////////////////// LITTERALE ////////////////////////////////////////

/// \class The Litterale class
///
/// \brief Abstract class from which inherits all the other litterale class (LiNumerique and LiComplexe)
///
/// No attributes but pure virtual methods which will be defined in the inherited classes
///


class Litterale {
public:

    /*!
     *  \brief Destructor
     *
     *  Virtual method (because of the LiComplexe class)
     *  When a Litterale object which points to a LiComplexe object is deleted, the destructor of the LiComplexe class needs to be called
     *
     */
    virtual ~Litterale() {}

    /*!
     *  \brief toString() method
     *
     *  Pure virtual method used in the afficher() method
     *  This method have to be defined in the inherited classes
     *
     *  \param no parameter
     *  \return string
     */
    virtual string toString() const = 0;

    /*!
     *  \brief isZero() method
     *
     *  Pure virtual method
     *  Used to inform us if a the attributs of a class are 0
     *  This method have to be defined in the inherited classes
     *
     *  \param no parameter
     *  \return bool
     */
    virtual bool isZero() const = 0;

    /*!
     *  \brief afficher() method
     *
     *  const method used to print the different Litterale
     *  Call the toString() method
     *
     *  \param 1 parameter of type ostream& (default : cout)
     *  \return void
     */
    void afficher (ostream& f=cout) const { f << toString() << "\n"; }

    /*!
     *  \brief getValue() method
     *
     *  Virtual method
     *  Accessor for the LiEntiere class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return int
     */
    virtual int getValue() const { return 1; }

    /*!
     *  \brief getNumerator() method
     *
     *  Virtual method
     *  Accessor for the LiRationnelle class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return int
     */
    virtual int getNumerateur() const{ return 1; }

    /*!
     *  \brief getDenominator() method
     *
     *  Virtual method
     *  Accessor for the LiRationnelle class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return int
     */
    virtual int getDenominateur() const { return 1; }

    /*!
     *  \brief getReel() method
     *
     *  Virtual method
     *  Accessor for the LiReelle class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return double
     */
    virtual double getReel() const { return 1; }

    /*!
     *  \brief operator+
     *
     *  Pure virtual method
     *  Const method (object sould not be modified)
     *  overload of the operator +
     *  Used to add 2 litterales
     *
     *  \param const reference to Litterale (parameter sould not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator+ (const Litterale& li) const = 0;

    /*!
     *  \brief operator-
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator -
     *  Used to substract 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator- (const Litterale& li) const = 0;

    /*!
     *  \brief operator/
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator /
     *  Used to divid 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator/ (const Litterale& li) const = 0;

    /*!
     *  \brief operator*
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator *
     *  Used to multiply 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator* (const Litterale& li) const = 0;

    /*!
     *  \brief operator==
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator ==
     *  Used to test if 2 litterales are equal
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator== (const Litterale& li) const = 0;

    /*!
     *  \brief operator!=
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator !=
     *  Used to test if 2 litterales are not equal
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator!= (const Litterale& li) const = 0;

    /*!
     *  \brief operator<=
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator <=
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator<= (const Litterale& li) const = 0;

    /*!
     *  \brief operator>=
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator >=
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator>= (const Litterale& li) const = 0;

    /*!
     *  \brief operator<
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator <
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator< (const Litterale& li) const = 0;

    /*!
     *  \brief operator>
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator >
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator> (const Litterale& li) const = 0;

    /*!
     *  \brief NEG() method
     *
     *  Pure virtual method
     *  Changes the sign of the attributes of a Litterale
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
    virtual Litterale* Neg() = 0;

    /*!
     *  \brief NUM() method
     *
     *  Pure virtual method
     *  Accessor to the numerator of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
    virtual Litterale* Num() = 0;

    /*!
     *  \brief DEN() method
     *
     *  Pure virtual method
     *  Accessor to the denominator of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
    virtual Litterale* Den() = 0;

    /*!
     *  \brief RE() method
     *
     *  Pure virtual method
     *  Accessor to the real part of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
    virtual Litterale* Re() = 0;

    /*!
     *  \brief IM() method
     *
     *  Pure virtual method
     *  Accessor to the imaginary part of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
    virtual Litterale* Im() = 0;

    /*!
     *  \brief AND() method
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  Logic operator AND
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* And(const Litterale* li) = 0;

    /*!
     *  \brief OR() method
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  Logic operator OR
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* Or(const Litterale* li) = 0;

    /*!
     *  \brief NOT() method
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  Logic operator NOT
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    virtual Litterale* Not() = 0;
    virtual Litterale* Clone() const = 0;
};


#endif // LITTERALE_H_INCLUDED
