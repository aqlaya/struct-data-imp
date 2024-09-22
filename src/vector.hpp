template <typename T>
class vector
{
private:

public:
    vector();
    vector(size_t);
    vector(size_t, T);
    vector(std::initializer_list<T>);
    ~vector();
};
