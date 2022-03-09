#pragma once

#include <QWidget>
#include "ui_Subwindow_Delete.h"

class Subwindow_Delete : public QWidget
{
	Q_OBJECT

	public:
		Subwindow_Delete(QWidget *parent = Q_NULLPTR);
		~Subwindow_Delete();
		Ui::Subwindow_Delete ui;
};
