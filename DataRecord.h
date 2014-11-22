// Data Record 
// By Elton Vinh


#ifndef _DATA_RECORD
#define _DATA_RECORD

#include <iostream>

using namespace std;

class DataRecord
{
private:
	string key;
	string frequency;
public:
	DataRecord()													{}
	DataRecord(string entry)										{key = entry;}
	void setKey(string newKey)										{key = newKey;}
	void setFrequency(string newFreq)								{frequency = newFreq;}
	string getKey()													{return key;}
	friend ostream& operator<< (ostream& out, DataRecord& dr);
	bool operator> (const DataRecord& rdr)							{return key>rdr.key;}
	bool operator< (const DataRecord& rdr)							{return	key<rdr.key;}
};

ostream& operator<< (ostream& out, DataRecord& dr)
{
	out << dr.key <<","<< dr.frequency;
	return out;
}

#endif
