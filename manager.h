#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "liexpression.h"

/**
 * \file manager.h
 * \brief file where the classes Memento, Pile and Calculatrice are defined
 * Handle the treatment of the litterales
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

//////////////////////////////////////// MEMENTO ////////////////////////////////////////

/*!
 * \class The Memento class
 *
 * \brief Class to save the attributes of a pile at a T moment
 */
class Memento {
    //Same attributes as in pile (except message which is not necessary)
    Litterale** li; /*!< li : attribut of type Litterale** (tab of pointer to Litterale)*/
    unsigned int nb; /*!< nb : attribut of type unsigned int (number of element in the saved stack)*/
    unsigned int nbMax; /*!< nbMax : attribut of type unsigned int (capacity of the saved stack)*/
    unsigned int nbAffiche; /*!< message : attribut of type unsigned int (number of element to display in the saved stack)*/
public:

    //The constructor initializes all the attributes of the class with parameters from a pile
    /*!
     * \brief Memento
     *
     * Constructor of the class Memento
     * Inline Method
     *
     * \param l
     * \param n
     * \param nmax
     * \param naff
     *
     *
     */
    Memento(Litterale** l, unsigned int n, unsigned int nmax, unsigned int naff):li(l),nb(n),nbMax(nmax),nbAffiche(naff){}
    //The destructor deletes all the Litterales of li

    /*!
     *  \brief Destructor
     *
     *  Destructor of the Pile class
     *  Inline Method
     *  Delete all the elements of the attribute li and li itself, because they are all allocated dynamically
     *
     *  \param no parameters
     */
    ~Memento() {for (unsigned int i = 0; i < nb; i++) delete li[i]; delete[] li;}
    //Accessors
    /*!
     *  \brief getNb() method
     *
     *  Accessor to the number of element of the saved stack
     *  Inline const Method
     *
     *  \param no parameter
     *  \return unsigned int
     */
    unsigned int getNb()const { return nb; }
    /*!
     *  \brief getNbMax() method
     *
     *  Accessor to the capacity of the saved stack
     *  Inline const Method
     *
     *  \param no parameter
     *  \return unsigned int
     */
    unsigned int getNbMax()const { return nbMax; }
    /*!
     *  \brief getNbAffiche() method
     *
     *  Accessor to the number of element of the saved stack to display
     *  Inline const Method
     *
     *  \param no parameter
     *  \return unsigned int
     */
    unsigned int getNbAffiche()const { return nbAffiche; }
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
     *  \brief getNbLitteralesToAffiche() method
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

    /*!
     * \brief SaveStatetoMemento() method
     *
     * Method to save the state of the pile at a t moment
     * Make a deep copy of all the Litterales of the stack using Clone() method
     * Create a new Memento
     *
     * \return a pointer to an object of the class Memento
     */
    Memento* SaveStatetoMemento() {
        Litterale** newtab = new Litterale*[nbMax];
        for(unsigned int i=0; i<nb; i++) newtab[i]= li[i]->Clone();
        return new Memento(newtab, nb, nbMax, nbAffiche);
    }
    /*!
     * \brief getStateFromMemento() method
     *
     * Method to get back the state of the stack at a T-1 moment
     * Make a deep copy of all the Litterales of the stack using Clone() method
     *
     * \param m : a pointer to an object of the class Memento
     */
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
    /*!
     * \brief The iterator class
     *
     * Permits to go through the stack
     *
     */
    class iterator {
            Litterale** current;/*!< current: the current Litterale */
            /*!
             * \brief iterator
             * Private Constructor with argument
             * \param u
             */
            iterator(Litterale** u):current(u){}

            friend class Pile;
    public:
            /*!
             * \brief iterator
             * Public Constructor with no argument
             */
            iterator():current(0){}
            /*!
             * \brief overloaded operator *
             *
             * Get the current Litterale while going threw the stack
             *
             * \return a const reference to an object of class Litterale
             */
            Litterale& operator*() const { return **current; }
            /*!
             * \brief overloaded operator !=
             *
             * return true if the current Litterale is different from the litteral from the iterator in parameter
             * \param an iterator
             * \return a boolean
             */
            bool operator!=(iterator it) const { return current!=it.current; }
            /*!
             * \brief overloaded operator ++
             *
             * return the next element in the stack
             *
             * \return an iterator
             */
            iterator& operator++(){ ++current; return *this; }
            /*!
             * \brief overloaded operator --
             *
             * return the past element in the stack
             *
             * \return an iterator
             */
            iterator& operator--(){ --current; return *this;}

            /*!
             * \brief overloaded operator >=
             *
             * return true if current litteral >= litteral from the iterator in parameter
             *  \param an iterator
             * \return a boolean
             */
            bool operator>=(iterator it) {return current >= it.current;}
    };
    /*!
     * \brief begin
     * to set the iterator at the beginning of the stack
     * \return an iterator
     */
    iterator begin() { return iterator(li); }
    /*! \brief end
    * to set the iterator at the end of the stack
    * \return an iterator
    */
    iterator end() { return iterator(li+nb); }

signals:
    /*!
     * \brief modificationEtat
     * signal sent when an attribut of the stack is modified
     *
     */
    void modificationEtat();

    /*!
     * \brief newMessag
     * signal sent when the message of the stack is modified
     */
    void newMessage();
};





//////////////////////////////////////// CALCULATRICE ////////////////////////////////////////

/// \class The Calculatrice class
///
/// \brief Class to manage all the calculator
///
///

class Calculatrice : public QObject {
    Q_OBJECT

    Pile* pile; /*!< pile : attribut of type Pile* (pointer to a stack)*/
    QString lastoperateur; /*!< lastoperateur : attribut of type QString (to remember the lastoperation made)*/
    Litterale* lastarg1; /*!< lastarg1 : attribut of type Litterale* (to remember the last Litterale used in an operation)*/
    Litterale* lastarg2; /*!< lastarg2 : attribut of type Litterale* (to remember the last Litterale used in an operation if it was a binary operator)*/
    map<QString,Litterale*> mapAtome; /*!< mapAtome : attribut of type map<QString,Litterale*> (to manage all the Atomes in the calculator (associate a QString to a Litterale*))*/
    unsigned int nbAtoms;
public:
    map<QString, Litterale*> getMapAtome() const {return mapAtome;}
    unsigned int getNbAtoms() const {return nbAtoms;}
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
    Calculatrice(Pile* p):pile(p), lastoperateur(""), lastarg1(nullptr), lastarg2(nullptr), nbAtoms(0) {}

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

signals:
    /*!
     * \brief newAtom()
     * Signal sent when a new Atome is created
     * \param constQString&
     * \return void
     */
    void newAtom(const QString&);
    /*!
     * \brief deleteAtom()
     * Signal sent when a new Atome is created
     * \param constQString&
     * \return void
     */
    void deleteAtom(const QString&);
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

