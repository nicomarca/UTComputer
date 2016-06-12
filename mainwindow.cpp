/**
 * \file mainwindow.cpp
 * \brief file where the methods of the MainWindow class are defined
 *
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QLineEdit>
#include<QTableWidget>
#include<QKeyEvent>
#include<QOBject>
#include<QMediaPlayer>
#include<QComboBox>
#include<qcombobox.h>
#include<QShortcut>
#include<QKeySequence>



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ///INITIALIZATION OF THE ATTRIBUTES
    exp = false;
    undo = false;
    p = new Pile;
    //m1 = p->SaveStatetoMemento();
    //m2 = p->SaveStatetoMemento();
    m.push(p->SaveStatetoMemento());
    tailleMemento = 1;
    cal = new Calculatrice(p);
    ui->setupUi(this);
    pop = new QMediaPlayer();
    pop->setMedia(QUrl("qrc:/sounds/pop.mp3")); //access to the file
    pop->setMuted(false); //Not muted by default

    ///GRAPHIC INITIALIZATIONs

    // Put a title on the application windows
    this->setWindowTitle("UTComputer");
    //size of the main window
    this->setFixedSize(400,730);

    ui->nbLignes->setValue(p->getNbLitteralesToAffiche()); //Pile Display
    ui->Message->setAlignment(Qt::AlignHCenter);
    ui->Message->setText("Bienvenue sur UTComputer !");
    ui->vuePile->setRowCount(p->getNbLitteralesToAffiche());
    ui->vuePile->setColumnCount(1);
    // inhibit modification
    ui->vuePile->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // make invisible the column table.
    ui->vuePile->horizontalHeader()->setVisible(false);
    // adjust automatically the window's width.
    ui->vuePile->horizontalHeader()->setStretchLastSection(true);
    //  create a list of tables "i:" for each line and the items of each list.
    QStringList numberList;
    for(unsigned int i=p->getNbLitteralesToAffiche(); i>0; i--) {
        QString str= QString::number(i) + " : ";
        numberList<<str;
        // creation of the item of each line initialized with an empty chain
        ui->vuePile->setItem(i-1, 0, new QTableWidgetItem(""));
    }
    // print the label list on a vertial header.
    ui->vuePile->setVerticalHeaderLabels(numberList);

    ui->expression->setFocus(Qt::OtherFocusReason); //Focus directly on the command line (no need to click on it)

    ui->expression->installEventFilter(this);


    // connections
    connect(p,SIGNAL(modificationEtat()), this,SLOT(refresh()));
    connect(p, SIGNAL(newMessage()), this, SLOT(playsound()));
    connect(cal, SIGNAL(newAtom(const QString&, const QString&)), this, SLOT(addAtom(const QString&,const QString&)));
    connect(cal, SIGNAL(deleteAtom(const QString&, const QString&)), this, SLOT(rmAtom(const QString&, const QString&)));

    QKeySequence* CtrlZ = new QKeySequence(Qt::CTRL + Qt::Key_Z);
    QShortcut* raccourci = new QShortcut(*CtrlZ, this );
    connect(raccourci, SIGNAL(activated()), this, SLOT(on_pushButtonUndo_clicked()));
    QKeySequence* CtrlY = new QKeySequence(Qt::CTRL + Qt::Key_Y);
    QShortcut* raccourci2 = new QShortcut(*CtrlY, this );
    connect(raccourci2, SIGNAL(activated()), this, SLOT(on_pushButtonRedo_clicked()));
}


void MainWindow::refresh() {
    //the message
    ui->Message->setText(p->getMessage());

    //put everything to NULL
    for(unsigned int i=0; i<p->getNbLitteralesToAffiche(); i++)
        ui->vuePile->item(i,0)->setText("");

    //and then updtate
    unsigned int nb = 0;
    Pile::iterator it = p->end();
    --it;
    for(it; it >= p->begin() && nb < p->getNbLitteralesToAffiche(); --it, nb++){
        ui->vuePile->item(p->getNbLitteralesToAffiche()-1-nb,0)->setText(QString::fromStdString((*it).toString()));
    }
}

void MainWindow::getNextCommande(){
    if (exp) return;
    //save the pile before changing it
    //m1 = p->SaveStatetoMemento();





    p->setMessage(""); //the message is not usefull anymore

    // getting text for the command bar
    QString c=ui->expression->text();
    // extraction of each element from the line
    //(we suppose that <space> is the field separator)
    QTextStream stream(&c);
    QString com;
    try{
    do {
        stream>>com; // element extraction
        if (com!="") {

            if(com == "UNDO") {
                on_pushButtonUndo_clicked();
            }
            else {
                if(com == "REDO") {
                    on_pushButtonRedo_clicked();
                }
                else {
                    undo = false;
                    cal->commande(com); // send the command to the controller
                }
            }

            if(com != "UNDO" && com != "REDO") {
                while(m.size() != tailleMemento) {
                    m.pop_back();
                }
                m.push(p->SaveStatetoMemento());
                tailleMemento++;
                std::cout << "taille memento :" <<tailleMemento << endl;
                std::cout << "taille m.size :" << m.size() << endl;
            }

        }
    }while (com!="");
    } catch(LiException e) {
        p->setMessage(e.getInfo());
    }
    ui->expression->clear(); //clear the command line

}

///DEFINITION DES SLOTS

//Basically, set the command line to the actual text + the text of the pushed button
void MainWindow::on_pushButton0_clicked() { ui->expression->setText(ui->expression->text()+ "0"); }
void MainWindow::on_pushButton1_clicked() { ui->expression->setText(ui->expression->text()+ "1"); }
void MainWindow::on_pushButton2_clicked() { ui->expression->setText(ui->expression->text()+ "2"); }
void MainWindow::on_pushButton3_clicked() { ui->expression->setText(ui->expression->text()+ "3"); }
void MainWindow::on_pushButton4_clicked() { ui->expression->setText(ui->expression->text()+ "4"); }
void MainWindow::on_pushButton5_clicked() { ui->expression->setText(ui->expression->text()+ "5"); }
void MainWindow::on_pushButton6_clicked() { ui->expression->setText(ui->expression->text()+ "6"); }
void MainWindow::on_pushButton7_clicked() { ui->expression->setText(ui->expression->text()+ "7"); }
void MainWindow::on_pushButton8_clicked() { ui->expression->setText(ui->expression->text()+ "8"); }
void MainWindow::on_pushButton9_clicked() { ui->expression->setText(ui->expression->text()+ "9"); }

void MainWindow::on_pushButtonSpace_clicked() { ui->expression->setText(ui->expression->text()+ " "); }
void MainWindow::on_pushButtonPoint_clicked() {ui->expression->setText(ui->expression->text()+ ".");}
void MainWindow::on_pushButtonLeftPar_clicked() {ui->expression->setText(ui->expression->text()+ "(");}
void MainWindow::on_pushButtonRightPar_clicked() {ui->expression->setText(ui->expression->text()+ ")");}

void MainWindow::on_pushButtonQuote_clicked() {
    //If it is the first "'" (or uneven number), the user is writting an expression => exp = true;
    //It it is the second (or even number), the user is not in an expression anymore => exp = false;
    exp = !exp;
    ui->expression->setText(ui->expression->text()+ "'");
}

//clear the command line
void MainWindow::on_pushButtonAC_clicked() {ui->expression->clear();}

//backspace on the command line
void MainWindow::on_pushButtonBack_clicked() {
    QString s = ui->expression->text();
    if (s == "") return;
    QCharRef c = s[s.length()-1];
    if (c == '\'') exp=!exp;
    ui->expression->backspace();
}

///OPERATORS
void MainWindow::on_pushButtonAdd_clicked() {
    //Add the "+" in the command line
    if (exp) ui->expression->setText(ui->expression->text()+ "+");
    //If we are not in an expression, the command line has to be directly evaluate
    else {ui->expression->setText(ui->expression->text()+ " +"); getNextCommande();}
}

void MainWindow::on_pushButtonMinus_clicked() {
    //Add the "-" in the command line
    if (exp) ui->expression->setText(ui->expression->text()+ "-");
    //If we are not in an expression, the command line has to be directly evaluate
    else {ui->expression->setText(ui->expression->text()+ " -"); getNextCommande();}
}
void MainWindow::on_pushButtonMul_clicked() {

    //Add the "*" in the command line
    if (exp) ui->expression->setText(ui->expression->text()+ "*");
    //If we are not in an expression, the command line has to be directly evaluate
    else {ui->expression->setText(ui->expression->text()+ " *"); getNextCommande();}
}

void MainWindow::on_pushButtonDi_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "/");
    else {ui->expression->setText(ui->expression->text()+ " /"); getNextCommande();}
}

void MainWindow::on_pushButtonDiv_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "DIV");
    else {ui->expression->setText(ui->expression->text()+ " DIV"); getNextCommande();}
}

void MainWindow::on_pushButtonMod_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "MOD");
    else {ui->expression->setText(ui->expression->text()+ " MOD"); getNextCommande();}
}

void MainWindow::on_pushButtonComp_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "$");
    else {ui->expression->setText(ui->expression->text()+ " $"); getNextCommande();}
}

void MainWindow::on_pushButtonRe_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "RE");
    else {ui->expression->setText(ui->expression->text()+ " RE"); getNextCommande();}
}

void MainWindow::on_pushButtonIm_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "IM");
    else {ui->expression->setText(ui->expression->text()+ " IM"); getNextCommande();}
}
void MainWindow::on_pushButtonDen_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "DEN");
    else {ui->expression->setText(ui->expression->text()+ " DEN"); getNextCommande();}
}

void MainWindow::on_pushButtonNum_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "NUM");
    else {ui->expression->setText(ui->expression->text()+ " NUM"); getNextCommande();}
}

void MainWindow::on_pushButtonNeg_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "NEG");
    else {ui->expression->setText(ui->expression->text()+ " NEG"); getNextCommande();}
}


void MainWindow::on_pushButtonEq_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "==");
    else {ui->expression->setText(ui->expression->text()+ " =="); getNextCommande();}
}

void MainWindow::on_pushButtonDif_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "!=");
    else {ui->expression->setText(ui->expression->text()+ " !="); getNextCommande();}
}

void MainWindow::on_pushButtonInfeq_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "<=");
    else {ui->expression->setText(ui->expression->text()+ " <="); getNextCommande();}
}

void MainWindow::on_pushButtonInf_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "<");
    else {ui->expression->setText(ui->expression->text()+ " <"); getNextCommande();}
}

void MainWindow::on_pushButtonSup_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ ">");
    else {ui->expression->setText(ui->expression->text()+ " >"); getNextCommande();}
}
void MainWindow::on_pushButtonSupeq_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ ">=");
    else {ui->expression->setText(ui->expression->text()+ " >="); getNextCommande();}
}

void MainWindow::on_pushButtonAnd_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "AND");
    else {ui->expression->setText(ui->expression->text()+ " AND"); getNextCommande();}
}

void MainWindow::on_pushButtonOr_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "OR");
    else {ui->expression->setText(ui->expression->text()+ " OR"); getNextCommande();}
}

void MainWindow::on_pushButtonNot_clicked() {

    if (exp) ui->expression->setText(ui->expression->text()+ "NOT");
    else {ui->expression->setText(ui->expression->text()+ " NOT"); getNextCommande();}
}


void MainWindow::on_pushButtonEnter_clicked(){getNextCommande();}

///PILE OPERATORS
void MainWindow::on_pushButtonLastargs_clicked()
{
    //Obligation to pass by getNextCommande()
    //If not, no save of the pile in the memento => impossible to undo
    ui->expression->setText(ui->expression->text()+ "LASTARGS");
    getNextCommande();
}

void MainWindow::on_pushButtonClear_clicked()
{
    ui->expression->setText(ui->expression->text()+ "CLEAR");
    getNextCommande();
}

void MainWindow::on_pushButtonLastop_clicked()
{
    ui->expression->setText(ui->expression->text()+ "LASTOP");
    getNextCommande();
}

void MainWindow::on_pushButtonDrop_clicked()
{
    ui->expression->setText(ui->expression->text()+ "DROP");
    getNextCommande();
}

void MainWindow::on_pushButtonDup_clicked()
{
    ui->expression->setText(ui->expression->text()+ "DUP");
    getNextCommande();
}

void MainWindow::on_pushButtonSwap_clicked()
{
    ui->expression->setText(ui->expression->text()+ "SWAP");
    getNextCommande();
}

void MainWindow::on_pushButtonEval_clicked()
{
    ui->expression->setText(ui->expression->text()+ "EVAL");
    getNextCommande();
}

void MainWindow::on_pushButtonUndo_clicked()
{
    if(tailleMemento > 0) {
        tailleMemento--;
        p->getStateFromMemento(m[tailleMemento]);
        //Authorizes to redo
        if (!undo) undo = true;
    }
}

void MainWindow::on_pushButtonRedo_clicked()
{
    //check if an undo was done juste before
    if (!undo) { p->setMessage("Il faut effectuer un UNDO avant un REDO"); return; }



    if (tailleMemento < m.size()) {
        p->getStateFromMemento(m[tailleMemento]);
        tailleMemento++;
    }
    else {
        p->setMessage("REDO impossible");
        return;
    }
}

void MainWindow::on_pushButtonSto_clicked()
{
    ui->expression->setText(ui->expression->text()+ "STO");
    getNextCommande();
}

void MainWindow::on_pushButtonForget_clicked()
{
    ui->expression->setText(ui->expression->text()+ "FORGET");
    getNextCommande();
}

void MainWindow::on_pushButtonSound_clicked()
{
    if (pop->isMuted()){
        pop->setMuted(false);
        ui->pushButtonSound->setText("son");
        playsound();
    }


    else {
            pop->setMuted(true);
            ui->pushButtonSound->setText("/");
    }
}

//SpinBox permitting to change the number of displayed lines
void MainWindow::on_nbLignes_valueChanged(int arg1)
{
    //update the number of line to display
    p->setNbLitteralesToAffiche(arg1);
    ui->vuePile->setRowCount(p->getNbLitteralesToAffiche());

    //increase or dicrease the number of lines
    QStringList numberList;
    //reinitialize
    for(unsigned int i=p->getNbLitteralesToAffiche(); i>0; i--) {
        delete ui->vuePile->item(i-1,0);
        QString str= QString::number(i) + " : ";
        numberList<<str;
        ui->vuePile->setItem(i-1, 0, new QTableWidgetItem(""));
    }
    ui->vuePile->setVerticalHeaderLabels(numberList);

    //refresh to put back the items of the pile
    if (p->taille() != 0) p->modificationEtat();
}

void MainWindow::on_checkBox_clicked(bool checked)
{
    if (checked == true) MainWindow::setFixedSize(400,320);
    else MainWindow::setFixedSize(400,730);
}

bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->expression && event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Return) {getNextCommande();}
        //if(keyEvent->key() == Qt::Key_Enter) {getNextCommande();}
        if(keyEvent->key() == Qt::Key_Plus) {getNextCommande();}
        if(keyEvent->key() == Qt::Key_Minus) {getNextCommande();}
        if(keyEvent->key() == Qt::Key_Dollar) {getNextCommande();}
        if(keyEvent->key() == Qt::Key_division) {getNextCommande();}
        if(keyEvent->key() == Qt::Key_Asterisk) {getNextCommande();}
        if(keyEvent->key() == Qt::Key_Apostrophe) {exp=!exp;}
    }
    if (object == ui->expression && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if(keyEvent->key() == Qt::Key_Backspace) {
            QString s = ui->expression->text();
            if (s=="") return false;
            QCharRef c = s[s.length()-1];
            if (c == '\'') exp=!exp;
        }
    }
    return false;
}

void MainWindow::addAtom(const QString& qs, const QString& li)
{
    QString res = qs % " : " % li;
    ui->comboBoxAtomes->addItem(ui->comboBoxAtomes->currentText());
    ui->comboBoxAtomes->setCurrentIndex(0);
    ui->comboBoxAtomes->setItemText(ui->comboBoxAtomes->currentIndex(), res);
}

void MainWindow::rmAtom(const QString& qs, const QString& li)
{

    int n = ui->comboBoxAtomes->findText(qs % " : " % li);
    if (n != -1) ui->comboBoxAtomes->removeItem(n);
}

void MainWindow::on_comboBoxAtomes_activated(const QString& arg1)
{
    unsigned int i=0;
    for (i; i<arg1.length(); i++) if (arg1[i]==':') break;
    QString res = arg1;
    res.truncate(i-1);
    ui->expression->setText(ui->expression->text() + res);
}

