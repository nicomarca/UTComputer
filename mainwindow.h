#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "manager.h"
#include <QMediaPlayer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); //Destructeur

private slots:
    ///SLOT when pressing a key of the keyBoard
    void keyPressEvent(QKeyEvent *event);

    ///SLOTS when clicking on one of the PushButton
    void on_pushButton0_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();
    void on_pushButtonSpace_clicked();

    void on_pushButtonPoint_clicked();
    void on_pushButtonLeftPar_clicked();
    void on_pushButtonRightPar_clicked();
    void on_pushButtonQuote_clicked();

    void on_pushButtonBack_clicked();

    //BOUTONS D'OPERATEURS ARITHMETIQUES
    void on_pushButtonAdd_clicked();
    void on_pushButtonMinus_clicked();
    void on_pushButtonMul_clicked();
    void on_pushButtonDi_clicked();
    void on_pushButtonDiv_clicked();
    void on_pushButtonComp_clicked();
    void on_pushButtonRe_clicked();
    void on_pushButtonIm_clicked();
    void on_pushButtonDen_clicked();
    void on_pushButtonNum_clicked();
    void on_pushButtonNeg_clicked();
    void on_pushButtonMod_clicked();

    //BOUTONS D'OPERATEURS LOGIQUES
    void on_pushButtonEq_clicked();
    void on_pushButtonDif_clicked();
    void on_pushButtonInfeq_clicked();
    void on_pushButtonInf_clicked();
    void on_pushButtonSup_clicked();
    void on_pushButtonSupeq_clicked();
    void on_pushButtonAnd_clicked();
    void on_pushButtonOr_clicked();
    void on_pushButtonNot_clicked();

    void on_pushButtonEnter_clicked();


    //BOUTONS OPERATEURS DE PILE
    void on_pushButtonLastargs_clicked();
    void on_pushButtonClear_clicked();
    void on_pushButtonLastop_clicked();
    void on_pushButtonDrop_clicked();
    void on_pushButtonDup_clicked();
    void on_pushButtonSwap_clicked();
    void on_pushButtonUndo_clicked();
    void on_pushButtonRedo_clicked();

    void on_nbLignes_valueChanged(int arg1); //Change the number of displayed lines
    void on_pushButtonAC_clicked(); //Clear the command line
    void on_pushButtonSound_clicked(); //Activate/Desactive sound

public slots:
    void refresh(); //Slot to refresh the pile's display
    void getNextCommande(); //Slot to annalyse the command line
    void playsound() //Slot playing (or not) the "pop"
    {
        if (pop->isMuted()) return;
        if (pop->state()== QMediaPlayer::PlayingState) pop->setPosition(0);
        else if (pop->state() == QMediaPlayer::StoppedState) pop->play();
    }

private:
    Ui::MainWindow *ui; //Pointer to the main window
    Calculatrice* cal; //Pointer to the Calculator (the controler)
    Pile* p; //Pointer to the pile managed by cal
    Memento* m1; //Pointer to a save of the pile at a T moment (able to UNDO)
    Memento* m2; //Pointer to a save of the pile at a T moment (able to REDO)
    bool exp; //Permit us to know if we are writting in an expression or not in the command line
    bool undo; //True if the user just did an UNDO, false otherwise. Allow or not REDO.

    QMediaPlayer* pop; //Pointer to the sound file
};

#endif // MAINWINDOW_H
