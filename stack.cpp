#include "stack.h"

void stack::ensure_capacity(size_t c)
{
    unsigned int p = 1;
    while (p < current_capacity)
    {
        p = p * 2;
    }
    current_capacity = p;

    if (c > current_capacity)
    {
        while (c > current_capacity)
        {
            current_capacity = current_capacity * 2;
        }
    }

    double *newdata = new double[current_capacity];
    std::copy(data, data + current_size, newdata);

    delete[] data;
    data = newdata;
}

stack::stack() : current_size(0),
                 current_capacity(4),
                 data(new double[4])
{
}

stack::stack(const stack &s) : current_size(s.current_size),
                               current_capacity(s.current_capacity),
                               data(new double[s.current_capacity])
{
    std::copy(s.data, s.data + s.current_size, data);
    ensure_capacity(s.current_capacity);
}

const stack &stack::operator=(const stack &s)
{
    current_size = s.current_size;
    ensure_capacity(s.current_size);
    std::copy(s.data, s.data + s.current_size, data);
    return *this;
}

stack::~stack()
{
    delete[] data;
}

void stack::push(double d)
{
    ensure_capacity(current_size + 1);
    data[current_size] = d;
    ++current_size;
}

stack::stack(std::initializer_list<double> init) : current_size(0),
                                                   current_capacity(4),
                                                   data(new double[4])
{
    for (double val : init)
    {
        push(val);
    }
}

void stack::pop()
{
    if (current_size <= 0)
    {
        throw std::runtime_error("pop: stack is empty");
    }
    else
    {
        current_size--;
    }
}

void stack::clear()
{
    current_size = 0;
}

void stack::reset(size_t s)
{
    current_size = s;
}

double stack::peek() const
{
    if (current_size <= 0)
    {
        throw std::runtime_error("peek: stack is empty");
    }
    else
    {
        return data[current_size - 1];
    }
}

size_t stack::size() const
{
    return current_size;
}

bool stack::empty() const
{
    if (current_size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack::print(std::ostream &out) const
{
    for (size_t i = 0; i < current_size; ++i)
    {
        if (i == (current_size - 1))
        {
            out << *(data + i);
        }
        else
        {
            out << *(data + i) << ", ";
        }
    }
}
