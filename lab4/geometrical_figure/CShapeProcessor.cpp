#include "pch.h"
#include <map>
#include <string>
//#include <boost/algorithm/string.hpp>
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CShapeProcessor.h"
#include "CTriangle.h"

using namespace std;
using namespace std::placeholders;

CShapeProcessor::CShapeProcessor(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({ { "Circle", bind(&CShapeProcessor::AddCircle, this, placeholders::_1) },
		  { "Triangle", bind(&CShapeProcessor::AddTriangle, this, placeholders::_1) },
		  { "Rectangle", bind(&CShapeProcessor::AddRectangle, this, placeholders::_1) },
		  { "LineSegment", bind(&CShapeProcessor::AddLineSegment, this, placeholders::_1) } })
{
}

vector<string> CShapeProcessor::ParseShapeParameterString(istream& strm)
{
	vector<string> shapeParametrs;
	string parametr;

	while (getline(strm, parametr, ' '))
	{
		shapeParametrs.push_back(parametr);
	}
	return shapeParametrs;
}

void CShapeProcessor::HandleCommand()
{
	string commandLine; // = "Circle 0 0 10 0x001000 0xEE0022";
	string actions;
	vector<string> params;
	getline(m_input, commandLine);
	if (commandLine.empty())
	{
		return;
	}
	istringstream strm(commandLine);
	params = ParseShapeParameterString(strm);
	auto it = m_actionMap.find(params.at(0)); //
	if (it != m_actionMap.end())
	{
		it->second(params);
	}
}

void CShapeProcessor::PrintInfo() const
{
	for (const auto shape : m_shapesList)
	{
		m_output << shape->ToString() << endl;
	}
}

void CShapeProcessor::AddTriangle(vector<string> const& shapeParametrs)
{
	if ((shapeParametrs.size() != 7 && shapeParametrs.size() != 9))
	{
		throw invalid_argument("Incorrect count of arguments! Use: Triangle vertex1.x vertex1.y vertex2.x vertex2.y vertex3.x vertex.3y {outline fill}\n");
	}

	CPoint vertex1 = { stod(shapeParametrs[1]), stod(shapeParametrs[2]) };
	CPoint vertex2 = { stod(shapeParametrs[3]), stod(shapeParametrs[4]) };
	CPoint vertex3 = { stod(shapeParametrs[5]), stod(shapeParametrs[6]) };
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (shapeParametrs.size() == 9)
	{
		outlineColor = stoul(shapeParametrs[7], nullptr, 16);
		fillColor = stoul(shapeParametrs[8], nullptr, 16);
	}
	auto triangle = make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
	m_shapesList.push_back(triangle);
}

void CShapeProcessor::AddRectangle(vector<string> const& shapeParametrs)
{
	if ((shapeParametrs.size() != 5 && shapeParametrs.size() != 7))
	{
		throw invalid_argument("Incorrect amount arguments! Use:  Rectangle leftTop.x leftTop.y rightBottom.x rightBottom.y {outline fill}\n");
	}

	CPoint leftTop = { stod(shapeParametrs[1]), stod(shapeParametrs[2]) };
	CPoint rightBottom = { stod(shapeParametrs[3]), stod(shapeParametrs[4]) };
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (shapeParametrs.size() == 7)
	{
		outlineColor = stoul(shapeParametrs[5], nullptr, 16);
		fillColor = stoul(shapeParametrs[6], nullptr, 16);
	}
	auto rectangle = make_shared<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
	m_shapesList.push_back(rectangle);
}

void CShapeProcessor::AddCircle(vector<string> const& shapeParametrs)
{
	if ((shapeParametrs.size() != 4 && shapeParametrs.size() != 6))
	{
		throw invalid_argument("Incorrect amount arguments! Use: Circle center.x center.y radius { outline fill }\n");
	}
	CPoint center = { stod(shapeParametrs[1]), stod(shapeParametrs[2]) };
	double radius = stod(shapeParametrs[3]);
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (shapeParametrs.size() == 6)
	{
		outlineColor = stoul(shapeParametrs[4], nullptr, 16);
		fillColor = stoul(shapeParametrs[5], nullptr, 16);
	}
	auto circle = make_shared<CCircle>(center, radius, outlineColor, fillColor);
	m_shapesList.push_back(circle);
}

void CShapeProcessor::AddLineSegment(vector<string> const& shapeParametrs)
{
	if ((shapeParametrs.size() != 5 && shapeParametrs.size() != 6))
	{
		throw invalid_argument("Incorrect amount arguments! Use: LineSegment vertex1.x vertex1.y vertex2.x vertex2.y {outline}\n");
	}

	CPoint startPoint = { stod(shapeParametrs[1]), stod(shapeParametrs[2]) };
	CPoint endPoint = { stod(shapeParametrs[3]), stod(shapeParametrs[4]) };
	uint32_t outlineColor = 0x000000;

	if (shapeParametrs.size() == 6)
	{
		outlineColor = stoul(shapeParametrs[5], nullptr, 16);
	}
	auto lineSegment = make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
	m_shapesList.push_back(lineSegment);
}

void CShapeProcessor::PrintShapeWithMaxArea() const
{
	if (m_shapesList.empty())
	{
		return;
	}
	auto shapeWithMaxArea = max_element(m_shapesList.begin(), m_shapesList.end(), [](const auto& arg1, const auto& arg2) {
		return arg1->GetArea() < arg2->GetArea();
	});
	m_output << "Shape with max area\n" << (*shapeWithMaxArea)->ToString() << "\n";
}

void CShapeProcessor::PrintShapeWithMinPerimeter() const
{
	if (m_shapesList.empty())
	{
		return;
	}
	auto shapeWithMinPerimeter = std::min_element(m_shapesList.cbegin(), m_shapesList.cend(), [](const auto& arg1, const auto& arg2) {
		return arg1->GetPerimeter() < arg2->GetPerimeter();
	});
	m_output << "Shape with min perimeter\n"
			 << (*shapeWithMinPerimeter)->ToString() << "\n";
}
