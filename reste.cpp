

/*
void Calculatrice::Eval(const QString& exp1) {
    QStack<QChar> stack; stack.clear();
    const QString& exp = exp1 % ' ';
    int i=0;
    int lg = exp.length() - 1;
    QString resultat = "";
    QString tmp, tmp2;
    stringstream ss; ss.str("");
    string st, st2;
    QChar qc;
    QRegExp qre("^+||-||*||/||$||<||>||DIV||MOD||");

    while(i < lg) {

        //cout << "i = " << i << endl;

        if(exp[i] == '.' || (exp[i] >= '0' && exp[i] <= '9')) {
            //cout << "on est dans boucle nombre" << endl;
            while((exp[i] == '.' || (exp[i] >= '0' && exp[i] <= '9')) && i < lg) {
                resultat = resultat % exp[i];
                i++;
            }
            resultat = resultat % ' ';
            //cout << "resultatboucle = " << resultat.toStdString() << endl;
        }

        else {
            //if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '$' || exp[i] == '<' || exp[i] == '>')
            //if(estUnOperateurBinaire(exp[i]) || estUnOperateurUnaire(exp[i]))

            if(exp[i] < '0' || exp[i] > '9') {
                if(exp[i] == '(') {
                    stack.push('(');
                    if(i < lg) i++;
                }
                else {
                    if(estUnOperateurBinaire(exp[i])) {
                        if(stack.isEmpty()) {
                            stack.push(exp[i]);
                            if(i < lg) i++;
                        }

                        else {
                            if(prioriteOp(exp[i]) >= prioriteOp(stack.top())) {
                                stack.push(exp[i]);
                                if(i < lg) i++;
                            }

                            else {
                                while(prioriteOp(exp[i]) < prioriteOp(stack.top())) {
                                    tmp = stack.pop();
                                    if(resultat[resultat.length() - 1] != ' ') {
                                        resultat = resultat % " " % tmp;
                                    }
                                    else {
                                       resultat = resultat % tmp;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    while(!stack.isEmpty()) {
        qc = stack.pop();
        tmp = qc;
        if(resultat[resultat.length() - 1] != ' ') {
            resultat = resultat % " " % tmp;
        }
        else {
           resultat = resultat % tmp;
        }
    }

    resultat = resultat % ' ';
    cout << "resultat2 = " << resultat.toStdString() << endl;


    st = resultat.toStdString();
    i=0;
    while(i < st.length()) {
        if(st[i] == ' ') {
            st2 = ss.str();
            cout << "commande:" << st2 << "/commande" << endl;
            commande(QString::fromStdString(st2));
            cout << "apres commande" << endl;
            ss.str("");
        }
        else {
            ss << st[i];
        }
        i++;
    }
    return;
}
*/




/*

if(exp[i] >= '0' && exp[i] <='9') {
    nb=0;
    while(exp[i] >= '0' && exp[i] <='9') {
        nb*=10;
        nb+=exp[i].toLatin1() - '0';
        if(i < lg) i++;
    }
    if(exp[i] == '.') {
        nb1=0.;
        cpt=0;
        if(i < lg) i++;
        if(exp[i] >= '0' && exp[i] <='9') {
            while(exp[i] >= '0' && exp[i] <='9') {
                nb1*=10;
                nb1+=exp[i].toLatin1() - '0';
                if(i < lg) i++;
                cpt++;
            }
            cpt=pow(10,cpt);
            nb1=(double)(nb1/cpt);
            nb1+=(double)nb;
            tmp = QString::number(nb1);
            resultat = resultat % " " % tmp;
        }
        else {
            tmp = QString::number(nb);
            resultat = resultat % " " % tmp;
        }
    }
    else {
        tmp = QString::number(nb);
        resultat = resultat % " " % tmp;
    }
}
else {
    if(exp[i]=='.') {
        nb1=0.;
        cpt=0;
        if(i < lg) i++;
        if(exp[i] >= '0' && exp[i] <='9') {
            while(exp[i] >= '0' && exp[i] <='9') {
                nb1*=10;
                nb1+=exp[i].toLatin1() - '0';
                if(i < lg) i++;
                cpt++;
            }
            cpt=pow(10,cpt);
            nb1=(double)(nb1/cpt);
            tmp = QString::number(nb1);
            resultat = resultat % " " % tmp;
            cout << resultat.toStdString() << endl;
        }
    }



*/










/*
LiEntiere* e1 = new LiEntiere(10);
LiReelle* re1 = new LiReelle(5.5);
LiEntiere* e2 = new LiEntiere(11);
LiReelle* re2 = new LiReelle(5.5);
LiRationnelle* ra1 = new LiRationnelle(11,2);
LiComplexe* comp1 = new LiComplexe(e1, re2);
LiComplexe* comp2 = new LiComplexe(e2, re2);

Litterale* egalegal = (*comp1 == *comp2);
if( egalegal->getValue() == 1 ) cout<<"vrai";
else cout<<"faux";

//Atome* a = new Atome("AZERTY123");

//Litterale* pt4 = &e1;
//Litterale* pt5 = &re1;
//Litterale* pt6 = &comp1;


Pile p;
p.push(e1);
p.push(re1);
p.push(comp1);
p.push(ra1);
//p.push(a);
p.push(*comp1 - *e1);
p.affiche();

p.swap();
p.affiche();
p.drop();
p.affiche();
p.dup();
p.affiche();
//p.clear();
//p.affiche();

string s1, s2, s3;
s1="abc";
s2="def";
s3="("+s1+")"+"("+s2+")";
cout << s3 << endl;

QString d1 = "67.876";
cout << "estEntier() : " << estEntier(d1) << endl;
cout << "estDouble() : " << estDouble(d1) << endl;

cout << d1.toDouble() << endl;

//delete p;
*/
/*
QString s1 = "abc";
QString s2 = "def";
LiEntiere lie1(12);
LiReelle lir1(1.3);
LiComplexe lic1(&lie1,&lir1);
Litterale* l1 = new LiExpression(s1);
Litterale* l2 = new LiExpression(s2);
Litterale* l3 = (*l1) + lic1;
LiExpression* l4= dynamic_cast<LiExpression*>(l3);
cout << l4->getExpression().toStdString() << endl;
delete l1, l2, l3;
*/
/*
QString qs("12+3.4*9");
QChar qc;
for(QString::iterator it = qs.begin(); it!=qs.end(); it++) {
    qc = *it;
    cout << qc.toLatin1();
    cout << endl;
}
*/
