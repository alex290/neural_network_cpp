#ifndef MAINFRAME_H
#define MAINFRAME_H

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "dataglobal.h"
#include "savecsv.h"
#include "neurodata.h"

class MainFrame : public wxFrame
{
public:
    MainFrame();
    ~MainFrame();

private:
    void Gui();

    wxCheckBox *inp11;
    wxCheckBox *inp12;
    wxCheckBox *inp13;
    wxCheckBox *inp14;
    wxCheckBox *inp21;
    wxCheckBox *inp22;
    wxCheckBox *inp23;
    wxCheckBox *inp24;
    wxCheckBox *inp31;
    wxCheckBox *inp32;
    wxCheckBox *inp33;
    wxCheckBox *inp34;
    wxCheckBox *inp41;
    wxCheckBox *inp42;
    wxCheckBox *inp43;
    wxCheckBox *inp44;
    wxCheckBox *outHoriz;
    wxCheckBox *outVert;
    wxButton *btnSave;
    wxButton *btnCheck;
    wxButton *SaveFile;

    void AddLess(wxCommandEvent &event);
    void SaveFileOut(wxCommandEvent &event);
    void CheckDat(wxCommandEvent &event);

    DataGlobal *dataGlobal;
    SaveCsv *saveCsv;
    NeuroData *neuroData;
};

#endif