#ifndef LITTERALE_H_INCLUDED
#define LITTERALE_H_INCLUDED

#include "manager.h"


using namespace std;



//////////////////////////////////////// LITTERALE NUMERIQUE ////////////////////////////////////////

class LiNumerique : public Litterale {
public:
    virtual string toString() const = 0;
    virtual Litterale* Clone() const=0;
};




//////////////////////////////////////// LITTERALE ENTIERE ////////////////////////////////////////


class LiEntiere : public LiNumerique {
	int value;
public:
    LiEntiere():value(0) {}
	LiEntiere(int v=0):value(v) {}
    string toString() const {stringstream ss; ss << value; return ss.str();}
    bool isZero() const { if(value == 0) return true; else return false; }
	int getValue() const { return value; }
	int setValue(int n) { value=n; return n; }
	int getNumerateur() const { throw LiException("error : pas de numerateur dans une LiEntiere"); }
	int getDenominateur() const { throw LiException("error : pas de denominateur dans une LiEntiere"); }
	double getReel() const { throw LiException("error : pas de reel dans une LiEntiere"); }
    string getAtom() const { throw LiException("error : pas d'atom dans une LiEntiere"); }

	Litterale* operator+ (const Litterale& li) const;
	Litterale* operator- (const Litterale& li) const;
	Litterale* operator/ (const Litterale& li) const;
	Litterale* operator* (const Litterale& li) const;
	LiEntiere* operator== (const Litterale& li) const;
	LiEntiere* operator!= (const Litterale& li) const;
	Litterale* operator<= (const Litterale& li) const;
	Litterale* operator>= (const Litterale& li) const;
	Litterale* operator< (const Litterale& li) const;
	Litterale* operator> (const Litterale& li) const;

        virtual Litterale* Clone() const {
                 return new LiEntiere(*this);
        }

    LiEntiere* Neg() { value = -value; return this; }
    LiEntiere* Div (const Litterale& li);
	LiEntiere* Mod (const Litterale& li);
	Litterale* Num() { return this; }
	Litterale* Den() { return new LiEntiere(1); }
	Litterale* Re() { return this; }
	Litterale* Im() { return new LiEntiere(0); }
    Litterale* And(const Litterale* li);
    Litterale* Or(const Litterale* li);
    Litterale* Not();
};






//////////////////////////////////////// LITTERALE RATIONNELLE ////////////////////////////////////////


class LiRationnelle : public LiNumerique {
	LiEntiere numerateur;
	LiEntiere denominateur;
public:
	LiRationnelle() :numerateur(0), denominateur(1) {}
	LiRationnelle(int n, int d):numerateur(n), denominateur(d) { simplification(); }
	LiRationnelle(const LiEntiere& n, const LiEntiere& d):numerateur(n), denominateur(d) {}
	string toString() const {stringstream ss; ss << numerateur.getValue() << "/" << denominateur.getValue(); return ss.str();}
	void simplification();
	void afficher() const { cout <<"LiRationnelle : "<<numerateur.getValue() << "/" << denominateur.getValue()<< "\n"; }

    bool isZero() const { if(numerateur.getValue() == 0) return true; else return false;}
	int getValue() const { throw LiException("error : pas de value dans une LiRationnelle"); }
	int getNumerateur() const { return numerateur.getValue(); }
	int getDenominateur() const { return denominateur.getValue(); }
	double getReel() const { throw LiException("error : pas de reel dans une LiRationnelle"); }
    string getAtom() const { throw LiException("error : pas d'atom dans une LiRationnelle"); }

	Litterale* operator+ (const Litterale& li) const;
	Litterale* operator- (const Litterale& li) const;
	Litterale* operator/ (const Litterale& li) const;
	Litterale* operator* (const Litterale& li) const;
	Litterale* operator== (const Litterale& li) const;
	Litterale* operator!= (const Litterale& li) const;
	Litterale* operator<= (const Litterale& li) const;
	Litterale* operator>= (const Litterale& li) const;
	Litterale* operator< (const Litterale& li) const;
	Litterale* operator> (const Litterale& li) const;
	//LiRationnelle& operator= (Litterale& li);
	LiRationnelle* Neg() { numerateur.Neg(); return this; }
	Litterale* Num() { return &numerateur; }
	Litterale* Den() { return &denominateur;}
	Litterale* Re() { return this; }
	Litterale* Im() { return new LiEntiere(0); }
	Litterale* Div(const Litterale& li) { throw LiException("Error : pas de DIV entre LiRationnelles"); }
	Litterale* Mod(const Litterale& li) { throw LiException("Error : pas de MOD entre LiRationnelles"); }
    Litterale* And(const Litterale* li);
    Litterale* Or(const Litterale* li);
    Litterale* Not();
    virtual Litterale* Clone() const {
        return new LiRationnelle(*this);
    }
};







