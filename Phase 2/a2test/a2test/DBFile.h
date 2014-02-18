#ifndef DBFILE_H
#define DBFILE_H

#include "TwoWayList.h"
#include "Record.h"
#include "Schema.h"
#include "File.h"
#include "Comparison.h"
#include "ComparisonEngine.h"

typedef enum {heap, sorted, tree} fType;

// stub DBFile header..replace it with your own DBFile.h 

class DBFile {
	
	Record* current;
	Page* readPage;
	Page* writePage;
	File* file;
	char *fpath;
	off_t pageIndex;
	off_t writeIndex;
	char* name;
	int writeIsDirty;
	int endOfFile;
	
public:
	DBFile (); 
	~DBFile();

	int Create (char *fpath, fType file_type, void *startup);
	int Open (off_t length,char *fpath);
        int Open (char *fpath);
	int Close ();

	void Load (Schema &myschema, char *loadpath);

	void MoveFirst();
//	void MoveFirst(int);
//	int page_Index();
	void Add (Record &addme);
	int GetNext (Record &fetchme);
	int GetNext (Record &fetchme, CNF &cnf, Record &literal);
        off_t GetLength();

};
#endif
