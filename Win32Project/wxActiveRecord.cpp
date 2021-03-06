///////////////////////////////////////////////////////////////////////////////
// Name:		wxActiveRecord.cpp
// Purpose:     Base classes of wxActiveRecord
// Author:      Matas Szeftel
// Modified by:
// Created:     01/10/2006
// Copyright:   (c) 2006 Matas Szeftel - mszeftel@yahoo.com.ar
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#include "wxActiveRecord.h"

//begin WX_ACTIVE_RECORD

wxActiveRecord::wxActiveRecord(){
	m_generatedConnection=false;
}

wxActiveRecord::wxActiveRecord(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password){
	m_generatedConnection=true;
}

wxActiveRecord::wxActiveRecord(DatabaseLayer* database,const wxString& table){
	m_generatedConnection=false;;
	Create(database,table);
}

bool wxActiveRecord::Create(DatabaseLayer* database,const wxString& table){
	if(database==NULL)
		return false;

	m_table=table;
	m_database=database;

	return true;
}

wxActiveRecord::~wxActiveRecord(){
	if(m_generatedConnection){
		if(m_database!=NULL){
			delete m_database;
		}
	}

	while(garbageRows.Count()>0){
		delete garbageRows.Item(0);
		garbageRows.RemoveAt(0);
	}
	garbageRows.Clear();

	while(garbageRowSets.Count()>0){
		delete garbageRowSets.Item(0);
		garbageRowSets.RemoveAt(0);
	}
	garbageRowSets.Clear();
}

DatabaseLayer* wxActiveRecord::GetDatabase() const{
	return m_database;
}

wxString wxActiveRecord::GetTable() const{
	return m_table;
}

void wxActiveRecord::ProcessException(DatabaseLayerException& e){
	wxMessageBox(wxString::Format(wxT("%d: %s."),e.GetErrorCode(),e.GetErrorMessage().c_str()),wxT("Database Error"));
}

void wxActiveRecord::CollectRow(wxActiveRecordRow* row){
	int index =garbageRows.Index(row);
	delete garbageRows.Item(index);
	garbageRows.RemoveAt(index);
}

void wxActiveRecord::CollectRowSet(wxActiveRecordRowSet* set){
	int index =garbageRowSets.Index(set);
	delete garbageRowSets.Item(index);
	garbageRowSets.RemoveAt(index);
}

//end WX_ACTIVE_RECORD


//begin WX_ACTIVE_RECORD_ROW

wxActiveRecordRow::wxActiveRecordRow(){
	m_database=0;
}

wxActiveRecordRow::wxActiveRecordRow(wxActiveRecord* activeRecord){
	Create(activeRecord);
}

wxActiveRecordRow::wxActiveRecordRow(DatabaseLayer* database,const wxString& table){
	Create(database,table);
}

wxActiveRecordRow::~wxActiveRecordRow(){
	while(garbageRows.Count()>0){
		delete garbageRows.Item(0);
		garbageRows.RemoveAt(0);
	}
	garbageRows.Clear();

	while(garbageRowSets.Count()>0){
		delete garbageRowSets.Item(0);
		garbageRowSets.RemoveAt(0);
	}
	garbageRowSets.Clear();
}

bool wxActiveRecordRow::Create(wxActiveRecord* activeRecord){
	m_database=activeRecord->GetDatabase();
	m_table=activeRecord->GetTable();

	return true;
}

bool wxActiveRecordRow::Create(DatabaseLayer* database,const wxString& table){
	m_database=database;
	m_table=table;

	return true;
}

bool wxActiveRecordRow::Save(){
	return true;
}

