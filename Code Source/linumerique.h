#ifndef LINUMERIQUE_H
#define LINUMERIQUE_H

/**
 * \file linumerique.h
 * \brief file where the class LiNumerique is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */


#include "litterale.h"

using namespace std;



//////////////////////////////////////// LITTERALE NUMERIQUE ////////////////////////////////////////

/// \class The LiNumerique class
///
/// \brief abstract class which inherits from the abstract class Litterale
///
/// used to define liEntiere, LiReelle and LiRationnelle
/// no attributes
///
///

class LiNumerique : public Litterale {
public:
    virtual string toString() const = 0;
    virtual Litterale* Clone() const = 0;
};






#endif // LINUMERIQUE_H
