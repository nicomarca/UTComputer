#ifndef LIRATIONNELLE_H
#define LIRATIONNELLE_H

/**
 * \file lirationnelle.h
 * \brief file where the class LiRationnelle is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */


#include "lireelle.h"

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
     *  Inline Method
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
     *  Inline Method
     *
     *  \param 2 parameters of type int to intialize numerator and denominator
     *
     */
    LiRationnelle(int n, int d):numerateur(n), denominateur(d) { simplification(); }

    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiRationnelle class
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
     *
     *  \param no parameter
     *  \return bool
     */
    bool isZero() const { if(numerateur.getValue() == 0) return true; else return false;}

    /*!
     *  \brief getValue() method
     *
     *  Pure virtual method in Litterale
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
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
     *  Inline Method
     *  Throws an error used on LiRationnelle (only on LiReelle)
     *
     *  \param no parameter
     *  \return int
     */
    double getReel() const { throw LiException("error : pas de reel dans une LiRationnelle"); }

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
     *  \return pointer to Litterale (LiEntiere(1) if true, LiEntiere(0) if false)
     */
    Litterale* operator== (const Litterale& li) const;

    /*!
     *  \brief overloaded operator!=
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale (LiEntiere(1) if true, LiEntiere(0) if false)
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
     *  Inline Method which was defined in Litterale (pure virtual)
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
     *  Inline Method which was defined in Litterale (pure virtual)
     *  Returns a pointer to the numerator
     *
     *  \param 1 no parameters
     *  \return pointer to Litterale
     */
    Litterale* Num() { return &numerateur; }

    /*!
     *  \brief DEN() method
     *
     *  Inline Method which was defined in Litterale (pure virtual)
     *  Returns a pointer to the denominator
     *
     *  \param 1 no parameters
     *  \return pointer to Litterale
     */
    Litterale* Den() { return &denominateur;}

    /*!
     *  \brief RE() method
     *
     *  Inline Method which was defined in Litterale (pure virtual)
     *  Returns a pointer to the real part of a LiRationnelle (so itself)
     *
     *  \param 1 no parameters
     *  \return pointer to Litterale
     */
    Litterale* Re() { return this; }

    /*!
     *  \brief IM() method
     *
     *  Inline Method which was defined in Litterale (pure virtual)
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
     *  \param no parameter
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Not();


    Litterale* Clone() const {
             return new LiRationnelle(*this);
    }
};

#endif // LIRATIONNELLE_H
