
// 学生信息管理系统Set.cpp : C学生信息管理系统Set 类的实现
//

#include "stdafx.h"
#include "学生信息管理系统.h"
#include "学生信息管理系统Set.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C学生信息管理系统Set 实现

// 代码生成在 2020年6月1日, 14:26

IMPLEMENT_DYNAMIC(C学生信息管理系统Set, CRecordset)

C学生信息管理系统Set::C学生信息管理系统Set(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	column1 = L"";
	column2 = L"";
	column3 = L"";
	column4 = L"";
	column5 = 0.0;
	column6 = 0;
	column7 = L"";
	column8 = L"";
	column9 = L"";
	m_nFields = 10;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString C学生信息管理系统Set::GetDefaultConnect()
{
	return _T("DBQ=D:\\Data\\\x5b66\x4e60\x6587\x4ef6\\Visual C++\x4e0eWindows\x5e94\x7528\x5f00\x53d1\\\x6570\x636e\x5e93\\\x5b66\x751f\x4fe1\x606f\x7ba1\x7406\x7cfb\x7edf.mdb;DefaultDir=D:\\Data\\\x5b66\x4e60\x6587\x4ef6\\Visual C++\x4e0eWindows\x5e94\x7528\x5f00\x53d1\\\x6570\x636e\x5e93;Driver={Microsoft Access Driver (*.mdb, *.accdb)};DriverId=25;FIL=MS Access;FILEDSN=D:\\Data\\\x5b66\x4e60\x6587\x4ef6\\Visual C++\x4e0eWindows\x5e94\x7528\x5f00\x53d1\\\x6570\x636e\x5e93\\\x5b66\x751f\x4fe1\x606f\x7ba1\x7406\x7cfb\x7edf.mdb.dsn;MaxBufferSize=2048;MaxScanRows=8;PageTimeout=5;SafeTransactions=0;Threads=3;UID=admin;UserCommitSync=Yes;");
}

CString C学生信息管理系统Set::GetDefaultSQL()
{
	return _T("[表1]");
}

void C学生信息管理系统Set::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[姓名]"), column1);
	RFX_Text(pFX, _T("[学号]"), column2);
	RFX_Text(pFX, _T("[专业]"), column3);
	RFX_Text(pFX, _T("[性别]"), column4);
	RFX_Double(pFX, _T("[出生年月]"), column5);
	RFX_Long(pFX, _T("[手机号码]"), column6);
	RFX_Text(pFX, _T("[家庭住址]"), column7);
	RFX_Text(pFX, _T("[相片文件名]"), column8);
	RFX_Text(pFX, _T("[相片文件夹]"), column9);

}
/////////////////////////////////////////////////////////////////////////////
// C学生信息管理系统Set 诊断

#ifdef _DEBUG
void C学生信息管理系统Set::AssertValid() const
{
	CRecordset::AssertValid();
}

void C学生信息管理系统Set::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

