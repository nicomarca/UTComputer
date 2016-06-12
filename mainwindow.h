#ifndef MAINWINDOW_H
#define MAINWINDOW_H

/**
 * \file mainwindow.h
 * \brief file where the class MainWindow is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "calculatrice.h"
#include <QMediaPlayer>


///
///
///
namespace Ui {
class MainWindow;
}

///
/// \brief The MainWindow class
///
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow
     *
     * Constructor
     *
     * \param parent
     */
    explicit MainWindow(QWidget *parent = 0);

    /*!
     *  \brief Destructor
     *
     *  Destructor of the MainWindow class.
     *
     */
    ~MainWindow() {
        for(unsigned int i=0; i<tailleMemento; i++) {
            delete m[i];
        }
        delete cal;
        delete p;
        delete ui;
    }
    /*!
     *  \brief Annalyses the command line
     *
     */
    void getNextCommande();

private slots:
    /*!
     *  \brief Private SLOT when pressing a key of the keyboard
     *
     *  \param A QEvent* object which represents the pressed key of the keyboard
     *  \param A QObject* which represent an object of the main window
     *
     */
    bool eventFilter(QObject* target, QEvent *event);
    /*!
     *  \brief Private SLOT when the button 0 is clicked
     *
     *  used to writte a "0" in the command line
     *
     */

    void on_pushButton0_clicked();
    /*!
     *  \brief Private SLOT when the button 1 is clicked
     *
     *  used to writte a "1" in the command line
     *
     */
    void on_pushButton1_clicked();
    /*!
     *  \brief Private SLOT when the button 2 is clicked
     *
     *  used to writte a "2" in the command line
     *
     */
    void on_pushButton2_clicked();
    /*!
     *  \brief Private SLOT when the button 3 is clicked
     *
     *  used to writte a "3" in the command line
     *
     */
    void on_pushButton3_clicked();
    /*!
     *  \brief Private SLOT when the button 4 is clicked
     *
     *  used to writte a "4" in the command line
     *
     */
    void on_pushButton4_clicked();
    /*!
     *  \brief Private SLOT when the button 5 is clicked
     *
     *  used to writte a "5" in the command line
     *
     */
    void on_pushButton5_clicked();
    /*!
     *  \brief Private SLOT when the button 6 is clicked
     *
     *  used to writte a "6" in the command line
     *
     */
    void on_pushButton6_clicked();
    /*!
     *  \brief Private SLOT when the button 7 is clicked
     *
     *  used to writte a "7" in the command line
     *
     */
    void on_pushButton7_clicked();
    /*!
     *  \brief Private SLOT when the button 8 is clicked
     *
     *  used to writte a "8" in the command line
     *
     */
    void on_pushButton8_clicked();
    /*!
     *  \brief Private SLOT when the button 9 is clicked
     *
     *  used to writte a "9" in the command line
     *
     */
    void on_pushButton9_clicked();
    /*!
     *  \brief Private SLOT when the button Space is clicked
     *
     *  used to writte a " " in the command line
     *
     */
    void on_pushButtonSpace_clicked();
    /*!
     *  \brief Private SLOT when the button . is clicked
     *
     *  used to writte a "." in the command line
     *
     */
    void on_pushButtonPoint_clicked();
    /*!
     *  \brief Private SLOT when the button ( is clicked
     *
     *  used to writte a "(" in the command line
     *
     */
    void on_pushButtonLeftPar_clicked();
    /*!
     *  \brief Private SLOT when the button ) is clicked
     *
     *  used to writte a ")" in the command line
     *
     */
    void on_pushButtonRightPar_clicked();
    /*!
     *  \brief Private SLOT when the button ' is clicked
     *
     *  used to writte a "'" in the command line
     *
     */
    void on_pushButtonQuote_clicked();

    /*!
     *  \brief Private SLOT when the button BackSpace is clicked
     *
     *  used to erase the last letter behind the focus
     *
     */
    void on_pushButtonBack_clicked();

    //BOUTONS D'OPERATEURS ARITHMETIQUES
    /*!
     *  \brief Private SLOT when the button + is clicked
     *
     *  used to writte a "+" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonAdd_clicked();
    /*!
     *  \brief Private SLOT when the button - is clicked
     *
     * used to writte a "-" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonMinus_clicked();
    /*!
     *  \brief Private SLOT when the button * is clicked
     *
     *  used to writte a "*" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonMul_clicked();
    /*!
     *  \brief Private SLOT when the button / is clicked
     *
     * used to writte a "/" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonDi_clicked();
    /*!
     *  \brief Private SLOT when the button DIV is clicked
     *
     * used to writte a "DIV" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonDiv_clicked();
    /*!
     *  \brief Private SLOT when the button $ is clicked
     *
     * used to writte a "$" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonComp_clicked();
    /*!
     *  \brief Private SLOT when the button RE is clicked
     *
     * used to writte a "RE" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonRe_clicked();
    /*!
     *  \brief Private SLOT when the button IM is clicked
     *
     * used to writte a "IM" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonIm_clicked();
    /*!
     *  \brief Private SLOT when the button DEN is clicked
     *
     * used to writte a "DEN" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonDen_clicked();
    /*!
     *  \brief Private SLOT when the button NUM is clicked
     *
     * used to writte a "NUM" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonNum_clicked();
    /*!
     *  \brief Private SLOT when the button NEG is clicked
     *
     * used to writte a "NEG" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonNeg_clicked();
    /*!
     *  \brief Private SLOT when the button MOD is clicked
     *
     * used to writte a "MOD" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonMod_clicked();

    //BOUTONS D'OPERATEURS LOGIQUES
    /*!
     *  \brief Private SLOT when the button = is clicked
     *
     * used to writte a "=" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonEq_clicked();
    /*!
     *  \brief Private SLOT when the button != is clicked
     *
     * used to writte a "!=" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonDif_clicked();
    /*!
     *  \brief Private SLOT when the button <= is clicked
     *
     * used to writte a "<=" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonInfeq_clicked();
    /*!
     *  \brief Private SLOT when the button < is clicked
     *
     * used to writte a "<" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonInf_clicked();
    /*!
     *  \brief Private SLOT when the button > is clicked
     *
     * used to writte a ">" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonSup_clicked();
    /*!
     *  \brief Private SLOT when the button >= is clicked
     *
     * used to writte a ">=" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonSupeq_clicked();
    /*!
     *  \brief Private SLOT when the button AND is clicked
     *
     * used to writte a "AND" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonAnd_clicked();
    /*!
     *  \brief Private SLOT when the button OR is clicked
     *
     * used to writte a "OR" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonOr_clicked();
    /*!
     *  \brief Private SLOT when the button NOT is clicked
     *
     * used to writte a "NOT" in the command line or to directly make this operation and to stack the result
     *
     */
    void on_pushButtonNot_clicked();
    /*!
     *  \brief Private SLOT when the button ENTER is clicked
     *
     * used to evaluate the command line
     *
     */
    void on_pushButtonEnter_clicked();


    //BOUTONS OPERATEURS DE PILE
    /*!
     *  \brief Private SLOT when the button LASTARGS is clicked
     *
     * used to stack the litterales used for the last operation
     *
     */
    void on_pushButtonLastargs_clicked();
    /*!
     *  \brief Private SLOT when the button CLEAR is clicked
     *
     * used to clear the stack
     *
     */
    void on_pushButtonClear_clicked();
    /*!
     *  \brief Private SLOT when the button LASTOP is clicked
     *
     * used to redo the last used operator
     *
     */
    void on_pushButtonLastop_clicked();
    /*!
     *  \brief Private SLOT when the button DROP is clicked
     *
     * used to unstack the litteral at the top of the stack
     *
     */
    void on_pushButtonDrop_clicked();
    /*!
     *  \brief Private SLOT when the button DUP is clicked
     *
     * used to stack a copy of the litteral situated at the top of the stack
     *
     */
    void on_pushButtonDup_clicked();
    /*!
     *  \brief Private SLOT when the button SWAP is clicked
     *
     * used to invert the place of the two last litterals stacked
     *
     */
    void on_pushButtonSwap_clicked();
    /*!
     *  \brief Private SLOT when the button UNDO is clicked
     *
     * used to reestablish the state of the calculator before the last operation
     */
    void on_pushButtonUndo_clicked();
    /*!
     *  \brief Private SLOT when the button REDO is clicked
     *
     * ised to reestablish the state of the calculator before the last operation UNDO
     */
    void on_pushButtonRedo_clicked();

    /*!
     *  \brief Private SLOT when the value of the spinbox is changed
     *
     *  used to change the number of displayed lines
     *
     */
    void on_nbLignes_valueChanged(int arg1);
    /*!
     *  \brief Private SLOT when the button AC is clicked
     *
     *  used to clear the command line
     *
     */
    void on_pushButtonAC_clicked();
    /*!
     *  \brief Private SLOT when the button Sound is clicked
     *
     *  used to activate or deactivate the sound
     *
     */
    void on_pushButtonSound_clicked(); //Activate/Desactive sound

    /*!
     *  \brief Private SLOT when the checkbox is clicked
     *
     *  used to hide or to display the keyboard of the calculator
     *
     */
    void on_checkBox_clicked(bool checked);

    /*!
     *  \brief Private SLOT when the button EVAL is clicked
     *
     *  used to evaluate an expression
     *
     */
    void on_pushButtonEval_clicked();

    /*!
     *  \brief Private SLOT when a Item from the comboBox is selected
     *
     *  used to write an existing Atom in the command line
     *
     */
    void on_comboBoxAtomes_activated(const QString &arg1);
    /*!
     *  \brief Private SLOT when the button STO is clicked
     *
     *  used to write an existing Atom in the command line
     *
     */
    void on_pushButtonSto_clicked();
    /*!
     *  \brief Private SLOT when the button FORGET is clicked
     *
     *  used to write an existing Atom in the command line
     *
     */
    void on_pushButtonForget_clicked();

    /*!
     *  \brief Public SLOT to add the string of an Atom in the comboBox
     *
     */
    void addAtom(const QString&, const QString&);
    /*!
     *  \brief Public SLOT to remove the string of an Atom in the comboBox
     *
     */
    void rmAtom(const QString&, const QString&);
    /*!
     *  \brief Public SLOT to refresh the pile's display
     *
     */
    void refresh();
    /*!
     *  \brief Public SLOT to play the sound's message
     *
     */
    void playsound()
    {
        if (pop->isMuted()) return;
        if (pop->state()== QMediaPlayer::PlayingState) pop->setPosition(0);
        else if (pop->state() == QMediaPlayer::StoppedState) pop->play();
    }
private:
    Ui::MainWindow *ui; /*!< ui : attribut of type Ui::MainWindow* */
    Calculatrice* cal; /*!< cal : attribut of type Calculatrice* */
    Pile* p; /*!< cal : attribut of type Calculatrice* */
    bool exp; /*!< exp : attribut of type bool*/
    bool undo; /*!< undo : attribut of type bool*/

    QStack <Memento*> m; /*!< m : attribut of type QStack<Memento*>*/
    unsigned int tailleMemento; /*!< tailleMemento : attribut of type unsigned int* */

    QMediaPlayer* pop; /*!< pop : attribut of type QMediaPlayer* */
};

#endif // MAINWINDOW_H
