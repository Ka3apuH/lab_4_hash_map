//
// Created by kirill_kazarin on 21.04.22.
//

#ifndef LAB4_HASH_NODE_H
#define LAB4_HASH_NODE_H

namespace h_work {
        template<typename _main_node_inf>
        struct hash_node{
        public:
            hash_node(_main_node_inf inf, const size_t hash) : _inf(inf), _hash(hash) {}

            _main_node_inf _inf;
            const size_t _hash;
        };
}

#endif //LAB4_HASH_NODE_H
