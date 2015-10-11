#pragma once
// Copyright (c) 2015 Tony Kirke. License MIT  (http://www.opensource.org/licenses/mit-license.php)
// from directory: spuc_templates
#include <spuc/spuc_types.h>
#include <stdexcept>
#include <string>
#include <unordered_map>
namespace SPUC {
//! Class that implements a hash map with string key
template <typename T> class hash_map {
 public:
  //! Clear all contents of the table
  void clear();
  //! Get number of elements in the table
  uint32_t getSize();
  //! Add key and value to the table (return operation success / fail)
  bool add(std::string key, T value);
  //! Change value for key (assuming already in table)
  bool set(std::string key, T value);
  //! Check if table already contains key
  bool contains(std::string key);
  //! Remove key and corresponding value from table (return operation success / fail)
  bool remove(std::string key);
  //! Get value corresponding to key (if it exists)
  T getValue(std::string key);

  typedef std::unordered_map<std::string, T> HashTableType;
  HashTableType table;                                                // Actual hash table
  typename std::unordered_map<std::string, T>::const_iterator _iter;  // Iterator
};

// Clear all contents of the table
template <typename T> void hash_map<T>::clear() { table.clear(); }

// Get number of elements in the table
template <typename T> uint32_t hash_map<T>::getSize() { return (uint32_t)table.size(); }

// Add key and value to the table
template <typename T> bool hash_map<T>::add(std::string key, T value) {
  // Check if key already exists in table
  if (contains(key))
    return false;
  else {
    table[key] = value;
    return true;
  }
}
template <typename T> bool hash_map<T>::set(std::string key, T value) {
  // Check if key already exists in table
  if (contains(key)) {
    table[key] = value;
    return true;
  } else {
    return false;
  }
}

// Check if table already contains key
template <typename T> bool hash_map<T>::contains(std::string key) {
  if (table.count(key) == 0)
    return false;
  else
    return true;
}

// Remove key and corresponding value from table (return operation success / fail)
template <typename T> bool hash_map<T>::remove(std::string key) {
  // Check if key already exists in table
  if (contains(key)) {
    table.erase(key);
    return true;
  } else {  // Was not in table
    return false;
  }
}

// Get value corresponding to key (if it exists)
template <typename T> T hash_map<T>::getValue(std::string key) {
  if (contains(key)) {
    return table[key];
  } else {
    T x(0);
    return x;
  }
}

}  // namespace SPUC
