#include "neurodata.h"

NeuroData::NeuroData()
{
    model_ = new cppflow::model("neuro");
}

NeuroData::~NeuroData()
{
    delete model_;
}
vector<double> NeuroData::SetData(vector<int> input)
{
    vector<double> dat;
    // Run
    vector<float> inpData;
    for (size_t i = 0; i < 16; i++)
    {
        inpData.push_back(input[i]);
    }

    auto inp = cppflow::tensor(inpData, {1, 16});
    auto output = model_->operator()(inp);

    vector<float> outputData = output.get_data<float>();

    for (auto v : outputData)
    {
        std::cout << v << "; ";
        // if (v > 0.8)
        // {
        //     std::cout << 1 << "; ";
        // }
        // else
        // {
        //     std::cout << 0 << "; ";
        // }
    }

    return dat;
}
