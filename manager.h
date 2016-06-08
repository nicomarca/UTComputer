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
#include <QTextStream>
#include <QMainWindow>
#include <QDebug>
#include <QWidget>
#include <QLineEdit>
#include <QKeyEvent>
#include <QTableWidget>
//#include <regex>

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
    virtual Litterale* Clone() const = 0;
};





//////////////////////////////////////// ATOME ////////////////////////////////////////

class Atome : public Litterale {
    string atom;
public:
    Atome(string a);
    string getAtom() const {  return atom; }
    string toString()const { return atom; }

    int getValue() const { throw LiException("error : pas de getValue sur un atome"); }
	int getNumerateur() const { throw LiException("error : pas de getNumerateur sur un atome"); }
	int getDenominateur() const { throw LiException("error : pas de getDenominateur sur un atome"); }
	double getReel() const { throw LiException("error : pas de getReel sur un atome"); }
    Litterale* operator+ (const Litterale& li) const { throw LiException("error : pas de + pour un atome"); }
	Litterale* operator- (const Litterale& li) const { throw LiException("error : pas de - pour un atome"); }
	Litterale* operator/ (const Litterale& li) const { throw LiException("error : pas de / pour un atome"); }
	Litterale* operator* (const Litterale& li) const { throw LiException("error : pas de * pour un atome"); }
	Litterale* operator== (const Litterale& li) const {}
	Litterale* operator!= (const Litterale& li) const {}
	Litterale* operator<= (const Litterale& li) const {}
	Litterale* operator>= (const Litterale& li) const {}
	Litterale* operator< (const Litterale& li) const {}
	Litterale* operator> (const Litterale& li) const {}
	//Litterale& operator= (Litterale& li);
    Litterale* Num() { throw LiException("error : pas de Num pour un atome"); }
    Litterale* Den() { throw LiException("error : pas de Den pour un atome"); }
	Litterale* Re() { throw LiException("error : pas de Re pour un atome"); }
	Litterale* Im() { throw LiException("error : pas de Im pour un atome"); }
	Litterale* Neg() { throw LiException("error : pas de Neg pour un atome"); }
};




//////////////////////////////////////// EXPRESSION ////////////////////////////////////////


class LiExpression : public Litterale {
    QString exp;
public:
    LiExpression(QString a):exp(a) {}
    QString getExpression() const {  return exp; }
    string toString()const { return exp.toStdString(); }
    bool isZero() const { return exp.toStdString() == ""; }

    int getValue() const { throw LiException("error : pas de getValue sur une Expression"); }
	int getNumerateur() const { throw LiException("error : pas de getNumerateur sur une Expression"); }
	int getDenominateur() const { throw LiException("error : pas de getDenominateur sur une Expression"); }
	double getReel() const { throw LiException("error : pas de getReel sur un atome"); }
    Litterale* operator+ (const Litterale& li) const;
	Litterale* operator- (const Litterale& li) const;
	Litterale* operator/ (const Litterale& li) const;
	Litterale* operator* (const Litterale& li) const;
    Litterale* operator== (const Litterale& li) const { throw LiException("error : pas de == sur un atome"); }
    Litterale* operator!= (const Litterale& li) const { throw LiException("error : pas de != sur un atome"); }
    Litterale* operator<= (const Litterale& li) const { throw LiException("error : pas de <= sur un atome"); }
    Litterale* operator>= (const Litterale& li) const { throw LiException("error : pas de >= sur un atome"); }
    Litterale* operator< (const Litterale& li) const { throw LiException("error : pas de < sur un atome"); }
    Litterale* operator> (const Litterale& li) const { throw LiException("error : pas de > sur un atome"); }
	//Litterale& operator= (Litterale& li);
    Litterale* Num() { throw LiException("error : pas de Num pour une Expression"); }
    Litterale* Den() { throw LiException("error : pas de Den pour une Expression"); }
	Litterale* Re() { throw LiException("error : pas de Re pour une Expression"); }
	Litterale* Im() { throw LiException("error : pas de Im pour une Expression"); }
	Litterale* Neg() { throw LiException("error : pas de Neg pour une Expression"); }
    virtual Litterale* And(const Litterale* li);
    virtual Litterale* Or(const Litterale* li);
    virtual Litterale* Not();
};






//////////////////////////////////////// PILE ////////////////////////////////////////

class Memento {
    //Same attributes as in pile (except message which is not necessary)
    Litterale** li;
    unsigned int nb;
    unsigned int nbMax;
    unsigned int nbAffiche;
public:
    //The constructor initializes all the attributes of the class with parameters from a pile
    Memento(Litterale** l, unsigned int n, unsigned int nmax, unsigned int naff):li(l),nb(n),nbMax(nmax),nbAffiche(naff){}
    //The destructor deletes all the Litterales of li
    ~Memento() {for (unsigned int i = 0; i < nb; i++) delete li[i]; delete[] li;}
    //Accessors
    unsigned int getNb()const { return nb; }
    unsigned int getNbMax()const { return nbMax; }
    unsigned int getNbAffiche()const { return nbAffiche; }
    Litterale** getLi()const { return li; }
};




