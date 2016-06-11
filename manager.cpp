#include "manager.h"

using namespace std;




//////////////////////////////////////// PILE ////////////////////////////////////////


void Pile::agrandissementCapacite() {
    Litterale** newtab = new Litterale*[(nbMax+1)*2];
    for(unsigned int i=0; i<nb; i++) newtab[i]=li[i];
    Litterale** old = li;
    li=newtab;
    nbMax=(nbMax+1)*2;
    delete[] old;
}


void Pile::affiche() const {
    fflush(stdin);
    //system("cls");
    cout <<"*************************"<< endl;
    cout << message.toStdString() << endl;
    cout <<"-------------------------" << endl;
    for (unsigned int i = nbAffiche; i>0; i--) {
        if (i <= nb) { cout << i << " : "; li[nb-i]->afficher(); }
        else cout << i << " : " << endl;
    }
    cout <<"-------------------------" << endl;
}


void Pile::push(Litterale* l){
    if (nb==nbMax) agrandissementCapacite();
    li[nb] = l;
    nb++;
    modificationEtat();
}


Litterale* Pile::top() const {
    if (nb == 0) throw LiException("Pile vie , pas de top() possible");
    return li[nb-1];
}


void Pile::dup() {
    if (nb == nbMax) agrandissementCapacite();
    Litterale* newli = li[nb-1];
    if (typeid(*newli) == typeid(LiEntiere)) li[nb] = new LiEntiere(newli->getValue());
    if (typeid(*newli) == typeid(LiReelle)) li[nb] = new LiReelle(newli->getReel());
    if (typeid(*newli) == typeid(LiRationnelle)) li[nb] = new LiRationnelle(newli->getNumerateur(), newli->getDenominateur());
    if (typeid(*newli) == typeid(LiComplexe)) {
        LiNumerique* preelle = dynamic_cast<LiNumerique*>(newli->Re());
        LiNumerique* pimaginaire = dynamic_cast<LiNumerique*>(newli->Im());
        li[nb] = new LiComplexe(preelle, pimaginaire);
    }
    if(typeid(*newli) == typeid(LiExpression)) {
        LiExpression* lie = dynamic_cast<LiExpression*>(newli);
        li[nb] = new LiExpression(lie->getExpression());
    }
    nb++;
    modificationEtat();
}


void Pile::drop() {
    nb--;
    li[nb] = 0;
    modificationEtat();
}


void Pile::swap() {
    Litterale* tmp = li[nb-1];
    li[nb-1] = li[nb-2];
    li[nb-2] = tmp;
    modificationEtat();
}


/*
Litterale* Pile::lastop() {
}


void Pile::lastargs() {
}


void Pile::undo(){
}


void Pile::redo(){
}
*/


void Pile::clear() {
    for(unsigned int i=0; i<nb; i++) {
        delete li[i];
        li[i] = 0;
    }
    nb = 0;
    modificationEtat();
}









bool estUnOperateurBinaire (const QString& s) {
    if (s=="+") return true; if (s=="-") return true; if (s=="*") return true; if (s=="/") return true;
    if (s=="DIV") return true; if (s=="MOD") return true;
    if (s=="$") return true;
    //if (s=="=") return true;
    if (s=="==") return true; if (s=="!=") return true; if (s=="<=") return true; if (s==">=") return true; if (s=="<") return true; if (s==">") return true;
    if (s=="AND") return true; if (s=="OR") return true;
    if(s=="STO") return true;
    return false;
}

bool estUnOperateurUnaire(const QString& s) {
    if (s=="NEG") return true;
    if (s=="NUM") return true;
    if (s=="DEN") return true;
    if (s=="RE") return true;
    if (s=="IM") return true;
    if (s=="NOT") return true;
    if (s=="EVAL") return true;
    if (s=="FORGET") return true;
    return false;
}

bool estUnOperateurDePile(const QString& s) {
    if (s=="DUP") return true; if (s=="DROP") return true; if (s=="SWAP") return true;
    if (s=="LASTOP") return true; if (s=="LASTARGS") return true;
    if (s=="UNDO") return true; if (s=="REDO") return true; if (s=="CLEAR") return true;
    return false;
}

