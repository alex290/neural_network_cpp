#ifndef NEURODATA_H
#define NEURODATA_H

#include <vector>
// CppFlow headers
#include <cppflow/ops.h>
#include <cppflow/model.h>

// C++ headers
#include <iostream>

using namespace std;

class NeuroData
{
public:
    NeuroData();
    ~NeuroData();

    vector<double> SetData(vector<int> input);

private:
    cppflow::model *model_;
};

#endif