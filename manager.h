#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
#include <QString>
#include <QStringBuilder>
#include <QRegExp>
#include <QStack>
#include <map>


using namespace std;





//////////////////////////////////////// LITTERALE EXCEPTION ////////////////////////////////////////


class LiException {
	string info;
public:
	LiException(const string& s) :info(s) {}
	~LiException() { cout << info << endl; }
	const string& getInfo() const {return info;}
};

//////////////////////////////////////// CALCULATRICE EXCEPTION ////////////////////////////////////////

class CalculatriceException {
	string info;
public:
	CalculatriceException(const string& s) :info(s) {}
	~CalculatriceException() { cout << info << endl; }
	const string& getInfo() const {return info;}
};





//////////////////////////////////////// LITTERALE ////////////////////////////////////////


class Litterale {
public:
    virtual ~Litterale() {}
    virtual string toString() const = 0;
    virtual bool isZero() const = 0;
    void afficher (ostream& f=cout) const { f << toString() << "\n"; }

    virtual int getValue() const { return 1; }
    virtual int getNumerateur() const{ return 1; }
    virtual int getDenominateur() const { return 1; }
    virtual double getReel() const { return 1; }
    //virtual string getAtom() const { return ""; }
    //virtual QString getExpression { return QString(""); }
	virtual Litterale* operator+ (const Litterale& li) const = 0;
	virtual Litterale* operator- (const Litterale& li) const = 0;
	virtual Litterale* operator/ (const Litterale& li) const = 0;
	virtual Litterale* operator* (const Litterale& li) const = 0;
	virtual Litterale* operator== (const Litterale& li) const = 0;
	virtual Litterale* operator!= (const Litterale& li) const = 0;
	virtual Litterale* operator<= (const Litterale& li) const = 0;
	virtual Litterale* operator>= (const Litterale& li) const = 0;
	virtual Litterale* operator< (const Litterale& li) const = 0;
	virtual Litterale* operator> (const Litterale& li) const = 0;
	//virtual Litterale& operator= (Litterale& li) = 0;
	virtual Litterale* Neg() = 0;
	virtual Litterale* Num() = 0;
	virtual Litterale* Den() = 0;
	virtual Litterale* Re() = 0;
	virtual Litterale* Im() = 0;
    virtual Litterale* And(const Litterale* li) = 0;
    virtual Litterale* Or(const Litterale* li) = 0;
    virtual Litterale* Not() = 0;
};






//////////////////////////////////////// EXPRESSION ////////////////////////////////////////


class LiExpression : public Litterale {
    QString exp;
public:
    LiExpression(QString a):exp(a) {}
    QString getExpression() const {  return exp; }
    string toString()const { QString tmp; tmp = "'" % exp % "'"; return tmp.toStdString(); }
    bool isZero() const { return exp.toStdString() == ""; }
    static LiExpression* enleverGuillemets(const QString& s);

    int getValue() const { throw LiException("error : pas de getValue sur une Expression"); }
    int getNumerateur() const { throw LiException("error : pas de getNumerateur sur une Expression"); }
	int getDenominateur() const { throw LiException("error : pas de getDenominateur sur une Expression"); }
	double getReel() const { throw LiException("error : pas de getReel sur un atome"); }
    Litterale* operator+ (const Litterale& li) const;
	Litterale* operator- (const Litterale& li) const;
	Litterale* operator/ (const Litterale& li) const;
	Litterale* operator* (const Litterale& li) const;
    Litterale* operator== (const Litterale& li) const { throw LiException("error : pas de == sur une Expression"); }
    Litterale* operator!= (const Litterale& li) const { throw LiException("error : pas de != sur une Expression"); }
    Litterale* operator<= (const Litterale& li) const { throw LiException("error : pas de <= sur une Expression"); }
    Litterale* operator>= (const Litterale& li) const { throw LiException("error : pas de >= sur une Expression"); }
    Litterale* operator< (const Litterale& li) const { throw LiException("error : pas de < sur une Expression"); }
    Litterale* operator> (const Litterale& li) const { throw LiException("error : pas de > sur une Expression"); }
	//Litterale& operator= (Litterale& li);
    Litterale* Num();
    Litterale* Den();
    Litterale* Re();
    Litterale* Im();
    Litterale* Neg();
    Litterale* Div(const Litterale& li);
    Litterale* Mod(const Litterale& li);
    virtual Litterale* And(const Litterale* li);
    virtual Litterale* Or(const Litterale* li);
    virtual Litterale* Not();
};






