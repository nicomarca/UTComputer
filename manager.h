#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

/**
 * \file manager.h
 * \brief file where the class managing the calculator are defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

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




#include <QRegexp>
#include <QStack>
#include <Map>



using namespace std;





//////////////////////////////////////// LITTERALE EXCEPTION ////////////////////////////////////////

<<<<<<< 5053b611ade148341877aa723b8b13dde212b35b
/// \class The LiException class
///
/// \brief class to manage all the exception of the calculator
///
/// All the exception are send to this class
///


class LiException {
        QString info; /*!< info : attribut of type QString (message send to a LiException object)*/
=======
/*!
 * \brief The LiException class
 *
 * Handle the exception encountered in the program
 *
 */
class LiException {
    /*!
         * \brief info
         */
        QString info;
>>>>>>> uml

public:
        /*!
         *  \brief Constructor
         *
         *  Constructor of the LiException class
         *  Inline Method
         *
         *  \param 1 parameter of type const QString& to initialize the info attribute
         */
        LiException(const QString& s) :info(s) {}

        /*!
         *  \brief getInfo() method
         *
         *  Accessor to the attribute
         *
         *  \param 1 parameter of type const QString& to initialize the info attribute
         *  \return const reference to QString (message sould not be modified)
         */
        const QString& getInfo() const {return info;}
};




//////////////////////////////////////// LITTERALE ////////////////////////////////////////

/// \class The Litterale class
///
/// \brief Abstract class from which inherits all the other litterale class (LiNumerique and LiComplexe)
///
/// No attributes but pure virtual methods which will be defined in the inherited classes
///


class Litterale {
public:

    /*!
     *  \brief Destructor
     *
     *  Virtual method (because of the LiComplexe class)
     *  When a Litterale object which points to a LiComplexe object is deleted, the destructor of the LiComplexe class needs to be called
     *
     */
    virtual ~Litterale() {}

    /*!
     *  \brief toString() method
     *
     *  Pure virtual method used in the afficher() method
     *  This method have to be defined in the inherited classes
     *
     *  \param no parameter
     *  \return string
     */
    virtual string toString() const = 0;

    /*!
     *  \brief isZero() method
     *
     *  Pure virtual method
     *  Used to inform us if a the attributs of a class are 0
     *  This method have to be defined in the inherited classes
     *
     *  \param no parameter
     *  \return bool
     */
    virtual bool isZero() const = 0;

    /*!
     *  \brief afficher() method
     *
     *  const method used to print the different Litterale
     *  Call the toString() method
     *
     *  \param 1 parameter of type ostream& (default : cout)
     *  \return void
     */
    void afficher (ostream& f=cout) const { f << toString() << "\n"; }

    /*!
     *  \brief getValue() method
     *
     *  Virtual method
     *  Accessor for the LiEntiere class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return int
     */
    virtual int getValue() const { return 1; }

    /*!
     *  \brief getNumerator() method
     *
     *  Virtual method
     *  Accessor for the LiRationnelle class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return int
     */
    virtual int getNumerateur() const{ return 1; }

    /*!
     *  \brief getDenominator() method
     *
     *  Virtual method
     *  Accessor for the LiRationnelle class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return int
     */
    virtual int getDenominateur() const { return 1; }

    /*!
     *  \brief getReel() method
     *
     *  Virtual method
     *  Accessor for the LiReelle class (defined here to avoid dynamic_casts)
     *
     *  \param no parameters
     *  \return double
     */
    virtual double getReel() const { return 1; }

