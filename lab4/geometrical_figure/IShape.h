#pragma once
class IShape
{
public:
	IShape();
	virtual ~IShape();
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	//virtual void SetOutlineColor(const std::string & color) = 0;
	virtual std::uint32_t GetOutlineColor() const = 0;
};

