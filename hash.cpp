#include<iostream>
#include<fstream>
#include<cstdlib>
#define MaxSize 7
struct hashtable

{

	int key;
	bool empty;
};

hashtable htable[MaxSize];

int hash(int key) { return key%MaxSize; }

bool findKey(int key,int& index,int number) // Linear Probing으로 확장
{
	bool found = false;
	bool loop = true;
	index = hash(key);
	int index_ = index;
	if (number == 0)
	{
		while (htable[index].empty == true && loop == true)
		{
			index = (index + 1) % MaxSize;

			if (index == index_)

				loop = false;
		}
	}
	else if (number == 1)
	{
		while (htable[index].key != key && loop == true)
		{
			index = (index + 1) % MaxSize;
			if (index == index_)
				loop = false;
		}
	}

	else
	{
		while (htable[index].key != key && loop == true)
		{
			index = (index + 1) % MaxSize;
			if (index == index_)
				loop = false;
		}

		if (loop == true)

			std::cout << key << " exist" << std::endl;

		else

			std::cout << "not exist" << std::endl;

		return 0;

	}

	if (loop == true)

		found = true;

	return found;

}

void searchKey(int key)

{

  int index=0;

  findKey(key, index, 3);

}

int insertKey(int key)

{

	int index = 0;

	int check = findKey(key,index,0);

	if (check == false)

		return false;

	else

	{

		htable[index].key = key;

		htable[index].empty = true;

		return true;

	}

}

void deleteKey(int key)

{

	int index = 0;

	int check = findKey(key,index,1);

	if (check == false)

		std::cout << "not exist" << std::endl;

	else

	{

		std::cout << htable[index].key << "delete!" << std::endl;

		htable[index].empty = false; // marking

	}

}



void printtable()

{

	for (int i = 0; i < MaxSize; ++i)

	{

		if (htable[i].empty == true)

			std::cout << "at "<<i<<" position "<<  htable[i].key << std::endl;

	}

}



int main()

{

	int num = 0;

	char input[20];

	while (1)

	{

		std::cout << " ( 1.insert, 2.delete, 3.search, 4.printtable, 5.quit) " << std::endl;

		std::cin >> input;

		std::cout << std::endl;

		if (strcmp(input, "1") == 0)

		{

			std::cout << "넣고 싶은 수를 써주세요 : ";

			std::cin >> num;

			insertKey(num);

			std::cout << num << "이 들어갔습니다." << std::endl;

		}

		else if (strcmp(input, "2") == 0)

		{

			std::cout << "지우고 싶은 수를 써주세요 : ";

			std::cin >> num;

			deleteKey(num);

		}

		else if (strcmp(input, "3") == 0)

		{

			std::cout << "찾으시는 수를 써주세요 : ";

			std::cin >> num;

			searchKey(num);

		}

		else if (strcmp(input, "4") == 0)

		{

			printtable();

		}

		else if (strcmp(input, "5") == 0)

		{

			std::cout << "프로그램을 종료 합니다. ";

			break;

		}

		else

			std::cout << "잘못 입력하셨습니다." << std::endl;

	}

	return 0;

}