int prioriteOp(const QString& s) {
    if(s == "$") return -1;
    if(s == "*" || s == "/" || s == "N") return 2;
    if(s == "+" || s == "-" || s == "<" || s == ">" || s == "<=" || s == ">=") return 1;
    if(s == "(" || s == ")") return 0;
    throw LiException("mauvais operateur pour priorite");
}

bool estEntier (const QString& s) {
    QRegExp isdouble("^[0-9]+\\.?");
    return isdouble.exactMatch(s);
}

bool estDouble (const QString& s) {
    QRegExp isdouble("^[0-9]*\\.[0-9]+$");
    return isdouble.exactMatch(s);
}

bool estExpression(const QString& s) {
    QRegExp isexp("'.+'");
    return isexp.exactMatch(s);
}

bool estAtome(const QString& s) {
    QRegExp isatom("^[A-Z][A-Z0-9]*$");
    return isatom.exactMatch(s);
}

bool estAtomeGuillemets(const QString& s) {
    QRegExp isatomG("^'[A-Z][A-Z0-9]*'$");
    return isatomG.exactMatch(s);
}

bool is2operator(const QString& s) {
    if(s == "+" || s == "-" || s == "*" || s == "/" || s == "$" || s == "<" || s == ">" || s == "=" || s == "DIV" || s == "MOD" || s == "<=" || s == ">=" || s == "!=" || s == "AND" || s == "OR" || s == "STO") {
        return true;
    }
    return false;
}

bool is1operator(const QString& s) {
    if(s == "NOT" || s == "NEG" || s == "IM" || s == "RE" || s == "DEN" || s == "NUM" || s == "FORGET") {
        return true;
    }
    return false;
}

bool isoperatorPVP(const QString& s) {
    QRegExp qr1("^DIV\\(.+,.+\\)"); QRegExp qr2("^MOD\\(.+,.+\\)"); QRegExp qr3("^AND\\(.+,.+\\)"); QRegExp qr4("^OR\\(.+,.+\\)");
    if(qr1.exactMatch(s) || qr2.exactMatch(s) || qr3.exactMatch(s) || qr4.exactMatch(s)) {
        return true;
    }
    return false;
}

bool isoperatorPP(const QString& s) {
    QRegExp qr("^NOT\\(.+\\)|NEG\\(.+\\)|IM\\(.+\\)|RE\\(.+\\)|DEN\\(.+\\)|NUM\\(.+\\)");
    return qr.exactMatch(s);
}

bool PrioritePrecedentSup(const QChar qc, const QChar ptop) {
    if(prioriteOp(qc) < prioriteOp(ptop)) {
        return true;
    }
    return false;
}









//////////////////////////////////////// CALCULATRICE ////////////////////////////////////////



/*!
 *  \brief operateur2() method
 *
 *  Method declared in the Calculatrice class
 *  Used to manage all the operation with a binary operator
 *  the binary operator are : +, -, *, /, DIV, MOD, $, AND, OR, , ==, !=, =<, >=, <, >
 *  It takes two Litterales from the stack (pop and drop)
 *  Then the calls the appropriate operator which was overloaded in the other classes
 *  Throws an error when called on a wrong operator
 *
 *  \param const QString& s
 *  \return void
 */

