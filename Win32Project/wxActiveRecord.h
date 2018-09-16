
#ifndef _WX_ACTIVE_RECORD_H_
#define _WX_ACTIVE_RECORD_H_

#include <wx/wx.h>
#include <wx/string.h>
#include <wx/wfstream.h>
#include <wx/tokenzr.h>
#include <DatabaseLayer.h>
#include <DatabaseErrorCodes.h>
#include <DatabaseLayerException.h>

#include <vector>

#define AR_USE_SQLITE


class wxActiveRecord;
class wxActiveRecordRow;
class wxActiveRecordRowSet;


WX_DEFINE_ARRAY(wxActiveRecordRow* , ArrayOfRows);
WX_DEFINE_ARRAY(wxActiveRecordRowSet* , ArrayOfRowSets);


class wxActiveRecord{
protected:
        DatabaseLayer* m_database;
        wxString m_table;
        bool m_generatedConnection;
        ArrayOfRows garbageRows;
        ArrayOfRowSets garbageRowSets;

public:
        wxActiveRecord();
        /**
        \param table Is the table or view with you want to access.
        \param name Is the filename for sqlite3 or the database name for postgres and mysql
        */
        wxActiveRecord(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""));
        /**
        \param table Is the table or view with you want to access.
        \param database is a DatabaseLyaer pointer so you can reuse an open connection
        */
        wxActiveRecord(DatabaseLayer* database,const wxString& table);

        virtual ~wxActiveRecord();
        /**
        \param table Is the table or view with you want to access.
        \param name Is the filename for sqlite3 or the database name for postgres and mysql

        */
        virtual bool Create(const wxString& table,const wxString& name,const wxString& server=wxT(""),const wxString& user=wxT(""),const wxString& password=wxT(""))=0;
        /**
        \param table Is the table or view with you want to access.
        \param database is a DatabaseLyaer pointer so you can reuse an open connection
        */
        virtual bool Create(DatabaseLayer* database,const wxString& table);

        /**
         Returns the database.
        */
        virtual DatabaseLayer* GetDatabase() const;
        /**
        Returns the name of the table.
        */
        virtual wxString GetTable() const;

        /**
        Shows a dialog message with exception details.
        */
        static void ProcessException(DatabaseLayerException& e);

        void CollectRow(wxActiveRecordRow* row);
        void CollectRowSet(wxActiveRecordRowSet* set);

};


class wxActiveRecordRow{
protected:
        DatabaseLayer* m_database;
        wxString m_table;
        bool newRow;
        ArrayOfRows garbageRows;
        ArrayOfRowSets garbageRowSets;
public:
        wxActiveRecordRow();
        wxActiveRecordRow(wxActiveRecord* activeRecord);
        wxActiveRecordRow(DatabaseLayer* database,const wxString& table);
        virtual ~wxActiveRecordRow();
        virtual bool Create(wxActiveRecord* activeRecord);
        virtual bool Create(DatabaseLayer* database,const wxString& table);
        virtual bool Save();
        virtual bool Delete();
        void CollectRow(wxActiveRecordRow* row);
        void CollectRowSet(wxActiveRecordRowSet* set);
public:
        long id;
};


typedef int (*CMPFUNC_proto)(wxActiveRecordRow**,wxActiveRecordRow**);
WX_DEFINE_ARRAY_SHORT(bool , AscArr);


class wxActiveRecordRowSet : public ArrayOfRows{
protected:
        DatabaseLayer* m_database;
        wxString m_table;

		static std::vector<CMPFUNC_proto> cmpArr;

        static AscArr ascArr;
        static wxString lastSort;
        static int CMPFUNC_default(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
        static int CMPFUNC_global(wxActiveRecordRow** item1,wxActiveRecordRow** item2);
        virtual CMPFUNC_proto GetCmpFunc(const wxString& var) const;

public:
        wxActiveRecordRowSet();
        wxActiveRecordRowSet(wxActiveRecord* activeRecord);
        wxActiveRecordRowSet(DatabaseLayer* database,const wxString& table);
        virtual ~wxActiveRecordRowSet();
        virtual bool Create(wxActiveRecord* activeRecord);
        virtual bool Create(DatabaseLayer* database,const wxString& table);
        virtual bool SaveAll();
        virtual void SortBy(const wxString& sortBy);
        virtual void ReSort();
};

#ifdef AR_USE_SQLITE
#include <SqliteDatabaseLayer.h>
class wxSqliteActiveRecord : public wxActiveRecord{
protected:
        wxSqliteActiveRecord();
        wxSqliteActiveRecord(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
        wxSqliteActiveRecord(DatabaseLayer* database,const wxString& table);
        virtual bool Create(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
};
#endif //AR_USE_SQLITE
//end WX_SQLITE_ACTIVE_RECORD

//begin WX_POSTGRESQL_ACTIVE_RECORD
#ifdef AR_USE_POSTGRESQL

#include <PostgresDatabaseLayer.h>

class wxPostgresActiveRecord : public wxActiveRecord{
protected:
        wxPostgresActiveRecord();
        wxPostgresActiveRecord(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
        wxPostgresActiveRecord(DatabaseLayer* database,const wxString& table);
        virtual bool Create(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
};

#endif //AR_USE_POSTGRESQL
//end WX_POSTGRESQL_ACTIVE_RECORD

//begin WX_MYSQL_ACTIVE_RECORD
#ifdef AR_USE_MYSQL

#include <MysqlDatabaseLayer.h>

class wxMysqlActiveRecord : public wxActiveRecord{
protected:
        wxMysqlActiveRecord();
        wxMysqlActiveRecord(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
        wxMysqlActiveRecord(DatabaseLayer* database,const wxString& table);
        virtual bool Create(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
};


#endif //AR_USE_MYSQL

//end WX_MYSQL_ACTIVE_RECORD

//begin WX_FIREBIRD_ACTIVE_RECORD
#ifdef AR_USE_FIREBIRD

#include <FirebirdDatabaseLayer.h>

class wxFirebirdActiveRecord : public wxActiveRecord{
protected:
        wxFirebirdActiveRecord();
        wxFirebirdActiveRecord(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
        wxFirebirdActiveRecord(DatabaseLayer* database,const wxString& table);
        virtual bool Create(const wxString& table,const wxString& name,const wxString& server=wxT("localhost"),const wxString& user=wxEmptyString,const wxString& password=wxEmptyString);
};


#endif //AR_USE_FIREBIRD

//end WX_FIREBIRD_ACTIVE_RECORD

#endif /* _WX_ACTIVE_RECORD_H_ */
