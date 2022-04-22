


#ifndef LAB4_HASH_MAP_H
#define LAB4_HASH_MAP_H

#include <functional>
#include <cmath>
#include <algorithm>

#define start_num_list 16
#define lim_MAX_num_list 1024

#include "hash_node.h"
#include "hash_map_iterator.h"

namespace h_work{

    template<typename _key, typename _maped_type,
            typename _hash = std::hash<_key>,
            typename _pred = std::equal_to<_key>>
    class hash_map{
    public:

        typedef hash_node<std::pair<const _key,_maped_type>> type_node;
        typedef std::pair<const _key,_maped_type> reference;

//    protected:
        class hash_equal_to;
//    public:

        typedef hash_map_iterator<_key,_maped_type,hash_equal_to> iterator;

        /**
         * коструктор
         * */
        hash_map() :mass(num_lists){}

        iterator begin(){
            auto now_pos=mass.begin();
            while (now_pos!=mass.end() && now_pos->empty()) {
                now_pos.operator++();
            }
            if(now_pos==mass.end())return iterator(0, (std::vector<std::list<type_node>> &) (std::vector<std::list<type_node>> &) nullptr);

            return iterator(now_pos->begin()->_hash,mass);
        }

        iterator end(){
            return iterator(0, (std::vector<std::list<type_node>> &)nullptr);
        }

        iterator insert(reference element){

            rehash();

            size_t hash=hash_func{}(element.first);
            std::list<type_node>& curent_list=mass.at(std::modulus<>()(hash ,num_lists));

            if(curent_list.empty() || std::find_if(curent_list.begin(), curent_list.end(),hash_equal_to(hash))==curent_list.end()) {
                curent_list.push_back(hash_node<reference>(element, hash));
                num_element++;
            }

           return iterator(hash,mass);
        }

        hash_map(std::initializer_list<reference> args):mass(num_lists){
            for(auto i=args.begin();i< args.end();i++){
                this->insert(*i);
            }
        }

        _maped_type& operator[](_key key){
        auto hash=hash_func{}(key);
            return mass.at(std::modulus<>()(hash,num_lists)).begin()->inf;
        }

        bool del_elem(_key key){

            size_t hash=hash_func{}(key);

            std::list<type_node>& curent_list=mass.at(std::modulus<>()(hash ,num_lists));

            if(curent_list.empty()){
                return false;
            }

            auto curent_elem_iter=std::find_if(curent_list.begin(), curent_list.end(),hash_equal_to(hash));

            if(curent_elem_iter==curent_list.end()) {
                return false;
            }

            curent_list.erase(curent_elem_iter);

            num_element--;
            rehash();

            return true;
        }

        void clear(){
            num_element=0;
            num_lists=start_num_list;
            mass.clear();
            mass.resize(num_lists);
        }

 //   private:

         void rehash(){

             if(get_now_load_factor()<load_factor_max) {
                 num_lists = 2 * num_lists + 1;
             } else if(get_now_load_factor()>load_factor_min && num_lists>lim_MAX_num_list){
                 num_lists=(num_lists-1)/2;
             } else{
                 return;
             }

                 auto mass_next =std::vector<std::list<type_node>>(num_lists);
                 for (auto i = mass.begin();i != mass.end(); ++i) {
                     if(!i->empty()) {
                         for (auto k=i->begin();k!=i->end(); ++k) {
                             mass_next.at(std::modulus<>()((k->_hash) , num_lists)).push_back(*k);
                         }
                     }
                 }

             mass.swap(mass_next);
             mass_next.clear();
             std::destroy(mass_next.begin(), mass_next.end());
        }

 //   protected:
/*        class key_equal_to: std::unary_function<type_node ,bool>{

        private:
            _pred equal;
            _key key;
        public:

            ~key_equal_to()=default;

            explicit key_equal_to(_key input_key): equal(), key(input_key){};

            bool operator()( type_node _x)
            { return equal(key,_x._inf.first); }
        };*/

        class hash_equal_to: std::unary_function<type_node ,bool>{

        private:
            size_t hash_for_eq;
        public:
            ~hash_equal_to()=default;

            explicit hash_equal_to(size_t input_hash): hash_for_eq(input_hash){};

            bool operator()(type_node _x)
            { return std::equal_to<>()(hash_for_eq,_x._hash); }
        };

        class hash_func: std::unary_function<_key ,size_t>{

        private:
            _hash hash;
        public:
            ~hash_func()=default;

            hash_func(): hash(){};

            size_t operator()( _key _x)
            { return hash(_x); }
        };

    public:
        [[nodiscard]] size_t get_num_element() const {
            return num_element;
        }

        [[nodiscard]] float get_load_factor() const {
            return load_factor_max;
        }

        void set_load_factor(float loadFactor) {
            load_factor_max = loadFactor;
        }

        [[nodiscard]] float get_now_load_factor(){
            return static_cast<float>(num_lists)/static_cast<float>(num_element);
        }

    private:
        size_t num_element=0;
        size_t num_lists=start_num_list;
        float load_factor_max=2.0;
        float load_factor_min=8;


        std::vector<std::list<type_node>> mass;
    };
}
#endif //LAB4_HASH_MAP_H
