//
// Created by kirill_kazarin on 24.02.2022.
//


#ifndef LAB1_BENCHMARK_PRIORITY_QUEUE_H
#define LAB1_BENCHMARK_PRIORITY_QUEUE_H

#include <random>
#include "benchmark/benchmark.h"
#include "hash_map.h"

class benchmark_hash_map_Fixture: public benchmark::Fixture{

public:

    void SetUp(const ::benchmark::State &state) override {

        for (int64_t i = 0; i < state.range(0); ++i) {
            pr_hash_map.insert({randomDevice(), randomDevice()});
        }
    }

    void TearDown(const ::benchmark::State &state) override{
        this->pr_hash_map.clear();
    }


protected:
    h_work::hash_map<size_t,size_t> pr_hash_map;
    std::random_device randomDevice;
};

#endif //LAB1_BENCHMARK_PRIORITY_QUEUE_H