bool wxActiveRecordRow::Delete(){
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

void wxActiveRecordRow::CollectRow(wxActiveRecordRow* row){
	int index =garbageRows.Index(row);
	delete garbageRows.Item(index);
	garbageRows.RemoveAt(index);
}

void wxActiveRecordRow::CollectRowSet(wxActiveRecordRowSet* set){
	int index =garbageRowSets.Index(set);
	delete garbageRowSets.Item(index);
	garbageRowSets.RemoveAt(index);
}

//end WX_ACTIVE_RECORD_ROW

//begin WX_ACTIVE_RECORD_ROW_SET

wxActiveRecordRowSet::wxActiveRecordRowSet():ArrayOfRows(){
	m_database=0;
}
wxActiveRecordRowSet::wxActiveRecordRowSet(wxActiveRecord* activeRecord):ArrayOfRows(){
	Create(activeRecord);
}

wxActiveRecordRowSet::wxActiveRecordRowSet(DatabaseLayer* database,const wxString& table):ArrayOfRows(){
	Create(database,table);
}

wxActiveRecordRowSet::~wxActiveRecordRowSet(){
	while(Count()>0){
		delete Item(0);
		RemoveAt(0);
	}
	Clear();
}

bool wxActiveRecordRowSet::Create(wxActiveRecord* activeRecord){
	m_database=activeRecord->GetDatabase();
	m_table=activeRecord->GetTable();

	return true;
}

bool wxActiveRecordRowSet::Create(DatabaseLayer* database,const wxString& table){
	m_database=database;
	m_table=table;

	return true;
}

bool wxActiveRecordRowSet::SaveAll(){
	for(unsigned long i=0;i<Count();i++){
		if(!Item(0)->Save())
			return false;
	}
	return true;
}

int wxActiveRecordRowSet::CMPFUNC_global(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	int res=0;
	size_t level=0;
	//size_t count=cmpArr.Count();
	size_t count=cmpArr.size();

	while(res==0&&level<count){
		if(ascArr[level])
			//res=cmpArr.Item(level)(item1,item2);
			res=cmpArr[level](item1,item2);
		else
			//res=-cmpArr.Item(level)(item1,item2);
			res=-cmpArr[level](item1,item2);
		level++;
	}
	return res;
}

int wxActiveRecordRowSet::CMPFUNC_default(wxActiveRecordRow** item1,wxActiveRecordRow** item2){
	return 0;
}

CMPFUNC_proto wxActiveRecordRowSet::GetCmpFunc(const wxString& var) const{
	return &wxActiveRecordRowSet::CMPFUNC_default;
}

void wxActiveRecordRowSet::SortBy(const wxString& SortBy){
	
	lastSort=SortBy;

	wxString sortBy=SortBy;

	
	cmpArr.clear();
	wxActiveRecordRowSet::ascArr.Empty();

	wxStringTokenizer tkz(sortBy,wxT(","));
	while(tkz.HasMoreTokens()){
		wxStringTokenizer tkz2(tkz.GetNextToken().Trim(),wxT(" "));
		
		cmpArr.push_back(GetCmpFunc(tkz2.GetNextToken()));
		if(tkz2.HasMoreTokens()){
			wxString strAsc=tkz2.GetNextToken();
			if(!strAsc.CmpNoCase(wxT("desc")))
				ascArr.Add(false);
			else
				ascArr.Add(true);
		}
		else
			ascArr.Add(true);

	}

	Sort(CMPFUNC_global);
	
	
	cmpArr.clear();
	ascArr.Empty();

}

void wxActiveRecordRowSet::ReSort(){
	SortBy(lastSort);
}

std::vector<CMPFUNC_proto> wxActiveRecordRowSet::cmpArr;
AscArr wxActiveRecordRowSet::ascArr;
wxString wxActiveRecordRowSet::lastSort;


#ifdef AR_USE_SQLITE

wxSqliteActiveRecord::wxSqliteActiveRecord():wxActiveRecord(){
	m_database=NULL;
}

wxSqliteActiveRecord::wxSqliteActiveRecord(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password):wxActiveRecord(table,name,server,user,password){
	m_database=NULL;
	Create(table,name,server,user,password);
}

wxSqliteActiveRecord::wxSqliteActiveRecord(DatabaseLayer* database,const wxString& table):wxActiveRecord(database,table){
}

bool wxSqliteActiveRecord::Create(const wxString& table,const wxString& name,const wxString& server,const wxString& user,const wxString& password){
	if(m_database!=0){
		delete m_database;
		m_database=0;
	}
	try{
		m_table=table;
		m_database = new SqliteDatabaseLayer(name);
		return true;
	}
	catch(DatabaseLayerException& e){
		throw(e);
		return false;
	}
}


#endif