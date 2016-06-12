#ifndef PILE_H
#define PILE_H

/**
 * \file pile.h
 * \brief file where the classes Pile and Memento are defined
 *
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "liexpression.h"

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

#endif // PILE_H
