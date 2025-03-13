// File header documentation is required!!!

// This file must contain definitions of ALL static data, static member,
// class template member and non-member functions of sllist<T>.
// Of course, don't go including any prohibited files!!!

// Add the following definition of non-member, non-friend function template declared in sllist.hpp:

template <typename T>
std::ostream& operator<<(std::ostream& os, sllist<T> const& list) {
  // start at the first node ...
  typename sllist<T>::size_type ls_sz = list.size();

  // uses overloaded subscript operator for class sllist ...
  for (typename sllist<T>::size_type i = 0; i < ls_sz; ++i) {
    os << list[i] << std::setw(4);
  }
  os << "\n"; // extra newline for readability
  return os;
}