class Pile : public QObject {
    //The pile emits a signal when it is modified => Q_OBJECT
    Q_OBJECT
    //A table of Litterale*
    Litterale** li;
    unsigned int nb; //number of elements in the pile
    unsigned int nbMax; //capacity of the pile
    unsigned int nbAffiche; //number of elements to display
    QString message; //A message about the state of the pile, a disfunctionment...
    void agrandissementCapacite(); //Private method to reallocates some memory to the pile in order to increase its capacity
public:
    Pile():li(0),nb(0),nbMax(0),nbAffiche(5),message("") {}
    ~Pile() { for (unsigned int i = 0; i < nb; i++) delete li[i]; delete[] li; }
    bool estVide() const {return nb==0;}
    unsigned int taille() const { return nb; }
    void supprimerPile() { for (unsigned int i = 0; i < nb; i++) delete li[i]; delete[] li; nb=0; }
    void affiche() const;
    void setMessage(const QString& m) { message = m; if (message != "") modificationEtat();}
    QString getMessage() const { return message; }
    unsigned int getNbLitteralesToAffiche()const { return nbAffiche; }
    Litterale** getLi()const { return li; }
    void setNbLitteralesToAffiche(int n) { if (n>0) nbAffiche = n; }

    void push(Litterale* li);
    //void pop(); <==> drop dans le sujet
    Litterale* top() const;
    void dup();
    void drop();
    void swap();
    Litterale* lastop();
    void undo();
    void redo();
    void clear();

    void setMemento();
    Memento* SaveStatetoMemento() {
        Litterale** newtab = new Litterale*[nbMax];
        for(unsigned int i=0; i<nb; i++) newtab[i]= li[i]->Clone();
        return new Memento(newtab, nb, nbMax, nbAffiche);
    }

    void getStateFromMemento(Memento* m) {
        Litterale** newtab = new Litterale*[nbMax];
        for (unsigned int i = 0; i<m->getNb();i++) newtab[i]= (m->getLi())[i]->Clone();
        li=newtab;
        nb = m->getNb();
        nbMax=m->getNbMax();
        nbAffiche=m->getNbAffiche();
        message = "";
        modificationEtat();
    }

    class iterator {
            Litterale** current;
            iterator(Litterale** u):current(u){}
            friend class Pile;
    public:
    iterator():current(0){}
            Litterale& operator*() const { return **current; }
            bool operator!=(iterator it) const { return current!=it.current; }
            iterator& operator++(){ ++current; return *this; }
            iterator& operator--(){ --current; return *this;}
            bool operator>=(iterator it) {return current >= it.current;}
    };
    iterator begin() { return iterator(li); }
    iterator end() { return iterator(li+nb); }

signals:
    void modificationEtat();
};






//////////////////////////////////////// CALCULATRICE ////////////////////////////////////////

class Calculatrice: public QObject {
    Pile* pile;
    QString message;
    QString lastoperateur;
    Litterale* lastarg1;
    Litterale* lastarg2;

    //CONSTRUCTEUR ET DESTRUCTEUR PRIVE ==> SINGLETON
    /*Calculatrice(Pile* p):pile(p), message(""), lastoperateur(""), lastarg1(nullptr), lastarg2(nullptr) {}
    ~Calculatrice() {  delete pile; }*/
public:
    Calculatrice(Pile* p):pile(p), message(""), lastoperateur(""), lastarg1(nullptr), lastarg2(nullptr) {}
    ~Calculatrice() {  delete pile; }
    //Calculatrice():pile(0), message("") {}
    //Calculatrice(Pile* p):pile(p), message(""), lastoperateur(""), lastarg1(nullptr), lastarg2(nullptr) {}
    //~Calculatrice() {  delete pile; }
    void setMessage(const QString& m) { message=m;}
    QString getMessage() const { return message; }
    //void afficherMessage() { cout << QString::toStdString(message) ; }
    QString getLastOp() const { return lastoperateur; }
    Litterale* getLastArg1() const { return lastarg1; }
    Litterale* getLastArg2() const { return lastarg2; }
    void setLastarg1(Litterale* l) {lastarg1 = l;}
    void setLastarg2(Litterale* l) {lastarg2 = l;}
    Pile* getPile() const {return pile;}
    void operateur2(const QString& s);
    void operateur1(const QString& s);
    void operateurp(const QString& s);
    void enregistrerLast(const QString& s);
    void lastargs();

    void commande(const QString & s);
    void executer();

    // Fonctions de création et destruction du singleton
    //static Calculatrice* getInstance ();

    //static void libereInstance();

private:
    static Calculatrice* cal;
};

bool estUnOperateurBinaire (const QString& s);
bool estUnOperateurUnaire (const QString& s);
bool estUnOperateurDePile(const QString& s);
bool estEntier (const QString& s);
bool estDouble (const QString& s);
bool estEntierPoint (const QString& s);




//////////////////////////////////////// VARIABLE ////////////////////////////////////////
/*

class Var {
    Atome* id;
    Litterale* li;
};

class VariableMng {
    Var** tab;
    unsigned int nb;
    unsigned int nbMax;
    void AgrandissementCapacite();
public:
    Variable():tab(0), nb(0), nbMax(10) {}
    // ...
};
*/




#endif // MANAGER_H_INCLUDED

