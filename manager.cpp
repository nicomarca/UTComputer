#include "litterale.h"
#include "mainwindow.h"
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
    system("cls");
    cout<<"*************************"<< endl;
    cout<< message.toStdString() << endl;
    //ui->expression_2->setText(ui->expression_2->text()+ message);
    cout<<"-------------------------" << endl;
    for (unsigned int i = nbAffiche; i>0; i--) {
        if (i <= nb) { cout << i << " : "; li[nb-i]->afficher(); }
        else cout << i << " : " << endl;
    }
    cout<<"-------------------------"<< endl;
}


void Pile::push(Litterale* l){
    if (this->nb==this->nbMax) agrandissementCapacite();
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



//Litterale* Pile::lastop() {
//}

/*
void Calculatrice::lastargs() {

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





/*
//////////////////////////////////////// ATOME ////////////////////////////////////////


Atome::Atome(string a):atom(a) {
    if (!(atom[0] >= 'A' && atom[0] <= 'Z')) throw LiException("Error : syntaxe de l'atome non valide");
    for (unsigned int i = 1; i<atom.length(); i++)
        if (!(('0' <= atom[i] && atom[i] <= '9') || ('A' <= atom[i] && atom[i] <= 'Z'))) throw LiException("Error : syntaxe de l'atome non valide");
}

<<<<<<< 5f7bc0fe36a6d11459c15a3f8d1cfe81268e21ab
=======
//<<<<<<< HEAD
//////////////////////////////////////// EXPRESSION MANAGER ////////////////////////////////////////

void ExpressionManager::agrandissementCapacite() {

        Operande** newtab = new Operande*[(nbMax+1)*2];
        for(unsigned int i=0; i<nb; i++) newtab[i]=tabOp[i];
        Operande** old = tabOp;
        tabOp=newtab;
        nbMax=(nbMax+1)*2;
        delete[] old;
}

void ExpressionManager::addOperande(Operande* o){
    if (nb==nbMax) agrandissementCapacite();
    tabOp[nb] = o;
        nb++;
}
>>>>>>> Qt


<<<<<<< 5f7bc0fe36a6d11459c15a3f8d1cfe81268e21ab
=======

//=======

/*
>>>>>>> Qt
Litterale* Atome::operator== (Litterale& li) {
    if(atom == li.atom) return new
}


Litterale* Atome::operator!= (Litterale& li);


Litterale* Atome::operator= (Litterale& li);


Litterale* Atome::operator<= (const Litterale& li) const {
    if(typeid(li) == typeid(Atome))
        if(getAtom() <= li.getAtom())
            return new LiEntiere(1);
    return new LiEntiere(0);
}


Litterale* Atome::operator>= (const Litterale& li) const {
    if(typeid(li) == typeid(Atome))
        if(getAtom() >= li.getAtom())
            return new LiEntiere(1);
    return new LiEntiere(0);
}


Litterale* Atome::operator< (const Litterale& li) const {
    if(typeid(li) == typeid(Atome))
        if(getAtom() < li.getAtom())
            return new LiEntiere(1);
    return new LiEntiere(0);
}


Litterale* Atome::operator> (const Litterale& li) const {
    if(typeid(li) == typeid(Atome))
        if(getAtom() > li.getAtom())
            return new LiEntiere(1);
    return new LiEntiere(0);
}
<<<<<<< 5f7bc0fe36a6d11459c15a3f8d1cfe81268e21ab
*/





//////////////////////////////////////// EXPRESSION ////////////////////////////////////////


/*
Litterale* LiExpression::operator+ (const Litterale& li) const {
    const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
    return new LiExpression(getExpression()%"+"%lie.getExpression());
}


Litterale* LiExpression::operator- (const Litterale& li) const {
    const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
    return new LiExpression(getExpression() % "-" % lie.getExpression());
}

Litterale* LiExpression::operator/ (const Litterale& li) const {
    const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
    return new LiExpression("("%getExpression()%")/("%lie.getExpression()%")");
}


Litterale* LiExpression::operator* (const Litterale& li) const {
    const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
    return new LiExpression("("%getExpression()%")*("%lie.getExpression()%")");
}


Litterale* LiExpression::And(const Litterale* li) {
    if(isZero() || li->isZero())
        return new LiEntiere(0);
    return new LiEntiere(1);
}


Litterale* LiExpression::Or(const Litterale* li) {
    if(isZero() && li->isZero())
        return new LiEntiere(0);
    return new LiEntiere(1);
}


Litterale* LiExpression::Not() {
    if(isZero())
        return new LiEntiere(1);
    return new LiEntiere(0);
}
*/



//////////////////////////////////////// CALCULATRICE ////////////////////////////////////////

/*
///SINGLETON
Calculatrice* Calculatrice::cal=0;


Calculatrice* Calculatrice::getInstance() {
      if (cal == 0) cal =  new Calculatrice(new Pile);
      else throw CalculatriceException("Singleton already created !");
      return cal;
}

void Calculatrice::libereInstance() {
    if (cal != 0) { delete cal; cal = 0; }
}
////////////
*/

// +, -, *, / (si div par 0, pas de modif de la pile mais message d’erreur)
//DIV (qur sur LiEntiere), MOD, $, AND, OR, , ==, !=, =<, >=, <, >
//=


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

            if(typeid(*l1) != typeid(LiEntiere) || typeid(*l2) != typeid(LiEntiere)) {
                pile->push(l2); pile->push(l1);
                throw LiException("erreur : DIV uniquement entre entiers");
                return;
            }
            else {
                lie = dynamic_cast<LiEntiere*>(l2);
                pile->push(lie->Div(*l1));
            }
            delete l1; delete l2;
        }
        if(s == "MOD") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            if(typeid(*l1) != typeid(LiEntiere) || typeid(*l2) != typeid(LiEntiere)) {
                pile->push(l2); pile->push(l1);
                throw LiException("erreur : MOD uniquement entre entiers");
                return;
            }
            else {
                lie = dynamic_cast<LiEntiere*>(l2);
                pile->push(lie->Mod(*l1));
            }
            delete l1; delete l2;
        }
        if(s == "$") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            if(typeid(*l1)==typeid(LiComplexe)) {
                LiComplexe* lc1 = dynamic_cast<LiComplexe*>(l1);
                if(typeid(*l2)==typeid(LiComplexe)) {
                    LiComplexe* lc2 = dynamic_cast<LiComplexe*>(l2);
                    Litterale* res1 = lc1->getReelle()+lc2->getReelle(); Litterale* res2 = lc1->getImage()+lc2->getImage();
                    LiNumerique* res3= dynamic_cast<LiNumerique*>(res1); LiNumerique* res4= dynamic_cast<LiNumerique*>(res1);
                    pile->push(new LiComplexe(res3,res4));
                    delete res1; delete res2;
                    return;
                }
                Litterale* res1 = lc1->getReelle()+(*l2);
                LiNumerique* res2= dynamic_cast<LiNumerique*>(res1);
                pile->push(new LiComplexe(res2, &(lc1->getImage())));
                delete res1;
                return;
            }
            if(typeid(*l2)==typeid(LiComplexe)) {
                LiComplexe* lc2 = dynamic_cast<LiComplexe*>(l2);
                Litterale* res1 = lc2->getReelle()+(*l1);
                LiNumerique* res2= dynamic_cast<LiNumerique*>(res1);
                pile->push(new LiComplexe(res2, &(lc2->getImage())));
                delete res1;
                return;
            }
            lin1 = dynamic_cast<LiNumerique*>(l1); lin2 = dynamic_cast<LiNumerique*>(l2);
            pile->push(new LiComplexe(lin2, lin1));
            delete l1; delete l2;
        }
        if(s == "AND") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push(l2->And(l1));
            //delete l1; delete l2;
        }
        if(s == "OR") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push(l2->Or(l1));
            //delete l1; delete l2;
        }
        if(s == "==") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)==(*l1));
            //delete l1; delete l2;
        }
        if(s == "!=") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)!=(*l1));
            //delete l1; delete l2;
        }
        if(s == "<=") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)<=(*l1));
            //delete l1; delete l2;
        }
        if(s == ">=") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)>=(*l1));
            //delete l1; delete l2;
        }
        if(s == ">") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)>(*l1));
            //delete l1; delete l2;
        }
        if(s == "<") {
            l1 = pile->top(); pile->drop(); l2 = pile->top(); pile->drop();
            pile->push(l2); pile->push(l1); pile->push((*l2)<(*l1));
            //delete l1; delete l2;
        }
    }
    else {
        throw LiException("Mauvais operateur binaire, recommencez svp !");
    }
    return;
}


