#include <iostream>
#include <list>

class Hash
{
public:
	Hash(int V); 

	void insert_item(int x);
	void delete_item(int key);

	int hash_function(int x)
	{
		return (x % m_bucket);
	}
	void display_hash();
private:
	int m_bucket; 
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
	int index = hash_function(key);
	std::list<int> :: iterator i;
	
	for (i = m_table[index].begin(); i != m_table[index].end(); ++i)
	{
		if (*i == key)
		{
			break;
		}
	}
	if (i != m_table[index].end())
	{
		m_table[index].erase(i);
	}
}

void Hash::display_hash()
{
	for (int i = 0; i < m_bucket; ++i)
	{
		std::cout << i;
		for (auto x : m_table[i])
		{
			std::cout << "-->" << x;
		}
		std::cout << std::endl;
	}
}

int main()
{
	const int size = 5;
	int arr[size] = {15, 11, 27, 8, 12} ;  
 
	Hash h(7); 
	
	for (int i = 0; i < size; ++i)
	{
		h.insert_item(arr[i]);
	}

	h.delete_item(12);
	h.display_hash();

	return 0;
}
