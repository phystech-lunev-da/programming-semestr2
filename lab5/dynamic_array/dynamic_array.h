
struct DynamicArray
{
    long* elements = nullptr;
    unsigned long long capacity = 0;
    unsigned long long size = 0;
};

DynamicArray* new_array(unsigned long size, long value = 0)
{
    DynamicArray* array = new DynamicArray;

    array->elements = new long[size];

    array->size = size;
    array->capacity = size;

    for (long long i = 0; i < size; i++)
    {
        array->elements[i] = value;
    }
    return array;
}

void erase(DynamicArray& array)
{
    delete[] array.elements;
    array.elements = nullptr;
    array.capacity = 0L;
    array.size = 0L;
}

DynamicArray& reserve(DynamicArray& array, unsigned long long capacity)
{
    if (array.capacity < capacity)
    {
        long* temp_elements = new long[capacity];

        for (long long i = 0; i < array.capacity; i++)
        {
            temp_elements[i] = array.elements[i];
        }

        for (long long i = array.capacity; i < capacity; i++)
        {
            temp_elements[i] = 0;
        }

        delete[] array.elements;

        array.elements = temp_elements;
        array.capacity = capacity;
    }

    return array;
}

DynamicArray& clone(DynamicArray& source)
{
    DynamicArray* cloned = new DynamicArray;

    cloned->capacity = source.capacity;
    cloned->size = source.size;
    cloned->elements = new long[cloned->capacity];

    for (long long i = 0; i < source.capacity; i++)
    {
        cloned->elements[i] = source.elements[i];
    }

    return *cloned;
}

unsigned long long fix_add = 10l;

DynamicArray& push_back_once(DynamicArray& array, long value)
{
    if (array.capacity == 0)
    {
        array = reserve(array, fix_add);
    }
    if (array.size >= array.capacity)
    {
        array = reserve(array, array.capacity + 1); 
    }
    array.elements[array.size++] = value;

    return array;
}

DynamicArray& push_back_linear(DynamicArray& array, long value)
{
    if (array.capacity == 0)
    {
        array = reserve(array, fix_add);
    }
    if (array.size >= array.capacity)
    {
        array = reserve(array, array.capacity + fix_add); 
    }
    array.elements[array.size++] = value;

    return array;
}

DynamicArray& push_back_double(DynamicArray& array, long value)
{
    if (array.capacity == 0)
    {
        array = reserve(array, fix_add);
    }
    if (array.size >= array.capacity)
    {
        array = reserve(array, (array.capacity) * 2); 
    }
    array.elements[array.size++] = value;

    return array;
}

DynamicArray& push_back(DynamicArray& array, long value)
{
    return push_back_double(array, value);
}