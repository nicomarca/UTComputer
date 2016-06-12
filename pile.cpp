/**
 * \file pile.cpp
 * \brief file where the methods of Pile and Memento are defined
 *
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include "pile.h"



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
