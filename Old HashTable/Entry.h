#ifndef _ENTRY
#define _ENTRY

template<class KeyType, class ItemType>
class Entry
{
private:
	//data
	ItemType item;
	KeyType searchKey;

protected:
	void setKey(const KeyType& searchKey);

public:
	
	//constructors
	Entry();
	Entry(ItemType newEntry, KeyType searchKey);

	//methods
	ItemType getItem() const;
	KeyType getKey() const;
	void setItem(const ItemType& newEntry);

	//operator overload
	bool operator==(const Entry<KeyType, ItemType>& rightHandItem) const;
	bool operator>(const Entry<KeyType, ItemType>& rightHandItem) const;
};

#endif