//////////////////////////////////////// LITTERALE REELLE ////////////////////////////////////////


class LiReelle : public LiNumerique {
	double value;
public:
    LiReelle():value(0) {}
	LiReelle(double v) :value(v) {}
	string toString() const {stringstream ss; ss << value; return ss.str();}

    bool isZero() const { if(value == 0.) return true; else return false;}
	int getValue() const { throw LiException("error : pas de value dans une LiReelle"); }
	int getNumerateur() const { throw LiException("error : pas de numerateur dans une LiReelle"); }
	int getDenominateur() const { throw LiException("error : pas de denominateur dans une LiReelle"); }
	double getReel() const { return value; }
    string getAtom() const { throw LiException("error : pas d'atom dans une LiReelle"); }

	Litterale* operator+ (const Litterale& li) const;
	Litterale* operator- (const Litterale& li) const;
	Litterale* operator/ (const Litterale& li) const;
	Litterale* operator* (const Litterale& li) const;
	Litterale* operator== (const Litterale& li) const;
	Litterale* operator!= (const Litterale& li) const;
	Litterale* operator<= (const Litterale& li) const;
	Litterale* operator>= (const Litterale& li) const;
	Litterale* operator< (const Litterale& li) const;
	Litterale* operator> (const Litterale& li) const;
	//LiReelle& operator= (Litterale& li);
	LiReelle* Neg() { value = -value; return this; }
	Litterale* Num() { throw LiException("Error : LiReelle pas de num"); }
	Litterale* Den() { throw LiException("Error : LiReelle pas de den"); }
	Litterale* Re() { return this; }
	Litterale* Im() { return new LiEntiere(0); }
	Litterale* Div(const Litterale& li) { throw LiException("Error : pas de DIV entre LiReelles"); }
	Litterale* Mod(const Litterale& li) { throw LiException("Error : pas de MOD entre LiReelles"); }
    Litterale* And(const Litterale* li);
    Litterale* Or(const Litterale* li);
    Litterale* Not();
    virtual Litterale* Clone() const {
        return new LiReelle(*this);
    }
};





//////////////////////////////////////// LITTERALE COMPLEXE ////////////////////////////////////////


class LiComplexe : public Litterale {
	LiNumerique* re;
	LiNumerique* im;
public:
        LiComplexe(LiNumerique* r, LiNumerique* i);
	LiComplexe(const LiComplexe& lc);
	LiComplexe& operator=(const LiComplexe& lc);
	~LiComplexe() { delete re; delete im; }

	string toString() const;
    bool isZero() const { return (re->isZero() && im->isZero()); }

	LiNumerique& getReelle() const { return *re; }
	LiNumerique& getImage() const { return *im; }

	Litterale* operator+ (const Litterale& li) const;
	Litterale* operator- (const Litterale& li) const;
	Litterale* operator/ (const Litterale& li) const;
	Litterale* operator* (const Litterale& li) const;
	Litterale* operator== (const Litterale& li) const;
	Litterale* operator!= (const Litterale& li) const;
	Litterale* operator<= (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	Litterale* operator>= (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	Litterale* operator< (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	Litterale* operator> (const Litterale& li) const { throw LiException("Error : pas de comparaison LiComplexe"); }
	//LiComplexe& operator= (Litterale& li);
    LiComplexe* Neg() { re->Neg(); im->Neg(); return this; }
	Litterale* Num() { throw LiException("Error : LiComplexe pas de num"); }
	Litterale* Den() { throw LiException("Error : LiComplexe pas de den"); }
	Litterale* Re() { return re; }
	Litterale* Im() { return im; }
	Litterale* Div(const Litterale& li) { throw LiException("Error : pas de DIV entre LiComplexes"); }
	Litterale* Mod(const Litterale& li) { throw LiException("Error : pas de MOD entre LiComplexes"); }
    Litterale* And(const Litterale* li);
    Litterale* Or(const Litterale* li);
    Litterale* Not();
    virtual Litterale* Clone() const {
        LiNumerique* r = dynamic_cast<LiNumerique*>(re->Clone());
        LiNumerique* i = dynamic_cast<LiNumerique*>(im->Clone());
        return new LiComplexe(r, i);
    }
};





#endif // LITTERALE_H_INCLUDED

