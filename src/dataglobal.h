#ifndef DATAGLOBAL_H
#define DATAGLOBAL_H

#include <vector>
#include <iostream>
#include <string>

using namespace std;

class DataGlobal
{
public:
    DataGlobal();
    ~DataGlobal();

    std::vector<std::vector<int>> inputData;
    std::vector<std::vector<int>> outputData;

private:
};

#endif