#pragma once
#include "IShape.h"
#include "stdint.h"


class ISolidShape: public virtual IShape
{
public:
	virtual void SetFillColor(uint32_t color) = 0;
	virtual uint32_t GetFillColor() const = 0;
};