    /*!
     *  \brief operator+
     *
     *  Pure virtual method
     *  Const method (object sould not be modified)
     *  overload of the operator +
     *  Used to add 2 litterales
     *
     *  \param const reference to Litterale (parameter sould not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator+ (const Litterale& li) const = 0;

    /*!
     *  \brief operator-
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator -
     *  Used to substract 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator- (const Litterale& li) const = 0;

    /*!
     *  \brief operator/
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator /
     *  Used to divid 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator/ (const Litterale& li) const = 0;

    /*!
     *  \brief operator*
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator *
     *  Used to multiply 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator* (const Litterale& li) const = 0;

    /*!
     *  \brief operator==
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator ==
     *  Used to test if 2 litterales are equal
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator== (const Litterale& li) const = 0;

    /*!
     *  \brief operator!=
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator !=
     *  Used to test if 2 litterales are not equal
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator!= (const Litterale& li) const = 0;

    /*!
     *  \brief operator<=
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator <=
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator<= (const Litterale& li) const = 0;

    /*!
     *  \brief operator>=
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator >=
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator>= (const Litterale& li) const = 0;

    /*!
     *  \brief operator<
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator <
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
	virtual Litterale* operator< (const Litterale& li) const = 0;

    /*!
     *  \brief operator>
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  overload of the operator >
     *  Used to compare 2 litterales
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* operator> (const Litterale& li) const = 0;

    /*!
     *  \brief NEG() method
     *
     *  Pure virtual method
     *  Changes the sign of the attributes of a Litterale
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
	virtual Litterale* Neg() = 0;

    /*!
     *  \brief NUM() method
     *
     *  Pure virtual method
     *  Accessor to the numerator of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
	virtual Litterale* Num() = 0;

    /*!
     *  \brief DEN() method
     *
     *  Pure virtual method
     *  Accessor to the denominator of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
	virtual Litterale* Den() = 0;

    /*!
     *  \brief RE() method
     *
     *  Pure virtual method
     *  Accessor to the real part of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
	virtual Litterale* Re() = 0;

    /*!
     *  \brief IM() method
     *
     *  Pure virtual method
     *  Accessor to the imaginary part of Litterales
     *
     *  \param no parameters
     *  \return pointer to Litterale
     */
	virtual Litterale* Im() = 0;

    /*!
     *  \brief AND() method
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  Logic operator AND
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* And(const Litterale* li) = 0;

    /*!
     *  \brief OR() method
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  Logic operator OR
     *
     *  \param const reference to Litterale (parameter should not be modified)
     *  \return pointer to Litterale
     */
    virtual Litterale* Or(const Litterale* li) = 0;

    /*!
     *  \brief NOT() method
     *
     *  Pure virtual method
     *  Const method (object should not be modified)
     *  Logic operator NOT
     *
     *  \param no parameter
     *  \return pointer to Litterale
     */
    virtual Litterale* Not() = 0;
    virtual Litterale* Clone() const = 0;
};






//////////////////////////////////////// EXPRESSION ////////////////////////////////////////

/// \class The LiExpression class
///
/// \brief Class which inherits from Litterale
///
/// Used to represent all the expression in the Calculator
///
///
class LiExpression : public Litterale {
    QString exp; /*!< exp : attribut of type QString (represent the expression)*/
public:
    /*!
     *  \brief Constructor
     *
     *  Constructor of the LiExpression class
     *  Inline Method
     *
     *  \param 1 parameter of type QString to initialize exp
     */
    LiExpression(QString a):exp(a) {}

    /*!
     *  \brief getExpression() method
     *
     *  Accessor to the attribute of a LiExpression object
     *
     *  \param no parameter
     *  \return QString
     */
    QString getExpression() const {  return exp; }

    /*!
     *  \brief toString() method
     *
     *  Used to transform the attribute of type QString into a string
     *  This method was pure virtual in Litterale
     *  Inline Method
     *
     *  \param no parameter
     *  \return string
     */
    string toString()const { QString tmp; tmp = "'" % exp % "'"; return tmp.toStdString(); }

    /*!
     *  \brief isZero() method
     *
     *  Used to inform us if the attribut is empty or not.
     *  This method was pure virtual in Litterale
     *  Inline Method
     *
     *  \param no parameter
     *  \return bool
     */
    bool isZero() const { return exp.toStdString() == ""; }

    /*!
     *  \brief enleverGuillemets() method
     *
     *  Static method (it will be needed in other classes)
     *  Used to detached the quotation marks
     *  When a user wants to put an expression into the calculator, he has to put it between quotations marks
     *  Then the expression will be evaluated
     *
     *  \param const QString&
     *  \return pointer to LiExpression
     */
    static LiExpression* enleverGuillemets(const QString& s);