void Calculatrice::operateur2(const QString& s) {
    Litterale* l1; Litterale* l2;
    LiEntiere* lie; LiNumerique* lin1; LiNumerique* lin2;
    if(estUnOperateurBinaire(s)) {
        if(s == "+") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(*l1 + *l2);
            delete l1; delete l2;
        }
        if(s == "-") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(*l2 - *l1);
            delete l1; delete l2;
        }
        if(s == "*") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(*l1 * *l2);
            delete l1; delete l2;
        }
        if(s == "/") {
            l1 = pile->top();
            if(typeid(*l1) == typeid(LiEntiere)) { if(l1->getValue() == 0) {throw LiException("erreur : division par 0"); return; } }
            pile->drop(); l2 = pile->top(); pile->drop();
            if(typeid(*l1) == typeid(LiEntiere) && typeid(*l2) == typeid(LiEntiere)) {
                if(l2->getValue()%l1->getValue() == 0) pile->push(new LiEntiere(l2->getValue()/l1->getValue()));
                else pile->push(new LiRationnelle(l2->getValue(), l1->getValue()));
            }
            else pile->push(*l2 / *l1);
            delete l1; delete l2;
        }

        if(s == "DIV") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();

            if(typeid(*l2) == typeid(LiEntiere)) {
                LiEntiere* lie = dynamic_cast<LiEntiere*>(l2);
                pile->push(lie->Div(*l1));
                delete l1; delete l2;
                return;
            }

            if(typeid(*l2) == typeid(LiExpression)) {
                LiExpression* liexp = dynamic_cast<LiExpression*>(l2);
                pile->push(liexp->Div(*l1));
                delete l1; delete l2;
                return;
            }
        }

        if(s == "MOD") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();

            if(typeid(*l2) == typeid(LiEntiere)) {
                LiEntiere* lie = dynamic_cast<LiEntiere*>(l2);
                pile->push(lie->Mod(*l1));
                delete l1; delete l2;
                return;
            }

            if(typeid(*l2) == typeid(LiExpression)) {
                LiExpression* liexp = dynamic_cast<LiExpression*>(l2);
                pile->push(liexp->Mod(*l1));
                delete l1; delete l2;
                return;
            }
        }

        if(s == "$") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            if(typeid(*l1)==typeid(LiComplexe)) {
                LiComplexe* lc1 = dynamic_cast<LiComplexe*>(l1);
                if(typeid(*l2)==typeid(LiComplexe)) {
                    LiComplexe* lc2 = dynamic_cast<LiComplexe*>(l2);
                    Litterale* res1 = lc1->getReelle()+lc2->getReelle(); Litterale* res2 = lc1->getImage()+lc2->getImage();
                    LiNumerique* res3= dynamic_cast<LiNumerique*>(res1); LiNumerique* res4= dynamic_cast<LiNumerique*>(res2);
                    pile->push(new LiComplexe(res3,res4));
                    delete res1; delete res2; delete l1; delete l2;
                    return;
                }
                Litterale* res1 = lc1->getReelle()+(*l2);
                LiNumerique* res2= dynamic_cast<LiNumerique*>(res1);
                pile->push(new LiComplexe(res2, &(lc1->getImage())));
                delete res1; delete l1; delete l2;
                return;
            }
            if(typeid(*l2)==typeid(LiComplexe)) {
                LiComplexe* lc2 = dynamic_cast<LiComplexe*>(l2);
                Litterale* res1 = lc2->getReelle()+(*l1);
                LiNumerique* res2= dynamic_cast<LiNumerique*>(res1);
                pile->push(new LiComplexe(res2, &(lc2->getImage())));
                delete res1; delete l1; delete l2;
                return;
            }

            if(typeid(*l1) == typeid(LiExpression)) {
                if(typeid(*l2) == typeid(LiExpression)) {
                    LiExpression* liexp1 = dynamic_cast<LiExpression*>(l1);
                    LiExpression* liexp2 = dynamic_cast<LiExpression*>(l2);
                    pile->push(new LiExpression(liexp2->getExpression() % "$" % liexp1->getExpression()));
                    return;
                }
                LiExpression* liexp1 = dynamic_cast<LiExpression*>(l1);
                QString qs2 = QString::fromStdString(l2->toString());
                pile->push(new LiExpression(qs2 % "$" % liexp1->getExpression()));
                return;
            }
            if(typeid(*l2) == typeid(LiExpression)) {
                LiExpression* liexp2 = dynamic_cast<LiExpression*>(l2);
                QString qs1 = QString::fromStdString(l1->toString());
                pile->push(new LiExpression(liexp2->getExpression() % "$" % qs1));
                return;
            }

            lin1 = dynamic_cast<LiNumerique*>(l1); lin2 = dynamic_cast<LiNumerique*>(l2);
            pile->push(new LiComplexe(lin2, lin1));
            delete l1; delete l2;
        }

        if(s == "AND") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2->And(l1));
            delete l1; delete l2;
        }
        if(s == "OR") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2->Or(l1));
            delete l1; delete l2;
        }
        if(s == "==") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)==(*l1));
        }
        if(s == "!=") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)!=(*l1));
        }
        if(s == "<=") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)<=(*l1));
        }
        if(s == ">=") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)>=(*l1));
        }
        if(s == ">") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)>(*l1));
        }
        if(s == "<") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)<(*l1));
            //delete l1; delete l2;
        }
        if(s == "STO") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            if(typeid(*l1) == typeid(LiExpression) && (typeid(*l2) == typeid(LiEntiere) || typeid(*l2) == typeid(LiReelle) || typeid(*l2) == typeid(LiRationnelle) || typeid(*l2) == typeid(LiComplexe))) {
                LiExpression* liexp = dynamic_cast<LiExpression*>(l1);
                if(estAtome(liexp->getExpression())) {
                  addAtom(liexp->getExpression(), l2);
                  return;
                }
            }
            else {
                pile->push(l2); pile->push(l1);
                throw LiException("STO impossible");
                return;
            }
        }
    }
    else {
        throw LiException("Mauvais operateur binaire, recommencez svp !");
    }
    return;
}


 /*!
 *  \brief operateur1() method
 *
 *  Method declared in the Calculatrice class
 *  Used to manage all the operation with a unaire operator
 *  the binary operator are : NEG, NUM, DEN, RE, IM, NOT, FORGET
 *  It takes one Litterale from the stack (pop and drop)
 *  Then the calls the appropriate operator which was overloaded in the other classes
 *  Throws an error when called on a wrong operator
 *
 *  \param const QString& s
 *  \return void
 */

