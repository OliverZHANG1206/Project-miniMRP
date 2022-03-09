#pragma once
#include <iostream>
#include <atlstr.h>
#include <sqlext.h>
#include <odbcinst.h>
#include <string>

#include <QString>
#include <QDebug>
#import  <C:\\Program Files\\Common Files\\System\\ado\\msado15.dll> rename("EOF", "AdoNSEOF")

using namespace ADODB;
using namespace std;

class AdoAccess
{
	public:
		AdoAccess();
		QString error_info;
		bool Connected();
		void connect(string);
		void select_table(CString);
		QStringList show_table();
		void append_item(string[]);
		QString show_item(CString);
		void quitconnection();

	private:
		bool error_flag;
		_ConnectionPtr  HX_pConnection; // ���ݿ�ָ��
		_RecordsetPtr   HX_pRecordset;  // ����ָ��
		_CommandPtr     HX_pCommand;    // ��¼ָ�� 
};