    /*!
     *  \brief getValue() method
     *
     *  Accessor of the LiEntiere class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiEntiere)
     *
     *  \param no parameter
     *  \return int
     */
    int getValue() const { throw LiException("error : pas de getValue sur une Expression"); }

    /*!
     *  \brief getNumerator() method
     *
     *  Accessor of the LiRationnelle class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiRationnelle)
     *
     *  \param no parameter
     *  \return int
     */
    int getNumerateur() const { throw LiException("error : pas de getNumerateur sur une Expression"); }

    /*!
     *  \brief getDenominator() method
     *
     *  Accessor of the LiRationnelle class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiRationnelle)
     *
     *  \param no parameter
     *  \return int
     */
	int getDenominateur() const { throw LiException("error : pas de getDenominateur sur une Expression"); }

    /*!
     *  \brief getReel() method
     *
     *  Accessor of the LiReelle class (pure virtual in the Litterale class)
     *  Throws a LiException (can only be called on LiRationnelle)
     *
     *  \param no parameter
     *  \return double
     */
	double getReel() const { throw LiException("error : pas de getReel sur un atome"); }

    /*!
     *  \brief operator+
     *
     *  Overloaded operator+
     *  const method (attribut should not be modified)
     *  Used to add a LiExpression and a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
    Litterale* operator+ (const Litterale& li) const;

    /*!
     *  \brief operator-
     *
     *  Overloaded operator-
     *  const method (attribut should not be modified)
     *  Used to substract to a LiExpression a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
	Litterale* operator- (const Litterale& li) const;

    /*!
     *  \brief operator/
     *
     *  Overloaded operator/
     *  const method (attribut should not be modified)
     *  Used to divid a LiExpression by a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
	Litterale* operator/ (const Litterale& li) const;

    /*!
     *  \brief operator*
     *
     *  Overloaded operator*
     *  const method (attribut should not be modified)
     *  Used to multiply a LiExpression and a Litterale
     *  Construct a new QString (concatenation of the 2 Litterale*)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return pointer to Litterale
     */
	Litterale* operator* (const Litterale& li) const;

    /*!
     *  \brief operator==
     *
     *  Overloaded operator==
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator== (const Litterale& li) const { throw LiException("error : pas de == sur une Expression"); }

    /*!
     *  \brief operator!=
     *
     *  Overloaded operator!=
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator!= (const Litterale& li) const { throw LiException("error : pas de != sur une Expression"); }

    /*!
     *  \brief operator<=
     *
     *  Overloaded operator<=
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator<= (const Litterale& li) const { throw LiException("error : pas de <= sur une Expression"); }

    /*!
     *  \brief operator>=
     *
     *  Overloaded operator>=
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator>= (const Litterale& li) const { throw LiException("error : pas de >= sur une Expression"); }

    /*!
     *  \brief operator<
     *
     *  Overloaded operator>
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator< (const Litterale& li) const { throw LiException("error : pas de < sur une Expression"); }

    /*!
     *  \brief operator>
     *
     *  Overloaded operator>
     *  Throws a LiException (can not compare a Litterale and a LiExpression)
     *
     *  \param const Litterale&
     *  \return Litterale*
     */
    Litterale* operator> (const Litterale& li) const { throw LiException("error : pas de > sur une Expression"); }

    /*!
     *  \brief NUM() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Num();

    /*!
     *  \brief DEN() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Den();

    /*!
     *  \brief RE() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Re();

    /*!
     *  \brief IM() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Im();

    /*!
     *  \brief NEG() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* Neg();

    /*!
     *  \brief DIV() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Div(const Litterale& li);

    /*!
     *  \brief MOD() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Mod(const Litterale& li);

    /*!
     *  \brief AND() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* And(const Litterale* li);

    /*!
     *  \brief OR() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Or(const Litterale* li);

    /*!
     *  \brief NOT() method
     *
     *  Construct a new QString (concatenation of the operator and the 2 Litterales)
     *
     *  \param const Litterale& (parameter should not be modified)
     *  \return Litterale*
     */
    Litterale* Not();

    Litterale* Clone() const { return new LiExpression(exp); }
};






//////////////////////////////////////// MEMENTO ////////////////////////////////////////


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




