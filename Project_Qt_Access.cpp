#include "Project_Qt_Access.h"
#include <QDebug>
#include <QFileDialog>

Project_Qt_Access::Project_Qt_Access(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
}

void Project_Qt_Access::on_Database_Connection_clicked()
{
    db.connect(ui.Database_Path->text().toStdString());
    
    if (db.Connected())
    {
        ui.Database_info->setText("Successfully connected to the database.");
        ui.Create_table->setEnabled(true);
        ui.Add_Item->setEnabled(true);
        ui.Delete_Item->setEnabled(true);
    }
    else
    {
        ui.Database_info->setText(QString("Failed to connect to the database. %1").arg(db.error_info));
    }
}

void Project_Qt_Access::on_Select_Database_clicked()
{
    QString FileName = QFileDialog::getOpenFileName(this, tr(""), "", tr("MS Access Database(*.mdb *.accdb)")); //ѡ��·��
    ui.Database_info->setText("");
    ui.Database_Path->setText(FileName);
}

void Project_Qt_Access::on_Delete_Item_clicked()
{
    Subwindow_Delete* subwin = new Subwindow_Delete();
    subwin->show();
    subwin->ui.Table_select->addItems(db.show_table());
}
