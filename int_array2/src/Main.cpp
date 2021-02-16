#include <cassert> // for assert()
#include <initializer_list> // for std::initializer_list
#include <iostream>
 
class IntArray
{
private:
	uint m_length{0};
	int *m_data{nullptr};
 
public:
	IntArray() = default;
 
	IntArray(uint length) :
		m_length{ length },
		m_data{ new int[length]{} }
	{
 
	}
 
	IntArray(std::initializer_list<int> list) : // allow IntArray to be initialized via list initialization
		IntArray(static_cast<int>(list.size())) // use delegating constructor to set up initial array
	{
		// Now initialize our array from the list
		int count{ 0 };
		for (auto element : list)
		{
			m_data[count] = element;
			++count;
		}
	}
 
	~IntArray()
	{
        if(m_data)
    		delete[] m_data;
		// we don't need to set m_data to null or m_length to 0 here, since the object will be destroyed immediately after this function anyway
	}
 
	IntArray(const IntArray&) = delete; // to avoid shallow copies
 
	int& operator[](uint index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}
 
	int getLength() const { return m_length; }
    void erase()
    {
        if(m_data)
            delete[] m_data;
        // We need to make sure we set m_data to nullptr here, otherwise it will
        // be left pointing at deallocated memory!
        m_data = nullptr;
        m_length = 0;
    }
 
    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(uint newLength)
    {
        if(newLength == m_length)
            return;
        // First we delete any existing elements
        erase();
 
        // If our array is going to be empty now, return here
        if (newLength <= 0)
            return;
 
        // Then we have to allocate new elements
        m_data = new int[newLength];
        m_length = newLength;
    }
 
    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void insertBefore(int value, uint index)
    {
        // Sanity check our index value
        assert(index >= 0 && index <= m_length);
 
        // First create a new array one element larger than the old array
        int *data{ new int[m_length+1] };
 
        // Copy all of the elements up to the index
        for (uint before{ 0 }; before < index; ++before)
            data[before] = m_data[before];
 
        // Insert our new element into the new array
        data [index] = value;
 
        // Copy all of the values after the inserted element
        for (uint after{ index }; after < m_length; ++after)
            data[after+1] = m_data[after];
 
        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        ++m_length;
    }
 
    void remove(uint index)
    {
        // Sanity check our index value
        assert(index >= 0 && index < m_length);
 
        // If this is the last element in the array, set the array to empty and bail out
        if (m_length == 1)
        {
            erase();
            return;
        }
 
        // First create a new array one element smaller than the old array
        int *data{ new int[m_length-1] };
 
        // Copy all of the elements up to the index
        for (uint before{ 0 }; before  < index; ++before)
            data[before] = m_data[before];
 
        // Copy all of the values after the removed element
        for (uint after{ index+1 }; after < m_length; ++after)
            data[after-1] = m_data[after];
 
        // Finally, delete the old array, and use the new array instead
        delete[] m_data;
        m_data = data;
        --m_length;
    }
 
    // A couple of additional functions just for convenience
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }

    IntArray& operator=(std::initializer_list<int> list){
        // assuer that the new list is the right size
        if(static_cast<uint>(list.size()) != m_length){
            reallocate(list.size());
        }
        int count {0};
        for (auto element : list){    
            m_data[count] = element;
            ++count;
        }
        return *this;
    }
};
 
int main()
{
    	IntArray array { 5, 4, 3, 2, 1 }; // initializer list
    uint arrayLen = array.getLength();
	for (int count{ 0 }; count < arrayLen; ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };
    arrayLen = array.getLength();

	for (int count{ 0 }; count < arrayLen; ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}