//////////////////////////////////////// PILE ////////////////////////////////////////

/// \class The Pile class
///
/// \brief Class to contain all the Litterale of the calculator
///
///

class Pile : public QObject {
    //The pile emits a signal when it is modified => Q_OBJECT
    Q_OBJECT

    Litterale** li; /*!< li : attribut of type Litterale** (tab of pointer to Litterale)*/
    unsigned int nb; /*!< nb : attribut of type unsigned int (number of element in the stack)*/
    unsigned int nbMax; /*!< nbMax : attribut of type unsigned int (capacity of the stack)*/
    unsigned int nbAffiche; /*!< message : attribut of type unsigned int (number of element to display)*/
    QString message; /*!< exp : attribut of type QString (message about the state of the pile, a disfunctionment...)*/

    /*!
     *  \brief agrandissementCapacite() method
     *
     *  Private method to reallocates some memory to the pile in order to increase its capacity
     *
     *  \param no parameter
     *  \return void
     */
    void agrandissementCapacite();

public:
<<<<<<< 5053b611ade148341877aa723b8b13dde212b35b

    /*!
     *  \brief Constructor
     *
     *  Constructor of the Pile class
     *  Inline Method
     *  li, nb, nbMax, nbAffiche and message are set to 0, and then call of agrandissementCapacite()
     *
     *  \param with no parameters
     */
    Pile():li(0),nb(0),nbMax(0),nbAffiche(5),message("") { agrandissementCapacite(); }

    /*!
     *  \brief Destructor
     *
     *  Destructor of the Pile class
     *  Inline Method
     *  Delete all the elements of the stack and the stack itself, because they are all allocated dynamically
     *
     *  \param no parameters
     */
=======
    Pile():li(0),nb(0),nbMax(0),nbAffiche(5),message("") {agrandissementCapacite();}
>>>>>>> uml
    ~Pile() { for (unsigned int i = 0; i < nb; i++) delete li[i]; delete[] li; }

    /*!
     *  \brief estVide() method
     *
     *  Returns true if the stack is empty
     *  Inline const Method
     *
     *  \param no parameters
     *  \return bool
     */
    bool estVide() const {return nb==0;}

    /*!
     *  \brief taille() method
     *
     *  Accessor to the size of the stack
     *  Inline const Method
     *
     *  \param no parameters
     *  \return unsigned int
     */
    unsigned int taille() const { return nb; }

    /*!
     *  \brief affiche() method
     *
     *  Method to print the stack
     *  Const Method
     *
     *  \param no parameters
     *  \return void
     */
    void affiche() const;


    void setMessage(const QString& m) { message = m; if (message != ""){ newMessage(); modificationEtat(); }}

    /*!
     *  \brief getMessage() method
     *
     *  Accessor to the message attribute (of type QString)
     *  Inline const Method
     *
     *  \param no parameter
     *  \return QString
     */
    QString getMessage() const { return message; }

    /*!
     *  \brief getMessage() method
     *
     *  Accessor to the number of element of the stack to display
     *  Inline const Method
     *
     *  \param no parameter
     *  \return unsigned int
     */
    unsigned int getNbLitteralesToAffiche()const { return nbAffiche; }

    /*!
     *  \brief getLi() method
     *
     *  Accessor to the message stack itself
     *  Inline const Method
     *
     *  \param no parameter
     *  \return Litterale**
     */
    Litterale** getLi()const { return li; }

    /*!
     *  \brief getMessage() method
     *
     *  Method to set the number of Litterale to display
     *  Inline Method
     *
     *  \param 1 parameter of type int
     *  \return void
     */
    void setNbLitteralesToAffiche(int n) { if (n>0) nbAffiche = n; }

    /*!
     *  \brief push() method
     *
     *  Accessor to the add a Litterale to the stack
     *  If the stack is full, call of agrandissementCapacite()
     *
     *  \param 1 parameter of type pointer to Litterale
     *  \return void
     */
    void push(Litterale* li);

