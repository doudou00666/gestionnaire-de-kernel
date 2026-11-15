#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/settings.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include "src/cpp/qt_widget.h"
#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <iterator>
#include <new>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#if __cplusplus >= 202002L
#include <ranges>
#endif

#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#ifdef __clang__
#pragma clang diagnostic ignored "-Wdollar-in-identifier-extension"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
#endif // __clang__
#endif // __GNUC__

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_PANIC
#define CXXBRIDGE1_PANIC
template <typename Exception>
void panic [[noreturn]] (const char *msg);
#endif // CXXBRIDGE1_PANIC

struct unsafe_bitcopy_t;

namespace {
template <typename T>
class impl;
} // namespace

class Opaque;

template <typename T>
::std::size_t size_of();
template <typename T>
::std::size_t align_of();

#ifndef CXXBRIDGE1_RUST_STRING
#define CXXBRIDGE1_RUST_STRING
class String final {
public:
  String() noexcept;
  String(const String &) noexcept;
  String(String &&) noexcept;
  ~String() noexcept;

  String(const std::string &);
  String(const char *);
  String(const char *, std::size_t);
  String(const char16_t *);
  String(const char16_t *, std::size_t);
#ifdef __cpp_char8_t
  String(const char8_t *s);
  String(const char8_t *s, std::size_t len);
#endif

  static String lossy(const std::string &) noexcept;
  static String lossy(const char *) noexcept;
  static String lossy(const char *, std::size_t) noexcept;
  static String lossy(const char16_t *) noexcept;
  static String lossy(const char16_t *, std::size_t) noexcept;

  String &operator=(const String &) & noexcept;
  String &operator=(String &&) & noexcept;

  explicit operator std::string() const;

  const char *data() const noexcept;
  char *data() noexcept;

  std::size_t size() const noexcept;
  std::size_t length() const noexcept;
  bool empty() const noexcept;

  const char *c_str() noexcept;

  std::size_t capacity() const noexcept;
  void reserve(size_t new_cap) noexcept;

  using iterator = char *;
  iterator begin() noexcept;
  iterator end() noexcept;

  using const_iterator = const char *;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool operator==(const String &) const noexcept;
  bool operator!=(const String &) const noexcept;
  bool operator<(const String &) const noexcept;
  bool operator<=(const String &) const noexcept;
  bool operator>(const String &) const noexcept;
  bool operator>=(const String &) const noexcept;

  void swap(String &) noexcept;

  String(unsafe_bitcopy_t, const String &) noexcept;

private:
  struct lossy_t;
  String(lossy_t, const char *, std::size_t) noexcept;
  String(lossy_t, const char16_t *, std::size_t) noexcept;
  friend void swap(String &lhs, String &rhs) noexcept { lhs.swap(rhs); }

  std::array<std::uintptr_t, 3> repr;
};
#endif // CXXBRIDGE1_RUST_STRING

#ifndef CXXBRIDGE1_RUST_SLICE
#define CXXBRIDGE1_RUST_SLICE
namespace detail {
template <bool>
struct copy_assignable_if {};

template <>
struct copy_assignable_if<false> {
  copy_assignable_if() noexcept = default;
  copy_assignable_if(const copy_assignable_if &) noexcept = default;
  copy_assignable_if &operator=(const copy_assignable_if &) & noexcept = delete;
  copy_assignable_if &operator=(copy_assignable_if &&) & noexcept = default;
};
} // namespace detail

template <typename T>
class Slice final
    : private detail::copy_assignable_if<std::is_const<T>::value> {
public:
  using value_type = T;

  Slice() noexcept;
  Slice(T *, std::size_t count) noexcept;

  template <typename C>
  explicit Slice(C &c) : Slice(c.data(), c.size()) {}

  Slice &operator=(const Slice<T> &) & noexcept = default;
  Slice &operator=(Slice<T> &&) & noexcept = default;

  T *data() const noexcept;
  std::size_t size() const noexcept;
  std::size_t length() const noexcept;
  bool empty() const noexcept;

  T &operator[](std::size_t n) const noexcept;
  T &at(std::size_t n) const;
  T &front() const noexcept;
  T &back() const noexcept;

  Slice(const Slice<T> &) noexcept = default;
  ~Slice() noexcept = default;

  class iterator;
  iterator begin() const noexcept;
  iterator end() const noexcept;

  void swap(Slice &) noexcept;

private:
  class uninit;
  Slice(uninit) noexcept;
  friend impl<Slice>;
  friend void sliceInit(void *, const void *, std::size_t) noexcept;
  friend void *slicePtr(const void *) noexcept;
  friend std::size_t sliceLen(const void *) noexcept;

  std::array<std::uintptr_t, 2> repr;
};

#ifdef __cpp_deduction_guides
template <typename C>
explicit Slice(C &c)
    -> Slice<std::remove_reference_t<decltype(*std::declval<C>().data())>>;
#endif // __cpp_deduction_guides

template <typename T>
class Slice<T>::iterator final {
public:
#if __cplusplus >= 202002L
  using iterator_category = std::contiguous_iterator_tag;
#else
  using iterator_category = std::random_access_iterator_tag;
#endif
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = typename std::add_pointer<T>::type;
  using reference = typename std::add_lvalue_reference<T>::type;

  reference operator*() const noexcept;
  pointer operator->() const noexcept;
  reference operator[](difference_type) const noexcept;

  iterator &operator++() noexcept;
  iterator operator++(int) noexcept;
  iterator &operator--() noexcept;
  iterator operator--(int) noexcept;

  iterator &operator+=(difference_type) noexcept;
  iterator &operator-=(difference_type) noexcept;
  iterator operator+(difference_type) const noexcept;
  friend inline iterator operator+(difference_type lhs, iterator rhs) noexcept {
    return rhs + lhs;
  }
  iterator operator-(difference_type) const noexcept;
  difference_type operator-(const iterator &) const noexcept;

  bool operator==(const iterator &) const noexcept;
  bool operator!=(const iterator &) const noexcept;
  bool operator<(const iterator &) const noexcept;
  bool operator<=(const iterator &) const noexcept;
  bool operator>(const iterator &) const noexcept;
  bool operator>=(const iterator &) const noexcept;

private:
  friend class Slice;
  void *pos;
  std::size_t stride;
};

template <typename T>
Slice<T>::Slice() noexcept {
  sliceInit(this, reinterpret_cast<void *>(align_of<T>()), 0);
}

template <typename T>
Slice<T>::Slice(T *s, std::size_t count) noexcept {
  assert(s != nullptr || count == 0);
  sliceInit(this,
            s == nullptr && count == 0
                ? reinterpret_cast<void *>(align_of<T>())
                : const_cast<typename std::remove_const<T>::type *>(s),
            count);
}

template <typename T>
T *Slice<T>::data() const noexcept {
  return reinterpret_cast<T *>(slicePtr(this));
}

template <typename T>
std::size_t Slice<T>::size() const noexcept {
  return sliceLen(this);
}

template <typename T>
std::size_t Slice<T>::length() const noexcept {
  return this->size();
}

template <typename T>
bool Slice<T>::empty() const noexcept {
  return this->size() == 0;
}

template <typename T>
T &Slice<T>::operator[](std::size_t n) const noexcept {
  assert(n < this->size());
  auto ptr = static_cast<char *>(slicePtr(this)) + size_of<T>() * n;
  return *reinterpret_cast<T *>(ptr);
}

template <typename T>
T &Slice<T>::at(std::size_t n) const {
  if (n >= this->size()) {
    panic<std::out_of_range>("rust::Slice index out of range");
  }
  return (*this)[n];
}

template <typename T>
T &Slice<T>::front() const noexcept {
  assert(!this->empty());
  return (*this)[0];
}

template <typename T>
T &Slice<T>::back() const noexcept {
  assert(!this->empty());
  return (*this)[this->size() - 1];
}

template <typename T>
typename Slice<T>::iterator::reference
Slice<T>::iterator::operator*() const noexcept {
  return *static_cast<T *>(this->pos);
}

template <typename T>
typename Slice<T>::iterator::pointer
Slice<T>::iterator::operator->() const noexcept {
  return static_cast<T *>(this->pos);
}