void Calculatrice::operateur1(const QString& s) {
    Litterale* l1;
    if(estUnOperateurUnaire(s)) {
        if(s == "NEG") {
            l1 = pile->top(); pile->drop();
            pile->push(l1->Neg());
        }
        if(s == "NUM") {
            l1 = pile->top();
            if(typeid(*l1) == typeid(LiComplexe) || typeid(*l1) == typeid(LiReelle)) { throw LiException("NUM impossible sur ce type de litterale"); return; }
            pile->drop();
            pile->push(l1->Num());
            //delete l1;
        }
        if(s == "DEN") {
            l1 = pile->top();
            if(typeid(*l1) == typeid(LiComplexe) || typeid(*l1) == typeid(LiReelle)) { throw LiException("DEN impossible sur ce type de litterale"); return; }
            pile->drop();
            pile->push(l1->Den());
            //delete l1;
        }
        if(s == "RE") {
            l1 = pile->top(); pile->drop();
            pile->push(l1->Re());
            //delete l1;
        }
        if(s == "IM") {
            l1 = pile->top(); pile->drop();
            pile->push(l1->Im());
            //delete l1;
        }
        if(s == "NOT") {
            l1 = pile->top();
            pile->push(l1->Not());
        }

        if(s == "EVAL") {
            //cout << "dans evaaal" << endl;
            l1 = pile->top();
            if(typeid(*l1) != typeid(LiExpression)) {
                throw LiException("EVAL only on LiExpression");
                return;
            }
            pile->drop();
            LiExpression* liexp = dynamic_cast<LiExpression*>(l1);
            //cout << " dans eval avant infixePostfixe" << endl;
            QString post = infixePostfixe(liexp->getExpression());
            //cout << " dans eval apres infixePostfixe" << endl;
            string st = post.toStdString();
            string st2;
            int i = 0;
            stringstream ss;
            while(i < st.length()) {
                if(st[i] == ' ') {
                    st2 = ss.str();
                    //cout << "commande:" << st2 << "/commande" << endl;
                    commande(QString::fromStdString(st2));
                    //cout << "apres commande" << endl;
                    ss.str("");
                }
                else {
                    ss << st[i];
                }
                i++;
            }
            delete l1;
        }

        if( s == "FORGET") {
            l1 = pile->top();
            if(typeid(*l1) == typeid(LiExpression)) {
                LiExpression* liexp = dynamic_cast<LiExpression*>(l1);
                if(alreadyExists(liexp->getExpression())) {
                    removeAtom(liexp->getExpression());
                    pile->drop();
                    return;
                }
                else {
                    throw LiException("FORGET not possible : Atome doesn't exist_n");
                    return;
                }
            }
            else {
                throw LiException("FORGET : only on Atomes");
            }
        }
    }
    else {
        throw LiException("Mauvais operateur unaire, recommencez svp !");
    }
    return;
}



