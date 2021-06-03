#include <iostream>
#include <list>

using namespace std;

int main()
{ 
	list<int> sold;
	int counter= 1;
	for (int i = 0; i < 6; i++)
	{
		sold.push_back(i+1);
	}
	list<int>::iterator it = sold.begin();
	for (; sold.size()>1; )
	{
		if (it == sold.end())
		{
			it = sold.begin();
		}
		if (counter == 3)
		{		
			it = sold.erase(it);
			if (it == sold.end())
			{
				it = sold.begin();
			}
			counter = 1;
			continue;
		}
		counter++;
		it++;
	}
	for (int i : sold)
	{
		cout << i<<endl;
	}

	system("pause");
	return 0;
}