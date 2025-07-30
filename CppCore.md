# C++ Core

## Summary:
### Basics
* [Types](#types)
* [Arrays](#arrays)
* [Loops](#loops)
* [Functions](#functions)
* [Recursion](#recursion)
* [Address of Operator (&)](#address-of-operator-)
* [Pass by Value](#pass-by-value)
* [References](#references)
* [Pass by Reference](#pass-by-reference)
* [Functions with const parameters](#functions-with-const-parameters)
* [Pointers: Definition, Dereference](#pointers-definition-dereference)
* [Dynamic Memory Allocation (new/delete)](#dynamic-memory-allocation-newdelete)
* [Pointer Arithmetics](#pointer-arithmetics)
* [Sizeof operator](#sizeof-operator)
* [Passing Arrays into functions](#passing-arrays-into-functions)
* [Pitfalls of Pointers](#pitfalls-of-pointers)
* [Function pointers](#function-pointers)
* [lvalue and rvalue](#lvalue-and-rvalue)
* [std::move](#stdmove)
* [std::unique_ptr](#stdunique_ptr)
* [std::shared_ptr](#stdshared_ptr)
* [std::weak_ptr](#stdweak_ptr)
* [Interface(.hpp) vs Implementation(.cpp)](#interfacehpp-vs-implementationcpp)

### Object Oriented Programming
* [Introduction to Classes](#introduction-to-classes)
* [Defaults](#defaults)
* [Copy Constructor and Copy Assignment Operator](#copy-constructor-and-copy-assignment-operator)
* [Rule of 3](#rule-of-3)
* [Avoiding Copies](#avoiding-copies)
* [Operator Overloading](#operator-overloading)
* [Member Initializer Lists](#member-initializer-lists)
* [Structs](#structs)
* [Resource Acquisition is Initialization RAII](#resource-acquisition-is-initialization-raii)
* [Rule of 5](#rule-of-5)
* [Friend Functions](#friend-functions)
* [Explicit ctor](#explicit-ctor)
* [Introduction to Inheritance](#introduction-to-inheritance)
* [Inheritance (public, private, protected access)](#inheritance-public-private-protected-access)
* [Inheritance calling different constructors](#inheritance-calling-different-constructors)
* [Virtual Functions (Dynamic dispatch)](#virtual-functions-dynamic-dispatch)
* [Understanding the vtable](#understanding-the-vtable)
* [Interfaces in C++ (Pure virtual functions)](#interfaces-in-c-pure-virtual-functions)
* [Multiple Inheritance](#multiple-inheritance)
* [cppman](#cppman)
* [const correctness](#const-correctness)
* [{} and () initializer list](#-and--initializer-list)
* [Composition and Aggregation](#composition-and-aggregation)
* [Virtual Inheritance](#virtual-inheritance)
* [Value initialization](#value-initialization)
* [in-class initializer](#in-class-initializer)
* [Delegating Constructors](#delegating-constructors)
* [Class Data Layout](#class-data-layout)
* [pIMPL](#pimpl)
* ['this' keyword](#this-keyword)
* ['static' keyword](#static-keyword)
* ['static' and classes](#static-and-classes)

# Basics
## Types
```
#include <iostream>

int main() {
  int x = 42;
  int64_t q = 2133333331313131;
  bool y = true;
  float z = 3.14f;
  char w = 'w';
  std::cout << x << std::endl;
  std::cout << q << std::endl;
  std::cout << sizeof(x) << std::endl;
  std::cout << y << std::endl;
  std::cout << z << std::endl;
  std::cout << w << std::endl;

  return 0;
}
```
## Arrays
```
#include <iostream>
#include <numeric>
#include <iterator>
#include <array>

int main() {
  
  std::array<int, 100> ids; // or int ids[100];

  std::iota(std::begin(ids), std::end(ids), 0);

  for(int i = 0; i < 100; i++) {
    std::cout << ids[i] << std::endl;
  }

  ids.at(1000) = 9;

  return 0;
}

```
## Loops
```
#include <iostream>
#include <array>
#include <algorithm>

int main() {
  int arr[] = {1, 3, 5};

  std::array<int, 3> arr2{1, 3, 5};

  for(int i = 0; i < arr2.size(); i = i + 1) {
    std::cout << arr2[i] << std::endl;
  }

  // range-based for loops
  for(int element: arr2) {
    std::cout << element << std::endl;
  }
  
  int countdown = 3;
  while(countdown > 0) {
    std::cout << countdown << std::endl;
    countdown--;
  }

  countdown = 3;
  do {
    std::cout << countdown << std::endl;
    countdown--;
  } while(countdown > 0);

  std::array<int, 3> arr;
  std::fill(std::begin(arr), std::end(arr), 1024);
  for(int element:arr) {
    std::cout << element << std::endl;
  }
  return 0;
}
```
## Functions
```
#include <iostream>

// Forward Declared
// Function Declaration
int add(int a, int b);
float add(float a, float b); // or auto add(float a, float b) -> float;

// Declared and Defined
void print(void) {
  std::cout << "hello" << std::endl;
}

int main() {
  
  std::cout << add(1, 2) << std::endl;
  std::cout << add(1.2f, 1.4f) << std::endl;

  print();

  return 0;
}

int add(int a, int b) {
  std::cout << "int add(int a, int b)" << std::endl;
  return a+b;
}

float add(float a, float b) {
  std::cout << "float add(float b, float b)" << std::endl;
  return a+b;
}
```
## Recursion
```
#include <iostream>

int countdown(int n) {
  // Base Case
  if (n == 0) {
    std::cout << "0... blast off!" << std::endl;
    return 0;
  }

  // Recursive Case
  std::cout << n << std::endl;
  return countdown(n-1);
}

int main() {
  // countdown(5000000); // stack overflow
  countdown(5);
  return 0;
}
```
## Address of Operator (&)
Address Of Operator (&): returns the address of a variable or function value in memory.
```
#include <iostream>
void foo() {

}

int main() {
  int x = 42;
  float y = 72;
  char a = 'a';
  signed char b = 'b';
  unsigned char c = 'c';

  std::cout << "x: " << &(x) << std::endl; // address in hexadecimal in RAM
  std::cout << "x's size: " << sizeof(int) << " bytes" << std::endl;
  std::cout << "y: " << &(y) << std::endl;
  std::cout << "a: " << (void*)&(a) << std::endl;
  std::cout << "b: " << (void*)&(b) << std::endl;
  std::cout << "c: " << (void*)&(c) << std::endl;
  std::cout << "foo: " << (void*)&(foo) << std::endl;
  std::cout << "main: " << (void*)&(main) << std::endl;

  return 0;
}
```
## Pass by Value
Pass-by-value: We make copies of our arguments when passed in functions.

```
#include <iostream>

 void SetValue(int arg) {
  std::cout << "SetValue: arg initially is " << arg << std::endl;
  std::cout << "arg's addr is " << &(arg) << std::endl;
  arg = 9999;
  std::cout << "SetValue: arg at the end is " << arg << std::endl;
}

int main() {

  int x = 42;
  std::cout << "x's value is " << x << std::endl;
  std::cout << "x's addr is " << &(x) << std::endl;
  
  // Call our function
  SetValue(x);

  // Check x's value
  std::cout << "x's value is " << x << std::endl;
  std::cout << "x's addr is " << &(x) << std::endl;

  return 0;

}
```
## References 
References (Second use of & symbol), the primary use of references is the pass-by-reference argument in functions.
```
#include <iostream>

int main() {

  int x = 42;
  // "int&" is the full type, for a reference type.
  int& ref = x;

  int* y = nullptr;
  int*& ref2 = y; // illegal to ref null pointer.

  std::cout << "x value  :" << x << std::endl;
  std::cout << "x address:" << &(x) << std::endl;

  std::cout << "ref value  :" << ref << std::endl;
  std::cout << "ref address:" << &(ref) << std::endl;

  return 0;
}

```
## Pass by Reference
Pass by Reference: Mutable and Efficient
```
#include <iostream>
#include <vector>
#include <algorithm>

// Pass by Value
void PassByValue(std::vector<int> arg) {
  arg[0] = 1;
}

// Pass by Reference:
void PassByReference(std::vector<int>& ref) {
  ref[0] = 1;
}

int main() {
  std::vector<int> x(1000000000);
  std::fill(std::begin(x), std::end(x), 1);
  
  PassByValue(x);
  PassByReference(x);

  return 0;
}
```
## Functions with const parameters
Uses of Const: 1) Read Only data; 2) Safety - Ensure that the functions don't change the data
```
#include <iostream>
#include <vector>
#include <algorithm>

// Function with Const Param
void PassByReference(const std::vector<int>& ref) {
  ref[0] = 0;
}

int main() {
  const double PI = 3.14; // const = immutable = read-only
  constexpr int expression = 10 + 10 + 4;

  std::cout << PI << std::endl;
  std::cout << expression << std::endl;

  std::vector<int> x(100000000);
  
  PassByReference(x);
  
  return 0;
}
```
## Pointers: Definition, Dereference
A pointer is a variable that stores the memory address of another variable.
A reference is an alias or an alternative name for an already existing variable. It directly refers to the same memory location as the original variable. 

Use pointers for share a data, and access it from multiple sources that point to it.
```
#include <iostream>

int main() {
  int x = 7;
  int* px = &x;
  int* px2 = &x;

  // Update x
  x = 9;

  std::cout << "x stores        :" << x << std::endl; // 4 bytes
  std::cout << "x addr          :" << &(x) << std::endl;
  std::cout << "px stores       :" << px << std::endl;
  std::cout << "px addr         :" << &(px) << std::endl;
  // Dereference: Retrieve the value of the type we point to.
  std::cout << "px dereferenced :" << *px << std::endl;
  std::cout << "px2 stores      :" << px2 << std::endl;
  std::cout << "px2 dereferenced:" << *px2 << std::endl;

  int y = 7;
  int* py = &y;
  *py = 42;
  std::cout << "y stores: " << y << std::endl;

  return 0;
}
```
## Dynamic Memory Allocation (new/delete)
HEAP Memory: Dynamic Memory Allocation with new and delete.
Allows us to allocate resources at runtime. This resource is returned to us in a pointer.

```
#include <iostream>

int main() {

  int numberOfStudents = 0;

  std::cout << "How many students in our class?" << std::endl;
  std::cin >> numberOfStudents;

  int* studentIds = new int[numberOfStudents];

  for(int i = 0; i < numberOfStudents; i++) {
    studentIds[i] = i;
  }

  delete[] studentIds; // Free Memory: Very important, otherwise we're gonna lose information.

  return 0;
}
```
## Pointer Arithmetics
```
#include <iostream>

int main() {
  
  // Arrays are contiguous chunks of memory, where we can iterate through each item incrementing the pointers.
  int array[] = {1, 3, 5, 7, 9};
  int* px = array;

  std::cout << "array[0]     : " << array[0] << std::endl;
  std::cout << "array[0] addr: " << &array[0] << std::endl;
  std::cout << std::endl;
  
  std::cout << "array   :" << array << std::endl; // points to the first element
  std::cout << "px      : " << px << std::endl;
  std::cout << "px deref: " << *px << std::endl;
  std::cout << std::endl;
  // Increment px: Whenever we increment a pointer the size of the incrementation is the size of the datatype, in this case is the sizeof int = 4 bytes.
  px++;
  std::cout << "px      : " << px << std::endl;
  std::cout << "px deref: " << *px << std::endl;
  std::cout << std::endl;

  px++;
  std::cout << "px      : " << px << std::endl;
  std::cout << "px deref: " << *px << std::endl;
   
  // Show the array offset: Moving through an array using pointer arithmetic
  int* px2 = array;
  std::cout << *(px2 + 0) << std::endl; // or *(array + offset) or array[index]
  std::cout << *(px2 + 1) << std::endl;
  std::cout << *(px2 + 2) << std::endl;
  std::cout << *(px2 + 3) << std::endl;
  std::cout << *(px2 + 4) << std::endl;
  
  // How brackets [] dereference addresses from array.
  std::cout << array[0] << std::endl; 
  std::cout << array[1] << std::endl;
  std::cout << array[2] << std::endl;
  std::cout << array[3] << std::endl;
  std::cout << array[4] << std::endl;

  return 0;
}

```
## Sizeof operator
```
#include <iostream>
#include <vector>

// sizeof returns the size of the data type.
int main() {
  // Local Variable (primitive type)
  int x = 8;

  // A pointer
  int* px = &x;

  // A STACK allocated array with fixed size
  int array[] = {1, 3, 5, 7, 9};

  // A HEAP allocated array
  int* dinamicallyAllocatedArray = new int[1000];

  // Vector
  std::vector<int> vec;

  // Output
  std::cout << "x                        : " << sizeof(x) << " Bytes" << std::endl;
  std::cout << "px                       : " << sizeof(px) << " Bytes" << std::endl; // Pointer: Always 8 bytes for a 64 bit Archtecture System.
  std::cout << "array                    : " << sizeof(array) << " Bytes" << std::endl;
  std::cout << "dinamicallyAllocatedArray: " << sizeof(dinamicallyAllocatedArray) << " Bytes" << std::endl; // Pointer: points to the first element of the array: 8 bytes for a 64 bit Archtecture System.
  std::cout << "vec                      : " << sizeof(vec) << " Bytes" << std::endl;
  std::cout << "vec elements             : " << vec.size() << " Bytes" << std::endl;

  return 0;
}

```
## Passing Arrays into functions
```
#include <iostream>
#include <array>
#include <vector>

/*void PrintArray(std::array<int, 5> arr, size_t size) {
  for(int i = 0; i < size; i++) {
    std::cout << arr[i] << std::endl;
  }
}*/

void PrintArray(std::vector<int> vector) {
  for(int i = 0; i < vector.size(); i++) {
    std::cout << vector[i] << std::endl;
  }
}

int main() {
  
  // ARRAYS ARE STATIC
  //int array[] = {1, 3, 5, 7, 9};
  //std::array<int, 5> array = {1, 3, 5, 7, 9};
  //PrintArray(array, sizeof(array) /sizeof(int));
  
  // VECTOR ARE DYNAMIC
  std::vector<int> vec = {1, 3, 5, 7, 9};
  PrintArray(vec);
  
  return 0;
}

```
## Function pointers
```
#include <iostream>
#include <functional>

// Function Pointer are used to create callback functions.

typedef int (*PFIntegerOperations)(int, int);

int add(int x, int y) {
  return x + y;
}

int multiply(int x, int y) {
  return x * y;
}

int main() {
  
  // Function Pointer for functions: int name(int, int)
  // int (*op)(int, int);
  // PFIntegerOperations op;
  std::function<int(int, int)> op;
  
  std::cout << "type 1 for add and 2 for multiply: ";
  int n;
  std::cin >> n;

  if(n == 1) {
    op = add;
  } else if(n == 2) {
    op = multiply;
  }

  int x,y;
  std::cin >> x;
  std::cin >> y;

  std::cout << "Operation: " << op(x, y) << std::endl;

  return 0;
}

```
## Pitfalls of pointers
```
#include <iostream>

int* returnResult() {

  int result = 42;
  return &result;
}

int main() {
  
  // 1) NULL POINTER Derenference
  /* int* px = nullptr;
  *px = 42; // Segmentation Fault: Derenference something that you don't have access to.
  */

  // 2) MEMORY LEAKS 
  // g++ -g -fsanitize=address -std=c++17 main.cpp -o prog
  // int* array = new int[1000];
  
  // 3) DANGLING POINTER
  /*int* px = returnResult();

  std::cout << "*px: " << *px << std::endl; */

  // 4) Double Free
  int* x = new int;
  *x = 42;
  delete x;
  delete x;

  return 0;
}
```

## lvalue and rvalue

lvalue (locator value) refers to an object that occupies an identifiable location in memory (i.e., it has an address). You can take its address using &. Example: a variable name.

rvalue (read value) refers to a temporary value or literal that does not have a persistent memory address. You cannot take its address. Example: the result of 2 + 3 or a literal like 42.

Example:
```
int x = 5; // x is an lvalue
int y = x + 2; // (x + 2) is an rvalue
```

Key point:

lvalues can appear on the left or right of an assignment.
rvalues can only appear on the right.
## std::move
```
#include <iostream>
#include <string>
/* Move Semantics
- <utilily> header, c++11 >
- std::move is used to indicate that an object t may be "moved from", i.e. allowing the efficient move of resources from t to another object.
- std::move moves the data instead of creating a copy of it. Transfering the ownership or stealing the resources from another.
*/

// Construct a new string. This uses copy constructor
// We have 'rvalue' on the right, and that will be copied into 'MyString' using the copy contructor.
int main() {
  std::string myString = "copy construct me";
  std::string newValue;

  std::cout << "myString: " << myString << std::endl;
  std::cout << "newValue: " << newValue << std::endl;
  // std::move allows us to "adopt" or "steal" the value 
  newValue = std::move(myString);
  // Could more explicitly call the static cast here to move the value of myString into newValue.
  
  // Not here, myString is still some 'valid' value. 
  // Maybe it stores "nullptr" in the data in the string, but it still exists.
  //newValue = static_cast<std::string&&>(myString)
  std::cout << "myString: " << myString << std::endl;
  std::cout << "newValue: " << newValue << std::endl;
  

  return 0;
}
```
## std::unique_ptr
```
#include <iostream>
#include <memory> // unique_ptr

/*
- Raw Pointers allow sharing:
  1) Allow room for errors (meaning forgetting to dealocate)
  2) Ownership (Dealocating before accessing it)
- Smart Pointers:
  1) Address these issues.
  2) RAII - Scoped -> Will be deleted after out of scope.
  3) Unique Pointer 
- Unique Pointers:
  1) We cannot share (no copies are allowed). TWO POINTERS CANNOT POINT TO THE SAME ADDRESS.
  2) We don't have to delete, deletes within the scope (block scope {})
  3) Move semantics is allowed.
*/

// Some user defined type
class UDT {
  public:
    // Contructor (Called on creation)
    UDT() { std::cout << "UDT Created" << std::endl; }

    // Destructor (called on destruction)
    ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main() {
  /* RAW POINTERS
  int* array = new int[100];
  for(int i=0; i < 100; i++) {
    array[i] = i;
  }

  int* ptr = array;

  // Output value value pointed to by ptr
  std::cout << "*ptr = " << *ptr << std::endl;

  // Create a second pointer
  int* ptr2 = ptr;
  
  std::cout << "*ptr2 = " << *ptr2 << std::endl;

  delete[] array;
  */    
      
  // SMART Pointers
  // Creating one unique pointer
  std::unique_ptr<UDT> fekenzofugi = std::unique_ptr<UDT>(new UDT);
  // NOT POSSIBLE std::unique_ptr<UDT> joe = fekenzofugi;
  // We are allowed to move a unique pointer
  // But we cannot copy with unique pointer
  std::unique_ptr<UDT> joe = std::move(fekenzofugi);
  // Create an 'array' that is pointed to, by one unique ptr
  // std::unique_ptr<UDT[]> array = std::unique_ptr<UDT[]>(new UDT[2]);
  // The equivalent to the line above is:
  // std::unique_ptr<UDT[]> array2 = std::make_unique<UDT[]>(2);
  
  return 0;
}

```
## std::shared_ptr
```
#include <iostream>
#include <memory> // shared_ptr 
/*
- Raw Pointers allow sharing:
  1) Allow room for errors (meaning forgetting to dealocate)
  2) Ownership (Dealocating before accessing it)
- Smart Pointers: Helps us avoid calling new and delete.
  1) Address these issues.
  2) RAII - Scoped -> Will be deleted after out of scope.
  3) Unique Pointer, Shared Pointer
- Unique Pointers:
  1) We cannot share (no copies are allowed). TWO POINTERS CANNOT POINT TO THE SAME ADDRESS.
  2) We don't have to delete, deletes within the scope (block scope {})
  3) Move semantics is allowed.
- Shared Pointers:
  1) We can share. Two pointers can point to the same resource.
  2) Reference Count: Count how many pointers are pointing to the same resource. The pointers can be located in different scopes. But the resource is dealocated only when all pointers are within scope. This is handled automatically.
  3) Shared Ownership: Lifetime of the resource over time.
  4) The reference count is thread safe.

*/
// Some user defined type 
class UDT{
  public: 
    // Constructor (called on creation) 
    UDT() { std::cout << "UDT Created" << std::endl; }    
    // Destructor (called on destruction)
    ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main() {
  {
    // Creating our shared pointer
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    { 
      // Then in a new scope, I share the resource
      std::shared_ptr<UDT> ptr2 = ptr1;
      // Our reference count is updated
      std::cout << "use count = " << ptr2.use_count() << std::endl;
    } // Then ptr2 is freeded
    // Then we check our updated reference count
    std::cout << "use count = " << ptr1.use_count() << std::endl; 
  } 
  std::cout << "The resources should be dealocated before this line" << std::endl;
  return 0;
}
```
## std::weak_ptr
```
#include <iostream>
#include <memory>

/*
- Raw Pointers allow sharing:
  1) Allow room for errors (meaning forgetting to dealocate)
  2) Ownership (Dealocating before accessing it)

- Smart Pointers: Helps us avoid calling new and delete.
  1) Address these issues.
  2) RAII - Scoped -> Will be deleted after out of scope.
  3) Unique Pointer, Shared Pointer

- Unique Pointers:
  1) We cannot share (no copies are allowed). TWO POINTERS CANNOT POINT TO THE SAME ADDRESS.
  2) We don't have to delete, deletes within the scope (block scope {})
  3) Move semantics is allowed.

- Shared Pointers:
  1) We can share. Two pointers can point to the same resource.
  2) Reference Count: Count how many pointers are pointing to the same resource. The pointers can be located in different scopes. But the resource is dealocated only when all pointers are within scope. This is handled automatically.
  3) Shared Ownership: Lifetime of the resource over time.
  4) The reference count is thread safe.

- Weak Pointers:
  1) Non-Owning Pointer: Does not increase the reference count. Why? 
    * Safer way to have dangling pointers 
    * Break Cycles

- Dangling Pointers: 
  A dangling pointer is a pointer that no longer points to a valid object or memory location in computer programming. This   happens when the object the pointer was referring to is deleted, deallocated, or goes out of scope, but the pointer itsel  f is not updated to reflect this change. Using a dangling pointer can lead to unpredictable behavior, including crashes,   data corruption, or security vulnerabilities
*/ 

// Some user defined type 
class UDT{
  public: 
    // Constructor (called on creation) 
    UDT() { std::cout << "UDT Created" << std::endl; }    
    // Destructor (called on destruction)
    ~UDT() { std::cout << "UDT Destroyed" << std::endl; }
};

int main() {
  std::weak_ptr<UDT> ptr2;
  {
    // Creating a shared pointer
    std::shared_ptr<UDT> ptr1 = std::make_shared<UDT>();
    { // Then in a new scope, i share the resource
      ptr2 = ptr1;
      // Our reference count is NOT updated with a WEAK pointer
      std::cout << "use_count: " << ptr2.use_count() << std::endl;
    } // Then ptr2 is freed
    // Then check our updated reference count
    std::cout << "use_count: " << ptr1.use_count() << std::endl;
  } // Dealocate Resources
  std::cout << "We should see the destructor before this line" << std::endl;
  std::cout << "Is weak_ptr (object that it points to) valid: " << ptr2.expired() << std::endl;
  return 0;
}
```
## Interface(.hpp) vs Implementation(.cpp)
The interface file (.hpp or .h) declares the structure of your code—such as classes, functions, and their signatures—without providing the actual logic. It tells other code how to interact with your components.

The implementation file (.cpp) contains the actual code (function bodies, logic) that fulfills the declarations in the interface. This separation helps organize code, speeds up compilation, and makes it easier to maintain and reuse components.

## Introduction to Classes
Class is a User-Defined-Type (UDT)
1) Information Hiding (public, private and protected).
2) Ability to create instances of objects and think in objects in our software.

## Defaults
Default on Classes 
1) We get a 'default constructor' and a 'default destructor'. That don't take any parameters. But we can override these.

## Copy Constructor and Copy Assignment Operator
Default compiler generated
1) Constructor
2) Destructor

Shallow Copy: Default Given 
C++ gives us a 'free' copy constructor and assignment operator, but, it does a Shallow copy. Which is a simple assignment.
It can cause memory issues, because if a instance of some class points dynamically to some location in memory, and it gets deallocated, 
the copy of this instance will also try to deallocate the resources, but, it already was freed, causing a double free in memory.

Deep Copy: Need to SetUp
What we really want is a deep copy for dynamically allocated memory (HEAP).

3) Copy Constructor
4) Copy-Assignment Operator

## Rule of 3
Is a rule of thumb in C++ that claims that if a class defines any of the following 
  * Destructor
  * Copy Constructor
  * Copy Assignment Operator
then it should probably explicitly define all three.

Because implicitly-generated constructors and assignment operatores simply cover all class data members (shallow copy),
one should define explicit copy construcotr and copy assignment operators for classes that encapsulate complex data structures
or have external references such as pointers, if you need to copy the objects pointed to by the class members. If the default 
behavior ("shallow copy") is actually the intended one, then an explicit definition, although redundant, will be 
"self-documenting code" indicating that it was an intention rather than an oversight. 

LAW OF THE BIG TWO : An amendment to this rule is that if the class is designed in such a way that resource acquisition is initialization (RAII) 
is used for all its (nontrivial) members, the destructor may be left undefined (also known as The Law of The Big Two[3]).
A ready-to-go example of this approach is the use of smart pointers instead of plain ones.


## Avoiding Copies
```
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <vector>

class Array {
  public:
    // SPECIAL MEMBER FUNCTIONS
    // 1) Constructor
    Array();
    // 2) Destructor
    ~Array();
    // 3) Copy Constructor
    Array(const Array& rhs);
    // 4) Copy Assignment Operator
    Array& operator = (const Array& rhs);

    void PrintingData();
    void SetData(int index, int value);
  private:
    std::vector<int> data;
};

#endif
```

```
#include "Array.hpp"
#include <iostream>

Array::Array() {
  std::cout << "Constructor" << std::endl;
  for(int i = 0; i<10000; i++) {
    data.push_back(i);
  }
}

Array::~Array() {
}

// Copy Constructor
// Array myNewArray = someExistingArray
Array::Array(const Array& rhs){
  std::cout << "Copy Constructor" << std::endl;
  for(int i=0; i<rhs.data.size(); i++) {
    data.push_back(rhs.data[i]);
  }
}

// Copy Assigment Operator
// Object is already constructred, we are just making a copy later (e.g. myArray2 = myArray)
Array& Array::operator=(const Array& rhs) {
  std::cout << "Copy Assignment Operator" << std::endl;
  if(&rhs == this) { // this is the current instance of the class.
    return *this;
  }

  data.clear();
  for(int i=0; i<rhs.data.size(); i++) {
    data.push_back(rhs.data[i]);
  }
  return *this;
}

void Array::PrintingData() {
  for(int i=0; i<data.size(); i++) {
    std::cout << data[i] << std::endl;
  }
}

void Array::SetData(int index, int value) {
  data[index] = value;
}
```

```
#include "Array.hpp"

void passByRef(const Array& a) {
  
}

void passByVal(Array a) {

}

int main() {

  // Initialize all of our data
  Array myArray;

  myArray.SetData(0, 12345);
  
  // Copy contructor called
  Array myArray2 = myArray;
  for(int i=0; i<100; i++) {
    passByVal(myArray);
    passByRef(myArray);
  }

  return 0;
}
```

## Operator Overloading
Operator Functions are functions with spetial function names:
1) operator op  
any of the following operators:+ - * / % ^ & | ~ ! = < > += -= *= /= %= ^= &= |= << >> >>= <<= == != <= >= <=>(since C++20)   && || ++ -- , ->* -> () []

2) operator new 
    operator new []

3) operator delete
    operator delete []

4) operator co_await
```
#include <iostream>

// A vector3 data type, storing floats
class Vector3f {
  public:
    Vector3f() {
      x = 0.0f;
      y = 0.0f; 
      z = 0.0f;
    }
    
    Vector3f operator+(const Vector3f& rhs) const { //const means that we're not changing anything the current object in this function.
      Vector3f result;
      result.x = x + rhs.x;
      result.y = y + rhs.y;
      result.z = z + rhs.z;
      return result;
    }
    //prefix increment
    Vector3f operator++() {
      x = x+1;
      y = y+1;
      z = z+1;
      return *this;
    }

    bool operator==(const Vector3f& rhs) {
      std::cout << "part of the class" << std::endl;
      float u = 1e-12;
      if (x - rhs.x < u  && y - rhs.y < u && z - rhs.z < u) {
        return true;
      }
      return false;
    }
    
    float x, y, z;
};

// output stream
std::ostream& operator<<(std::ostream& os, const Vector3f& obj) {
  
  os << obj.x << "," << obj.y << "," << obj.z;

  return os;
}

bool operator==(const Vector3f& lhs, const Vector3f rhs) {
  std::cout << "free function" << std::endl;
  if(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z) {
    return true;
  } 
  return false;  
}

int main() {

  Vector3f myVector;
  myVector.x = 0.9999999999999f;
  myVector.y = 0.9999999999999f;
  myVector.z = 0.9999999999999f;
  Vector3f myVector2;
  myVector2.x = 1.f;
  myVector2.y = 1.f;
  myVector2.z = 1.f;

  Vector3f result;
  result = myVector + myVector2;
  ++result;
  std::cout << result << std::endl;
  
  if(myVector == myVector2) {
    std::cout << "The vectors are equal" << std::endl;
  } else {
    std::cout << "The vectors are not equal" << std::endl;
  }

  return 0;
}
```
## Member Initializer Lists
**Vector3f.hpp**
```
#ifndef VECTOR3F_HPP
#define VECTOR3F_HPP

class Vector3f {
public:
  Vector3f();

  float x, y, z;
};

#endif
```
**Vector3f.cpp**
```
#include "Vector3f.hpp"

Vector3f::Vector3f(): x(0.0f), y(0.0f), z(0.0f){

}
```
## Structs
Classes and Structs are user-defined types, defined by class-specifier.
For both classes and structs the keywords are identical EXCEPT for the
default MEMBER ACCESS and the default BASE CLASS ACCESS.

The default access for classes are PRIVATE.
The default access for structs are PUBLIC.

C++ in built on top of C which have Structs.

## Resource Acquisition is Initialization (RAII)

Resource Acquisition Is Initialization or RAII, is a C++ programming technique
which binds the life cycle of a resource that must be acquired before use 
(allocated heap memory, thread of execution, open socket, open file, locked mutex, 
disk space, database connection—anything that exists in limited supply) to the 
lifetime of an object.

RAII can be summarized as follows:

* encapsulate each resource into a class, where 
    * the constructor acquires the resource and establishes all class nvariants or throws an exception if that cannot be done,
    * the destructor releases the resource and never throws exceptions; 

* always use the resource via an instance of a RAII-class that either 
    * has automatic storage duration or temporary lifetime itself, or
    * has lifetime that is bounded by the lifetime of an automatic or temporary object. 

WHY USE RAII? RAII uses classes with destructors to impose order on resource management (new and delete).
if some function (e.g. file handle) in the class throws an exception, the destructor is still invoked and the file is properly
closed.

Learks are typically unacceptable. Manual resource release is error-prone. RAII is the simplets, most systematic way of
preventing leaks.
```
class Collection {
public: 
  Collection() {
    data = new int[10];
    try {
      throw 20;
    } catch(int e) {
      // some error message
    }
  } 

  ~Collection() {
    std::cout << "destructor is called" << std::endl;
    delete[] data;
  }

  int& operator[](std::size_t idx) {
    return data[idx];
  }

  const int& operator[](std::size_t idx) const {
    return data[idx];
  }
  
private:
  int* data;
};


int main() {
  
  Collection myCollection;
  myCollection[0] = 7;
  myCollection[1] = 7;
  
  return 0;
}
```
## Rule of 5
## Friend Functions
## Explicit ctor
## Introduction to Inheritance
## Inheritance (public, private, protected access)
## Inheritance calling different constructors
## Virtual Functions (Dynamic dispatch)
## Understanding the vtable
## Interfaces in C++ (Pure virtual functions)
## Multiple Inheritance
## cppman
## const correctness
## {} and () initializer list
## Composition and Aggregation
## Virtual Inheritance
## Value initialization
## in-class initializer
## Delegating Constructors
## Class Data Layout
## pIMPL
## 'this' keyword
## 'static' keyword
## 'static' and classes



# References:
* <a href="https://www.youtube.com/playlist?list=PLvv0ScY6vfd8j-tlhYVPYgiIyXduu6m-L">Mike Shah Course</a>
* <a href="https://cppreference.com/">cppreference.com</a>