//NEG, NUM, DEN, RE, IM, NOT


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
    }
    else {
        throw LiException("Mauvais operateur unaire, recommencez svp !");
    }
    return;
}


void Calculatrice::operateurp(const QString& s) {
    if(estUnOperateurDePile(s)) {
        if(s == "DUP") { if (pile->taille() < 1) { pile->setMessage("Pas assez de litterales dans la pile."); return; } pile->dup(); }
        if(s == "SWAP") {if (pile->taille() < 2) { pile->setMessage("Pas assez de litterales dans la pile."); return; } pile->swap(); }
        if(s == "DROP") {if (pile->taille() < 1) { pile->setMessage("Pas assez de litterales dans la pile."); return; } pile->drop(); }
        if(s == "LASTOP") {
            if(getLastOp()=="") {
                pile->setMessage("Aucune operation a appliquer.");
                return;
            }
            commande(getLastOp());
            pile->modificationEtat();
        }
        if(s == "LASTARGS") {
            if(getLastArg1()==0) {
                pile->setMessage("Aucun argument a empiler.");
                return;
            }
            else {
                if(getLastArg2()!=0) { pile->push(getLastArg2()); lastarg2 = 0; }
                pile->push(getLastArg1()); lastarg1 = 0;
            }
        }
        //if(s == "UNDO") pile->undo();
        //if(s == "REDO") pile->redo();
        if(s == "CLEAR") { if(pile->taille()>0) pile->clear();  }
    }
    else {
        throw LiException("Mauvais operateur de pile, recommencez svp !");
    }
}



