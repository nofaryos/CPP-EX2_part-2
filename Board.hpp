#include "Direction.hpp"
#include <string>
#include <map>
#include <climits>

namespace ariel{
	class Board{
		private:
		
        std::map<unsigned int, std::map<unsigned int, char>> messages;
        unsigned int minRow=UINT_MAX;
        unsigned int minCol=UINT_MAX;
		unsigned int maxRow=0;
        unsigned int maxCol=0;
		
		public:
		
		Board(){}
		~Board(){}
		
		void post(unsigned int row, unsigned int col, Direction d, const std::string &m);
		
		std::string read(unsigned int row, unsigned int col, Direction d, unsigned int length);
		
		void show();
	};
};