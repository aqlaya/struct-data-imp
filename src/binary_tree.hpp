#include <iostream>
#include <memory>


template <typename T>
concept compare_el = requires(T a, T b) { a < b; a == b; };

template <typename T>
class BinaryTree {
    public:  
        BinaryTree(std::initializer_list<T>);

        void add(T value) {
            std::shared_ptr<node> new_node = std::make_shared({nullptr, nullptr, nullptr, })
        }

    private:
        struct node  {
            std::weak_ptr<node> parent;
            std::shared_ptr<node> left;
            std::shared_ptr<node> right;
            T  value;
        };
    private:
        node* root;

};
