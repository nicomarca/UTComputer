/**
 * \file licomplexe.cpp
 * \brief file where the methods of the LiComplexe class are defined
 *
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "liexpression.h"


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
