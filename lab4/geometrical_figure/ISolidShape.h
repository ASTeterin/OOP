#pragma once
#include "IShape.h"
#include "stdint.h"


class ISolidShape: virtual public IShape
{
public:
	ISolidShape() = default;
	virtual ~ISolidShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;

	virtual void SetFillColor(uint32_t color) = 0;
	virtual uint32_t GetFillColor() const = 0;
};
