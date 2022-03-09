#pragma once
#include <QtWidgets/QMainWindow>

#include "Access_DB.h"
#include "ui_Project_Qt_Access.h"
#include "Subwindow_Delete.h"

class Project_Qt_Access : public QMainWindow
{
    Q_OBJECT

    public slots:
        void on_Database_Connection_clicked();
        void on_Select_Database_clicked();
        void on_Delete_Item_clicked();

    public:
        Project_Qt_Access(QWidget *parent = Q_NULLPTR);

    private:
        AdoAccess db;
        Ui::Project_Qt_AccessClass ui;
};

