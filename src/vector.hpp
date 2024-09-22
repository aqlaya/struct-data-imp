template <typename T>
class vector
{
private:
    T *_arr;
    size_t _cap;
    size_t _sz;

public:
    class iterator
    {
        T *_begin;
        T *_end;
        size_t _ind;

    public:
        using value_type = T;
        using pointer = T *;
        using reference = T &;
        using difference_type = size_t;
        using iterator_category = std::contiguous_iterator_tag;

        iterator();

        reference operator*(iterator it);
        difference_type operator-(iterator it);
        iterator operator-(size_t i);
        iterator operator+(size_t i);
        iterator operator++(size_t);
        bool operator==(iterator it);
        bool operator!=(iterator it);

        iterator next();
        iterator prev();
    };
    
    vector(): _cap(0), _sz(0), _arr(nullptr){}
    vector(size_t s): _cap(s), _sz(s)
    {
        void* ptr = malloc(s);
        _arr = std::reinterpret_cast<T*>(ptr);
    }
    vector(size_t s, T v): _cap(s), _sz(s)
    {
        void* ptr = malloc(s);
        _arr = std::reinterpret_cast<T*>(ptr);
        size_t index = 0;
        try{
            for(; index < s; ++index, ++_arr){
                new(_arr) T(v);
            }
        }catch{
            for(size_t i; i < index; ++i){
                _arr->T::~T();
            }
            delete[] ptr;
            throw;
        }
    }
    vector(std::initializer_list<T>);
    void reserve(size_t new_cap);
    void clear();
    void push_back();
    T &operator[](size_t ind);
    ~vector();
};
