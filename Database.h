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


class AdoAccess {
	public:
		QString         error_info;

		AdoAccess(string);
		bool Connected();
		void quitconnection();

	private:
		bool error_flag;

		_ConnectionPtr  HX_pConnection; // ���ݿ�ָ��
		_RecordsetPtr   HX_pRecordset;  // ����ָ��
		_CommandPtr     HX_pCommand;    // ��¼ָ�� 
};

AdoAccess::AdoAccess(string s)
{
	string path = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + s + "; Persist Security Info = False";
	CoInitialize(NULL);
	try
	{
		HX_pConnection.CreateInstance(__uuidof(Connection));
		_bstr_t strConnect(path.c_str()); //"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=DataLib.accdb;Persist Security Info=False";
		HX_pConnection->Open(strConnect, "", "", adModeUnknown);	//�������ݿ�
		error_flag = false;
	}
	catch (_com_error e)
	{
		error_flag = true;
		string msg = "Error: " + e.Description();
		error_info = QString::fromLocal8Bit(msg.data());
	}
}

void AdoAccess::quitconnection()
{
	if (HX_pRecordset != NULL)
		HX_pRecordset->Close();
	HX_pConnection->Close();
	CoUninitialize();
}

bool AdoAccess::Connected()
{
	return !error_flag;
}