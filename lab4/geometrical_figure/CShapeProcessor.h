#pragma once
#include "IShape.h"
#include <map>
#include <functional>
#include <vector>
#include <string>
#include <boost/noncopyable.hpp>

class CShapeProcessor : boost::noncopyable
{
public:
	CShapeProcessor(std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	void AddCircle(std::vector<std::string> const& parametersList);
	void AddTriangle(std::vector<std::string> const& parametersList);
	void AddRectangle(std::vector<std::string> const& parametersList);
	void AddLineSegment(std::vector<std::string> const& parametersList);
	std::vector<std::string> ReadShape(std::istream& strm);

private:
	typedef std::map<std::string, std::function<void(std::vector<std::string> const& parametersList)>> ActionMap;
	std::istream& m_input;
	std::ostream& m_output;
	const ActionMap m_actionMap;
	std::vector<std::shared_ptr<IShape>> m_shapesList;
	

};
