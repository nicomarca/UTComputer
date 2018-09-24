#ifndef LICOMPLEXE_H
#define LICOMPLEXE_H

/**
 * \file licomplexe.h
 * \brief file where the class LiComplexe is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "lirationnelle.h"



//////////////////////////////////////// LITTERALE COMPLEXE ////////////////////////////////////////

/// \class The LiComplexe class
///
/// \brief Class which inherits from LiNumerique
///
/// 2 attributes of type pointer to LiNumerique.
/// The real and the imaginary part of a LiComplexe can either be a LiEntiere, a LiReelle or a LiRationnelle.
/// used to represent the complexe objects in the calculator.
///


class LiComplexe : public Litterale {
    LiNumerique* re; /*!< re : attribute of type LiNumerique* : the real part of LiComplexe can be  LiEntiere, LiReelle or LiRationnelle*/
    LiNumerique* im; /*!< im : attribute of type LiNumerique* : the imaginary part of LiComplexe can be  LiEntiere, LiReelle or LiRationnelle*/
public:

    /*!
     *  \brief Constructor
     *
     *  \param 2 parameters of type LiNumerique*, to initialize the real and the imaginary part
     *
     */
    LiComplexe(LiNumerique* r, LiNumerique* i);

    /*!
     *  \brief Copy Constructor
     *
     *  \param 1 parameter of type const LiComplexe& (needed because the attributs are pointers to LiNumerique*
     *
     */
    LiComplexe(const LiComplexe& lc);

    /*!
     *  \brief Assignment operator (operator=)
     *
     *  \param 1 parameter of type const LiComplexe& (needed because the attributs are pointers to LiNumerique*
     *
     */
    LiComplexe& operator=(const LiComplexe& lc);

    /*!
     *  \brief Destructor
     *
     *  Destructor of the LiComplexe class
     *  Inline Method
     *
     *  \param 1 no parameters
     *  Delete the attributes that are allocated dynamically
     *
     */
    ~LiComplexe() { delete re; delete im; }

    /*!
     *  \brief toString() method
     *
     *  \param no parameter
     *  \return string
     */
    string toString() const;

    /*!
     *  \brief isZero() method
     *
     *  Pure virtual method in Litterale, used to test if re and im are equal to 0
     *  Use the isZero mehtods defined in the other classes
     *  Inline Method
     *
     *  \param no parameter
     *  \return bool
     */
    bool isZero() const { return (re->isZero() && im->isZero()); }

    /*!
     *  \brief getReelle() method
     *
     *  Accessor to the real part of a LiComplexe
     *  Inline Method
     *
     *  \param no parameter
     *  \return reference to LiNumerique
     */
    LiNumerique& getReelle() const { return *re; }

    /*!
     *  \brief getReelle() method
     *
     *  Accessor to the imaginary part of a LiComplexe
     *  Inline Method
     *
     *  \param no parameter
     *  \return reference to LiNumerique
     */
    LiNumerique& getImage() const { return *im; }

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
     *  \return pointer to Litterale  (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator== (const Litterale& li) const;

    /*!
     *  \brief overloaded operator!=
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale  (with value = 1 if true, value = 0 otherwise)
     */
    Litterale* operator!= (const Litterale& li) const;

    /*!
     *  \brief overloaded operator<=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an exception : can't compare complexes
     *  Inline Method
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator<= (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }

    /*!
     *  \brief overloaded operator>=
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an exception : can't compare complexes
     *  Inline Method
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator>= (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }

    /*!
     *  \brief overloaded operator<
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an exception : can't compare complexes
     *  Inline Method
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator< (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }

    /*!
     *  \brief overloaded operator>
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Throws an exception : can't compare complexes
     *  Inline Method
     *
     *  \param 1 parameter of type const Litterale&
     *  \return pointer to Litterale
     */
    Litterale* operator> (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }

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
    LiComplexe* Neg() { re->Neg(); return this; }

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
    Litterale* Num() { throw LiException("Error : LiComplexe pas de num"); }

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
    Litterale* Den() { throw LiException("Error : LiComplexe pas de den"); }

    /*!
     *  \brief RE() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Accessor to the real part of a LiComplexe
     *  Inline Method
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    Litterale* Re() { return re; }

    /*!
     *  \brief IM() method
     *
     *  Method which was defined in Litterale (pure virtual)
     *  Accessor to the imaginary part of a LiComplexe
     *  Inline Method
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    Litterale* Im() { return im; }

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
     *  \param no paramter
     *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
     */
    Litterale* Not();
    Litterale* Clone() const {
        LiNumerique* r = dynamic_cast<LiNumerique*>(re->Clone());
        LiNumerique* i = dynamic_cast<LiNumerique*>(im->Clone());
        return new LiComplexe(r, i);
    }
};


#endif // LICOMPLEXE_H
