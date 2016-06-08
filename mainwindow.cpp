#include "mainwindow.h"
#include "manager.h"
#include "ui_mainwindow.h"
#include<QLineEdit>
#include<QTableWidget>
#include<QKeyEvent>
#include<QOBject>
#include<QMediaPlayer>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ///INITIALIZATION OF THE ATTRIBUTES
    exp = false;
    undo = false;
    p = new Pile;
    m1 = p->SaveStatetoMemento();
    m2 = p->SaveStatetoMemento();
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

    // connections
    connect(p,SIGNAL(modificationEtat()), this,SLOT(refresh()));
    connect(ui->expression,SIGNAL(returnPressed()),this,SLOT(getNextCommande()));
    connect(p, SIGNAL(newMessage()), this,SLOT(playsound()));



}

MainWindow::~MainWindow() {delete ui;}


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
    //save the pile before changing it
    m1 = p->SaveStatetoMemento();

    undo = false; //impossible to do an undo now

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
        if (com!="") cal->commande(com); // send the command to the controller
    }while (com!="");
    } catch(LiException e) {
        std::cout<<"OK\n";
        //p->setMessage(QString::fromStdString(e.getInfo()));
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
void MainWindow::on_pushButtonBack_clicked() { ui->expression->backspace();}

///OPERATORS
void MainWindow::on_pushButtonAdd_clicked() {
    //Add the "+" in the command line
    ui->expression->setText(ui->expression->text()+ "+");
    //If we are not in an expression, the command line has to be directly evaluate
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonMinus_clicked() {
    ui->expression->setText(ui->expression->text()+ "-");
    if (!exp) getNextCommande();
}
void MainWindow::on_pushButtonMul_clicked() {

    ui->expression->setText(ui->expression->text()+ "*");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonDi_clicked() {

    ui->expression->setText(ui->expression->text()+ "/");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonDiv_clicked() {

    ui->expression->setText(ui->expression->text()+ "DIV");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonMod_clicked() {

    ui->expression->setText(ui->expression->text()+ "MOD");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonComp_clicked() {

    ui->expression->setText(ui->expression->text()+ "$");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonRe_clicked() {

    ui->expression->setText(ui->expression->text()+ "RE");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonIm_clicked() {

    ui->expression->setText(ui->expression->text()+ "IM");
    if (!exp) getNextCommande();
}
void MainWindow::on_pushButtonDen_clicked() {

    ui->expression->setText(ui->expression->text()+ "DEN");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonNum_clicked() {

    ui->expression->setText(ui->expression->text()+ "NUM");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonNeg_clicked() {

    ui->expression->setText(ui->expression->text()+ "NEG");
    if (!exp) getNextCommande();
}


void MainWindow::on_pushButtonEq_clicked() {

    ui->expression->setText(ui->expression->text()+ "==");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonDif_clicked() {

    ui->expression->setText(ui->expression->text()+ "!=");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonInfeq_clicked() {

    ui->expression->setText(ui->expression->text()+ "<=");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonInf_clicked() {

    ui->expression->setText(ui->expression->text()+ "<");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonSup_clicked() {

    ui->expression->setText(ui->expression->text()+ ">");
    if (!exp) getNextCommande();
}
void MainWindow::on_pushButtonSupeq_clicked() {

    ui->expression->setText(ui->expression->text()+ ">=");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonAnd_clicked() {

    ui->expression->setText(ui->expression->text()+ "AND");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonOr_clicked() {

    ui->expression->setText(ui->expression->text()+ "OR");
    if (!exp) getNextCommande();
}

void MainWindow::on_pushButtonNot_clicked() {

    ui->expression->setText(ui->expression->text()+ "NOT");
    if (!exp) getNextCommande();
}



void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Enter) {  getNextCommande();} //enter key of the keyboard
}

void MainWindow::on_pushButtonEnter_clicked(){  getNextCommande();}

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

void MainWindow::on_pushButtonUndo_clicked()
{
    //saves the state of the pile into m2
    m2 = p->SaveStatetoMemento();
    //the pile gets back its previous state from m1
    p->getStateFromMemento(m1);
    //authorizes the redo
    undo = true;
}

void MainWindow::on_pushButtonRedo_clicked()
{
    //check if an undo was done juste before
    if (!undo) {p->setMessage("Il faut effectuer un UNDO avant un REDO"); return;}
    //saves the state of the pile into m1
    m1 = p->SaveStatetoMemento();
    //the pile gets back the state it had before doing the UNDO
    p->getStateFromMemento(m2);
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

