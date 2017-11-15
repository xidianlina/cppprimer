#ifndef QUERY_H_
#define QUERY_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
class QueryResult;

class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) :file(new std::vector<std::string>)
{
	using namespace std;

	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;
		while (line >> word)
		{
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p, std::shared_ptr<std::vector<std::string>>f):sought(s),lines(p),file(f){}
private:
	std::string sought;
	std::shared_ptr<std::set<TextQuery::line_no>> lines;
	std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string& sought)const
{
	static std::shared_ptr < std::set<line_no >> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<< (qr.lines->size() == 1 ? "time" : "times") << std::endl;
	for (auto num : *qr.lines)
		os << "\t(line " << num + 1 << ") "
		<< *(qr.file->begin() + num) << std::endl;

	return os;
}

#endif