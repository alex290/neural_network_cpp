#include "mainframe.h"

MainFrame::MainFrame() : wxFrame(NULL, wxID_ANY, "Neuro")
{

    dataGlobal = new DataGlobal;
    saveCsv = new SaveCsv(dataGlobal);
    neuroData = new NeuroData;
    Gui();

    btnSave->Bind(wxEVT_BUTTON, &MainFrame::AddLess, this);
    SaveFile->Bind(wxEVT_BUTTON, &MainFrame::SaveFileOut, this);
    btnCheck->Bind(wxEVT_BUTTON, &MainFrame::CheckDat, this);
}

MainFrame::~MainFrame()
{
    delete saveCsv;
    delete dataGlobal;
    delete neuroData;
}
void MainFrame::Gui()
{
    wxBoxSizer *bSizer1;
    bSizer1 = new wxBoxSizer(wxVERTICAL);

    wxStaticText *label;
    label = new wxStaticText(this, wxID_ANY, wxT("Входящие данные"), wxDefaultPosition, wxDefaultSize, 0);
    label->Wrap(-1);
    bSizer1->Add(label, 0, wxALL, 5);

    wxBoxSizer *vSize;
    vSize = new wxBoxSizer(wxHORIZONTAL);

    wxGridSizer *gSizer2;
    gSizer2 = new wxGridSizer(4, 4, 0, 0);

    inp11 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp11, 0, wxALL, 5);

    inp12 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp12, 0, wxALL, 5);

    inp13 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp13, 0, wxALL, 5);

    inp14 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp14, 0, wxALL, 5);

    inp21 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp21, 0, wxALL, 5);

    inp22 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp22, 0, wxALL, 5);

    inp23 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp23, 0, wxALL, 5);

    inp24 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp24, 0, wxALL, 5);

    inp31 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp31, 0, wxALL, 5);

    inp32 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp32, 0, wxALL, 5);

    inp33 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp33, 0, wxALL, 5);

    inp34 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp34, 0, wxALL, 5);

    inp41 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp41, 0, wxALL, 5);

    inp42 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp42, 0, wxALL, 5);

    inp43 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp43, 0, wxALL, 5);

    inp44 = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    gSizer2->Add(inp44, 0, wxALL, 5);

    vSize->Add(gSizer2, 1, wxEXPAND, 5);

    vSize->Add(0, 0, 1, wxEXPAND, 5);

    bSizer1->Add(vSize, 0, wxEXPAND, 5);

    bSizer1->Add(0, 20, 0, wxEXPAND, 5);

    wxStaticText *label1;
    label1 = new wxStaticText(this, wxID_ANY, wxT("Выходящие данные"), wxDefaultPosition, wxDefaultSize, 0);
    label1->Wrap(-1);
    bSizer1->Add(label1, 0, wxALL, 5);

    wxBoxSizer *bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    outHoriz = new wxCheckBox(this, wxID_ANY, wxT("Горизонтальный"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(outHoriz, 0, wxALL, 5);

    outVert = new wxCheckBox(this, wxID_ANY, wxT("Вертикальный"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(outVert, 0, wxALL, 5);

    bSizer1->Add(bSizer3, 0, wxEXPAND, 5);

    bSizer1->Add(0, 20, 0, wxEXPAND, 5);

    wxBoxSizer *bSizer5;
    bSizer5 = new wxBoxSizer(wxHORIZONTAL);

    btnSave = new wxButton(this, wxID_ANY, wxT("Добавить в обучение"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer5->Add(btnSave, 0, wxALL, 5);

    btnCheck = new wxButton(this, wxID_ANY, wxT("Проверка"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer5->Add(btnCheck, 0, wxALL, 5);

    bSizer1->Add(bSizer5, 0, wxEXPAND, 5);

    bSizer1->Add(0, 0, 1, wxEXPAND, 5);

    SaveFile = new wxButton(this, wxID_ANY, wxT("Сохранить файл"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer1->Add(SaveFile, 0, wxALL, 5);

    bSizer1->Add(0, 0, 1, wxEXPAND, 5);

    this->SetSizer(bSizer1);
    this->Layout();

    this->Centre(wxBOTH);
}

void MainFrame::AddLess(wxCommandEvent &event)
{
    std::vector<int> inputData;
    std::vector<int> outputData;

    int m11 = inp11->GetValue();
    int m12 = inp12->GetValue();
    int m13 = inp13->GetValue();
    int m14 = inp14->GetValue();
    int m21 = inp21->GetValue();
    int m22 = inp22->GetValue();
    int m23 = inp23->GetValue();
    int m24 = inp34->GetValue();
    int m31 = inp31->GetValue();
    int m32 = inp32->GetValue();
    int m33 = inp33->GetValue();
    int m34 = inp34->GetValue();
    int m41 = inp41->GetValue();
    int m42 = inp42->GetValue();
    int m43 = inp43->GetValue();
    int m44 = inp44->GetValue();

    inputData.push_back(m11);
    inputData.push_back(m12);
    inputData.push_back(m13);
    inputData.push_back(m14);
    inputData.push_back(m21);
    inputData.push_back(m22);
    inputData.push_back(m23);
    inputData.push_back(m24);
    inputData.push_back(m31);
    inputData.push_back(m32);
    inputData.push_back(m33);
    inputData.push_back(m34);
    inputData.push_back(m41);
    inputData.push_back(m42);
    inputData.push_back(m43);
    inputData.push_back(m44);

    int outH = outHoriz->GetValue();
    int outV = outVert->GetValue();

    outputData.push_back(outH);
    outputData.push_back(outV);

    dataGlobal->inputData.push_back(inputData);
    dataGlobal->outputData.push_back(outputData);

    inp11->SetValue(false);
    inp12->SetValue(false);
    inp13->SetValue(false);
    inp14->SetValue(false);
    inp21->SetValue(false);
    inp22->SetValue(false);
    inp23->SetValue(false);
    inp24->SetValue(false);
    inp31->SetValue(false);
    inp32->SetValue(false);
    inp33->SetValue(false);
    inp34->SetValue(false);
    inp41->SetValue(false);
    inp42->SetValue(false);
    inp43->SetValue(false);
    inp44->SetValue(false);

    outHoriz->SetValue(false);
    outVert->SetValue(false);
}

void MainFrame::SaveFileOut(wxCommandEvent &event)
{
    
    saveCsv->SaveScv();
}

void MainFrame::CheckDat(wxCommandEvent &event) {
    std::vector<int> inputData;

    int m11 = inp11->GetValue();
    int m12 = inp12->GetValue();
    int m13 = inp13->GetValue();
    int m14 = inp14->GetValue();
    int m21 = inp21->GetValue();
    int m22 = inp22->GetValue();
    int m23 = inp23->GetValue();
    int m24 = inp34->GetValue();
    int m31 = inp31->GetValue();
    int m32 = inp32->GetValue();
    int m33 = inp33->GetValue();
    int m34 = inp34->GetValue();
    int m41 = inp41->GetValue();
    int m42 = inp42->GetValue();
    int m43 = inp43->GetValue();
    int m44 = inp44->GetValue();

    inputData.push_back(m11);
    inputData.push_back(m12);
    inputData.push_back(m13);
    inputData.push_back(m14);
    inputData.push_back(m21);
    inputData.push_back(m22);
    inputData.push_back(m23);
    inputData.push_back(m24);
    inputData.push_back(m31);
    inputData.push_back(m32);
    inputData.push_back(m33);
    inputData.push_back(m34);
    inputData.push_back(m41);
    inputData.push_back(m42);
    inputData.push_back(m43);
    inputData.push_back(m44);


    neuroData->SetData(inputData);
}
