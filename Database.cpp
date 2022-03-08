#include <Database.h>

AdoAccess::AdoAccess(string s)
{
	string path = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + s + "; Persist Security Info = False";
	CoInitialize(NULL);
	try
	{
		HX_pConnection.CreateInstance(__uuidof(Connection));
		_bstr_t strConnect(path.c_str()); //"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=DataLib.accdb;Persist Security Info=False";
		HX_pConnection->Open(strConnect, "", "", adModeUnknown);	//连接数据库
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