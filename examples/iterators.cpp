//
// Created by Ivan Shynkarenka on 03.08.2015
//

#include "benchmark/cppbenchmark.h"

#include <list>
#include <vector>

const uint64_t operations = 1000;

template <typename T>
class ContainerFixture
{
protected:
    T container;

    ContainerFixture()
    {
        for (int i = 0; i < 1000000; ++i)
            container.push_back(rand());
    }
};

BENCHMARK_FIXTURE(ContainerFixture<std::list<int>>, "std::list<int>-forward", operations)
{
    for (auto it = container.begin(); it != container.end(); ++it)
        ++(*it);
}

BENCHMARK_FIXTURE(ContainerFixture<std::list<int>>, "std::list<int>-backward", operations)
{
    for (auto it = container.rbegin(); it != container.rend(); ++it)
        ++(*it);
}

BENCHMARK_FIXTURE(ContainerFixture<std::vector<int>>, "std::vector<int>-forward", operations)
{
    for (auto it = container.begin(); it != container.end(); ++it)
        ++(*it);
}

BENCHMARK_FIXTURE(ContainerFixture<std::vector<int>>, "std::vector<int>-backward", operations)
{
    for (auto it = container.rbegin(); it != container.rend(); ++it)
        ++(*it);
}

BENCHMARK_MAIN()