    /*!
     *  \brief top() method
     *
     *  Accessor to the element on the top of the stack
     *  Const Method
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* top() const;

    /*!
     *  \brief dup() method
     *
     *  Method to duplicate the element on the top of the stack
     *  If the stack is full, call of agrandissementCapacite()
     *
     *  \param no parameter
     *  \return void
     */
    void dup();

    /*!
     *  \brief drop() method
     *
     *  Method to delete the element on the top of the stack
     *
     *  \param no parameter
     *  \return void
     */
    void drop();

    /*!
     *  \brief swap() method
     *
     *  Method to swap the 2 elements on the top of the stack
     *
     *  \param no parameter
     *  \return void
     */
    void swap();

    /*!
     *  \brief undo() method
     *
     *  Method to reset the state of the stack before the last operation
     *
     *  \param no parameter
     *  \return void
     */
    void undo();

    /*!
     *  \brief undo() method
     *
     *  Method to cancel the action of a redo
     *
     *  \param no parameter
     *  \return void
     */
    void redo();

    /*!
     *  \brief clear() method
     *
     *  Method to clear the stack of all the Litterale that might be in it (delete them)
     *
     *  \param no parameter
     *  \return void
     */
    void clear();

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
    void newMessage();
};





//////////////////////////////////////// CALCULATRICE ////////////////////////////////////////

/// \class The Calculatrice class
///
/// \brief Class to manage all the calculator
///
///

class Calculatrice {
    Pile* pile; /*!< pile : attribut of type Pile* (pointer to a stack)*/
    QString lastoperateur; /*!< lastoperateur : attribut of type QString (to remember the lastoperation made)*/
    Litterale* lastarg1; /*!< lastarg1 : attribut of type Litterale* (to remember the last Litterale used in an operation)*/
    Litterale* lastarg2; /*!< lastarg2 : attribut of type Litterale* (to remember the last Litterale used in an operation if it was a binary operator)*/
    map<QString,Litterale*> mapAtome; /*!< mapAtome : attribut of type map<QString,Litterale*> (to manage all the Atomes in the calculator (associate a QString to a Litterale*))*/
public:
    /*!
     *  \brief Constructor
     *
     *  Constructor of the Calculatrice class
     *  the stack is initialize with the argument
     *  lastoperateur is initialize with an empty QString
     *  lastarg1 and lastarg2 with nullptr
     *  Inline method
     *
     *  \param 1 parameter of type Pile*
     */
    Calculatrice(Pile* p):pile(p), lastoperateur(""), lastarg1(nullptr), lastarg2(nullptr) {}

    /*!
     *  \brief Destructor
     *
     *  Destructor of the Calculatrice class (inline method)
     *  Needed because we have to delete the stack which was allocated dynamically
     *
     *  \param no parameter
     */
    ~Calculatrice() {  delete pile; }

    /*!
     *  \brief getLastOp() method
     *
     *  Accessor to lastoperator
     *  Const inline method (attribut should not be modified)
     *
     *  \param no parameter
     *  \return QString
     */
    QString getLastOp() const { return lastoperateur; }

    /*!
     *  \brief getLastArg1() method
     *
     *  Accessor to lastarg1
     *  Const inline method (attribut should not be modified)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* getLastArg1() const { return lastarg1; }

    /*!
     *  \brief getLastArg2() method
     *
     *  Accessor to lastarg2
     *  Const inline method (attribut should not be modified)
     *
     *  \param no parameter
     *  \return Litterale*
     */
    Litterale* getLastArg2() const { return lastarg2; }

    /*!
     *  \brief getPile() method
     *
     *  Accessor to the stack
     *  Const inline method (attribut should not be modified)
     *
     *  \param no parameter
     *  \return Pile*
     */
    Pile* getPile() const {return pile;}

    /*!
     *  \brief operateur2() method
     *
     *  \param const QString& s
     *  \return void
     */
    void operateur2(const QString& s);

    /*!
     *  \brief operateur1() method
     *
     *  \param const QString& s
     *  \return void
     */
    void operateur1(const QString& s);

    /*!
     *  \brief operateurp() method
     *
     *  \param const QString& s
     *  \return void
     */
    void operateurp(const QString& s);  

    /*!
     *  \brief enregistrerLast() method
     *
     *  \param const QString& s
     *  \return void
     */
    void enregistrerLast(const QString& s);

