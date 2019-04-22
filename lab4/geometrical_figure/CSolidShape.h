#pragma once

#include "ISolidShape.h"
#include "CShape.h"



class CSolidShape
	: public ISolidShape
	, public CShape
{
public:

	CSolidShape(const std::string& type, uint32_t outlineColor, uint32_t fillColor);
	virtual ~CSolidShape() = default;

	void SetFillColor(uint32_t color) override;
	uint32_t GetFillColor() const final;

	void SetOutlineColor(uint32_t color);
	std::uint32_t GetOutlineColor() const final;

	std::string ToString() const;
	virtual void AppendProperties(std::ostream& strm) const = 0;

private:
	std::string m_type;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};