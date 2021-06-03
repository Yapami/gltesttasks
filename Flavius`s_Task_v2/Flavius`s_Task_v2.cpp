#include <iostream>
#include <list>

int main()
{
	std::cout << "Enter the number of soldiers: ";
	uint32_t NUMBER_OF_SILDIERS;
	std::cin >> NUMBER_OF_SILDIERS;

	std::list<uint32_t> soldiers;
	uint32_t counter = 1;

	for (uint32_t i = 0; i < NUMBER_OF_SILDIERS; ++i) {
		soldiers.push_back(i + 1);
	}

	std::list<uint32_t>::iterator it = soldiers.begin();

	for (; soldiers.size() > 1;) {
		if (it == soldiers.end()) {
			it = soldiers.begin();
		}
		if (counter == 3) {
			it = soldiers.erase(it);
			if (it == soldiers.end()) {
				it = soldiers.begin();
			}
			counter = 1;
			continue;
		}
		++counter;
		++it;
	}

	for (uint32_t i : soldiers) {
		std::cout << "The soldier in position " << i << " will survive."
			<< std::endl;
	}

	system("pause");
	return 0;
}