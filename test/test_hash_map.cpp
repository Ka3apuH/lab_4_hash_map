#include <iostream>

#include "hash_map.h"
#include "gtest/gtest.h"

#include <random>

#include "test_hash_map.h"
#include "hash_map_iterator.h"

using namespace h_work;
using namespace std;

TEST_F(Testing_main_func_priority_queue,add_element){
    //auto iter=test_map.insert(std::pair<unsigned int,std::string>(12, "gfbrgbgb"));
    test_map.insert(std::pair<unsigned int,std::string>(1, "gfbryyhtygb"));
    test_map.insert(std::pair<unsigned int,std::string>(2, "gfbrgbgtynmtymb"));
    test_map.insert(std::pair<unsigned int,std::string>(3, "gfbrgbgyntymtytntynb"));
    test_map.insert(std::pair<unsigned int,std::string>(4, "gfbrgbgb"));
    test_map.insert(std::pair<unsigned int,std::string>(5, "gfbryyhtygb"));
    test_map.insert(std::pair<unsigned int,std::string>(435, "gfbrgbgtynmtymb"));
    test_map.insert(std::pair<unsigned int,std::string>(163422452, "gfbrgbgyntymtytntynb"));
    test_map.insert(std::pair<unsigned int,std::string>(12234, "gfbrgbgb"));
    test_map.insert(std::pair<unsigned int,std::string>(13423552, "gfbryyhtygb"));
    test_map.insert(std::pair<unsigned int,std::string>(1235235, "gfbrgbgtynmtymb"));
    test_map.insert(std::pair<unsigned int,std::string>(16452352, "gfbrgbgyntymtytntynb"));
    test_map.insert(std::pair<unsigned int,std::string>(12325, "gfbrgbgb"));
    test_map.insert(std::pair<unsigned int,std::string>(134523452, "gfbryyhtygb"));
    test_map.insert(std::pair<unsigned int,std::string>(1235235, "gfbrgbgtynmtymb"));
    test_map.insert(std::pair<unsigned int,std::string>(164523552, "gfbrgbgyntymtytntynb"));

    test_map.del_elem(163422452);

    h_work::hash_map<int,int> aa{{1,2},{23,23}};

    real_map.insert({{0,"efebb"},{1,"rbgrtbrtbrt"}});
    real_map.insert({{2,"fdvrbretbetb"}});
}


TEST_F(Testing_main_func_priority_queue,add_2_element){


}


