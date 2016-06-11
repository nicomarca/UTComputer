#include"liexpression.h"


//////////////////////////////////////// EXPRESSION ////////////////////////////////////////



Litterale* LiExpression::operator+ (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
        return new LiExpression("("%getExpression()%")+("%lie.getExpression()%")");
    }
    QString qs = QString::fromStdString(li.toString());
    return new LiExpression("("%getExpression() % ")+(" % qs % ")");
}


Litterale* LiExpression::operator- (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
        return new LiExpression("("%getExpression()%")-("%lie.getExpression()%")");
    }
    QString qs = QString::fromStdString(li.toString());
    return new LiExpression("("%getExpression() % ")-(" % qs % ")");
}


Litterale* LiExpression::operator/ (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
        return new LiExpression("("%getExpression()%")/("%lie.getExpression()%")");
    }
    QString qs = QString::fromStdString(li.toString());
    return new LiExpression("("%getExpression() % ")/(" % qs % ")");
}


Litterale* LiExpression::operator* (const Litterale& li) const {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& lie = dynamic_cast<const LiExpression&>(li);
        return new LiExpression("("%getExpression()%")*("%lie.getExpression()%")");
    }
    QString qs = QString::fromStdString(li.toString());
    return new LiExpression("("%getExpression() % ")*(" % qs % ")");
}


Litterale* LiExpression::Div (const Litterale& li) {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& exp1 = dynamic_cast<const LiExpression&>(li);
        return new LiExpression("DIV(" % getExpression() % "," % exp1.getExpression() % ")");
    }
    else {
        QString qs2 = QString::fromStdString(li.toString());
        return new LiExpression("DIV(" % getExpression() % "," % qs2 % ")");
    }
}


Litterale* LiExpression::Mod (const Litterale& li) {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression& exp1 = dynamic_cast<const LiExpression&>(li);
        return new LiExpression("MOD(" % getExpression() % "," % exp1.getExpression() % ")");
    }
    else {
        QString qs2 = QString::fromStdString(li.toString());
        return new LiExpression("MOD(" % getExpression() % "," % qs2 % ")");
    }
}


Litterale* LiExpression::Num() {
    return new LiExpression("NUM("%getExpression() % ")");
}

Litterale* LiExpression::Den() {
    return new LiExpression("DEN("%getExpression() % ")");
}

Litterale* LiExpression::Re() {
    return new LiExpression("RE("%getExpression() % ")");
}

Litterale* LiExpression::Im() {
    return new LiExpression("IM("%getExpression() % ")");
}

Litterale* LiExpression::Neg() {
    return new LiExpression("NEG("%getExpression() % ")");
}


Litterale* LiExpression::And(const Litterale* li) {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression* exp1 = dynamic_cast<const LiExpression*>(li);
        return new LiExpression("AND(" % getExpression() % "," % exp1->getExpression() % ")");
    }
    else {
        QString qs2 = QString::fromStdString(li->toString());
        return new LiExpression("AND(" % getExpression() % "," % qs2 % ")");
    }
}


Litterale* LiExpression::Or(const Litterale* li) {
    if(typeid(li) == typeid(LiExpression)) {
        const LiExpression* exp1 = dynamic_cast<const LiExpression*>(li);
        return new LiExpression("OR(" % getExpression() % "," % exp1->getExpression() % ")");
    }
    else {
        QString qs2 = QString::fromStdString(li->toString());
        return new LiExpression("OR(" % getExpression() % "," % qs2 % ")");
    }
}


Litterale* LiExpression::Not() {
    return new LiExpression("NOT(" % getExpression() % ")");
}


LiExpression* LiExpression::enleverGuillemets(const QString& s) {
    QString s1;
    for(int i=1; i<s.length()-1; i++) {
        s1[i-1]=s[i];
    }
    return new LiExpression(s1);
}
