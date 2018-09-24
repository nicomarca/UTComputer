#ifndef LIEXCEPTION_H
#define LIEXCEPTION_H

/**
 * \file liexception.h
 * \brief file where the class managing the exception is defined
 * \author Virgile VANCON and Nicolas MARCADET
 * \version 0.1
 * \date 12 Juin 2016
 *
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <typeinfo>
#include <sstream>
#include <cstdlib>
#include <QString>
#include <QStringBuilder>
#include <QTextStream>
#include <QMainWindow>
#include <QDebug>
#include <QWidget>
#include <QLineEdit>
#include <QKeyEvent>
#include <QTableWidget>
#include <QRegexp>
#include <QStack>
#include <Map>
#include <QComboBox>


using namespace std;

#endif // LIEXCEPTION_H

//////////////////////////////////////// LITTERALE EXCEPTION ////////////////////////////////////////


/// \class The LiException class
///
/// \brief class to manage all the exception of the calculator
///
/// All the exception are send to this class
///


class LiException {
        QString info; /*!< info : attribut of type QString (message send to a LiException object)*/

public:
        /*!
         *  \brief Constructor
         *
         *  Constructor of the LiException class
         *  Inline Method
         *
         *  \param 1 parameter of type const QString& to initialize the info attribute
         */
        LiException(const QString& s) :info(s) {}

        /*!
         *  \brief getInfo() method
         *
         *  Accessor to the attribute
         *
         *  \param 1 parameter of type const QString& to initialize the info attribute
         *  \return const reference to QString (message sould not be modified)
         */
        const QString& getInfo() const {return info;}
};