/*!
*  \brief operateurp() method
*
*  Method declared in the Calculatrice class
*  Used to manage all the operation with a stack
*  the binary operator are : NDUP, DROP, SWAP, LASTOP, LASTARGS, CLEAR
*  For DUP, DROP, SWAP, the function checks first if there is enough elements in the stack
*  For LASTOP it checks first if there is an operation to call (if yes, put it in the commande function)
*  For LASTARGS, it push the last arguments only if they exist
*  Throws an error when called on a wrong operator, or if there is any problem (not enough element in the stack, ...)
*
*  \param const QString& s
*  \return void
*/

void Calculatrice::operateurp(const QString& s) {
    if(estUnOperateurDePile(s)) {
        if(s == "DUP") { if (pile->taille() < 1) { throw LiException("Pas assez de litterales dans la pile."); return; } pile->dup(); }
        if(s == "SWAP") {if (pile->taille() < 2) { throw LiException("Pas assez de litterales dans la pile."); return; } pile->swap(); }
        if(s == "DROP") {if (pile->taille() < 1) { throw LiException("Pas assez de litterales dans la pile."); return; } pile->drop(); }
        if(s == "LASTOP") {
            if(getLastOp()=="") {
                throw LiException("Aucune operation a appliquer.");
                return;
            }
            commande(getLastOp());
            pile->modificationEtat();
        }
        if(s == "LASTARGS") {
            if(getLastArg1()==nullptr) {
                throw LiException("Aucun argument a empiler.");
                return;
            }
            else {
                if(getLastArg2()!=nullptr) { pile->push(getLastArg2()); lastarg2 = nullptr; }
                pile->push(getLastArg1()); lastarg1 = nullptr;
            }
        }
        //if(s == "UNDO") pile->undo();
        //if(s == "REDO") pile->redo();
        if(s == "CLEAR") { if(pile->taille()>0) pile->clear(); }
    }
    else {
        throw LiException("Mauvais operateur de pile, recommencez svp !");
    }
}



/*!
 *  \brief enregistrerLast() method
 *
 *  Method declared in the Calculatrice class
 *  Used to save the last operator used after each operation
 *  Used to save the last arguments after each operation (makes a copy and delete the old ones if they have not been pushed again)
 *
 *  \param const QString& s
 *  \return void
 */

void Calculatrice::enregistrerLast(const QString& s) {
    Litterale* l1; Litterale* l2;

    if(estUnOperateurBinaire(s)) {
        lastoperateur = s;
        l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();

        if(lastarg1!=nullptr) delete lastarg1;
        if(lastarg2!=nullptr) delete lastarg2;
        if(typeid(*l1) == typeid(LiEntiere)) lastarg1 = new LiEntiere(l1->getValue());
        if(typeid(*l1) == typeid(LiReelle)) lastarg1 = new LiReelle(l1->getReel());
        if(typeid(*l1) == typeid(LiRationnelle)) lastarg1 = new LiRationnelle(l1->getNumerateur(),l1->getDenominateur());
        if(typeid(*l1) == typeid(LiComplexe)) {
            LiComplexe* lc = dynamic_cast<LiComplexe*>(l1);
            lastarg1 = new LiComplexe(&lc->getReelle(), &lc->getImage());
        }
        if(typeid(*l1) == typeid(LiExpression)){
            LiExpression* liexp = dynamic_cast<LiExpression*>(l1);
            lastarg1 =  new LiExpression(liexp->getExpression());
        }
        if(typeid(*l2) == typeid(LiEntiere)) lastarg2 = new LiEntiere(l2->getValue());
        if(typeid(*l2) == typeid(LiReelle)) lastarg2 = new LiReelle(l2->getReel());
        if(typeid(*l2) == typeid(LiRationnelle)) lastarg2 = new LiRationnelle(l2->getNumerateur(),l2->getDenominateur());
        if(typeid(*l2) == typeid(LiComplexe)) {
            LiComplexe* lc = dynamic_cast<LiComplexe*>(l2);
            lastarg2 = new LiComplexe(&lc->getReelle(), &lc->getImage());
        }
        if(typeid(*l2) == typeid(LiExpression)){
            LiExpression* liexp = dynamic_cast<LiExpression*>(l2);
            lastarg1 =  new LiExpression(liexp->getExpression());
        }

        pile->push(l2); pile->push(l1);
    }

    if(estUnOperateurUnaire(s)) {
        lastoperateur = s;
        l1 = pile->top(); pile->drop();
        if(lastarg1!=nullptr) delete lastarg1;
        lastarg2=nullptr;
        if(typeid(*l1) == typeid(LiEntiere)) lastarg1 = new LiEntiere(l1->getValue());
        if(typeid(*l1) == typeid(LiReelle)) lastarg1 = new LiReelle(l1->getReel());
        if(typeid(*l1) == typeid(LiRationnelle)) lastarg1 = new LiRationnelle(l1->getNumerateur(),l1->getDenominateur());
        if(typeid(*l1) == typeid(LiComplexe)) {
            LiComplexe* lc = dynamic_cast<LiComplexe*>(l1);
            lastarg1 = new LiComplexe(&lc->getReelle(), &lc->getImage());
        }
        if(typeid(*l1) == typeid(LiExpression)){
            LiExpression* liexp = dynamic_cast<LiExpression*>(l1);
            lastarg1 =  new LiExpression(liexp->getExpression());
        }
        pile->push(l1);
    }
}


