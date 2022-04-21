#include <iostream>

#include "hash_map.h"
#include "gtest/gtest.h"

#include <random>

#include "test_hash_map.h"

using namespace h_work;
using namespace std;

TEST_F(Testing_main_func_priority_queue,add_element){
    test_heap.insert(std::pair<unsigned int,std::string>(12,"gfbrgbgb"));
    test_heap.insert(std::pair<unsigned int,std::string>(13452,"gfbryyhtygb"));
    test_heap.insert(std::pair<unsigned int,std::string>(1235,"gfbrgbgtynmtymb"));
    test_heap.insert(std::pair<unsigned int,std::string>(16452,"gfbrgbgyntymtytntynb"));
    test_heap.insert(std::pair<unsigned int,std::string>(12,"gfbrgbgb"));
    test_heap.insert(std::pair<unsigned int,std::string>(13452,"gfbryyhtygb"));
    test_heap.insert(std::pair<unsigned int,std::string>(1235,"gfbrgbgtynmtymb"));
    test_heap.insert(std::pair<unsigned int,std::string>(16452,"gfbrgbgyntymtytntynb"));
    test_heap.insert(std::pair<unsigned int,std::string>(12,"gfbrgbgb"));
    test_heap.insert(std::pair<unsigned int,std::string>(13452,"gfbryyhtygb"));
    test_heap.insert(std::pair<unsigned int,std::string>(1235,"gfbrgbgtynmtymb"));
    test_heap.insert(std::pair<unsigned int,std::string>(16452,"gfbrgbgyntymtytntynb"));
    test_heap.insert(std::pair<unsigned int,std::string>(12,"gfbrgbgb"));
    test_heap.insert(std::pair<unsigned int,std::string>(13452,"gfbryyhtygb"));
    test_heap.insert(std::pair<unsigned int,std::string>(1235,"gfbrgbgtynmtymb"));
    test_heap.insert(std::pair<unsigned int,std::string>(16452,"gfbrgbgyntymtytntynb"));

    h_work::hash_map<int,int> aa{{1,2},{23,23}};

    real_map.insert({{0,"efebb"},{1,"rbgrtbrtbrt"}});
    real_map.insert({{2,"fdvrbretbetb"}});
}


TEST_F(Testing_main_func_priority_queue,add_2_element){


}


