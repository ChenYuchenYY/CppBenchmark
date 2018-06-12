//
// Created by Ivan Shynkarenka on 24.07.2015
//

#include "benchmark/cppbenchmark.h"

#include <atomic>

const uint64_t operations = 100000000;

template <typename T>
class AtomicFixture
{
protected:
    std::atomic<T> x;
    T y;
    T z;
};

BENCHMARK_FIXTURE(AtomicFixture<int32_t>, "std::atomic<int32_t>.CAS()", operations)
{
    x.compare_exchange_strong(y, z, std::memory_order_acq_rel);
}

BENCHMARK_FIXTURE(AtomicFixture<int64_t>, "std::atomic<int64_t>.CAS()", operations)
{
    x.compare_exchange_strong(y, z, std::memory_order_acq_rel);
}

BENCHMARK_FIXTURE(AtomicFixture<int32_t>, "std::atomic<int32_t>.FAA()", operations)
{
    x.fetch_add(y, std::memory_order_acq_rel);
}

BENCHMARK_FIXTURE(AtomicFixture<int64_t>, "std::atomic<int64_t>.FAA()", operations)
{
    x.fetch_add(y, std::memory_order_acq_rel);
}

BENCHMARK_MAIN()
