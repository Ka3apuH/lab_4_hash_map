


#ifndef LAB4_HASH_MAP_H
#define LAB4_HASH_MAP_H

#include <functional>
#include <cmath>

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
        typedef hash_node<std::pair<const _key,_maped_type>>* type_node_link;
        typedef std::pair<const _key,_maped_type> reference;

    protected:
        class hash_equal_to;
    public:

        typedef hash_map_iterator<type_node,hash_equal_to> iterator;

        /**
         * коструктор
         * */
        hash_map() :mass(num_lists){}

        iterator insert(reference element){

            num_element++;

            rehash();

            auto hash=hash_func{}(element.first);
            if(mass.at(std::modulus<>()(hash ,num_lists)).empty()||
            std::find(mass.begin(), mass.end(),key_equal_to(element.first)())) {
                mass.at(std::modulus<>()(hash ,num_lists)).push_back(hash_node<reference>(element, hash));
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

            auto hash=hash_func{}(key);

            if(mass.at(std::modulus<>()(hash,num_lists))== nullptr ||
                    mass.at(std::modulus<>()(hash,num_lists)).empty())return false;

            mass.at(std::modulus<>()(hash,num_lists)).clear();
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

    private:

         void rehash(){

             if(get_now_load_factor()<load_factor_max) {
                 num_lists = 2 * num_lists + 1;
             }

             if(get_now_load_factor()>load_factor_min && num_lists>lim_MAX_num_list){
                 num_lists=(num_lists-1)/2;
             }

                 auto mass_next =std::vector<std::list<type_node>>(num_lists);
                 for (auto i = mass.begin();i < mass.end(); ++i) {
                     if(!i->empty()) {
                         mass_next.at(std::modulus<>()((i->begin()->_hash) , num_lists)) = std::list<type_node>(*i);
                     }
                 }

             mass.swap(mass_next);
             mass_next.clear();
             std::destroy(mass_next.begin(), mass_next.end());
        }

    protected:
        class key_equal_to: std::unary_function<type_node ,bool>{

        private:
            _pred equal;
            _key key;
        public:

            ~key_equal_to()=default;

            explicit key_equal_to(_key input_key): equal(), key(input_key){};

            bool operator()( type_node _x)
            { return equal(key,_x._inf.first); }
        };

        class hash_equal_to: std::unary_function<type_node ,bool>{

        private:
            size_t hash_for_eq;
        public:
            ~hash_equal_to()=default;

            explicit hash_equal_to(size_t input_hash): hash_for_eq(input_hash){};

            bool operator()( type_node& _x)
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