    /*!
     *  \brief commande() method
     *
     *  \param const QString& s
     *  \return void
     */
    void commande(const QString & s);

    /*!
     *  \brief executer() method
     *
     *  \param no parameter
     *  \return void
     */
    void executer();

    /*!
     *  \brief Eval() method
     *
     *  \param const QString&
     *  \return void
     */
    void Eval(const QString& exp1);

    /*!
     *  \brief infixePostfixe() method
     *
     *  \param const QString&
     *  \return QString
     */
    QString infixePostfixe(const QString& s);

    /*!
     *  \brief addAtome() method
     *
     *  \param 2 parameters of type const QString& and Litteral*
     *  \return void
     */
    void addAtom(const QString&s, Litterale* li);

    /*!
     *  \brief removeAtome() method
     *
     *  \param const QString&
     *  \return void
     */
    void removeAtom(const QString& s);

    /*!
     *  \brief alreadyExists() method
     *
     *  \param const Qstring&
     *  \return bool
     */
    bool alreadyExists(const QString& s);

    /*!
     *  \brief afficherTousAtomes() method
     *
     *  \param const Qstring&
     *  \return void
     */
    void afficherTousAtomes() const;
};


/*!
 *  \brief estUnOperateurBinaire() method
 *
 *  Method used to know if a QString is a binary operator
 *
 *  \param const QString& s
 *  \return bool
 */
bool estUnOperateurBinaire (const QString& s);

/*!
 *  \brief estUnOperateurUnaire() method
 *
 *  Method used to know if a QString is a unaire operator
 *
 *  \param const QString& s
 *  \return bool
 */
bool estUnOperateurDePile (const QString& s);

/*!
 *  \brief operateur2() method
 *
 *  Method used to know if a QString is a stack operator
 *
 *  \param const QString& s
 *  \return bool
 */
bool estUnOperateurDePile(const QString& s);

/*!
 *  \brief estEntier() method
 *
 *  Method used to know if a QString is an integer
 *  Use regular expressions
 *
 *  \param const QString& s
 *  \return bool
 */
bool estEntier (const QString& s);

/*!
 *  \brief estDouble() method
 *
 *  Method used to know if a QString is an double
 *  Use regular expressions
 *
 *  \param const QString& s
 *  \return bool
 */
bool estDouble (const QString& s);

/*!
 *  \brief estExpression() method
 *
 *  Method used to know if a QString is an Expression
 *  Use regular expressions
 *
 *  \param const QString& s
 *  \return bool
 */
bool estExpression(const QString& s);

/*!
 *  \brief estAtomeGuillemets() method
 *
 *  Method used to know if a QString is an atome with quotes
 *  Use regular expressions
 *
 *  \param const QString& s
 *  \return bool
 */
bool estAtomeGuillemets(const QString& s);

/*!
 *  \brief estAtome() method
 *
 *  Method used to know if a QString is an atome without quotes
 *  Use regular expressions
 *
 *  \param const QString& s
 *  \return bool
 */
bool estAtome(const QString& s);

bool is1operator(const QString& s);
bool is2operator(const QString& s);

/*!
 *  \brief estAtomeGuillemets() method
 *
 *  Method used to know if a of the type OP(...)
 *
 *  \param const QString& s
 *  \return bool
 */
bool is1operatorPP(const QString& s);

/*!
 *  \brief estAtomeGuillemets() method
 *
 *  Method used to know if a of the type OP(..., ...)
 *
 *  \param const QString& s
 *  \return bool
 */
bool is2operatorPVP(const QString& s);

/*!
 *  \brief estAtomeGuillemets() method
 *
 *  Method used to know if the priority of the operator ptop is higher than the priority of the operator qc
 *
 *  \param const QString& s
 *  \return bool
 */
bool PrioritePrecedentSup(const QChar qc, const QChar ptop);

/*!
 *  \brief estAtomeGuillemets() method
 *
 *  Method used to know the priority of an operator
 *  Throws an error if the parameter is not an operator
 *
 *  \param const QString& s
 *  \return int
 */
int prioriteOp(const QString& s);






#endif // MANAGER_H_INCLUDED

