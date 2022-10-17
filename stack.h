#ifndef STACK_
#define STACK_ 1

#include <iostream>
#include <initializer_list>
#include <algorithm>

class stack
{
   size_t current_size;
   size_t current_capacity;

   double *data;
   void ensure_capacity(size_t c);

public:
   stack();
   stack(const stack &s);
   ~stack();

   const stack &operator=(const stack &s);

   stack(std::initializer_list<double> init);

   void push(double d);

   void pop();

   void clear();

   void reset(size_t s);

   double peek() const;

   size_t size() const;

   bool empty() const;

   void print(std::ostream &out) const;

   friend int main(int argc, char *argv[]);
};

inline std::ostream &operator<<(std::ostream &out, const stack &st)
{
   st.print(out);
   return out;
}

#endif