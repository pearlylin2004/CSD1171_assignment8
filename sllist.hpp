/*!************************************************************************
\file sllist.hpp
\author Pearly Lin Lee Ying
\par DP email: p.lin@digipen.edu
\par Course: CSD1171
\par Assignment #08
\date 03-18-2025
\brief header file for sllist.tpp, where declaration is made
**************************************************************************/
#include <cstddef>
#include "str.hpp"

namespace hlp2{
template <typename T>
class sllist{
public:
    // Type alias
    using size_type = std::size_t; 
    using value_type = T; 
    using reference = value_type&;
    using const_reference = const value_type&; 
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using iterator = pointer;
    using const_iterator = const_pointer; 

public:
    sllist();
    sllist(const_iterator lhs, const_iterator rhs); 
    sllist(std::initializer_list<value_type> rhs); 
    sllist(sllist const& node); 

    ~sllist(); 

    sllist& operator=(sllist const& rhs); 
    sllist& operator=(std::initializer_list<value_type> rhs);

    sllist& operator+=(sllist const& nodes); 
    sllist& operator+=(std::initializer_list<value_type> rhs);

    reference operator[](size_type index); 
    const_reference operator[](size_type index) const; 

    reference front();
    const_reference front() const; 

    void push_front(value_type const& value); 
    void push_back(value_type const& value); 

    void pop_front();

    bool empty() const; 
    size_type size() const; 

    void clear(); 
    void swap(sllist& rhs); 

    // Returns value in node_counter 
    static size_type node_count(); 

    static size_type object_count();

private:
    struct Node{
        value_type data;
        Node* next{nullptr};
        Node(value_type const&);

        ~Node();

        static size_type node_counter; 
    };
    Node *head{nullptr};
    Node *tail{nullptr};
    size_type counter{0}; 
    static size_type obj_counter; 

}; 

template <typename T>
void swap(sllist<T>& lhs, sllist<T>& rhs); 

template <typename T>
sllist<T> operator+(sllist<T> const& lhs, sllist<T> const& rhs);

template <typename T>
sllist<T> operator+(sllist<T> const& lhs, std::initializer_list<T> rhs);

template <typename T>
sllist<T> operator+(std::initializer_list<T> lhs, sllist<T> const& rhs);

template <typename T>
sllist<T> operator+(std::initializer_list<T> lhs, std::initializer_list<T> rhs);

// add this non-member, non-friend function template declaration:
template <typename T>
std::ostream& operator<<(std::ostream& os, sllist<T> const& list);
}

#include "sllist.tpp"
