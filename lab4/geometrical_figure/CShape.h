#pragma once
#include "IShape.h"

class CShape: public IShape
{
public:
	CShape();
	CShape(std::string const& type, uint32_t outlineColor);
	uint32_t GetOutlineColor() const override;
	std::string ToString() const override;
	void SetOutlineColor(uint32_t color);

private:
	virtual void AppendProperty(std::ostream& strm) const;
	uint32_t m_outlineColor;
	std::string m_type;
};

