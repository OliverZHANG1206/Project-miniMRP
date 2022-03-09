#include "Access_DB.h"

AdoAccess::AdoAccess()
{
	error_flag = false;
}

void AdoAccess::connect(string s)
{
	string path = "Provider=Microsoft.ACE.OLEDB.12.0; Data Source=" + s + "; Persist Security Info = False";
	CoInitialize(NULL);
	try
	{
		HX_pConnection.CreateInstance(__uuidof(Connection));
		_bstr_t strConnect(path.c_str());
		HX_pConnection->Open(strConnect, "", "", adModeUnknown);	//连接数据库
		HX_pRecordset.CreateInstance("ADODB.Recordset");
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

void AdoAccess::select_table(CString table)
{
	CString comm = "SELECT * FROM " + table;
	HX_pRecordset->Open((LPCTSTR)comm, HX_pConnection.GetInterfacePtr(), adOpenDynamic, adLockOptimistic, adCmdText);
}

QString AdoAccess::show_item(CString col)
{
	string str;
	while (!HX_pRecordset->AdoNSEOF)
	{
		_variant_t var = HX_pRecordset->GetCollect((LPCTSTR)col);

		if (var.vt != VT_NULL)
			str += _com_util::ConvertBSTRToString((_bstr_t)var);

		str += '\n';
		HX_pRecordset->MoveNext();
	}
	return QString::fromStdString(str);
}

void AdoAccess::append_item(string s[])
{
	
}

QStringList AdoAccess::show_table()
{
	QStringList table_list;
	table_list << "<Select>";
	HX_pRecordset = HX_pConnection->OpenSchema(adSchemaTables);
	while (!HX_pRecordset->AdoNSEOF)
	{
		_bstr_t tblname = HX_pRecordset->Fields->GetItem("TABLE_NAME")->Value;
		_bstr_t tbltype = HX_pRecordset->Fields->GetItem("TABLE_TYPE")->Value;
		if (!strcmp(tbltype, "TABLE"))
		{
			string str = (char*)tblname;
			table_list << QString::fromStdString(str);
		}
		HX_pRecordset->MoveNext();
	}
	return table_list;
}
