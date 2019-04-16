#pragma once
#include "IShape.h"

class CShape: public IShape
{
public:
	CShape(const uint32_t outlineColor);
	uint32_t GetOutlineColor() const override;
	std::string ToString() const override;

private:
	uint32_t m_outlineColor

};

