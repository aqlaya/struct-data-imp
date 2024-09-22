#pragma once


#include <iostream>
#include <memory>
#include <type_traits>
#include <algorithm>

namespace __detail {
    template <typename T>
    concept Compare = requires(T a, T b) { a < b; a == b; };

    template <typename U>
    struct check_value_type {
        using value = typename U::value_type;
    };

    template <typename U>
    using check_value_type_v = check_value_type<U>::value;
}

template <__detail::Compare T>
requires std::is_copy_constructible_v<T>
class BinaryTree { 
    private:
        struct node  {
            std::weak_ptr<node> parent;
            std::shared_ptr<node> left;
            std::shared_ptr<node> right;
            T  value;
        };

        std::shared_ptr<node> root;

        template <typename U>
        requires std::is_same_v<__detail::check_value_type_v<U>, T>
        void inorder_tree_walk(U& container, std::shared_ptr<node> ptr) {
            while (ptr != nullptr) { 
                inorder_tree_walk(container, ptr->left);
                container.push_back(ptr->value);
                inorder_tree_walk(container, ptr->right);
            }
        }

    public:  
        BinaryTree(): root(nullptr) {}

        void add(const T& value) {

            std::shared_ptr<node> cur_ptr = root, prev_ptr = nullptr;

            while (cur_ptr != nullptr) {
                prev_ptr = cur_ptr;
                if (cur_ptr->value <= value) {
                    cur_ptr = cur_ptr->right;
                }
                else {
                    cur_ptr = cur_ptr->left;
                }
            }

            /* here need copy_construcible_v<T> or is_integral_v<T> */
            std::shared_ptr<node> new_node 
                = std::make_shared<node>(prev_ptr, nullptr, nullptr, value);

            /* empty tree */
            if (prev_ptr == nullptr) {
                root = new_node;
            }
            /* don't empty tree */ 
            else if (prev_ptr->value <= value) {
                prev_ptr->right = new_node;
            }
            else 
                prev_ptr->left = new_node;
        }


        BinaryTree(std::initializer_list<T> items)
            : BinaryTree()
        {
            std::for_each(items.begin(), items.end(), [this](const T& value) {
                add(value);
            });    
        }


        template <typename U> 
        requires std::is_same_v<__detail::check_value_type_v<U>, T>
        auto sort(U& container) {
            inorder_tree_walk(container, root);
            return container;
        }
};
