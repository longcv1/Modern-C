namespace TypeDeduction
{
   template <typename T>
   class MyContainer
   {
   private:
      std::vector<T> m_Data;

   public:
      T &operator[](int index)
      {
         return m_Data[index];
      }
      // how to fix
      // decltype(auto) operator[](int index) {
      //     return m_Data[index];
      // }
   };
} // end of namespace

/*
======== Template Type Deduction (Part 1)=========
template<typename T>
void func(T& param);
func(expr);

- T: deduced type
- T&: param's type
- expr: T and the param type are deduced
- The type is deduced for T depends on the deduced param's type

=> 3 cases for deduction of param's type
- Param type is neither reference nor pointer (pass by value)
  => if expr's type is & , ignore that
  => if expr is const or top-level of const or volatile , ignore that
   // template<typename T>
   // void func(T param);

   // int x = 42;
   // const int &rcx = x;
   // func(x);  // param type = int ; T = int
   // func(rcx); // param type = const int, T= int

- Param type is reference (or pointer)
   => if expr's type is &, ignore that
   => pattern match expr's type  against the parameter to determine T
   // template<typename T>
   // void func(T& param);

   // int x = 42;
   // const int cx = 45;
   // const int &rcx = x;

   // func(x);  // param type = int& ; T = int
   // func(cx);  // param type = const int& ; T = const int
   // func(rcx); // param type = const int&, T= const int
   
- Param type is forwarding reference (universal type &&)
   => if expr is lvalue or lvalue reference of type E. T = E&
      param is of type E& && --> reference collapsing --> E&
   => if expr is rvalue , ignore reference and pattern-match
   // template<typename T>
   // void func(T&& param);

   // int x = 42;
   // const int &rcx = x;

   // func(x);  // param type = int& ; T = int&
   // func(rcx); // param type = const int&, T= const int&
   // func(34); // param type = int && , T = int`

======== Template Type Deduction (Part 2)=========
1. Lambda capture deduction:
   - By reference: follow template deduction for ref params rule
   - By value: Template deduction but with cv qualifiers (keep const / volatile)
2. Decltype deduction:
   - Never strips const/volatile/references.
   int x = 10; // decltype(x) ≡ int
   const auto& rx = x; // decltype(rx) ≡ const int&
   - Unsurprising. Almost all such expressions really have type T&.

3. Function Return Type Deduction
      decltype(auto) sensitive to function implementation:
      decltype(auto) lookupValue( context information )
      {
         static std::vector<int> values = initValues();
         int idx = compute index into values from context info;
         auto retVal = values[idx]; // retVal's type is int
         return retVal; // returns int
      }
      decltype(auto) lookupValue( context information )
      {
         static std::vector<int> values = initValues();
         int idx = compute index into values from context info;
         auto retVal = values[idx]; // retVal's type is int
         return (retVal); // returns int& (to local
      } // variable!)
=> Rules of thumb:
- Use auto if a reference type would never be correct.
- Use decltype(auto) only if a reference type could be correct
*/