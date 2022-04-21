//
// Created by kirill_kazarin on 14.04.2022.
//

#ifndef LAB4_HASH_MAP_ITERATOR_H
#define LAB4_HASH_MAP_ITERATOR_H

#include <vector>
#include <list>
namespace h_work {

    template<typename _type_inf,typename _pred>
    struct hash_map_iterator {

        typedef typename std::vector<std::list<hash_node<_type_inf>>>& lvalue_vector;
        typedef typename std::list<hash_node<_type_inf>> list_of_nodes;

        hash_map_iterator(size_t hash, lvalue_vector &vector) : _hash(hash), _vector(vector){}

        hash_map_iterator operator++(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            if(typename list_of_nodes::iterator next_elem=std::find(now_pos->begin(),now_pos->end(),_pred(_hash)()).operator++()!=now_pos->end()){
                this->_hash=next_elem.operator*()._hash;
            } else{
                while (now_pos!=_vector.end() && now_pos->empty()) {
                  now_pos.operator++();
                }
                this->_hash = now_pos.operator*().begin().operator*()._hash;
            }
            return this;
        }


        hash_map_iterator operator--(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            if(typename list_of_nodes::iterator next_elem=std::find(now_pos->begin(),now_pos->end(),_pred(_hash)())!=now_pos->begin()){
                this->_hash=next_elem.operator--().operator*()._hash;
            } else{
                while (now_pos!=_vector.begin() && now_pos->empty()) {
                    now_pos.operator--();
                }
                this->_hash = now_pos.operator*().begin().operator*()._hash;
            }
            return this;
        }


        hash_map_iterator operator*(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            typename list_of_nodes::iterator next_elem=std::find(now_pos->begin(),now_pos->end(),_pred(_hash)());
            return next_elem.operator*();
        }

        hash_map_iterator operator->(){
            auto now_pos=_vector.begin().operator+(std::modulus<>()(_hash,_vector.size()));

            typename list_of_nodes::iterator next_elem=std::find(now_pos->begin(),now_pos->end(),_pred(_hash)());
            return next_elem.operator->();
        }

    private:
        size_t _hash;
        lvalue_vector _vector;
    };
}


#endif //LAB4_HASH_MAP_ITERATOR_H
