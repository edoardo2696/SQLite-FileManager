#ifndef __GCODE_
#define __GCODE_

#include "wxActiveRecord.h"
#include <wx/wx.h>
#include <wx/string.h>
#include <wx/datetime.h>
#include "Element.h"

class Gcode;
class GcodeRow;
class GcodeRowSet;

class Element;
class ElementRow;
class ElementRowSet;

class Gcode: public wxSqliteActiveRecord{
protected:
	GcodeRow* RowFromResult(DatabaseResultSet* result);
public:
	Gcode();
	Gcode(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
	Gcode(DatabaseLayer* database,const wxString& table);
	bool Create(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
	GcodeRow* New();


	bool Delete(wxString key);

	GcodeRow* Where(const wxString& whereClause);
	GcodeRowSet* WhereSet(const wxString& whereClause);
	GcodeRowSet* All(); 

public:
};
class GcodeRow: public wxActiveRecordRow{
public:
	GcodeRow();
	GcodeRow(const GcodeRow& src);
	GcodeRow(Gcode* activeRecord);
	GcodeRow(DatabaseLayer* database,const wxString& table);
	GcodeRow& operator=(const GcodeRow& src);
	bool GetFromResult(DatabaseResultSet* result);
public:
	wxString gcode;
	int elementid;

public:
	ElementRow* GetElement();

	bool Save();
	bool Delete();

public:
};
class GcodeRowSet: public wxActiveRecordRowSet{
public:
	GcodeRowSet();
	GcodeRowSet(wxActiveRecord* activeRecord);
	GcodeRowSet(DatabaseLayer* database,const wxString& table);
	virtual GcodeRow* Item(unsigned long item);
	virtual bool SaveAll();
protected:
	static int CMPFUNC_gcode(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_elementid(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_global(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	virtual CMPFUNC_proto GetCmpFunc(const wxString& var) const;

public:
};

#endif