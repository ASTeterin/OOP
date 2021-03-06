#pragma once
#include "IShape.h"

class CShape: public virtual IShape
{
public:

	CShape(std::string const& type, uint32_t outlineColor);

	uint32_t GetOutlineColor() const override;
	void SetOutlineColor(uint32_t color);

	std::string ToString() const;	

private:
	virtual void AppendProperty(std::ostream& strm) const;
	uint32_t m_outlineColor;
	std::string m_type;
};