/*!
 *  \brief commande() method
 *
 *  Method whichwas declare in the Calculatrice class
 *  Takes one argument of type const QString& representing what the user entered in the calculator
 *  if it is an integer, it pushes a new LiEntiere
 *  if it is a double type number, it pushes a new LiReelle
 *  if it is an expression, it pushes a new LiExpression
 *  if it is an Atome : if it did not exist before, it creates an Expression, and if it already existed, it pushes the Litterale corresponding to this atome
 *  if it is an operator, it calls the appropriate function (operator1, operator2, operatorp)
 *  try ... catch block to catch all the excpetions thrown by the different function called
 *
 *  \param const QString& s
 *  \return void
 */

void Calculatrice::commande(const QString& c){
    try {
        if(c == "AFFICHEALL") {
            afficherTousAtomes();
            return;
        }

        if(estEntier(c)) {
            pile->push(new LiEntiere(c.toDouble()));
            return;
        }
        else {
            if(estDouble(c)) {
                    if(floor(c.toDouble()) == c.toDouble()) pile->push(new LiEntiere(c.toDouble()));
                    else {
                        pile->push(new LiReelle(c.toDouble()));
                        return;
                    }
            }
            else {
                if(estUnOperateurBinaire(c)) {
                    if (pile->taille() < 2) {
                        throw LiException("Pas assez de litterales dans la pile.");
                        return;
                    }
                    enregistrerLast(c);
                    operateur2(c);
                    return;
                }
                else {
                    if(estUnOperateurUnaire(c)) {
                       if (pile->taille() < 1) {
                           throw LiException("Pas assez de litterales dans la pile.");
                           return;
                       }
                       enregistrerLast(c);
                       operateur1(c);
                       return;
                    }
                    else {
                        if(estUnOperateurDePile(c)) {
                           enregistrerLast(c);
                           operateurp(c);
                           return;
                        }
                        else {
                            if(estExpression(c) && !estAtomeGuillemets(c)) {
                                pile->push(LiExpression::enleverGuillemets(c));
                                return;
                            }
                            else {
                                if(estAtomeGuillemets(c)) {
                                    pile->push(new LiExpression(LiExpression::enleverGuillemets(c)->getExpression()));
                                    return;
                                }
                                else {
                                    if(estAtome(c)) {
                                        if(alreadyExists(c)) {
                                            Litterale* newli = mapAtome[c];
                                            if (typeid(*newli) == typeid(LiEntiere)) pile->push(new LiEntiere(newli->getValue()));
                                            if (typeid(*newli) == typeid(LiReelle)) pile->push(new LiReelle(newli->getReel()));
                                            if (typeid(*newli) == typeid(LiRationnelle)) pile->push(new LiRationnelle(newli->getNumerateur(), newli->getDenominateur()));
                                            if (typeid(*newli) == typeid(LiComplexe)) {
                                                LiNumerique* preelle = dynamic_cast<LiNumerique*>(newli->Re());
                                                LiNumerique* pimaginaire = dynamic_cast<LiNumerique*>(newli->Im());
                                                pile->push(new LiComplexe(preelle, pimaginaire));
                                            }
                                            if(typeid(*newli) == typeid(LiExpression)) {
                                                LiExpression* lie = dynamic_cast<LiExpression*>(newli);
                                                pile->push(new LiExpression(lie->getExpression()));
                                            }
                                            return;
                                        }

                                        else {
                                            pile->push(new LiExpression(c));
                                            return;
                                        }
                                    }
                                }
                                if(c != " ") pile->setMessage("operateur inconnu, recommencez svp !");
                            }
                        }
                    }
                }
            }
        }
    }
    catch(LiException e) {
            pile->setMessage(e.getInfo());
        }
}



