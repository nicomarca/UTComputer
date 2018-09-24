/**
 * \file lireelle.cpp
 * \brief file where the methods of the LiReelle class are defined
 *
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */


#include"liexpression.h"

//////////////////////////////////////// LITTERALE REELLE ////////////////////////////////////////



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
Litterale* LiReelle::operator+ (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        return new LiReelle(getReel() + li.getValue());

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getReel() + li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getReel() + li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiReelle l1 ((getReel() * li.getDenominateur() + li.getNumerateur()) / li.getDenominateur());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle((getReel() * li.getDenominateur() + li.getNumerateur()) / li.getDenominateur());
    }

    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& x = dynamic_cast<const Litterale&>(*this);
        const Litterale& a = dynamic_cast<const Litterale&>(lc1.getReelle());

        Litterale* resxa = x + a;

        LiNumerique* lin;

        lin = dynamic_cast<LiNumerique*>(resxa);
        return new LiComplexe(lin, &lc1.getImage());
        delete resxa;
    }
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")+(" % tmp.getExpression() % ")");
    }
}


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
Litterale* LiReelle::operator- (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        return new LiReelle(getReel() - li.getValue());

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getReel() - li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getReel() - li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiReelle l1 ((getReel() * li.getDenominateur() - li.getNumerateur()) / li.getDenominateur());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle((getReel() * li.getDenominateur() - li.getNumerateur()) / li.getDenominateur());
    }

    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& x = dynamic_cast<const Litterale&>(*this);
        const Litterale& a = dynamic_cast<const Litterale&>(lc1.getReelle());

        Litterale* resxa = x - a;

        LiNumerique* lin;

        lin = dynamic_cast<LiNumerique*>(resxa);
        return new LiComplexe(lin, &lc1.getImage());
        delete resxa;
    }
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")-(" % tmp.getExpression() % ")");
    }
}


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
Litterale* LiReelle::operator/ (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        return new LiReelle(getReel() / li.getValue());

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getReel() / li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getReel() / li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiReelle l1 ((getReel() * li.getDenominateur()) / li.getNumerateur());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle((getReel() * li.getDenominateur()) / li.getNumerateur());
    }

    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& x = dynamic_cast<const Litterale&>(*this);
        const Litterale& a = dynamic_cast<const Litterale&>(lc1.getReelle());
        const Litterale& b = dynamic_cast<const Litterale&>(lc1.getImage());

        Litterale* resxa = x * a;
        Litterale* resxb = x * b; resxb = resxb->Neg();
        Litterale* resa2 = a * a;
        Litterale* resb2 = b * b;
        Litterale* resa2b2 = *resa2 + *resb2;
        Litterale* resf1 = *resxa / *resa2b2;
        Litterale* resf2 = *resxb / *resa2b2;

        LiNumerique* lin;
        LiNumerique* lin2;

        lin = dynamic_cast<LiNumerique*>(resf1);
        lin2 = dynamic_cast<LiNumerique*>(resf2);

        if (lin2->isZero()) {
            if (typeid(*lin) == typeid(LiEntiere)) return new LiEntiere(lin->getValue());
            if (typeid(*lin) == typeid(LiReelle)) return new LiReelle(lin->getReel());
            if (typeid(*lin) == typeid(LiRationnelle)) return new LiRationnelle(lin->getNumerateur(),lin->getDenominateur());
        }
        else {
            return new LiComplexe(lin, lin2);
        }
        delete resxa; delete resxb; delete resa2; delete resb2;
        delete resa2b2; delete resf1; delete resf2;
    }
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")/(" % tmp.getExpression() % ")");
    }
}


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
Litterale* LiReelle::operator* (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        return new LiReelle(getReel() * li.getValue());

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getReel() * li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getReel() * li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiReelle l1 (getReel() * li.getNumerateur() / li.getDenominateur());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getReel() * li.getNumerateur() / li.getDenominateur());
    }

    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& x = dynamic_cast<const Litterale&>(*this);
        const Litterale& a = dynamic_cast<const Litterale&>(lc1.getReelle());
        const Litterale& b = dynamic_cast<const Litterale&>(lc1.getImage());

        Litterale* resxa = x * a;
        Litterale* resxb = x * b;

        LiNumerique* lin;
        LiNumerique* lin2;

        lin = dynamic_cast<LiNumerique*>(resxa);
        lin2 = dynamic_cast<LiNumerique*>(resxb);

        if (lin2->isZero()) {
            if (typeid(*lin) == typeid(LiEntiere)) return new LiEntiere(lin->getValue());
            if (typeid(*lin) == typeid(LiReelle)) return new LiReelle(lin->getReel());
            if (typeid(*lin) == typeid(LiRationnelle)) return new LiRationnelle(lin->getNumerateur(),lin->getDenominateur());
        }
        else {
            return new LiComplexe(lin, lin2);
        }
        delete resxa; delete resxb;
    }
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")*(" % tmp.getExpression() % ")");
    }
}



