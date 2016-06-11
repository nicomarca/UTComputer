#include"liexpression.h"

//////////////////////////////////////// LITTERALE ENTIERE ////////////////////////////////////////


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
Litterale* LiEntiere::operator+ (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        return new LiEntiere(getValue() + li.getValue());

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getValue() + li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getValue() + li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(li.getDenominateur() * getValue() + li.getNumerateur(), li.getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
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
 *  Used to substract to a LiEntiere object a Litterale
 *  const method (attribut sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiEntiere::operator- (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        return new LiEntiere(getValue() - li.getValue());

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getValue() - li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getValue() - li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(li.getDenominateur() * getValue() - li.getNumerateur(), li.getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
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
 *  Used to divide a LiEntiere by a Litterale
 *  const method (attribut sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiEntiere::operator/ (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere)) {
        if (getValue() % li.getValue() == 0)
            return new LiEntiere(getValue() / li.getValue());
        return new LiRationnelle(getValue(), li.getValue());
    }

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getValue() / li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getValue() / li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(li.getDenominateur() * getValue(), li.getNumerateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
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
 *  Used to multiply to a LiEntiere object a Litterale oject
 *  const method (attribut sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiEntiere::operator* (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        return new LiEntiere(getValue()*li.getValue());

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getValue() * li.getReel());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getValue() * li.getReel());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(li.getNumerateur() * getValue(), li.getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
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
 *  Used to test if a LiEntiere equals a Litterale
 *  const method (attribut sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to LiEntiere (with value = 1 if true, value = 0 otherwise)
 */
LiEntiere* LiEntiere::operator== (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        if(getValue() == li.getValue())
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiReelle))
        if (getValue() == li.getReel())
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiRationnelle))
        if (getValue() == li.getNumerateur() && li.getDenominateur() == 1)
            return new LiEntiere(1);
    return new LiEntiere(0);
}


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
LiEntiere* LiEntiere::operator!= (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere))
        if(getValue() == li.getValue())
            return new LiEntiere(0);
    if (typeid(li) == typeid(LiReelle))
        if (getValue() == li.getReel())
            return new LiEntiere(0);
    if (typeid(li) == typeid(LiRationnelle))
            return new LiEntiere(1);
    return new LiEntiere(1);
}


/*!
 *  \brief DIV() method
 *
 *  Euclidean division (only between LiEntiere)
 *  Throws an error if parameter not of type LiEntiere
 *
 *  \param const reference to Litterale
 *  \return pointer to Litterale
 */
Litterale* LiEntiere::Div(const Litterale& li) {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& liexp = dynamic_cast<const LiExpression&>(li);
        QString qs1 = QString::fromStdString(toString());
        return new LiExpression("DIV(" % qs1 % "," % liexp.getExpression() % ")");
    }
    else {
        if (typeid(li) != typeid(LiEntiere)) throw LiException("Error : DIV uniquement entre LiEntiere");
        else return new LiEntiere(getValue() / li.getValue());
    }
}


/*!
 *  \brief MOD() method
 *
 *  Modulo method (only between LiEntiere)
 *  Throws an error if parameter not of type LiEntiere
 *
 *  \param const reference to Litterale
 *  \return pointer to Litterale
 */
Litterale* LiEntiere::Mod(const Litterale& li) {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& liexp = dynamic_cast<const LiExpression&>(li);
        QString qs1 = QString::fromStdString(toString());
        return new LiExpression("MOD(" % qs1 % "," % liexp.getExpression() % ")");
    }
    else {
        if (typeid(li) != typeid(LiEntiere)) throw LiException("Error : Mod uniquement entre LiEntiere");
        else return new LiEntiere(getValue() % li.getValue());
    }
}


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
Litterale* LiEntiere::operator<= (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getValue() <= li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getValue() <= li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getValue() <= ((double)li.getNumerateur() / (double)li.getDenominateur()))
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiComplexe))
        throw LiException("error : pas de comparaison avec LiComplexe");
    return new LiEntiere(0);
}


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
Litterale* LiEntiere::operator>= (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getValue() >= li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getValue() >= li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getValue() >= ((double)li.getNumerateur() / (double)li.getDenominateur()))
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiComplexe))
        throw LiException("error : pas de comparaison avec LiComplexe");
    return new LiEntiere(0);
}


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
Litterale* LiEntiere::operator< (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getValue() < li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getValue() < li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getValue() < ((double)li.getNumerateur() / (double)li.getDenominateur()))
            return new LiEntiere(1);
    if (typeid(li) == typeid(LiComplexe))
        throw LiException("error : pas de comparaison avec LiComplexe");
    return new LiEntiere(0);
}


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
Litterale* LiEntiere::operator> (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if(getValue() > li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if(getValue() > li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if(getValue() > ((double)li.getNumerateur() / (double)li.getDenominateur()))
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
 *  Use the isZero() method
 *
 *
 *  \param const reference to Litterale
 *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
 */
Litterale* LiEntiere::And(const Litterale* li) {
    if(isZero() || li->isZero())
        return new LiEntiere(0);
    return new LiEntiere(1);
}


/*!
 *  \brief OR() method
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Logic operator or
 *  Use the isZero() method
 *
 *  \param const reference to Litterale
 *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
 */
Litterale* LiEntiere::Or(const Litterale* li) {
    if(isZero() && li->isZero())
        return new LiEntiere(0);
    return new LiEntiere(1);
}


/*!
 *  \brief NOT() method
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Logic operator and
 *  Use the isZero() method
 *
 *
 *  \param no parameter
 *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
 */
Litterale* LiEntiere::Not() {
    if(isZero())
        return new LiEntiere(1);
    return new LiEntiere(0);
}
