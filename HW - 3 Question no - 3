#include <iostream>


template <typename T>
struct RemoveReferences {
    using type = T;
};

template <typename T>
struct RemoveReferences<T&> {
    using type = T;
};


template <typename T>
struct RemoveModifiers {
private:
    template <typename U>
    struct RemovePointerImpl {
        using type = U;
    };

    template <typename U>
    struct RemovePointerImpl<U*> {
        using type = typename RemovePointerImpl<U>::type;
    };

    template <typename U>
    struct RemoveReferenceImpl {
        using type = U;
    };

    template <typename U>
    struct RemoveReferenceImpl<U&> {
        using type = typename RemoveReferenceImpl<U>::type;
    };

    template <typename U>
    struct RemoveConstImpl {
        using type = U;
    };

    template <typename U>
    struct RemoveConstImpl<const U> {
        using type = typename RemoveConstImpl<U>::type;
    };

public:
    using type = typename RemoveConstImpl<typename RemovePointerImpl<typename RemoveReferenceImpl<T>::type>::type>::type;
};

int main() {
    
    using Type1 = RemoveReferences<int&>::type;
    using Type2 = RemoveModifiers<const int*>::type;

    std::cout << "Type1 is " << typeid(Type1).name() << std::endl; // Output: Type1 is i
    std::cout << "Type2 is " << typeid(Type2).name() << std::endl; // Output: Type2 is i

    return 0;
}