bool estUnOperateurBinaire (const QString& s) {
    if (s=="+") return true; if (s=="-") return true; if (s=="*") return true; if (s=="/") return true;
    if (s=="DIV") return true; if (s=="MOD") return true;
    if (s=="$") return true;
    if (s=="=") return true; if (s=="==") return true; if (s=="!=") return true; if (s=="<=") return true; if (s==">=") return true; if (s=="<") return true; if (s==">") return true;
    if (s=="AND") return true; if (s=="OR") return true;
    return false;
}


bool estUnOperateurUnaire(const QString& s) {
    if (s=="NEG") return true;
    if (s=="NUM") return true;
    if (s=="DEN") return true;
    if (s=="RE") return true;
    if (s=="IM") return true;
    if (s=="NOT") return true;
    return false;
}


bool estUnOperateurDePile(const QString& s) {
    if (s=="DUP") return true; if (s=="DROP") return true; if (s=="SWAP") return true;
    if (s=="LASTOP") return true; if (s=="LASTARGS") return true;
    if (s=="UNDO") return true; if (s=="REDO") return true; if (s=="CLEAR") return true;
    return false;
}


bool estEntier (const QString& s) {
    for(QString::const_iterator it=s.begin(); it!=s.end(); ++it)
        if (*it<'0' || *it>'9') return false;
    return true;
}


bool estDouble (const QString& s) {
    int nb = 0;
    QString::const_iterator it;
    for(it=s.begin(); it!=s.end(); ++it) {
        if (*it == '.') nb++;
        if (!( (*it>='0' && *it<='9') || *it=='.' )) return false;
        if (nb == 2) return false;
    }
    if (nb==1 && s[s.length()-1] == '.') return false;
    if (nb == 0) return false;
    return true;
}


bool estEntierPoint (const QString& s) {
    int nb = 0;
    QString::const_iterator it;
    for(it=s.begin(); it!=s.end(); ++it) {
        if (*it == '.') nb++;
        if (!( (*it>='0' && *it<='9') || *it=='.' )) return false;
        if (nb == 2) return false;
    }
    if (nb==1 && s[s.length()-1] == '.') return true;
    return false;
}


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
        if(typeid(*l2) == typeid(LiEntiere)) lastarg2 = new LiEntiere(l2->getValue());
        if(typeid(*l2) == typeid(LiReelle)) lastarg2 = new LiReelle(l2->getReel());
        if(typeid(*l2) == typeid(LiRationnelle)) lastarg2 = new LiRationnelle(l2->getNumerateur(),l2->getDenominateur());
        if(typeid(*l2) == typeid(LiComplexe)) {
            LiComplexe* lc = dynamic_cast<LiComplexe*>(l2);
            lastarg2 = new LiComplexe(&lc->getReelle(), &lc->getImage());
        }

        pile->push(l2); pile->push(l1);
    }
}



void Calculatrice::commande(const QString& c){
    try {
        if(estEntier(c)) {
            pile->push(new LiEntiere(c.toInt()));
            return;
        }
        else {
            if(estEntierPoint(c)) {
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
                    if (pile->taille()==0) {pile->setMessage("La pile est vide : aucune opération possible"); return;}
                    if(estUnOperateurBinaire(c)) {
                        if (pile->taille() < 2) {
                            pile->setMessage("Pas assez de litterales dans la pile.");
                            return;
                        }
                        enregistrerLast(c);
                        operateur2(c);
                        return;
                    }
                    else {
                        if(estUnOperateurUnaire(c)) {
                           if (pile->taille() < 1) {
                               pile->setMessage("Pas assez de litterales dans la pile.");
                               return;
                           }
                           enregistrerLast(c);
                           operateur1(c);
                           return;
                        }
                        else {
                            if(estUnOperateurDePile(c)) {
                               operateurp(c);
                               return;
                            }
                            else {
                                pile->setMessage("operateur inconnue, recommencez svp !");
                            }
                        }
                    }
                }
            }
        }

    /*
    if(getMessage() != "") {
        cout << getMessage().toStdString() << endl;
        pile->setMessage("");
    }
    */
    } catch(LiException e) {
        pile->setMessage(QString::fromStdString(e.getInfo()));
        //cout << e.getInfo() << endl;
    }
}


void Calculatrice::executer() {
    try {
    string c;
    do {
        pile->affiche();
        if(getMessage() != "") {
            cout << getMessage().toStdString() << endl;
            pile->setMessage("");
        }
        cout << "?-";
        cin >> c;
        if (c!="Q") { commande(QString::fromStdString(c)); }
        //else { pile->supprimerPile(); }
    }
    while(c!="Q");
    if(c=="Q") cout << "Au revoir, merci d'avoir utilise UTComputer !" << endl << endl << endl;
    } catch (LiException e) {
        pile->setMessage(QString::fromStdString(e.getInfo()));
        cout << e.getInfo() << endl;
    }
}
