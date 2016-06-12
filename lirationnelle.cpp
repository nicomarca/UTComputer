/**
 * \file lirationnelle.cpp
 * \brief file where the methods of the LiRationnelle class are defined
 *
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include"liexpression.h"

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




