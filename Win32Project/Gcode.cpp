#include "Gcode.h"


Gcode::Gcode():wxSqliteActiveRecord(){
}

Gcode::Gcode(DatabaseLayer* database,const wxString& table):wxSqliteActiveRecord(database,table){
}

bool Gcode::Create(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password){
	return wxSqliteActiveRecord::Create(table,name,server,user,password);
}

GcodeRow* Gcode::RowFromResult(DatabaseResultSet* result){
	GcodeRow* row=new GcodeRow(this);
	
	row->GetFromResult(result);
	
	return row;
}

GcodeRow* Gcode::New(){
	GcodeRow* newRow=new GcodeRow(this);
	garbageRows.Add(newRow);
	return newRow;
}

GcodeRow* Gcode::Id(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		DatabaseResultSet* result= pStatement->ExecuteQuery();

		result->Next();
		GcodeRow* row=RowFromResult(result);
		garbageRows.Add(row);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);
		return row;
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return nullptr;
	}
}

bool Gcode::Delete(int key){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,key);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}


GcodeRowSet* Gcode::All(){
	GcodeRowSet* rowSet=new GcodeRowSet();
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("SELECT * FROM %s"),m_table.c_str()));
		DatabaseResultSet* result= pStatement->ExecuteQuery();
		
		if(result){
			while(result->Next()){
				rowSet->Add(RowFromResult(result));
			}
		}
		garbageRowSets.Add(rowSet);
		m_database->CloseResultSet(result);
		m_database->CloseStatement(pStatement);	
		return rowSet;
		
	}
	catch (DatabaseLayerException& e)
	{
		ProcessException(e);
		return 0;
	}
}


GcodeRow::GcodeRow():wxActiveRecordRow(){
	bool newRow=true;
}

GcodeRow::GcodeRow(Gcode* activeRecord):wxActiveRecordRow(activeRecord){
	bool newRow=true;
}

GcodeRow::GcodeRow(const GcodeRow& src){
	if(&src==this)
		return;
	newRow=src.newRow;
	
	code=src.code;
	elementid=src.elementid;
	id=src.id;
}

GcodeRow::GcodeRow(DatabaseLayer* database,const wxString& table):wxActiveRecordRow(database,table){
	newRow=true;
}
	
GcodeRow& GcodeRow::operator=(const GcodeRow& src){
	if(&src==this)
		return *this;
	newRow=src.newRow;

	code=src.code;
	elementid=src.elementid;
	id=src.id;


	return *this;
}

bool GcodeRow::GetFromResult(DatabaseResultSet* result){
	
	newRow=false;
		code=result->GetResultString(wxT("code"));
	elementid=result->GetResultInt(wxT("elementid"));
	id=result->GetResultInt(wxT("id"));

	return true;
}

bool GcodeRow::Save(){
	try{
		if(newRow){
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("INSERT INTO %s (elementid, code) VALUES (?,?)"),m_table.c_str()));
			//pStatement->SetParamInt(1,id);
			pStatement->SetParamString(2,code);
			pStatement->SetParamInt(1,elementid);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);

			
			newRow=false;
		}
		else{
			PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("UPDATE %s SET code=? ,elementid=? WHERE id=?"),m_table.c_str()));
			pStatement->SetParamInt(1,elementid);
			pStatement->SetParamString(2,code);
			pStatement->SetParamInt(3,id);
			pStatement->RunQuery();
			m_database->CloseStatement(pStatement);

		}
		
		return true;
	}
	catch (DatabaseLayerException& e)
	{
		wxActiveRecord::ProcessException(e);
		return false;
	}
}

bool GcodeRow::Delete(){
	try{
		PreparedStatement* pStatement=m_database->PrepareStatement(wxString::Format(wxT("DELETE FROM %s WHERE id=?"),m_table.c_str()));
		pStatement->SetParamInt(1,id);
		pStatement->ExecuteUpdate();
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}

ElementRow* GcodeRow::GetElement(){
	ElementRow* owner= new ElementRow(m_database,wxT("elements"));
	PreparedStatement* pStatement=m_database->PrepareStatement(wxT("SELECT * FROM elements WHERE id=?"));
	pStatement->SetParamInt(1,elementid);

	DatabaseResultSet* result= pStatement->ExecuteQuery();

	result->Next();
	owner->GetFromResult(result);
	garbageRows.Add(owner);
	m_database->CloseResultSet(result);
	m_database->CloseStatement(pStatement);
	return owner;
}


GcodeRowSet::GcodeRowSet():wxActiveRecordRowSet(){
}

GcodeRowSet::GcodeRowSet(wxActiveRecord* activeRecord):wxActiveRecordRowSet(activeRecord){
}

GcodeRowSet::GcodeRowSet(DatabaseLayer* database,const wxString& table):wxActiveRecordRowSet(database,table){
}

GcodeRow* GcodeRowSet::Item(unsigned long item){
	return (GcodeRow*)wxActiveRecordRowSet::Item(item);
}

bool GcodeRowSet::SaveAll(){
	try{
		m_database->BeginTransaction();
		for(unsigned long i=0;i<Count();i++)
			Item(i)->Save();
		m_database->Commit();
		return true;
	}
	catch (DatabaseLayerException& e)
	{
		m_database->RollBack();
		wxActiveRecord::ProcessException(e);
		return false;
	}
}

int GcodeRowSet::CMPFUNC_code(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	GcodeRow** m_item1=(GcodeRow**)item1;
	GcodeRow** m_item2=(GcodeRow**)item2;
	return (*m_item1)->code.Cmp((*m_item2)->code);
}

int GcodeRowSet::CMPFUNC_elementid(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	GcodeRow** m_item1=(GcodeRow**)item1;
	GcodeRow** m_item2=(GcodeRow**)item2;
	if((*m_item1)->elementid<(*m_item2)->elementid)
		return -1;
	else if((*m_item1)->elementid>(*m_item2)->elementid)
		return 1;
	else
		return 0;
}

int GcodeRowSet::CMPFUNC_id(wxActiveRecordRow **item1, wxActiveRecordRow **item2) {
	GcodeRow** m_item1=(GcodeRow**)item1;
	GcodeRow** m_item2=(GcodeRow**)item2;
	if((*m_item1)->id<(*m_item2)->id)
		return -1;
	else if((*m_item1)->id>(*m_item2)->id)
		return 1;
	else
		return 0;
}
CMPFUNC_proto GcodeRowSet::GetCmpFunc(const wxString& var) const{
	if(var==wxT("code"))
		return (CMPFUNC_proto)CMPFUNC_code;
	else if(var==wxT("elementid"))
		return (CMPFUNC_proto)CMPFUNC_elementid;
	else 
	return (CMPFUNC_proto)CMPFUNC_default;
}