/*!
 *  \brief executer() method
 *
 *  Method declared in the Calculatrice class
 *  takes what the user entered and sends it to the commande function
 *
 *  \param no parameter
 *  \return void
 */

void Calculatrice::executer() {
    try {
    string c;
    do {
        pile->affiche();
        if(pile->getMessage() != "") {
            pile->setMessage("");
        }
        cout << "?-";
        cin >> c;
        QString qs(QString::fromStdString(c));
        if (c!="Q") { commande(QString::fromStdString(c)); }
    }
    while(c!="Q");
    if(c=="Q") cout << "Au revoir, merci d'avoir utilise UTComputer !" << endl << endl << endl;
    } catch (LiException e) {
        pile->setMessage(e.getInfo());
    }
}



/*!
 *  \brief infixePostfixe() method
 *
 *  Method declared in the Calculatrice class
 *  Used to transform an expression (not wrote in RPN) in a new expression in RPN that can be interpreted by the commande function
 *  It is, in some cases, a recursive function
 *  If it finds in the expression a operator with parentheses like DIV(e1,e2), it calls the function again on e1 and e2
 *  it has one QStack, an to manage the other operator found
 *  when the function finds an operator, it pushes it on the top of the stack only if its priority is higher than the priority of the operator already on the top of the stack
 *  if its priority is lower, it adds it to "post" which is the QString that the function will return
 *  if the function finds a number, it also adds it to post
 *
 *  \param const QString&
 *  \return QString
 */

