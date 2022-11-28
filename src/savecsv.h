#ifndef SAVECSV_H
#define SAVECSV_H

#include "dataglobal.h"
#include <wx/file.h>

class SaveCsv
{
public:
    SaveCsv(DataGlobal *data);
    ~SaveCsv();

    void SaveScv();

private:
    DataGlobal *dataGlobal;
};

#endif