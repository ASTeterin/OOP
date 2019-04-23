#pragma once
#include "IShape.h"
#include "stdint.h"


class ISolidShape: public IShape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;

	virtual void SetFillColor(uint32_t color) = 0;
	virtual uint32_t GetFillColor() const = 0;
};
