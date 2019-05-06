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

vector<string> CShapeProcessor::ReadShape(istream& strm)
{
	vector<string> shapeParametrs;
	string parametr;

	while (getline(strm, parametr, ' '))
	{
		shapeParametrs.push_back(parametr);
	}
	return shapeParametrs;
}

void CShapeProcessor::AddTriangle(vector<string> const& parametersList)
{
	//CheckTriangleArguments(parametersList);

	CPoint vertex1 = { stod(parametersList[1]), stod(parametersList[2]) };
	CPoint vertex2 = { stod(parametersList[3]), stod(parametersList[4]) };
	CPoint vertex3 = { stod(parametersList[5]), stod(parametersList[6]) };
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (parametersList.size() == 9)
	{
		outlineColor = stoul(parametersList[7], nullptr, 16);
		fillColor = stoul(parametersList[8], nullptr, 16);
	}
	auto triangle = make_shared<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
	m_shapesList.push_back(triangle);
}

void CShapeProcessor::AddRectangle(vector<string> const& parametersList)
{
	//CheckRectangleArguments(parametersList);

	CPoint leftTop = { stod(parametersList[1]), stod(parametersList[2]) };
	CPoint rightBottom = { stod(parametersList[3]), stod(parametersList[4]) };
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (parametersList.size() == 7)
	{
		outlineColor = stoul(parametersList[5], nullptr, 16);
		fillColor = stoul(parametersList[6], nullptr, 16);
	}
	auto rectangle = make_shared<CRectangle>(leftTop, rightBottom, outlineColor, fillColor);
	m_shapesList.push_back(rectangle);
}

void CShapeProcessor::AddCircle(vector<string> const& parametersList)
{
	if ((parametersList.size() != 4 && parametersList.size() != 6))
	{
		throw invalid_argument("Incorrect amount arguments! Must will be 4 or 6!");
	}
	CPoint center = { stod(parametersList[1]), stod(parametersList[2]) };
	double radius = stod(parametersList[3]);
	uint32_t outlineColor = 0x000000;
	uint32_t fillColor = 0xFFFFFF;

	if (parametersList.size() == 6)
	{
		outlineColor = stoul(parametersList[4], nullptr, 16);
		fillColor = stoul(parametersList[5], nullptr, 16);
	}
	auto circle = make_shared<CCircle>(center, radius, outlineColor, fillColor);
	m_shapesList.push_back(circle);
}

void CShapeProcessor::AddLineSegment(vector<string> const& parametersList)
{
	//CheckLineSegmentArguments(parametersList);

	CPoint startPoint = { stod(parametersList[1]), stod(parametersList[2]) };
	CPoint endPoint = { stod(parametersList[3]), stod(parametersList[4]) };
	uint32_t outlineColor = 0x000000;

	if (parametersList.size() == 6)
	{
		outlineColor = stoul(parametersList[5], nullptr, 16);
	}
	auto lineSegment = make_shared<CLineSegment>(startPoint, endPoint, outlineColor);
	m_shapesList.push_back(lineSegment);
}
