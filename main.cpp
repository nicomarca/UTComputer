#include "litterale.h"



int main()
{
    /*
    try {
    QString qs("1.3+2");
    Pile* p1 = new Pile;
    p1->setMessage("Bienvenue");
    Calculatrice c1(p1);
    c1.Eval(qs);
    } catch(LiException e) {
        cout << e.getInfo() << endl;
    }
    */


    try {
    Pile* p1 = new Pile;
    p1->setMessage("Bienvenue");
    Calculatrice c1(p1);
    c1.executer();
    } catch(LiException e) {
        cout << e.getInfo() << endl;
    }


    return 1;
}