template <typename T>
typename Slice<T>::iterator::reference Slice<T>::iterator::operator[](
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ptr = static_cast<char *>(this->pos) + this->stride * n;
  return *reinterpret_cast<T *>(ptr);
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator++() noexcept {
  this->pos = static_cast<char *>(this->pos) + this->stride;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator++(int) noexcept {
  auto ret = iterator(*this);
  this->pos = static_cast<char *>(this->pos) + this->stride;
  return ret;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator--() noexcept {
  this->pos = static_cast<char *>(this->pos) - this->stride;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator--(int) noexcept {
  auto ret = iterator(*this);
  this->pos = static_cast<char *>(this->pos) - this->stride;
  return ret;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator+=(
    typename Slice<T>::iterator::difference_type n) noexcept {
  this->pos = static_cast<char *>(this->pos) + this->stride * n;
  return *this;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator-=(
    typename Slice<T>::iterator::difference_type n) noexcept {
  this->pos = static_cast<char *>(this->pos) - this->stride * n;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator+(
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ret = iterator(*this);
  ret.pos = static_cast<char *>(this->pos) + this->stride * n;
  return ret;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator-(
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ret = iterator(*this);
  ret.pos = static_cast<char *>(this->pos) - this->stride * n;
  return ret;
}

template <typename T>
typename Slice<T>::iterator::difference_type
Slice<T>::iterator::operator-(const iterator &other) const noexcept {
  auto diff = std::distance(static_cast<char *>(other.pos),
                            static_cast<char *>(this->pos));
  return diff / static_cast<typename Slice<T>::iterator::difference_type>(
                    this->stride);
}

template <typename T>
bool Slice<T>::iterator::operator==(const iterator &other) const noexcept {
  return this->pos == other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator!=(const iterator &other) const noexcept {
  return this->pos != other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator<(const iterator &other) const noexcept {
  return this->pos < other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator<=(const iterator &other) const noexcept {
  return this->pos <= other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator>(const iterator &other) const noexcept {
  return this->pos > other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator>=(const iterator &other) const noexcept {
  return this->pos >= other.pos;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::begin() const noexcept {
  iterator it;
  it.pos = slicePtr(this);
  it.stride = size_of<T>();
  return it;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::end() const noexcept {
  iterator it = this->begin();
  it.pos = static_cast<char *>(it.pos) + it.stride * this->size();
  return it;
}

template <typename T>
void Slice<T>::swap(Slice &rhs) noexcept {
  std::swap(*this, rhs);
}
#endif // CXXBRIDGE1_RUST_SLICE

#ifndef CXXBRIDGE1_RUST_BITCOPY_T
#define CXXBRIDGE1_RUST_BITCOPY_T
struct unsafe_bitcopy_t final {
  explicit unsafe_bitcopy_t() = default;
};
#endif // CXXBRIDGE1_RUST_BITCOPY_T

#ifndef CXXBRIDGE1_RUST_BITCOPY
#define CXXBRIDGE1_RUST_BITCOPY
constexpr unsafe_bitcopy_t unsafe_bitcopy{};
#endif // CXXBRIDGE1_RUST_BITCOPY

#ifndef CXXBRIDGE1_RUST_VEC
#define CXXBRIDGE1_RUST_VEC
template <typename T>
class Vec final {
public:
  using value_type = T;

  Vec() noexcept;
  Vec(std::initializer_list<T>);
  Vec(const Vec &);
  Vec(Vec &&) noexcept;
  ~Vec() noexcept;

  Vec &operator=(Vec &&) & noexcept;
  Vec &operator=(const Vec &) &;

  std::size_t size() const noexcept;
  bool empty() const noexcept;
  const T *data() const noexcept;
  T *data() noexcept;
  std::size_t capacity() const noexcept;

  const T &operator[](std::size_t n) const noexcept;
  const T &at(std::size_t n) const;
  const T &front() const noexcept;
  const T &back() const noexcept;

  T &operator[](std::size_t n) noexcept;
  T &at(std::size_t n);
  T &front() noexcept;
  T &back() noexcept;

  void reserve(std::size_t new_cap);
  void push_back(const T &value);
  void push_back(T &&value);
  template <typename... Args>
  void emplace_back(Args &&...args);
  void truncate(std::size_t len);
  void clear();

  using iterator = typename Slice<T>::iterator;
  iterator begin() noexcept;
  iterator end() noexcept;

  using const_iterator = typename Slice<const T>::iterator;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  void swap(Vec &) noexcept;

  Vec(unsafe_bitcopy_t, const Vec &) noexcept;

private:
  void reserve_total(std::size_t new_cap) noexcept;
  void set_len(std::size_t len) noexcept;
  void drop() noexcept;

  friend void swap(Vec &lhs, Vec &rhs) noexcept { lhs.swap(rhs); }

  std::array<std::uintptr_t, 3> repr;
};

template <typename T>
Vec<T>::Vec(std::initializer_list<T> init) : Vec{} {
  this->reserve_total(init.size());
  std::move(init.begin(), init.end(), std::back_inserter(*this));
}

template <typename T>
Vec<T>::Vec(const Vec &other) : Vec() {
  this->reserve_total(other.size());
  std::copy(other.begin(), other.end(), std::back_inserter(*this));
}

template <typename T>
Vec<T>::Vec(Vec &&other) noexcept : repr(other.repr) {
  new (&other) Vec();
}

template <typename T>
Vec<T>::~Vec() noexcept {
  this->drop();
}

template <typename T>
Vec<T> &Vec<T>::operator=(Vec &&other) & noexcept {
  this->drop();
  this->repr = other.repr;
  new (&other) Vec();
  return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &other) & {
  if (this != &other) {
    this->drop();
    new (this) Vec(other);
  }
  return *this;
}

template <typename T>
bool Vec<T>::empty() const noexcept {
  return this->size() == 0;
}

template <typename T>
const T &Vec<T>::operator[](std::size_t n) const noexcept {
  assert(n < this->size());
  auto data = reinterpret_cast<const char *>(this->data());
  return *reinterpret_cast<const T *>(data + n * size_of<T>());
}

template <typename T>
const T &Vec<T>::at(std::size_t n) const {
  if (n >= this->size()) {
    panic<std::out_of_range>("rust::Vec index out of range");
  }
  return (*this)[n];
}

template <typename T>
const T &Vec<T>::front() const noexcept {
  assert(!this->empty());
  return (*this)[0];
}

template <typename T>
const T &Vec<T>::back() const noexcept {
  assert(!this->empty());
  return (*this)[this->size() - 1];
}

template <typename T>
T &Vec<T>::operator[](std::size_t n) noexcept {
  assert(n < this->size());
  auto data = reinterpret_cast<char *>(this->data());
  return *reinterpret_cast<T *>(data + n * size_of<T>());
}

template <typename T>
T &Vec<T>::at(std::size_t n) {
  if (n >= this->size()) {
    panic<std::out_of_range>("rust::Vec index out of range");
  }
  return (*this)[n];
}

template <typename T>
T &Vec<T>::front() noexcept {
  assert(!this->empty());
  return (*this)[0];
}

template <typename T>
T &Vec<T>::back() noexcept {
  assert(!this->empty());
  return (*this)[this->size() - 1];
}

template <typename T>
void Vec<T>::reserve(std::size_t new_cap) {
  this->reserve_total(new_cap);
}

template <typename T>
void Vec<T>::push_back(const T &value) {
  this->emplace_back(value);
}

template <typename T>
void Vec<T>::push_back(T &&value) {
  this->emplace_back(std::move(value));
}

template <typename T>
template <typename... Args>
void Vec<T>::emplace_back(Args &&...args) {
  auto size = this->size();
  this->reserve_total(size + 1);
  ::new (reinterpret_cast<T *>(reinterpret_cast<char *>(this->data()) +
                               size * size_of<T>()))
      T(std::forward<Args>(args)...);
  this->set_len(size + 1);
}

template <typename T>
void Vec<T>::clear() {
  this->truncate(0);
}

template <typename T>
typename Vec<T>::iterator Vec<T>::begin() noexcept {
  return Slice<T>(this->data(), this->size()).begin();
}

template <typename T>
typename Vec<T>::iterator Vec<T>::end() noexcept {
  return Slice<T>(this->data(), this->size()).end();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::begin() const noexcept {
  return this->cbegin();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::end() const noexcept {
  return this->cend();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cbegin() const noexcept {
  return Slice<const T>(this->data(), this->size()).begin();
}

template <typename T>
typename Vec<T>::const_iterator Vec<T>::cend() const noexcept {
  return Slice<const T>(this->data(), this->size()).end();
}

template <typename T>
void Vec<T>::swap(Vec &rhs) noexcept {
  using std::swap;
  swap(this->repr, rhs.repr);
}

template <typename T>
Vec<T>::Vec(unsafe_bitcopy_t, const Vec &bits) noexcept : repr(bits.repr) {}
#endif // CXXBRIDGE1_RUST_VEC

#ifndef CXXBRIDGE1_RUST_FN
#define CXXBRIDGE1_RUST_FN
template <typename Signature>
class Fn;

template <typename Ret, typename... Args>
class Fn<Ret(Args...)> final {
public:
  Ret operator()(Args... args) const noexcept;
  Fn operator*() const noexcept;

private:
  Ret (*trampoline)(Args..., void *fn) noexcept;
  void *fn;
};

template <typename Ret, typename... Args>
Ret Fn<Ret(Args...)>::operator()(Args... args) const noexcept {
  return (*this->trampoline)(std::forward<Args>(args)..., this->fn);
}

template <typename Ret, typename... Args>
Fn<Ret(Args...)> Fn<Ret(Args...)>::operator*() const noexcept {
  return *this;
}
#endif // CXXBRIDGE1_RUST_FN

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

#ifndef CXXBRIDGE1_LAYOUT
#define CXXBRIDGE1_LAYOUT
class layout {
  template <typename T>
  friend std::size_t size_of();
  template <typename T>
  friend std::size_t align_of();
  template <typename T>
  static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_size_of() {
    return T::layout::size();
  }
  template <typename T>
  static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_size_of() {
    return sizeof(T);
  }
  template <typename T>
  static
      typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
      size_of() {
    return do_size_of<T>();
  }
  template <typename T>
  static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_align_of() {
    return T::layout::align();
  }
  template <typename T>
  static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_align_of() {
    return alignof(T);
  }
  template <typename T>
  static
      typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
      align_of() {
    return do_align_of<T>();
  }
};

template <typename T>
std::size_t size_of() {
  return layout::size_of<T>();
}

template <typename T>
std::size_t align_of() {
  return layout::align_of<T>();
}
#endif // CXXBRIDGE1_LAYOUT
} // namespace cxxbridge1
} // namespace rust

using QObject = ::QObject;
using QApplication = ::QApplication;
using QWidget = ::QWidget;
using QPushButton = ::QPushButton;
using QLabel = ::QLabel;
using QLineEdit = ::QLineEdit;
using QCheckBox = ::QCheckBox;
using QComboBox = ::QComboBox;
using QTextEdit = ::QTextEdit;
using QSlider = ::QSlider;
using QProgressBar = ::QProgressBar;
using QTimer = ::QTimer;
using QVBoxLayout = ::QVBoxLayout;
using QHBoxLayout = ::QHBoxLayout;
using QGridLayout = ::QGridLayout;
using QLayout = ::QLayout;
using QRadioButton = ::QRadioButton;
using QGroupBox = ::QGroupBox;
using QTabWidget = ::QTabWidget;
using QSpinBox = ::QSpinBox;
using QMenu = ::QMenu;
using QMenuBar = ::QMenuBar;
using QIcon = ::QIcon;
using QPoint = ::QPoint;
using QListWidget = ::QListWidget;
using QAction = ::QAction;
using QMainWindow = ::QMainWindow;
using QToolBar = ::QToolBar;
using QStatusBar = ::QStatusBar;
using QMessageBox = ::QMessageBox;
using QProgressDialog = ::QProgressDialog;
using QTableWidget = ::QTableWidget;
using QTreeWidget = ::QTreeWidget;
using QScrollArea = ::QScrollArea;
using QStackedWidget = ::QStackedWidget;
using QSplitter = ::QSplitter;
using QDateEdit = ::QDateEdit;
using QTimeEdit = ::QTimeEdit;
using QDateTimeEdit = ::QDateTimeEdit;
using QPlainTextEdit = ::QPlainTextEdit;
using QTextBrowser = ::QTextBrowser;
using QFrame = ::QFrame;
using QToolButton = ::QToolButton;
using QCalendarWidget = ::QCalendarWidget;
using QShortcut = ::QShortcut;
using QSystemTrayIcon = ::QSystemTrayIcon;
using QFont = ::QFont;
using QUiLoader = ::QUiLoader;
using QDialog = ::QDialog;
using QFormLayout = ::QFormLayout;
using QDialogButtonBox = ::QDialogButtonBox;
using QDial = ::QDial;
using QDoubleSpinBox = ::QDoubleSpinBox;
using QLCDNumber = ::QLCDNumber;
using QScrollBar = ::QScrollBar;
using QDockWidget = ::QDockWidget;
using QToolBox = ::QToolBox;
using QFontComboBox = ::QFontComboBox;
using QButtonGroup = ::QButtonGroup;
using QKeySequenceEdit = ::QKeySequenceEdit;
using QStringListModel = ::QStringListModel;
using QSortFilterProxyModel = ::QSortFilterProxyModel;
using QCompleter = ::QCompleter;
using QUndoStack = ::QUndoStack;
using QIntValidator = ::QIntValidator;
using QDoubleValidator = ::QDoubleValidator;
using QFileSystemModel = ::QFileSystemModel;
using QHeaderView = ::QHeaderView;
using QWizard = ::QWizard;
using QWizardPage = ::QWizardPage;
using QColumnView = ::QColumnView;
using QAbstractButton = ::QAbstractButton;
using QVariant = ::QVariant;
using QSettings = ::QSettings;
using QSpacerItem = ::QSpacerItem;
using QStandardItemModel = ::QStandardItemModel;
using QTableView = ::QTableView;
using QListView = ::QListView;
using QTreeView = ::QTreeView;
using QItemSelectionModel = ::QItemSelectionModel;

extern "C" {
::QAction *cxxbridge1$205$QAction_new(::std::string const &text, ::QWidget *parent) noexcept {
  ::QAction *(*QAction_new$)(::std::string const &, ::QWidget *) = ::QAction_new;
  return QAction_new$(text, parent);
}

void cxxbridge1$205$QAction_delete(::QAction *action) noexcept {
  void (*QAction_delete$)(::QAction *) = ::QAction_delete;
  QAction_delete$(action);
}

void cxxbridge1$205$QAction_setText(::QAction *action, ::std::string const &text) noexcept {
  void (*QAction_setText$)(::QAction *, ::std::string const &) = ::QAction_setText;
  QAction_setText$(action, text);
}

void cxxbridge1$205$QAction_setIcon(::QAction *action, ::std::string const &icon_path) noexcept {
  void (*QAction_setIcon$)(::QAction *, ::std::string const &) = ::QAction_setIcon;
  QAction_setIcon$(action, icon_path);
}

void cxxbridge1$205$QAction_setCheckable(::QAction *action, bool checkable) noexcept {
  void (*QAction_setCheckable$)(::QAction *, bool) = ::QAction_setCheckable;
  QAction_setCheckable$(action, checkable);
}

void cxxbridge1$205$QAction_setChecked(::QAction *action, bool checked) noexcept {
  void (*QAction_setChecked$)(::QAction *, bool) = ::QAction_setChecked;
  QAction_setChecked$(action, checked);
}

void cxxbridge1$205$QAction_setShortcut(::QAction *action, ::std::string const &key) noexcept {
  void (*QAction_setShortcut$)(::QAction *, ::std::string const &) = ::QAction_setShortcut;
  QAction_setShortcut$(action, key);
}

void cxxbridge1$205$QAction_setEnabled(::QAction *action, bool enabled) noexcept {
  void (*QAction_setEnabled$)(::QAction *, bool) = ::QAction_setEnabled;
  QAction_setEnabled$(action, enabled);
}

void cxxbridge1$205$QAction_setToolTip(::QAction *action, ::std::string const &tip) noexcept {
  void (*QAction_setToolTip$)(::QAction *, ::std::string const &) = ::QAction_setToolTip;
  QAction_setToolTip$(action, tip);
}

void cxxbridge1$205$QAction_text(::QAction *action, ::rust::String *return$) noexcept {
  ::rust::String (*QAction_text$)(::QAction *) = ::QAction_text;
  new (return$) ::rust::String(QAction_text$(action));
}

bool cxxbridge1$205$QAction_isChecked(::QAction *action) noexcept {
  bool (*QAction_isChecked$)(::QAction *) = ::QAction_isChecked;
  return QAction_isChecked$(action);
}

bool cxxbridge1$205$QAction_isEnabled(::QAction *action) noexcept {
  bool (*QAction_isEnabled$)(::QAction *) = ::QAction_isEnabled;
  return QAction_isEnabled$(action);
}

void cxxbridge1$205$QAction_onTriggered(::QAction *action, ::std::uint64_t ctx) noexcept {
  void (*QAction_onTriggered$)(::QAction *, ::std::uint64_t) = ::QAction_onTriggered;
  QAction_onTriggered$(action, ctx);
}

void cxxbridge1$205$QAction_onToggled(::QAction *action, ::std::uint64_t ctx) noexcept {
  void (*QAction_onToggled$)(::QAction *, ::std::uint64_t) = ::QAction_onToggled;
  QAction_onToggled$(action, ctx);
}

::QApplication *cxxbridge1$205$QApplication_new() noexcept {
  ::QApplication *(*QApplication_new$)() = ::QApplication_new;
  return QApplication_new$();
}

::std::int32_t cxxbridge1$205$QApplication_exec(::QApplication *app) noexcept {
  ::std::int32_t (*QApplication_exec$)(::QApplication *) = ::QApplication_exec;
  return QApplication_exec$(app);
}

void cxxbridge1$205$QApplication_setWindowIcon(::QApplication *app, ::std::string const &icon_path) noexcept {
  void (*QApplication_setWindowIcon$)(::QApplication *, ::std::string const &) = ::QApplication_setWindowIcon;
  QApplication_setWindowIcon$(app, icon_path);
}

void cxxbridge1$205$QApplication_setDesktopFileName(::QApplication *app, ::std::string const &name) noexcept {
  void (*QApplication_setDesktopFileName$)(::QApplication *, ::std::string const &) = ::QApplication_setDesktopFileName;
  QApplication_setDesktopFileName$(app, name);
}

::QCheckBox *cxxbridge1$205$QCheckBox_new(::std::string const &text, ::QWidget *parent) noexcept {
  ::QCheckBox *(*QCheckBox_new$)(::std::string const &, ::QWidget *) = ::QCheckBox_new;
  return QCheckBox_new$(text, parent);
}

bool cxxbridge1$205$QCheckBox_isChecked(::QCheckBox *cb) noexcept {
  bool (*QCheckBox_isChecked$)(::QCheckBox *) = ::QCheckBox_isChecked;
  return QCheckBox_isChecked$(cb);
}

void cxxbridge1$205$QCheckBox_setChecked(::QCheckBox *cb, bool checked) noexcept {
  void (*QCheckBox_setChecked$)(::QCheckBox *, bool) = ::QCheckBox_setChecked;
  QCheckBox_setChecked$(cb, checked);
}

void cxxbridge1$205$QCheckBox_setTristate(::QCheckBox *cb, bool tri) noexcept {
  void (*QCheckBox_setTristate$)(::QCheckBox *, bool) = ::QCheckBox_setTristate;
  QCheckBox_setTristate$(cb, tri);
}

bool cxxbridge1$205$QCheckBox_isTristate(::QCheckBox *cb) noexcept {
  bool (*QCheckBox_isTristate$)(::QCheckBox *) = ::QCheckBox_isTristate;
  return QCheckBox_isTristate$(cb);
}

void cxxbridge1$205$QCheckBox_delete(::QCheckBox *cb) noexcept {
  void (*QCheckBox_delete$)(::QCheckBox *) = ::QCheckBox_delete;
  QCheckBox_delete$(cb);
}

void cxxbridge1$205$QCheckBox_onToggled(::QCheckBox *cb, ::std::uint64_t ctx) noexcept {
  void (*QCheckBox_onToggled$)(::QCheckBox *, ::std::uint64_t) = ::QCheckBox_onToggled;
  QCheckBox_onToggled$(cb, ctx);
}

::QComboBox *cxxbridge1$205$QComboBox_new(::QWidget *parent) noexcept {
  ::QComboBox *(*QComboBox_new$)(::QWidget *) = ::QComboBox_new;
  return QComboBox_new$(parent);
}

void cxxbridge1$205$QComboBox_addItem(::QComboBox *cb, ::std::string const &text) noexcept {
  void (*QComboBox_addItem$)(::QComboBox *, ::std::string const &) = ::QComboBox_addItem;
  QComboBox_addItem$(cb, text);
}

void cxxbridge1$205$QComboBox_currentText(::QComboBox *cb, ::rust::String *return$) noexcept {
  ::rust::String (*QComboBox_currentText$)(::QComboBox *) = ::QComboBox_currentText;
  new (return$) ::rust::String(QComboBox_currentText$(cb));
}

void cxxbridge1$205$QComboBox_setCurrentIndex(::QComboBox *cb, ::std::int32_t index) noexcept {
  void (*QComboBox_setCurrentIndex$)(::QComboBox *, ::std::int32_t) = ::QComboBox_setCurrentIndex;
  QComboBox_setCurrentIndex$(cb, index);
}

::std::int32_t cxxbridge1$205$QComboBox_count(::QComboBox *cb) noexcept {
  ::std::int32_t (*QComboBox_count$)(::QComboBox *) = ::QComboBox_count;
  return QComboBox_count$(cb);
}

void cxxbridge1$205$QComboBox_removeItem(::QComboBox *cb, ::std::int32_t index) noexcept {
  void (*QComboBox_removeItem$)(::QComboBox *, ::std::int32_t) = ::QComboBox_removeItem;
  QComboBox_removeItem$(cb, index);
}

void cxxbridge1$205$QComboBox_clear(::QComboBox *cb) noexcept {
  void (*QComboBox_clear$)(::QComboBox *) = ::QComboBox_clear;
  QComboBox_clear$(cb);
}

void cxxbridge1$205$QComboBox_setEditable(::QComboBox *cb, bool edit) noexcept {
  void (*QComboBox_setEditable$)(::QComboBox *, bool) = ::QComboBox_setEditable;
  QComboBox_setEditable$(cb, edit);
}

bool cxxbridge1$205$QComboBox_isEditable(::QComboBox *cb) noexcept {
  bool (*QComboBox_isEditable$)(::QComboBox *) = ::QComboBox_isEditable;
  return QComboBox_isEditable$(cb);
}

void cxxbridge1$205$QComboBox_setMaxCount(::QComboBox *cb, ::std::int32_t max) noexcept {
  void (*QComboBox_setMaxCount$)(::QComboBox *, ::std::int32_t) = ::QComboBox_setMaxCount;
  QComboBox_setMaxCount$(cb, max);
}

void cxxbridge1$205$QComboBox_delete(::QComboBox *cb) noexcept {
  void (*QComboBox_delete$)(::QComboBox *) = ::QComboBox_delete;
  QComboBox_delete$(cb);
}

void cxxbridge1$205$QComboBox_onCurrentTextChanged(::QComboBox *cb, ::std::uint64_t ctx) noexcept {
  void (*QComboBox_onCurrentTextChanged$)(::QComboBox *, ::std::uint64_t) = ::QComboBox_onCurrentTextChanged;
  QComboBox_onCurrentTextChanged$(cb, ctx);
}

void cxxbridge1$205$QComboBox_onCurrentIndexChanged(::QComboBox *cb, ::std::uint64_t ctx) noexcept {
  void (*QComboBox_onCurrentIndexChanged$)(::QComboBox *, ::std::uint64_t) = ::QComboBox_onCurrentIndexChanged;
  QComboBox_onCurrentIndexChanged$(cb, ctx);
}

void cxxbridge1$205$QFileDialog_getOpenFileName(::QWidget *parent, ::std::string const &caption, ::std::string const &dir, ::std::string const &filter, ::rust::String *return$) noexcept {
  ::rust::String (*QFileDialog_getOpenFileName$)(::QWidget *, ::std::string const &, ::std::string const &, ::std::string const &) = ::QFileDialog_getOpenFileName;
  new (return$) ::rust::String(QFileDialog_getOpenFileName$(parent, caption, dir, filter));
}

void cxxbridge1$205$QFileDialog_getOpenFileNames(::QWidget *parent, ::std::string const &caption, ::std::string const &dir, ::std::string const &filter, ::rust::Vec<::rust::String> *return$) noexcept {
  ::rust::Vec<::rust::String> (*QFileDialog_getOpenFileNames$)(::QWidget *, ::std::string const &, ::std::string const &, ::std::string const &) = ::QFileDialog_getOpenFileNames;
  new (return$) ::rust::Vec<::rust::String>(QFileDialog_getOpenFileNames$(parent, caption, dir, filter));
}

void cxxbridge1$205$QFileDialog_getSaveFileName(::QWidget *parent, ::std::string const &caption, ::std::string const &dir, ::std::string const &filter, ::rust::String *return$) noexcept {
  ::rust::String (*QFileDialog_getSaveFileName$)(::QWidget *, ::std::string const &, ::std::string const &, ::std::string const &) = ::QFileDialog_getSaveFileName;
  new (return$) ::rust::String(QFileDialog_getSaveFileName$(parent, caption, dir, filter));
}

void cxxbridge1$205$QFileDialog_getExistingDirectory(::QWidget *parent, ::std::string const &caption, ::std::string const &dir, ::rust::String *return$) noexcept {
  ::rust::String (*QFileDialog_getExistingDirectory$)(::QWidget *, ::std::string const &, ::std::string const &) = ::QFileDialog_getExistingDirectory;
  new (return$) ::rust::String(QFileDialog_getExistingDirectory$(parent, caption, dir));
}

::QWidget *cxxbridge1$205$QWidget_findWidget(::QWidget *parent, ::std::string const &name) noexcept {
  ::QWidget *(*QWidget_findWidget$)(::QWidget *, ::std::string const &) = ::QWidget_findWidget;
  return QWidget_findWidget$(parent, name);
}

::QPushButton *cxxbridge1$205$QWidget_findPushButton(::QWidget *parent, ::std::string const &name) noexcept {
  ::QPushButton *(*QWidget_findPushButton$)(::QWidget *, ::std::string const &) = ::QWidget_findPushButton;
  return QWidget_findPushButton$(parent, name);
}

::QLineEdit *cxxbridge1$205$QWidget_findLineEdit(::QWidget *parent, ::std::string const &name) noexcept {
  ::QLineEdit *(*QWidget_findLineEdit$)(::QWidget *, ::std::string const &) = ::QWidget_findLineEdit;
  return QWidget_findLineEdit$(parent, name);
}

::QCheckBox *cxxbridge1$205$QWidget_findCheckBox(::QWidget *parent, ::std::string const &name) noexcept {
  ::QCheckBox *(*QWidget_findCheckBox$)(::QWidget *, ::std::string const &) = ::QWidget_findCheckBox;
  return QWidget_findCheckBox$(parent, name);
}

::QLabel *cxxbridge1$205$QWidget_findLabel(::QWidget *parent, ::std::string const &name) noexcept {
  ::QLabel *(*QWidget_findLabel$)(::QWidget *, ::std::string const &) = ::QWidget_findLabel;
  return QWidget_findLabel$(parent, name);
}

::QComboBox *cxxbridge1$205$QWidget_findComboBox(::QWidget *parent, ::std::string const &name) noexcept {
  ::QComboBox *(*QWidget_findComboBox$)(::QWidget *, ::std::string const &) = ::QWidget_findComboBox;
  return QWidget_findComboBox$(parent, name);
}

::QSlider *cxxbridge1$205$QWidget_findSlider(::QWidget *parent, ::std::string const &name) noexcept {
  ::QSlider *(*QWidget_findSlider$)(::QWidget *, ::std::string const &) = ::QWidget_findSlider;
  return QWidget_findSlider$(parent, name);
}

::QTextEdit *cxxbridge1$205$QWidget_findTextEdit(::QWidget *parent, ::std::string const &name) noexcept {
  ::QTextEdit *(*QWidget_findTextEdit$)(::QWidget *, ::std::string const &) = ::QWidget_findTextEdit;
  return QWidget_findTextEdit$(parent, name);
}

::QProgressBar *cxxbridge1$205$QWidget_findProgressBar(::QWidget *parent, ::std::string const &name) noexcept {
  ::QProgressBar *(*QWidget_findProgressBar$)(::QWidget *, ::std::string const &) = ::QWidget_findProgressBar;
  return QWidget_findProgressBar$(parent, name);
}

::QRadioButton *cxxbridge1$205$QWidget_findRadioButton(::QWidget *parent, ::std::string const &name) noexcept {
  ::QRadioButton *(*QWidget_findRadioButton$)(::QWidget *, ::std::string const &) = ::QWidget_findRadioButton;
  return QWidget_findRadioButton$(parent, name);
}

::QGroupBox *cxxbridge1$205$QWidget_findGroupBox(::QWidget *parent, ::std::string const &name) noexcept {
  ::QGroupBox *(*QWidget_findGroupBox$)(::QWidget *, ::std::string const &) = ::QWidget_findGroupBox;
  return QWidget_findGroupBox$(parent, name);
}

::QTabWidget *cxxbridge1$205$QWidget_findTabWidget(::QWidget *parent, ::std::string const &name) noexcept {
  ::QTabWidget *(*QWidget_findTabWidget$)(::QWidget *, ::std::string const &) = ::QWidget_findTabWidget;
  return QWidget_findTabWidget$(parent, name);
}

::QSpinBox *cxxbridge1$205$QWidget_findSpinBox(::QWidget *parent, ::std::string const &name) noexcept {
  ::QSpinBox *(*QWidget_findSpinBox$)(::QWidget *, ::std::string const &) = ::QWidget_findSpinBox;
  return QWidget_findSpinBox$(parent, name);
}

::QListWidget *cxxbridge1$205$QWidget_findListWidget(::QWidget *parent, ::std::string const &name) noexcept {
  ::QListWidget *(*QWidget_findListWidget$)(::QWidget *, ::std::string const &) = ::QWidget_findListWidget;
  return QWidget_findListWidget$(parent, name);
}

::QProgressDialog *cxxbridge1$205$QWidget_findProgressDialog(::QWidget *parent, ::std::string const &name) noexcept {
  ::QProgressDialog *(*QWidget_findProgressDialog$)(::QWidget *, ::std::string const &) = ::QWidget_findProgressDialog;
  return QWidget_findProgressDialog$(parent, name);
}

::QScrollArea *cxxbridge1$205$QWidget_findScrollArea(::QWidget *parent, ::std::string const &name) noexcept {
  ::QScrollArea *(*QWidget_findScrollArea$)(::QWidget *, ::std::string const &) = ::QWidget_findScrollArea;
  return QWidget_findScrollArea$(parent, name);
}

::QTableWidget *cxxbridge1$205$QWidget_findTableWidget(::QWidget *parent, ::std::string const &name) noexcept {
  ::QTableWidget *(*QWidget_findTableWidget$)(::QWidget *, ::std::string const &) = ::QWidget_findTableWidget;
  return QWidget_findTableWidget$(parent, name);
}

::QTreeWidget *cxxbridge1$205$QWidget_findTreeWidget(::QWidget *parent, ::std::string const &name) noexcept {
  ::QTreeWidget *(*QWidget_findTreeWidget$)(::QWidget *, ::std::string const &) = ::QWidget_findTreeWidget;
  return QWidget_findTreeWidget$(parent, name);
}

::QStackedWidget *cxxbridge1$205$QWidget_findStackedWidget(::QWidget *parent, ::std::string const &name) noexcept {
  ::QStackedWidget *(*QWidget_findStackedWidget$)(::QWidget *, ::std::string const &) = ::QWidget_findStackedWidget;
  return QWidget_findStackedWidget$(parent, name);
}

::QSplitter *cxxbridge1$205$QWidget_findSplitter(::QWidget *parent, ::std::string const &name) noexcept {
  ::QSplitter *(*QWidget_findSplitter$)(::QWidget *, ::std::string const &) = ::QWidget_findSplitter;
  return QWidget_findSplitter$(parent, name);
}

::QFrame *cxxbridge1$205$QWidget_findFrame(::QWidget *parent, ::std::string const &name) noexcept {
  ::QFrame *(*QWidget_findFrame$)(::QWidget *, ::std::string const &) = ::QWidget_findFrame;
  return QWidget_findFrame$(parent, name);
}

::QToolButton *cxxbridge1$205$QWidget_findToolButton(::QWidget *parent, ::std::string const &name) noexcept {
  ::QToolButton *(*QWidget_findToolButton$)(::QWidget *, ::std::string const &) = ::QWidget_findToolButton;
  return QWidget_findToolButton$(parent, name);
}

::QCalendarWidget *cxxbridge1$205$QWidget_findCalendarWidget(::QWidget *parent, ::std::string const &name) noexcept {
  ::QCalendarWidget *(*QWidget_findCalendarWidget$)(::QWidget *, ::std::string const &) = ::QWidget_findCalendarWidget;
  return QWidget_findCalendarWidget$(parent, name);
}

::QDateEdit *cxxbridge1$205$QWidget_findDateEdit(::QWidget *parent, ::std::string const &name) noexcept {
  ::QDateEdit *(*QWidget_findDateEdit$)(::QWidget *, ::std::string const &) = ::QWidget_findDateEdit;
  return QWidget_findDateEdit$(parent, name);
}

::QTimeEdit *cxxbridge1$205$QWidget_findTimeEdit(::QWidget *parent, ::std::string const &name) noexcept {
  ::QTimeEdit *(*QWidget_findTimeEdit$)(::QWidget *, ::std::string const &) = ::QWidget_findTimeEdit;
  return QWidget_findTimeEdit$(parent, name);
}

::QDateTimeEdit *cxxbridge1$205$QWidget_findDateTimeEdit(::QWidget *parent, ::std::string const &name) noexcept {
  ::QDateTimeEdit *(*QWidget_findDateTimeEdit$)(::QWidget *, ::std::string const &) = ::QWidget_findDateTimeEdit;
  return QWidget_findDateTimeEdit$(parent, name);
}

::QPlainTextEdit *cxxbridge1$205$QWidget_findPlainTextEdit(::QWidget *parent, ::std::string const &name) noexcept {
  ::QPlainTextEdit *(*QWidget_findPlainTextEdit$)(::QWidget *, ::std::string const &) = ::QWidget_findPlainTextEdit;
  return QWidget_findPlainTextEdit$(parent, name);
}

::QTextBrowser *cxxbridge1$205$QWidget_findTextBrowser(::QWidget *parent, ::std::string const &name) noexcept {
  ::QTextBrowser *(*QWidget_findTextBrowser$)(::QWidget *, ::std::string const &) = ::QWidget_findTextBrowser;
  return QWidget_findTextBrowser$(parent, name);
}

::QFormLayout *cxxbridge1$205$QFormLayout_new(::QWidget *parent) noexcept {
  ::QFormLayout *(*QFormLayout_new$)(::QWidget *) = ::QFormLayout_new;
  return QFormLayout_new$(parent);
}

void cxxbridge1$205$QFormLayout_addRow(::QFormLayout *layout, ::rust::String const &label, ::QWidget *widget) noexcept {
  void (*QFormLayout_addRow$)(::QFormLayout *, ::rust::String const &, ::QWidget *) = ::QFormLayout_addRow;
  QFormLayout_addRow$(layout, label, widget);
}

void cxxbridge1$205$QFormLayout_addRowWidget(::QFormLayout *layout, ::QWidget *widget) noexcept {
  void (*QFormLayout_addRowWidget$)(::QFormLayout *, ::QWidget *) = ::QFormLayout_addRowWidget;
  QFormLayout_addRowWidget$(layout, widget);
}

void cxxbridge1$205$QFormLayout_setSpacing(::QFormLayout *layout, ::std::int32_t spacing) noexcept {
  void (*QFormLayout_setSpacing$)(::QFormLayout *, ::std::int32_t) = ::QFormLayout_setSpacing;
  QFormLayout_setSpacing$(layout, spacing);
}

void cxxbridge1$205$QFormLayout_setContentsMargins(::QFormLayout *layout, ::std::int32_t left, ::std::int32_t top, ::std::int32_t right, ::std::int32_t bottom) noexcept {
  void (*QFormLayout_setContentsMargins$)(::QFormLayout *, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QFormLayout_setContentsMargins;
  QFormLayout_setContentsMargins$(layout, left, top, right, bottom);
}

void cxxbridge1$205$QFormLayout_delete(::QFormLayout *layout) noexcept {
  void (*QFormLayout_delete$)(::QFormLayout *) = ::QFormLayout_delete;
  QFormLayout_delete$(layout);
}

::QGridLayout *cxxbridge1$205$QGridLayout_new(::QWidget *parent) noexcept {
  ::QGridLayout *(*QGridLayout_new$)(::QWidget *) = ::QGridLayout_new;
  return QGridLayout_new$(parent);
}

void cxxbridge1$205$QGridLayout_addWidget(::QGridLayout *layout, ::QWidget *widget, ::std::int32_t row, ::std::int32_t col, ::std::int32_t rowSpan, ::std::int32_t colSpan) noexcept {
  void (*QGridLayout_addWidget$)(::QGridLayout *, ::QWidget *, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QGridLayout_addWidget;
  QGridLayout_addWidget$(layout, widget, row, col, rowSpan, colSpan);
}

void cxxbridge1$205$QGridLayout_delete(::QGridLayout *layout) noexcept {
  void (*QGridLayout_delete$)(::QGridLayout *) = ::QGridLayout_delete;
  QGridLayout_delete$(layout);
}

::QGroupBox *cxxbridge1$205$QGroupBox_new(::std::string const &title, ::QWidget *parent) noexcept {
  ::QGroupBox *(*QGroupBox_new$)(::std::string const &, ::QWidget *) = ::QGroupBox_new;
  return QGroupBox_new$(title, parent);
}

void cxxbridge1$205$QGroupBox_setTitle(::QGroupBox *gb, ::std::string const &title) noexcept {
  void (*QGroupBox_setTitle$)(::QGroupBox *, ::std::string const &) = ::QGroupBox_setTitle;
  QGroupBox_setTitle$(gb, title);
}

void cxxbridge1$205$QGroupBox_delete(::QGroupBox *gb) noexcept {
  void (*QGroupBox_delete$)(::QGroupBox *) = ::QGroupBox_delete;
  QGroupBox_delete$(gb);
}

::QHBoxLayout *cxxbridge1$205$QHBoxLayout_new(::QWidget *parent) noexcept {
  ::QHBoxLayout *(*QHBoxLayout_new$)(::QWidget *) = ::QHBoxLayout_new;
  return QHBoxLayout_new$(parent);
}

void cxxbridge1$205$QHBoxLayout_addWidget(::QHBoxLayout *layout, ::QWidget *widget) noexcept {
  void (*QHBoxLayout_addWidget$)(::QHBoxLayout *, ::QWidget *) = ::QHBoxLayout_addWidget;
  QHBoxLayout_addWidget$(layout, widget);
}

void cxxbridge1$205$QHBoxLayout_delete(::QHBoxLayout *layout) noexcept {
  void (*QHBoxLayout_delete$)(::QHBoxLayout *) = ::QHBoxLayout_delete;
  QHBoxLayout_delete$(layout);
}

void cxxbridge1$205$QHBoxLayout_setSpacing(::QHBoxLayout *layout, ::std::int32_t spacing) noexcept {
  void (*QHBoxLayout_setSpacing$)(::QHBoxLayout *, ::std::int32_t) = ::QHBoxLayout_setSpacing;
  QHBoxLayout_setSpacing$(layout, spacing);
}

void cxxbridge1$205$QHBoxLayout_setContentsMargins(::QHBoxLayout *layout, ::std::int32_t left, ::std::int32_t top, ::std::int32_t right, ::std::int32_t bottom) noexcept {
  void (*QHBoxLayout_setContentsMargins$)(::QHBoxLayout *, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QHBoxLayout_setContentsMargins;
  QHBoxLayout_setContentsMargins$(layout, left, top, right, bottom);
}

void cxxbridge1$205$QHBoxLayout_addSpacerItem(::QHBoxLayout *layout, ::QSpacerItem *spacer) noexcept {
  void (*QHBoxLayout_addSpacerItem$)(::QHBoxLayout *, ::QSpacerItem *) = ::QHBoxLayout_addSpacerItem;
  QHBoxLayout_addSpacerItem$(layout, spacer);
}

void cxxbridge1$205$QInputDialog_getText(::QWidget *parent, ::std::string const &title, ::std::string const &label, ::std::string const &text, ::rust::String *return$) noexcept {
  ::rust::String (*QInputDialog_getText$)(::QWidget *, ::std::string const &, ::std::string const &, ::std::string const &) = ::QInputDialog_getText;
  new (return$) ::rust::String(QInputDialog_getText$(parent, title, label, text));
}

::std::int32_t cxxbridge1$205$QInputDialog_getInt(::QWidget *parent, ::std::string const &title, ::std::string const &label, ::std::int32_t value, ::std::int32_t min, ::std::int32_t max, ::std::int32_t step) noexcept {
  ::std::int32_t (*QInputDialog_getInt$)(::QWidget *, ::std::string const &, ::std::string const &, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QInputDialog_getInt;
  return QInputDialog_getInt$(parent, title, label, value, min, max, step);
}

double cxxbridge1$205$QInputDialog_getDouble(::QWidget *parent, ::std::string const &title, ::std::string const &label, double value, double min, double max, ::std::int32_t decimals) noexcept {
  double (*QInputDialog_getDouble$)(::QWidget *, ::std::string const &, ::std::string const &, double, double, double, ::std::int32_t) = ::QInputDialog_getDouble;
  return QInputDialog_getDouble$(parent, title, label, value, min, max, decimals);
}

void cxxbridge1$205$QInputDialog_getItem(::QWidget *parent, ::std::string const &title, ::std::string const &label, ::rust::Vec<::rust::String> const *items, ::std::int32_t current, bool editable, ::rust::String *return$) noexcept {
  ::rust::String (*QInputDialog_getItem$)(::QWidget *, ::std::string const &, ::std::string const &, ::rust::Vec<::rust::String>, ::std::int32_t, bool) = ::QInputDialog_getItem;
  new (return$) ::rust::String(QInputDialog_getItem$(parent, title, label, ::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *items), current, editable));
}

::QLabel *cxxbridge1$205$QLabel_new(::std::string const &text, ::QWidget *parent) noexcept {
  ::QLabel *(*QLabel_new$)(::std::string const &, ::QWidget *) = ::QLabel_new;
  return QLabel_new$(text, parent);
}

void cxxbridge1$205$QLabel_setText(::QLabel *label, ::std::string const &text) noexcept {
  void (*QLabel_setText$)(::QLabel *, ::std::string const &) = ::QLabel_setText;
  QLabel_setText$(label, text);
}

void cxxbridge1$205$QLabel_delete(::QLabel *label) noexcept {
  void (*QLabel_delete$)(::QLabel *) = ::QLabel_delete;
  QLabel_delete$(label);
}

::QLineEdit *cxxbridge1$205$QLineEdit_new(::std::string const &text, ::QWidget *parent) noexcept {
  ::QLineEdit *(*QLineEdit_new$)(::std::string const &, ::QWidget *) = ::QLineEdit_new;
  return QLineEdit_new$(text, parent);
}

void cxxbridge1$205$QLineEdit_text(::QLineEdit *edit, ::rust::String *return$) noexcept {
  ::rust::String (*QLineEdit_text$)(::QLineEdit *) = ::QLineEdit_text;
  new (return$) ::rust::String(QLineEdit_text$(edit));
}

void cxxbridge1$205$QLineEdit_setText(::QLineEdit *edit, ::std::string const &text) noexcept {
  void (*QLineEdit_setText$)(::QLineEdit *, ::std::string const &) = ::QLineEdit_setText;
  QLineEdit_setText$(edit, text);
}

void cxxbridge1$205$QLineEdit_delete(::QLineEdit *edit) noexcept {
  void (*QLineEdit_delete$)(::QLineEdit *) = ::QLineEdit_delete;
  QLineEdit_delete$(edit);
}

void cxxbridge1$205$QLineEdit_clear(::QLineEdit *edit) noexcept {
  void (*QLineEdit_clear$)(::QLineEdit *) = ::QLineEdit_clear;
  QLineEdit_clear$(edit);
}

void cxxbridge1$205$QLineEdit_selectAll(::QLineEdit *edit) noexcept {
  void (*QLineEdit_selectAll$)(::QLineEdit *) = ::QLineEdit_selectAll;
  QLineEdit_selectAll$(edit);
}

void cxxbridge1$205$QLineEdit_copy(::QLineEdit *edit) noexcept {
  void (*QLineEdit_copy$)(::QLineEdit *) = ::QLineEdit_copy;
  QLineEdit_copy$(edit);
}

void cxxbridge1$205$QLineEdit_cut(::QLineEdit *edit) noexcept {
  void (*QLineEdit_cut$)(::QLineEdit *) = ::QLineEdit_cut;
  QLineEdit_cut$(edit);
}

void cxxbridge1$205$QLineEdit_paste(::QLineEdit *edit) noexcept {
  void (*QLineEdit_paste$)(::QLineEdit *) = ::QLineEdit_paste;
  QLineEdit_paste$(edit);
}

void cxxbridge1$205$QLineEdit_undo(::QLineEdit *edit) noexcept {
  void (*QLineEdit_undo$)(::QLineEdit *) = ::QLineEdit_undo;
  QLineEdit_undo$(edit);
}

void cxxbridge1$205$QLineEdit_redo(::QLineEdit *edit) noexcept {
  void (*QLineEdit_redo$)(::QLineEdit *) = ::QLineEdit_redo;
  QLineEdit_redo$(edit);
}

void cxxbridge1$205$QLineEdit_setReadOnly(::QLineEdit *edit, bool ro) noexcept {
  void (*QLineEdit_setReadOnly$)(::QLineEdit *, bool) = ::QLineEdit_setReadOnly;
  QLineEdit_setReadOnly$(edit, ro);
}

bool cxxbridge1$205$QLineEdit_isReadOnly(::QLineEdit *edit) noexcept {
  bool (*QLineEdit_isReadOnly$)(::QLineEdit *) = ::QLineEdit_isReadOnly;
  return QLineEdit_isReadOnly$(edit);
}

void cxxbridge1$205$QLineEdit_setEchoMode(::QLineEdit *edit, ::std::int32_t mode) noexcept {
  void (*QLineEdit_setEchoMode$)(::QLineEdit *, ::std::int32_t) = ::QLineEdit_setEchoMode;
  QLineEdit_setEchoMode$(edit, mode);
}

void cxxbridge1$205$QLineEdit_setMaxLength(::QLineEdit *edit, ::std::int32_t len) noexcept {
  void (*QLineEdit_setMaxLength$)(::QLineEdit *, ::std::int32_t) = ::QLineEdit_setMaxLength;
  QLineEdit_setMaxLength$(edit, len);
}

::std::int32_t cxxbridge1$205$QLineEdit_maxLength(::QLineEdit *edit) noexcept {
  ::std::int32_t (*QLineEdit_maxLength$)(::QLineEdit *) = ::QLineEdit_maxLength;
  return QLineEdit_maxLength$(edit);
}

::std::int32_t cxxbridge1$205$QLineEdit_cursorPosition(::QLineEdit *edit) noexcept {
  ::std::int32_t (*QLineEdit_cursorPosition$)(::QLineEdit *) = ::QLineEdit_cursorPosition;
  return QLineEdit_cursorPosition$(edit);
}

void cxxbridge1$205$QLineEdit_setCursorPosition(::QLineEdit *edit, ::std::int32_t pos) noexcept {
  void (*QLineEdit_setCursorPosition$)(::QLineEdit *, ::std::int32_t) = ::QLineEdit_setCursorPosition;
  QLineEdit_setCursorPosition$(edit, pos);
}

void cxxbridge1$205$QLineEdit_onReturnPressed(::QLineEdit *edit, ::std::uint64_t ctx) noexcept {
  void (*QLineEdit_onReturnPressed$)(::QLineEdit *, ::std::uint64_t) = ::QLineEdit_onReturnPressed;
  QLineEdit_onReturnPressed$(edit, ctx);
}

::QMainWindow *cxxbridge1$205$QMainWindow_new(::QWidget *parent) noexcept {
  ::QMainWindow *(*QMainWindow_new$)(::QWidget *) = ::QMainWindow_new;
  return QMainWindow_new$(parent);
}

void cxxbridge1$205$QMainWindow_delete(::QMainWindow *w) noexcept {
  void (*QMainWindow_delete$)(::QMainWindow *) = ::QMainWindow_delete;
  QMainWindow_delete$(w);
}

void cxxbridge1$205$QMainWindow_setMenuBar(::QMainWindow *w, ::QMenuBar *menuBar) noexcept {
  void (*QMainWindow_setMenuBar$)(::QMainWindow *, ::QMenuBar *) = ::QMainWindow_setMenuBar;
  QMainWindow_setMenuBar$(w, menuBar);
}

void cxxbridge1$205$QMainWindow_setCentralWidget(::QMainWindow *w, ::QWidget *central) noexcept {
  void (*QMainWindow_setCentralWidget$)(::QMainWindow *, ::QWidget *) = ::QMainWindow_setCentralWidget;
  QMainWindow_setCentralWidget$(w, central);
}

void cxxbridge1$205$QMainWindow_setStatusBar(::QMainWindow *w, ::QStatusBar *statusBar) noexcept {
  void (*QMainWindow_setStatusBar$)(::QMainWindow *, ::QStatusBar *) = ::QMainWindow_setStatusBar;
  QMainWindow_setStatusBar$(w, statusBar);
}

::QToolBar *cxxbridge1$205$QMainWindow_addToolBar(::QMainWindow *w, ::std::string const &title) noexcept {
  ::QToolBar *(*QMainWindow_addToolBar$)(::QMainWindow *, ::std::string const &) = ::QMainWindow_addToolBar;
  return QMainWindow_addToolBar$(w, title);
}

void cxxbridge1$205$QMainWindow_addToolBarBreak(::QMainWindow *w) noexcept {
  void (*QMainWindow_addToolBarBreak$)(::QMainWindow *) = ::QMainWindow_addToolBarBreak;
  QMainWindow_addToolBarBreak$(w);
}

void cxxbridge1$205$QMainWindow_setWindowTitle(::QMainWindow *w, ::std::string const &title) noexcept {
  void (*QMainWindow_setWindowTitle$)(::QMainWindow *, ::std::string const &) = ::QMainWindow_setWindowTitle;
  QMainWindow_setWindowTitle$(w, title);
}

void cxxbridge1$205$QMainWindow_resize(::QMainWindow *w, ::std::int32_t width, ::std::int32_t height) noexcept {
  void (*QMainWindow_resize$)(::QMainWindow *, ::std::int32_t, ::std::int32_t) = ::QMainWindow_resize;
  QMainWindow_resize$(w, width, height);
}

void cxxbridge1$205$QMainWindow_show(::QMainWindow *w) noexcept {
  void (*QMainWindow_show$)(::QMainWindow *) = ::QMainWindow_show;
  QMainWindow_show$(w);
}

void cxxbridge1$205$QMainWindow_hide(::QMainWindow *w) noexcept {
  void (*QMainWindow_hide$)(::QMainWindow *) = ::QMainWindow_hide;
  QMainWindow_hide$(w);
}

void cxxbridge1$205$QMainWindow_setDockOptions(::QMainWindow *w, ::std::int32_t options) noexcept {
  void (*QMainWindow_setDockOptions$)(::QMainWindow *, ::std::int32_t) = ::QMainWindow_setDockOptions;
  QMainWindow_setDockOptions$(w, options);
}

void cxxbridge1$205$QMainWindow_setTabPosition(::QMainWindow *w, ::std::int32_t areas, ::std::int32_t tabPos) noexcept {
  void (*QMainWindow_setTabPosition$)(::QMainWindow *, ::std::int32_t, ::std::int32_t) = ::QMainWindow_setTabPosition;
  QMainWindow_setTabPosition$(w, areas, tabPos);
}

::QMenu *cxxbridge1$205$QMenu_new(::std::string const &title, ::QWidget *parent) noexcept {
  ::QMenu *(*QMenu_new$)(::std::string const &, ::QWidget *) = ::QMenu_new;
  return QMenu_new$(title, parent);
}

void cxxbridge1$205$QMenu_addAction(::QMenu *menu, ::std::string const &text, ::std::uint64_t ctx) noexcept {
  void (*QMenu_addAction$)(::QMenu *, ::std::string const &, ::std::uint64_t) = ::QMenu_addAction;
  QMenu_addAction$(menu, text, ctx);
}

void cxxbridge1$205$QMenu_delete(::QMenu *menu) noexcept {
  void (*QMenu_delete$)(::QMenu *) = ::QMenu_delete;
  QMenu_delete$(menu);
}

::QMenuBar *cxxbridge1$205$QMenuBar_new(::QWidget *parent) noexcept {
  ::QMenuBar *(*QMenuBar_new$)(::QWidget *) = ::QMenuBar_new;
  return QMenuBar_new$(parent);
}

void cxxbridge1$205$QMenuBar_addMenu(::QMenuBar *mb, ::QMenu *menu) noexcept {
  void (*QMenuBar_addMenu$)(::QMenuBar *, ::QMenu *) = ::QMenuBar_addMenu;
  QMenuBar_addMenu$(mb, menu);
}

void cxxbridge1$205$QMenuBar_delete(::QMenuBar *mb) noexcept {
  void (*QMenuBar_delete$)(::QMenuBar *) = ::QMenuBar_delete;
  QMenuBar_delete$(mb);
}

void cxxbridge1$205$QMessageBox_information(::QWidget *parent, ::std::string const &title, ::std::string const &text) noexcept {
  void (*QMessageBox_information$)(::QWidget *, ::std::string const &, ::std::string const &) = ::QMessageBox_information;
  QMessageBox_information$(parent, title, text);
}

void cxxbridge1$205$QMessageBox_warning(::QWidget *parent, ::std::string const &title, ::std::string const &text) noexcept {
  void (*QMessageBox_warning$)(::QWidget *, ::std::string const &, ::std::string const &) = ::QMessageBox_warning;
  QMessageBox_warning$(parent, title, text);
}

void cxxbridge1$205$QMessageBox_critical(::QWidget *parent, ::std::string const &title, ::std::string const &text) noexcept {
  void (*QMessageBox_critical$)(::QWidget *, ::std::string const &, ::std::string const &) = ::QMessageBox_critical;
  QMessageBox_critical$(parent, title, text);
}

::std::int32_t cxxbridge1$205$QMessageBox_question(::QWidget *parent, ::std::string const &title, ::std::string const &text) noexcept {
  ::std::int32_t (*QMessageBox_question$)(::QWidget *, ::std::string const &, ::std::string const &) = ::QMessageBox_question;
  return QMessageBox_question$(parent, title, text);
}

::QMessageBox *cxxbridge1$205$QMessageBox_new(::QWidget *parent) noexcept {
  ::QMessageBox *(*QMessageBox_new$)(::QWidget *) = ::QMessageBox_new;
  return QMessageBox_new$(parent);
}

void cxxbridge1$205$QMessageBox_delete(::QMessageBox *w) noexcept {
  void (*QMessageBox_delete$)(::QMessageBox *) = ::QMessageBox_delete;
  QMessageBox_delete$(w);
}

void cxxbridge1$205$QMessageBox_setIcon(::QMessageBox *w, ::std::int32_t icon) noexcept {
  void (*QMessageBox_setIcon$)(::QMessageBox *, ::std::int32_t) = ::QMessageBox_setIcon;
  QMessageBox_setIcon$(w, icon);
}

void cxxbridge1$205$QMessageBox_setText(::QMessageBox *w, ::std::string const &text) noexcept {
  void (*QMessageBox_setText$)(::QMessageBox *, ::std::string const &) = ::QMessageBox_setText;
  QMessageBox_setText$(w, text);
}

void cxxbridge1$205$QMessageBox_setInformativeText(::QMessageBox *w, ::std::string const &text) noexcept {
  void (*QMessageBox_setInformativeText$)(::QMessageBox *, ::std::string const &) = ::QMessageBox_setInformativeText;
  QMessageBox_setInformativeText$(w, text);
}

void cxxbridge1$205$QMessageBox_setWindowTitle(::QMessageBox *w, ::std::string const &title) noexcept {
  void (*QMessageBox_setWindowTitle$)(::QMessageBox *, ::std::string const &) = ::QMessageBox_setWindowTitle;
  QMessageBox_setWindowTitle$(w, title);
}

void cxxbridge1$205$QMessageBox_setStandardButtons(::QMessageBox *w, ::std::int32_t buttons) noexcept {
  void (*QMessageBox_setStandardButtons$)(::QMessageBox *, ::std::int32_t) = ::QMessageBox_setStandardButtons;
  QMessageBox_setStandardButtons$(w, buttons);
}

void cxxbridge1$205$QMessageBox_setDefaultButton(::QMessageBox *w, ::std::int32_t button) noexcept {
  void (*QMessageBox_setDefaultButton$)(::QMessageBox *, ::std::int32_t) = ::QMessageBox_setDefaultButton;
  QMessageBox_setDefaultButton$(w, button);
}

void cxxbridge1$205$QMessageBox_setDetailedText(::QMessageBox *w, ::std::string const &text) noexcept {
  void (*QMessageBox_setDetailedText$)(::QMessageBox *, ::std::string const &) = ::QMessageBox_setDetailedText;
  QMessageBox_setDetailedText$(w, text);
}

::std::int32_t cxxbridge1$205$QMessageBox_exec(::QMessageBox *w) noexcept {
  ::std::int32_t (*QMessageBox_exec$)(::QMessageBox *) = ::QMessageBox_exec;
  return QMessageBox_exec$(w);
}

void cxxbridge1$205$QMessageBox_about(::QWidget *parent, ::std::string const &title, ::std::string const &text) noexcept {
  void (*QMessageBox_about$)(::QWidget *, ::std::string const &, ::std::string const &) = ::QMessageBox_about;
  QMessageBox_about$(parent, title, text);
}

bool cxxbridge1$205$QObject_connect(::QObject *sender, ::std::string const &sig, ::QObject *receiver, ::std::string const &slt, ::std::int32_t conn_type) noexcept {
  bool (*QObject_connect$)(::QObject *, ::std::string const &, ::QObject *, ::std::string const &, ::std::int32_t) = ::QObject_connect;
  return QObject_connect$(sender, sig, receiver, slt, conn_type);
}

bool cxxbridge1$205$QObject_disconnect(::QObject *sender, ::std::string const &sig, ::QObject *receiver, ::std::string const &slt) noexcept {
  bool (*QObject_disconnect$)(::QObject *, ::std::string const &, ::QObject *, ::std::string const &) = ::QObject_disconnect;
  return QObject_disconnect$(sender, sig, receiver, slt);
}

void cxxbridge1$205$QObject_disconnectAll(::QObject *obj) noexcept {
  void (*QObject_disconnectAll$)(::QObject *) = ::QObject_disconnectAll;
  QObject_disconnectAll$(obj);
}

bool cxxbridge1$205$QObject_isInGuiThread() noexcept {
  bool (*QObject_isInGuiThread$)() = ::QObject_isInGuiThread;
  return QObject_isInGuiThread$();
}

void cxxbridge1$205$qtrs_setVoidTrampoline(::rust::Fn<void(::std::uint64_t)> trampoline) noexcept {
  void (*qtrs_setVoidTrampoline$)(::rust::Fn<void(::std::uint64_t)>) = ::qtrs_setVoidTrampoline;
  qtrs_setVoidTrampoline$(trampoline);
}

void cxxbridge1$205$qtrs_setVoidTrampoline$trampoline$1(::std::uint64_t arg0, void *) noexcept;

void cxxbridge1$205$qtrs_setVoidTrampoline$trampoline$0(::std::uint64_t arg0, void *extern$) noexcept {
  cxxbridge1$205$qtrs_setVoidTrampoline$trampoline$1(arg0, extern$);
}

void cxxbridge1$205$qtrs_setBoolTrampoline(::rust::Fn<void(::std::uint64_t, bool)> trampoline) noexcept {
  void (*qtrs_setBoolTrampoline$)(::rust::Fn<void(::std::uint64_t, bool)>) = ::qtrs_setBoolTrampoline;
  qtrs_setBoolTrampoline$(trampoline);
}

void cxxbridge1$205$qtrs_setBoolTrampoline$trampoline$1(::std::uint64_t arg0, bool arg1, void *) noexcept;

void cxxbridge1$205$qtrs_setBoolTrampoline$trampoline$0(::std::uint64_t arg0, bool arg1, void *extern$) noexcept {
  cxxbridge1$205$qtrs_setBoolTrampoline$trampoline$1(arg0, arg1, extern$);
}

void cxxbridge1$205$qtrs_setIntTrampoline(::rust::Fn<void(::std::uint64_t, ::std::int32_t)> trampoline) noexcept {
  void (*qtrs_setIntTrampoline$)(::rust::Fn<void(::std::uint64_t, ::std::int32_t)>) = ::qtrs_setIntTrampoline;
  qtrs_setIntTrampoline$(trampoline);
}

void cxxbridge1$205$qtrs_setIntTrampoline$trampoline$1(::std::uint64_t arg0, ::std::int32_t arg1, void *) noexcept;

void cxxbridge1$205$qtrs_setIntTrampoline$trampoline$0(::std::uint64_t arg0, ::std::int32_t arg1, void *extern$) noexcept {
  cxxbridge1$205$qtrs_setIntTrampoline$trampoline$1(arg0, arg1, extern$);
}

void cxxbridge1$205$qtrs_setStringTrampoline(::rust::Fn<void(::std::uint64_t, ::rust::String)> trampoline) noexcept {
  void (*qtrs_setStringTrampoline$)(::rust::Fn<void(::std::uint64_t, ::rust::String)>) = ::qtrs_setStringTrampoline;
  qtrs_setStringTrampoline$(trampoline);
}

void cxxbridge1$205$qtrs_setStringTrampoline$trampoline$1(::std::uint64_t arg0, ::rust::String *arg1, void *) noexcept;

void cxxbridge1$205$qtrs_setStringTrampoline$trampoline$0(::std::uint64_t arg0, ::rust::String arg1, void *extern$) noexcept {
  cxxbridge1$205$qtrs_setStringTrampoline$trampoline$1(arg0, &arg1, extern$);
}

::QPoint *cxxbridge1$205$QPoint_new(::std::int32_t x, ::std::int32_t y) noexcept {
  ::QPoint *(*QPoint_new$)(::std::int32_t, ::std::int32_t) = ::QPoint_new;
  return QPoint_new$(x, y);
}

void cxxbridge1$205$QPoint_delete(::QPoint *point) noexcept {
  void (*QPoint_delete$)(::QPoint *) = ::QPoint_delete;
  QPoint_delete$(point);
}

::QListWidget *cxxbridge1$205$QListWidget_new(::QWidget *parent) noexcept {
  ::QListWidget *(*QListWidget_new$)(::QWidget *) = ::QListWidget_new;
  return QListWidget_new$(parent);
}

void cxxbridge1$205$QListWidget_delete(::QListWidget *w) noexcept {
  void (*QListWidget_delete$)(::QListWidget *) = ::QListWidget_delete;
  QListWidget_delete$(w);
}

void cxxbridge1$205$QListWidget_addItem(::QListWidget *w, ::std::string const &text) noexcept {
  void (*QListWidget_addItem$)(::QListWidget *, ::std::string const &) = ::QListWidget_addItem;
  QListWidget_addItem$(w, text);
}

void cxxbridge1$205$QListWidget_addItems(::QListWidget *w, ::std::vector<::std::string> const &items) noexcept {
  void (*QListWidget_addItems$)(::QListWidget *, ::std::vector<::std::string> const &) = ::QListWidget_addItems;
  QListWidget_addItems$(w, items);
}

void cxxbridge1$205$QListWidget_insertItem(::QListWidget *w, ::std::int32_t row, ::std::string const &text) noexcept {
  void (*QListWidget_insertItem$)(::QListWidget *, ::std::int32_t, ::std::string const &) = ::QListWidget_insertItem;
  QListWidget_insertItem$(w, row, text);
}

void cxxbridge1$205$QListWidget_clear(::QListWidget *w) noexcept {
  void (*QListWidget_clear$)(::QListWidget *) = ::QListWidget_clear;
  QListWidget_clear$(w);
}

void cxxbridge1$205$QListWidget_removeItem(::QListWidget *w, ::std::int32_t row) noexcept {
  void (*QListWidget_removeItem$)(::QListWidget *, ::std::int32_t) = ::QListWidget_removeItem;
  QListWidget_removeItem$(w, row);
}

::std::int32_t cxxbridge1$205$QListWidget_count(::QListWidget *w) noexcept {
  ::std::int32_t (*QListWidget_count$)(::QListWidget *) = ::QListWidget_count;
  return QListWidget_count$(w);
}

void cxxbridge1$205$QListWidget_itemText(::QListWidget *w, ::std::int32_t row, ::rust::String *return$) noexcept {
  ::rust::String (*QListWidget_itemText$)(::QListWidget *, ::std::int32_t) = ::QListWidget_itemText;
  new (return$) ::rust::String(QListWidget_itemText$(w, row));
}

::std::int32_t cxxbridge1$205$QListWidget_currentRow(::QListWidget *w) noexcept {
  ::std::int32_t (*QListWidget_currentRow$)(::QListWidget *) = ::QListWidget_currentRow;
  return QListWidget_currentRow$(w);
}

void cxxbridge1$205$QListWidget_currentText(::QListWidget *w, ::rust::String *return$) noexcept {
  ::rust::String (*QListWidget_currentText$)(::QListWidget *) = ::QListWidget_currentText;
  new (return$) ::rust::String(QListWidget_currentText$(w));
}

void cxxbridge1$205$QListWidget_setCurrentRow(::QListWidget *w, ::std::int32_t row) noexcept {
  void (*QListWidget_setCurrentRow$)(::QListWidget *, ::std::int32_t) = ::QListWidget_setCurrentRow;
  QListWidget_setCurrentRow$(w, row);
}

void cxxbridge1$205$QListWidget_setSelectionMode(::QListWidget *w, ::std::int32_t mode) noexcept {
  void (*QListWidget_setSelectionMode$)(::QListWidget *, ::std::int32_t) = ::QListWidget_setSelectionMode;
  QListWidget_setSelectionMode$(w, mode);
}

void cxxbridge1$205$QListWidget_onItemClicked(::QListWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QListWidget_onItemClicked$)(::QListWidget *, ::std::uint64_t) = ::QListWidget_onItemClicked;
  QListWidget_onItemClicked$(w, ctx);
}

void cxxbridge1$205$QListWidget_onItemDoubleClicked(::QListWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QListWidget_onItemDoubleClicked$)(::QListWidget *, ::std::uint64_t) = ::QListWidget_onItemDoubleClicked;
  QListWidget_onItemDoubleClicked$(w, ctx);
}

void cxxbridge1$205$QListWidget_onCurrentItemChanged(::QListWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QListWidget_onCurrentItemChanged$)(::QListWidget *, ::std::uint64_t) = ::QListWidget_onCurrentItemChanged;
  QListWidget_onCurrentItemChanged$(w, ctx);
}

void cxxbridge1$205$QListWidget_setItemCheckable(::QListWidget *w, ::std::int32_t row, bool checkable) noexcept {
  void (*QListWidget_setItemCheckable$)(::QListWidget *, ::std::int32_t, bool) = ::QListWidget_setItemCheckable;
  QListWidget_setItemCheckable$(w, row, checkable);
}

void cxxbridge1$205$QListWidget_setItemChecked(::QListWidget *w, ::std::int32_t row, bool checked) noexcept {
  void (*QListWidget_setItemChecked$)(::QListWidget *, ::std::int32_t, bool) = ::QListWidget_setItemChecked;
  QListWidget_setItemChecked$(w, row, checked);
}

bool cxxbridge1$205$QListWidget_isItemChecked(::QListWidget *w, ::std::int32_t row) noexcept {
  bool (*QListWidget_isItemChecked$)(::QListWidget *, ::std::int32_t) = ::QListWidget_isItemChecked;
  return QListWidget_isItemChecked$(w, row);
}

void cxxbridge1$205$QListWidget_onItemChanged(::QListWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QListWidget_onItemChanged$)(::QListWidget *, ::std::uint64_t) = ::QListWidget_onItemChanged;
  QListWidget_onItemChanged$(w, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QListWidget(::QListWidget *w) noexcept {
  ::QWidget *(*toQWidget_QListWidget$)(::QListWidget *) = ::toQWidget_QListWidget;
  return toQWidget_QListWidget$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QMainWindow(::QMainWindow *w) noexcept {
  ::QWidget *(*toQWidget_QMainWindow$)(::QMainWindow *) = ::toQWidget_QMainWindow;
  return toQWidget_QMainWindow$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QToolBar(::QToolBar *toolbar) noexcept {
  ::QWidget *(*toQWidget_QToolBar$)(::QToolBar *) = ::toQWidget_QToolBar;
  return toQWidget_QToolBar$(toolbar);
}

::QWidget *cxxbridge1$205$toQWidget_QStatusBar(::QStatusBar *bar) noexcept {
  ::QWidget *(*toQWidget_QStatusBar$)(::QStatusBar *) = ::toQWidget_QStatusBar;
  return toQWidget_QStatusBar$(bar);
}

::QWidget *cxxbridge1$205$toQWidget_QMessageBox(::QMessageBox *w) noexcept {
  ::QWidget *(*toQWidget_QMessageBox$)(::QMessageBox *) = ::toQWidget_QMessageBox;
  return toQWidget_QMessageBox$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QProgressDialog(::QProgressDialog *w) noexcept {
  ::QWidget *(*toQWidget_QProgressDialog$)(::QProgressDialog *) = ::toQWidget_QProgressDialog;
  return toQWidget_QProgressDialog$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QTableWidget(::QTableWidget *w) noexcept {
  ::QWidget *(*toQWidget_QTableWidget$)(::QTableWidget *) = ::toQWidget_QTableWidget;
  return toQWidget_QTableWidget$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QTreeWidget(::QTreeWidget *w) noexcept {
  ::QWidget *(*toQWidget_QTreeWidget$)(::QTreeWidget *) = ::toQWidget_QTreeWidget;
  return toQWidget_QTreeWidget$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QScrollArea(::QScrollArea *w) noexcept {
  ::QWidget *(*toQWidget_QScrollArea$)(::QScrollArea *) = ::toQWidget_QScrollArea;
  return toQWidget_QScrollArea$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QStackedWidget(::QStackedWidget *w) noexcept {
  ::QWidget *(*toQWidget_QStackedWidget$)(::QStackedWidget *) = ::toQWidget_QStackedWidget;
  return toQWidget_QStackedWidget$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QSplitter(::QSplitter *w) noexcept {
  ::QWidget *(*toQWidget_QSplitter$)(::QSplitter *) = ::toQWidget_QSplitter;
  return toQWidget_QSplitter$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QDateEdit(::QDateEdit *w) noexcept {
  ::QWidget *(*toQWidget_QDateEdit$)(::QDateEdit *) = ::toQWidget_QDateEdit;
  return toQWidget_QDateEdit$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QTimeEdit(::QTimeEdit *w) noexcept {
  ::QWidget *(*toQWidget_QTimeEdit$)(::QTimeEdit *) = ::toQWidget_QTimeEdit;
  return toQWidget_QTimeEdit$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QDateTimeEdit(::QDateTimeEdit *w) noexcept {
  ::QWidget *(*toQWidget_QDateTimeEdit$)(::QDateTimeEdit *) = ::toQWidget_QDateTimeEdit;
  return toQWidget_QDateTimeEdit$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QPlainTextEdit(::QPlainTextEdit *w) noexcept {
  ::QWidget *(*toQWidget_QPlainTextEdit$)(::QPlainTextEdit *) = ::toQWidget_QPlainTextEdit;
  return toQWidget_QPlainTextEdit$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QTextBrowser(::QTextBrowser *w) noexcept {
  ::QWidget *(*toQWidget_QTextBrowser$)(::QTextBrowser *) = ::toQWidget_QTextBrowser;
  return toQWidget_QTextBrowser$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QFrame(::QFrame *w) noexcept {
  ::QWidget *(*toQWidget_QFrame$)(::QFrame *) = ::toQWidget_QFrame;
  return toQWidget_QFrame$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QToolButton(::QToolButton *btn) noexcept {
  ::QWidget *(*toQWidget_QToolButton$)(::QToolButton *) = ::toQWidget_QToolButton;
  return toQWidget_QToolButton$(btn);
}

::QWidget *cxxbridge1$205$toQWidget_QCalendarWidget(::QCalendarWidget *cal) noexcept {
  ::QWidget *(*toQWidget_QCalendarWidget$)(::QCalendarWidget *) = ::toQWidget_QCalendarWidget;
  return toQWidget_QCalendarWidget$(cal);
}

::QProgressBar *cxxbridge1$205$QProgressBar_new(::QWidget *parent) noexcept {
  ::QProgressBar *(*QProgressBar_new$)(::QWidget *) = ::QProgressBar_new;
  return QProgressBar_new$(parent);
}

void cxxbridge1$205$QProgressBar_setValue(::QProgressBar *bar, ::std::int32_t value) noexcept {
  void (*QProgressBar_setValue$)(::QProgressBar *, ::std::int32_t) = ::QProgressBar_setValue;
  QProgressBar_setValue$(bar, value);
}

::std::int32_t cxxbridge1$205$QProgressBar_value(::QProgressBar *bar) noexcept {
  ::std::int32_t (*QProgressBar_value$)(::QProgressBar *) = ::QProgressBar_value;
  return QProgressBar_value$(bar);
}

void cxxbridge1$205$QProgressBar_setRange(::QProgressBar *bar, ::std::int32_t min, ::std::int32_t max) noexcept {
  void (*QProgressBar_setRange$)(::QProgressBar *, ::std::int32_t, ::std::int32_t) = ::QProgressBar_setRange;
  QProgressBar_setRange$(bar, min, max);
}

void cxxbridge1$205$QProgressBar_setMinimum(::QProgressBar *bar, ::std::int32_t min) noexcept {
  void (*QProgressBar_setMinimum$)(::QProgressBar *, ::std::int32_t) = ::QProgressBar_setMinimum;
  QProgressBar_setMinimum$(bar, min);
}

void cxxbridge1$205$QProgressBar_setMaximum(::QProgressBar *bar, ::std::int32_t max) noexcept {
  void (*QProgressBar_setMaximum$)(::QProgressBar *, ::std::int32_t) = ::QProgressBar_setMaximum;
  QProgressBar_setMaximum$(bar, max);
}

void cxxbridge1$205$QProgressBar_setFormat(::QProgressBar *bar, ::std::string const &format) noexcept {
  void (*QProgressBar_setFormat$)(::QProgressBar *, ::std::string const &) = ::QProgressBar_setFormat;
  QProgressBar_setFormat$(bar, format);
}

void cxxbridge1$205$QProgressBar_delete(::QProgressBar *bar) noexcept {
  void (*QProgressBar_delete$)(::QProgressBar *) = ::QProgressBar_delete;
  QProgressBar_delete$(bar);
}

::QProgressDialog *cxxbridge1$205$QProgressDialog_new(::std::string const &label, ::std::string const &cancelText, ::std::int32_t min, ::std::int32_t max, ::QWidget *parent) noexcept {
  ::QProgressDialog *(*QProgressDialog_new$)(::std::string const &, ::std::string const &, ::std::int32_t, ::std::int32_t, ::QWidget *) = ::QProgressDialog_new;
  return QProgressDialog_new$(label, cancelText, min, max, parent);
}

void cxxbridge1$205$QProgressDialog_delete(::QProgressDialog *w) noexcept {
  void (*QProgressDialog_delete$)(::QProgressDialog *) = ::QProgressDialog_delete;
  QProgressDialog_delete$(w);
}

void cxxbridge1$205$QProgressDialog_setMinimum(::QProgressDialog *w, ::std::int32_t min) noexcept {
  void (*QProgressDialog_setMinimum$)(::QProgressDialog *, ::std::int32_t) = ::QProgressDialog_setMinimum;
  QProgressDialog_setMinimum$(w, min);
}

void cxxbridge1$205$QProgressDialog_setMaximum(::QProgressDialog *w, ::std::int32_t max) noexcept {
  void (*QProgressDialog_setMaximum$)(::QProgressDialog *, ::std::int32_t) = ::QProgressDialog_setMaximum;
  QProgressDialog_setMaximum$(w, max);
}

void cxxbridge1$205$QProgressDialog_setRange(::QProgressDialog *w, ::std::int32_t min, ::std::int32_t max) noexcept {
  void (*QProgressDialog_setRange$)(::QProgressDialog *, ::std::int32_t, ::std::int32_t) = ::QProgressDialog_setRange;
  QProgressDialog_setRange$(w, min, max);
}

void cxxbridge1$205$QProgressDialog_setValue(::QProgressDialog *w, ::std::int32_t value) noexcept {
  void (*QProgressDialog_setValue$)(::QProgressDialog *, ::std::int32_t) = ::QProgressDialog_setValue;
  QProgressDialog_setValue$(w, value);
}

::std::int32_t cxxbridge1$205$QProgressDialog_value(::QProgressDialog *w) noexcept {
  ::std::int32_t (*QProgressDialog_value$)(::QProgressDialog *) = ::QProgressDialog_value;
  return QProgressDialog_value$(w);
}

void cxxbridge1$205$QProgressDialog_setLabelText(::QProgressDialog *w, ::std::string const &text) noexcept {
  void (*QProgressDialog_setLabelText$)(::QProgressDialog *, ::std::string const &) = ::QProgressDialog_setLabelText;
  QProgressDialog_setLabelText$(w, text);
}

void cxxbridge1$205$QProgressDialog_setCancelButtonText(::QProgressDialog *w, ::std::string const &text) noexcept {
  void (*QProgressDialog_setCancelButtonText$)(::QProgressDialog *, ::std::string const &) = ::QProgressDialog_setCancelButtonText;
  QProgressDialog_setCancelButtonText$(w, text);
}

bool cxxbridge1$205$QProgressDialog_wasCanceled(::QProgressDialog *w) noexcept {
  bool (*QProgressDialog_wasCanceled$)(::QProgressDialog *) = ::QProgressDialog_wasCanceled;
  return QProgressDialog_wasCanceled$(w);
}

void cxxbridge1$205$QProgressDialog_setMinimumDuration(::QProgressDialog *w, ::std::int32_t ms) noexcept {
  void (*QProgressDialog_setMinimumDuration$)(::QProgressDialog *, ::std::int32_t) = ::QProgressDialog_setMinimumDuration;
  QProgressDialog_setMinimumDuration$(w, ms);
}

void cxxbridge1$205$QProgressDialog_setAutoClose(::QProgressDialog *w, bool close) noexcept {
  void (*QProgressDialog_setAutoClose$)(::QProgressDialog *, bool) = ::QProgressDialog_setAutoClose;
  QProgressDialog_setAutoClose$(w, close);
}

void cxxbridge1$205$QProgressDialog_setAutoReset(::QProgressDialog *w, bool reset) noexcept {
  void (*QProgressDialog_setAutoReset$)(::QProgressDialog *, bool) = ::QProgressDialog_setAutoReset;
  QProgressDialog_setAutoReset$(w, reset);
}

void cxxbridge1$205$QProgressDialog_show(::QProgressDialog *w) noexcept {
  void (*QProgressDialog_show$)(::QProgressDialog *) = ::QProgressDialog_show;
  QProgressDialog_show$(w);
}

void cxxbridge1$205$QProgressDialog_hide(::QProgressDialog *w) noexcept {
  void (*QProgressDialog_hide$)(::QProgressDialog *) = ::QProgressDialog_hide;
  QProgressDialog_hide$(w);
}

void cxxbridge1$205$QProgressDialog_close(::QProgressDialog *w) noexcept {
  void (*QProgressDialog_close$)(::QProgressDialog *) = ::QProgressDialog_close;
  QProgressDialog_close$(w);
}

::QPushButton *cxxbridge1$205$QPushButton_new(::std::string const &text, ::QWidget *parent) noexcept {
  ::QPushButton *(*QPushButton_new$)(::std::string const &, ::QWidget *) = ::QPushButton_new;
  return QPushButton_new$(text, parent);
}

void cxxbridge1$205$QPushButton_show(::QPushButton *btn) noexcept {
  void (*QPushButton_show$)(::QPushButton *) = ::QPushButton_show;
  QPushButton_show$(btn);
}

void cxxbridge1$205$QPushButton_setText(::QPushButton *btn, ::std::string const &text) noexcept {
  void (*QPushButton_setText$)(::QPushButton *, ::std::string const &) = ::QPushButton_setText;
  QPushButton_setText$(btn, text);
}

void cxxbridge1$205$QPushButton_delete(::QPushButton *btn) noexcept {
  void (*QPushButton_delete$)(::QPushButton *) = ::QPushButton_delete;
  QPushButton_delete$(btn);
}

void cxxbridge1$205$QPushButton_setIcon(::QPushButton *btn, ::std::string const &path) noexcept {
  void (*QPushButton_setIcon$)(::QPushButton *, ::std::string const &) = ::QPushButton_setIcon;
  QPushButton_setIcon$(btn, path);
}

void cxxbridge1$205$QPushButton_setFlat(::QPushButton *btn, bool flat) noexcept {
  void (*QPushButton_setFlat$)(::QPushButton *, bool) = ::QPushButton_setFlat;
  QPushButton_setFlat$(btn, flat);
}

bool cxxbridge1$205$QPushButton_isFlat(::QPushButton *btn) noexcept {
  bool (*QPushButton_isFlat$)(::QPushButton *) = ::QPushButton_isFlat;
  return QPushButton_isFlat$(btn);
}

void cxxbridge1$205$QPushButton_setDefault(::QPushButton *btn, bool def) noexcept {
  void (*QPushButton_setDefault$)(::QPushButton *, bool) = ::QPushButton_setDefault;
  QPushButton_setDefault$(btn, def);
}

void cxxbridge1$205$QPushButton_setAutoDefault(::QPushButton *btn, bool def) noexcept {
  void (*QPushButton_setAutoDefault$)(::QPushButton *, bool) = ::QPushButton_setAutoDefault;
  QPushButton_setAutoDefault$(btn, def);
}

void cxxbridge1$205$QPushButton_onClicked(::QPushButton *btn, ::std::uint64_t ctx) noexcept {
  void (*QPushButton_onClicked$)(::QPushButton *, ::std::uint64_t) = ::QPushButton_onClicked;
  QPushButton_onClicked$(btn, ctx);
}

::QRadioButton *cxxbridge1$205$QRadioButton_new(::std::string const &text, ::QWidget *parent) noexcept {
  ::QRadioButton *(*QRadioButton_new$)(::std::string const &, ::QWidget *) = ::QRadioButton_new;
  return QRadioButton_new$(text, parent);
}

bool cxxbridge1$205$QRadioButton_isChecked(::QRadioButton *rb) noexcept {
  bool (*QRadioButton_isChecked$)(::QRadioButton *) = ::QRadioButton_isChecked;
  return QRadioButton_isChecked$(rb);
}

void cxxbridge1$205$QRadioButton_setChecked(::QRadioButton *rb, bool checked) noexcept {
  void (*QRadioButton_setChecked$)(::QRadioButton *, bool) = ::QRadioButton_setChecked;
  QRadioButton_setChecked$(rb, checked);
}

void cxxbridge1$205$QRadioButton_delete(::QRadioButton *rb) noexcept {
  void (*QRadioButton_delete$)(::QRadioButton *) = ::QRadioButton_delete;
  QRadioButton_delete$(rb);
}

void cxxbridge1$205$QRadioButton_onToggled(::QRadioButton *rb, ::std::uint64_t ctx) noexcept {
  void (*QRadioButton_onToggled$)(::QRadioButton *, ::std::uint64_t) = ::QRadioButton_onToggled;
  QRadioButton_onToggled$(rb, ctx);
}

::QScrollArea *cxxbridge1$205$QScrollArea_new(::QWidget *parent) noexcept {
  ::QScrollArea *(*QScrollArea_new$)(::QWidget *) = ::QScrollArea_new;
  return QScrollArea_new$(parent);
}

void cxxbridge1$205$QScrollArea_delete(::QScrollArea *w) noexcept {
  void (*QScrollArea_delete$)(::QScrollArea *) = ::QScrollArea_delete;
  QScrollArea_delete$(w);
}

void cxxbridge1$205$QScrollArea_setWidget(::QScrollArea *w, ::QWidget *widget) noexcept {
  void (*QScrollArea_setWidget$)(::QScrollArea *, ::QWidget *) = ::QScrollArea_setWidget;
  QScrollArea_setWidget$(w, widget);
}

::QWidget *cxxbridge1$205$QScrollArea_takeWidget(::QScrollArea *w) noexcept {
  ::QWidget *(*QScrollArea_takeWidget$)(::QScrollArea *) = ::QScrollArea_takeWidget;
  return QScrollArea_takeWidget$(w);
}

void cxxbridge1$205$QScrollArea_setWidgetResizable(::QScrollArea *w, bool resizable) noexcept {
  void (*QScrollArea_setWidgetResizable$)(::QScrollArea *, bool) = ::QScrollArea_setWidgetResizable;
  QScrollArea_setWidgetResizable$(w, resizable);
}

void cxxbridge1$205$QScrollArea_setHorizontalScrollBarPolicy(::QScrollArea *w, ::std::int32_t policy) noexcept {
  void (*QScrollArea_setHorizontalScrollBarPolicy$)(::QScrollArea *, ::std::int32_t) = ::QScrollArea_setHorizontalScrollBarPolicy;
  QScrollArea_setHorizontalScrollBarPolicy$(w, policy);
}

void cxxbridge1$205$QScrollArea_setVerticalScrollBarPolicy(::QScrollArea *w, ::std::int32_t policy) noexcept {
  void (*QScrollArea_setVerticalScrollBarPolicy$)(::QScrollArea *, ::std::int32_t) = ::QScrollArea_setVerticalScrollBarPolicy;
  QScrollArea_setVerticalScrollBarPolicy$(w, policy);
}

void cxxbridge1$205$QScrollArea_ensureVisible(::QScrollArea *w, ::std::int32_t x, ::std::int32_t y) noexcept {
  void (*QScrollArea_ensureVisible$)(::QScrollArea *, ::std::int32_t, ::std::int32_t) = ::QScrollArea_ensureVisible;
  QScrollArea_ensureVisible$(w, x, y);
}

void cxxbridge1$205$QScrollArea_ensureWidgetVisible(::QScrollArea *w, ::QWidget *widget) noexcept {
  void (*QScrollArea_ensureWidgetVisible$)(::QScrollArea *, ::QWidget *) = ::QScrollArea_ensureWidgetVisible;
  QScrollArea_ensureWidgetVisible$(w, widget);
}

::QSettings *cxxbridge1$205$QSettings_new_user_app(::rust::String const &org, ::rust::String const &app) noexcept {
  ::QSettings *(*QSettings_new_user_app$)(::rust::String const &, ::rust::String const &) = ::QSettings_new_user_app;
  return QSettings_new_user_app$(org, app);
}

::QSettings *cxxbridge1$205$QSettings_new_scope_app(::std::int32_t scope, ::rust::String const &org, ::rust::String const &app) noexcept {
  ::QSettings *(*QSettings_new_scope_app$)(::std::int32_t, ::rust::String const &, ::rust::String const &) = ::QSettings_new_scope_app;
  return QSettings_new_scope_app$(scope, org, app);
}

::QSettings *cxxbridge1$205$QSettings_new_format_scope(::std::int32_t format, ::std::int32_t scope, ::rust::String const &org, ::rust::String const &app) noexcept {
  ::QSettings *(*QSettings_new_format_scope$)(::std::int32_t, ::std::int32_t, ::rust::String const &, ::rust::String const &) = ::QSettings_new_format_scope;
  return QSettings_new_format_scope$(format, scope, org, app);
}

::QSettings *cxxbridge1$205$QSettings_new_file(::rust::String const &fileName, ::std::int32_t format) noexcept {
  ::QSettings *(*QSettings_new_file$)(::rust::String const &, ::std::int32_t) = ::QSettings_new_file;
  return QSettings_new_file$(fileName, format);
}

void cxxbridge1$205$QSettings_delete(::QSettings *s) noexcept {
  void (*QSettings_delete$)(::QSettings *) = ::QSettings_delete;
  QSettings_delete$(s);
}

void cxxbridge1$205$QSettings_beginGroup(::QSettings *s, ::rust::String const &prefix) noexcept {
  void (*QSettings_beginGroup$)(::QSettings *, ::rust::String const &) = ::QSettings_beginGroup;
  QSettings_beginGroup$(s, prefix);
}

void cxxbridge1$205$QSettings_endGroup(::QSettings *s) noexcept {
  void (*QSettings_endGroup$)(::QSettings *) = ::QSettings_endGroup;
  QSettings_endGroup$(s);
}

void cxxbridge1$205$QSettings_group(::QSettings *s, ::rust::String *return$) noexcept {
  ::rust::String (*QSettings_group$)(::QSettings *) = ::QSettings_group;
  new (return$) ::rust::String(QSettings_group$(s));
}

::std::int32_t cxxbridge1$205$QSettings_beginReadArray(::QSettings *s, ::rust::String const &prefix) noexcept {
  ::std::int32_t (*QSettings_beginReadArray$)(::QSettings *, ::rust::String const &) = ::QSettings_beginReadArray;
  return QSettings_beginReadArray$(s, prefix);
}

void cxxbridge1$205$QSettings_beginWriteArray(::QSettings *s, ::rust::String const &prefix, ::std::int32_t size) noexcept {
  void (*QSettings_beginWriteArray$)(::QSettings *, ::rust::String const &, ::std::int32_t) = ::QSettings_beginWriteArray;
  QSettings_beginWriteArray$(s, prefix, size);
}

void cxxbridge1$205$QSettings_endArray(::QSettings *s) noexcept {
  void (*QSettings_endArray$)(::QSettings *) = ::QSettings_endArray;
  QSettings_endArray$(s);
}

void cxxbridge1$205$QSettings_setArrayIndex(::QSettings *s, ::std::int32_t i) noexcept {
  void (*QSettings_setArrayIndex$)(::QSettings *, ::std::int32_t) = ::QSettings_setArrayIndex;
  QSettings_setArrayIndex$(s, i);
}

::QVariant *cxxbridge1$205$QSettings_value(::QSettings *s, ::rust::String const &key, ::QVariant *default_value) noexcept {
  ::QVariant *(*QSettings_value$)(::QSettings *, ::rust::String const &, ::QVariant *) = ::QSettings_value;
  return QSettings_value$(s, key, default_value);
}

void cxxbridge1$205$QSettings_setValue(::QSettings *s, ::rust::String const &key, ::QVariant *value) noexcept {
  void (*QSettings_setValue$)(::QSettings *, ::rust::String const &, ::QVariant *) = ::QSettings_setValue;
  QSettings_setValue$(s, key, value);
}

bool cxxbridge1$205$QSettings_contains(::QSettings *s, ::rust::String const &key) noexcept {
  bool (*QSettings_contains$)(::QSettings *, ::rust::String const &) = ::QSettings_contains;
  return QSettings_contains$(s, key);
}

void cxxbridge1$205$QSettings_remove(::QSettings *s, ::rust::String const &key) noexcept {
  void (*QSettings_remove$)(::QSettings *, ::rust::String const &) = ::QSettings_remove;
  QSettings_remove$(s, key);
}

void cxxbridge1$205$QSettings_sync(::QSettings *s) noexcept {
  void (*QSettings_sync$)(::QSettings *) = ::QSettings_sync;
  QSettings_sync$(s);
}

void cxxbridge1$205$QSettings_clear(::QSettings *s) noexcept {
  void (*QSettings_clear$)(::QSettings *) = ::QSettings_clear;
  QSettings_clear$(s);
}

bool cxxbridge1$205$QSettings_isWritable(::QSettings *s) noexcept {
  bool (*QSettings_isWritable$)(::QSettings *) = ::QSettings_isWritable;
  return QSettings_isWritable$(s);
}

::std::int32_t cxxbridge1$205$QSettings_status(::QSettings *s) noexcept {
  ::std::int32_t (*QSettings_status$)(::QSettings *) = ::QSettings_status;
  return QSettings_status$(s);
}

void cxxbridge1$205$QSettings_allKeys(::QSettings *s, ::rust::Vec<::rust::String> *return$) noexcept {
  ::rust::Vec<::rust::String> (*QSettings_allKeys$)(::QSettings *) = ::QSettings_allKeys;
  new (return$) ::rust::Vec<::rust::String>(QSettings_allKeys$(s));
}

void cxxbridge1$205$QSettings_childKeys(::QSettings *s, ::rust::Vec<::rust::String> *return$) noexcept {
  ::rust::Vec<::rust::String> (*QSettings_childKeys$)(::QSettings *) = ::QSettings_childKeys;
  new (return$) ::rust::Vec<::rust::String>(QSettings_childKeys$(s));
}

void cxxbridge1$205$QSettings_childGroups(::QSettings *s, ::rust::Vec<::rust::String> *return$) noexcept {
  ::rust::Vec<::rust::String> (*QSettings_childGroups$)(::QSettings *) = ::QSettings_childGroups;
  new (return$) ::rust::Vec<::rust::String>(QSettings_childGroups$(s));
}

void cxxbridge1$205$QSettings_fileName(::QSettings *s, ::rust::String *return$) noexcept {
  ::rust::String (*QSettings_fileName$)(::QSettings *) = ::QSettings_fileName;
  new (return$) ::rust::String(QSettings_fileName$(s));
}

bool cxxbridge1$205$QSettings_fallbacksEnabled(::QSettings *s) noexcept {
  bool (*QSettings_fallbacksEnabled$)(::QSettings *) = ::QSettings_fallbacksEnabled;
  return QSettings_fallbacksEnabled$(s);
}

void cxxbridge1$205$QSettings_setFallbacksEnabled(::QSettings *s, bool enabled) noexcept {
  void (*QSettings_setFallbacksEnabled$)(::QSettings *, bool) = ::QSettings_setFallbacksEnabled;
  QSettings_setFallbacksEnabled$(s, enabled);
}

::QSlider *cxxbridge1$205$QSlider_new(::std::int32_t orientation, ::QWidget *parent) noexcept {
  ::QSlider *(*QSlider_new$)(::std::int32_t, ::QWidget *) = ::QSlider_new;
  return QSlider_new$(orientation, parent);
}

::std::int32_t cxxbridge1$205$QSlider_value(::QSlider *s) noexcept {
  ::std::int32_t (*QSlider_value$)(::QSlider *) = ::QSlider_value;
  return QSlider_value$(s);
}

void cxxbridge1$205$QSlider_setValue(::QSlider *s, ::std::int32_t value) noexcept {
  void (*QSlider_setValue$)(::QSlider *, ::std::int32_t) = ::QSlider_setValue;
  QSlider_setValue$(s, value);
}

void cxxbridge1$205$QSlider_setRange(::QSlider *s, ::std::int32_t min, ::std::int32_t max) noexcept {
  void (*QSlider_setRange$)(::QSlider *, ::std::int32_t, ::std::int32_t) = ::QSlider_setRange;
  QSlider_setRange$(s, min, max);
}

void cxxbridge1$205$QSlider_setOrientation(::QSlider *s, ::std::int32_t o) noexcept {
  void (*QSlider_setOrientation$)(::QSlider *, ::std::int32_t) = ::QSlider_setOrientation;
  QSlider_setOrientation$(s, o);
}

::std::int32_t cxxbridge1$205$QSlider_orientation(::QSlider *s) noexcept {
  ::std::int32_t (*QSlider_orientation$)(::QSlider *) = ::QSlider_orientation;
  return QSlider_orientation$(s);
}

void cxxbridge1$205$QSlider_setTickPosition(::QSlider *s, ::std::int32_t pos) noexcept {
  void (*QSlider_setTickPosition$)(::QSlider *, ::std::int32_t) = ::QSlider_setTickPosition;
  QSlider_setTickPosition$(s, pos);
}

void cxxbridge1$205$QSlider_setTickInterval(::QSlider *s, ::std::int32_t interval) noexcept {
  void (*QSlider_setTickInterval$)(::QSlider *, ::std::int32_t) = ::QSlider_setTickInterval;
  QSlider_setTickInterval$(s, interval);
}

bool cxxbridge1$205$QSlider_invertedAppearance(::QSlider *s) noexcept {
  bool (*QSlider_invertedAppearance$)(::QSlider *) = ::QSlider_invertedAppearance;
  return QSlider_invertedAppearance$(s);
}

void cxxbridge1$205$QSlider_delete(::QSlider *s) noexcept {
  void (*QSlider_delete$)(::QSlider *) = ::QSlider_delete;
  QSlider_delete$(s);
}

void cxxbridge1$205$QSlider_onValueChanged(::QSlider *s, ::std::uint64_t ctx) noexcept {
  void (*QSlider_onValueChanged$)(::QSlider *, ::std::uint64_t) = ::QSlider_onValueChanged;
  QSlider_onValueChanged$(s, ctx);
}

::QSpacerItem *cxxbridge1$205$QSpacerItem_new(::std::int32_t w, ::std::int32_t h, ::std::int32_t hPolicy, ::std::int32_t vPolicy) noexcept {
  ::QSpacerItem *(*QSpacerItem_new$)(::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QSpacerItem_new;
  return QSpacerItem_new$(w, h, hPolicy, vPolicy);
}

void cxxbridge1$205$QSpacerItem_delete(::QSpacerItem *s) noexcept {
  void (*QSpacerItem_delete$)(::QSpacerItem *) = ::QSpacerItem_delete;
  QSpacerItem_delete$(s);
}

void cxxbridge1$205$QSpacerItem_changeSize(::QSpacerItem *s, ::std::int32_t w, ::std::int32_t h, ::std::int32_t hPolicy, ::std::int32_t vPolicy) noexcept {
  void (*QSpacerItem_changeSize$)(::QSpacerItem *, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QSpacerItem_changeSize;
  QSpacerItem_changeSize$(s, w, h, hPolicy, vPolicy);
}

::QSpinBox *cxxbridge1$205$QSpinBox_new(::QWidget *parent) noexcept {
  ::QSpinBox *(*QSpinBox_new$)(::QWidget *) = ::QSpinBox_new;
  return QSpinBox_new$(parent);
}

void cxxbridge1$205$QSpinBox_setValue(::QSpinBox *sb, ::std::int32_t value) noexcept {
  void (*QSpinBox_setValue$)(::QSpinBox *, ::std::int32_t) = ::QSpinBox_setValue;
  QSpinBox_setValue$(sb, value);
}

::std::int32_t cxxbridge1$205$QSpinBox_value(::QSpinBox *sb) noexcept {
  ::std::int32_t (*QSpinBox_value$)(::QSpinBox *) = ::QSpinBox_value;
  return QSpinBox_value$(sb);
}

void cxxbridge1$205$QSpinBox_setRange(::QSpinBox *sb, ::std::int32_t min, ::std::int32_t max) noexcept {
  void (*QSpinBox_setRange$)(::QSpinBox *, ::std::int32_t, ::std::int32_t) = ::QSpinBox_setRange;
  QSpinBox_setRange$(sb, min, max);
}

void cxxbridge1$205$QSpinBox_setSuffix(::QSpinBox *sb, ::std::string const &suffix) noexcept {
  void (*QSpinBox_setSuffix$)(::QSpinBox *, ::std::string const &) = ::QSpinBox_setSuffix;
  QSpinBox_setSuffix$(sb, suffix);
}

void cxxbridge1$205$QSpinBox_setPrefix(::QSpinBox *sb, ::std::string const &prefix) noexcept {
  void (*QSpinBox_setPrefix$)(::QSpinBox *, ::std::string const &) = ::QSpinBox_setPrefix;
  QSpinBox_setPrefix$(sb, prefix);
}

void cxxbridge1$205$QSpinBox_delete(::QSpinBox *sb) noexcept {
  void (*QSpinBox_delete$)(::QSpinBox *) = ::QSpinBox_delete;
  QSpinBox_delete$(sb);
}

void cxxbridge1$205$QSpinBox_onValueChanged(::QSpinBox *sb, ::std::uint64_t ctx) noexcept {
  void (*QSpinBox_onValueChanged$)(::QSpinBox *, ::std::uint64_t) = ::QSpinBox_onValueChanged;
  QSpinBox_onValueChanged$(sb, ctx);
}

::QSplitter *cxxbridge1$205$QSplitter_new(::std::int32_t orientation, ::QWidget *parent) noexcept {
  ::QSplitter *(*QSplitter_new$)(::std::int32_t, ::QWidget *) = ::QSplitter_new;
  return QSplitter_new$(orientation, parent);
}

void cxxbridge1$205$QSplitter_delete(::QSplitter *w) noexcept {
  void (*QSplitter_delete$)(::QSplitter *) = ::QSplitter_delete;
  QSplitter_delete$(w);
}

void cxxbridge1$205$QSplitter_addWidget(::QSplitter *w, ::QWidget *widget) noexcept {
  void (*QSplitter_addWidget$)(::QSplitter *, ::QWidget *) = ::QSplitter_addWidget;
  QSplitter_addWidget$(w, widget);
}

void cxxbridge1$205$QSplitter_insertWidget(::QSplitter *w, ::std::int32_t index, ::QWidget *widget) noexcept {
  void (*QSplitter_insertWidget$)(::QSplitter *, ::std::int32_t, ::QWidget *) = ::QSplitter_insertWidget;
  QSplitter_insertWidget$(w, index, widget);
}

void cxxbridge1$205$QSplitter_setStretchFactor(::QSplitter *w, ::std::int32_t index, ::std::int32_t stretch) noexcept {
  void (*QSplitter_setStretchFactor$)(::QSplitter *, ::std::int32_t, ::std::int32_t) = ::QSplitter_setStretchFactor;
  QSplitter_setStretchFactor$(w, index, stretch);
}

void cxxbridge1$205$QSplitter_setSizes(::QSplitter *w, ::rust::Vec<::std::int32_t> const *sizes) noexcept {
  void (*QSplitter_setSizes$)(::QSplitter *, ::rust::Vec<::std::int32_t>) = ::QSplitter_setSizes;
  QSplitter_setSizes$(w, ::rust::Vec<::std::int32_t>(::rust::unsafe_bitcopy, *sizes));
}

void cxxbridge1$205$QSplitter_sizes(::QSplitter *w, ::rust::Vec<::std::int32_t> *return$) noexcept {
  ::rust::Vec<::std::int32_t> (*QSplitter_sizes$)(::QSplitter *) = ::QSplitter_sizes;
  new (return$) ::rust::Vec<::std::int32_t>(QSplitter_sizes$(w));
}

void cxxbridge1$205$QSplitter_setOrientation(::QSplitter *w, ::std::int32_t orientation) noexcept {
  void (*QSplitter_setOrientation$)(::QSplitter *, ::std::int32_t) = ::QSplitter_setOrientation;
  QSplitter_setOrientation$(w, orientation);
}

::std::int32_t cxxbridge1$205$QSplitter_count(::QSplitter *w) noexcept {
  ::std::int32_t (*QSplitter_count$)(::QSplitter *) = ::QSplitter_count;
  return QSplitter_count$(w);
}

void cxxbridge1$205$QSplitter_setHandleWidth(::QSplitter *w, ::std::int32_t width) noexcept {
  void (*QSplitter_setHandleWidth$)(::QSplitter *, ::std::int32_t) = ::QSplitter_setHandleWidth;
  QSplitter_setHandleWidth$(w, width);
}

void cxxbridge1$205$QSplitter_setChildrenCollapsible(::QSplitter *w, bool collapsible) noexcept {
  void (*QSplitter_setChildrenCollapsible$)(::QSplitter *, bool) = ::QSplitter_setChildrenCollapsible;
  QSplitter_setChildrenCollapsible$(w, collapsible);
}

::QDateEdit *cxxbridge1$205$QDateEdit_new(::QWidget *parent) noexcept {
  ::QDateEdit *(*QDateEdit_new$)(::QWidget *) = ::QDateEdit_new;
  return QDateEdit_new$(parent);
}

void cxxbridge1$205$QDateEdit_delete(::QDateEdit *w) noexcept {
  void (*QDateEdit_delete$)(::QDateEdit *) = ::QDateEdit_delete;
  QDateEdit_delete$(w);
}

void cxxbridge1$205$QDateEdit_setDate(::QDateEdit *w, ::std::string const &date) noexcept {
  void (*QDateEdit_setDate$)(::QDateEdit *, ::std::string const &) = ::QDateEdit_setDate;
  QDateEdit_setDate$(w, date);
}

void cxxbridge1$205$QDateEdit_date(::QDateEdit *w, ::rust::String *return$) noexcept {
  ::rust::String (*QDateEdit_date$)(::QDateEdit *) = ::QDateEdit_date;
  new (return$) ::rust::String(QDateEdit_date$(w));
}

void cxxbridge1$205$QDateEdit_setMinimumDate(::QDateEdit *w, ::std::string const &date) noexcept {
  void (*QDateEdit_setMinimumDate$)(::QDateEdit *, ::std::string const &) = ::QDateEdit_setMinimumDate;
  QDateEdit_setMinimumDate$(w, date);
}

void cxxbridge1$205$QDateEdit_setMaximumDate(::QDateEdit *w, ::std::string const &date) noexcept {
  void (*QDateEdit_setMaximumDate$)(::QDateEdit *, ::std::string const &) = ::QDateEdit_setMaximumDate;
  QDateEdit_setMaximumDate$(w, date);
}

void cxxbridge1$205$QDateEdit_clearMinimumDate(::QDateEdit *w) noexcept {
  void (*QDateEdit_clearMinimumDate$)(::QDateEdit *) = ::QDateEdit_clearMinimumDate;
  QDateEdit_clearMinimumDate$(w);
}

void cxxbridge1$205$QDateEdit_clearMaximumDate(::QDateEdit *w) noexcept {
  void (*QDateEdit_clearMaximumDate$)(::QDateEdit *) = ::QDateEdit_clearMaximumDate;
  QDateEdit_clearMaximumDate$(w);
}

void cxxbridge1$205$QDateEdit_setDisplayFormat(::QDateEdit *w, ::std::string const &format) noexcept {
  void (*QDateEdit_setDisplayFormat$)(::QDateEdit *, ::std::string const &) = ::QDateEdit_setDisplayFormat;
  QDateEdit_setDisplayFormat$(w, format);
}

void cxxbridge1$205$QDateEdit_setCalendarPopup(::QDateEdit *w, bool enabled) noexcept {
  void (*QDateEdit_setCalendarPopup$)(::QDateEdit *, bool) = ::QDateEdit_setCalendarPopup;
  QDateEdit_setCalendarPopup$(w, enabled);
}

void cxxbridge1$205$QDateEdit_onDateChanged(::QDateEdit *w, ::std::uint64_t ctx) noexcept {
  void (*QDateEdit_onDateChanged$)(::QDateEdit *, ::std::uint64_t) = ::QDateEdit_onDateChanged;
  QDateEdit_onDateChanged$(w, ctx);
}

::QTimeEdit *cxxbridge1$205$QTimeEdit_new(::QWidget *parent) noexcept {
  ::QTimeEdit *(*QTimeEdit_new$)(::QWidget *) = ::QTimeEdit_new;
  return QTimeEdit_new$(parent);
}

void cxxbridge1$205$QTimeEdit_delete(::QTimeEdit *w) noexcept {
  void (*QTimeEdit_delete$)(::QTimeEdit *) = ::QTimeEdit_delete;
  QTimeEdit_delete$(w);
}

void cxxbridge1$205$QTimeEdit_setTime(::QTimeEdit *w, ::std::string const &time) noexcept {
  void (*QTimeEdit_setTime$)(::QTimeEdit *, ::std::string const &) = ::QTimeEdit_setTime;
  QTimeEdit_setTime$(w, time);
}

void cxxbridge1$205$QTimeEdit_time(::QTimeEdit *w, ::rust::String *return$) noexcept {
  ::rust::String (*QTimeEdit_time$)(::QTimeEdit *) = ::QTimeEdit_time;
  new (return$) ::rust::String(QTimeEdit_time$(w));
}

void cxxbridge1$205$QTimeEdit_setDisplayFormat(::QTimeEdit *w, ::std::string const &format) noexcept {
  void (*QTimeEdit_setDisplayFormat$)(::QTimeEdit *, ::std::string const &) = ::QTimeEdit_setDisplayFormat;
  QTimeEdit_setDisplayFormat$(w, format);
}

void cxxbridge1$205$QTimeEdit_onTimeChanged(::QTimeEdit *w, ::std::uint64_t ctx) noexcept {
  void (*QTimeEdit_onTimeChanged$)(::QTimeEdit *, ::std::uint64_t) = ::QTimeEdit_onTimeChanged;
  QTimeEdit_onTimeChanged$(w, ctx);
}

::QDateTimeEdit *cxxbridge1$205$QDateTimeEdit_new(::QWidget *parent) noexcept {
  ::QDateTimeEdit *(*QDateTimeEdit_new$)(::QWidget *) = ::QDateTimeEdit_new;
  return QDateTimeEdit_new$(parent);
}

void cxxbridge1$205$QDateTimeEdit_delete(::QDateTimeEdit *w) noexcept {
  void (*QDateTimeEdit_delete$)(::QDateTimeEdit *) = ::QDateTimeEdit_delete;
  QDateTimeEdit_delete$(w);
}

void cxxbridge1$205$QDateTimeEdit_setDateTime(::QDateTimeEdit *w, ::std::string const &dt) noexcept {
  void (*QDateTimeEdit_setDateTime$)(::QDateTimeEdit *, ::std::string const &) = ::QDateTimeEdit_setDateTime;
  QDateTimeEdit_setDateTime$(w, dt);
}

void cxxbridge1$205$QDateTimeEdit_dateTime(::QDateTimeEdit *w, ::rust::String *return$) noexcept {
  ::rust::String (*QDateTimeEdit_dateTime$)(::QDateTimeEdit *) = ::QDateTimeEdit_dateTime;
  new (return$) ::rust::String(QDateTimeEdit_dateTime$(w));
}

void cxxbridge1$205$QDateTimeEdit_setDisplayFormat(::QDateTimeEdit *w, ::std::string const &format) noexcept {
  void (*QDateTimeEdit_setDisplayFormat$)(::QDateTimeEdit *, ::std::string const &) = ::QDateTimeEdit_setDisplayFormat;
  QDateTimeEdit_setDisplayFormat$(w, format);
}

void cxxbridge1$205$QDateTimeEdit_setCalendarPopup(::QDateTimeEdit *w, bool enabled) noexcept {
  void (*QDateTimeEdit_setCalendarPopup$)(::QDateTimeEdit *, bool) = ::QDateTimeEdit_setCalendarPopup;
  QDateTimeEdit_setCalendarPopup$(w, enabled);
}

void cxxbridge1$205$QDateTimeEdit_onDateTimeChanged(::QDateTimeEdit *w, ::std::uint64_t ctx) noexcept {
  void (*QDateTimeEdit_onDateTimeChanged$)(::QDateTimeEdit *, ::std::uint64_t) = ::QDateTimeEdit_onDateTimeChanged;
  QDateTimeEdit_onDateTimeChanged$(w, ctx);
}

::QPlainTextEdit *cxxbridge1$205$QPlainTextEdit_new(::QWidget *parent) noexcept {
  ::QPlainTextEdit *(*QPlainTextEdit_new$)(::QWidget *) = ::QPlainTextEdit_new;
  return QPlainTextEdit_new$(parent);
}

void cxxbridge1$205$QPlainTextEdit_delete(::QPlainTextEdit *w) noexcept {
  void (*QPlainTextEdit_delete$)(::QPlainTextEdit *) = ::QPlainTextEdit_delete;
  QPlainTextEdit_delete$(w);
}

void cxxbridge1$205$QPlainTextEdit_setPlainText(::QPlainTextEdit *w, ::std::string const &text) noexcept {
  void (*QPlainTextEdit_setPlainText$)(::QPlainTextEdit *, ::std::string const &) = ::QPlainTextEdit_setPlainText;
  QPlainTextEdit_setPlainText$(w, text);
}

void cxxbridge1$205$QPlainTextEdit_plainText(::QPlainTextEdit *w, ::rust::String *return$) noexcept {
  ::rust::String (*QPlainTextEdit_plainText$)(::QPlainTextEdit *) = ::QPlainTextEdit_plainText;
  new (return$) ::rust::String(QPlainTextEdit_plainText$(w));
}

void cxxbridge1$205$QPlainTextEdit_setPlaceholderText(::QPlainTextEdit *w, ::std::string const &text) noexcept {
  void (*QPlainTextEdit_setPlaceholderText$)(::QPlainTextEdit *, ::std::string const &) = ::QPlainTextEdit_setPlaceholderText;
  QPlainTextEdit_setPlaceholderText$(w, text);
}

void cxxbridge1$205$QPlainTextEdit_setReadOnly(::QPlainTextEdit *w, bool readOnly) noexcept {
  void (*QPlainTextEdit_setReadOnly$)(::QPlainTextEdit *, bool) = ::QPlainTextEdit_setReadOnly;
  QPlainTextEdit_setReadOnly$(w, readOnly);
}

void cxxbridge1$205$QPlainTextEdit_setLineWrapMode(::QPlainTextEdit *w, ::std::int32_t mode) noexcept {
  void (*QPlainTextEdit_setLineWrapMode$)(::QPlainTextEdit *, ::std::int32_t) = ::QPlainTextEdit_setLineWrapMode;
  QPlainTextEdit_setLineWrapMode$(w, mode);
}

void cxxbridge1$205$QPlainTextEdit_appendPlainText(::QPlainTextEdit *w, ::std::string const &text) noexcept {
  void (*QPlainTextEdit_appendPlainText$)(::QPlainTextEdit *, ::std::string const &) = ::QPlainTextEdit_appendPlainText;
  QPlainTextEdit_appendPlainText$(w, text);
}

void cxxbridge1$205$QPlainTextEdit_clear(::QPlainTextEdit *w) noexcept {
  void (*QPlainTextEdit_clear$)(::QPlainTextEdit *) = ::QPlainTextEdit_clear;
  QPlainTextEdit_clear$(w);
}

void cxxbridge1$205$QPlainTextEdit_onTextChanged(::QPlainTextEdit *w, ::std::uint64_t ctx) noexcept {
  void (*QPlainTextEdit_onTextChanged$)(::QPlainTextEdit *, ::std::uint64_t) = ::QPlainTextEdit_onTextChanged;
  QPlainTextEdit_onTextChanged$(w, ctx);
}

void cxxbridge1$205$QPlainTextEdit_onCursorPositionChanged(::QPlainTextEdit *w, ::std::uint64_t ctx) noexcept {
  void (*QPlainTextEdit_onCursorPositionChanged$)(::QPlainTextEdit *, ::std::uint64_t) = ::QPlainTextEdit_onCursorPositionChanged;
  QPlainTextEdit_onCursorPositionChanged$(w, ctx);
}

::QTextBrowser *cxxbridge1$205$QTextBrowser_new(::QWidget *parent) noexcept {
  ::QTextBrowser *(*QTextBrowser_new$)(::QWidget *) = ::QTextBrowser_new;
  return QTextBrowser_new$(parent);
}

void cxxbridge1$205$QTextBrowser_delete(::QTextBrowser *w) noexcept {
  void (*QTextBrowser_delete$)(::QTextBrowser *) = ::QTextBrowser_delete;
  QTextBrowser_delete$(w);
}

void cxxbridge1$205$QTextBrowser_setHtml(::QTextBrowser *w, ::std::string const &html) noexcept {
  void (*QTextBrowser_setHtml$)(::QTextBrowser *, ::std::string const &) = ::QTextBrowser_setHtml;
  QTextBrowser_setHtml$(w, html);
}

void cxxbridge1$205$QTextBrowser_setPlainText(::QTextBrowser *w, ::std::string const &text) noexcept {
  void (*QTextBrowser_setPlainText$)(::QTextBrowser *, ::std::string const &) = ::QTextBrowser_setPlainText;
  QTextBrowser_setPlainText$(w, text);
}

void cxxbridge1$205$QTextBrowser_plainText(::QTextBrowser *w, ::rust::String *return$) noexcept {
  ::rust::String (*QTextBrowser_plainText$)(::QTextBrowser *) = ::QTextBrowser_plainText;
  new (return$) ::rust::String(QTextBrowser_plainText$(w));
}

void cxxbridge1$205$QTextBrowser_toHtml(::QTextBrowser *w, ::rust::String *return$) noexcept {
  ::rust::String (*QTextBrowser_toHtml$)(::QTextBrowser *) = ::QTextBrowser_toHtml;
  new (return$) ::rust::String(QTextBrowser_toHtml$(w));
}

void cxxbridge1$205$QTextBrowser_setOpenExternalLinks(::QTextBrowser *w, bool open) noexcept {
  void (*QTextBrowser_setOpenExternalLinks$)(::QTextBrowser *, bool) = ::QTextBrowser_setOpenExternalLinks;
  QTextBrowser_setOpenExternalLinks$(w, open);
}

void cxxbridge1$205$QTextBrowser_setOpenLinks(::QTextBrowser *w, bool open) noexcept {
  void (*QTextBrowser_setOpenLinks$)(::QTextBrowser *, bool) = ::QTextBrowser_setOpenLinks;
  QTextBrowser_setOpenLinks$(w, open);
}

void cxxbridge1$205$QTextBrowser_setSource(::QTextBrowser *w, ::std::string const &url) noexcept {
  void (*QTextBrowser_setSource$)(::QTextBrowser *, ::std::string const &) = ::QTextBrowser_setSource;
  QTextBrowser_setSource$(w, url);
}

void cxxbridge1$205$QTextBrowser_source(::QTextBrowser *w, ::rust::String *return$) noexcept {
  ::rust::String (*QTextBrowser_source$)(::QTextBrowser *) = ::QTextBrowser_source;
  new (return$) ::rust::String(QTextBrowser_source$(w));
}

void cxxbridge1$205$QTextBrowser_clear(::QTextBrowser *w) noexcept {
  void (*QTextBrowser_clear$)(::QTextBrowser *) = ::QTextBrowser_clear;
  QTextBrowser_clear$(w);
}

void cxxbridge1$205$QTextBrowser_append(::QTextBrowser *w, ::std::string const &text) noexcept {
  void (*QTextBrowser_append$)(::QTextBrowser *, ::std::string const &) = ::QTextBrowser_append;
  QTextBrowser_append$(w, text);
}

void cxxbridge1$205$QTextBrowser_setSearchPaths(::QTextBrowser *w, ::rust::Vec<::rust::String> const *paths) noexcept {
  void (*QTextBrowser_setSearchPaths$)(::QTextBrowser *, ::rust::Vec<::rust::String>) = ::QTextBrowser_setSearchPaths;
  QTextBrowser_setSearchPaths$(w, ::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *paths));
}

void cxxbridge1$205$QTextBrowser_onAnchorClicked(::QTextBrowser *w, ::std::uint64_t ctx) noexcept {
  void (*QTextBrowser_onAnchorClicked$)(::QTextBrowser *, ::std::uint64_t) = ::QTextBrowser_onAnchorClicked;
  QTextBrowser_onAnchorClicked$(w, ctx);
}

void cxxbridge1$205$QTextBrowser_onTextChanged(::QTextBrowser *w, ::std::uint64_t ctx) noexcept {
  void (*QTextBrowser_onTextChanged$)(::QTextBrowser *, ::std::uint64_t) = ::QTextBrowser_onTextChanged;
  QTextBrowser_onTextChanged$(w, ctx);
}

::QFrame *cxxbridge1$205$QFrame_new(::QWidget *parent) noexcept {
  ::QFrame *(*QFrame_new$)(::QWidget *) = ::QFrame_new;
  return QFrame_new$(parent);
}

void cxxbridge1$205$QFrame_delete(::QFrame *frame) noexcept {
  void (*QFrame_delete$)(::QFrame *) = ::QFrame_delete;
  QFrame_delete$(frame);
}

void cxxbridge1$205$QFrame_setFrameShape(::QFrame *frame, ::std::int32_t shape) noexcept {
  void (*QFrame_setFrameShape$)(::QFrame *, ::std::int32_t) = ::QFrame_setFrameShape;
  QFrame_setFrameShape$(frame, shape);
}

void cxxbridge1$205$QFrame_setFrameShadow(::QFrame *frame, ::std::int32_t shadow) noexcept {
  void (*QFrame_setFrameShadow$)(::QFrame *, ::std::int32_t) = ::QFrame_setFrameShadow;
  QFrame_setFrameShadow$(frame, shadow);
}

void cxxbridge1$205$QFrame_setLineWidth(::QFrame *frame, ::std::int32_t width) noexcept {
  void (*QFrame_setLineWidth$)(::QFrame *, ::std::int32_t) = ::QFrame_setLineWidth;
  QFrame_setLineWidth$(frame, width);
}

void cxxbridge1$205$QFrame_setMidLineWidth(::QFrame *frame, ::std::int32_t width) noexcept {
  void (*QFrame_setMidLineWidth$)(::QFrame *, ::std::int32_t) = ::QFrame_setMidLineWidth;
  QFrame_setMidLineWidth$(frame, width);
}

void cxxbridge1$205$QFrame_setFrameStyle(::QFrame *frame, ::std::int32_t style) noexcept {
  void (*QFrame_setFrameStyle$)(::QFrame *, ::std::int32_t) = ::QFrame_setFrameStyle;
  QFrame_setFrameStyle$(frame, style);
}

::QToolButton *cxxbridge1$205$QToolButton_new(::QWidget *parent) noexcept {
  ::QToolButton *(*QToolButton_new$)(::QWidget *) = ::QToolButton_new;
  return QToolButton_new$(parent);
}

void cxxbridge1$205$QToolButton_delete(::QToolButton *btn) noexcept {
  void (*QToolButton_delete$)(::QToolButton *) = ::QToolButton_delete;
  QToolButton_delete$(btn);
}

void cxxbridge1$205$QToolButton_setText(::QToolButton *btn, ::std::string const &text) noexcept {
  void (*QToolButton_setText$)(::QToolButton *, ::std::string const &) = ::QToolButton_setText;
  QToolButton_setText$(btn, text);
}

void cxxbridge1$205$QToolButton_setIcon(::QToolButton *btn, ::std::string const &icon_path) noexcept {
  void (*QToolButton_setIcon$)(::QToolButton *, ::std::string const &) = ::QToolButton_setIcon;
  QToolButton_setIcon$(btn, icon_path);
}

void cxxbridge1$205$QToolButton_setToolButtonStyle(::QToolButton *btn, ::std::int32_t style) noexcept {
  void (*QToolButton_setToolButtonStyle$)(::QToolButton *, ::std::int32_t) = ::QToolButton_setToolButtonStyle;
  QToolButton_setToolButtonStyle$(btn, style);
}

void cxxbridge1$205$QToolButton_setPopupMode(::QToolButton *btn, ::std::int32_t mode) noexcept {
  void (*QToolButton_setPopupMode$)(::QToolButton *, ::std::int32_t) = ::QToolButton_setPopupMode;
  QToolButton_setPopupMode$(btn, mode);
}

void cxxbridge1$205$QToolButton_setAutoRaise(::QToolButton *btn, bool enabled) noexcept {
  void (*QToolButton_setAutoRaise$)(::QToolButton *, bool) = ::QToolButton_setAutoRaise;
  QToolButton_setAutoRaise$(btn, enabled);
}

void cxxbridge1$205$QToolButton_setCheckable(::QToolButton *btn, bool checkable) noexcept {
  void (*QToolButton_setCheckable$)(::QToolButton *, bool) = ::QToolButton_setCheckable;
  QToolButton_setCheckable$(btn, checkable);
}

void cxxbridge1$205$QToolButton_setChecked(::QToolButton *btn, bool checked) noexcept {
  void (*QToolButton_setChecked$)(::QToolButton *, bool) = ::QToolButton_setChecked;
  QToolButton_setChecked$(btn, checked);
}

void cxxbridge1$205$QToolButton_setShortcut(::QToolButton *btn, ::std::string const &key) noexcept {
  void (*QToolButton_setShortcut$)(::QToolButton *, ::std::string const &) = ::QToolButton_setShortcut;
  QToolButton_setShortcut$(btn, key);
}

void cxxbridge1$205$QToolButton_onClicked(::QToolButton *btn, ::std::uint64_t ctx) noexcept {
  void (*QToolButton_onClicked$)(::QToolButton *, ::std::uint64_t) = ::QToolButton_onClicked;
  QToolButton_onClicked$(btn, ctx);
}

void cxxbridge1$205$QToolButton_onToggled(::QToolButton *btn, ::std::uint64_t ctx) noexcept {
  void (*QToolButton_onToggled$)(::QToolButton *, ::std::uint64_t) = ::QToolButton_onToggled;
  QToolButton_onToggled$(btn, ctx);
}

::QCalendarWidget *cxxbridge1$205$QCalendarWidget_new(::QWidget *parent) noexcept {
  ::QCalendarWidget *(*QCalendarWidget_new$)(::QWidget *) = ::QCalendarWidget_new;
  return QCalendarWidget_new$(parent);
}

void cxxbridge1$205$QCalendarWidget_delete(::QCalendarWidget *cal) noexcept {
  void (*QCalendarWidget_delete$)(::QCalendarWidget *) = ::QCalendarWidget_delete;
  QCalendarWidget_delete$(cal);
}

void cxxbridge1$205$QCalendarWidget_setSelectedDate(::QCalendarWidget *cal, ::std::string const &date_str) noexcept {
  void (*QCalendarWidget_setSelectedDate$)(::QCalendarWidget *, ::std::string const &) = ::QCalendarWidget_setSelectedDate;
  QCalendarWidget_setSelectedDate$(cal, date_str);
}

void cxxbridge1$205$QCalendarWidget_selectedDate(::QCalendarWidget *cal, ::rust::String *return$) noexcept {
  ::rust::String (*QCalendarWidget_selectedDate$)(::QCalendarWidget *) = ::QCalendarWidget_selectedDate;
  new (return$) ::rust::String(QCalendarWidget_selectedDate$(cal));
}

void cxxbridge1$205$QCalendarWidget_setMinimumDate(::QCalendarWidget *cal, ::std::string const &date_str) noexcept {
  void (*QCalendarWidget_setMinimumDate$)(::QCalendarWidget *, ::std::string const &) = ::QCalendarWidget_setMinimumDate;
  QCalendarWidget_setMinimumDate$(cal, date_str);
}

void cxxbridge1$205$QCalendarWidget_setMaximumDate(::QCalendarWidget *cal, ::std::string const &date_str) noexcept {
  void (*QCalendarWidget_setMaximumDate$)(::QCalendarWidget *, ::std::string const &) = ::QCalendarWidget_setMaximumDate;
  QCalendarWidget_setMaximumDate$(cal, date_str);
}

void cxxbridge1$205$QCalendarWidget_setFirstDayOfWeek(::QCalendarWidget *cal, ::std::int32_t day) noexcept {
  void (*QCalendarWidget_setFirstDayOfWeek$)(::QCalendarWidget *, ::std::int32_t) = ::QCalendarWidget_setFirstDayOfWeek;
  QCalendarWidget_setFirstDayOfWeek$(cal, day);
}

void cxxbridge1$205$QCalendarWidget_setGridVisible(::QCalendarWidget *cal, bool visible) noexcept {
  void (*QCalendarWidget_setGridVisible$)(::QCalendarWidget *, bool) = ::QCalendarWidget_setGridVisible;
  QCalendarWidget_setGridVisible$(cal, visible);
}

void cxxbridge1$205$QCalendarWidget_setNavigationBarVisible(::QCalendarWidget *cal, bool visible) noexcept {
  void (*QCalendarWidget_setNavigationBarVisible$)(::QCalendarWidget *, bool) = ::QCalendarWidget_setNavigationBarVisible;
  QCalendarWidget_setNavigationBarVisible$(cal, visible);
}

void cxxbridge1$205$QCalendarWidget_onSelectionChanged(::QCalendarWidget *cal, ::std::uint64_t ctx) noexcept {
  void (*QCalendarWidget_onSelectionChanged$)(::QCalendarWidget *, ::std::uint64_t) = ::QCalendarWidget_onSelectionChanged;
  QCalendarWidget_onSelectionChanged$(cal, ctx);
}

void cxxbridge1$205$QCalendarWidget_onActivated(::QCalendarWidget *cal, ::std::uint64_t ctx) noexcept {
  void (*QCalendarWidget_onActivated$)(::QCalendarWidget *, ::std::uint64_t) = ::QCalendarWidget_onActivated;
  QCalendarWidget_onActivated$(cal, ctx);
}

::QShortcut *cxxbridge1$205$QShortcut_new(::std::string const &key, ::QWidget *parent) noexcept {
  ::QShortcut *(*QShortcut_new$)(::std::string const &, ::QWidget *) = ::QShortcut_new;
  return QShortcut_new$(key, parent);
}

void cxxbridge1$205$QShortcut_delete(::QShortcut *sc) noexcept {
  void (*QShortcut_delete$)(::QShortcut *) = ::QShortcut_delete;
  QShortcut_delete$(sc);
}

void cxxbridge1$205$QShortcut_setKey(::QShortcut *sc, ::std::string const &key) noexcept {
  void (*QShortcut_setKey$)(::QShortcut *, ::std::string const &) = ::QShortcut_setKey;
  QShortcut_setKey$(sc, key);
}

void cxxbridge1$205$QShortcut_setEnabled(::QShortcut *sc, bool enabled) noexcept {
  void (*QShortcut_setEnabled$)(::QShortcut *, bool) = ::QShortcut_setEnabled;
  QShortcut_setEnabled$(sc, enabled);
}

void cxxbridge1$205$QShortcut_setAutoRepeat(::QShortcut *sc, bool repeat) noexcept {
  void (*QShortcut_setAutoRepeat$)(::QShortcut *, bool) = ::QShortcut_setAutoRepeat;
  QShortcut_setAutoRepeat$(sc, repeat);
}

void cxxbridge1$205$QShortcut_onActivated(::QShortcut *sc, ::std::uint64_t ctx) noexcept {
  void (*QShortcut_onActivated$)(::QShortcut *, ::std::uint64_t) = ::QShortcut_onActivated;
  QShortcut_onActivated$(sc, ctx);
}

::QFont *cxxbridge1$205$QFont_new() noexcept {
  ::QFont *(*QFont_new$)() = ::QFont_new;
  return QFont_new$();
}

void cxxbridge1$205$QFont_setFamily(::QFont *font, ::std::string const &family) noexcept {
  void (*QFont_setFamily$)(::QFont *, ::std::string const &) = ::QFont_setFamily;
  QFont_setFamily$(font, family);
}

void cxxbridge1$205$QFont_setPointSize(::QFont *font, ::std::int32_t size) noexcept {
  void (*QFont_setPointSize$)(::QFont *, ::std::int32_t) = ::QFont_setPointSize;
  QFont_setPointSize$(font, size);
}

void cxxbridge1$205$QFont_setPixelSize(::QFont *font, ::std::int32_t size) noexcept {
  void (*QFont_setPixelSize$)(::QFont *, ::std::int32_t) = ::QFont_setPixelSize;
  QFont_setPixelSize$(font, size);
}

void cxxbridge1$205$QFont_setBold(::QFont *font, bool bold) noexcept {
  void (*QFont_setBold$)(::QFont *, bool) = ::QFont_setBold;
  QFont_setBold$(font, bold);
}

void cxxbridge1$205$QFont_setItalic(::QFont *font, bool italic) noexcept {
  void (*QFont_setItalic$)(::QFont *, bool) = ::QFont_setItalic;
  QFont_setItalic$(font, italic);
}

void cxxbridge1$205$QFont_setUnderline(::QFont *font, bool underline) noexcept {
  void (*QFont_setUnderline$)(::QFont *, bool) = ::QFont_setUnderline;
  QFont_setUnderline$(font, underline);
}

void cxxbridge1$205$QFont_setStrikeOut(::QFont *font, bool strike) noexcept {
  void (*QFont_setStrikeOut$)(::QFont *, bool) = ::QFont_setStrikeOut;
  QFont_setStrikeOut$(font, strike);
}

void cxxbridge1$205$QFont_setWeight(::QFont *font, ::std::int32_t weight) noexcept {
  void (*QFont_setWeight$)(::QFont *, ::std::int32_t) = ::QFont_setWeight;
  QFont_setWeight$(font, weight);
}

void cxxbridge1$205$QFont_family(::QFont *font, ::rust::String *return$) noexcept {
  ::rust::String (*QFont_family$)(::QFont *) = ::QFont_family;
  new (return$) ::rust::String(QFont_family$(font));
}

::std::int32_t cxxbridge1$205$QFont_pointSize(::QFont *font) noexcept {
  ::std::int32_t (*QFont_pointSize$)(::QFont *) = ::QFont_pointSize;
  return QFont_pointSize$(font);
}

::std::int32_t cxxbridge1$205$QFont_pixelSize(::QFont *font) noexcept {
  ::std::int32_t (*QFont_pixelSize$)(::QFont *) = ::QFont_pixelSize;
  return QFont_pixelSize$(font);
}

bool cxxbridge1$205$QFont_bold(::QFont *font) noexcept {
  bool (*QFont_bold$)(::QFont *) = ::QFont_bold;
  return QFont_bold$(font);
}

bool cxxbridge1$205$QFont_italic(::QFont *font) noexcept {
  bool (*QFont_italic$)(::QFont *) = ::QFont_italic;
  return QFont_italic$(font);
}

bool cxxbridge1$205$QFont_underline(::QFont *font) noexcept {
  bool (*QFont_underline$)(::QFont *) = ::QFont_underline;
  return QFont_underline$(font);
}

bool cxxbridge1$205$QFont_strikeOut(::QFont *font) noexcept {
  bool (*QFont_strikeOut$)(::QFont *) = ::QFont_strikeOut;
  return QFont_strikeOut$(font);
}

::std::int32_t cxxbridge1$205$QFont_weight(::QFont *font) noexcept {
  ::std::int32_t (*QFont_weight$)(::QFont *) = ::QFont_weight;
  return QFont_weight$(font);
}

void cxxbridge1$205$QFont_delete(::QFont *font) noexcept {
  void (*QFont_delete$)(::QFont *) = ::QFont_delete;
  QFont_delete$(font);
}

::QSystemTrayIcon *cxxbridge1$205$QSystemTrayIcon_new(::std::string const &icon_path, ::QObject *parent) noexcept {
  ::QSystemTrayIcon *(*QSystemTrayIcon_new$)(::std::string const &, ::QObject *) = ::QSystemTrayIcon_new;
  return QSystemTrayIcon_new$(icon_path, parent);
}

void cxxbridge1$205$QSystemTrayIcon_delete(::QSystemTrayIcon *tray) noexcept {
  void (*QSystemTrayIcon_delete$)(::QSystemTrayIcon *) = ::QSystemTrayIcon_delete;
  QSystemTrayIcon_delete$(tray);
}

void cxxbridge1$205$QSystemTrayIcon_setIcon(::QSystemTrayIcon *tray, ::std::string const &icon_path) noexcept {
  void (*QSystemTrayIcon_setIcon$)(::QSystemTrayIcon *, ::std::string const &) = ::QSystemTrayIcon_setIcon;
  QSystemTrayIcon_setIcon$(tray, icon_path);
}

void cxxbridge1$205$QSystemTrayIcon_setToolTip(::QSystemTrayIcon *tray, ::std::string const &tip) noexcept {
  void (*QSystemTrayIcon_setToolTip$)(::QSystemTrayIcon *, ::std::string const &) = ::QSystemTrayIcon_setToolTip;
  QSystemTrayIcon_setToolTip$(tray, tip);
}

void cxxbridge1$205$QSystemTrayIcon_show(::QSystemTrayIcon *tray) noexcept {
  void (*QSystemTrayIcon_show$)(::QSystemTrayIcon *) = ::QSystemTrayIcon_show;
  QSystemTrayIcon_show$(tray);
}

void cxxbridge1$205$QSystemTrayIcon_hide(::QSystemTrayIcon *tray) noexcept {
  void (*QSystemTrayIcon_hide$)(::QSystemTrayIcon *) = ::QSystemTrayIcon_hide;
  QSystemTrayIcon_hide$(tray);
}

bool cxxbridge1$205$QSystemTrayIcon_isVisible(::QSystemTrayIcon *tray) noexcept {
  bool (*QSystemTrayIcon_isVisible$)(::QSystemTrayIcon *) = ::QSystemTrayIcon_isVisible;
  return QSystemTrayIcon_isVisible$(tray);
}

void cxxbridge1$205$QSystemTrayIcon_setContextMenu(::QSystemTrayIcon *tray, ::QMenu *menu) noexcept {
  void (*QSystemTrayIcon_setContextMenu$)(::QSystemTrayIcon *, ::QMenu *) = ::QSystemTrayIcon_setContextMenu;
  QSystemTrayIcon_setContextMenu$(tray, menu);
}

void cxxbridge1$205$QSystemTrayIcon_onActivated(::QSystemTrayIcon *tray, ::std::uint64_t ctx) noexcept {
  void (*QSystemTrayIcon_onActivated$)(::QSystemTrayIcon *, ::std::uint64_t) = ::QSystemTrayIcon_onActivated;
  QSystemTrayIcon_onActivated$(tray, ctx);
}

::QDial *cxxbridge1$205$QDial_new(::QWidget *parent) noexcept {
  ::QDial *(*QDial_new$)(::QWidget *) = ::QDial_new;
  return QDial_new$(parent);
}

void cxxbridge1$205$QDial_delete(::QDial *dial) noexcept {
  void (*QDial_delete$)(::QDial *) = ::QDial_delete;
  QDial_delete$(dial);
}

::std::int32_t cxxbridge1$205$QDial_value(::QDial *dial) noexcept {
  ::std::int32_t (*QDial_value$)(::QDial *) = ::QDial_value;
  return QDial_value$(dial);
}

void cxxbridge1$205$QDial_setValue(::QDial *dial, ::std::int32_t value) noexcept {
  void (*QDial_setValue$)(::QDial *, ::std::int32_t) = ::QDial_setValue;
  QDial_setValue$(dial, value);
}

void cxxbridge1$205$QDial_setRange(::QDial *dial, ::std::int32_t min, ::std::int32_t max) noexcept {
  void (*QDial_setRange$)(::QDial *, ::std::int32_t, ::std::int32_t) = ::QDial_setRange;
  QDial_setRange$(dial, min, max);
}

void cxxbridge1$205$QDial_setSingleStep(::QDial *dial, ::std::int32_t step) noexcept {
  void (*QDial_setSingleStep$)(::QDial *, ::std::int32_t) = ::QDial_setSingleStep;
  QDial_setSingleStep$(dial, step);
}

void cxxbridge1$205$QDial_setPageStep(::QDial *dial, ::std::int32_t step) noexcept {
  void (*QDial_setPageStep$)(::QDial *, ::std::int32_t) = ::QDial_setPageStep;
  QDial_setPageStep$(dial, step);
}

::std::int32_t cxxbridge1$205$QDial_minimum(::QDial *dial) noexcept {
  ::std::int32_t (*QDial_minimum$)(::QDial *) = ::QDial_minimum;
  return QDial_minimum$(dial);
}

::std::int32_t cxxbridge1$205$QDial_maximum(::QDial *dial) noexcept {
  ::std::int32_t (*QDial_maximum$)(::QDial *) = ::QDial_maximum;
  return QDial_maximum$(dial);
}

void cxxbridge1$205$QDial_setMinimum(::QDial *dial, ::std::int32_t min) noexcept {
  void (*QDial_setMinimum$)(::QDial *, ::std::int32_t) = ::QDial_setMinimum;
  QDial_setMinimum$(dial, min);
}

void cxxbridge1$205$QDial_setMaximum(::QDial *dial, ::std::int32_t max) noexcept {
  void (*QDial_setMaximum$)(::QDial *, ::std::int32_t) = ::QDial_setMaximum;
  QDial_setMaximum$(dial, max);
}

void cxxbridge1$205$QDial_setNotchesVisible(::QDial *dial, bool visible) noexcept {
  void (*QDial_setNotchesVisible$)(::QDial *, bool) = ::QDial_setNotchesVisible;
  QDial_setNotchesVisible$(dial, visible);
}

bool cxxbridge1$205$QDial_notchesVisible(::QDial *dial) noexcept {
  bool (*QDial_notchesVisible$)(::QDial *) = ::QDial_notchesVisible;
  return QDial_notchesVisible$(dial);
}

void cxxbridge1$205$QDial_setWrapping(::QDial *dial, bool wrapping) noexcept {
  void (*QDial_setWrapping$)(::QDial *, bool) = ::QDial_setWrapping;
  QDial_setWrapping$(dial, wrapping);
}

bool cxxbridge1$205$QDial_wrapping(::QDial *dial) noexcept {
  bool (*QDial_wrapping$)(::QDial *) = ::QDial_wrapping;
  return QDial_wrapping$(dial);
}

void cxxbridge1$205$QDial_onValueChanged(::QDial *dial, ::std::uint64_t ctx) noexcept {
  void (*QDial_onValueChanged$)(::QDial *, ::std::uint64_t) = ::QDial_onValueChanged;
  QDial_onValueChanged$(dial, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QDial(::QDial *dial) noexcept {
  ::QWidget *(*toQWidget_QDial$)(::QDial *) = ::toQWidget_QDial;
  return toQWidget_QDial$(dial);
}

::QDoubleSpinBox *cxxbridge1$205$QDoubleSpinBox_new(::QWidget *parent) noexcept {
  ::QDoubleSpinBox *(*QDoubleSpinBox_new$)(::QWidget *) = ::QDoubleSpinBox_new;
  return QDoubleSpinBox_new$(parent);
}

void cxxbridge1$205$QDoubleSpinBox_delete(::QDoubleSpinBox *sb) noexcept {
  void (*QDoubleSpinBox_delete$)(::QDoubleSpinBox *) = ::QDoubleSpinBox_delete;
  QDoubleSpinBox_delete$(sb);
}

void cxxbridge1$205$QDoubleSpinBox_setValue(::QDoubleSpinBox *sb, double value) noexcept {
  void (*QDoubleSpinBox_setValue$)(::QDoubleSpinBox *, double) = ::QDoubleSpinBox_setValue;
  QDoubleSpinBox_setValue$(sb, value);
}

double cxxbridge1$205$QDoubleSpinBox_value(::QDoubleSpinBox *sb) noexcept {
  double (*QDoubleSpinBox_value$)(::QDoubleSpinBox *) = ::QDoubleSpinBox_value;
  return QDoubleSpinBox_value$(sb);
}

void cxxbridge1$205$QDoubleSpinBox_setRange(::QDoubleSpinBox *sb, double min, double max) noexcept {
  void (*QDoubleSpinBox_setRange$)(::QDoubleSpinBox *, double, double) = ::QDoubleSpinBox_setRange;
  QDoubleSpinBox_setRange$(sb, min, max);
}

void cxxbridge1$205$QDoubleSpinBox_setSingleStep(::QDoubleSpinBox *sb, double step) noexcept {
  void (*QDoubleSpinBox_setSingleStep$)(::QDoubleSpinBox *, double) = ::QDoubleSpinBox_setSingleStep;
  QDoubleSpinBox_setSingleStep$(sb, step);
}

double cxxbridge1$205$QDoubleSpinBox_singleStep(::QDoubleSpinBox *sb) noexcept {
  double (*QDoubleSpinBox_singleStep$)(::QDoubleSpinBox *) = ::QDoubleSpinBox_singleStep;
  return QDoubleSpinBox_singleStep$(sb);
}

void cxxbridge1$205$QDoubleSpinBox_setDecimals(::QDoubleSpinBox *sb, ::std::int32_t decimals) noexcept {
  void (*QDoubleSpinBox_setDecimals$)(::QDoubleSpinBox *, ::std::int32_t) = ::QDoubleSpinBox_setDecimals;
  QDoubleSpinBox_setDecimals$(sb, decimals);
}

::std::int32_t cxxbridge1$205$QDoubleSpinBox_decimals(::QDoubleSpinBox *sb) noexcept {
  ::std::int32_t (*QDoubleSpinBox_decimals$)(::QDoubleSpinBox *) = ::QDoubleSpinBox_decimals;
  return QDoubleSpinBox_decimals$(sb);
}

void cxxbridge1$205$QDoubleSpinBox_setPrefix(::QDoubleSpinBox *sb, ::std::string const &prefix) noexcept {
  void (*QDoubleSpinBox_setPrefix$)(::QDoubleSpinBox *, ::std::string const &) = ::QDoubleSpinBox_setPrefix;
  QDoubleSpinBox_setPrefix$(sb, prefix);
}

void cxxbridge1$205$QDoubleSpinBox_setSuffix(::QDoubleSpinBox *sb, ::std::string const &suffix) noexcept {
  void (*QDoubleSpinBox_setSuffix$)(::QDoubleSpinBox *, ::std::string const &) = ::QDoubleSpinBox_setSuffix;
  QDoubleSpinBox_setSuffix$(sb, suffix);
}

void cxxbridge1$205$QDoubleSpinBox_setMinimum(::QDoubleSpinBox *sb, double min) noexcept {
  void (*QDoubleSpinBox_setMinimum$)(::QDoubleSpinBox *, double) = ::QDoubleSpinBox_setMinimum;
  QDoubleSpinBox_setMinimum$(sb, min);
}

void cxxbridge1$205$QDoubleSpinBox_setMaximum(::QDoubleSpinBox *sb, double max) noexcept {
  void (*QDoubleSpinBox_setMaximum$)(::QDoubleSpinBox *, double) = ::QDoubleSpinBox_setMaximum;
  QDoubleSpinBox_setMaximum$(sb, max);
}

double cxxbridge1$205$QDoubleSpinBox_minimum(::QDoubleSpinBox *sb) noexcept {
  double (*QDoubleSpinBox_minimum$)(::QDoubleSpinBox *) = ::QDoubleSpinBox_minimum;
  return QDoubleSpinBox_minimum$(sb);
}

double cxxbridge1$205$QDoubleSpinBox_maximum(::QDoubleSpinBox *sb) noexcept {
  double (*QDoubleSpinBox_maximum$)(::QDoubleSpinBox *) = ::QDoubleSpinBox_maximum;
  return QDoubleSpinBox_maximum$(sb);
}

void cxxbridge1$205$QDoubleSpinBox_setReadOnly(::QDoubleSpinBox *sb, bool read_only) noexcept {
  void (*QDoubleSpinBox_setReadOnly$)(::QDoubleSpinBox *, bool) = ::QDoubleSpinBox_setReadOnly;
  QDoubleSpinBox_setReadOnly$(sb, read_only);
}

void cxxbridge1$205$QDoubleSpinBox_setGroupSeparatorShown(::QDoubleSpinBox *sb, bool shown) noexcept {
  void (*QDoubleSpinBox_setGroupSeparatorShown$)(::QDoubleSpinBox *, bool) = ::QDoubleSpinBox_setGroupSeparatorShown;
  QDoubleSpinBox_setGroupSeparatorShown$(sb, shown);
}

void cxxbridge1$205$QDoubleSpinBox_onValueChanged(::QDoubleSpinBox *sb, ::std::uint64_t ctx) noexcept {
  void (*QDoubleSpinBox_onValueChanged$)(::QDoubleSpinBox *, ::std::uint64_t) = ::QDoubleSpinBox_onValueChanged;
  QDoubleSpinBox_onValueChanged$(sb, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QDoubleSpinBox(::QDoubleSpinBox *sb) noexcept {
  ::QWidget *(*toQWidget_QDoubleSpinBox$)(::QDoubleSpinBox *) = ::toQWidget_QDoubleSpinBox;
  return toQWidget_QDoubleSpinBox$(sb);
}

::QLCDNumber *cxxbridge1$205$QLCDNumber_new(::QWidget *parent) noexcept {
  ::QLCDNumber *(*QLCDNumber_new$)(::QWidget *) = ::QLCDNumber_new;
  return QLCDNumber_new$(parent);
}

void cxxbridge1$205$QLCDNumber_delete(::QLCDNumber *lcd) noexcept {
  void (*QLCDNumber_delete$)(::QLCDNumber *) = ::QLCDNumber_delete;
  QLCDNumber_delete$(lcd);
}

void cxxbridge1$205$QLCDNumber_displayInt(::QLCDNumber *lcd, ::std::int32_t value) noexcept {
  void (*QLCDNumber_displayInt$)(::QLCDNumber *, ::std::int32_t) = ::QLCDNumber_displayInt;
  QLCDNumber_displayInt$(lcd, value);
}

void cxxbridge1$205$QLCDNumber_displayStr(::QLCDNumber *lcd, ::std::string const &text) noexcept {
  void (*QLCDNumber_displayStr$)(::QLCDNumber *, ::std::string const &) = ::QLCDNumber_displayStr;
  QLCDNumber_displayStr$(lcd, text);
}

void cxxbridge1$205$QLCDNumber_setDigitCount(::QLCDNumber *lcd, ::std::int32_t n) noexcept {
  void (*QLCDNumber_setDigitCount$)(::QLCDNumber *, ::std::int32_t) = ::QLCDNumber_setDigitCount;
  QLCDNumber_setDigitCount$(lcd, n);
}

::std::int32_t cxxbridge1$205$QLCDNumber_digitCount(::QLCDNumber *lcd) noexcept {
  ::std::int32_t (*QLCDNumber_digitCount$)(::QLCDNumber *) = ::QLCDNumber_digitCount;
  return QLCDNumber_digitCount$(lcd);
}

void cxxbridge1$205$QLCDNumber_setMode(::QLCDNumber *lcd, ::std::int32_t mode) noexcept {
  void (*QLCDNumber_setMode$)(::QLCDNumber *, ::std::int32_t) = ::QLCDNumber_setMode;
  QLCDNumber_setMode$(lcd, mode);
}

void cxxbridge1$205$QLCDNumber_setSegmentStyle(::QLCDNumber *lcd, ::std::int32_t style) noexcept {
  void (*QLCDNumber_setSegmentStyle$)(::QLCDNumber *, ::std::int32_t) = ::QLCDNumber_setSegmentStyle;
  QLCDNumber_setSegmentStyle$(lcd, style);
}

void cxxbridge1$205$QLCDNumber_setSmallDecimalPoint(::QLCDNumber *lcd, bool enabled) noexcept {
  void (*QLCDNumber_setSmallDecimalPoint$)(::QLCDNumber *, bool) = ::QLCDNumber_setSmallDecimalPoint;
  QLCDNumber_setSmallDecimalPoint$(lcd, enabled);
}

bool cxxbridge1$205$QLCDNumber_checkOverflow(::QLCDNumber *lcd, ::std::int32_t value) noexcept {
  bool (*QLCDNumber_checkOverflow$)(::QLCDNumber *, ::std::int32_t) = ::QLCDNumber_checkOverflow;
  return QLCDNumber_checkOverflow$(lcd, value);
}

void cxxbridge1$205$QLCDNumber_onOverflow(::QLCDNumber *lcd, ::std::uint64_t ctx) noexcept {
  void (*QLCDNumber_onOverflow$)(::QLCDNumber *, ::std::uint64_t) = ::QLCDNumber_onOverflow;
  QLCDNumber_onOverflow$(lcd, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QLCDNumber(::QLCDNumber *lcd) noexcept {
  ::QWidget *(*toQWidget_QLCDNumber$)(::QLCDNumber *) = ::toQWidget_QLCDNumber;
  return toQWidget_QLCDNumber$(lcd);
}

::QScrollBar *cxxbridge1$205$QScrollBar_new(::std::int32_t orientation, ::QWidget *parent) noexcept {
  ::QScrollBar *(*QScrollBar_new$)(::std::int32_t, ::QWidget *) = ::QScrollBar_new;
  return QScrollBar_new$(orientation, parent);
}

void cxxbridge1$205$QScrollBar_delete(::QScrollBar *sb) noexcept {
  void (*QScrollBar_delete$)(::QScrollBar *) = ::QScrollBar_delete;
  QScrollBar_delete$(sb);
}

::std::int32_t cxxbridge1$205$QScrollBar_value(::QScrollBar *sb) noexcept {
  ::std::int32_t (*QScrollBar_value$)(::QScrollBar *) = ::QScrollBar_value;
  return QScrollBar_value$(sb);
}

void cxxbridge1$205$QScrollBar_setValue(::QScrollBar *sb, ::std::int32_t value) noexcept {
  void (*QScrollBar_setValue$)(::QScrollBar *, ::std::int32_t) = ::QScrollBar_setValue;
  QScrollBar_setValue$(sb, value);
}

void cxxbridge1$205$QScrollBar_setRange(::QScrollBar *sb, ::std::int32_t min, ::std::int32_t max) noexcept {
  void (*QScrollBar_setRange$)(::QScrollBar *, ::std::int32_t, ::std::int32_t) = ::QScrollBar_setRange;
  QScrollBar_setRange$(sb, min, max);
}

void cxxbridge1$205$QScrollBar_setSingleStep(::QScrollBar *sb, ::std::int32_t step) noexcept {
  void (*QScrollBar_setSingleStep$)(::QScrollBar *, ::std::int32_t) = ::QScrollBar_setSingleStep;
  QScrollBar_setSingleStep$(sb, step);
}

void cxxbridge1$205$QScrollBar_setPageStep(::QScrollBar *sb, ::std::int32_t step) noexcept {
  void (*QScrollBar_setPageStep$)(::QScrollBar *, ::std::int32_t) = ::QScrollBar_setPageStep;
  QScrollBar_setPageStep$(sb, step);
}

::std::int32_t cxxbridge1$205$QScrollBar_minimum(::QScrollBar *sb) noexcept {
  ::std::int32_t (*QScrollBar_minimum$)(::QScrollBar *) = ::QScrollBar_minimum;
  return QScrollBar_minimum$(sb);
}

::std::int32_t cxxbridge1$205$QScrollBar_maximum(::QScrollBar *sb) noexcept {
  ::std::int32_t (*QScrollBar_maximum$)(::QScrollBar *) = ::QScrollBar_maximum;
  return QScrollBar_maximum$(sb);
}

void cxxbridge1$205$QScrollBar_setMinimum(::QScrollBar *sb, ::std::int32_t min) noexcept {
  void (*QScrollBar_setMinimum$)(::QScrollBar *, ::std::int32_t) = ::QScrollBar_setMinimum;
  QScrollBar_setMinimum$(sb, min);
}

void cxxbridge1$205$QScrollBar_setMaximum(::QScrollBar *sb, ::std::int32_t max) noexcept {
  void (*QScrollBar_setMaximum$)(::QScrollBar *, ::std::int32_t) = ::QScrollBar_setMaximum;
  QScrollBar_setMaximum$(sb, max);
}

void cxxbridge1$205$QScrollBar_setOrientation(::QScrollBar *sb, ::std::int32_t orientation) noexcept {
  void (*QScrollBar_setOrientation$)(::QScrollBar *, ::std::int32_t) = ::QScrollBar_setOrientation;
  QScrollBar_setOrientation$(sb, orientation);
}

void cxxbridge1$205$QScrollBar_setInvertedAppearance(::QScrollBar *sb, bool inverted) noexcept {
  void (*QScrollBar_setInvertedAppearance$)(::QScrollBar *, bool) = ::QScrollBar_setInvertedAppearance;
  QScrollBar_setInvertedAppearance$(sb, inverted);
}

void cxxbridge1$205$QScrollBar_setInvertedControls(::QScrollBar *sb, bool inverted) noexcept {
  void (*QScrollBar_setInvertedControls$)(::QScrollBar *, bool) = ::QScrollBar_setInvertedControls;
  QScrollBar_setInvertedControls$(sb, inverted);
}

void cxxbridge1$205$QScrollBar_setSliderPosition(::QScrollBar *sb, ::std::int32_t pos) noexcept {
  void (*QScrollBar_setSliderPosition$)(::QScrollBar *, ::std::int32_t) = ::QScrollBar_setSliderPosition;
  QScrollBar_setSliderPosition$(sb, pos);
}

::std::int32_t cxxbridge1$205$QScrollBar_sliderPosition(::QScrollBar *sb) noexcept {
  ::std::int32_t (*QScrollBar_sliderPosition$)(::QScrollBar *) = ::QScrollBar_sliderPosition;
  return QScrollBar_sliderPosition$(sb);
}

void cxxbridge1$205$QScrollBar_onValueChanged(::QScrollBar *sb, ::std::uint64_t ctx) noexcept {
  void (*QScrollBar_onValueChanged$)(::QScrollBar *, ::std::uint64_t) = ::QScrollBar_onValueChanged;
  QScrollBar_onValueChanged$(sb, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QScrollBar(::QScrollBar *sb) noexcept {
  ::QWidget *(*toQWidget_QScrollBar$)(::QScrollBar *) = ::toQWidget_QScrollBar;
  return toQWidget_QScrollBar$(sb);
}

::QDialogButtonBox *cxxbridge1$205$QDialogButtonBox_new(::QWidget *parent) noexcept {
  ::QDialogButtonBox *(*QDialogButtonBox_new$)(::QWidget *) = ::QDialogButtonBox_new;
  return QDialogButtonBox_new$(parent);
}

void cxxbridge1$205$QDialogButtonBox_setStandardButtons(::QDialogButtonBox *button_box, ::std::int32_t buttons) noexcept {
  void (*QDialogButtonBox_setStandardButtons$)(::QDialogButtonBox *, ::std::int32_t) = ::QDialogButtonBox_setStandardButtons;
  QDialogButtonBox_setStandardButtons$(button_box, buttons);
}

::QPushButton *cxxbridge1$205$QDialogButtonBox_button(::QDialogButtonBox *box_, ::std::int32_t button) noexcept {
  ::QPushButton *(*QDialogButtonBox_button$)(::QDialogButtonBox *, ::std::int32_t) = ::QDialogButtonBox_button;
  return QDialogButtonBox_button$(box_, button);
}

void cxxbridge1$205$QDialogButtonBox_delete(::QDialogButtonBox *box_) noexcept {
  void (*QDialogButtonBox_delete$)(::QDialogButtonBox *) = ::QDialogButtonBox_delete;
  QDialogButtonBox_delete$(box_);
}

::QDockWidget *cxxbridge1$205$QDockWidget_new(::QWidget *parent) noexcept {
  ::QDockWidget *(*QDockWidget_new$)(::QWidget *) = ::QDockWidget_new;
  return QDockWidget_new$(parent);
}

void cxxbridge1$205$QDockWidget_delete(::QDockWidget *dw) noexcept {
  void (*QDockWidget_delete$)(::QDockWidget *) = ::QDockWidget_delete;
  QDockWidget_delete$(dw);
}

void cxxbridge1$205$QDockWidget_setWindowTitle(::QDockWidget *dw, ::std::string const &title) noexcept {
  void (*QDockWidget_setWindowTitle$)(::QDockWidget *, ::std::string const &) = ::QDockWidget_setWindowTitle;
  QDockWidget_setWindowTitle$(dw, title);
}

void cxxbridge1$205$QDockWidget_setWidget(::QDockWidget *dw, ::QWidget *widget) noexcept {
  void (*QDockWidget_setWidget$)(::QDockWidget *, ::QWidget *) = ::QDockWidget_setWidget;
  QDockWidget_setWidget$(dw, widget);
}

::QWidget *cxxbridge1$205$QDockWidget_widget(::QDockWidget *dw) noexcept {
  ::QWidget *(*QDockWidget_widget$)(::QDockWidget *) = ::QDockWidget_widget;
  return QDockWidget_widget$(dw);
}

void cxxbridge1$205$QDockWidget_setFeatures(::QDockWidget *dw, ::std::int32_t features) noexcept {
  void (*QDockWidget_setFeatures$)(::QDockWidget *, ::std::int32_t) = ::QDockWidget_setFeatures;
  QDockWidget_setFeatures$(dw, features);
}

::std::int32_t cxxbridge1$205$QDockWidget_features(::QDockWidget *dw) noexcept {
  ::std::int32_t (*QDockWidget_features$)(::QDockWidget *) = ::QDockWidget_features;
  return QDockWidget_features$(dw);
}

void cxxbridge1$205$QDockWidget_setAllowedAreas(::QDockWidget *dw, ::std::int32_t areas) noexcept {
  void (*QDockWidget_setAllowedAreas$)(::QDockWidget *, ::std::int32_t) = ::QDockWidget_setAllowedAreas;
  QDockWidget_setAllowedAreas$(dw, areas);
}

::std::int32_t cxxbridge1$205$QDockWidget_allowedAreas(::QDockWidget *dw) noexcept {
  ::std::int32_t (*QDockWidget_allowedAreas$)(::QDockWidget *) = ::QDockWidget_allowedAreas;
  return QDockWidget_allowedAreas$(dw);
}

void cxxbridge1$205$QDockWidget_setFloating(::QDockWidget *dw, bool floating) noexcept {
  void (*QDockWidget_setFloating$)(::QDockWidget *, bool) = ::QDockWidget_setFloating;
  QDockWidget_setFloating$(dw, floating);
}

bool cxxbridge1$205$QDockWidget_isFloating(::QDockWidget *dw) noexcept {
  bool (*QDockWidget_isFloating$)(::QDockWidget *) = ::QDockWidget_isFloating;
  return QDockWidget_isFloating$(dw);
}

void cxxbridge1$205$QDockWidget_setVisible(::QDockWidget *dw, bool visible) noexcept {
  void (*QDockWidget_setVisible$)(::QDockWidget *, bool) = ::QDockWidget_setVisible;
  QDockWidget_setVisible$(dw, visible);
}

void cxxbridge1$205$QDockWidget_show(::QDockWidget *dw) noexcept {
  void (*QDockWidget_show$)(::QDockWidget *) = ::QDockWidget_show;
  QDockWidget_show$(dw);
}

void cxxbridge1$205$QDockWidget_hide(::QDockWidget *dw) noexcept {
  void (*QDockWidget_hide$)(::QDockWidget *) = ::QDockWidget_hide;
  QDockWidget_hide$(dw);
}

void cxxbridge1$205$QDockWidget_onVisibilityChanged(::QDockWidget *dw, ::std::uint64_t ctx) noexcept {
  void (*QDockWidget_onVisibilityChanged$)(::QDockWidget *, ::std::uint64_t) = ::QDockWidget_onVisibilityChanged;
  QDockWidget_onVisibilityChanged$(dw, ctx);
}

void cxxbridge1$205$QDockWidget_onFeaturesChanged(::QDockWidget *dw, ::std::uint64_t ctx) noexcept {
  void (*QDockWidget_onFeaturesChanged$)(::QDockWidget *, ::std::uint64_t) = ::QDockWidget_onFeaturesChanged;
  QDockWidget_onFeaturesChanged$(dw, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QDockWidget(::QDockWidget *dw) noexcept {
  ::QWidget *(*toQWidget_QDockWidget$)(::QDockWidget *) = ::toQWidget_QDockWidget;
  return toQWidget_QDockWidget$(dw);
}

::QToolBox *cxxbridge1$205$QToolBox_new(::QWidget *parent) noexcept {
  ::QToolBox *(*QToolBox_new$)(::QWidget *) = ::QToolBox_new;
  return QToolBox_new$(parent);
}

void cxxbridge1$205$QToolBox_delete(::QToolBox *tb) noexcept {
  void (*QToolBox_delete$)(::QToolBox *) = ::QToolBox_delete;
  QToolBox_delete$(tb);
}

void cxxbridge1$205$QToolBox_addItem(::QToolBox *tb, ::QWidget *widget, ::std::string const &text) noexcept {
  void (*QToolBox_addItem$)(::QToolBox *, ::QWidget *, ::std::string const &) = ::QToolBox_addItem;
  QToolBox_addItem$(tb, widget, text);
}

void cxxbridge1$205$QToolBox_insertItem(::QToolBox *tb, ::std::int32_t index, ::QWidget *widget, ::std::string const &text) noexcept {
  void (*QToolBox_insertItem$)(::QToolBox *, ::std::int32_t, ::QWidget *, ::std::string const &) = ::QToolBox_insertItem;
  QToolBox_insertItem$(tb, index, widget, text);
}

void cxxbridge1$205$QToolBox_removeItem(::QToolBox *tb, ::std::int32_t index) noexcept {
  void (*QToolBox_removeItem$)(::QToolBox *, ::std::int32_t) = ::QToolBox_removeItem;
  QToolBox_removeItem$(tb, index);
}

void cxxbridge1$205$QToolBox_setItemText(::QToolBox *tb, ::std::int32_t index, ::std::string const &text) noexcept {
  void (*QToolBox_setItemText$)(::QToolBox *, ::std::int32_t, ::std::string const &) = ::QToolBox_setItemText;
  QToolBox_setItemText$(tb, index, text);
}

void cxxbridge1$205$QToolBox_itemText(::QToolBox *tb, ::std::int32_t index, ::rust::String *return$) noexcept {
  ::rust::String (*QToolBox_itemText$)(::QToolBox *, ::std::int32_t) = ::QToolBox_itemText;
  new (return$) ::rust::String(QToolBox_itemText$(tb, index));
}

void cxxbridge1$205$QToolBox_setItemIcon(::QToolBox *tb, ::std::int32_t index, ::std::string const &icon_path) noexcept {
  void (*QToolBox_setItemIcon$)(::QToolBox *, ::std::int32_t, ::std::string const &) = ::QToolBox_setItemIcon;
  QToolBox_setItemIcon$(tb, index, icon_path);
}

void cxxbridge1$205$QToolBox_setItemEnabled(::QToolBox *tb, ::std::int32_t index, bool enabled) noexcept {
  void (*QToolBox_setItemEnabled$)(::QToolBox *, ::std::int32_t, bool) = ::QToolBox_setItemEnabled;
  QToolBox_setItemEnabled$(tb, index, enabled);
}

bool cxxbridge1$205$QToolBox_isItemEnabled(::QToolBox *tb, ::std::int32_t index) noexcept {
  bool (*QToolBox_isItemEnabled$)(::QToolBox *, ::std::int32_t) = ::QToolBox_isItemEnabled;
  return QToolBox_isItemEnabled$(tb, index);
}

::std::int32_t cxxbridge1$205$QToolBox_currentIndex(::QToolBox *tb) noexcept {
  ::std::int32_t (*QToolBox_currentIndex$)(::QToolBox *) = ::QToolBox_currentIndex;
  return QToolBox_currentIndex$(tb);
}

void cxxbridge1$205$QToolBox_setCurrentIndex(::QToolBox *tb, ::std::int32_t index) noexcept {
  void (*QToolBox_setCurrentIndex$)(::QToolBox *, ::std::int32_t) = ::QToolBox_setCurrentIndex;
  QToolBox_setCurrentIndex$(tb, index);
}

::std::int32_t cxxbridge1$205$QToolBox_count(::QToolBox *tb) noexcept {
  ::std::int32_t (*QToolBox_count$)(::QToolBox *) = ::QToolBox_count;
  return QToolBox_count$(tb);
}

::QWidget *cxxbridge1$205$QToolBox_widget(::QToolBox *tb, ::std::int32_t index) noexcept {
  ::QWidget *(*QToolBox_widget$)(::QToolBox *, ::std::int32_t) = ::QToolBox_widget;
  return QToolBox_widget$(tb, index);
}

void cxxbridge1$205$QToolBox_onCurrentChanged(::QToolBox *tb, ::std::uint64_t ctx) noexcept {
  void (*QToolBox_onCurrentChanged$)(::QToolBox *, ::std::uint64_t) = ::QToolBox_onCurrentChanged;
  QToolBox_onCurrentChanged$(tb, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QToolBox(::QToolBox *tb) noexcept {
  ::QWidget *(*toQWidget_QToolBox$)(::QToolBox *) = ::toQWidget_QToolBox;
  return toQWidget_QToolBox$(tb);
}

::QFontComboBox *cxxbridge1$205$QFontComboBox_new(::QWidget *parent) noexcept {
  ::QFontComboBox *(*QFontComboBox_new$)(::QWidget *) = ::QFontComboBox_new;
  return QFontComboBox_new$(parent);
}

void cxxbridge1$205$QFontComboBox_delete(::QFontComboBox *cb) noexcept {
  void (*QFontComboBox_delete$)(::QFontComboBox *) = ::QFontComboBox_delete;
  QFontComboBox_delete$(cb);
}

void cxxbridge1$205$QFontComboBox_setCurrentFont(::QFontComboBox *cb, ::std::string const &family) noexcept {
  void (*QFontComboBox_setCurrentFont$)(::QFontComboBox *, ::std::string const &) = ::QFontComboBox_setCurrentFont;
  QFontComboBox_setCurrentFont$(cb, family);
}

void cxxbridge1$205$QFontComboBox_currentFont(::QFontComboBox *cb, ::rust::String *return$) noexcept {
  ::rust::String (*QFontComboBox_currentFont$)(::QFontComboBox *) = ::QFontComboBox_currentFont;
  new (return$) ::rust::String(QFontComboBox_currentFont$(cb));
}

void cxxbridge1$205$QFontComboBox_setFontFilters(::QFontComboBox *cb, ::std::int32_t filters) noexcept {
  void (*QFontComboBox_setFontFilters$)(::QFontComboBox *, ::std::int32_t) = ::QFontComboBox_setFontFilters;
  QFontComboBox_setFontFilters$(cb, filters);
}

void cxxbridge1$205$QFontComboBox_onCurrentFontChanged(::QFontComboBox *cb, ::std::uint64_t ctx) noexcept {
  void (*QFontComboBox_onCurrentFontChanged$)(::QFontComboBox *, ::std::uint64_t) = ::QFontComboBox_onCurrentFontChanged;
  QFontComboBox_onCurrentFontChanged$(cb, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QFontComboBox(::QFontComboBox *cb) noexcept {
  ::QWidget *(*toQWidget_QFontComboBox$)(::QFontComboBox *) = ::toQWidget_QFontComboBox;
  return toQWidget_QFontComboBox$(cb);
}

::QButtonGroup *cxxbridge1$205$QButtonGroup_new(::QObject *parent) noexcept {
  ::QButtonGroup *(*QButtonGroup_new$)(::QObject *) = ::QButtonGroup_new;
  return QButtonGroup_new$(parent);
}

void cxxbridge1$205$QButtonGroup_delete(::QButtonGroup *bg) noexcept {
  void (*QButtonGroup_delete$)(::QButtonGroup *) = ::QButtonGroup_delete;
  QButtonGroup_delete$(bg);
}

void cxxbridge1$205$QButtonGroup_addButton(::QButtonGroup *bg, ::QAbstractButton *btn, ::std::int32_t id) noexcept {
  void (*QButtonGroup_addButton$)(::QButtonGroup *, ::QAbstractButton *, ::std::int32_t) = ::QButtonGroup_addButton;
  QButtonGroup_addButton$(bg, btn, id);
}

void cxxbridge1$205$QButtonGroup_setExclusive(::QButtonGroup *bg, bool exclusive) noexcept {
  void (*QButtonGroup_setExclusive$)(::QButtonGroup *, bool) = ::QButtonGroup_setExclusive;
  QButtonGroup_setExclusive$(bg, exclusive);
}

void cxxbridge1$205$QButtonGroup_onButtonClicked(::QButtonGroup *bg, ::std::uint64_t ctx) noexcept {
  void (*QButtonGroup_onButtonClicked$)(::QButtonGroup *, ::std::uint64_t) = ::QButtonGroup_onButtonClicked;
  QButtonGroup_onButtonClicked$(bg, ctx);
}

::QKeySequenceEdit *cxxbridge1$205$QKeySequenceEdit_new(::QWidget *parent) noexcept {
  ::QKeySequenceEdit *(*QKeySequenceEdit_new$)(::QWidget *) = ::QKeySequenceEdit_new;
  return QKeySequenceEdit_new$(parent);
}

void cxxbridge1$205$QKeySequenceEdit_delete(::QKeySequenceEdit *e) noexcept {
  void (*QKeySequenceEdit_delete$)(::QKeySequenceEdit *) = ::QKeySequenceEdit_delete;
  QKeySequenceEdit_delete$(e);
}

void cxxbridge1$205$QKeySequenceEdit_clear(::QKeySequenceEdit *e) noexcept {
  void (*QKeySequenceEdit_clear$)(::QKeySequenceEdit *) = ::QKeySequenceEdit_clear;
  QKeySequenceEdit_clear$(e);
}

void cxxbridge1$205$QKeySequenceEdit_onEditingFinished(::QKeySequenceEdit *e, ::std::uint64_t ctx) noexcept {
  void (*QKeySequenceEdit_onEditingFinished$)(::QKeySequenceEdit *, ::std::uint64_t) = ::QKeySequenceEdit_onEditingFinished;
  QKeySequenceEdit_onEditingFinished$(e, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QKeySequenceEdit(::QKeySequenceEdit *e) noexcept {
  ::QWidget *(*toQWidget_QKeySequenceEdit$)(::QKeySequenceEdit *) = ::toQWidget_QKeySequenceEdit;
  return toQWidget_QKeySequenceEdit$(e);
}

::QStringListModel *cxxbridge1$205$QStringListModel_new(::QObject *parent) noexcept {
  ::QStringListModel *(*QStringListModel_new$)(::QObject *) = ::QStringListModel_new;
  return QStringListModel_new$(parent);
}

void cxxbridge1$205$QStringListModel_delete(::QStringListModel *m) noexcept {
  void (*QStringListModel_delete$)(::QStringListModel *) = ::QStringListModel_delete;
  QStringListModel_delete$(m);
}

void cxxbridge1$205$QStringListModel_setStringList(::QStringListModel *m, ::rust::Vec<::rust::String> const *list) noexcept {
  void (*QStringListModel_setStringList$)(::QStringListModel *, ::rust::Vec<::rust::String>) = ::QStringListModel_setStringList;
  QStringListModel_setStringList$(m, ::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *list));
}

void cxxbridge1$205$QStringListModel_data(::QStringListModel *m, ::std::int32_t row, ::rust::String *return$) noexcept {
  ::rust::String (*QStringListModel_data$)(::QStringListModel *, ::std::int32_t) = ::QStringListModel_data;
  new (return$) ::rust::String(QStringListModel_data$(m, row));
}

::std::int32_t cxxbridge1$205$QStringListModel_rowCount(::QStringListModel *m) noexcept {
  ::std::int32_t (*QStringListModel_rowCount$)(::QStringListModel *) = ::QStringListModel_rowCount;
  return QStringListModel_rowCount$(m);
}

::QSortFilterProxyModel *cxxbridge1$205$QSortFilterProxyModel_new(::QObject *parent) noexcept {
  ::QSortFilterProxyModel *(*QSortFilterProxyModel_new$)(::QObject *) = ::QSortFilterProxyModel_new;
  return QSortFilterProxyModel_new$(parent);
}

void cxxbridge1$205$QSortFilterProxyModel_delete(::QSortFilterProxyModel *m) noexcept {
  void (*QSortFilterProxyModel_delete$)(::QSortFilterProxyModel *) = ::QSortFilterProxyModel_delete;
  QSortFilterProxyModel_delete$(m);
}

void cxxbridge1$205$QSortFilterProxyModel_setSourceModel(::QSortFilterProxyModel *m, ::QStandardItemModel *src) noexcept {
  void (*QSortFilterProxyModel_setSourceModel$)(::QSortFilterProxyModel *, ::QStandardItemModel *) = ::QSortFilterProxyModel_setSourceModel;
  QSortFilterProxyModel_setSourceModel$(m, src);
}

void cxxbridge1$205$QSortFilterProxyModel_setFilterRole(::QSortFilterProxyModel *m, ::std::int32_t role) noexcept {
  void (*QSortFilterProxyModel_setFilterRole$)(::QSortFilterProxyModel *, ::std::int32_t) = ::QSortFilterProxyModel_setFilterRole;
  QSortFilterProxyModel_setFilterRole$(m, role);
}

void cxxbridge1$205$QSortFilterProxyModel_setFilterFixedString(::QSortFilterProxyModel *m, ::std::string const &text) noexcept {
  void (*QSortFilterProxyModel_setFilterFixedString$)(::QSortFilterProxyModel *, ::std::string const &) = ::QSortFilterProxyModel_setFilterFixedString;
  QSortFilterProxyModel_setFilterFixedString$(m, text);
}

void cxxbridge1$205$QSortFilterProxyModel_setFilterCaseSensitivity(::QSortFilterProxyModel *m, ::std::int32_t cs) noexcept {
  void (*QSortFilterProxyModel_setFilterCaseSensitivity$)(::QSortFilterProxyModel *, ::std::int32_t) = ::QSortFilterProxyModel_setFilterCaseSensitivity;
  QSortFilterProxyModel_setFilterCaseSensitivity$(m, cs);
}

void cxxbridge1$205$QSortFilterProxyModel_setSortRole(::QSortFilterProxyModel *m, ::std::int32_t role) noexcept {
  void (*QSortFilterProxyModel_setSortRole$)(::QSortFilterProxyModel *, ::std::int32_t) = ::QSortFilterProxyModel_setSortRole;
  QSortFilterProxyModel_setSortRole$(m, role);
}

void cxxbridge1$205$QSortFilterProxyModel_sort(::QSortFilterProxyModel *m, ::std::int32_t col, ::std::int32_t order) noexcept {
  void (*QSortFilterProxyModel_sort$)(::QSortFilterProxyModel *, ::std::int32_t, ::std::int32_t) = ::QSortFilterProxyModel_sort;
  QSortFilterProxyModel_sort$(m, col, order);
}

::QCompleter *cxxbridge1$205$QCompleter_new(::QStringListModel *model, ::QObject *parent) noexcept {
  ::QCompleter *(*QCompleter_new$)(::QStringListModel *, ::QObject *) = ::QCompleter_new;
  return QCompleter_new$(model, parent);
}

void cxxbridge1$205$QCompleter_delete(::QCompleter *c) noexcept {
  void (*QCompleter_delete$)(::QCompleter *) = ::QCompleter_delete;
  QCompleter_delete$(c);
}

void cxxbridge1$205$QCompleter_setCompletionMode(::QCompleter *c, ::std::int32_t mode) noexcept {
  void (*QCompleter_setCompletionMode$)(::QCompleter *, ::std::int32_t) = ::QCompleter_setCompletionMode;
  QCompleter_setCompletionMode$(c, mode);
}

void cxxbridge1$205$QCompleter_setCaseSensitivity(::QCompleter *c, ::std::int32_t cs) noexcept {
  void (*QCompleter_setCaseSensitivity$)(::QCompleter *, ::std::int32_t) = ::QCompleter_setCaseSensitivity;
  QCompleter_setCaseSensitivity$(c, cs);
}

void cxxbridge1$205$QCompleter_setFilterMode(::QCompleter *c, ::std::int32_t mode) noexcept {
  void (*QCompleter_setFilterMode$)(::QCompleter *, ::std::int32_t) = ::QCompleter_setFilterMode;
  QCompleter_setFilterMode$(c, mode);
}

void cxxbridge1$205$QCompleter_onActivated(::QCompleter *c, ::std::uint64_t ctx) noexcept {
  void (*QCompleter_onActivated$)(::QCompleter *, ::std::uint64_t) = ::QCompleter_onActivated;
  QCompleter_onActivated$(c, ctx);
}

void cxxbridge1$205$QClipboard_setText(::std::string const &text) noexcept {
  void (*QClipboard_setText$)(::std::string const &) = ::QClipboard_setText;
  QClipboard_setText$(text);
}

void cxxbridge1$205$QClipboard_text(::rust::String *return$) noexcept {
  ::rust::String (*QClipboard_text$)() = ::QClipboard_text;
  new (return$) ::rust::String(QClipboard_text$());
}

void cxxbridge1$205$QClipboard_clear() noexcept {
  void (*QClipboard_clear$)() = ::QClipboard_clear;
  QClipboard_clear$();
}

bool cxxbridge1$205$QDesktopServices_openUrl(::std::string const &url) noexcept {
  bool (*QDesktopServices_openUrl$)(::std::string const &) = ::QDesktopServices_openUrl;
  return QDesktopServices_openUrl$(url);
}

::QUndoStack *cxxbridge1$205$QUndoStack_new(::QObject *parent) noexcept {
  ::QUndoStack *(*QUndoStack_new$)(::QObject *) = ::QUndoStack_new;
  return QUndoStack_new$(parent);
}

void cxxbridge1$205$QUndoStack_delete(::QUndoStack *s) noexcept {
  void (*QUndoStack_delete$)(::QUndoStack *) = ::QUndoStack_delete;
  QUndoStack_delete$(s);
}

void cxxbridge1$205$QUndoStack_undo(::QUndoStack *s) noexcept {
  void (*QUndoStack_undo$)(::QUndoStack *) = ::QUndoStack_undo;
  QUndoStack_undo$(s);
}

void cxxbridge1$205$QUndoStack_redo(::QUndoStack *s) noexcept {
  void (*QUndoStack_redo$)(::QUndoStack *) = ::QUndoStack_redo;
  QUndoStack_redo$(s);
}

void cxxbridge1$205$QUndoStack_clear(::QUndoStack *s) noexcept {
  void (*QUndoStack_clear$)(::QUndoStack *) = ::QUndoStack_clear;
  QUndoStack_clear$(s);
}

bool cxxbridge1$205$QUndoStack_canUndo(::QUndoStack *s) noexcept {
  bool (*QUndoStack_canUndo$)(::QUndoStack *) = ::QUndoStack_canUndo;
  return QUndoStack_canUndo$(s);
}

bool cxxbridge1$205$QUndoStack_canRedo(::QUndoStack *s) noexcept {
  bool (*QUndoStack_canRedo$)(::QUndoStack *) = ::QUndoStack_canRedo;
  return QUndoStack_canRedo$(s);
}

::std::int32_t cxxbridge1$205$QUndoStack_count(::QUndoStack *s) noexcept {
  ::std::int32_t (*QUndoStack_count$)(::QUndoStack *) = ::QUndoStack_count;
  return QUndoStack_count$(s);
}

::QIntValidator *cxxbridge1$205$QIntValidator_new(::QObject *parent) noexcept {
  ::QIntValidator *(*QIntValidator_new$)(::QObject *) = ::QIntValidator_new;
  return QIntValidator_new$(parent);
}

void cxxbridge1$205$QIntValidator_delete(::QIntValidator *v) noexcept {
  void (*QIntValidator_delete$)(::QIntValidator *) = ::QIntValidator_delete;
  QIntValidator_delete$(v);
}

void cxxbridge1$205$QIntValidator_setRange(::QIntValidator *v, ::std::int32_t min, ::std::int32_t max) noexcept {
  void (*QIntValidator_setRange$)(::QIntValidator *, ::std::int32_t, ::std::int32_t) = ::QIntValidator_setRange;
  QIntValidator_setRange$(v, min, max);
}

void cxxbridge1$205$QIntValidator_setBottom(::QIntValidator *v, ::std::int32_t bottom) noexcept {
  void (*QIntValidator_setBottom$)(::QIntValidator *, ::std::int32_t) = ::QIntValidator_setBottom;
  QIntValidator_setBottom$(v, bottom);
}

void cxxbridge1$205$QIntValidator_setTop(::QIntValidator *v, ::std::int32_t top) noexcept {
  void (*QIntValidator_setTop$)(::QIntValidator *, ::std::int32_t) = ::QIntValidator_setTop;
  QIntValidator_setTop$(v, top);
}

::QDoubleValidator *cxxbridge1$205$QDoubleValidator_new(::QObject *parent) noexcept {
  ::QDoubleValidator *(*QDoubleValidator_new$)(::QObject *) = ::QDoubleValidator_new;
  return QDoubleValidator_new$(parent);
}

void cxxbridge1$205$QDoubleValidator_delete(::QDoubleValidator *v) noexcept {
  void (*QDoubleValidator_delete$)(::QDoubleValidator *) = ::QDoubleValidator_delete;
  QDoubleValidator_delete$(v);
}

void cxxbridge1$205$QDoubleValidator_setRange(::QDoubleValidator *v, double min, double max, ::std::int32_t decimals) noexcept {
  void (*QDoubleValidator_setRange$)(::QDoubleValidator *, double, double, ::std::int32_t) = ::QDoubleValidator_setRange;
  QDoubleValidator_setRange$(v, min, max, decimals);
}

void cxxbridge1$205$QWidget_setCursor(::QWidget *widget, ::std::int32_t shape) noexcept {
  void (*QWidget_setCursor$)(::QWidget *, ::std::int32_t) = ::QWidget_setCursor;
  QWidget_setCursor$(widget, shape);
}

void cxxbridge1$205$QWidget_unsetCursor(::QWidget *widget) noexcept {
  void (*QWidget_unsetCursor$)(::QWidget *) = ::QWidget_unsetCursor;
  QWidget_unsetCursor$(widget);
}

::QFileSystemModel *cxxbridge1$205$QFileSystemModel_new(::QObject *parent) noexcept {
  ::QFileSystemModel *(*QFileSystemModel_new$)(::QObject *) = ::QFileSystemModel_new;
  return QFileSystemModel_new$(parent);
}

void cxxbridge1$205$QFileSystemModel_delete(::QFileSystemModel *m) noexcept {
  void (*QFileSystemModel_delete$)(::QFileSystemModel *) = ::QFileSystemModel_delete;
  QFileSystemModel_delete$(m);
}

void cxxbridge1$205$QFileSystemModel_setRootPath(::QFileSystemModel *m, ::std::string const &path) noexcept {
  void (*QFileSystemModel_setRootPath$)(::QFileSystemModel *, ::std::string const &) = ::QFileSystemModel_setRootPath;
  QFileSystemModel_setRootPath$(m, path);
}

void cxxbridge1$205$QFileSystemModel_rootPath(::QFileSystemModel *m, ::rust::String *return$) noexcept {
  ::rust::String (*QFileSystemModel_rootPath$)(::QFileSystemModel *) = ::QFileSystemModel_rootPath;
  new (return$) ::rust::String(QFileSystemModel_rootPath$(m));
}

void cxxbridge1$205$QFileSystemModel_filePath(::QFileSystemModel *m, ::std::int32_t idx_row, ::std::int32_t idx_col, ::rust::String *return$) noexcept {
  ::rust::String (*QFileSystemModel_filePath$)(::QFileSystemModel *, ::std::int32_t, ::std::int32_t) = ::QFileSystemModel_filePath;
  new (return$) ::rust::String(QFileSystemModel_filePath$(m, idx_row, idx_col));
}

bool cxxbridge1$205$QFileSystemModel_isDir(::QFileSystemModel *m, ::std::int32_t idx_row, ::std::int32_t idx_col) noexcept {
  bool (*QFileSystemModel_isDir$)(::QFileSystemModel *, ::std::int32_t, ::std::int32_t) = ::QFileSystemModel_isDir;
  return QFileSystemModel_isDir$(m, idx_row, idx_col);
}

::QHeaderView *cxxbridge1$205$QHeaderView_new(::std::int32_t orientation, ::QWidget *parent) noexcept {
  ::QHeaderView *(*QHeaderView_new$)(::std::int32_t, ::QWidget *) = ::QHeaderView_new;
  return QHeaderView_new$(orientation, parent);
}

void cxxbridge1$205$QHeaderView_delete(::QHeaderView *h) noexcept {
  void (*QHeaderView_delete$)(::QHeaderView *) = ::QHeaderView_delete;
  QHeaderView_delete$(h);
}

void cxxbridge1$205$QHeaderView_setStretchLastSection(::QHeaderView *h, bool stretch) noexcept {
  void (*QHeaderView_setStretchLastSection$)(::QHeaderView *, bool) = ::QHeaderView_setStretchLastSection;
  QHeaderView_setStretchLastSection$(h, stretch);
}

void cxxbridge1$205$QHeaderView_resizeSection(::QHeaderView *h, ::std::int32_t section, ::std::int32_t size) noexcept {
  void (*QHeaderView_resizeSection$)(::QHeaderView *, ::std::int32_t, ::std::int32_t) = ::QHeaderView_resizeSection;
  QHeaderView_resizeSection$(h, section, size);
}

void cxxbridge1$205$QHeaderView_hideSection(::QHeaderView *h, ::std::int32_t section) noexcept {
  void (*QHeaderView_hideSection$)(::QHeaderView *, ::std::int32_t) = ::QHeaderView_hideSection;
  QHeaderView_hideSection$(h, section);
}

void cxxbridge1$205$QHeaderView_showSection(::QHeaderView *h, ::std::int32_t section) noexcept {
  void (*QHeaderView_showSection$)(::QHeaderView *, ::std::int32_t) = ::QHeaderView_showSection;
  QHeaderView_showSection$(h, section);
}

void cxxbridge1$205$QHeaderView_setSectionResizeMode(::QHeaderView *h, ::std::int32_t mode) noexcept {
  void (*QHeaderView_setSectionResizeMode$)(::QHeaderView *, ::std::int32_t) = ::QHeaderView_setSectionResizeMode;
  QHeaderView_setSectionResizeMode$(h, mode);
}

::QWidget *cxxbridge1$205$toQWidget_QHeaderView(::QHeaderView *h) noexcept {
  ::QWidget *(*toQWidget_QHeaderView$)(::QHeaderView *) = ::toQWidget_QHeaderView;
  return toQWidget_QHeaderView$(h);
}

::QWizard *cxxbridge1$205$QWizard_new(::QWidget *parent) noexcept {
  ::QWizard *(*QWizard_new$)(::QWidget *) = ::QWizard_new;
  return QWizard_new$(parent);
}

void cxxbridge1$205$QWizard_delete(::QWizard *w) noexcept {
  void (*QWizard_delete$)(::QWizard *) = ::QWizard_delete;
  QWizard_delete$(w);
}

void cxxbridge1$205$QWizard_addPage(::QWizard *w, ::QWizardPage *page) noexcept {
  void (*QWizard_addPage$)(::QWizard *, ::QWizardPage *) = ::QWizard_addPage;
  QWizard_addPage$(w, page);
}

void cxxbridge1$205$QWizard_setWindowTitle(::QWizard *w, ::std::string const &title) noexcept {
  void (*QWizard_setWindowTitle$)(::QWizard *, ::std::string const &) = ::QWizard_setWindowTitle;
  QWizard_setWindowTitle$(w, title);
}

void cxxbridge1$205$QWizard_next(::QWizard *w) noexcept {
  void (*QWizard_next$)(::QWizard *) = ::QWizard_next;
  QWizard_next$(w);
}

void cxxbridge1$205$QWizard_back(::QWizard *w) noexcept {
  void (*QWizard_back$)(::QWizard *) = ::QWizard_back;
  QWizard_back$(w);
}

void cxxbridge1$205$QWizard_restart(::QWizard *w) noexcept {
  void (*QWizard_restart$)(::QWizard *) = ::QWizard_restart;
  QWizard_restart$(w);
}

::std::int32_t cxxbridge1$205$QWizard_currentId(::QWizard *w) noexcept {
  ::std::int32_t (*QWizard_currentId$)(::QWizard *) = ::QWizard_currentId;
  return QWizard_currentId$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QWizard(::QWizard *w) noexcept {
  ::QWidget *(*toQWidget_QWizard$)(::QWizard *) = ::toQWidget_QWizard;
  return toQWidget_QWizard$(w);
}

::QWizardPage *cxxbridge1$205$QWizardPage_new(::QWidget *parent) noexcept {
  ::QWizardPage *(*QWizardPage_new$)(::QWidget *) = ::QWizardPage_new;
  return QWizardPage_new$(parent);
}

void cxxbridge1$205$QWizardPage_delete(::QWizardPage *p) noexcept {
  void (*QWizardPage_delete$)(::QWizardPage *) = ::QWizardPage_delete;
  QWizardPage_delete$(p);
}

void cxxbridge1$205$QWizardPage_setTitle(::QWizardPage *p, ::std::string const &title) noexcept {
  void (*QWizardPage_setTitle$)(::QWizardPage *, ::std::string const &) = ::QWizardPage_setTitle;
  QWizardPage_setTitle$(p, title);
}

void cxxbridge1$205$QWizardPage_setSubTitle(::QWizardPage *p, ::std::string const &subtitle) noexcept {
  void (*QWizardPage_setSubTitle$)(::QWizardPage *, ::std::string const &) = ::QWizardPage_setSubTitle;
  QWizardPage_setSubTitle$(p, subtitle);
}

::QWidget *cxxbridge1$205$toQWidget_QWizardPage(::QWizardPage *p) noexcept {
  ::QWidget *(*toQWidget_QWizardPage$)(::QWizardPage *) = ::toQWidget_QWizardPage;
  return toQWidget_QWizardPage$(p);
}

::QColumnView *cxxbridge1$205$QColumnView_new(::QWidget *parent) noexcept {
  ::QColumnView *(*QColumnView_new$)(::QWidget *) = ::QColumnView_new;
  return QColumnView_new$(parent);
}

void cxxbridge1$205$QColumnView_delete(::QColumnView *v) noexcept {
  void (*QColumnView_delete$)(::QColumnView *) = ::QColumnView_delete;
  QColumnView_delete$(v);
}

void cxxbridge1$205$QColumnView_setModel(::QColumnView *v, ::QStandardItemModel *model) noexcept {
  void (*QColumnView_setModel$)(::QColumnView *, ::QStandardItemModel *) = ::QColumnView_setModel;
  QColumnView_setModel$(v, model);
}

::QWidget *cxxbridge1$205$toQWidget_QColumnView(::QColumnView *v) noexcept {
  ::QWidget *(*toQWidget_QColumnView$)(::QColumnView *) = ::toQWidget_QColumnView;
  return toQWidget_QColumnView$(v);
}

::QStandardItemModel *cxxbridge1$205$QStandardItemModel_new(::QObject *parent) noexcept {
  ::QStandardItemModel *(*QStandardItemModel_new$)(::QObject *) = ::QStandardItemModel_new;
  return QStandardItemModel_new$(parent);
}

void cxxbridge1$205$QStandardItemModel_delete(::QStandardItemModel *model) noexcept {
  void (*QStandardItemModel_delete$)(::QStandardItemModel *) = ::QStandardItemModel_delete;
  QStandardItemModel_delete$(model);
}

::std::int32_t cxxbridge1$205$QStandardItemModel_rowCount(::QStandardItemModel *model) noexcept {
  ::std::int32_t (*QStandardItemModel_rowCount$)(::QStandardItemModel *) = ::QStandardItemModel_rowCount;
  return QStandardItemModel_rowCount$(model);
}

::std::int32_t cxxbridge1$205$QStandardItemModel_columnCount(::QStandardItemModel *model) noexcept {
  ::std::int32_t (*QStandardItemModel_columnCount$)(::QStandardItemModel *) = ::QStandardItemModel_columnCount;
  return QStandardItemModel_columnCount$(model);
}

void cxxbridge1$205$QStandardItemModel_setRowCount(::QStandardItemModel *model, ::std::int32_t rows) noexcept {
  void (*QStandardItemModel_setRowCount$)(::QStandardItemModel *, ::std::int32_t) = ::QStandardItemModel_setRowCount;
  QStandardItemModel_setRowCount$(model, rows);
}

void cxxbridge1$205$QStandardItemModel_setColumnCount(::QStandardItemModel *model, ::std::int32_t cols) noexcept {
  void (*QStandardItemModel_setColumnCount$)(::QStandardItemModel *, ::std::int32_t) = ::QStandardItemModel_setColumnCount;
  QStandardItemModel_setColumnCount$(model, cols);
}

void cxxbridge1$205$QStandardItemModel_setData(::QStandardItemModel *model, ::std::int32_t row, ::std::int32_t col, ::std::string const &value) noexcept {
  void (*QStandardItemModel_setData$)(::QStandardItemModel *, ::std::int32_t, ::std::int32_t, ::std::string const &) = ::QStandardItemModel_setData;
  QStandardItemModel_setData$(model, row, col, value);
}

void cxxbridge1$205$QStandardItemModel_data(::QStandardItemModel *model, ::std::int32_t row, ::std::int32_t col, ::rust::String *return$) noexcept {
  ::rust::String (*QStandardItemModel_data$)(::QStandardItemModel *, ::std::int32_t, ::std::int32_t) = ::QStandardItemModel_data;
  new (return$) ::rust::String(QStandardItemModel_data$(model, row, col));
}

void cxxbridge1$205$QStandardItemModel_setHeaderData(::QStandardItemModel *model, ::std::int32_t section, ::std::int32_t orientation, ::std::string const &value) noexcept {
  void (*QStandardItemModel_setHeaderData$)(::QStandardItemModel *, ::std::int32_t, ::std::int32_t, ::std::string const &) = ::QStandardItemModel_setHeaderData;
  QStandardItemModel_setHeaderData$(model, section, orientation, value);
}

void cxxbridge1$205$QStandardItemModel_headerData(::QStandardItemModel *model, ::std::int32_t section, ::std::int32_t orientation, ::rust::String *return$) noexcept {
  ::rust::String (*QStandardItemModel_headerData$)(::QStandardItemModel *, ::std::int32_t, ::std::int32_t) = ::QStandardItemModel_headerData;
  new (return$) ::rust::String(QStandardItemModel_headerData$(model, section, orientation));
}

void cxxbridge1$205$QStandardItemModel_insertRow(::QStandardItemModel *model, ::std::int32_t row) noexcept {
  void (*QStandardItemModel_insertRow$)(::QStandardItemModel *, ::std::int32_t) = ::QStandardItemModel_insertRow;
  QStandardItemModel_insertRow$(model, row);
}

void cxxbridge1$205$QStandardItemModel_removeRow(::QStandardItemModel *model, ::std::int32_t row) noexcept {
  void (*QStandardItemModel_removeRow$)(::QStandardItemModel *, ::std::int32_t) = ::QStandardItemModel_removeRow;
  QStandardItemModel_removeRow$(model, row);
}

void cxxbridge1$205$QStandardItemModel_insertColumn(::QStandardItemModel *model, ::std::int32_t column) noexcept {
  void (*QStandardItemModel_insertColumn$)(::QStandardItemModel *, ::std::int32_t) = ::QStandardItemModel_insertColumn;
  QStandardItemModel_insertColumn$(model, column);
}

void cxxbridge1$205$QStandardItemModel_removeColumn(::QStandardItemModel *model, ::std::int32_t column) noexcept {
  void (*QStandardItemModel_removeColumn$)(::QStandardItemModel *, ::std::int32_t) = ::QStandardItemModel_removeColumn;
  QStandardItemModel_removeColumn$(model, column);
}

void cxxbridge1$205$QStandardItemModel_clear(::QStandardItemModel *model) noexcept {
  void (*QStandardItemModel_clear$)(::QStandardItemModel *) = ::QStandardItemModel_clear;
  QStandardItemModel_clear$(model);
}

void cxxbridge1$205$QStandardItemModel_appendRow(::QStandardItemModel *model, ::rust::Vec<::rust::String> const *texts) noexcept {
  void (*QStandardItemModel_appendRow$)(::QStandardItemModel *, ::rust::Vec<::rust::String>) = ::QStandardItemModel_appendRow;
  QStandardItemModel_appendRow$(model, ::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *texts));
}

void cxxbridge1$205$QStandardItemModel_onModelReset(::QStandardItemModel *model, ::std::uint64_t ctx) noexcept {
  void (*QStandardItemModel_onModelReset$)(::QStandardItemModel *, ::std::uint64_t) = ::QStandardItemModel_onModelReset;
  QStandardItemModel_onModelReset$(model, ctx);
}

void cxxbridge1$205$QStandardItemModel_onDataChanged(::QStandardItemModel *model, ::std::uint64_t ctx) noexcept {
  void (*QStandardItemModel_onDataChanged$)(::QStandardItemModel *, ::std::uint64_t) = ::QStandardItemModel_onDataChanged;
  QStandardItemModel_onDataChanged$(model, ctx);
}

void cxxbridge1$205$QStandardItemModel_onRowsInserted(::QStandardItemModel *model, ::std::uint64_t ctx) noexcept {
  void (*QStandardItemModel_onRowsInserted$)(::QStandardItemModel *, ::std::uint64_t) = ::QStandardItemModel_onRowsInserted;
  QStandardItemModel_onRowsInserted$(model, ctx);
}

void cxxbridge1$205$QStandardItemModel_onRowsRemoved(::QStandardItemModel *model, ::std::uint64_t ctx) noexcept {
  void (*QStandardItemModel_onRowsRemoved$)(::QStandardItemModel *, ::std::uint64_t) = ::QStandardItemModel_onRowsRemoved;
  QStandardItemModel_onRowsRemoved$(model, ctx);
}

::QTableView *cxxbridge1$205$QTableView_new(::QWidget *parent) noexcept {
  ::QTableView *(*QTableView_new$)(::QWidget *) = ::QTableView_new;
  return QTableView_new$(parent);
}

void cxxbridge1$205$QTableView_delete(::QTableView *view) noexcept {
  void (*QTableView_delete$)(::QTableView *) = ::QTableView_delete;
  QTableView_delete$(view);
}

void cxxbridge1$205$QTableView_setModel(::QTableView *view, ::QStandardItemModel *model) noexcept {
  void (*QTableView_setModel$)(::QTableView *, ::QStandardItemModel *) = ::QTableView_setModel;
  QTableView_setModel$(view, model);
}

::QStandardItemModel *cxxbridge1$205$QTableView_model(::QTableView *view) noexcept {
  ::QStandardItemModel *(*QTableView_model$)(::QTableView *) = ::QTableView_model;
  return QTableView_model$(view);
}

void cxxbridge1$205$QTableView_setSelectionMode(::QTableView *view, ::std::int32_t mode) noexcept {
  void (*QTableView_setSelectionMode$)(::QTableView *, ::std::int32_t) = ::QTableView_setSelectionMode;
  QTableView_setSelectionMode$(view, mode);
}

void cxxbridge1$205$QTableView_setSelectionBehavior(::QTableView *view, ::std::int32_t behavior) noexcept {
  void (*QTableView_setSelectionBehavior$)(::QTableView *, ::std::int32_t) = ::QTableView_setSelectionBehavior;
  QTableView_setSelectionBehavior$(view, behavior);
}

void cxxbridge1$205$QTableView_setShowGrid(::QTableView *view, bool show) noexcept {
  void (*QTableView_setShowGrid$)(::QTableView *, bool) = ::QTableView_setShowGrid;
  QTableView_setShowGrid$(view, show);
}

void cxxbridge1$205$QTableView_setAlternatingRowColors(::QTableView *view, bool enable) noexcept {
  void (*QTableView_setAlternatingRowColors$)(::QTableView *, bool) = ::QTableView_setAlternatingRowColors;
  QTableView_setAlternatingRowColors$(view, enable);
}

void cxxbridge1$205$QTableView_setSortingEnabled(::QTableView *view, bool enable) noexcept {
  void (*QTableView_setSortingEnabled$)(::QTableView *, bool) = ::QTableView_setSortingEnabled;
  QTableView_setSortingEnabled$(view, enable);
}

void cxxbridge1$205$QTableView_resizeColumnsToContents(::QTableView *view) noexcept {
  void (*QTableView_resizeColumnsToContents$)(::QTableView *) = ::QTableView_resizeColumnsToContents;
  QTableView_resizeColumnsToContents$(view);
}

void cxxbridge1$205$QTableView_resizeRowsToContents(::QTableView *view) noexcept {
  void (*QTableView_resizeRowsToContents$)(::QTableView *) = ::QTableView_resizeRowsToContents;
  QTableView_resizeRowsToContents$(view);
}

void cxxbridge1$205$QTableView_selectRow(::QTableView *view, ::std::int32_t row) noexcept {
  void (*QTableView_selectRow$)(::QTableView *, ::std::int32_t) = ::QTableView_selectRow;
  QTableView_selectRow$(view, row);
}

void cxxbridge1$205$QTableView_clearSelection(::QTableView *view) noexcept {
  void (*QTableView_clearSelection$)(::QTableView *) = ::QTableView_clearSelection;
  QTableView_clearSelection$(view);
}

void cxxbridge1$205$QTableView_onClicked(::QTableView *view, ::std::uint64_t ctx) noexcept {
  void (*QTableView_onClicked$)(::QTableView *, ::std::uint64_t) = ::QTableView_onClicked;
  QTableView_onClicked$(view, ctx);
}

void cxxbridge1$205$QTableView_onDoubleClicked(::QTableView *view, ::std::uint64_t ctx) noexcept {
  void (*QTableView_onDoubleClicked$)(::QTableView *, ::std::uint64_t) = ::QTableView_onDoubleClicked;
  QTableView_onDoubleClicked$(view, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QTableView(::QTableView *view) noexcept {
  ::QWidget *(*toQWidget_QTableView$)(::QTableView *) = ::toQWidget_QTableView;
  return toQWidget_QTableView$(view);
}

::QListView *cxxbridge1$205$QListView_new(::QWidget *parent) noexcept {
  ::QListView *(*QListView_new$)(::QWidget *) = ::QListView_new;
  return QListView_new$(parent);
}

void cxxbridge1$205$QListView_delete(::QListView *view) noexcept {
  void (*QListView_delete$)(::QListView *) = ::QListView_delete;
  QListView_delete$(view);
}

void cxxbridge1$205$QListView_setModel(::QListView *view, ::QStandardItemModel *model) noexcept {
  void (*QListView_setModel$)(::QListView *, ::QStandardItemModel *) = ::QListView_setModel;
  QListView_setModel$(view, model);
}

::QStandardItemModel *cxxbridge1$205$QListView_model(::QListView *view) noexcept {
  ::QStandardItemModel *(*QListView_model$)(::QListView *) = ::QListView_model;
  return QListView_model$(view);
}

void cxxbridge1$205$QListView_setSelectionMode(::QListView *view, ::std::int32_t mode) noexcept {
  void (*QListView_setSelectionMode$)(::QListView *, ::std::int32_t) = ::QListView_setSelectionMode;
  QListView_setSelectionMode$(view, mode);
}

void cxxbridge1$205$QListView_setViewMode(::QListView *view, ::std::int32_t mode) noexcept {
  void (*QListView_setViewMode$)(::QListView *, ::std::int32_t) = ::QListView_setViewMode;
  QListView_setViewMode$(view, mode);
}

void cxxbridge1$205$QListView_onClicked(::QListView *view, ::std::uint64_t ctx) noexcept {
  void (*QListView_onClicked$)(::QListView *, ::std::uint64_t) = ::QListView_onClicked;
  QListView_onClicked$(view, ctx);
}

void cxxbridge1$205$QListView_onDoubleClicked(::QListView *view, ::std::uint64_t ctx) noexcept {
  void (*QListView_onDoubleClicked$)(::QListView *, ::std::uint64_t) = ::QListView_onDoubleClicked;
  QListView_onDoubleClicked$(view, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QListView(::QListView *view) noexcept {
  ::QWidget *(*toQWidget_QListView$)(::QListView *) = ::toQWidget_QListView;
  return toQWidget_QListView$(view);
}

::QTreeView *cxxbridge1$205$QTreeView_new(::QWidget *parent) noexcept {
  ::QTreeView *(*QTreeView_new$)(::QWidget *) = ::QTreeView_new;
  return QTreeView_new$(parent);
}

void cxxbridge1$205$QTreeView_delete(::QTreeView *view) noexcept {
  void (*QTreeView_delete$)(::QTreeView *) = ::QTreeView_delete;
  QTreeView_delete$(view);
}

void cxxbridge1$205$QTreeView_setModel(::QTreeView *view, ::QStandardItemModel *model) noexcept {
  void (*QTreeView_setModel$)(::QTreeView *, ::QStandardItemModel *) = ::QTreeView_setModel;
  QTreeView_setModel$(view, model);
}

::QStandardItemModel *cxxbridge1$205$QTreeView_model(::QTreeView *view) noexcept {
  ::QStandardItemModel *(*QTreeView_model$)(::QTreeView *) = ::QTreeView_model;
  return QTreeView_model$(view);
}

void cxxbridge1$205$QTreeView_setSelectionMode(::QTreeView *view, ::std::int32_t mode) noexcept {
  void (*QTreeView_setSelectionMode$)(::QTreeView *, ::std::int32_t) = ::QTreeView_setSelectionMode;
  QTreeView_setSelectionMode$(view, mode);
}

void cxxbridge1$205$QTreeView_setHeaderHidden(::QTreeView *view, bool hidden) noexcept {
  void (*QTreeView_setHeaderHidden$)(::QTreeView *, bool) = ::QTreeView_setHeaderHidden;
  QTreeView_setHeaderHidden$(view, hidden);
}

void cxxbridge1$205$QTreeView_setAnimated(::QTreeView *view, bool animated) noexcept {
  void (*QTreeView_setAnimated$)(::QTreeView *, bool) = ::QTreeView_setAnimated;
  QTreeView_setAnimated$(view, animated);
}

void cxxbridge1$205$QTreeView_setIndentation(::QTreeView *view, ::std::int32_t indent) noexcept {
  void (*QTreeView_setIndentation$)(::QTreeView *, ::std::int32_t) = ::QTreeView_setIndentation;
  QTreeView_setIndentation$(view, indent);
}

void cxxbridge1$205$QTreeView_setRootIsDecorated(::QTreeView *view, bool decorated) noexcept {
  void (*QTreeView_setRootIsDecorated$)(::QTreeView *, bool) = ::QTreeView_setRootIsDecorated;
  QTreeView_setRootIsDecorated$(view, decorated);
}

void cxxbridge1$205$QTreeView_setItemsExpandable(::QTreeView *view, bool expandable) noexcept {
  void (*QTreeView_setItemsExpandable$)(::QTreeView *, bool) = ::QTreeView_setItemsExpandable;
  QTreeView_setItemsExpandable$(view, expandable);
}

void cxxbridge1$205$QTreeView_expandAll(::QTreeView *view) noexcept {
  void (*QTreeView_expandAll$)(::QTreeView *) = ::QTreeView_expandAll;
  QTreeView_expandAll$(view);
}

void cxxbridge1$205$QTreeView_collapseAll(::QTreeView *view) noexcept {
  void (*QTreeView_collapseAll$)(::QTreeView *) = ::QTreeView_collapseAll;
  QTreeView_collapseAll$(view);
}

void cxxbridge1$205$QTreeView_onClicked(::QTreeView *view, ::std::uint64_t ctx) noexcept {
  void (*QTreeView_onClicked$)(::QTreeView *, ::std::uint64_t) = ::QTreeView_onClicked;
  QTreeView_onClicked$(view, ctx);
}

void cxxbridge1$205$QTreeView_onDoubleClicked(::QTreeView *view, ::std::uint64_t ctx) noexcept {
  void (*QTreeView_onDoubleClicked$)(::QTreeView *, ::std::uint64_t) = ::QTreeView_onDoubleClicked;
  QTreeView_onDoubleClicked$(view, ctx);
}

void cxxbridge1$205$QTreeView_onExpanded(::QTreeView *view, ::std::uint64_t ctx) noexcept {
  void (*QTreeView_onExpanded$)(::QTreeView *, ::std::uint64_t) = ::QTreeView_onExpanded;
  QTreeView_onExpanded$(view, ctx);
}

void cxxbridge1$205$QTreeView_onCollapsed(::QTreeView *view, ::std::uint64_t ctx) noexcept {
  void (*QTreeView_onCollapsed$)(::QTreeView *, ::std::uint64_t) = ::QTreeView_onCollapsed;
  QTreeView_onCollapsed$(view, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QTreeView(::QTreeView *view) noexcept {
  ::QWidget *(*toQWidget_QTreeView$)(::QTreeView *) = ::toQWidget_QTreeView;
  return toQWidget_QTreeView$(view);
}

bool cxxbridge1$205$QItemSelectionModel_hasSelection(::QItemSelectionModel *sm) noexcept {
  bool (*QItemSelectionModel_hasSelection$)(::QItemSelectionModel *) = ::QItemSelectionModel_hasSelection;
  return QItemSelectionModel_hasSelection$(sm);
}

void cxxbridge1$205$QItemSelectionModel_onSelectionChanged(::QItemSelectionModel *sm, ::std::uint64_t ctx) noexcept {
  void (*QItemSelectionModel_onSelectionChanged$)(::QItemSelectionModel *, ::std::uint64_t) = ::QItemSelectionModel_onSelectionChanged;
  QItemSelectionModel_onSelectionChanged$(sm, ctx);
}

void cxxbridge1$205$QItemSelectionModel_onCurrentChanged(::QItemSelectionModel *sm, ::std::uint64_t ctx) noexcept {
  void (*QItemSelectionModel_onCurrentChanged$)(::QItemSelectionModel *, ::std::uint64_t) = ::QItemSelectionModel_onCurrentChanged;
  QItemSelectionModel_onCurrentChanged$(sm, ctx);
}

::QUiLoader *cxxbridge1$205$QUiLoader_new() noexcept {
  ::QUiLoader *(*QUiLoader_new$)() = ::QUiLoader_new;
  return QUiLoader_new$();
}

::QWidget *cxxbridge1$205$QUiLoader_load(::QUiLoader *loader, ::std::string const &ui_path, ::QWidget *parent) noexcept {
  ::QWidget *(*QUiLoader_load$)(::QUiLoader *, ::std::string const &, ::QWidget *) = ::QUiLoader_load;
  return QUiLoader_load$(loader, ui_path, parent);
}

void cxxbridge1$205$QUiLoader_delete(::QUiLoader *loader) noexcept {
  void (*QUiLoader_delete$)(::QUiLoader *) = ::QUiLoader_delete;
  QUiLoader_delete$(loader);
}

::QDialog *cxxbridge1$205$QDialog_new(::QWidget *parent) noexcept {
  ::QDialog *(*QDialog_new$)(::QWidget *) = ::QDialog_new;
  return QDialog_new$(parent);
}

void cxxbridge1$205$QDialog_setModal(::QDialog *dialog, bool modal) noexcept {
  void (*QDialog_setModal$)(::QDialog *, bool) = ::QDialog_setModal;
  QDialog_setModal$(dialog, modal);
}

void cxxbridge1$205$QDialog_setWindowTitle(::QDialog *dialog, ::std::string const &title) noexcept {
  void (*QDialog_setWindowTitle$)(::QDialog *, ::std::string const &) = ::QDialog_setWindowTitle;
  QDialog_setWindowTitle$(dialog, title);
}

void cxxbridge1$205$QDialog_setMinimumSize(::QDialog *dialog, ::std::int32_t w, ::std::int32_t h) noexcept {
  void (*QDialog_setMinimumSize$)(::QDialog *, ::std::int32_t, ::std::int32_t) = ::QDialog_setMinimumSize;
  QDialog_setMinimumSize$(dialog, w, h);
}

void cxxbridge1$205$QDialog_resize(::QDialog *dialog, ::std::int32_t w, ::std::int32_t h) noexcept {
  void (*QDialog_resize$)(::QDialog *, ::std::int32_t, ::std::int32_t) = ::QDialog_resize;
  QDialog_resize$(dialog, w, h);
}

void cxxbridge1$205$QDialog_show(::QDialog *dialog) noexcept {
  void (*QDialog_show$)(::QDialog *) = ::QDialog_show;
  QDialog_show$(dialog);
}

void cxxbridge1$205$QDialog_exec(::QDialog *dialog) noexcept {
  void (*QDialog_exec$)(::QDialog *) = ::QDialog_exec;
  QDialog_exec$(dialog);
}

void cxxbridge1$205$QDialog_accept(::QDialog *dialog) noexcept {
  void (*QDialog_accept$)(::QDialog *) = ::QDialog_accept;
  QDialog_accept$(dialog);
}

void cxxbridge1$205$QDialog_reject(::QDialog *dialog) noexcept {
  void (*QDialog_reject$)(::QDialog *) = ::QDialog_reject;
  QDialog_reject$(dialog);
}

void cxxbridge1$205$QDialog_setLayout(::QDialog *dialog, ::QLayout *layout) noexcept {
  void (*QDialog_setLayout$)(::QDialog *, ::QLayout *) = ::QDialog_setLayout;
  QDialog_setLayout$(dialog, layout);
}

void cxxbridge1$205$QDialog_delete(::QDialog *dialog) noexcept {
  void (*QDialog_delete$)(::QDialog *) = ::QDialog_delete;
  QDialog_delete$(dialog);
}

::QStackedWidget *cxxbridge1$205$QStackedWidget_new(::QWidget *parent) noexcept {
  ::QStackedWidget *(*QStackedWidget_new$)(::QWidget *) = ::QStackedWidget_new;
  return QStackedWidget_new$(parent);
}

void cxxbridge1$205$QStackedWidget_delete(::QStackedWidget *w) noexcept {
  void (*QStackedWidget_delete$)(::QStackedWidget *) = ::QStackedWidget_delete;
  QStackedWidget_delete$(w);
}

::std::int32_t cxxbridge1$205$QStackedWidget_addWidget(::QStackedWidget *w, ::QWidget *page) noexcept {
  ::std::int32_t (*QStackedWidget_addWidget$)(::QStackedWidget *, ::QWidget *) = ::QStackedWidget_addWidget;
  return QStackedWidget_addWidget$(w, page);
}

::std::int32_t cxxbridge1$205$QStackedWidget_insertWidget(::QStackedWidget *w, ::std::int32_t index, ::QWidget *page) noexcept {
  ::std::int32_t (*QStackedWidget_insertWidget$)(::QStackedWidget *, ::std::int32_t, ::QWidget *) = ::QStackedWidget_insertWidget;
  return QStackedWidget_insertWidget$(w, index, page);
}

void cxxbridge1$205$QStackedWidget_removeWidget(::QStackedWidget *w, ::QWidget *page) noexcept {
  void (*QStackedWidget_removeWidget$)(::QStackedWidget *, ::QWidget *) = ::QStackedWidget_removeWidget;
  QStackedWidget_removeWidget$(w, page);
}

void cxxbridge1$205$QStackedWidget_setCurrentIndex(::QStackedWidget *w, ::std::int32_t index) noexcept {
  void (*QStackedWidget_setCurrentIndex$)(::QStackedWidget *, ::std::int32_t) = ::QStackedWidget_setCurrentIndex;
  QStackedWidget_setCurrentIndex$(w, index);
}

::std::int32_t cxxbridge1$205$QStackedWidget_currentIndex(::QStackedWidget *w) noexcept {
  ::std::int32_t (*QStackedWidget_currentIndex$)(::QStackedWidget *) = ::QStackedWidget_currentIndex;
  return QStackedWidget_currentIndex$(w);
}

::std::int32_t cxxbridge1$205$QStackedWidget_count(::QStackedWidget *w) noexcept {
  ::std::int32_t (*QStackedWidget_count$)(::QStackedWidget *) = ::QStackedWidget_count;
  return QStackedWidget_count$(w);
}

::QWidget *cxxbridge1$205$QStackedWidget_widget(::QStackedWidget *w, ::std::int32_t index) noexcept {
  ::QWidget *(*QStackedWidget_widget$)(::QStackedWidget *, ::std::int32_t) = ::QStackedWidget_widget;
  return QStackedWidget_widget$(w, index);
}

void cxxbridge1$205$QStackedWidget_onCurrentChanged(::QStackedWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QStackedWidget_onCurrentChanged$)(::QStackedWidget *, ::std::uint64_t) = ::QStackedWidget_onCurrentChanged;
  QStackedWidget_onCurrentChanged$(w, ctx);
}

::QStatusBar *cxxbridge1$205$QStatusBar_new(::QWidget *parent) noexcept {
  ::QStatusBar *(*QStatusBar_new$)(::QWidget *) = ::QStatusBar_new;
  return QStatusBar_new$(parent);
}

void cxxbridge1$205$QStatusBar_delete(::QStatusBar *bar) noexcept {
  void (*QStatusBar_delete$)(::QStatusBar *) = ::QStatusBar_delete;
  QStatusBar_delete$(bar);
}

void cxxbridge1$205$QStatusBar_showMessage(::QStatusBar *bar, ::std::string const &text, ::std::int32_t timeout_ms) noexcept {
  void (*QStatusBar_showMessage$)(::QStatusBar *, ::std::string const &, ::std::int32_t) = ::QStatusBar_showMessage;
  QStatusBar_showMessage$(bar, text, timeout_ms);
}

void cxxbridge1$205$QStatusBar_clearMessage(::QStatusBar *bar) noexcept {
  void (*QStatusBar_clearMessage$)(::QStatusBar *) = ::QStatusBar_clearMessage;
  QStatusBar_clearMessage$(bar);
}

void cxxbridge1$205$QStatusBar_addWidget(::QStatusBar *bar, ::QWidget *widget) noexcept {
  void (*QStatusBar_addWidget$)(::QStatusBar *, ::QWidget *) = ::QStatusBar_addWidget;
  QStatusBar_addWidget$(bar, widget);
}

void cxxbridge1$205$QStatusBar_addPermanentWidget(::QStatusBar *bar, ::QWidget *widget) noexcept {
  void (*QStatusBar_addPermanentWidget$)(::QStatusBar *, ::QWidget *) = ::QStatusBar_addPermanentWidget;
  QStatusBar_addPermanentWidget$(bar, widget);
}

void cxxbridge1$205$QStatusBar_removeWidget(::QStatusBar *bar, ::QWidget *widget) noexcept {
  void (*QStatusBar_removeWidget$)(::QStatusBar *, ::QWidget *) = ::QStatusBar_removeWidget;
  QStatusBar_removeWidget$(bar, widget);
}

void cxxbridge1$205$QStatusBar_setSizeGripEnabled(::QStatusBar *bar, bool enabled) noexcept {
  void (*QStatusBar_setSizeGripEnabled$)(::QStatusBar *, bool) = ::QStatusBar_setSizeGripEnabled;
  QStatusBar_setSizeGripEnabled$(bar, enabled);
}

::QTableWidget *cxxbridge1$205$QTableWidget_new(::std::int32_t rows, ::std::int32_t cols, ::QWidget *parent) noexcept {
  ::QTableWidget *(*QTableWidget_new$)(::std::int32_t, ::std::int32_t, ::QWidget *) = ::QTableWidget_new;
  return QTableWidget_new$(rows, cols, parent);
}

void cxxbridge1$205$QTableWidget_delete(::QTableWidget *w) noexcept {
  void (*QTableWidget_delete$)(::QTableWidget *) = ::QTableWidget_delete;
  QTableWidget_delete$(w);
}

void cxxbridge1$205$QTableWidget_setRowCount(::QTableWidget *w, ::std::int32_t rows) noexcept {
  void (*QTableWidget_setRowCount$)(::QTableWidget *, ::std::int32_t) = ::QTableWidget_setRowCount;
  QTableWidget_setRowCount$(w, rows);
}

void cxxbridge1$205$QTableWidget_setColumnCount(::QTableWidget *w, ::std::int32_t cols) noexcept {
  void (*QTableWidget_setColumnCount$)(::QTableWidget *, ::std::int32_t) = ::QTableWidget_setColumnCount;
  QTableWidget_setColumnCount$(w, cols);
}

void cxxbridge1$205$QTableWidget_setItem(::QTableWidget *w, ::std::int32_t row, ::std::int32_t col, ::std::string const &text) noexcept {
  void (*QTableWidget_setItem$)(::QTableWidget *, ::std::int32_t, ::std::int32_t, ::std::string const &) = ::QTableWidget_setItem;
  QTableWidget_setItem$(w, row, col, text);
}

void cxxbridge1$205$QTableWidget_itemText(::QTableWidget *w, ::std::int32_t row, ::std::int32_t col, ::rust::String *return$) noexcept {
  ::rust::String (*QTableWidget_itemText$)(::QTableWidget *, ::std::int32_t, ::std::int32_t) = ::QTableWidget_itemText;
  new (return$) ::rust::String(QTableWidget_itemText$(w, row, col));
}

void cxxbridge1$205$QTableWidget_setHorizontalHeaderLabels(::QTableWidget *w, ::rust::Vec<::rust::String> const *labels) noexcept {
  void (*QTableWidget_setHorizontalHeaderLabels$)(::QTableWidget *, ::rust::Vec<::rust::String>) = ::QTableWidget_setHorizontalHeaderLabels;
  QTableWidget_setHorizontalHeaderLabels$(w, ::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *labels));
}

void cxxbridge1$205$QTableWidget_setVerticalHeaderLabels(::QTableWidget *w, ::rust::Vec<::rust::String> const *labels) noexcept {
  void (*QTableWidget_setVerticalHeaderLabels$)(::QTableWidget *, ::rust::Vec<::rust::String>) = ::QTableWidget_setVerticalHeaderLabels;
  QTableWidget_setVerticalHeaderLabels$(w, ::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *labels));
}

void cxxbridge1$205$QTableWidget_setCurrentCell(::QTableWidget *w, ::std::int32_t row, ::std::int32_t col) noexcept {
  void (*QTableWidget_setCurrentCell$)(::QTableWidget *, ::std::int32_t, ::std::int32_t) = ::QTableWidget_setCurrentCell;
  QTableWidget_setCurrentCell$(w, row, col);
}

::std::int32_t cxxbridge1$205$QTableWidget_currentRow(::QTableWidget *w) noexcept {
  ::std::int32_t (*QTableWidget_currentRow$)(::QTableWidget *) = ::QTableWidget_currentRow;
  return QTableWidget_currentRow$(w);
}

::std::int32_t cxxbridge1$205$QTableWidget_currentColumn(::QTableWidget *w) noexcept {
  ::std::int32_t (*QTableWidget_currentColumn$)(::QTableWidget *) = ::QTableWidget_currentColumn;
  return QTableWidget_currentColumn$(w);
}

void cxxbridge1$205$QTableWidget_selectedRows(::QTableWidget *w, ::rust::Vec<::std::int32_t> *return$) noexcept {
  ::rust::Vec<::std::int32_t> (*QTableWidget_selectedRows$)(::QTableWidget *) = ::QTableWidget_selectedRows;
  new (return$) ::rust::Vec<::std::int32_t>(QTableWidget_selectedRows$(w));
}

void cxxbridge1$205$QTableWidget_clear(::QTableWidget *w) noexcept {
  void (*QTableWidget_clear$)(::QTableWidget *) = ::QTableWidget_clear;
  QTableWidget_clear$(w);
}

void cxxbridge1$205$QTableWidget_clearContents(::QTableWidget *w) noexcept {
  void (*QTableWidget_clearContents$)(::QTableWidget *) = ::QTableWidget_clearContents;
  QTableWidget_clearContents$(w);
}

void cxxbridge1$205$QTableWidget_setSelectionMode(::QTableWidget *w, ::std::int32_t mode) noexcept {
  void (*QTableWidget_setSelectionMode$)(::QTableWidget *, ::std::int32_t) = ::QTableWidget_setSelectionMode;
  QTableWidget_setSelectionMode$(w, mode);
}

void cxxbridge1$205$QTableWidget_setSelectionBehavior(::QTableWidget *w, ::std::int32_t behavior) noexcept {
  void (*QTableWidget_setSelectionBehavior$)(::QTableWidget *, ::std::int32_t) = ::QTableWidget_setSelectionBehavior;
  QTableWidget_setSelectionBehavior$(w, behavior);
}

void cxxbridge1$205$QTableWidget_removeRow(::QTableWidget *w, ::std::int32_t row) noexcept {
  void (*QTableWidget_removeRow$)(::QTableWidget *, ::std::int32_t) = ::QTableWidget_removeRow;
  QTableWidget_removeRow$(w, row);
}

void cxxbridge1$205$QTableWidget_insertRow(::QTableWidget *w, ::std::int32_t row) noexcept {
  void (*QTableWidget_insertRow$)(::QTableWidget *, ::std::int32_t) = ::QTableWidget_insertRow;
  QTableWidget_insertRow$(w, row);
}

void cxxbridge1$205$QTableWidget_setColumnWidth(::QTableWidget *w, ::std::int32_t col, ::std::int32_t width) noexcept {
  void (*QTableWidget_setColumnWidth$)(::QTableWidget *, ::std::int32_t, ::std::int32_t) = ::QTableWidget_setColumnWidth;
  QTableWidget_setColumnWidth$(w, col, width);
}

void cxxbridge1$205$QTableWidget_setRowHeight(::QTableWidget *w, ::std::int32_t row, ::std::int32_t height) noexcept {
  void (*QTableWidget_setRowHeight$)(::QTableWidget *, ::std::int32_t, ::std::int32_t) = ::QTableWidget_setRowHeight;
  QTableWidget_setRowHeight$(w, row, height);
}

void cxxbridge1$205$QTableWidget_onCellClicked(::QTableWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTableWidget_onCellClicked$)(::QTableWidget *, ::std::uint64_t) = ::QTableWidget_onCellClicked;
  QTableWidget_onCellClicked$(w, ctx);
}

void cxxbridge1$205$QTableWidget_onCellDoubleClicked(::QTableWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTableWidget_onCellDoubleClicked$)(::QTableWidget *, ::std::uint64_t) = ::QTableWidget_onCellDoubleClicked;
  QTableWidget_onCellDoubleClicked$(w, ctx);
}

void cxxbridge1$205$QTableWidget_onCurrentCellChanged(::QTableWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTableWidget_onCurrentCellChanged$)(::QTableWidget *, ::std::uint64_t) = ::QTableWidget_onCurrentCellChanged;
  QTableWidget_onCurrentCellChanged$(w, ctx);
}

::QTabWidget *cxxbridge1$205$QTabWidget_new(::QWidget *parent) noexcept {
  ::QTabWidget *(*QTabWidget_new$)(::QWidget *) = ::QTabWidget_new;
  return QTabWidget_new$(parent);
}

void cxxbridge1$205$QTabWidget_addTab(::QTabWidget *tw, ::QWidget *page, ::std::string const &label) noexcept {
  void (*QTabWidget_addTab$)(::QTabWidget *, ::QWidget *, ::std::string const &) = ::QTabWidget_addTab;
  QTabWidget_addTab$(tw, page, label);
}

::std::int32_t cxxbridge1$205$QTabWidget_currentIndex(::QTabWidget *tw) noexcept {
  ::std::int32_t (*QTabWidget_currentIndex$)(::QTabWidget *) = ::QTabWidget_currentIndex;
  return QTabWidget_currentIndex$(tw);
}

void cxxbridge1$205$QTabWidget_setCurrentIndex(::QTabWidget *tw, ::std::int32_t index) noexcept {
  void (*QTabWidget_setCurrentIndex$)(::QTabWidget *, ::std::int32_t) = ::QTabWidget_setCurrentIndex;
  QTabWidget_setCurrentIndex$(tw, index);
}

void cxxbridge1$205$QTabWidget_delete(::QTabWidget *tw) noexcept {
  void (*QTabWidget_delete$)(::QTabWidget *) = ::QTabWidget_delete;
  QTabWidget_delete$(tw);
}

void cxxbridge1$205$QTabWidget_onCurrentChanged(::QTabWidget *tw, ::std::uint64_t ctx) noexcept {
  void (*QTabWidget_onCurrentChanged$)(::QTabWidget *, ::std::uint64_t) = ::QTabWidget_onCurrentChanged;
  QTabWidget_onCurrentChanged$(tw, ctx);
}

::QTextEdit *cxxbridge1$205$QTextEdit_new(::QWidget *parent) noexcept {
  ::QTextEdit *(*QTextEdit_new$)(::QWidget *) = ::QTextEdit_new;
  return QTextEdit_new$(parent);
}

void cxxbridge1$205$QTextEdit_toPlainText(::QTextEdit *edit, ::rust::String *return$) noexcept {
  ::rust::String (*QTextEdit_toPlainText$)(::QTextEdit *) = ::QTextEdit_toPlainText;
  new (return$) ::rust::String(QTextEdit_toPlainText$(edit));
}

void cxxbridge1$205$QTextEdit_setPlainText(::QTextEdit *edit, ::std::string const &text) noexcept {
  void (*QTextEdit_setPlainText$)(::QTextEdit *, ::std::string const &) = ::QTextEdit_setPlainText;
  QTextEdit_setPlainText$(edit, text);
}

void cxxbridge1$205$QTextEdit_setPlaceholderText(::QTextEdit *edit, ::std::string const &text) noexcept {
  void (*QTextEdit_setPlaceholderText$)(::QTextEdit *, ::std::string const &) = ::QTextEdit_setPlaceholderText;
  QTextEdit_setPlaceholderText$(edit, text);
}

void cxxbridge1$205$QTextEdit_setReadOnly(::QTextEdit *edit, bool ro) noexcept {
  void (*QTextEdit_setReadOnly$)(::QTextEdit *, bool) = ::QTextEdit_setReadOnly;
  QTextEdit_setReadOnly$(edit, ro);
}

bool cxxbridge1$205$QTextEdit_isReadOnly(::QTextEdit *edit) noexcept {
  bool (*QTextEdit_isReadOnly$)(::QTextEdit *) = ::QTextEdit_isReadOnly;
  return QTextEdit_isReadOnly$(edit);
}

void cxxbridge1$205$QTextEdit_append(::QTextEdit *edit, ::std::string const &text) noexcept {
  void (*QTextEdit_append$)(::QTextEdit *, ::std::string const &) = ::QTextEdit_append;
  QTextEdit_append$(edit, text);
}

void cxxbridge1$205$QTextEdit_copy(::QTextEdit *edit) noexcept {
  void (*QTextEdit_copy$)(::QTextEdit *) = ::QTextEdit_copy;
  QTextEdit_copy$(edit);
}

void cxxbridge1$205$QTextEdit_cut(::QTextEdit *edit) noexcept {
  void (*QTextEdit_cut$)(::QTextEdit *) = ::QTextEdit_cut;
  QTextEdit_cut$(edit);
}

void cxxbridge1$205$QTextEdit_paste(::QTextEdit *edit) noexcept {
  void (*QTextEdit_paste$)(::QTextEdit *) = ::QTextEdit_paste;
  QTextEdit_paste$(edit);
}

void cxxbridge1$205$QTextEdit_undo(::QTextEdit *edit) noexcept {
  void (*QTextEdit_undo$)(::QTextEdit *) = ::QTextEdit_undo;
  QTextEdit_undo$(edit);
}

void cxxbridge1$205$QTextEdit_redo(::QTextEdit *edit) noexcept {
  void (*QTextEdit_redo$)(::QTextEdit *) = ::QTextEdit_redo;
  QTextEdit_redo$(edit);
}

void cxxbridge1$205$QTextEdit_selectAll(::QTextEdit *edit) noexcept {
  void (*QTextEdit_selectAll$)(::QTextEdit *) = ::QTextEdit_selectAll;
  QTextEdit_selectAll$(edit);
}

void cxxbridge1$205$QTextEdit_delete(::QTextEdit *edit) noexcept {
  void (*QTextEdit_delete$)(::QTextEdit *) = ::QTextEdit_delete;
  QTextEdit_delete$(edit);
}

void cxxbridge1$205$QTextEdit_onTextChanged(::QTextEdit *edit, ::std::uint64_t ctx) noexcept {
  void (*QTextEdit_onTextChanged$)(::QTextEdit *, ::std::uint64_t) = ::QTextEdit_onTextChanged;
  QTextEdit_onTextChanged$(edit, ctx);
}

::QTimer *cxxbridge1$205$QTimer_new() noexcept {
  ::QTimer *(*QTimer_new$)() = ::QTimer_new;
  return QTimer_new$();
}

void cxxbridge1$205$QTimer_start(::QTimer *timer, ::std::int32_t interval_ms) noexcept {
  void (*QTimer_start$)(::QTimer *, ::std::int32_t) = ::QTimer_start;
  QTimer_start$(timer, interval_ms);
}

void cxxbridge1$205$QTimer_stop(::QTimer *timer) noexcept {
  void (*QTimer_stop$)(::QTimer *) = ::QTimer_stop;
  QTimer_stop$(timer);
}

bool cxxbridge1$205$QTimer_isActive(::QTimer *timer) noexcept {
  bool (*QTimer_isActive$)(::QTimer *) = ::QTimer_isActive;
  return QTimer_isActive$(timer);
}

void cxxbridge1$205$QTimer_delete(::QTimer *timer) noexcept {
  void (*QTimer_delete$)(::QTimer *) = ::QTimer_delete;
  QTimer_delete$(timer);
}

void cxxbridge1$205$QTimer_onTimeout(::QTimer *timer, ::std::uint64_t ctx) noexcept {
  void (*QTimer_onTimeout$)(::QTimer *, ::std::uint64_t) = ::QTimer_onTimeout;
  QTimer_onTimeout$(timer, ctx);
}

void cxxbridge1$205$QTimer_singleShot(::std::int32_t interval_ms, ::std::uint64_t ctx) noexcept {
  void (*QTimer_singleShot$)(::std::int32_t, ::std::uint64_t) = ::QTimer_singleShot;
  QTimer_singleShot$(interval_ms, ctx);
}

::QToolBar *cxxbridge1$205$QToolBar_new(::std::string const &title, ::QWidget *parent) noexcept {
  ::QToolBar *(*QToolBar_new$)(::std::string const &, ::QWidget *) = ::QToolBar_new;
  return QToolBar_new$(title, parent);
}

void cxxbridge1$205$QToolBar_delete(::QToolBar *toolbar) noexcept {
  void (*QToolBar_delete$)(::QToolBar *) = ::QToolBar_delete;
  QToolBar_delete$(toolbar);
}

void cxxbridge1$205$QToolBar_addAction(::QToolBar *toolbar, ::std::string const &text, ::std::uint64_t ctx) noexcept {
  void (*QToolBar_addAction$)(::QToolBar *, ::std::string const &, ::std::uint64_t) = ::QToolBar_addAction;
  QToolBar_addAction$(toolbar, text, ctx);
}

void cxxbridge1$205$QToolBar_addSeparator(::QToolBar *toolbar) noexcept {
  void (*QToolBar_addSeparator$)(::QToolBar *) = ::QToolBar_addSeparator;
  QToolBar_addSeparator$(toolbar);
}

void cxxbridge1$205$QToolBar_addWidget(::QToolBar *toolbar, ::QWidget *widget) noexcept {
  void (*QToolBar_addWidget$)(::QToolBar *, ::QWidget *) = ::QToolBar_addWidget;
  QToolBar_addWidget$(toolbar, widget);
}

void cxxbridge1$205$QToolBar_setMovable(::QToolBar *toolbar, bool movable) noexcept {
  void (*QToolBar_setMovable$)(::QToolBar *, bool) = ::QToolBar_setMovable;
  QToolBar_setMovable$(toolbar, movable);
}

void cxxbridge1$205$QToolBar_setFloatable(::QToolBar *toolbar, bool floatable) noexcept {
  void (*QToolBar_setFloatable$)(::QToolBar *, bool) = ::QToolBar_setFloatable;
  QToolBar_setFloatable$(toolbar, floatable);
}

void cxxbridge1$205$QToolBar_setIconSize(::QToolBar *toolbar, ::std::int32_t w, ::std::int32_t h) noexcept {
  void (*QToolBar_setIconSize$)(::QToolBar *, ::std::int32_t, ::std::int32_t) = ::QToolBar_setIconSize;
  QToolBar_setIconSize$(toolbar, w, h);
}

void cxxbridge1$205$QToolBar_setAllowedAreas(::QToolBar *toolbar, ::std::int32_t areas) noexcept {
  void (*QToolBar_setAllowedAreas$)(::QToolBar *, ::std::int32_t) = ::QToolBar_setAllowedAreas;
  QToolBar_setAllowedAreas$(toolbar, areas);
}

void cxxbridge1$205$QToolBar_setToolButtonStyle(::QToolBar *toolbar, ::std::int32_t style) noexcept {
  void (*QToolBar_setToolButtonStyle$)(::QToolBar *, ::std::int32_t) = ::QToolBar_setToolButtonStyle;
  QToolBar_setToolButtonStyle$(toolbar, style);
}

void cxxbridge1$205$QToolBar_clear(::QToolBar *toolbar) noexcept {
  void (*QToolBar_clear$)(::QToolBar *) = ::QToolBar_clear;
  QToolBar_clear$(toolbar);
}

::QTreeWidget *cxxbridge1$205$QTreeWidget_new(::QWidget *parent) noexcept {
  ::QTreeWidget *(*QTreeWidget_new$)(::QWidget *) = ::QTreeWidget_new;
  return QTreeWidget_new$(parent);
}

void cxxbridge1$205$QTreeWidget_delete(::QTreeWidget *w) noexcept {
  void (*QTreeWidget_delete$)(::QTreeWidget *) = ::QTreeWidget_delete;
  QTreeWidget_delete$(w);
}

void cxxbridge1$205$QTreeWidget_addTopLevelItem(::QTreeWidget *w, ::std::string const &text) noexcept {
  void (*QTreeWidget_addTopLevelItem$)(::QTreeWidget *, ::std::string const &) = ::QTreeWidget_addTopLevelItem;
  QTreeWidget_addTopLevelItem$(w, text);
}

void cxxbridge1$205$QTreeWidget_clear(::QTreeWidget *w) noexcept {
  void (*QTreeWidget_clear$)(::QTreeWidget *) = ::QTreeWidget_clear;
  QTreeWidget_clear$(w);
}

void cxxbridge1$205$QTreeWidget_currentItemText(::QTreeWidget *w, ::rust::String *return$) noexcept {
  ::rust::String (*QTreeWidget_currentItemText$)(::QTreeWidget *) = ::QTreeWidget_currentItemText;
  new (return$) ::rust::String(QTreeWidget_currentItemText$(w));
}

void cxxbridge1$205$QTreeWidget_setHeaderLabel(::QTreeWidget *w, ::std::string const &text) noexcept {
  void (*QTreeWidget_setHeaderLabel$)(::QTreeWidget *, ::std::string const &) = ::QTreeWidget_setHeaderLabel;
  QTreeWidget_setHeaderLabel$(w, text);
}

void cxxbridge1$205$QTreeWidget_setHeaderLabels(::QTreeWidget *w, ::rust::Vec<::rust::String> const *labels) noexcept {
  void (*QTreeWidget_setHeaderLabels$)(::QTreeWidget *, ::rust::Vec<::rust::String>) = ::QTreeWidget_setHeaderLabels;
  QTreeWidget_setHeaderLabels$(w, ::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *labels));
}

void cxxbridge1$205$QTreeWidget_expandAll(::QTreeWidget *w) noexcept {
  void (*QTreeWidget_expandAll$)(::QTreeWidget *) = ::QTreeWidget_expandAll;
  QTreeWidget_expandAll$(w);
}

void cxxbridge1$205$QTreeWidget_collapseAll(::QTreeWidget *w) noexcept {
  void (*QTreeWidget_collapseAll$)(::QTreeWidget *) = ::QTreeWidget_collapseAll;
  QTreeWidget_collapseAll$(w);
}

void cxxbridge1$205$QTreeWidget_expandItem(::QTreeWidget *w, ::std::string const &text) noexcept {
  void (*QTreeWidget_expandItem$)(::QTreeWidget *, ::std::string const &) = ::QTreeWidget_expandItem;
  QTreeWidget_expandItem$(w, text);
}

void cxxbridge1$205$QTreeWidget_setCurrentItem(::QTreeWidget *w, ::std::string const &text) noexcept {
  void (*QTreeWidget_setCurrentItem$)(::QTreeWidget *, ::std::string const &) = ::QTreeWidget_setCurrentItem;
  QTreeWidget_setCurrentItem$(w, text);
}

::std::int32_t cxxbridge1$205$QTreeWidget_topLevelItemCount(::QTreeWidget *w) noexcept {
  ::std::int32_t (*QTreeWidget_topLevelItemCount$)(::QTreeWidget *) = ::QTreeWidget_topLevelItemCount;
  return QTreeWidget_topLevelItemCount$(w);
}

void cxxbridge1$205$QTreeWidget_onItemClicked(::QTreeWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTreeWidget_onItemClicked$)(::QTreeWidget *, ::std::uint64_t) = ::QTreeWidget_onItemClicked;
  QTreeWidget_onItemClicked$(w, ctx);
}

void cxxbridge1$205$QTreeWidget_onItemDoubleClicked(::QTreeWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTreeWidget_onItemDoubleClicked$)(::QTreeWidget *, ::std::uint64_t) = ::QTreeWidget_onItemDoubleClicked;
  QTreeWidget_onItemDoubleClicked$(w, ctx);
}

void cxxbridge1$205$QTreeWidget_onItemExpanded(::QTreeWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTreeWidget_onItemExpanded$)(::QTreeWidget *, ::std::uint64_t) = ::QTreeWidget_onItemExpanded;
  QTreeWidget_onItemExpanded$(w, ctx);
}

void cxxbridge1$205$QTreeWidget_onItemCollapsed(::QTreeWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTreeWidget_onItemCollapsed$)(::QTreeWidget *, ::std::uint64_t) = ::QTreeWidget_onItemCollapsed;
  QTreeWidget_onItemCollapsed$(w, ctx);
}

void cxxbridge1$205$QTreeWidget_onCurrentItemChanged(::QTreeWidget *w, ::std::uint64_t ctx) noexcept {
  void (*QTreeWidget_onCurrentItemChanged$)(::QTreeWidget *, ::std::uint64_t) = ::QTreeWidget_onCurrentItemChanged;
  QTreeWidget_onCurrentItemChanged$(w, ctx);
}

::QWidget *cxxbridge1$205$toQWidget_QWidget(::QWidget *w) noexcept {
  ::QWidget *(*toQWidget_QWidget$)(::QWidget *) = ::toQWidget_QWidget;
  return toQWidget_QWidget$(w);
}

::QWidget *cxxbridge1$205$toQWidget_QPushButton(::QPushButton *btn) noexcept {
  ::QWidget *(*toQWidget_QPushButton$)(::QPushButton *) = ::toQWidget_QPushButton;
  return toQWidget_QPushButton$(btn);
}

::QWidget *cxxbridge1$205$toQWidget_QLabel(::QLabel *label) noexcept {
  ::QWidget *(*toQWidget_QLabel$)(::QLabel *) = ::toQWidget_QLabel;
  return toQWidget_QLabel$(label);
}

::QWidget *cxxbridge1$205$toQWidget_QLineEdit(::QLineEdit *edit) noexcept {
  ::QWidget *(*toQWidget_QLineEdit$)(::QLineEdit *) = ::toQWidget_QLineEdit;
  return toQWidget_QLineEdit$(edit);
}

::QWidget *cxxbridge1$205$toQWidget_QCheckBox(::QCheckBox *cb) noexcept {
  ::QWidget *(*toQWidget_QCheckBox$)(::QCheckBox *) = ::toQWidget_QCheckBox;
  return toQWidget_QCheckBox$(cb);
}

::QWidget *cxxbridge1$205$toQWidget_QComboBox(::QComboBox *cb) noexcept {
  ::QWidget *(*toQWidget_QComboBox$)(::QComboBox *) = ::toQWidget_QComboBox;
  return toQWidget_QComboBox$(cb);
}

::QWidget *cxxbridge1$205$toQWidget_QTextEdit(::QTextEdit *edit) noexcept {
  ::QWidget *(*toQWidget_QTextEdit$)(::QTextEdit *) = ::toQWidget_QTextEdit;
  return toQWidget_QTextEdit$(edit);
}

::QWidget *cxxbridge1$205$toQWidget_QSlider(::QSlider *s) noexcept {
  ::QWidget *(*toQWidget_QSlider$)(::QSlider *) = ::toQWidget_QSlider;
  return toQWidget_QSlider$(s);
}

::QWidget *cxxbridge1$205$toQWidget_QProgressBar(::QProgressBar *bar) noexcept {
  ::QWidget *(*toQWidget_QProgressBar$)(::QProgressBar *) = ::toQWidget_QProgressBar;
  return toQWidget_QProgressBar$(bar);
}

::QWidget *cxxbridge1$205$toQWidget_QRadioButton(::QRadioButton *rb) noexcept {
  ::QWidget *(*toQWidget_QRadioButton$)(::QRadioButton *) = ::toQWidget_QRadioButton;
  return toQWidget_QRadioButton$(rb);
}

::QWidget *cxxbridge1$205$toQWidget_QGroupBox(::QGroupBox *gb) noexcept {
  ::QWidget *(*toQWidget_QGroupBox$)(::QGroupBox *) = ::toQWidget_QGroupBox;
  return toQWidget_QGroupBox$(gb);
}

::QWidget *cxxbridge1$205$toQWidget_QTabWidget(::QTabWidget *tw) noexcept {
  ::QWidget *(*toQWidget_QTabWidget$)(::QTabWidget *) = ::toQWidget_QTabWidget;
  return toQWidget_QTabWidget$(tw);
}

::QWidget *cxxbridge1$205$toQWidget_QSpinBox(::QSpinBox *sb) noexcept {
  ::QWidget *(*toQWidget_QSpinBox$)(::QSpinBox *) = ::toQWidget_QSpinBox;
  return toQWidget_QSpinBox$(sb);
}

::QWidget *cxxbridge1$205$toQWidget_QMenu(::QMenu *menu) noexcept {
  ::QWidget *(*toQWidget_QMenu$)(::QMenu *) = ::toQWidget_QMenu;
  return toQWidget_QMenu$(menu);
}

::QWidget *cxxbridge1$205$toQWidget_QMenuBar(::QMenuBar *mb) noexcept {
  ::QWidget *(*toQWidget_QMenuBar$)(::QMenuBar *) = ::toQWidget_QMenuBar;
  return toQWidget_QMenuBar$(mb);
}

::QVariant *cxxbridge1$205$QVariant_from_int(::std::int32_t v) noexcept {
  ::QVariant *(*QVariant_from_int$)(::std::int32_t) = ::QVariant_from_int;
  return QVariant_from_int$(v);
}

::QVariant *cxxbridge1$205$QVariant_from_uint(::std::uint32_t v) noexcept {
  ::QVariant *(*QVariant_from_uint$)(::std::uint32_t) = ::QVariant_from_uint;
  return QVariant_from_uint$(v);
}

::QVariant *cxxbridge1$205$QVariant_from_long(::std::int64_t v) noexcept {
  ::QVariant *(*QVariant_from_long$)(::std::int64_t) = ::QVariant_from_long;
  return QVariant_from_long$(v);
}

::QVariant *cxxbridge1$205$QVariant_from_bool(bool v) noexcept {
  ::QVariant *(*QVariant_from_bool$)(bool) = ::QVariant_from_bool;
  return QVariant_from_bool$(v);
}

::QVariant *cxxbridge1$205$QVariant_from_double(double v) noexcept {
  ::QVariant *(*QVariant_from_double$)(double) = ::QVariant_from_double;
  return QVariant_from_double$(v);
}

::QVariant *cxxbridge1$205$QVariant_from_string(::rust::String const *s) noexcept {
  ::QVariant *(*QVariant_from_string$)(::rust::String) = ::QVariant_from_string;
  return QVariant_from_string$(::rust::String(::rust::unsafe_bitcopy, *s));
}

::QVariant *cxxbridge1$205$QVariant_from_stringlist(::rust::Vec<::rust::String> const *v) noexcept {
  ::QVariant *(*QVariant_from_stringlist$)(::rust::Vec<::rust::String>) = ::QVariant_from_stringlist;
  return QVariant_from_stringlist$(::rust::Vec<::rust::String>(::rust::unsafe_bitcopy, *v));
}

::QVariant *cxxbridge1$205$QVariant_from_bytearray(::rust::Slice<::std::uint8_t const> data) noexcept {
  ::QVariant *(*QVariant_from_bytearray$)(::rust::Slice<::std::uint8_t const>) = ::QVariant_from_bytearray;
  return QVariant_from_bytearray$(data);
}

void cxxbridge1$205$QVariant_delete(::QVariant *v) noexcept {
  void (*QVariant_delete$)(::QVariant *) = ::QVariant_delete;
  QVariant_delete$(v);
}

bool cxxbridge1$205$QVariant_is_int(::QVariant *v) noexcept {
  bool (*QVariant_is_int$)(::QVariant *) = ::QVariant_is_int;
  return QVariant_is_int$(v);
}

bool cxxbridge1$205$QVariant_is_uint(::QVariant *v) noexcept {
  bool (*QVariant_is_uint$)(::QVariant *) = ::QVariant_is_uint;
  return QVariant_is_uint$(v);
}

bool cxxbridge1$205$QVariant_is_long(::QVariant *v) noexcept {
  bool (*QVariant_is_long$)(::QVariant *) = ::QVariant_is_long;
  return QVariant_is_long$(v);
}

bool cxxbridge1$205$QVariant_is_bool(::QVariant *v) noexcept {
  bool (*QVariant_is_bool$)(::QVariant *) = ::QVariant_is_bool;
  return QVariant_is_bool$(v);
}

bool cxxbridge1$205$QVariant_is_double(::QVariant *v) noexcept {
  bool (*QVariant_is_double$)(::QVariant *) = ::QVariant_is_double;
  return QVariant_is_double$(v);
}

bool cxxbridge1$205$QVariant_is_string(::QVariant *v) noexcept {
  bool (*QVariant_is_string$)(::QVariant *) = ::QVariant_is_string;
  return QVariant_is_string$(v);
}

bool cxxbridge1$205$QVariant_is_stringlist(::QVariant *v) noexcept {
  bool (*QVariant_is_stringlist$)(::QVariant *) = ::QVariant_is_stringlist;
  return QVariant_is_stringlist$(v);
}

bool cxxbridge1$205$QVariant_is_bytearray(::QVariant *v) noexcept {
  bool (*QVariant_is_bytearray$)(::QVariant *) = ::QVariant_is_bytearray;
  return QVariant_is_bytearray$(v);
}

::std::int32_t cxxbridge1$205$QVariant_to_int(::QVariant *v, bool *ok) noexcept {
  ::std::int32_t (*QVariant_to_int$)(::QVariant *, bool *) = ::QVariant_to_int;
  return QVariant_to_int$(v, ok);
}

::std::uint32_t cxxbridge1$205$QVariant_to_uint(::QVariant *v, bool *ok) noexcept {
  ::std::uint32_t (*QVariant_to_uint$)(::QVariant *, bool *) = ::QVariant_to_uint;
  return QVariant_to_uint$(v, ok);
}

::std::int64_t cxxbridge1$205$QVariant_to_long(::QVariant *v, bool *ok) noexcept {
  ::std::int64_t (*QVariant_to_long$)(::QVariant *, bool *) = ::QVariant_to_long;
  return QVariant_to_long$(v, ok);
}

bool cxxbridge1$205$QVariant_to_bool(::QVariant *v, bool *ok) noexcept {
  bool (*QVariant_to_bool$)(::QVariant *, bool *) = ::QVariant_to_bool;
  return QVariant_to_bool$(v, ok);
}

double cxxbridge1$205$QVariant_to_double(::QVariant *v, bool *ok) noexcept {
  double (*QVariant_to_double$)(::QVariant *, bool *) = ::QVariant_to_double;
  return QVariant_to_double$(v, ok);
}

void cxxbridge1$205$QVariant_to_string(::QVariant *v, bool *ok, ::rust::String *return$) noexcept {
  ::rust::String (*QVariant_to_string$)(::QVariant *, bool *) = ::QVariant_to_string;
  new (return$) ::rust::String(QVariant_to_string$(v, ok));
}

void cxxbridge1$205$QVariant_to_stringlist(::QVariant *v, ::rust::Vec<::rust::String> *return$) noexcept {
  ::rust::Vec<::rust::String> (*QVariant_to_stringlist$)(::QVariant *) = ::QVariant_to_stringlist;
  new (return$) ::rust::Vec<::rust::String>(QVariant_to_stringlist$(v));
}

void cxxbridge1$205$QVariant_to_bytearray(::QVariant *v, ::rust::Vec<::std::uint8_t> *return$) noexcept {
  ::rust::Vec<::std::uint8_t> (*QVariant_to_bytearray$)(::QVariant *) = ::QVariant_to_bytearray;
  new (return$) ::rust::Vec<::std::uint8_t>(QVariant_to_bytearray$(v));
}

::QVBoxLayout *cxxbridge1$205$QVBoxLayout_new(::QWidget *parent) noexcept {
  ::QVBoxLayout *(*QVBoxLayout_new$)(::QWidget *) = ::QVBoxLayout_new;
  return QVBoxLayout_new$(parent);
}

void cxxbridge1$205$QVBoxLayout_addWidget(::QVBoxLayout *layout, ::QWidget *widget) noexcept {
  void (*QVBoxLayout_addWidget$)(::QVBoxLayout *, ::QWidget *) = ::QVBoxLayout_addWidget;
  QVBoxLayout_addWidget$(layout, widget);
}

void cxxbridge1$205$QVBoxLayout_delete(::QVBoxLayout *layout) noexcept {
  void (*QVBoxLayout_delete$)(::QVBoxLayout *) = ::QVBoxLayout_delete;
  QVBoxLayout_delete$(layout);
}

void cxxbridge1$205$QVBoxLayout_setSpacing(::QVBoxLayout *layout, ::std::int32_t spacing) noexcept {
  void (*QVBoxLayout_setSpacing$)(::QVBoxLayout *, ::std::int32_t) = ::QVBoxLayout_setSpacing;
  QVBoxLayout_setSpacing$(layout, spacing);
}

void cxxbridge1$205$QVBoxLayout_setContentsMargins(::QVBoxLayout *layout, ::std::int32_t left, ::std::int32_t top, ::std::int32_t right, ::std::int32_t bottom) noexcept {
  void (*QVBoxLayout_setContentsMargins$)(::QVBoxLayout *, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QVBoxLayout_setContentsMargins;
  QVBoxLayout_setContentsMargins$(layout, left, top, right, bottom);
}

void cxxbridge1$205$QVBoxLayout_addSpacerItem(::QVBoxLayout *layout, ::QSpacerItem *spacer) noexcept {
  void (*QVBoxLayout_addSpacerItem$)(::QVBoxLayout *, ::QSpacerItem *) = ::QVBoxLayout_addSpacerItem;
  QVBoxLayout_addSpacerItem$(layout, spacer);
}

::QWidget *cxxbridge1$205$QWidget_new(::QWidget *parent) noexcept {
  ::QWidget *(*QWidget_new$)(::QWidget *) = ::QWidget_new;
  return QWidget_new$(parent);
}

void cxxbridge1$205$QWidget_show(::QWidget *widget) noexcept {
  void (*QWidget_show$)(::QWidget *) = ::QWidget_show;
  QWidget_show$(widget);
}

void cxxbridge1$205$QWidget_hide(::QWidget *widget) noexcept {
  void (*QWidget_hide$)(::QWidget *) = ::QWidget_hide;
  QWidget_hide$(widget);
}

void cxxbridge1$205$QWidget_setWindowTitle(::QWidget *widget, ::std::string const &title) noexcept {
  void (*QWidget_setWindowTitle$)(::QWidget *, ::std::string const &) = ::QWidget_setWindowTitle;
  QWidget_setWindowTitle$(widget, title);
}

void cxxbridge1$205$QWidget_resize(::QWidget *widget, ::std::int32_t width, ::std::int32_t height) noexcept {
  void (*QWidget_resize$)(::QWidget *, ::std::int32_t, ::std::int32_t) = ::QWidget_resize;
  QWidget_resize$(widget, width, height);
}

void cxxbridge1$205$QWidget_delete(::QWidget *widget) noexcept {
  void (*QWidget_delete$)(::QWidget *) = ::QWidget_delete;
  QWidget_delete$(widget);
}

void cxxbridge1$205$QWidget_setLayout(::QWidget *widget, ::QLayout *layout) noexcept {
  void (*QWidget_setLayout$)(::QWidget *, ::QLayout *) = ::QWidget_setLayout;
  QWidget_setLayout$(widget, layout);
}

void cxxbridge1$205$QWidget_setWindowIcon(::QWidget *widget, ::std::string const &icon_path) noexcept {
  void (*QWidget_setWindowIcon$)(::QWidget *, ::std::string const &) = ::QWidget_setWindowIcon;
  QWidget_setWindowIcon$(widget, icon_path);
}

void cxxbridge1$205$QWidget_move(::QWidget *widget, ::std::int32_t x, ::std::int32_t y) noexcept {
  void (*QWidget_move$)(::QWidget *, ::std::int32_t, ::std::int32_t) = ::QWidget_move;
  QWidget_move$(widget, x, y);
}

void cxxbridge1$205$QWidget_moveToPoint(::QWidget *widget, ::QPoint *point) noexcept {
  void (*QWidget_moveToPoint$)(::QWidget *, ::QPoint *) = ::QWidget_moveToPoint;
  QWidget_moveToPoint$(widget, point);
}

void cxxbridge1$205$QWidget_setEnabled(::QWidget *widget, bool enabled) noexcept {
  void (*QWidget_setEnabled$)(::QWidget *, bool) = ::QWidget_setEnabled;
  QWidget_setEnabled$(widget, enabled);
}

void cxxbridge1$205$QWidget_setVisible(::QWidget *widget, bool visible) noexcept {
  void (*QWidget_setVisible$)(::QWidget *, bool) = ::QWidget_setVisible;
  QWidget_setVisible$(widget, visible);
}

void cxxbridge1$205$QWidget_setToolTip(::QWidget *widget, ::std::string const &tip) noexcept {
  void (*QWidget_setToolTip$)(::QWidget *, ::std::string const &) = ::QWidget_setToolTip;
  QWidget_setToolTip$(widget, tip);
}

void cxxbridge1$205$QWidget_setMinimumSize(::QWidget *widget, ::std::int32_t width, ::std::int32_t height) noexcept {
  void (*QWidget_setMinimumSize$)(::QWidget *, ::std::int32_t, ::std::int32_t) = ::QWidget_setMinimumSize;
  QWidget_setMinimumSize$(widget, width, height);
}

void cxxbridge1$205$QWidget_setMaximumSize(::QWidget *widget, ::std::int32_t width, ::std::int32_t height) noexcept {
  void (*QWidget_setMaximumSize$)(::QWidget *, ::std::int32_t, ::std::int32_t) = ::QWidget_setMaximumSize;
  QWidget_setMaximumSize$(widget, width, height);
}

void cxxbridge1$205$QWidget_setFixedSize(::QWidget *widget, ::std::int32_t width, ::std::int32_t height) noexcept {
  void (*QWidget_setFixedSize$)(::QWidget *, ::std::int32_t, ::std::int32_t) = ::QWidget_setFixedSize;
  QWidget_setFixedSize$(widget, width, height);
}

void cxxbridge1$205$QWidget_setStyleSheet(::QWidget *widget, ::std::string const &css) noexcept {
  void (*QWidget_setStyleSheet$)(::QWidget *, ::std::string const &) = ::QWidget_setStyleSheet;
  QWidget_setStyleSheet$(widget, css);
}

void cxxbridge1$205$QWidget_setFont(::QWidget *widget, ::QFont *font) noexcept {
  void (*QWidget_setFont$)(::QWidget *, ::QFont *) = ::QWidget_setFont;
  QWidget_setFont$(widget, font);
}

::QFont *cxxbridge1$205$QWidget_font(::QWidget *widget) noexcept {
  ::QFont *(*QWidget_font$)(::QWidget *) = ::QWidget_font;
  return QWidget_font$(widget);
}

void cxxbridge1$205$QWidget_disconnectAll(::QWidget *widget) noexcept {
  void (*QWidget_disconnectAll$)(::QWidget *) = ::QWidget_disconnectAll;
  QWidget_disconnectAll$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_width(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_width$)(::QWidget *) = ::QWidget_width;
  return QWidget_width$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_height(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_height$)(::QWidget *) = ::QWidget_height;
  return QWidget_height$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_x(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_x$)(::QWidget *) = ::QWidget_x;
  return QWidget_x$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_y(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_y$)(::QWidget *) = ::QWidget_y;
  return QWidget_y$(widget);
}

void cxxbridge1$205$QWidget_setGeometry(::QWidget *widget, ::std::int32_t x, ::std::int32_t y, ::std::int32_t w, ::std::int32_t h) noexcept {
  void (*QWidget_setGeometry$)(::QWidget *, ::std::int32_t, ::std::int32_t, ::std::int32_t, ::std::int32_t) = ::QWidget_setGeometry;
  QWidget_setGeometry$(widget, x, y, w, h);
}

bool cxxbridge1$205$QWidget_isVisible(::QWidget *widget) noexcept {
  bool (*QWidget_isVisible$)(::QWidget *) = ::QWidget_isVisible;
  return QWidget_isVisible$(widget);
}

bool cxxbridge1$205$QWidget_isEnabled(::QWidget *widget) noexcept {
  bool (*QWidget_isEnabled$)(::QWidget *) = ::QWidget_isEnabled;
  return QWidget_isEnabled$(widget);
}

bool cxxbridge1$205$QWidget_isHidden(::QWidget *widget) noexcept {
  bool (*QWidget_isHidden$)(::QWidget *) = ::QWidget_isHidden;
  return QWidget_isHidden$(widget);
}

void cxxbridge1$205$QWidget_windowTitle(::QWidget *widget, ::rust::String *return$) noexcept {
  ::rust::String (*QWidget_windowTitle$)(::QWidget *) = ::QWidget_windowTitle;
  new (return$) ::rust::String(QWidget_windowTitle$(widget));
}

void cxxbridge1$205$QWidget_setFocus(::QWidget *widget) noexcept {
  void (*QWidget_setFocus$)(::QWidget *) = ::QWidget_setFocus;
  QWidget_setFocus$(widget);
}

bool cxxbridge1$205$QWidget_hasFocus(::QWidget *widget) noexcept {
  bool (*QWidget_hasFocus$)(::QWidget *) = ::QWidget_hasFocus;
  return QWidget_hasFocus$(widget);
}

void cxxbridge1$205$QWidget_clearFocus(::QWidget *widget) noexcept {
  void (*QWidget_clearFocus$)(::QWidget *) = ::QWidget_clearFocus;
  QWidget_clearFocus$(widget);
}

void cxxbridge1$205$QWidget_setObjectName(::QWidget *widget, ::std::string const &name) noexcept {
  void (*QWidget_setObjectName$)(::QWidget *, ::std::string const &) = ::QWidget_setObjectName;
  QWidget_setObjectName$(widget, name);
}

void cxxbridge1$205$QWidget_objectName(::QWidget *widget, ::rust::String *return$) noexcept {
  ::rust::String (*QWidget_objectName$)(::QWidget *) = ::QWidget_objectName;
  new (return$) ::rust::String(QWidget_objectName$(widget));
}

void cxxbridge1$205$QWidget_update(::QWidget *widget) noexcept {
  void (*QWidget_update$)(::QWidget *) = ::QWidget_update;
  QWidget_update$(widget);
}

void cxxbridge1$205$QWidget_repaint(::QWidget *widget) noexcept {
  void (*QWidget_repaint$)(::QWidget *) = ::QWidget_repaint;
  QWidget_repaint$(widget);
}

void cxxbridge1$205$QWidget_close(::QWidget *widget) noexcept {
  void (*QWidget_close$)(::QWidget *) = ::QWidget_close;
  QWidget_close$(widget);
}

::QWidget *cxxbridge1$205$QWidget_parentWidget(::QWidget *widget) noexcept {
  ::QWidget *(*QWidget_parentWidget$)(::QWidget *) = ::QWidget_parentWidget;
  return QWidget_parentWidget$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_minimumWidth(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_minimumWidth$)(::QWidget *) = ::QWidget_minimumWidth;
  return QWidget_minimumWidth$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_minimumHeight(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_minimumHeight$)(::QWidget *) = ::QWidget_minimumHeight;
  return QWidget_minimumHeight$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_maximumWidth(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_maximumWidth$)(::QWidget *) = ::QWidget_maximumWidth;
  return QWidget_maximumWidth$(widget);
}

::std::int32_t cxxbridge1$205$QWidget_maximumHeight(::QWidget *widget) noexcept {
  ::std::int32_t (*QWidget_maximumHeight$)(::QWidget *) = ::QWidget_maximumHeight;
  return QWidget_maximumHeight$(widget);
}

void cxxbridge1$205$QWidget_raiseWidget(::QWidget *widget) noexcept {
  void (*QWidget_raiseWidget$)(::QWidget *) = ::QWidget_raiseWidget;
  QWidget_raiseWidget$(widget);
}

void cxxbridge1$205$QWidget_lowerWidget(::QWidget *widget) noexcept {
  void (*QWidget_lowerWidget$)(::QWidget *) = ::QWidget_lowerWidget;
  QWidget_lowerWidget$(widget);
}

bool cxxbridge1$205$QWidget_isMinimized(::QWidget *widget) noexcept {
  bool (*QWidget_isMinimized$)(::QWidget *) = ::QWidget_isMinimized;
  return QWidget_isMinimized$(widget);
}

bool cxxbridge1$205$QWidget_isMaximized(::QWidget *widget) noexcept {
  bool (*QWidget_isMaximized$)(::QWidget *) = ::QWidget_isMaximized;
  return QWidget_isMaximized$(widget);
}

void cxxbridge1$205$QWidget_adjustSize(::QWidget *widget) noexcept {
  void (*QWidget_adjustSize$)(::QWidget *) = ::QWidget_adjustSize;
  QWidget_adjustSize$(widget);
}

bool cxxbridge1$205$QWidget_isActiveWindow(::QWidget *widget) noexcept {
  bool (*QWidget_isActiveWindow$)(::QWidget *) = ::QWidget_isActiveWindow;
  return QWidget_isActiveWindow$(widget);
}

bool cxxbridge1$205$QWidget_underMouse(::QWidget *widget) noexcept {
  bool (*QWidget_underMouse$)(::QWidget *) = ::QWidget_underMouse;
  return QWidget_underMouse$(widget);
}

bool cxxbridge1$205$QWidget_isWindow(::QWidget *widget) noexcept {
  bool (*QWidget_isWindow$)(::QWidget *) = ::QWidget_isWindow;
  return QWidget_isWindow$(widget);
}

::QWidget *cxxbridge1$205$QWidget_window(::QWidget *widget) noexcept {
  ::QWidget *(*QWidget_window$)(::QWidget *) = ::QWidget_window;
  return QWidget_window$(widget);
}

void cxxbridge1$205$QWidget_setWindowOpacity(::QWidget *widget, double opacity) noexcept {
  void (*QWidget_setWindowOpacity$)(::QWidget *, double) = ::QWidget_setWindowOpacity;
  QWidget_setWindowOpacity$(widget, opacity);
}

void cxxbridge1$205$QWidget_setFixedWidth(::QWidget *widget, ::std::int32_t width) noexcept {
  void (*QWidget_setFixedWidth$)(::QWidget *, ::std::int32_t) = ::QWidget_setFixedWidth;
  QWidget_setFixedWidth$(widget, width);
}

void cxxbridge1$205$QWidget_setFixedHeight(::QWidget *widget, ::std::int32_t height) noexcept {
  void (*QWidget_setFixedHeight$)(::QWidget *, ::std::int32_t) = ::QWidget_setFixedHeight;
  QWidget_setFixedHeight$(widget, height);
}

void cxxbridge1$205$QWidget_setMouseTracking(::QWidget *widget, bool enable) noexcept {
  void (*QWidget_setMouseTracking$)(::QWidget *, bool) = ::QWidget_setMouseTracking;
  QWidget_setMouseTracking$(widget, enable);
}

bool cxxbridge1$205$QWidget_hasMouseTracking(::QWidget *widget) noexcept {
  bool (*QWidget_hasMouseTracking$)(::QWidget *) = ::QWidget_hasMouseTracking;
  return QWidget_hasMouseTracking$(widget);
}

void cxxbridge1$205$QWidget_setAcceptDrops(::QWidget *widget, bool enable) noexcept {
  void (*QWidget_setAcceptDrops$)(::QWidget *, bool) = ::QWidget_setAcceptDrops;
  QWidget_setAcceptDrops$(widget, enable);
}

void cxxbridge1$205$QWidget_setAutoFillBackground(::QWidget *widget, bool enable) noexcept {
  void (*QWidget_setAutoFillBackground$)(::QWidget *, bool) = ::QWidget_setAutoFillBackground;
  QWidget_setAutoFillBackground$(widget, enable);
}

void cxxbridge1$205$QWidget_showFullScreen(::QWidget *widget) noexcept {
  void (*QWidget_showFullScreen$)(::QWidget *) = ::QWidget_showFullScreen;
  QWidget_showFullScreen$(widget);
}

void cxxbridge1$205$QWidget_showMaximized(::QWidget *widget) noexcept {
  void (*QWidget_showMaximized$)(::QWidget *) = ::QWidget_showMaximized;
  QWidget_showMaximized$(widget);
}

void cxxbridge1$205$QWidget_showMinimized(::QWidget *widget) noexcept {
  void (*QWidget_showMinimized$)(::QWidget *) = ::QWidget_showMinimized;
  QWidget_showMinimized$(widget);
}

void cxxbridge1$205$QWidget_showNormal(::QWidget *widget) noexcept {
  void (*QWidget_showNormal$)(::QWidget *) = ::QWidget_showNormal;
  QWidget_showNormal$(widget);
}

void cxxbridge1$205$QWidget_setSizePolicy(::QWidget *widget, ::std::int32_t hPolicy, ::std::int32_t vPolicy) noexcept {
  void (*QWidget_setSizePolicy$)(::QWidget *, ::std::int32_t, ::std::int32_t) = ::QWidget_setSizePolicy;
  QWidget_setSizePolicy$(widget, hPolicy, vPolicy);
}

bool cxxbridge1$205$QWidget_isVisibleTo(::QWidget *widget, ::QWidget *ancestor) noexcept {
  bool (*QWidget_isVisibleTo$)(::QWidget *, ::QWidget *) = ::QWidget_isVisibleTo;
  return QWidget_isVisibleTo$(widget, ancestor);
}
} // extern "C"
