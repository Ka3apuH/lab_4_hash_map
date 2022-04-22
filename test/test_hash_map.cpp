#include <iostream>

#include "hash_map.h"
#include "gtest/gtest.h"

#include <random>

#include "test_hash_map.h"
#include "hash_map_iterator.h"

using namespace h_work;
using namespace std;

TEST_F(Testing_main_func_priority_queue,add_element){
    for (int i = 0; i < 1000; ++i) {
        auto x=randomDevice();
        test_map.insert({x,"ojijij"});
        real_map.insert({x,"ojijij"});
    }
}


TEST_F(Testing_main_func_priority_queue,add_2_element){
}


