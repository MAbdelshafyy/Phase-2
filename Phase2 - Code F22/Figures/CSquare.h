#ifndef CSQUARE_H
#define CSQUARE_H

#include "CFigure.h"

class CSquare : public CFigure
{
private:
	Point Center1;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
};

#endif