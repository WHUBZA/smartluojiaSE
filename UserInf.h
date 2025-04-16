#pragma once

#include<vector>
#include<string>
using namespace std;

class UserInf
{
	string STUID;
	string NAME;
	string PASSWORD;
public:
	UserInf()
	{
	}
	UserInf(string&line)
	{
		vector<string>inf = split(line);
		AddID(inf[0]);
		AddName(inf[1]);
		AddPassword(inf[2]);
	}
	~UserInf()
	{
	}
	vector<string> split(string&line)
	{
		string temp = "";
		vector<string>words;
		for (int i = 0;i < line.size();i++)
		{
			if (line[i] != ' ')
			{
				temp += line[i];
			}
			else
			{
				words.push_back(temp);
				temp = "";
			}
		}
		words.push_back(temp);
		return words;
	}
	inline void AddID(string&a)
	{
		STUID = a;
	}
	inline void AddName(string&a)
	{
		NAME = a;
	}
	inline void AddPassword(string&a)
	{
		PASSWORD = a;
	}
	inline string FindID()
	{
		return  STUID;
	}
	inline string FindName()
	{
		return  NAME;
	}
	inline string FindPassword()
	{
		return PASSWORD;
	}
};

