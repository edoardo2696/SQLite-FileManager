#include "gtest/gtest.h"
#include "../Win32Project/databaselayer/include/wx/wx.h"
#include "../Win32Project/databaselayer/include/wx/chartype.h"
#include "../Win32Project/databaselayer/include/wx/string.h"
#include "../Win32Project/databaselayer/include/SqliteDatabaseLayer.h"
#include "../Win32Project/databaselayer/include/DatabaseLayerException.h"


TEST(GroupTest, InsertGroup) {

    try {
        DatabaseLayer *Database = new SqliteDatabaseLayer();
        wxString db_filename(wxT("SQLiteFileManager.db"));
        Database->Open(db_filename);
        PreparedStatement *pStatement(nullptr);
        PreparedStatement * InsertGroupStatement = Database->PrepareStatement(
                wxT("INSERT INTO groups (id, code, name, description, image) VALUES (?,?,?,?,?)"));
        InsertGroupStatement->SetParamInt(1, 1000);
        InsertGroupStatement->SetParamString(2, "groupsCode");
        InsertGroupStatement->SetParamString(3, "groupsName");
        InsertGroupStatement->SetParamString(4, "groupsDescription");
        InsertGroupStatement->SetParamString(5, "groupsImage");
        InsertGroupStatement->RunQuery();
        Database->CloseStatement(InsertGroupStatement);

        PreparedStatement *GroupStatement = Database->PrepareStatement(
                wxString::Format(wxT("SELECT * FROM groups WHERE id = 1000")));
        DatabaseResultSet *result = GroupStatement->ExecuteQuery();
        if (result->Next()) {
            ASSERT_EQ("groupsCode", result->GetResultString("code"));
            ASSERT_EQ("groupsName", result->GetResultString("name"));
            ASSERT_EQ("groupsDescription", result->GetResultString("description"));
            ASSERT_EQ("groupsImage", result->GetResultString("image"));
        }
        Database->CloseStatement(GroupStatement);

    }   catch(DatabaseLayerException & e) {printf(e.GetErrorMessage());}

}


TEST(ElementTest, InsertElement) {

    try {
        DatabaseLayer *Database = new SqliteDatabaseLayer();
        wxString db_filename(wxT("SQLiteFileManager.db"));
        Database->Open(db_filename);
        PreparedStatement *pStatement(nullptr);
        PreparedStatement *InsertElementStatement = Database->PrepareStatement(wxString::Format("INSERT INTO elements (id, name, description, groupid, image) VALUES (?,?,?,?,?)"));
        InsertElementStatement->SetParamInt(1, 1000);
        InsertElementStatement->SetParamString(2, "elementsName");
        InsertElementStatement->SetParamString(3, "elementsDescription");
        InsertElementStatement->SetParamInt(4, 1000);
        InsertElementStatement->SetParamString(5, "elementsImage");
        InsertElementStatement->RunQuery();
        Database->CloseStatement(InsertElementStatement);

        PreparedStatement *ElementStatement = Database->PrepareStatement(wxString::Format(wxT("SELECT * FROM elements WHERE id = 1000")));
        DatabaseResultSet *result = ElementStatement->ExecuteQuery();
        if (result->Next()) {
            ASSERT_EQ("elementsName", result->GetResultString("name"));
            ASSERT_EQ("elementsDescription", result->GetResultString("description"));
            ASSERT_EQ(1000, result->GetResultInt("groupid"));
            ASSERT_EQ("elementsImage", result->GetResultString("image"));
        }
        Database->CloseStatement(ElementStatement);
    }   catch(DatabaseLayerException & e) {printf(e.GetErrorMessage());}
}

