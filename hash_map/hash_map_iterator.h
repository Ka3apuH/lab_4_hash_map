//
// Created by kirill_kazarin on 14.04.2022.
//

#ifndef LAB4_HASH_MAP_ITERATOR_H
#define LAB4_HASH_MAP_ITERATOR_H

#include <vector>
#include <list>
#include <algorithm>
namespace h_work {

    template<typename _key,typename _maped_type,typename _pred>
    struct hash_map_iterator {

        typedef std::pair<const _key,_maped_type>  _type_inf;
        typedef hash_node<_type_inf>  type_node;
        typedef typename std::vector<std::list<type_node>>& lvalue_vector;
        typedef typename std::list<hash_node<_type_inf>> list_of_nodes;

        hash_map_iterator(size_t hash, lvalue_vector vector) : _hash(hash), _vector(vector){}

        hash_map_iterator operator++(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            auto list_curent_elem=std::find_if(now_pos->begin(),now_pos->end(),_pred(_hash));

            if(list_curent_elem.operator++()!=now_pos->end()){
                this->_hash=list_curent_elem.operator*()._hash;
            } else{
                while (now_pos!=_vector.end() && now_pos->empty()) {
                  now_pos.operator++();
                }

                if(now_pos==_vector.end())return nullptr;

                this->_hash = now_pos.operator*().begin().operator*()._hash;
            }
            return this;
        }

        hash_map_iterator operator--(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            auto list_curent_elem= std::find(now_pos->begin(), now_pos->end(), _pred(_hash)());

            if(list_curent_elem != now_pos->begin()){
                this->_hash=list_curent_elem.operator--().operator*()._hash;
            } else{
                while (now_pos!=_vector.begin() && now_pos->empty()) {
                    now_pos.operator--();
                }
                if (now_pos!=_vector.begin()){
                    this->_hash = now_pos.operator*().begin().operator*()._hash;
                }
            }
            return this;
        }

        hash_map_iterator operator*(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            typename list_of_nodes::iterator next_elem=std::find(now_pos->begin(),now_pos->end(),_pred(_hash)());
            return next_elem.operator*()._inf.second;
        }

        hash_map_iterator operator->(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            typename list_of_nodes::iterator next_elem=std::find(now_pos->begin(),now_pos->end(),_pred(_hash)());
            return &next_elem.operator->()->_inf.second;
        }

    private:
        size_t _hash;
        lvalue_vector _vector;
    };
}


#endif //LAB4_HASH_MAP_ITERATOR_H
