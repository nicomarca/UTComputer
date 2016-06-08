/*    QString s1 = "abc";
    QString s2 = "def";
    Litterale* l1 = new LiExpression(s1);
    Litterale* l2 = new LiExpression(s2);
    Litterale* l3 = (*l1)/(*l2);
    LiExpression* l4= dynamic_cast<LiExpression*>(l3);
    cout << l4->getExpression().toStdString() << endl;
    try {
    Pile* p1 = new Pile;
    p1->setMessage("Bienvenue");
    Calculatrice c1(p1);
    c1.executer();
    } catch(LiException e) {
        cout << e.getInfo() << endl;
    }

*/



/////////////////////////////////  MAIN SURCHARGES OPERTATEURS  /////////////////////////////////////



/*

    LiEntiere e1(10);
    LiReelle re1(5.5);
    LiRationnelle ra1(10,3);

    LiNumerique* e2 = new LiEntiere (3);
    LiNumerique* re2 = new LiReelle(555.555);
    LiNumerique* ra2 = new LiRationnelle(5,4);
    LiNumerique* ra3 = new LiRationnelle(6,7);
    LiComplexe lc1 = LiComplexe(e2, re2);
    LiComplexe lc2 = LiComplexe(re2, e2);
    LiComplexe lc3 = LiComplexe(ra2, ra3);

    Litterale* pt1;
    Litterale* pt2;
    Litterale* pt3;
    Litterale* pt0;
    Litterale* pt4 = &e1;
    Litterale* pt5 = &re1;
    Litterale* pt6 = &ra1;
    Litterale* pt7 = &lc1;
    Litterale* pt8 = &lc2;
    Litterale* pt9 = &lc3;



    cout <<"========== LITTERALE ENTIERE ==========\n";
    cout <<"\n---------- ADDITION -----------\n";

    pt1 = e1+e1; pt1->afficher();
    pt1 = *pt4+e1; pt1->afficher();
    pt2 = e1+re1; pt2->afficher();
    pt2 = *pt4+re1; pt2->afficher();
    pt3 = e1+ra1; pt3->afficher();
    pt3 = *pt4+ra1; pt3->afficher();
    pt1 = e1+lc1; pt1->afficher();
    pt1 = e1+lc2; pt1->afficher();
    pt1 = e1+lc3; pt1->afficher();


    cout <<"\n---------- SOUSTRACTION -----------\n";

    pt1 = e1-e1; pt1->afficher();
    pt1 = *pt4-e1; pt1->afficher();
    pt2 = e1-re1; pt2->afficher();
    pt2 = *pt4-re1; pt2->afficher();
    pt3 = e1-ra1; pt3->afficher();
    pt3 = *pt4-ra1; pt3->afficher();
    pt1 = e1-(*pt7); pt1->afficher();
    pt1 = e1-(*pt8); pt1->afficher();
    pt1 = e1-(*pt9); pt1->afficher();

    cout <<"\n---------- MULTIPLICATION -----------\n";

    pt1 = e1*e1; pt1->afficher();
    pt1 = *pt4*e1; pt1->afficher();
    pt2 = e1*re1; pt2->afficher();
    pt2 = *pt4*re1; pt2->afficher();
    pt3 = e1*ra1; pt3->afficher();
    pt3 = *pt4*ra1; pt3->afficher();
    pt1 = e1*(*pt7); pt1->afficher();
    pt1 = e1*(*pt8); pt1->afficher();
    pt1 = e1*(*pt9); pt1->afficher();

    cout <<"\n---------- DIVISION -----------\n";

    pt1 = e1/e1; pt1->afficher();
    pt1 = *pt4/e1; pt1->afficher();
    pt2 = e1/re1; pt2->afficher();
    pt2 = *pt4/re1; pt2->afficher();
    pt3 = e1/ra1; pt3->afficher();
    pt3 = *pt4/ra1; pt3->afficher();

    cout <<"\n---------- EGALITE -----------\n";

    pt1 = e1==e1; pt1->afficher();
    pt1 = *pt4==e1; pt1->afficher();
    pt1 = e1==re1; pt1->afficher();
    pt1 = *pt4==re1; pt1->afficher();
    pt1 = e1==ra1; pt1->afficher();
    pt1 = *pt4==ra1; pt1->afficher();
    pt1 = e1==lc1; pt1->afficher();

    cout <<"\n---------- INEGALITE -----------\n";

    pt1 = e1!=e1;  pt1->afficher();
    pt1 = *pt4!=e1; pt1->afficher();
    pt1 = e1!=re1; pt1->afficher();
    pt1 = *pt4!=re1; pt1->afficher();
    pt1 = e1!=ra1; pt1->afficher();
    pt1 = *pt4!=ra1; pt1->afficher();
    pt1 = e1!=lc1; pt1->afficher();





    cout << endl << endl << endl ;

    cout <<"========== LITTERALE RATIONNELLE ==========\n";
    cout <<"\n---------- ADDITION -----------\n";

    pt1 = ra1+e1; pt1->afficher();
    pt1 = *pt6+e1; pt1->afficher();
    pt2 = ra1+re1; pt2->afficher();
    pt2 = *pt6+re1; pt2->afficher();
    pt3 = ra1+ra1; pt3->afficher();
    pt3 = *pt6+ra1; pt3->afficher();

    cout <<"\n---------- SOUSTRACTION -----------\n";

    pt1 = ra1-e1; pt1->afficher();
    pt1 = *pt6-e1; pt1->afficher();
    pt2 = ra1-re1; pt2->afficher();
    pt2 = *pt6-re1; pt2->afficher();
    pt3 = ra1-ra1; pt3->afficher();
    pt3 = *pt6-ra1; pt3->afficher();

    cout <<"\n---------- MULTIPLICATION -----------\n";

    pt1 = ra1*e1; pt1->afficher();
    pt1 = *pt6*e1; pt1->afficher();
    pt2 = ra1*re1; pt2->afficher();
    pt2 = *pt6*re1; pt2->afficher();
    pt3 = ra1*ra1; pt3->afficher();
    pt3 = *pt6*ra1; pt3->afficher();

    cout <<"\n---------- DIVISION -----------\n";

    pt1 = ra1/e1; pt1->afficher();
    pt1 = *pt6/e1; pt1->afficher();
    pt2 = ra1/re1; pt2->afficher();
    pt2 = *pt6/re1; pt2->afficher();
    pt3 = ra1/ra1; pt3->afficher();
    pt3 = *pt6/ra1; pt3->afficher();

    cout <<"\n---------- EGALITE -----------\n";

    pt1 = ra1==e1; pt1->afficher();
    pt1 = *pt6==e1; pt1->afficher();
    pt1 = ra1==re1; pt1->afficher();
    pt1 = *pt6==re1; pt1->afficher();
    pt1 = ra1==ra1; pt1->afficher();
    pt1 = *pt6==ra1; pt1->afficher();
    pt1 = ra1==lc1; pt1->afficher();

    cout <<"\n---------- INEGALITE -----------\n";

    pt1 = ra1!=e1;  pt1->afficher();
    pt1 = *pt6!=e1; pt1->afficher();
    pt1 = ra1!=re1; pt1->afficher();
    pt1 = *pt6!=re1; pt1->afficher();
    pt1 = ra1!=ra1; pt1->afficher();
    pt1 = *pt6!=ra1; pt1->afficher();
    pt1 = ra1!=lc1; pt1->afficher();





    cout << endl << endl << endl ;

    cout <<"========== LITTERALE REELLE ==========\n";
    cout <<"\n---------- ADDITION -----------\n";

    pt1 = re1+e1; pt1->afficher();
    pt1 = *pt5+e1; pt1->afficher();
    pt2 = re1+re1; pt2->afficher();
    pt2 = *pt5+re1; pt2->afficher();
    pt3 = re1+ra1; pt3->afficher();
    pt3 = *pt5+ra1; pt3->afficher();

    cout <<"\n---------- SOUSTRACTION -----------\n";

    pt1 = re1-e1; pt1->afficher();
    pt1 = *pt5-e1; pt1->afficher();
    pt2 = re1-re1; pt2->afficher();
    pt2 = *pt5-re1; pt2->afficher();
    pt3 = re1-ra1; pt3->afficher();
    pt3 = *pt5-ra1; pt3->afficher();

    cout <<"\n---------- MULTIPLICATION -----------\n";

    pt1 = re1*e1; pt1->afficher();
    pt1 = *pt5*e1; pt1->afficher();
    pt2 = re1*re1; pt2->afficher();
    pt2 = *pt5*re1; pt2->afficher();
    pt3 = re1*ra1; pt3->afficher();
    pt3 = *pt5*ra1; pt3->afficher();

    cout <<"\n---------- DIVISION -----------\n";

    pt1 = re1/e1; pt1->afficher();
    pt1 = *pt5/e1; pt1->afficher();
    pt2 = re1/re1; pt2->afficher();
    pt2 = *pt5/re1; pt2->afficher();
    pt3 = re1/ra1; pt3->afficher();
    pt3 = *pt5/ra1; pt3->afficher();


    cout <<"\n---------- EGALITE -----------\n";

    pt1 = re1==e1; pt1->afficher();
    pt1 = *pt5==e1; pt1->afficher();
    pt1 = re1==re1; pt1->afficher();
    pt1 = *pt5==re1; pt1->afficher();
    pt1 = re1==ra1; pt1->afficher();
    pt1 = *pt5==ra1; pt1->afficher();
    pt1 = re1==lc1; pt1->afficher();

    cout <<"\n---------- INEGALITE -----------\n";

    pt1 = re1!=e1;  pt1->afficher();
    pt1 = *pt5!=e1; pt1->afficher();
    pt1 = re1!=re1; pt1->afficher();
    pt1 = *pt5!=re1; pt1->afficher();
    pt1 = re1!=ra1; pt1->afficher();
    pt1 = *pt5!=ra1; pt1->afficher();
    pt1 = re1!=lc1; pt1->afficher();





    cout << endl << endl << endl ;
    lc1.afficher();
    cout <<"========== LITTERALE COMPLEXE ==========\n";
    cout <<"\n---------- ADDITION -----------\n";

    pt1 = lc1+e1; pt1->afficher();
    pt1 = *pt7+e1; pt1->afficher();
    pt2 = lc1+re1; pt2->afficher();
    pt2 = *pt7+re1; pt2->afficher();
    pt3 = lc1+ra1; pt3->afficher();
    pt3 = *pt7+ra1; pt3->afficher();
    pt0 = lc1+lc1; pt0->afficher();
    pt0 = *pt7+lc1; pt0->afficher();

    cout <<"\n---------- SOUSTRACTION -----------\n";

    pt1 = lc1-e1; pt1->afficher();
    pt1 = *pt7-e1; pt1->afficher();
    pt2 = lc1-re1; pt2->afficher();
    pt2 = *pt7-re1; pt2->afficher();
    pt3 = lc1-ra1; pt3->afficher();
    pt3 = *pt7-ra1; pt3->afficher();
    pt0 = lc1-lc1; pt0->afficher();
    pt0 = *pt7-lc1; pt0->afficher();

    cout <<"\n---------- MULTIPLICATION -----------\n";

    pt1 = lc1*e1; pt1->afficher();
    pt1 = *pt7*e1; pt1->afficher();
    pt2 = lc1*re1; pt2->afficher();
    pt2 = *pt7*re1; pt2->afficher();
    pt3 = lc1*ra1; pt3->afficher();
    pt3 = *pt7*ra1; pt3->afficher();
    pt0 = lc1*lc1; pt0->afficher();
    pt0 = *pt7*lc1; pt0->afficher();

    cout <<"\n---------- DIVISION -----------\n";

    pt1 = lc1/e1; pt1->afficher();
    pt1 = *pt7/e1; pt1->afficher();
    pt2 = lc1/re1; pt2->afficher();
    pt2 = *pt7/re1; pt2->afficher();
    pt3 = lc1/ra1; pt3->afficher();
    pt3 = *pt7/ra1; pt3->afficher();
    pt0 = lc1/lc1; pt0->afficher();
    pt0 = *pt7/lc1; pt0->afficher();

    cout <<"\n---------- EGALITE -----------\n";

    pt1 = lc1==e1; pt1->afficher();
    pt1 = *pt7==e1; pt1->afficher();
    pt1 = lc1==re1; pt1->afficher();
    pt1 = *pt7==re1; pt1->afficher();
    pt1 = lc1==ra1; pt1->afficher();
    pt1 = *pt7==ra1; pt1->afficher();
    pt1 = lc1==lc1; pt1->afficher();

    cout <<"\n---------- INEGALITE -----------\n";

    pt1 = lc1!=e1;  pt1->afficher();
    pt1 = *pt7!=e1; pt1->afficher();
    pt1 = lc1!=re1; pt1->afficher();
    pt1 = *pt7!=re1; pt1->afficher();
    pt1 = lc1!=ra1; pt1->afficher();
    pt1 = *pt7!=ra1; pt1->afficher();
    pt1 = lc1!=lc1; pt1->afficher();





    delete pt1;
    delete pt2;
    delete pt3;
    delete pt4;
    delete pt5;
    delete pt6;
    delete e2;
    delete re2;
    delete ra2;
    delete ra3;

    */