TEST(GcodeTest, InsertGcode) {

    try {
        DatabaseLayer *Database = new SqliteDatabaseLayer();
        wxString db_filename(wxT("SQLiteFileManager.db"));
        Database->Open(db_filename);
        PreparedStatement *pStatement(nullptr);
        PreparedStatement *InsertGcodeStatement = Database->PrepareStatement(
                wxString::Format("INSERT INTO gcodes (id, elementid, code) VALUES (?,?,?)"));
        InsertGcodeStatement->SetParamInt(1, 1000);
        InsertGcodeStatement->SetParamInt(2, 1000);
        InsertGcodeStatement->SetParamString(3, "gcodesCode");
        InsertGcodeStatement->RunQuery();
        Database->CloseStatement(InsertGcodeStatement);

        PreparedStatement *GcodeStatement = Database->PrepareStatement(
                wxString::Format(wxT("SELECT * FROM gcodes WHERE id = 1000")));
        DatabaseResultSet *result = GcodeStatement->ExecuteQuery();
        if (result->Next()) {
            ASSERT_EQ(1000, result->GetResultInt("elementid"));
            ASSERT_EQ("gcodesCode", result->GetResultString("code"));
        }
        Database->CloseStatement(GcodeStatement);
    }   catch(DatabaseLayerException & e) {printf(e.GetErrorMessage());}
}

TEST(GcodeTest, DeleteGCode) {
    try {
        DatabaseLayer *Database = new SqliteDatabaseLayer();
        wxString db_filename(wxT("SQLiteFileManager.db"));
        Database->Open(db_filename);
        PreparedStatement *pStatement(nullptr);
        PreparedStatement *DeleteGcodeStatement = Database->PrepareStatement(
                wxString::Format("DELETE FROM gcodes WHERE id=1000"));
        DeleteGcodeStatement->RunQuery();
        Database->CloseStatement(DeleteGcodeStatement);

        PreparedStatement *gcodeStatement = Database->PrepareStatement(
                wxString::Format(wxT("SELECT * FROM gcodes WHERE id = 1000")));
        DatabaseResultSet *result = gcodeStatement->ExecuteQuery();
        ASSERT_EQ(result->Next(), false);

        Database->CloseStatement(gcodeStatement);
    }   catch(DatabaseLayerException & e) {printf(e.GetErrorMessage());}
}

TEST(ElementTest, DeleteElement) {
    try {
        DatabaseLayer *Database = new SqliteDatabaseLayer();
        wxString db_filename(wxT("SQLiteFileManager.db"));
        Database->Open(db_filename);
        PreparedStatement *pStatement(nullptr);
        PreparedStatement *DeleteElementStatement = Database->PrepareStatement(
                wxString::Format("DELETE FROM elements WHERE id=1000"));
        DeleteElementStatement->RunQuery();
        Database->CloseStatement(DeleteElementStatement);

        PreparedStatement *elementStatement = Database->PrepareStatement(
                wxString::Format(wxT("SELECT * FROM elements WHERE id = 1000")));
        DatabaseResultSet *result = elementStatement->ExecuteQuery();
        ASSERT_EQ(result->Next(), false);

        Database->CloseStatement(elementStatement);
    }   catch(DatabaseLayerException & e) {printf(e.GetErrorMessage());}
}

TEST(GroupTest, DeleteGroup) {
    try {
        DatabaseLayer *Database = new SqliteDatabaseLayer();
        wxString db_filename(wxT("SQLiteFileManager.db"));
        Database->Open(db_filename);
        PreparedStatement *pStatement(nullptr);
        PreparedStatement *DeleteGroupStatement = Database->PrepareStatement(
                wxString::Format("DELETE FROM groups WHERE id=1000"));
        DeleteGroupStatement->RunQuery();
        Database->CloseStatement(DeleteGroupStatement);

        PreparedStatement *groupStatement = Database->PrepareStatement(
                wxString::Format(wxT("SELECT * FROM groups WHERE id = 1000")));
        DatabaseResultSet *result = groupStatement->ExecuteQuery();
        ASSERT_EQ(result->Next(), false);

        Database->CloseStatement(groupStatement);
    }   catch(DatabaseLayerException & e) {printf(e.GetErrorMessage());}
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