//////////////////////////////////////// PILE ////////////////////////////////////////


class Pile {
    Litterale** li;
    unsigned int nb;
    unsigned int nbMax;
    unsigned int nbAffiche;
    QString message;
    void agrandissementCapacite();
public:
    Pile():li(0),nb(0),nbMax(0),nbAffiche(5),message("") {}
    ~Pile() { for (unsigned int i = 0; i < nb; i++) delete li[i]; delete[] li; }
    bool estVide() const {return nb==0;}
    unsigned int taille() const { return nb; }
    void supprimerPile() { for (unsigned int i = 0; i < nb; i++) delete li[i]; delete[] li; nb=0; }
    void affiche() const;
    void setMessage(const QString& m) { message = m; }
    QString getMessage() const { return message; }
    unsigned int getNbLitteralesToAffiche()const { return nbAffiche; }
    void setNbLitteralesToAffiche(unsigned int n) { nbAffiche = n; }

    void push(Litterale* li);
    //void pop(); <==> drop dans le sujet
    Litterale* top() const;
    void dup();
    void drop();
    void swap();
    Litterale* lastop();
    void lastargs();
    void undo();
    void redo();
    void clear();
};






//////////////////////////////////////// CALCULATRICE ////////////////////////////////////////

class Calculatrice {
    Pile* pile;
    QString message;
    QString lastoperateur;
    Litterale* lastarg1;
    Litterale* lastarg2;
    map<QString,Litterale*> mapAtome;
public:
    //Calculatrice():pile(0), message("") {}
    Calculatrice(Pile* p):pile(p), message(""), lastoperateur(""), lastarg1(nullptr), lastarg2(nullptr) {}
    ~Calculatrice() {  delete pile; }
    void setMessage(const QString& m) { message=m; }
    QString getMessage() const { return message; }
    //void afficherMessage() { cout << QString::toStdString(message) ; }
    QString getLastOp() const { return lastoperateur; }
    Litterale* getLastArg1() const { return lastarg1; }
    Litterale* getLastArg2() const { return lastarg2; }
    void operateur2(const QString& s);
    void operateur1(const QString& s);
    void operateurp(const QString& s);
    void enregistrerLast(const QString& s);

    void commande(const QString & s);
    void executer();
    void Eval(const QString& exp1);
    QString infixePostfixe(const QString& s);
    
    void addAtom(const QString&s, Litterale* li);
    void removeAtom(const QString& s, Litterale* li);
    bool alreadyExists(const QString& s);
    void afficherTousAtomes();
};



bool estUnOperateurBinaire (const QString& s);
bool estUnOperateurUnaire (const QString& s);
bool estUnOperateurDePile(const QString& s);
bool estEntier (const QString& s);
bool estDouble (const QString& s);
bool estExpression(const QString& s);
bool estAtomeGuillemets(const QString& s);
bool estAtome(const QString& s);
bool estAtomeGuillemetsExp(const QString& s);
bool estAtomeExp(const QString& s);

bool is1operator(const QString& s);
bool is2operator(const QString& s);

bool is1operatorPP(const QString& s);
bool is2operatorPVP(const QString& s);
bool PrioritePrecedentSup(const QChar qc, const QChar ptop);
int prioriteOp(const QString& s);






#endif // MANAGER_H_INCLUDED

