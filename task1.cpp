
#include "BitSet.h" 
#include <iostream>
using namespace std;
/*
namespace TestSystem
{
	static bool passed_flag = true;

	template <typename T>
	bool testEquals(const char* name, const T& left, const T& right)
	{
		bool res = left == right;
		static int i = 0;
		std::cout << "Test "
			<< name << " - "
			<< (res ? "Passed!" : "Failed!")
			<< std::endl;
		if (!res)
		{
			passed_flag = false;
		}
		return res;
	};

	void result()
	{
		if (passed_flag)
		{
			std::cout << "\nAll tests were passed SUCCESSFULLY!!!" << std::endl;
		}
		else
		{
			std::cout << "\nSome tests were FAILED!!!" << std::endl;
		}
	}
}

*/
enum ETrackTag { none = 0, pop, rock, rap, hiphop, english, russian, german, s80, s90, s00, s10 };


int main()
{
	int number = pop;
	std::cout << number << endl;
	/*
    BitSet set1;
    set1.setBit(pop);
    set1.setBit(english);
    set1.setBit(s80);
    BitSet set2({ rock,english,s80,s90 });
    auto set3 = set1;
    set3.clearBit(english);

    TestSystem::testEquals("1: getBit1", set1.getBit(pop), true);

    TestSystem::testEquals("2: getBit2", set1.getBit(rock), false);

    TestSystem::testEquals("3: clearBit", BitSet({ pop, s80 }), set3);
    
    TestSystem::testEquals("4: operator ==", BitSet({ english,s80, rock }), BitSet({ s80, rock, english }));
    
    TestSystem::testEquals("5: operator &", set1 & set2, BitSet({ english,s80 }));
    
    TestSystem::testEquals("6: operator |", set1 | set2, BitSet({ rock,pop,english,s80,s90 }));

    TestSystem::testEquals("7: operator >>", BitSet({ pop, rock}) << 2, BitSet({ rap, hiphop }));

    TestSystem::testEquals("8: operator <<", BitSet({ s80, s90 }) >> 2, BitSet({ russian, german}));

    TestSystem::testEquals("9: toString1 ", set1.toString(), std::string("10010001"));
    
    TestSystem::testEquals("10: toString2 ", set2.toString(), std::string("110010010"));
 
    TestSystem::result();
	*/
    system("pause");
}