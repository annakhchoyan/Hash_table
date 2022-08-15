#include <iostream>
#include <list>

class Hash
{
public:
	Hash(int V); 

//inserts a key into hash table
	void insert_item(int x);
//deletes a key from hash table
	void delete_item(int key);
//hash function to mapvalues to key
	int hash_function(int x)
	{
		return (x % m_bucket);
	}
	void display_hash();

private:
	int m_bucket; //no. of bukets

//pointer to an array containing buckets
	std::list<int>* m_table;
};

Hash::Hash(int b)
{
	m_bucket = b;
	m_table = new std::list<int> [m_bucket];
}

void Hash::insert_item(int key)
{
	int index = hash_function(key);
	m_table[index].push_back(key);
}

void Hash::delete_item(int key)
{
//get the hash index of key
	int index = hash_function(key);
//find the key in (index)th list
	std::list<int> :: iterator i;
	for(i = m_table[index].begin(); i != m_table[index].end(); ++i)
	{
		if(*i == key)
		{
			break;
		}
	}

//if key is found in hash table, remove it
	if(i != m_table[index].end())
	{
		m_table[index].erase(i);
	}
}

//function to display hash table
void Hash::display_hash()
{
	for(int i = 0; i < m_bucket; ++i)
	{
		std::cout << i;
		for(auto x : m_table[i])
		{
			std::cout << "-->" << x;
		}
		std::cout << std::endl;
	}
}

int main()
{
	const int size = 5;
	int arr[size] = {15, 11, 27, 8, 12} ;  // array that contains keys to be mapped
//	int n = sizeof(arr) / sizeof(arr[0]);

//insert the keys into the hash table 
	Hash h(7); // 7 is count of buckets in hash table
	for(int i = 0; i < size; ++i)
	{
		h.insert_item(arr[i]);
	}

//delete 12 from hash table
	h.delete_item(12);

//display the Hash table
	h.display_hash();

//	std::cout << "-------------------------------\n" << n << std::endl;
	return 0;
}
