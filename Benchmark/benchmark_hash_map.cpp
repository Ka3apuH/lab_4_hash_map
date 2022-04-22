//
// Created by kirill_kazarin on 23.02.2022.
//

#include <random>

#include "benchmark/benchmark.h"
#include "benchmark_hash_map.h"


BENCHMARK_DEFINE_F(benchmark_hash_map_Fixture,hash_map_insert_elements) (benchmark::State& state) {
    for (auto _ : state) {
        pr_hash_map.insert({randomDevice(), randomDevice()});
        benchmark::DoNotOptimize(pr_hash_map.insert({randomDevice(), randomDevice()}));
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_DEFINE_F(benchmark_hash_map_Fixture,hash_map_del_element) (benchmark::State& state) {
    for (auto _ : state) {
        pr_hash_map.del_elem(3490354);
    }
    state.SetComplexityN(state.range(0));
}

BENCHMARK_REGISTER_F(benchmark_hash_map_Fixture, hash_map_insert_elements)
->RangeMultiplier(2)
->Range(8, 8<<8)
->Complexity(benchmark::oAuto);

BENCHMARK_REGISTER_F(benchmark_hash_map_Fixture, hash_map_del_element)
        ->RangeMultiplier(2)
        ->Range(8, 8<<8)
        ->Complexity(benchmark::oAuto);

// Run the benchmark
BENCHMARK_MAIN();



