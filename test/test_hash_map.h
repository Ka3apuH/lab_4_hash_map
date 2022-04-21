//
// Created by kirill_kazarin on 23.02.2022.
//

#ifndef LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H
#define LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H

#include <gtest/gtest.h>
#include "hash_map.h"
#include <unordered_map>
#include <random>


class Testing_main_func_priority_queue : public ::testing::Test {
protected:
    void SetUp() override {
    }
    void TearDown() override {
        real_map.clear();
        test_heap.clear();
    }

// объекты тестового окружения, доступные в каждом тесте
    std::unordered_map<unsigned int,std::string> real_map;
    h_work::hash_map<unsigned int,std::string> test_heap;
    std::random_device randomDevice;
};

#endif //LAB1_TESTING_MAIN_FUNC_PRIORITY_QUEUE_H
