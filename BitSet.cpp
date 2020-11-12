#include "BitSet.h"
#include <algorithm>

BitSet::BitSet() 
{
	allocSmallBitSet();
};
bool BitSet::allocSmallBitSet() 
{
	if (!is_valid)
		return false;
	void * v = calloc(1, sizeof(int));
	if (!v)
	{
		is_valid = false;
		return false;
	}
	m_arr = (int*)v;
	m_size = SIZE_INT;
	return true;
}
BitSet::BitSet(vector<int> vec) 
{
	allocSmallBitSet();
	for (auto it:vec) 
	{
		if (is_valid)
			setBit(it);
	}
};
bool BitSet::setBit(int bit) 
{
	bit = bit - 1;
	if ((bit > m_size) && !reallocBitSet(bit))
	{
		return false;
	}
	m_arr[bit / SIZE_INT] = m_arr[bit / SIZE_INT] | (1 << (bit % SIZE_INT));
	return true;
}
bool BitSet::getBit(int bit) const
{
	bit = bit - 1;
	if ((bit >= m_size))
	{
		return false;
	}
	return ((m_arr[bit / SIZE_INT]&(1<<(bit%SIZE_INT))))>> (bit % SIZE_INT);
}
string  BitSet::toString() const
{
	string res = "";
	if (!is_valid)
		return res;
	for (int i = 0; i < m_size; ++i) 
	{
		res = to_string(getBit(i)) + res;
	}
	return res;
}
bool BitSet::clearBit(int bit)
{
	if (!is_valid)
		return false;
	bit = bit - 1;
	if ((bit >= m_size))
	{
		return false;
	}
	m_arr[bit / SIZE_INT] = m_arr[bit / SIZE_INT] & (~(1 << (bit % SIZE_INT)));
	return true;

}
bool BitSet::reallocBitSet(int new_size)
{
	if (!is_valid)
		return false;
	if (new_size <= m_size)
		return true;
	if (m_size ==0&& !allocSmallBitSet())
		return false;
	new_size = min(new_size, SIZE_INT);
	void* v = realloc(m_arr, new_size * sizeof(int)/SIZE_INT );
		
	if (!v)
	{
		free(m_arr);
		is_valid = false;
		
		return false;
	}
	
	m_arr = (int*)v;
	memset(m_arr, 0, new_size * sizeof(int) / SIZE_INT);
	m_size = new_size;
	return true;
}
bool  BitSet::operator== (const BitSet &rhs)  const
{
	if (!rhs.is_valid || !is_valid)
		return false;
	return strcmp((char*)rhs.m_arr, (char*)m_arr) == 0;
}

BitSet::BitSet(const BitSet& bitset)
{
	if (!is_valid)
		return;
	if (!bitset.is_valid || !reallocBitSet(bitset.m_size))
	{
		free(m_arr);
		is_valid = false;
		return;
	}
	
	memcpy(m_arr, bitset.m_arr, bitset.m_size*sizeof(int)/SIZE_INT);
}
BitSet BitSet::operator&(const BitSet &rhs) const
{
	
	BitSet res;
	if (!rhs.is_valid || !is_valid)
	{
		res.is_valid = false;
		free(res.m_arr);
		return res;
	}
	if (!res.reallocBitSet(max(rhs.m_size, m_size)))
		return res;
	for (int i = 0; i < min(res.m_size, rhs.m_size)/SIZE_INT; ++i) 
	{
		res.m_arr[i] = rhs.m_arr[i] & m_arr[i];
	}
	return res;
}
BitSet BitSet::operator|(const BitSet &rhs) const
{
	BitSet res;
	if (!rhs.is_valid || !is_valid)
	{
		res.is_valid = false;
		free(res.m_arr);
		return res;
	}
	if (!res.reallocBitSet(max(rhs.m_size, m_size)))
		return res;
	for (int i = 0; i < min(res.m_size, rhs.m_size) / SIZE_INT; ++i)
	{
		res.m_arr[i] = rhs.m_arr[i] | m_arr[i];
	}
	for (int i = min(res.m_size, rhs.m_size) / SIZE_INT; i < max(res.m_size, rhs.m_size) / SIZE_INT; ++i)
	{
		res.m_arr[i] = (m_size>rhs.m_size) ? m_arr[i] : rhs.m_arr[i];
	}
	return res;
}
BitSet BitSet::operator>>(int pos) const
{
	
	BitSet res;
	if (!is_valid)
	{
		res.is_valid = false;
		free(res.m_arr);
		return res;
	}
	res.reallocBitSet(min(m_size - pos, 0));
	for (int i = 0; i < res.m_size; ++i)
	{
		res.m_arr[i] = m_arr[i - pos];
	}
	
	return res;
}
BitSet BitSet::operator<<(int pos) const
{
	BitSet res;
	if (!is_valid)
	{
		res.is_valid = false;
		free(res.m_arr);
		return res;
	}
	res.reallocBitSet(m_size + pos);
	for (int i = pos; i < res.m_size; ++i)
	{
		res.m_arr[i] = m_arr[i - pos];
	}

	return res;
}
BitSet::~BitSet() {  if (is_valid) free(m_arr); m_arr = nullptr;  }