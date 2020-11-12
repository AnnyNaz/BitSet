#pragma once
#include <vector>
#include <string>
using namespace std;
class BitSet 
{
	public:
		BitSet();
		BitSet(vector<int> r);
		BitSet(const BitSet& a);
		bool setBit(int bit);
		bool clearBit(int bit);
		bool getBit(int bit) const;
		string toString()const ;
		bool  operator==(const BitSet &rhs) const;
		BitSet  operator&(const BitSet &rhs) const;
		BitSet  operator|(const BitSet &rhs) const;
		BitSet operator>>(int pos) const;
		BitSet operator<<(int pos) const;
		~BitSet();
	private:
		int* m_arr;
		int m_size = 0;
		bool is_valid = true;
		bool reallocBitSet(int new_size);
		bool allocSmallBitSet();
		const int SIZE_INT = 32;
};