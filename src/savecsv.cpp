#include "savecsv.h"

SaveCsv::SaveCsv(DataGlobal *data) : dataGlobal(data)
{
}

SaveCsv::~SaveCsv()
{
}
void SaveCsv::SaveScv()
{
    cout << "SaveFileOut" << endl;
    string inpCsv = "";
    for (size_t i = 0; i < 16; i++)
    {
        if (i > 0)
            inpCsv = inpCsv + ",";

        inpCsv = inpCsv + "inp/" + to_string(i);
    }
    inpCsv = inpCsv + "\n";

    if (!dataGlobal->inputData.empty())
    {
        for (std::vector<int> inputData : dataGlobal->inputData)
        {
            if (inputData.size() == 16)
            {
                for (size_t x = 0; x < 16; x++)
                {
                    if (x > 0)
                        inpCsv = inpCsv + ",";

                    inpCsv = inpCsv + to_string(inputData[x]);
                }
                inpCsv = inpCsv + "\n";
            }
        }
    }

    cout << inpCsv << endl;

    string outCsv = "";
    for (size_t z = 0; z < 2; z++)
    {
        if (z > 0)
            outCsv = outCsv + ",";

        outCsv = outCsv + "out/" + to_string(z);
    }
    outCsv = outCsv + "\n";

    if (!dataGlobal->outputData.empty())
    {
        for (std::vector<int> outputData : dataGlobal->outputData)
        {
            if (outputData.size() == 2)
            {
                for (size_t y = 0; y < 2; y++)
                {
                    if (y > 0)
                        outCsv = outCsv + ",";

                    outCsv = outCsv + to_string(outputData[y]);
                }
                outCsv = outCsv + "\n";
            }
        }
    }

    cout << outCsv << endl;

    wxFile file;
    file.Create("input.csv", true);

    wxString data(inpCsv);

    if (file.IsOpened())
    {
        file.Write(data);
        file.Close();
    }

    wxFile fileOut;
    fileOut.Create("out.csv", true);

    wxString dataO(outCsv);

    if (fileOut.IsOpened())
    {
        fileOut.Write(dataO);
        fileOut.Close();
    }
}
