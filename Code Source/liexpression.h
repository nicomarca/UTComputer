#ifndef LIEXPRESSION_H
#define LIEXPRESSION_H

/**
 * \file liexpression.h
 * \brief file where the class LiExpression is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "licomplexe.h"


//////////////////////////////////////// EXPRESSION ////////////////////////////////////////

/// \class The LiExpression class
///
/// \brief Class which inherits from Litterale
///
/// Used to represent all the expression in the Calculator
///
///
class LiExpression : public Litterale {
    QString exp; /*!< exp : attribut of type QString (represent the expression)*/
public:
    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiExpression class
     *  Inline Method
     *
     *  \param 1 parameter of type QString to initialize exp
     */
    LiExpression(QString a):exp(a) {}

    /*!
     *  \brief getExpression() method
     *
     *  Accessor to the attribute of a LiExpression object
     *
     *  \param no parameter
     *  \return QString
     */
    QString getExpression() const {  return exp; }

    /*!
     *  \brief toString() method
     *
     *  Used to transform the attribute of type QString into a string
     *  This method was pure virtual in Litterale
     *  Inline Method
     *
     *  \param no parameter
     *  \return string
     */
    string toString()const { QString tmp; tmp = "'" % exp % "'"; return tmp.toStdString(); }

    /*!
     *  \brief isZero() method
     *
     *  Used to inform us if the attribut is empty or not.
     *  This method was pure virtual in Litterale
     *  Inline Method
     *
     *  \param no parameter
     *  \return bool
     */
    bool isZero() const { return exp.toStdString() == ""; }

    /*!
     *  \brief enleverGuillemets() method
     *
     *  Static method (it will be needed in other classes)
     *  Used to detached the quotation marks
     *  When a user wants to put an expression into the calculator, he has to put it between quotations marks
     *  Then the expression will be evaluated
     *
     *  \param const QString&
     *  \return pointer to LiExpression
     */
    static LiExpression* enleverGuillemets(const QString& s);

    /*!
     *  \brief getValue() method
     *
     *  Accessor of the LiEntiere class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiEntiere)
     *
     *  \param no parameter
     *  \return int
     */
    int getValue() const { throw LiException("error : pas de getValue sur une Expression"); }

    /*!
     *  \brief getNumerator() method
     *
     *  Accessor of the LiRationnelle class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiRationnelle)
     *
     *  \param no parameter
     *  \return int
     */
    int getNumerateur() const { throw LiException("error : pas de getNumerateur sur une Expression"); }

    /*!
     *  \brief getDenominator() method
     *
     *  Accessor of the LiRationnelle class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiRationnelle)
     *
     *  \param no parameter
     *  \return int
     */
    int getDenominateur() const { throw LiException("error : pas de getDenominateur sur une Expression"); }

    /*!
     *  \brief getReel() method
     *
     *  Accessor of the LiReelle class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiRationnelle)
     *
     *  \param no parameter
     *  \return double
     */
    double getReel() const { throw LiException("error : pas de getReel sur un atome"); }

    /*!
     *  \brief operator+
     *
     *  Overloaded operator+
     *  const method (attribut should not be modified)
     *  Used to add a LiExpression and a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
    Litterale* operator+ (const Litterale& li) const;

    /*!
     *  \brief operator-
     *
     *  Overloaded operator-
     *  const method (attribut should not be modified)
     *  Used to substract to a LiExpression a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
    Litterale* operator- (const Litterale& li) const;

    /*!
     *  \brief operator/
     *
     *  Overloaded operator/
     *  const method (attribut should not be modified)
     *  Used to divid a LiExpression by a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
    Litterale* operator/ (const Litterale& li) const;

    /*!
     *  \brief operator*
     *
     *  Overloaded operator*
     *  const method (attribut should not be modified)
     *  Used to multiply a LiExpression and a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
    Litterale* operator* (const Litterale& li) const;

    /*!
     *  \brief operator==
     *
     *  Overloaded operator==
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator== (const Litterale& li) const { throw LiException("error : pas de == sur une Expression"); }

    /*!
     *  \brief operator!=
     *
     *  Overloaded operator!=
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator!= (const Litterale& li) const { throw LiException("error : pas de != sur une Expression"); }

    /*!
     *  \brief operator<=
     *
     *  Overloaded operator<=
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator<= (const Litterale& li) const { throw LiException("error : pas de <= sur une Expression"); }

    /*!
     *  \brief operator>=
     *
     *  Overloaded operator>=
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator>= (const Litterale& li) const { throw LiException("error : pas de >= sur une Expression"); }

    /*!
     *  \brief operator<
     *
     *  Overloaded operator>
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator< (const Litterale& li) const { throw LiException("error : pas de < sur une Expression"); }

    /*!
     *  \brief operator>
     *
     *  Overloaded operator>
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator> (const Litterale& li) const { throw LiException("error : pas de > sur une Expression"); }

    /*!
     *  \brief NUM() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Num();

    /*!
     *  \brief DEN() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Den();

    /*!
     *  \brief RE() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Re();

    /*!
     *  \brief IM() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Im();

    /*!
     *  \brief NEG() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Neg();

    /*!
     *  \brief DIV() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Div(const Litterale& li);

    /*!
     *  \brief MOD() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Mod(const Litterale& li);

    /*!
     *  \brief AND() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* And(const Litterale* li);

    /*!
     *  \brief OR() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Or(const Litterale* li);

    /*!
     *  \brief NOT() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Not();

    Litterale* Clone() const { return new LiExpression(exp); }
};


#endif // LIEXPRESSION_H
