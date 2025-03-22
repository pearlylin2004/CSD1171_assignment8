/*!************************************************************************
\file sllist.tpp
\author Pearly Lin Lee Ying
\par DP email: p.lin@digipen.edu
\par Course: CSD1171
\par Assignment #08
\date 03-18-2025
\brief header file for sllist.tpp, where declaration is made
**************************************************************************/
#include <cstddef> 
#include <iomanip> 


namespace hlp2{
  template<typename T>
  typename sllist<T>::size_type sllist<T>::Node::node_counter = 0; 

  template<typename T>
  typename sllist<T>::size_type sllist<T>::obj_counter = 0; 


  // Node constructor 
  template<typename T>
  sllist<T>::Node::Node(sllist<T>::value_type const& value) : data(value){
    node_counter++; 
  }

  // Node destructor 
  template<typename T>
  sllist<T>::Node::~Node() {
    node_counter--; 
  }

  // Default constructor 
  template<typename T>
  sllist<T>::sllist() : head{nullptr}, tail{nullptr}, counter(0){
    obj_counter++; 
  }

  // Constructor with iterator 
  template<typename T>
  sllist<T>::sllist(sllist<T>::const_iterator lhs, sllist<T>::const_iterator rhs){
    obj_counter++;
    for(const_iterator start = lhs; start != rhs; start++){
      hlp2::sllist<T>::Node* node = new Node(*start);
      if(tail != nullptr){
        tail->next = node; 
      } else{
        head = node; 
      }
      tail = node;
      counter++; 
    } 
  }

  // Constructor with initializer list 
  template<typename T>
  sllist<T>::sllist(std::initializer_list<value_type> rhs) : head{nullptr}, tail{nullptr}, counter(0){
    obj_counter++;
    for(const value_type& num : rhs){
      hlp2::sllist<T>::Node* node = new Node(num);
      if(tail != nullptr){
        tail->next = node; 
      } else{
        head = node; 
      }
      tail = node;
      counter++; 
    }
  }

  template<typename T>
  sllist<T>::sllist(sllist<T> const& node) : head{nullptr}, tail{nullptr}{
    obj_counter++;
    for(size_t num = 0; num < node.size(); num++){
      hlp2::sllist<T>::Node* node_new = new Node(node[num]);
      if(tail != nullptr){
        tail->next = node_new; 
      } else{
        head = node_new; 
      }
      tail = node_new;
      counter++; 
    }
  }

  // Destructor 
  template<typename T>
  sllist<T>::~sllist(){
    clear();
    obj_counter--; 
  }

  template<typename T>
  sllist<T>& sllist<T>::operator=(sllist const& rhs){
    if(this != &rhs){
      sllist temp(rhs);
      swap(temp); 
    }
    return *this; 
  }

  template<typename T>
  sllist<T>& sllist<T>::operator=(std::initializer_list<value_type> rhs){
    sllist temp(rhs);
    swap(temp);
    return *this; 
  }

  template<typename T>
  sllist<T>& sllist<T>::operator+=(sllist const& nodes){
    sllist temp(*this);
    for(size_t num = 0; num < nodes.size(); num++){
      temp.push_back(nodes[num]);
    }
    swap(temp); 

    return *this; 
  }

  template<typename T>
  sllist<T>& sllist<T>::operator+=(std::initializer_list<value_type> rhs){
    sllist temp(*this);
    for(const value_type& value : rhs){
      temp.push_back(value); 
    }
    
    swap(temp); 

    return *this; 
  }

  template<typename T>
  typename sllist<T>::reference sllist<T>::operator[](size_type index){
    hlp2::sllist<T>::Node* current_node = head; 
    for(size_type num = 0; num < index; num++){
      current_node = current_node->next; 
    }
    return current_node->data; 
  }

  template<typename T>
  typename sllist<T>::const_reference sllist<T>::operator[](size_type index) const{
    hlp2::sllist<T>::Node* current_node = head; 
    for(size_type num = 0; num < index; num++){
      current_node = current_node->next; 
    }
    return current_node->data; 
  }

  template<typename T>
  typename sllist<T>::reference sllist<T>::front(){
    return head->data; 
  }

  template<typename T>
  typename sllist<T>::const_reference sllist<T>::front() const{
    return head->data; 
  }

  template<typename T>
  void sllist<T>::push_front(sllist<T>::value_type const& value){
    hlp2::sllist<T>::Node* node = new Node(value);
    node->next = head;
    head = node;
    if(tail == nullptr){
      tail = node; 
    }
    counter++; 
  }

  template<typename T>
  void sllist<T>::push_back(sllist<T>::value_type const& value){
    hlp2::sllist<T>::Node* node = new Node(value);
    if(tail != nullptr){
      tail->next = node; 
    } else{
      head = node; 
    }
    tail = node;
    counter++; 
  }
  
  template<typename T>
  void sllist<T>::pop_front(){
    hlp2::sllist<T>::Node* prev_head = head;
    head = head->next;
    if(head == nullptr){
      tail = nullptr; 
    } 
    delete prev_head;
    counter--;
  }

  template<typename T>
  bool sllist<T>::empty() const{
    return head == nullptr; 
  }

  template<typename T>
  typename sllist<T>::size_type sllist<T>::size() const{
    return counter; 
  }

  template<typename T>
  void sllist<T>::clear(){
    while(head != nullptr){
      pop_front(); 
    }
    counter = 0; 
  }

  template<typename T>
  void sllist<T>::swap(sllist& rhs){
    std::swap(head, rhs.head);
    std::swap(tail, rhs.tail);
    std::swap(counter, rhs.counter); 
  }



  template<typename T>
  typename sllist<T>::size_type sllist<T>::node_count(){
    return sllist<T>::Node::node_counter; 
  }

  template<typename T>
  typename sllist<T>::size_type sllist<T>::object_count(){
    return obj_counter; 
  }

  template<typename T>
  void swap(sllist<T>& lhs, sllist<T>& rhs){
    sllist<T> temp{lhs};
    lhs = rhs;
    rhs = temp; 
  }

  template <typename T>
  sllist<T> operator+(sllist<T> const& lhs, sllist<T> const& rhs){
    sllist<T> result{lhs};
    result += rhs;
    return result; 
  }

  template<typename T>
  sllist<T> operator+(sllist<T> const& lhs, std::initializer_list<T> rhs){
    sllist<T> result = lhs;
    result += rhs; 
    return result; 
  }

  template<typename T>
  sllist<T> operator+(std::initializer_list<T> lhs, sllist<T> const& rhs){
    sllist<T> result = lhs;
    result += rhs;
    return result; 
  }

  template <typename T>
  sllist<T> operator+(std::initializer_list<T> lhs, std::initializer_list<T> rhs){
    sllist<T> result = lhs;
    lhs += rhs;
    return result; 
  }

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
}