/*!
 *  \brief overloaded operator==
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Used to test if the value of a LiReelle equals the value of a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
 */
Litterale* LiReelle::operator== (const Litterale& li) const {
    Litterale* newli;
    if (typeid(li) == typeid(LiEntiere))
        if (getReel() == li.getValue()) {
            LiEntiere* l1 = new LiEntiere(1);
            newli = l1;
            return newli;
        }
    if (typeid(li) == typeid(LiReelle))
        if (getReel() == li.getReel()) {
            LiEntiere* l1 = new LiEntiere(1);
            newli = l1;
            return newli;
        }
    if (typeid(li) == typeid(LiRationnelle))
        if (getReel() == ((double)li.getNumerateur() / (double)li.getDenominateur())) {
            LiEntiere* l1 = new LiEntiere(1);
            newli = l1;
            return newli;
        }
    LiEntiere* l1 = new LiEntiere(0);
    newli = l1;
    return newli;
}


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
Litterale* LiReelle::operator!= (const Litterale& li) const {
    Litterale* newli;
    if (typeid(li) == typeid(LiEntiere))
        if (getReel() == li.getValue()) {
            LiEntiere* l1 = new LiEntiere(0);
            newli = l1;
            return newli;
        }
    if (typeid(li) == typeid(LiReelle))
        if (getReel() == li.getReel()) {
            LiEntiere* l1 = new LiEntiere(0);
            newli = l1;
            return newli;
        }
    if (typeid(li) == typeid(LiRationnelle))
        if (getReel() == ((double)li.getNumerateur() / (double)li.getDenominateur())) {
            LiEntiere* l1 = new LiEntiere(0);
            newli = l1;
            return newli;
        }
    LiEntiere* l1 = new LiEntiere(1);
    newli = l1;
    return newli;
}


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
Litterale* LiReelle::operator<= (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getReel() <= li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getReel() <= li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getReel() <= ((double)li.getNumerateur() / (double)li.getDenominateur()))
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiComplexe))
        throw LiException("error : pas de comparaison avec LiComplexe");
    return new LiEntiere(0);
}


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
Litterale* LiReelle::operator>= (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getReel() >= li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getReel() >= li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getReel() >= ((double)li.getNumerateur() / (double)li.getDenominateur()))
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiComplexe))
        throw LiException("error : pas de comparaison avec LiComplexe");
    return new LiEntiere(0);
}


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
Litterale* LiReelle::operator< (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getReel() < li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getReel() < li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getReel() < ((double)li.getNumerateur() / (double)li.getDenominateur()))
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiComplexe))
        throw LiException("error : pas de comparaison avec LiComplexe");
    return new LiEntiere(0);
}


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
Litterale* LiReelle::operator> (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getReel() > li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getReel() > li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getReel() > ((double)li.getNumerateur() / (double)li.getDenominateur()))
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiComplexe))
        throw LiException("error : pas de comparaison avec LiComplexe");
    return new LiEntiere(0);
}


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
Litterale* LiReelle::And(const Litterale* li) {
    if(isZero() || li->isZero())
        return new LiEntiere(0);
    return new LiEntiere(1);
}


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
Litterale* LiReelle::Or(const Litterale* li) {
    if(isZero() && li->isZero())
        return new LiEntiere(0);
    return new LiEntiere(1);
}


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
Litterale* LiReelle::Not() {
    if(isZero())
        return new LiEntiere(1);
    return new LiEntiere(0);
}