QString Calculatrice::infixePostfixe(const QString& s) {
    int i = 0;
    QString exp = s % ' ';
    QString post;
    QChar qc;
    QStack<QChar> pile;
    int b;
    while(i < exp.size()-1 ) {

        qc = exp[i];
        b = 0;

        if(isoperatorPVP(s.right(s.size() - i))) {
            b++;
            QString tmp = s.right(s.size() - i);
            QString operateur = "";

            while(tmp[0] != '(') {
                operateur += tmp[0];
                tmp.remove(0,1);
            }

            tmp.remove(0,1);
            int j = 0;
            int nbPar = 0;
            int ok = 0;
            while(j < (tmp.size() - 1) && !ok) {
                if( tmp[j] == '(') {
                    nbPar++;
                }
                else {
                    if(tmp[j] == ')' && nbPar == 0) {
                        ok = 1;
                    }
                }

                j++;
            }
            tmp = tmp.left(j);
            QString gauche = "";
            QString droite = "";
            int k = 0;
            while(tmp[k] != ',') {
                gauche += tmp[k];
                k++;
            }
            k++;
            while(k<tmp.size()) {
                droite += tmp[k];
                k++;
            }

            i += operateur.size() + 2 + tmp.size();
            if(i < tmp.size() - 1) {
                qc = exp[i];
            }

            post = post % infixePostfixe(gauche) % infixePostfixe(droite) % operateur % " ";
        }


        if(isoperatorPP( s.right(s.size() - i)) ) {
            b++;
            QString tmp = s.right(s.size() - i);
            QString operateur = "";

            while(tmp[0] != '(') {
                operateur += tmp[0];
                tmp.remove(0,1);
            }

            tmp.remove(0,1);
            int j = 0;
            int nbPar = 0;
            int ok = 0;

            while(j < (tmp.size() - 1) && !ok) {
                if( tmp[j] == '(') {
                    nbPar++;
                }
                else {
                    if(tmp[j] == ')' && nbPar == 0) {
                        ok = 1;
                    }
                }

                j++;
            }
            tmp = tmp.left(j);
            i += operateur.size() + 2 + tmp.size();
            if(i<tmp.size() - 1) {
                qc = exp[i];
            }
            post = post % infixePostfixe(tmp) % operateur %" ";
        }

        if(qc == '-') {
            b++;
            if(i < exp.size() -1) {
                if(exp[i+1].isDigit()) {
                    if(i==0 || exp[i-1] == '('){
                        pile.push('N');
                        if(i<exp.size() - 1) {
                            i++;
                            qc = exp[i];
                        }
                    }
                }
            }
        }

        if(is2operator(qc)) {
            b++;
            if(!(pile.isEmpty())) {
                while(!(pile.isEmpty()) && PrioritePrecedentSup(qc, pile.top())) {
                    if(pile.top() == 'N') post += "NEG";
                    else post += pile.top();
                    pile.pop();
                    post += " ";
                }
            }
            pile.push(qc);
            if(i<exp.size() - 1) {
                i++;
                qc = exp[i];
            }
        }


        if(qc.isDigit() || qc == '.') {
            b++;
            int nbdot = 0;
            QString nb;
            while((qc.isNumber() || qc == '.') && (i < exp.size() - 1) && nbdot < 2) {
                if(qc == '.') nbdot++;
                nb += qc;
                i++;
                qc = exp[i];
            }
            post += nb;
            post += " ";
        }


        if(qc == ' ') {
            b++;
            if(i<exp.size() - 1) {
                i++;
                qc = exp[i];
            }
        }

        if(qc == '(') {
            b++;
            pile.push(qc);
            if(i<exp.size() - 1) {
                i++;
                qc = exp[i];
            }
        }

        if(qc == ')') {
            b++;
            while(!(pile.isEmpty()) && (pile.top() != '(')) {
                if(pile.top() == 'N') post += "NEG";
                else post += pile.top();
                post += " ";
                pile.pop();
            }
            pile.pop();
            if(i<exp.size() - 1) {
                i++;
                qc = exp[i];
            }
        }
        if(b == 0) {
            throw LiException("error : caractere inconnu dans cette expression");
        }
    }


    while(!(pile.isEmpty())) {
        if(pile.top() == 'N') post += "NEG";
        else post += pile.top();
        post += " ";
        pile.pop();
    }

    return post;
}



/*!
 *  \brief addAtome() method
 *
 *  Use to add a new Atome
 *  Very easy thanks to the map
 *  If it already exists it will change its value
 *  if not, it creates it
 *
 *  \param 2 parameters of type const QString& and Litteral*
 *  \return void
 */
void Calculatrice::addAtom(const QString& s, Litterale* li) {
        mapAtome[s] = li;
        nbAtoms++;
        newAtom(s);
}

/*!
 *  \brief removeAtome() method
 *
 *  Use to delete an atome
 *  use the erase method of map class
 *
 *  \param 2 parameters of type const QString& and Litteral*
 *  \return void
 */
void Calculatrice::removeAtom(const QString& s) {
    if( alreadyExists(s) ) {
        nbAtoms--;
        mapAtome.erase(s);
        deleteAtom(s);
    }
    else throw LiException("Atome can't be deleted : doesn't exist");
}

/*!
 *  \brief alreadyExists() method
 *
 *  Used to know if an atome already exists
 *
 *  \param const Qstring&
 *  \return bool (true if already exists, false otherwise)
 */
bool Calculatrice::alreadyExists(const QString& s) {
    if( mapAtome.find(s) != mapAtome.end() ) {
        return true;
    }
    return false;
}


/*!
 *  \brief afficherTousAtomes() method
 *
 *  Method to display all the atomes that the calculator contains
 *
 *  \param const Qstring&
 *  \return void
 */
void Calculatrice::afficherTousAtomes() const {
    for(map<QString,Litterale*>::const_iterator it = mapAtome.begin(); it != mapAtome.end(); ++it) {
        QString qs = it->first;
        cout << qs.toStdString() << "  " << it->second->toString() << endl;
    }
}
