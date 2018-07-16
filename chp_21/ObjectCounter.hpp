template <typename T>
class ObjectCounter
{
private:
    static std::size_t count;

protected:
    ObjectCounter() { ++count; }

    ObjectCounter(const ObjectCounter<T>&) { ++count; }

    ObjectCounter(ObjectCounter<T>&&) { ++count; }

    ~ObjectCounter() { --count; }

public:
    static std::size_t live() { return count; }
};

// static member
template <typename T>
std::size_t ObjectCounter<T>::count = 0;