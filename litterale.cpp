
/**
 * \file litterale.h
 * \brief file all the methods of the different Litterale class are defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */




#include "litterale.h"




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








//////////////////////////////////////// LITTERALE RATIONNELLE ////////////////////////////////////////




/*!
 *  \brief simplification() method
 *
 *  Method which transforms this fraction into an irreductible one
 *  Use of the setValue method()
 *  Euclide algorithm : Find the greater commun divisor (gcd)
 *  Divide the numerator and the denominator by the gcd
 *
 *  \param no parameter
 *  \return void
 */
void LiRationnelle::simplification() {
    if (numerateur.getValue() == 0) { denominateur.setValue(1); return; } // si le numerateur est 0, le denominateur prend la valeur 1
    if (denominateur.getValue() == 0) return; /* un denominateur ne devrait pas être 0; si c’est le cas, on sort de la méthode */
    int a = numerateur.getValue(), b = denominateur.getValue(); /* utilisation de l’algorithme d’Euclide pour trouver le Plus Grand Commun Denominateur (PGCD) entre le numerateur et le denominateur */
    if (a<0) a = -a; if (b<0) b = -b; // on ne travaille qu’avec des valeurs positives...
    while (a != b) { if (a>b) a = a - b; else b = b - a; }
    numerateur.setValue(numerateur.getValue() / a); denominateur.setValue(denominateur.getValue() / a); // on divise le numerateur et le denominateur par le PGCD=a
    if (denominateur.getValue()<0) { numerateur.setValue(-denominateur.getValue()); denominateur.setValue(-numerateur.getValue()); } // si le denominateur est négatif, on fait passer le signe - au denominateur
}


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
Litterale* LiRationnelle::operator+ (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere)) {
        LiRationnelle newli(getDenominateur() * li.getValue() + getNumerateur(), getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
    }

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 ((getDenominateur()*li.getReel() + getNumerateur()) / getDenominateur());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle((getDenominateur()*li.getReel() + getNumerateur()) / getDenominateur());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(getNumerateur()*li.getDenominateur() + getDenominateur()*li.getNumerateur(), getDenominateur()*li.getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getDenominateur());
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
 *  Used to substract to a LiRationnelle object a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiRationnelle::operator- (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere)) {
        LiRationnelle newli(getDenominateur() * li.getValue() - getNumerateur(), getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
    }

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 ((getDenominateur()*li.getReel() - getNumerateur()) / getDenominateur());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle((getDenominateur()*li.getReel() - getNumerateur()) / getDenominateur());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(getNumerateur()*li.getDenominateur() - getDenominateur()*li.getNumerateur(), getDenominateur()*li.getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getDenominateur());
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
 *  Used to divide a LiRationnelle object by a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiRationnelle::operator/ (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere)) {
        LiRationnelle newli(getNumerateur(), getDenominateur()*li.getValue());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
    }

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 (getNumerateur() / (getDenominateur() * li.getReel()));
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle(getNumerateur() / (getDenominateur() * li.getReel()));
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(getNumerateur() * li.getDenominateur(), getDenominateur() * li.getNumerateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getDenominateur());
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
 *  Used to multiply a LiRationnelle object and a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiRationnelle::operator* (const Litterale& li) const {
    if (typeid(li) == typeid(LiEntiere)) {
        LiRationnelle newli(getNumerateur() * li.getValue(), getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getNumerateur());
        return new LiRationnelle(newli.getNumerateur(), newli.getDenominateur());
    }

    if (typeid(li) == typeid(LiReelle)) {
        LiReelle l1 ((getNumerateur() * li.getReel()) / getDenominateur());
        if ( l1.getReel() - floor(l1.getReel()) == 0) return new LiEntiere(l1.getReel());
        return new LiReelle((getNumerateur() * li.getReel()) / getDenominateur());
    }

    if (typeid(li) == typeid(LiRationnelle)) {
        LiRationnelle newli(getNumerateur() * li.getNumerateur(), getDenominateur() * li.getDenominateur());
        if (newli.getDenominateur() == 1)
            return new LiEntiere(newli.getDenominateur());
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
 *  Used to test if a LiRationnelle equals a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale (LiEntiere(1) if true, LiEntiere(0) if false)
 */
Litterale* LiRationnelle::operator== (const Litterale& li) const {
    Litterale* newli;
    if (typeid(li) == typeid(LiEntiere))
        if (getNumerateur() == li.getValue() && getDenominateur() == 1) {
            LiEntiere* l1 = new LiEntiere(1);
            newli = l1;
            return newli;
        }
    if (typeid(li) == typeid(LiReelle))
        if ((getNumerateur() / getDenominateur()) == li.getReel()) {
            LiEntiere* l1 = new LiEntiere(1);
            newli = l1;
            return newli;
        }
    if (typeid(li) == typeid(LiRationnelle))
        if (li.getDenominateur() == getDenominateur() && li.getNumerateur() == getNumerateur()) {
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
 *  Used to test if a LiRationnelle does not equal a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale (LiEntiere(1) if true, LiEntiere(0) if false)
 */
Litterale* LiRationnelle::operator!= (const Litterale& li) const {
    Litterale* newli;
    if (typeid(li) == typeid(LiEntiere)) {
        LiEntiere* l1 = new LiEntiere(1);
        newli = l1;
        return newli;
    }
    if (typeid(li) == typeid(LiReelle))
        if ((getNumerateur() / getDenominateur()) == li.getReel()) {
            LiEntiere* l1 = new LiEntiere(0);
            newli = l1;
            return newli;
        }
    if (typeid(li) == typeid(LiRationnelle))
        if (li.getDenominateur() == getDenominateur() && li.getNumerateur() == getNumerateur()) {
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
 *  Used to test if a LiEntiere value is less than or equals to a Litterale value
 *  const method (attribut sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale (with value = 1 if true, value = 0 otherwise)
 */
Litterale* LiRationnelle::operator<= (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if (((double)getNumerateur() / (double)getDenominateur()) <= li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if (((double)getNumerateur() / (double)getDenominateur()) <= li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if (((double)getNumerateur() / (double)getDenominateur()) <= ((double)li.getNumerateur() / (double)li.getDenominateur()))
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
Litterale* LiRationnelle::operator>= (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if (((double)getNumerateur() / (double)getDenominateur()) >= li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if (((double)getNumerateur() / (double)getDenominateur()) >= li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if (((double)getNumerateur() / (double)getDenominateur()) >= ((double)li.getNumerateur() / (double)li.getDenominateur()))
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
Litterale* LiRationnelle::operator< (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if (((double)getNumerateur() / (double)getDenominateur()) < li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if (((double)getNumerateur() / (double)getDenominateur()) < li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if (((double)getNumerateur() / (double)getDenominateur()) < ((double)li.getNumerateur() / (double)li.getDenominateur()))
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
Litterale* LiRationnelle::operator> (const Litterale& li) const {
    if(typeid(li) == typeid(LiEntiere))
        if (((double)getNumerateur() / (double)getDenominateur()) > li.getValue())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiReelle))
        if (((double)getNumerateur() / (double)getDenominateur()) > li.getReel())
            return new LiEntiere(1);
    if(typeid(li) == typeid(LiRationnelle))
        if (((double)getNumerateur() / (double)getDenominateur()) > ((double)li.getNumerateur() / (double)li.getDenominateur()))
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
Litterale* LiRationnelle::And(const Litterale* li) {
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
Litterale* LiRationnelle::Or(const Litterale* li) {
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
 *  \param no parameter
 *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
 */
Litterale* LiRationnelle::Not() {
    if(isZero())
        return new LiEntiere(1);
    return new LiEntiere(0);
}








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










//////////////////////////////////////// LITTERALE COMPLEXE ////////////////////////////////////////


/*!
 *  \brief Constructor
 *
 *  Constructor of the LiComplexe class
 *  Needed because the attributes are pointers, so we have to make a copy
 *
 *  \param 2 parameters of type LiNumerique*, to initialize the real and the imaginary part
 *
 */
LiComplexe::LiComplexe(LiNumerique* r, LiNumerique* i) {

    if (typeid(*r) == typeid(LiEntiere)) re = new LiEntiere(r->getValue());
    if (typeid(*r) == typeid(LiReelle)) re = new LiReelle(r->getReel());
    if (typeid(*r) == typeid(LiRationnelle)) re = new LiRationnelle(r->getNumerateur(), r->getDenominateur());

    if (typeid(*i) == typeid(LiEntiere)) im = new LiEntiere(i->getValue());
    if (typeid(*i) == typeid(LiReelle)) im = new LiReelle(i->getReel());
    if (typeid(*i) == typeid(LiRationnelle)) im = new LiRationnelle(i->getNumerateur(), i->getDenominateur());

}

/*!
 *  \brief Copy Constructor
 *
 *  Copy Constructor of the LiComplexe class
 *  Needed ecause the attributes are pointers, so we have to make a copy
 *
 *  \param 1 parameter of type const LiComplexe&
 *
 */
LiComplexe::LiComplexe(const LiComplexe& lc):re(0), im(0) {
    if (typeid(lc.getReelle()) == typeid(LiEntiere)) re = new LiEntiere(lc.getReelle().getValue());
    if (typeid(lc.getReelle()) == typeid(LiReelle)) re = new LiReelle(lc.getReelle().getReel());
    if (typeid(lc.getReelle()) == typeid(LiRationnelle)) re = new LiRationnelle(lc.getReelle().getNumerateur(),lc.getReelle().getDenominateur());

    if (typeid(lc.getImage()) == typeid(LiEntiere)) im = new LiEntiere(lc.getImage().getValue());
    if (typeid(lc.getImage()) == typeid(LiReelle)) im = new LiReelle(lc.getImage().getReel());
    if (typeid(lc.getImage()) == typeid(LiRationnelle)) im = new LiRationnelle(lc.getImage().getNumerateur(),lc.getImage().getDenominateur());
}


/*!
 *  \brief Assignment operator (operator=)
 *
 *  Assignment operator of the LiComplexe class
 *  Needed ecause the attributes are pointers, so we have to make a copy
 *
 *  \param 1 parameter of type const LiComplexe&
 *
 */
LiComplexe& LiComplexe::operator=(const LiComplexe& lc) {
    if(re != 0) { delete re; re = 0; }
    if(im != 0) { delete im; im = 0; }
    if (typeid(lc.getReelle()) == typeid(LiEntiere)) re = new LiEntiere(lc.getReelle().getValue());
    if (typeid(lc.getReelle()) == typeid(LiReelle)) re = new LiReelle(lc.getReelle().getReel());
    if (typeid(lc.getReelle()) == typeid(LiRationnelle)) re = new LiRationnelle(lc.getReelle().getNumerateur(),lc.getReelle().getDenominateur());

    if (typeid(lc.getImage()) == typeid(LiEntiere)) im = new LiEntiere(lc.getImage().getValue());
    if (typeid(lc.getImage()) == typeid(LiReelle)) im = new LiReelle(lc.getImage().getReel());
    if (typeid(lc.getImage()) == typeid(LiRationnelle)) im = new LiRationnelle(lc.getImage().getNumerateur(),lc.getImage().getDenominateur());
    return *this;
}


/*!
 *  \brief overloaded operator+
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Used to add a LiComplexe object and a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiComplexe::operator+ (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")+(" % tmp.getExpression() % ")");
    }

    if (typeid(li) == typeid(LiComplexe)) {

        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& a1 = dynamic_cast<const Litterale&>(getReelle());
        const Litterale& b1 = dynamic_cast<const Litterale&>(getImage());
        const Litterale& a2 = dynamic_cast<const Litterale&>(lc1.getReelle());
        const Litterale& b2 = dynamic_cast<const Litterale&>(lc1.getImage());

        Litterale* resaa = a1 + a2;
        Litterale* resbb = b1 + b2;

        LiNumerique* lin;
        LiNumerique* lin2;

        lin = dynamic_cast<LiNumerique*>(resaa);
        lin2 = dynamic_cast<LiNumerique*>(resbb);

        if (lin2->isZero()) {
            if (typeid(*lin) == typeid(LiEntiere)) return new LiEntiere(lin->getValue());
            if (typeid(*lin) == typeid(LiReelle)) return new LiReelle(lin->getReel());
            if (typeid(*lin) == typeid(LiRationnelle)) return new LiRationnelle(lin->getNumerateur(),lin->getDenominateur());
        }
        else {
            return new LiComplexe(lin, lin2);
        }
        delete resaa; delete resbb;
    }

    Litterale& pt1 = getReelle();
    Litterale& pt2 = getImage();
    Litterale* lc1 = pt1 + li;
    LiNumerique* lc2 = dynamic_cast<LiNumerique*>(lc1);
    LiNumerique* lc3 = dynamic_cast<LiNumerique*>(&pt2);
    return new LiComplexe(lc2, lc3);

    delete lc1;
}


/*!
 *  \brief overloaded operator-
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Used to substract to a LiComplexe object a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiComplexe::operator- (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")-(" % tmp.getExpression() % ")");
    }

    if (typeid(li) == typeid(LiComplexe)) {

        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& a1 = dynamic_cast<const Litterale&>(getReelle());
        const Litterale& b1 = dynamic_cast<const Litterale&>(getImage());
        const Litterale& a2 = dynamic_cast<const Litterale&>(lc1.getReelle());
        const Litterale& b2 = dynamic_cast<const Litterale&>(lc1.getImage());

        Litterale* resaa = a1 - a2;
        Litterale* resbb = b1 - b2;

        LiNumerique* lin;
        LiNumerique* lin2;

        lin = dynamic_cast<LiNumerique*>(resaa);
        lin2 = dynamic_cast<LiNumerique*>(resbb);

        if (lin2->isZero()) {
            if (typeid(*lin) == typeid(LiEntiere)) return new LiEntiere(lin->getValue());
            if (typeid(*lin) == typeid(LiReelle)) return new LiReelle(lin->getReel());
            if (typeid(*lin) == typeid(LiRationnelle)) return new LiRationnelle(lin->getNumerateur(),lin->getDenominateur());
        }
        else {
            return new LiComplexe(lin, lin2);
        }
        delete resaa; delete resbb;
    }

    Litterale& pt1 = getReelle();
    Litterale& pt2 = getImage();
    Litterale* lc1 = pt1 - li;
    LiNumerique* lc2 = dynamic_cast<LiNumerique*>(lc1);
    LiNumerique* lc3 = dynamic_cast<LiNumerique*>(&pt2);
    return new LiComplexe(lc2, lc3);

    delete lc1;
}


/*!
 *  \brief overloaded operator/
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Used to divid a LiComplexe object and a Litterale
 *  const method (attributs sould not be modified)
 *  If the attribut is of type LiComplexe : multiplication by the conjugated
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiComplexe::operator/ (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")/(" % tmp.getExpression() % ")");
    }

    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& a1 = dynamic_cast<const Litterale&>(getReelle());
        const Litterale& b1 = dynamic_cast<const Litterale&>(getImage());
        const Litterale& a2 = dynamic_cast<const Litterale&>(lc1.getReelle());
        const Litterale& b2 = dynamic_cast<const Litterale&>(lc1.getImage());

        Litterale* resaa = a1 * a2;
        Litterale* resbb = b1 * b2;
        Litterale* resab = a1 * b2;
        Litterale* resba = b1 * a2;
        Litterale* resa22 = a2 * a2;
        Litterale* resb22 = b2 * b2;
        Litterale* resa22b22 = *resa22 + *resb22;
        Litterale* resaabb = *resaa + *resbb;
        Litterale* resbaab = *resba - *resab;
        Litterale* resf1 = *resaabb / *resa22b22;
        Litterale* resf2 = *resbaab / *resa22b22;

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
        delete resaa; delete resbb; delete resab; delete resba; delete resaabb; delete resbaab;
        delete resa22; delete resb22; delete resa22b22; delete resf1; delete resf2;
    }


    Litterale& pt1 = getReelle();
    Litterale& pt2 = getImage();
    Litterale* lc1 = pt1 / li;
    Litterale* lc4 = pt2 / li;
    LiNumerique* lc2 = dynamic_cast<LiNumerique*>(lc1);
    LiNumerique* lc3 = dynamic_cast<LiNumerique*>(lc4);
    return new LiComplexe(lc2, lc3);

    delete lc1; delete lc4;
}


/*!
 *  \brief overloaded operator*
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Used to multiply a LiComplexe object by a Litterale
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale
 */
Litterale* LiComplexe::operator* (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& tmp = dynamic_cast<const LiExpression&>(li);
        QString qs = QString::fromStdString(toString());
        return new LiExpression("("% qs % ")*(" % tmp.getExpression() % ")");
    }

    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        const Litterale& a1 = dynamic_cast<const Litterale&>(getReelle());
        const Litterale& b1 = dynamic_cast<const Litterale&>(getImage());
        const Litterale& a2 = dynamic_cast<const Litterale&>(lc1.getReelle());
        const Litterale& b2 = dynamic_cast<const Litterale&>(lc1.getImage());

        Litterale* resaa = a1 * a2;
        Litterale* resbb = b1 * b2;
        Litterale* resab = a1 * b2;
        Litterale* resba = b1 * a2;
        Litterale* resaabb = *resaa - *resbb;
        Litterale* resabba = *resab + *resba;

        LiNumerique* lin;
        LiNumerique* lin2;

        lin = dynamic_cast<LiNumerique*>(resaabb);
        lin2 = dynamic_cast<LiNumerique*>(resabba);

        if (lin2->isZero()) {
            if (typeid(*lin) == typeid(LiEntiere)) return new LiEntiere(lin->getValue());
            if (typeid(*lin) == typeid(LiReelle)) return new LiReelle(lin->getReel());
            if (typeid(*lin) == typeid(LiRationnelle)) return new LiRationnelle(lin->getNumerateur(),lin->getDenominateur());
        }
        else {
            return new LiComplexe(lin, lin2);
        }
        delete resaa; delete resbb; delete resab; delete resba; delete resaabb; delete resabba;
    }


    Litterale& pt1 = getReelle();
    Litterale& pt2 = getImage();
    Litterale* lc1 = pt1 * li;
    Litterale* lc4 = pt2 * li;
    LiNumerique* lc2 = dynamic_cast<LiNumerique*>(lc1);
    LiNumerique* lc3 = dynamic_cast<LiNumerique*>(lc4);
    return new LiComplexe(lc2, lc3);

    delete lc1; delete lc4;
}


/*!
 *  \brief overloaded operator==
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Used to test if the value of a LiComplexe equals the value of a Litterale
 *  If the other object is not of type LiComplexe, returns false
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale  (with value = 1 if true, value = 0 otherwise)
 */
Litterale* LiComplexe::operator== (const Litterale& li) const {
    Litterale* newli;
    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        Litterale* lit1 = (getReelle() == lc1.getReelle());
        Litterale* lit2 = (getImage() == lc1.getImage());
        if(lit1->getValue() == 1 && lit2->getValue() == 1) {
            LiEntiere* l1 = new LiEntiere(1);
            newli = l1;
            return newli;
        }
    }
    LiEntiere* l1 = new LiEntiere(0);
    newli = l1;
    return newli;
}


/*!
 *  \brief overloaded operator!=
 *
 *  Method which was defined in Litterale (pure virtual)
 *  Used to test if the value of a LiComplexe does not equal the value of a Litterale
 *  If the other object is not of type LiComplexe, returns true
 *  const method (attributs sould not be modified)
 *
 *  \param 1 parameter of type const Litterale&
 *  \return pointer to Litterale  (with value = 1 if true, value = 0 otherwise)
 */
Litterale* LiComplexe::operator!= (const Litterale& li) const {
    Litterale* newli;
    if (typeid(li) == typeid(LiComplexe)) {
        const LiComplexe& lc1 = dynamic_cast<const LiComplexe&>(li);
        Litterale* lit1 = (getReelle() == lc1.getReelle());
        Litterale* lit2 = (getImage() == lc1.getImage());
        if(lit1->getValue() == 1 && lit2->getValue() == 1) {
            LiEntiere* l1 = new LiEntiere(0);
            newli = l1;
            return newli;
        }
    }
    LiEntiere* l1 = new LiEntiere(1);
    newli = l1;
    return newli;
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
Litterale* LiComplexe::And(const Litterale* li) {
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
Litterale* LiComplexe::Or(const Litterale* li) {
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
 *  \param no paramter
 *  \return pointer to Litterale : LiEntiere(1) if true, LiEntiere(0) if false
 */
Litterale* LiComplexe::Not() {
    if(isZero())
        return new LiEntiere(1);
    return new LiEntiere(0);
}


/*!
 *  \brief toString() method
 *
 *  Pure virtual method in Litterale, used in the afficher() method
 *  Method which takes re and im (of type LiNUmerique*), transforms them into a string and returns them
 *
 *  \param no parameter
 *  \return string
 */
string LiComplexe::toString() const {
    stringstream ss;
    Litterale* lin = im;
    if(typeid(*lin) == typeid(LiEntiere)) {
        if(lin->getValue() < 0) {
            ss << re->toString() << "" << im->toString() << "i";
            return ss.str();
        }
        else {
            ss << re->toString() << "+" << im->toString() << "i";
            return ss.str();
        }
    }
    if(typeid(*lin) == typeid(LiReelle)) {
        if(lin->getReel() < 0) {
            ss << re->toString() << "" << im->toString() << "i";
            return ss.str();
        }
        else {
            ss << re->toString() << "+" << im->toString() << "i";
            return ss.str();
        }
    }
    if(typeid(*lin) == typeid(LiRationnelle)) {
        if(lin->getNumerateur() < 0) {
            ss << re->toString() << "" << im->toString() << "i";
            return ss.str();
        }
        else {
            ss << re->toString() << "+" << im->toString() << "i";
            return ss.str();
        }
    }
}



