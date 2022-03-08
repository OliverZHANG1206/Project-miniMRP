#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_Project_Qt_Access.h"

class Project_Qt_Access : public QMainWindow
{
    Q_OBJECT

    public slots:
        void on_Database_Connection_clicked();
        void on_Select_Database_clicked();

    public:
        Project_Qt_Access(QWidget *parent = Q_NULLPTR);

    private:
        Ui::Project_Qt_AccessClass ui;

};
