#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

/**
 * \file calculatrice.h
 * \brief file where the class Calculatrice is defined
 *
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "pile.h"







//////////////////////////////////////// CALCULATRICE ////////////////////////////////////////

/// \class The Calculatrice class
///
/// \brief Class to manage the calculator
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
    void newAtom(const QString&, const QString&);
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

