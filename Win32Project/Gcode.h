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
	Gcode(DatabaseLayer* database,const wxString& table);
	bool Create(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
	GcodeRow* New();
	GcodeRow* Id(int key);

	bool Delete(int key);
	GcodeRowSet* All();

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
	wxString code;
	int elementid;
	int id;
public:
	ElementRow* GetElement();

	bool Save();
	bool Delete();


};
class GcodeRowSet: public wxActiveRecordRowSet{
public:
	GcodeRowSet();
	GcodeRowSet(wxActiveRecord* activeRecord);
	GcodeRowSet(DatabaseLayer* database,const wxString& table);
	virtual GcodeRow* Item(unsigned long item);
	virtual bool SaveAll();
protected:
	static int CMPFUNC_id(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_code(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	static int CMPFUNC_elementid(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
	virtual CMPFUNC_proto GetCmpFunc(const wxString& var) const;

};

#endif